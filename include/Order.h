#pragma once

#include <string>

enum class OrderSide
{
	Ask,	 // Order to sell
	Bid,	 // Order to buy
	Unknown  // Unknown order side
};

struct Order
{
	uint64_t ID{ 0 };
	std::string venueID;
	unsigned int volume{ 0 };
	double price{ 0 };
	OrderSide side{ OrderSide::Unknown };

	bool operator<(const Order& other) const
	{
		return price < other.price;
	}

	bool operator>(const Order& other) const
	{
		return price > other.price;
	}
};