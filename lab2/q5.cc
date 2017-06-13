#include <iostream>
using namespace std;

int main () {
int x = 5, y = 15;
int * p1, *p2;
// value of x y p1 p2
// 5 15 uninit uninit
std::cout << p1 << std::endl;
std::cout << p2 << std::endl;

std:: endl;

p1 = &x;
std::cout << x << std::endl;
std::cout << y<< std::endl;
std::cout << p1 << std::endl;
std::cout << p2 << std::endl;
//
std::endl;

p2 = &y;
std::cout << x << std::endl;
std::cout << y<< std::endl;
std::cout << p1 << std::endl;
std::cout << p2 << std::endl;
//
std::endl;

*p1 = 6;
std::cout << x << std::endl;
std::cout << y<< std::endl;
std::cout << p1 << std::endl;
std::cout << p2 << std::endl;
//
*p1 = *p2;
std::cout << x << std::endl;
std::cout << y<< std::endl;
std::cout << p1 << std::endl;
std::cout << p2 << std::endl;
//
p2 = p1;
std::cout << x << std::endl;
std::cout << y<< std::endl;
std::cout << p1 << std::endl;
std::cout << p2 << std::endl;
//
*p1 = *p2+10;
std::cout << x << std::endl;
std::cout << y<< std::endl;
std::cout << p1 << std::endl;
std::cout << p2 << std::endl;
//
return 0;
}
