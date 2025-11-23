#pragma once

#include <string>

enum class OrderType
{
	Ask,	 // Order to sell
	Bid,	 // Order to buy
	Unknown  // Unknown order type
};

struct Order
{
	std::string ID;
	unsigned int volume{ 0 };
	double price{ 0 };
	OrderType type{ OrderType::Unknown };
};