#include "MatchingEngine.hpp"

int main() {
    auto engine = Engine("AAPL");

    auto order = Order("AAPL", 711.12, 10, OrderType::Bid);
    engine.addOrder(order);
    engine.addOrder(Order("AAPL", 711.12, 10, OrderType::Bid));

    engine.getPair();

    return 0;
}