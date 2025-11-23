#pragma once

#include <string>
#include <vector>
#include "Order.h"

class Gateway;

class Venue
{

public: 
	Venue(const std::string& id) : ID(id) {}
	void addOrder(const Order& order);
	void sendOrders(const Gateway& gateway) const;

private: 
	std::string ID;
	std::vector<Order> orders;
};