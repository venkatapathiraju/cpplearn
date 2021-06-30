#include <iostream>
#include <thread>
#include <chrono>

void hello()
{
	std::cout<<std::this_thread::get_id();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Hello world in new thread" << std::endl;
}

void funcwithParam(std::string str)
{
	std::cout << "funcwithParam " << str << std::endl;
}

class background_task
{
	public:
	void operator()() const{
		std::cout<<std::this_thread::get_id();
		std::cout << "background_task " << std::endl;
	}
};

int main(int argc, char *argv[])
{
	background_task bt;
	std::thread t(hello);
	std::thread t2(bt); // pass function object
	std::thread t3((background_task())); //extraset of parenthesis
	std::thread t4{background_task()}; //pass function object as Uniform initalization syntax
	//lambda
	std::thread tlambda([]{
		std::cout<<std::this_thread::get_id();
		std::cout << "lambda thread" << std::endl;
	});
	std::thread t5{funcwithParam,"hello"};
	t.join();
	t2.join();
	//std::cout << "Hello world!" << std::endl;
}