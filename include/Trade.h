#pragma once

#include <cstdint>

struct Trade
{
	uint64_t ID{ 0 };
	uint64_t askID{ 0 };
	uint64_t bidID{ 0 };
	unsigned int volume{ 0 };
};