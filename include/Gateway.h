#pragma once

#include <vector>

struct Order;

class Gateway
{
public:
	void receiveOrders(const std::vector<Order>& order) const;
};