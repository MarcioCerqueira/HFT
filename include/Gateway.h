#pragma once

#include <unordered_map>
#include <vector>
#include <functional>

#include "BookBuilder.h"
#include "Venue.h"

class Gateway 
{
public:
	void addVenue(Venue& venue);

private:
	void sendPriceUpdates(const std::string& venueID, const std::unordered_map<std::string, Order>& orderMap);
	void updateVenue(const std::string& venueID, const Order& order);

	std::unordered_map<std::string, std::reference_wrapper<Venue>> venueMap;
	BookBuilder bookBuilder;
};