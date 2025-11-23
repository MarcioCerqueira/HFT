#include "Venue.h"
#include "Gateway.h"
#include "Order.h"

void Venue::addOrder(const Order& order)
{
	orders[order.ID] = order;
}