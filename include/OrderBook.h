#pragma once

#include <vector>

struct Order;

struct OrderBook
{
	// We store the asks and bids in a vector rather than a map to avoid the overhead of memory (node) allocations.
	// See https://www.youtube.com/watch?v=sX2nF1fW7kI for a better discussion about that.
	std::vector<Order> asks;
	std::vector<Order> bids;
};