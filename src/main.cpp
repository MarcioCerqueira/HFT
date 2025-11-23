#include <iostream>
#include "Venue.h"
#include "Gateway.h"
#include "Order.h"

int main(int argc, char* argv[]) 
{
	//NOLINTBEGIN -> Suppress the magic number warning
	Venue nyseVenue("NYSE");
	nyseVenue.addOrder({ .ID = "Order1", .volume = 100, .price = 50.5, .type = OrderType::Bid });
	nyseVenue.addOrder({ .ID = "Order2", .volume = 200, .price = 51.0, .type = OrderType::Ask });
	nyseVenue.addOrder({ .ID = "Order3", .volume = 150, .price = 50.75, .type = OrderType::Bid });
	nyseVenue.addOrder({ .ID = "Order4", .volume = 250, .price = 51.25, .type = OrderType::Ask });
	//NOLINTEND

	Gateway gateway;
	nyseVenue.sendOrders(gateway);
	return 0;
}