// a)

#include <iostream>
using namespace std;

const int HOW_BIG = 10;
int globalarr[HOW_BIG];
void fill_array(); // function prototype

void fill_array()
{
	for (int i=0; i<10; i++)
	{
		globalarr[i] = i + 1;
		std::cout << globalarr[i] << std::endl;
	}
}

int main()
{
	fill_array();
	return 0;
}

