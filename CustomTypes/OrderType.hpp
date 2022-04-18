enum class OrderType {
    Ask, Bid, None
};

// OrderType overload
std::ostream& operator<<(std::ostream& os, const OrderType& type) {
    if (type == OrderType::Bid) {
        os << "Bid";
    } else {
        os << "Ask";
    }

    return os;
}