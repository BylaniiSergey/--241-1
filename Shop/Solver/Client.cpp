#include "Client.h"

namespace bakery::client
{

    Client::Client(const std::string& name, double discount) : name(name), discount(discount) {}

    std::string Client::toString() const
    {
        std::stringstream buffer;
        buffer << "Client: " << this->name << "; Skid: " << this->discount << " %: ";
        return buffer.str();
    }

    bool Client::operator==(const Client& other_client) const
    {
        return this->name == other_client.name;
    }

    std::ostream& bakery::client::operator<<(std::ostream& os, const Client& product)
    {
        return os << product.toString();
    }

    double Client::GetDiscount() const
    {
        return discount;
    }

    std::string bakery::client::Client::GetName() const
    {
        return name;
    }
}