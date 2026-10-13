//
// Created by Guill on 13/10/2026.
//

#include "Item.h"

#include <iostream>
#include <ostream>

Item::Item(const std::string& name, const float weight, const int price)
{
    SetName(name);
    SetWeight(weight);
    SetPrice(price);
}

const std::string& Item::GetName() const
{
    return name;
}

const float& Item::GetWeight() const
{
    return weight;
}

const int& Item::GetPrice() const
{
    return price;
}

void Item::SetName(const std::string& name)
{
    this->name = name;
}

void Item::SetWeight(const float weight)
{
    this->weight = weight;
}

void Item::SetPrice(const int price)
{
    this->price = price;
}

bool Item::operator==(const Item& other) const
{
    name == other.name;
}
