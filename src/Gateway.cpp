#include "Gateway.h"

using namespace std;

void Gateway::addVenue(Venue& venue)
{
	venueMap.emplace(venue.getID(), venue);
	sendPriceUpdates(venue.getID(), venue.getOrders());
}

void Gateway::sendPriceUpdates(const std::string& venueID, const std::unordered_map<std::string, Order>& order) const
{
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