#pragma once

#include <cstdint>
#include <string>
#include "Data.hpp"

class Data;

class Serializer
{
	public:
			Serializer(void);
			Serializer(const Serializer &serial);
			Serializer &operator=(const Serializer &serial);

			~Serializer(void);
			static uintptr_t	serialize(Data* ptr);
			static Data			*deserialize(uintptr_t raw);
};
