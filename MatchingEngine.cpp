#include "MatchingEngine.hpp"

int main() {
    auto engine = Engine("AAPL");

    engine.addOrder(Order("AAPL", 711.12, OrderType::Bid));
    engine.addOrder(Order("AAPL", 711.13, OrderType::Bid));

    engine.addOrder(Order("AAPL", 712.12, OrderType::Ask));
    engine.addOrder(Order("AAPL", 712.13, OrderType::Ask));
    engine.getPair();

    

    return 0;
}