#pragma once

#include <unordered_map>
#include <string>

#include "OrderBook.h"
#include "MatchingEngine.h"

struct Order;
enum class OrderSide;

class BookBuilder
{
public:
	void addOrder(const Order& order);
	void printOrderBook() const;

private:
	template <typename Comparator>
	void addOrder(std::vector<Order>& orders, const Order& order, Comparator comparator);
	void printOrders(const std::vector<Order>& orders) const;
	void updateOrderBook(const std::vector<Trade>& trades);
	void updateOrderBook(const Trade& trade, std::vector<Order>& orders, OrderSide orderSide);

	OrderBook orderBook;
	MatchingEngine matchingEngine;
};