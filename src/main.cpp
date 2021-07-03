#include <iostream>
#include "datastructures/ThreadsafeStack.h"
#include "datastructures/threadsafe_queue.h"

#include<vector>

using namespace std;

set

int main(int argc, char *argv[])
{
	//Threadsafe stack
	threadsafe_stack<int> ts;
	ts.push(1);
	ts.push(2);
	try{
		std::cout << ts.pop() << std::endl;
		auto n = ts.pop();
		std::cout << n << std::endl;
		ts.push(*n);
		std::cout << *ts.pop() << std::endl;
		std::cout << *ts.pop() << std::endl;
		//int n = ts.pop();
		//std::cout << n << std::endl;
	}
	catch(empty_stack ex)
	{
		std::cout<< ex.what() << std::endl;
	}
	
	
	int arr[4][4] = {0};


	
	
}