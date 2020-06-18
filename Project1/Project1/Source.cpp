#include <iostream>

int x = 0;

int main()
{
	while (x < 100)
	{
		x++;
		if (x % 3 == 0 || x% 5 == 0)
		{
			//divisible by 3 also divisble by 5!
			if (x % 3 == 0)
			{
				std::cout << "Fizz";
			}
			if (x % 5 == 0)
			{
				std::cout << "Buzz" << std::endl;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << x << std::endl;
		}
	}
	std::cout << "Hello World!" << std::endl;
	return 0;

	//Write a program that prints the numbers from 1 to 100. 
	//But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”. 
	//For numbers which are multiples of both three and five print “FizzBuzz”. 
}