#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <cfloat>
# include <sstream>
# include <typeinfo>
# include <exception>
# include <stdint.h>
# include <cstring>

struct Data
{
	int i;
	float f;
	double d;
	char c;
	std::string str;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &src);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &out, const Data &src);
#endif
