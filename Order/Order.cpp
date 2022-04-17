#include "Order.hpp"

int Order::nextOrderId = 0;

Order::Order(const std::string& ticker, const double& value, const OrderType& type) {
    this->_id = nextOrderId++;
    this->_ticker = ticker;
    this->_value = value;
    this->_type = type;
}

Order::Order(Order& order) {
    this->_id = order._id;
    this->_ticker = order._ticker;
    this->_value = order._value;
    this->_type = order._type;
}

Order::Order(Order&& order) noexcept {
    this->_id = order._id;
    this->_ticker = order._ticker;
    this->_value = order._value;
    this->_type = order._type;

    order._id = -1;
    order._ticker = "";
    order._value = -1;
    order._type = OrderType::None;
}

std::ostream& operator<<(std::ostream& os, const OrderType& type) {
    if (type == OrderType::Bid) {
        os << "Bid";
    } else {
        os << "Ask";
    }

    return os;
}

std::string Order::getTicker() {
    return this->_ticker;
}

int Order::getId() {
    return this->_id;
}

double Order::getValue() {
    return this->_value;
}

OrderType Order::getType() {
    return this->_type;
}

bool Order::operator<(Order& order) {
    if (this->_value == order.getValue()) {
        return this->_id < order.getId();
    } else {
        return this->_value < order.getValue();
    }
}

bool Order::operator>(Order& order) {
    if (this->_value == order.getValue()) {
        return this->_id > order.getId();
    } else {
        return this->_value > order.getValue();
    }
}

bool Order::operator<(std::unique_ptr<Order> order) {
    if (this->_value == order->getValue()) {
        return this->_id < order->getId();
    } else {
        return this->_value < order->getValue();
    }
}

bool Order::operator>(std::unique_ptr<Order> order) {
    if (this->_value == order->getValue()) {
        return this->_id > order->getId();
    } else {
        return this->_value > order->getValue();
    }
}

Order::~Order() {}