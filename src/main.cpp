
#include "myheaders.h"
using namespace std;

void scribble()
{
	char *str = "Hello";
	char *str1 = "123";
	str = str1;
	cout << *str1;

	int myarray[5];
	
	auto myarrayptr = make_unique<int[]>(10);
	for(int i=0; i < 5 ; i++)
	{
		myarrayptr[i] = i;
	}
	cout << endl << myarrayptr[0] + 4  << endl;
	
}

int main(int argc, char *argv[])
{
	learnvector::run();
	
	scribble();
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