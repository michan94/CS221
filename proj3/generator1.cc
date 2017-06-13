0#include <stdio.h>

#include <stdio.h>
#include <iostream>
#include <cstdlib> // for atoi
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


//generator to see insert elements NOT IN ORDER, we anticipate to point out which one is the sl, since inserting elements randomly is the worst case for sl, will see O(n) time

using namespace std;
int main(int argc, char* argv[])
{
    if (argc != 2) // remember, argv[0] is the program name
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1;
    }
    //int randomNum;
    
    srand (time(NULL));

    
    int n = atoi(argv[1]);
    //for(int i = 1; i <= n; i++) {
    //    randomNum = rand() % 1000000 + 1;
    //    cout << "I " << randomNum << endl;
    //}
    for(int i = 1; i <= n; i++) {
    	cout << "I " << i << endl;	
    }
    for(int i = 1; i <= n; i++) {
	cout << "F " << i << endl;
    } 	
    return 0;
}
