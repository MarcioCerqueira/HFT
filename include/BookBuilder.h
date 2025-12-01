#pragma once

#include <unordered_map>
#include <string>

#include "OrderBook.h"

struct Order;

class BookBuilder
{
public:
	void addOrder(const Order& order);
	void printOrderBook() const;

private:
	template <typename Comparator>
	void addOrder(std::vector<Order>& orders, const Order& order, Comparator comparator);
	void printOrders(const std::vector<Order>& orders) const;

	OrderBook orderBook;
};