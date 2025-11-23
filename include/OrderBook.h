#pragma once

#include <vector>

struct Order;

struct OrderBook
{
	std::vector<Order> orders;
};