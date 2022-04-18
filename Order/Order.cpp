#include "Order.hpp"

int Order::nextOrderId = 0;

// Constructor
Order::Order(const std::string& ticker, const double& value, const int& quantity, const OrderType& type) {
    this->_id = nextOrderId++;
    this->_ticker = ticker;
    this->_value = value;
    this->_quantity = quantity;
    this->_type = type;
}

// Perfectly forwarded helper
template <typename T>
void Order::copyConstructorHelper(T&& order) {
    this->_id = order._id;
    this->_ticker = order._ticker;
    this->_value = order._value;
    this->_quantity = order._quantity;
    this->_type = order._type;
}

// Copy constructor
Order::Order(Order& order) {
    this->copyConstructorHelper(order);
}

// Move constructor
Order::Order(Order&& order) noexcept {
    this->copyConstructorHelper(order);
    order._id = -1;
    order._ticker = "";
    order._value = -1;
    order._quantity = -1;
    order._type = OrderType::None;
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

int Order::getQuantity() {
    return this->_quantity;
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