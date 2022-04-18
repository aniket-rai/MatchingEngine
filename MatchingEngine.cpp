#include "MatchingEngine.hpp"

int main() {
    auto engine = Engine("AAPL");

    engine.addOrder(Order("AAPL", 711.12, 10, OrderType::Bid));
    engine.addOrder(Order("AAPL", 711.13, 10, OrderType::Bid));

    engine.addOrder(Order("AAPL", 712.12, 10, OrderType::Ask));
    engine.addOrder(Order("AAPL", 712.13, 10, OrderType::Ask));
    engine.getPair();

    return 0;
}