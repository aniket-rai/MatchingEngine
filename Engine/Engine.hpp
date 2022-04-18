#pragma once
#include <memory>
#include <queue>

#include "../Order/Order.hpp"

using order_ptr = std::unique_ptr<Order>;
using engine_queue_asks = std::priority_queue<order_ptr, std::vector<order_ptr>, std::greater<order_ptr> >;
using engine_queue_bids = std::priority_queue<order_ptr, std::vector<order_ptr>, std::less<order_ptr> >;

class Engine {
    public:
    Engine(std::string ticker) : _ticker(ticker) {};

    template <typename T>
    void addOrder(T&& order);
    void deleteOrder(T&& orderId);

    void getBid();
    void getAsk();
    void getPair();


    private:
    std::string _ticker;
    engine_queue_bids _bids;
    engine_queue_asks _asks;
};