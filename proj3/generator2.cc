//
//  generator2.cpp
//  
//
//  Created by Sandra Yoo on 2017-03-30.
//
//
#include <stdio.h>
#include <iostream>
#include <cstdlib> // for atoi


//generator to see FIND on mtf

using namespace std;
int main(int argc, char* argv[])
{
    if (argc != 2) // remember, argv[0] is the program name
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    for(int i = 1; i <= n/2; i++) {
        cout << "I " << i << endl;
    }
    
    for(int i = 1; i <= n/2; i++) {
        cout << "F " << i << endl;
    }
    
    return 0;
}

