#include "iter.hpp"

void rotate_char(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == 'z')
			str[i] = 'a';
		else if (str[i] == 'Z')
			str[i] = 'A';
		else
			str[i]++;
	}
}

void reverse_int_array(int &elem)
{
	elem = -elem;
}

int	main(void)
{
	int		array[5] = {1, 2, 3, 4, 5};
	std::string	strArray[3] = {"Hello", "World", "!"};

	std::cout << "Original int array:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	::iter(array, 5, reverse_int_array);
	std::cout << "Reversed int array:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	std::cout << "Original string array:" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;
	::iter(strArray, 3, rotate_char);
	std::cout << "Rotated string array:" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;

	return (0);
}
