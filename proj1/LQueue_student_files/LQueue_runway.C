/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;
	

void print(Queue q)
{ q.display(cout); }

int main(void)
{
	int maxNum, takeoffRate, landingRate;
	cout << "How long for program to run: " << endl;
	cin >> maxNum;
	cout << "Program will run for " << maxNum << " minutes" << endl;
	cout << "Takeoff rate: ";
	cin >> takeoffRate;
	cout << "Takeoff rate is " << takeoffRate << endl;
	cout << "Landing rate: ";
	cin >> landingRate;
	cout << "Landing rate is " << landingRate << endl;
	for (int simMin = 1; simMin < maxNum; simMin++) {	
		srand (time(NULL)); // random number seed
		int firstRandNum = rand() % 60;
		int secondRandNum = rand() % 60;
	}	
	
	
	
		//if (firstRandNum < 
   
   
   
   
   
   
   
   
   
   
   
   
   return 0;   
}
