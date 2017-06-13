// b)

#include <iostream>

using namespace std;

int globalarr[10];

void fill_array(int first_value, int increment); // function prototype

void fill_array(int first_value, int increment)
{
	for (int i=0; i<10; i++)
	{
		if (i != 0)
		{
			globalarr[i] = globalarr[i-1] + increment;
		}
		else
		{
			globalarr[i] = first_value;
		}
	}
}

int main()
{
	int x;
	int y;
	cout << "Input starting number: " << endl;
	cin >> x;
	cout << "Input increment: " << endl;
	cin >> y;
	cout << "Your array is: " << endl;
	fill_array(x, y);
	for(int i =0; i < 10; i++) {
		std::cout << globalarr[i] << std::endl;
	}
	cout << endl;
	return 0;
}



 



