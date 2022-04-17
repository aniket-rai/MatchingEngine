#include "Engine.hpp"

void Engine::addOrder(Order& order) {
    if (this->_ticker == order.getTicker()) {
        _bids.push(std::make_unique<Order>(order));
    } else {
        std::cout << "WRONG TICKER inserted into " << this->_ticker << std::endl;
    }
}

void Engine::deleteOrder(int orderId) {

}