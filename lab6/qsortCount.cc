#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps = 0;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

float c(int n) {
	if (n <= 1) return 0;
	float sum = 0.0;
	for (int m=1; m <= n; m++) {
		sum += n-1 + c(m-1) + c(n-m);
	}	
	return sum / n;
}
// C(n) = Summation of [n-1+C(m-1)+C(n-m)]/n	from m=1 to n

int qc(int n) {
	int pivot = rand() % n + 1;
	if (n <= 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}	
	else {
		return qc(pivot) + qc(n - pivot - 1);
	}	
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		if (x[i] < x[a]) {
			swap(x[++m], x[i]);
		}	
		comps++;
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	int repetitions = 100;
	int j = repetitions;
	x = new int[NN];
	while (j > 0) {
		for (int i=0; i<NN; ++i) {
			x[i] = rand() % NN;
		}
		quicksort(0, NN-1);	
		j--;
	}
	for (int i=0; i<NN; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << "Average comparisons: " << comps/repetitions << std::endl;
	//10000 - 11000 average comparisons
	std::cout << std::endl;

	delete[] x;
	return 0;
}

/*	
5a)	O(nlgn)
5b) O(n^2)

5c) Worst case in the instance where the pivot in each recursive
	iteration is the smallest or largest element in the list. If this
	was the case, each recursive call processes a list that is only 1 
	element smaller than the last

5d) This is an in-place sort. We destroy the previous list after each
	recursive call and return the sorted one

http://stackoverflow.com/questions/20375482/is-stable-and-in-place-the-same	

*/




// #include <iostream>
// #include <ctime>
// #include <cstdlib>
// #include <math.h>
// 
// using namespace std;
// 
// int * x;
// int comps = 0;
// 
// void swap(int & a, int & b) {
// 	int tmp = a;
// 	a = b;
// 	b = tmp;
// }
// 
// int randint(int a, int b) {
// 	return a + (rand() % (b - a + 1));
// }
// 
// float c(int n) {
// 	if (n <= 1) return 0;
// 	float sum = 0.0;
// 	for (int m=1; m <= n; m++) {
// 		sum += n-1 + c(m-1) + c(n-m);
// 	}	
// 	return sum / n;
// }
// // C(n) = Summation of [n-1+C(m-1)+C(n-m)]/n	from m=1 to n
// 
// int qc(int n) {
// 	int pivot = rand() % n + 1;
// 	if (n <= 1) {
// 		return 0;
// 	}
// 	if (n == 2) {
// 		return 1;
// 	}	
// 	else {
// 		return qc(pivot) + qc(n - pivot - 1);
// 	}	
// }
// 
// void quicksort(int a, int b) {
// 	if (a >= b) return;
// 	int p = randint(a,b); // pivot
// 	swap(x[a], x[p]);
// 	int m = a;
// 	int i;
// 	// in-place partition:
// 	for (i = a+1; i <= b; i++) {
// 		if (x[i] < x[a])
// 			swap(x[++m], x[i]);
// 		comps++;	
// 	}
// 	swap(x[a],x[m]);
// 	quicksort(a, m-1);
// 	quicksort(m+1, b);
// }
// 
// #define NN 20
// 
// int main(int argc, char *argv[]) {
// 	srand(time(0));
// 
// 	// change the following code
// 	int repetitions = 100;
// 	x = new int[NN];
// 	int j = 100; //# of repetitions
// 	/*
// 	for (int i=0; i<NN; ++i) {
// 		x[i] = rand() % NN;
// 	}
// 	*/
// 	while (j > 0) {
// 		for (int i = 0; i < NN; ++i) {
// 			x[i] = rand() % NN;
// 		}
// 		quicksort(0, NN - 1);
// 		for (int i = 0; i < NN; ++i) {
// 			cout << x[i] << " ";
// 		}
// 		j--;
// 		delete[] x;
// 		cout << "Number of comparisons: " << comps << endl;
// 		cout << endl;
// 	}
// 	return 0;
// 	
// }
// 
// /*	
// 5a)	O(nlgn)
// 5b) O(n^2)
// 
// 5c) Worst case in the instance where the pivot in each recursive
// 	iteration is the smallest or largest element in the list. If this
// 	was the case, each recursive call processes a list that is only 1 
// 	element smaller than the last
// 
// 5d) This is an in-place sort. We destroy the previous list after each
// 	recursive call and return the sorted one
// 
// http://stackoverflow.com/questions/20375482/is-stable-and-in-place-the-same	
// 
// */	
// 
