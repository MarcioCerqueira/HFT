#pragma once

#include <vector>

struct Order;

struct OrderBook
{
	std::vector<Order> asks;
	std::vector<Order> bids;
};