#include "BookBuilder.h"

#include <algorithm>
#include <iostream>
#include "Order.h"
#include "Trade.h"

void BookBuilder::addOrder(const Order& order)
{
	// Even though it seems counter-intuitive, it is better to sort best prices at the end of the collection
	// in order to minimize copies when buying/selling from the order book.
	if (order.side == OrderSide::Ask)
	{
		addOrder(orderBook.asks, order, std::less<Order>());
	}

	if (order.side == OrderSide::Bid)
	{
		addOrder(orderBook.bids, order, std::greater<Order>());
	}

	updateOrderBook(matchingEngine.match(order, orderBook));
}

template <typename Comparator>
void BookBuilder::addOrder(std::vector<Order>& orders, const Order& order, Comparator comparator)
{
	// Let's use lambda (functor) instead of std::function for better performance.
	auto comparatorLambda = [order, comparator](const Order& currentOrder) { return comparator(currentOrder, order); };

	// According to this performance benchmark (https://www.youtube.com/watch?v=sX2nF1fW7kI), 
	// linear search provides better than binary search for actual production data. 
	// Hence, we have chosen to stick with this solution for now.
	auto it = std::find_if(orders.begin(), orders.end(), comparatorLambda);
	orders.insert(it, order);
}

void BookBuilder::printOrderBook() const
{
	std::cout << "Order Book:" << std::endl;
	std::cout << "Asks:" << std::endl;
	printOrders(orderBook.asks);
	std::cout << "Bids:" << std::endl;
	printOrders(orderBook.bids);
	std::cout << std::endl;
}

void BookBuilder::printOrders(const std::vector<Order>& orders) const
{
	for (auto it = orders.rbegin(); it != orders.rend(); ++it)
	{
		std::cout << "ID: " << it->ID << ", Venue: " << it->venueID << ", Price: " << it->price << ", Volume: " << it->volume << std::endl;
	}
}

void BookBuilder::updateOrderBook(const std::vector<Trade>& trades)
{
	for (const auto& trade : trades)
	{
		updateOrderBook(trade, orderBook.asks, OrderSide::Ask);
		updateOrderBook(trade, orderBook.bids, OrderSide::Bid);
	}
}

void BookBuilder::updateOrderBook(const Trade& trade, std::vector<Order>& orders, OrderSide orderSide)
{
	const uint64_t targetID = (orderSide == OrderSide::Ask) ? trade.askID : trade.bidID;
	auto it = std::find_if(orders.rbegin(), orders.rend(), [targetID](const Order& order) { return order.ID == targetID; });

	if (it == orders.rend())
	{
		return;
	}

	if (it->volume > trade.volume)
	{
		it->volume -= trade.volume;
	}
	else
	{
		std::reverse_iterator(orders.erase(std::next(it).base()));
	}
}