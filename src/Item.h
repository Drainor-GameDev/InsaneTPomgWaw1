//
// Created by Guill on 13/10/2026.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>


class Item {
public:
    Item(const std::string& name, float weight, int price);

    const std::string& GetName() const;

    const float& GetWeight() const;
    const int& GetPrice() const;

    void SetName(const std::string& name);
    void SetWeight(float weight);
    void SetPrice(int price);
    bool operator==(const Item& other) const;

private:
    std::string name;

    ///Expressed in kg
    float weight;

    /// Expressed in gold (PO cause we're big frensh here)
    int price;
};



#endif
