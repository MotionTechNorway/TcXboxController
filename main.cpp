#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <string>

// XboxController based on XInput
#include "XboxController.h"

// ADS headers
#include "TcAdsDef.h"
#include "TcAdsApi.h"

int main(int argc, char *argv[])
{	
	if (argc < 2)
	{
		std::cout 
			<< "Usage: \n"
			<< "\t TcXboxController plcVar \t ex: TcXboxController MAIN.xbox" <<
		std::endl;

		return 1;
	}

	long nErr;
	AmsAddr Addr;
	PAmsAddr pAddr = &Addr;
	ULONG hVar;

	// Open communication port on the ADS router
	AdsPortOpen();
	nErr = AdsGetLocalAddress(pAddr);
	if (nErr)
	{
		std::cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
	}

	// Select Port: TwinCAT 3 PLC1 = 851
	// pAddr->netId
  	pAddr->port = 851;


	// Get variable handle
	nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(hVar), &hVar, (unsigned long)strlen(argv[1]), argv[1]);
  	if (nErr)
	{
		std::cerr << "Error: AdsSyncReadWriteReq: " << nErr << '\n';
	}
		
	// Xbox controller instance
	XboxController xbox;

	while (xbox.isConnected())
	{	
		// Read XboxController
		xbox.update();

		// Write the struct to the Plc
		nErr = AdsSyncWriteReq(
			pAddr, 
			ADSIGRP_SYM_VALBYHND,
			hVar,
			sizeof(TcXboxController),
			(void*) &xbox
		);

		if (nErr)
		{
			printf("Error: Ads: Write struct: %d\n", nErr);
			break;
		};

		// Break if BACK is pressed
		if (xbox.BACK)
		{
			break;
		}

		Sleep(10);
	}

	// Close communication port
  	nErr = AdsPortClose();
  	if (nErr)
		std::cerr << "Error: AdsPortClose: " << nErr << '\n';

	return 0;
}