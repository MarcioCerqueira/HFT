#pragma once

#include <vector>

struct Order;
struct OrderBook;
struct Trade;

class MatchingEngine
{
public:
	std::vector<Trade> match(const Order& order, const OrderBook& orderBook);

private:
	uint64_t nextTradeID{ 1 };
};