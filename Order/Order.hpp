#pragma once
#include <iostream>
#include <string>
#include <memory>

#include "../CustomTypes/OrderType.hpp"

class Order {
    static int nextOrderId;

    public:
    Order(const std::string& ticker, const double& value, const OrderType& type);
    Order(Order& order);
    Order(Order&& order) noexcept;
    ~Order();

    bool operator<(Order& order);
    bool operator>(Order& order);
    bool operator<(std::unique_ptr<Order> order);
    bool operator>(std::unique_ptr<Order> order);

    std::string getTicker();
    int getId();
    double getValue();
    OrderType getType();

    private:
    int _id;
    std::string _ticker;
    double _value;
    OrderType _type;
};