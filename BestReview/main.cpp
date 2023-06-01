#include <iostream>
#include <string>
#include <vector>
#include <C:\Users\MY\source\repos\BestReview\BestReview\Wheel.cpp>

using namespace std;

int go(int a, int b){
	if (a < 0 || b < 0) throw std::invalid_argument("should be bigger than 0\n");
	if (a > 10 || b > 10) throw std::out_of_range("should be smaller than 10\n");
	return a + b;
}

int main()
{
	try {
		go(0, 11);
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	

	return 0;
}
