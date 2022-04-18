#include <memory>
#include <set>

#include "../Order/Order.hpp"

using order_ptr = std::unique_ptr<Order>;
using engine_queue_asks = std::set<order_ptr, std::greater<order_ptr> >;
using engine_queue_bids = std::set<order_ptr, std::less<order_ptr> >;

class Engine {
    public:
    Engine(std::string ticker) : _ticker(ticker) {};

    template <typename T>
    void addOrder(T&& order);

    template <typename T>
    void deleteOrder(T&& orderId);

    void getBid();
    void getAsk();
    void getPair();


    private:
    std::string _ticker;
    engine_queue_bids _bids;
    engine_queue_asks _asks;
};