#pragma once

#include <unordered_map>
#include <string>

#include "OrderBook.h"

struct Order;

class BookBuilder
{
public:
	void addOrders(const std::unordered_map<std::string, Order>& orderMap);
	void printOrderBook() const;

private:
	OrderBook orderBook;
};