//
//  generator3.cpp
//  
//
//
//

#include <stdio.h>

#include <stdio.h>
#include <iostream>
#include <cstdlib> // for atoi
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



using namespace std;
int main(int argc, char* argv[])
{
    if (argc != 2) // remember, argv[0] is the program name
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1;
    }
    int randomNum;
    
    srand (time(NULL));

    
    int n = atoi(argv[1]);
    for(int i = 1; i <= n; i++) {
        randomNum = rand() % 1000000 + 1;
        cout << "I " << randomNum << endl;
    }
    return 0;
}

