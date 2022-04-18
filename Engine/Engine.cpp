#include "Engine.hpp"

template <typename T>
void Engine::addOrder(T&& order) {
    if (this->_ticker == order.getTicker()) {
        if (order.getType() == OrderType::Bid) {
            _bids.insert(std::make_unique<Order>(order));
        } else {
            _asks.insert(std::make_unique<Order>(order));
        }
    } else {
        std::cout << "WRONG TICKER inserted into " << this->_ticker << std::endl;
    }
}
template void Engine::addOrder<Order>(Order&& order);
template void Engine::addOrder<Order&>(Order& order);

void Engine::getBid() {
    auto order = _bids.begin()->get();
    std::cout << "Best bid for " << this->_ticker << ":\n" << " - ID: " << order->getId() << std::endl << " - Value: " << order->getValue() << std::endl;
}

void Engine::getAsk() {
    auto order = _asks.begin()->get();
    std::cout << "Best ask for " << this->_ticker << ":\n" << " - ID: " << order->getId() << std::endl << " - Value: " << order->getValue() << std::endl;
}

void Engine::getPair() {
    std::cout << this->_ticker << ": " << _bids.begin()->get()->getValue() << "/" << _asks.begin()->get()->getValue() << std::endl;
}

template <typename T>
void Engine::deleteOrder(T&& orderId) {

}