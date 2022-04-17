#include "MatchingEngine.hpp"

int main() {
    auto engine = Engine("AAPL");
    auto order = Order("AAPL", 712.12, OrderType::Bid);

    engine.addOrder(order);
    return 0;
}