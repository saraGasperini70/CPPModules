#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "func.hpp"

int main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
