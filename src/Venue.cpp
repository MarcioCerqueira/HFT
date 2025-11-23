#include "Venue.h"
#include "Gateway.h"
#include "Order.h"

void Venue::addOrder(const Order& order)
{
	orders.push_back(order);
}

void Venue::sendOrders(const Gateway& gateway) const
{
	gateway.receiveOrders(orders);
}