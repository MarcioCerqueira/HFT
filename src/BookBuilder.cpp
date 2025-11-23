#include "BookBuilder.h"

#include <algorithm>
#include <iostream>
#include "Order.h"

void BookBuilder::addOrders(const std::unordered_map<std::string, Order>& orderMap)
{
	for (const auto& [orderID, order] : orderMap)
	{
		if (order.type == OrderType::Ask)
		{
			orderBook.asks.push_back(order);
		}
		else if (order.type == OrderType::Bid)
		{
			orderBook.bids.push_back(order);
		}
	}

	std::sort(orderBook.asks.begin(), orderBook.asks.end(), [](const Order& a, const Order& b) {
		return a.price < b.price;
	});

	std::sort(orderBook.bids.begin(), orderBook.bids.end(), [](const Order& a, const Order& b) {
		return a.price > b.price;
	});
}

void BookBuilder::printOrderBook() const
{
	std::cout << "Order Book:" << std::endl;
	std::cout << "Asks:" << std::endl;
	for (const auto& ask : orderBook.asks)
	{
		std::cout << "ID: " << ask.ID << ", Venue: " << ask.venueID << ", Price: " << ask.price << ", Volume: " << ask.volume << std::endl;
	}
	std::cout << "Bids:" << std::endl;
	for (const auto& bid : orderBook.bids)
	{
		std::cout << "ID: " << bid.ID << ", Venue: " << bid.venueID << ", Price: " << bid.price << ", Volume: " << bid.volume << std::endl;
	}
}