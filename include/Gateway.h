#pragma once

#include <unordered_map>
#include <vector>
#include <functional>

#include "Venue.h"

struct Order;

class Gateway {
public:
	void addVenue(Venue& venue);

private:
	void sendPriceUpdates(const std::string& venueID, const std::unordered_map<std::string, Order>& order) const;
	void updateVenue(const std::string& venueID, const Order& order);

	std::unordered_map<std::string, std::reference_wrapper<Venue>> venueMap;
};