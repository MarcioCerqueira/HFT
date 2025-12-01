#include "Gateway.h"
#include "BookBuilder.h"

#include <ranges>

using namespace std;

void Gateway::addVenue(Venue& venue)
{
	venueMap.emplace(venue.getID(), venue);
	sendPriceUpdates(venue.getID(), venue.getOrders());
}

void Gateway::sendPriceUpdates(const std::string& venueID, const std::unordered_map<uint64_t, Order>& orderMap)
{
	for (const auto& [orderID, order] : orderMap)
	{
		bookBuilder.addOrder(order);
	}
	bookBuilder.printOrderBook();
}

void Gateway::updateVenue(const std::string& venueID, const Order& order)
{
	auto venueFound = venueMap.find(venueID);
	if (venueFound == venueMap.end())
	{
		return;
	}

	auto orderFound = venueFound->second.get().getOrders().find(order.ID);
	if (orderFound == venueFound->second.get().getOrders().end())
	{
		return;
	}

	orderFound->second = order;
}