#include "Engine.hpp"

template <typename T>
void Engine::addOrder(T&& order) {
    if (this->_ticker == order.getTicker()) {
        if (!matchOrder(order)) {
            if (order.getType() == OrderType::Bid) {
                _bids.insert(std::make_unique<Order>(order));
            } else {
                _asks.insert(std::make_unique<Order>(order));
            }
        } else {
            std::cout << "ORDER MATCHED!" << std::endl;
        }
    } else {
        std::cout << "WRONG TICKER inserted into " << this->_ticker << std::endl;
    }
}
template void Engine::addOrder<Order>(Order&& order);
template void Engine::addOrder<Order&>(Order& order);

template <typename T>
bool Engine::matchOrder(T&& order) {
    auto orderQty = order.getQuantity();
    double askPrice, bidPrice;
    int askQty, bidQty;

    if (order.getType() == OrderType::Bid) {
        if (this->_asks.size() > 0) {
            askPrice = this->_asks.begin()->get()->getValue();
            askQty = this->_asks.begin()->get()->getQuantity();
        } else {
            return false;
        }

        if(order.getValue() >= askPrice) {
            if(askQty == orderQty) {
                // full bid order can be fullfilled
                this->_asks.erase(this->_asks.begin());
                return true;
            } else if (askQty > orderQty) {
                this->_asks.begin()->get()->setQuantity(askQty - orderQty);
                return false;
            } else {
                order.setQuantity(orderQty - askQty);
                this->_asks.erase(this->_asks.begin());
                this->matchOrder(order);
            }
        }
    } else {
        if (this->_bids.size() > 0) {
            bidPrice = this->_bids.begin()->get()->getValue();
            bidQty = this->_bids.begin()->get()->getQuantity();
        } else {
            return false;
        }
        if(order.getValue() >= bidPrice) {
            if(bidQty == orderQty) {
                // full bid order can be fullfilled
                this->_bids.erase(this->_bids.begin());
                return true;
            } else if (bidQty > orderQty) {
                this->_asks.begin()->get()->setQuantity(bidQty - orderQty);
                return false;
            } else {
                order.setQuantity(orderQty - bidQty);
                this->_bids.erase(this->_bids.begin());
                this->matchOrder(order);
            }
        }
    }
    return false;
}
template bool Engine::matchOrder<Order>(Order&& order);
template bool Engine::matchOrder<Order&>(Order& order);

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
template void Engine::deleteOrder<int>(int&& orderId);
template void Engine::deleteOrder<int&>(int& orderId);