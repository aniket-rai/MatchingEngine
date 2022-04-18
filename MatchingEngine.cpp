#include "MatchingEngine.hpp"

int main() {
    auto engine = Engine("AAPL");

    engine.addOrder(Order("AAPL", 711, 10, OrderType::Bid));
    // engine.addOrder(Order("AAPL", 712, 10, OrderType::Bid));
    engine.addOrder(Order("AAPL", 711, 10, OrderType::Ask));
    // engine.addOrder(Order("AAPL", 714, 10, OrderType::Ask));

    // engine.getPair();

    return 0;
}