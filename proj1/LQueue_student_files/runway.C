//
//  project1.cpp
//
//
//  Created by Sandra Yoo on 2017-01-31.
//
//

//  airport has 1 runway
//  takeoff queue, landing queue
//  random number generator to reflect reality (cannot predict when plane will arrive or depart)
//  takeoff and landing rate (# of planes/hour) USER SUPPLIED, PRIORITY to LANDINGS...


#include <stdio.h>
#include <iostream>
#include "LQueue.h"
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    
    
    /* Declaring queues */
    Queue takeoff;
    Queue landing;
    int landingRate, takeoffRate, randNum1, randNum2, planeNumber, temp1, temp2, landingTime, takeoffTime;
    int landingQueueSize, takeoffQueueSize;
    int totalMins, maxTime;
    
    
    cout <<"Enter:" <<'\n';
    cout << "Time for a plane to land (in minutes): ";
    cin >> landingTime;
    cout << "Time for a plane to takeoff (in minutes): ";
    cin >> takeoffTime;
    cout << "Landing rate (planes per hour): ";
    cin >> landingRate;
    cout << "Takeoff rate (planes per hour): ";
    cin >> takeoffRate;
    cout << "How long to run the simulation (in minutes):";
    cin >> totalMins;
    
    cout << '\n' << endl;
    
    srand(time(0));
    
    maxTime = 1000;
    planeNumber = 1000;
    landingQueueSize = 0;
    takeoffQueueSize = 0;
    bool runwayInUse = false;
    int landingCounter = landingTime + 1;
    int takeoffCounter = takeoffTime + 1;
    
    for (int mins=0; mins <= maxTime; mins++ ) {
        cout << "Time = " << mins << endl;
        if(mins <= totalMins) {
            
            
            //*  every min, generate 2 random numbers  */
            randNum1 = rand()%60;
            randNum2 = rand()%60;


//----------------------------REQUESTS------------------------------------------               
            
			/* landing request has been generated,  and that the plane is enqueued or added to the landing queue */
            if(randNum1 < landingRate){
            	landingQueueSize++;
                landing.enqueue(planeNumber);
                temp1 = planeNumber;
                cout << "Plane " << planeNumber << " wants to land; " << landingQueueSize << " in queue" << endl;
                planeNumber++;
                
            }
            
            
			/* landing request has been generated,  and that the plane is enqueued or added to the landing queue */
            if(randNum2 < takeoffRate){
            	takeoffQueueSize++;
                takeoff.enqueue(planeNumber);
                temp2 = planeNumber;
                cout << "Plane " << planeNumber << " wants to takeoff; " << takeoffQueueSize << " in queue" << endl;
                planeNumber++;
            }
            
            
//-------------------RUNWAY PRIORITY---------------------------------------------------
            
            if (runwayInUse == false){
                
                //incoming landing plane on the runway
                if(!landing.empty()){
                    cout << "Landing: Plane " << landing.front() << endl;
                    runwayInUse = true;
                    
                }
                
                //outgoing takeoff plane on the runway
                else if(!takeoff.empty()){
                    cout << "Taking off: Plane " << takeoff.front() << endl;
                    runwayInUse = true;
                }
            }
            
            if ((runwayInUse == true) && (!landing.empty())) {
                landingCounter--;

                if(landingCounter == 0){
                    landingQueueSize--;
                    cout << "Plane " << landing.front() << " has landed; " << landingQueueSize << " in queue." << endl;
                    landing.dequeue();
                    landingCounter = landingTime +1;
                    
                    runwayInUse = false;
            
                }
            }
            
             else if ((runwayInUse == true) && (!takeoff.empty())) {
                takeoffCounter--;
                
                if(takeoffCounter == 0){
                    takeoffQueueSize--;
                    cout << "Plane " << takeoff.front() << " has taken off; " << takeoffQueueSize << " in queue." << endl;
                    takeoff.dequeue();
                    takeoffCounter = takeoffTime + 1;
                    
                    runwayInUse = false;
                    
                }
            }
            
		}
//----------------------------------------------------------------------               
        else if (mins > totalMins){
            if (runwayInUse == false){
                
                //incoming landing plane on the runway
                if(!landing.empty()){
                    cout << "Landing: Plane " << landing.front() << endl;
                    runwayInUse = true;
                    

                }
                
                //outgoing takeoff plane on the runway
                else if(!takeoff.empty()){
                    cout << "Taking off: Plane " << takeoff.front() << endl;
                    runwayInUse = true;
                    
                }
            }
            
            if ((runwayInUse == true) && (!landing.empty())) {
                landingCounter--;
                
                if(landingCounter == 0){
                    landingQueueSize--;
                    cout << "Plane " << landing.front() << " has landed; " << landingQueueSize << " in queue." << endl;
                    landing.dequeue();
                    landingCounter = landingTime +1;
                    
                    runwayInUse = false;
                }
            }
            
            else if ((runwayInUse == true) && (!takeoff.empty())) {
                takeoffCounter--;
                
                if(takeoffCounter == 0){
                    takeoffQueueSize--;
                    cout << "Plane " << takeoff.front() << " has taken off; " << takeoffQueueSize << " in queue." << endl;
                    takeoff.dequeue();
                    takeoffCounter = takeoffTime + 1;
                    
                    runwayInUse = false;
                    
                }
            }
            
            if (takeoff.empty() && landing.empty()) {
                break;
            }
		}
        planeNumber++;
    }
    
    
    
//-----------------------------PRINTOUTS-----------------------------------------     
    
     cout <<'\n';
    
    cout << "STATISTICS" <<'\n';
    cout << "Maximum number of planes in landing queue was: " << '\n';
    cout << "Average minutes spent waiting to land:  " << '\n';
    cout << "Maximum number of planes in takeoff queue was:  " << '\n';
    cout << "Average minutes spent waiting to takeoff:"  <<'\n';
    
     cout <<'\n';
    
    return 0;
    
}

