#include "Client.h"

namespace bakery::client 
{

    Client::Client(const std::string& name, double discount): name(name), discount(discount) {}

    std::string Client::toString() const 
    {
        return "Клиент: " + name + ", Скидка: " + std::to_string(discount) + "%";
    }
}