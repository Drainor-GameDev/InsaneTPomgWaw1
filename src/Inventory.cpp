//
// Created by Guill on 13/10/2026.
//

#include "Inventory.h"

#include <algorithm>
#include <iostream>

Inventory::Inventory(float maxWeight)
{
    this->maxWeight = maxWeight;
}

bool Inventory::AddItem(const Item& item)
{
    if (maxWeight < GetTotalWeight() + item.GetWeight())
    {
        std::cout << "Pas assez de place pour : " + item.GetName() + "\n" << std::endl;
        Print();
        std::cout << "Achete toi un meilleur sac sale pauvre" << std::endl;
        return false;
    }
    items.push_back(item);
    return true;
}

void Inventory::RemoveItem(const Item& item)
{
    items.erase(std::remove(items.begin(), items.end(), item));
}

bool Inventory::RemoveItem(const std::string& name)
{
    for (Item& item : items)
    {
        if (item.GetName() == name)
        {
            RemoveItem(item);
            return true;
        }
    }
    return false;
}

float Inventory::GetTotalWeight() const
{
    int totalWeight = 0;
    for (const Item& item : items)
    {
        totalWeight += item.GetWeight();
    }

    return totalWeight;
}

const Item* Inventory::GetMostValuable() const
{
    if (items.empty()) return nullptr;

    auto mostValuable = &items[0];
    int maxValue = mostValuable->GetPrice();

    for (const Item& item : items)
    {
        if (item.GetPrice() > maxValue)
        {
            mostValuable = &item;
            maxValue = item.GetPrice();
        }
    }

    return mostValuable;
}

const Item* Inventory::FindByName(const std::string& name) const
{
    for (const Item& item : items)
    {
        if (item.GetName() == name) return &item;
    }
    return nullptr;
}

void Inventory::Print() const
{
    std::cout << "Weight : " + std::to_string(GetTotalWeight())  + " / " + std::to_string(maxWeight) + "\n";

    for (const Item& item : items)
    {
        std::cout << " - " + item.GetName() << std::endl;
    }
}
