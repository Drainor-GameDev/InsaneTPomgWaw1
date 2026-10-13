#include <iostream>

#include "src/Inventory.h"

int main()
{
    auto inventory = Inventory(20);
    inventory.AddItem(Item("Epee courte", 3.5f, 40));
    inventory.AddItem(Item("Potion de soin", 0.5f, 25));
    inventory.AddItem(Item("Bouclier", 6, 55));
    inventory.AddItem(Item("Enclume", 15, 10));


}