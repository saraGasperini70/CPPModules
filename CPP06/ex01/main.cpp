#include "Serializer.hpp"

int	main(void)
{
	Data data;
	Data *dataPtr = &data;

	std::cout << "Original Data pointer: " << dataPtr << std::endl;

	uintptr_t raw = Serializer::serialize(dataPtr);
	std::cout << "Serialized Data pointer (uintptr_t): " << raw << std::endl;

	Data *deserializedDataPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data pointer: " << deserializedDataPtr << std::endl;

	return 0;
}
