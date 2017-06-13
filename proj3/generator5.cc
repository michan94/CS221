#include <stdio.h>

#include <stdio.h>
#include <iostream>
#include <cstdlib> // for atoi
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;

int main( int argc, char* argv[]) {
	if (argc != 2) {
		cerr << "Wrong number of arguments!" << endl;
		return 1;
	}
	int n = atoi(argv[1]);
	for(int i = 1; i <= n/2; i++) {
		cout << "I " << i << endl;
	}
	for(int k = 1; k <= n/100000; k++) {
		for(int j = 1; j <= 50000; j++) {
			cout << "F " << (k * 50000) << endl;
		}
	}
	return 0;
}
