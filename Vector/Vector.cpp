#include "Vector.h"
#include <iostream>

int main()
{
	Vector<int> vec;
	//std::cout<<vec[0]<<std::endl;
	for(int i = 0; i < 10; ++i) vec.push_Back(i*10);
	vec.erase(4);
	for(int i = 0; i < vec.Size(); ++i) std::cout << vec[i]<<std::endl;
	std::cout<<vec.Size()<<std::endl;
}	
