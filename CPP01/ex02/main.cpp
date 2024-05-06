#include <iostream>
#include <string>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR;

	stringPTR = &str;
	std::string	&stringREF = str;
	std::cout << "String address: " << &str << std::endl;
	std::cout << "Pointer address: " << stringPTR << std::endl;
	std::cout << "Reference address: " << &stringREF << std::endl;
	std::cout << "Pointer string: " << *stringPTR << std::endl;
	std::cout << "Reference string: " << stringREF << std::endl;
}
