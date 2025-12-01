#include <iostream>
#include "Venue.h"
#include "Gateway.h"
#include "Order.h"

int main(int argc, char* argv[]) 
{
	//NOLINTBEGIN -> Suppress the magic number warning
	Venue nyseVenue("NYSE");
	nyseVenue.addOrder({ .ID = 1, .venueID = nyseVenue.getID(), .volume = 100, .price = 50.5, .side = OrderSide::Bid });
	nyseVenue.addOrder({ .ID = 2, .venueID = nyseVenue.getID(), .volume = 200, .price = 51.0, .side = OrderSide::Ask });
	nyseVenue.addOrder({ .ID = 3, .venueID = nyseVenue.getID(), .volume = 150, .price = 50.75, .side = OrderSide::Bid });
	nyseVenue.addOrder({ .ID = 4, .venueID = nyseVenue.getID(), .volume = 250, .price = 51.25, .side = OrderSide::Ask });

	Venue nasdaqVenue("NASDAQ");
	nasdaqVenue.addOrder({ .ID = 5, .venueID = nasdaqVenue.getID(), .volume = 200, .price = 50.5, .side = OrderSide::Ask });
	nasdaqVenue.addOrder({ .ID = 6, .venueID = nasdaqVenue.getID(), .volume = 400, .price = 101.0, .side = OrderSide::Ask });
	nasdaqVenue.addOrder({ .ID = 7, .venueID = nasdaqVenue.getID(), .volume = 350, .price = 100.75, .side = OrderSide::Bid });
	nasdaqVenue.addOrder({ .ID = 8, .venueID = nasdaqVenue.getID(), .volume = 450, .price = 101.25, .side = OrderSide::Ask });
	//NOLINTEND

	Gateway gateway;
	gateway.addVenue(nyseVenue);
	gateway.addVenue(nasdaqVenue);
	return 0;
}