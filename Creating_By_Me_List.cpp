#include <iostream>
#include "forward_list.h"

int main()
{
	List<int> mylist;
	mylist.push_back(10);
	mylist.push_back(20);
	mylist.push_back(30);
	mylist.push_front(40);
	std::cout<<mylist.getSize()<<std::endl;
	for(int i{};i<mylist.getSize();++i)
	{
		std::cout<<mylist[i]<<std::endl;
	}
	std::cout<<mylist.getSize()<<std::endl;
	mylist.pop_front();

        for(int i{};i<mylist.getSize();++i)
        {
                std::cout<<mylist[i]<<std::endl;
        }

}
