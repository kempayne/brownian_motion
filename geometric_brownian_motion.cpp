#include <iostream>
#include <fstream>
#include <cmath>
#include "/home/kempayne/BM/HeaderFiles/Random1.h"

using namespace std;

int main()
{
	double TimeHorizon, TimeInterval, Drift, Vol;
	
	TimeHorizon = 20;			// Number of years for simulation
	TimeInterval = 1;			// This will have to be divisible into TimeHorizon so that an integer is the quotient;	
	
	int NumberOfIterations = TimeHorizon / TimeInterval;
	double StockPrice[NumberOfIterations];
	
	StockPrice[0] = 100;		// Initial stock price
	Drift = .07;				// Expected return
	Vol = .05;					// Volatility of returns
		
	double TimeAxis[NumberOfIterations];
	TimeAxis[0] = 0;
	double GaussianRV;
	
	// cout << TimeAxis[0] << ", " << StockPrice[0] << endl;
	
	for (int i = 1; i <= NumberOfIterations; i++)
	{
		TimeAxis[i] = i * TimeInterval;
		GaussianRV = GetOneGaussianByBoxMuller();
		StockPrice[i] = StockPrice[i-1] * (1 + (Drift * TimeInterval) + (Vol * GaussianRV * sqrt(TimeInterval)));
	
	}	
	
	ofstream BMData;
	BMData.open("brownian_motion_data.csv");
	
	for (int i=0; i < NumberOfIterations; i++)
	{
	
		BMData << TimeAxis[i] << "," << StockPrice[i] << endl;
	
	}
	
	BMData.close();
		
		
	return 0;		
}
	
	
