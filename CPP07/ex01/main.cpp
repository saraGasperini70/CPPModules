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

template void	print_elem<int>(int&);
template void	print_elem<const int>(const int&);
template void	print_elem<std::string>(std::string&);
template void	print_elem<const std::string>(const std::string&);

int	main(void)
{
	int		array[5] = {1, 2, 3, 4, 5};
	std::string	strArray[3] = {"Hello", "World", "!"};
	int  const array2[5] = {5, 4, 3, 2, 1};
	std::string const 	strArray2[3] = {"Hollo", "!", "Worlo"};
	size_t	len = 5;

	std::cout << "Original int array: ";
	for (size_t i = 0; i < len; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	iter(array, len, reverse_int_array);
	std::cout << "Reversed int array: ";
	for (size_t i = 0; i < len; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "Original string array: ";
	for (size_t i = 0; i < 3; i++) {
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	iter(strArray, 3, rotate_char);
	std::cout << "Rotated string array: ";
	for (size_t i = 0; i < 3; i++) {
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "Printing const int array: " << std::endl;
	iter(array2, len, print_elem<const int>);

	std::cout << "Printing string array: " << std::endl;
	iter(strArray2, 3, print_elem<const std::string>);

	return (0);
}
