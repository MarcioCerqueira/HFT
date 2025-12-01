#pragma once

#include <string>
#include <unordered_map>
#include "Order.h"

class Gateway;

class Venue
{

public: 
	Venue(const std::string& id) : ID(id) {}

	void addOrder(const Order& order);

	std::string getID() const { return ID; }
	std::unordered_map<uint64_t, Order> getOrders() const { return orders; }

private: 
	std::string ID;
	std::unordered_map<uint64_t, Order> orders;
};