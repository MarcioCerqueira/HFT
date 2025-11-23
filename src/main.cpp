#include <iostream>
#include "Venue.h"
#include "Gateway.h"
#include "Order.h"

int main(int argc, char* argv[]) 
{
	//NOLINTBEGIN -> Suppress the magic number warning
	Venue nyseVenue("NYSE");
	nyseVenue.addOrder({ .ID = "Order1", .venueID = nyseVenue.getID(), .volume = 100, .price = 50.5, .type = OrderType::Bid});
	nyseVenue.addOrder({ .ID = "Order2", .venueID = nyseVenue.getID(), .volume = 200, .price = 51.0, .type = OrderType::Ask });
	nyseVenue.addOrder({ .ID = "Order3", .venueID = nyseVenue.getID(), .volume = 150, .price = 50.75, .type = OrderType::Bid });
	nyseVenue.addOrder({ .ID = "Order4", .venueID = nyseVenue.getID(), .volume = 250, .price = 51.25, .type = OrderType::Ask });
	//NOLINTEND

	Gateway gateway;
	gateway.addVenue(nyseVenue);
	return 0;
}