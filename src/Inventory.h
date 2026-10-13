//
// Created by Guill on 13/10/2026.
//

#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>

#include "Item.h"


class Inventory {
public:
    explicit Inventory(float maxWeight);

    bool AddItem(const Item& item);
    void RemoveItem(Item item);
    bool RemoveItem(const std::string& name);

    float GetTotalWeight() const;
    const Item* GetMostValuable() const;
    Item* FindByName(const std::string& name);
    void Print() const;

private:
    float maxWeight;
    std::vector<Item> items;
};



#endif //INVENTORY_H
