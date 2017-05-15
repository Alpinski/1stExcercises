#include <iostream>

int main()
{
	int num, num1;

	std::cin >> num >> num1;

	std::cout << "\nFirstNumber " << num << std::endl;
	std::cout << "\nSecondNumber " << num1 << std::endl;

	num = num - num1;
	num1 = num + num1;
	num = num1 - num;

	std::cout << "\nAfterSwapFirst " << num << std::endl;
	std::cout << "\nAfterSwapSecond " << num1 << std::endl;
	system("pause");

	return 0;

}