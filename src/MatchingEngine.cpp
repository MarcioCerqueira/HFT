#include "MatchingEngine.h"

#include "Order.h"
#include "OrderBook.h"
#include "Trade.h"

std::vector<Trade> MatchingEngine::match(const Order& order, const OrderBook& orderBook)
{
	std::vector<Trade> trades;
	unsigned int remainingVolume = order.volume;
	if (order.side == OrderSide::Bid)
	{
		for (auto it = orderBook.asks.rbegin(); it != orderBook.asks.rend(); ++it)
		{
			const auto& ask = *it;
			if (ask.price > order.price || remainingVolume == 0)
			{
				break;
			}
			const unsigned int tradeVolume = std::min(remainingVolume, ask.volume);
			trades.push_back(Trade{ .ID = nextTradeID, .askID = ask.ID, .bidID = order.ID, .volume = tradeVolume });
			remainingVolume -= tradeVolume;
			++nextTradeID;
		}
		return trades;
	}

	if (order.side == OrderSide::Ask)
	{
		for (auto it = orderBook.bids.rbegin(); it != orderBook.bids.rend(); ++it)
		{
			const auto& bid = *it;
			if (bid.price < order.price || remainingVolume == 0)
			{
				break;
			}
			const unsigned int tradeVolume = std::min(remainingVolume, bid.volume);
			trades.push_back(Trade{ .ID =  nextTradeID, .askID = order.ID, .bidID = bid.ID, .volume = tradeVolume });
			remainingVolume -= tradeVolume;
			++nextTradeID;
		}
		return trades;
	}

	return trades;
}