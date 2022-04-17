#include "Engine.hpp"

void Engine::addOrder(Order& order) {
    if (this->_ticker == order.getTicker()) {
        _bids.push(std::make_unique<Order>(order));
    } else {
        std::cout << "WRONG TICKER inserted into " << this->_ticker << std::endl;
    }
}

void Engine::addOrder(Order&& order) {
    if (this->_ticker == order.getTicker()) {
        if (order.getType() == OrderType::Bid) {
            _bids.push(std::make_unique<Order>(order));
        } else {
            _asks.push(std::make_unique<Order>(order));
        }
    } else {
        std::cout << "WRONG TICKER inserted into " << this->_ticker << std::endl;
    }
}

void Engine::getBid() {
    std::cout << "Best bid for " << this->_ticker << ":\n" << " - ID: " << _bids.top()->getId() << std::endl << " - Value: " << _bids.top()->getValue() << std::endl;
}

void Engine::getAsk() {
    std::cout << "Best ask for " << this->_ticker << ":\n" << " - ID: " << _asks.top()->getId() << std::endl << " - Value: " << _asks.top()->getValue() << std::endl;
}

void Engine::getPair() {
    std::cout << this->_ticker << ": " << _bids.top()->getValue() << "/" << _asks.top()->getValue() << std::endl;
}

void Engine::deleteOrder(int orderId) {

}