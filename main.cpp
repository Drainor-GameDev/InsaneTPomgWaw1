#include <iostream>

#include "src/Inventory.h"
#include "src/Composition/Simulation/SimulationManager.h"

void EnchantCopy(Item item, int bonus)
{
    item.SetPrice(item.GetPrice() + bonus);
}

void Enchant(Item* item, int bonus)
{
    item->SetPrice(item->GetPrice() + bonus);
}

/// TP1 Simulation
void Tp1()
{
    std::cout << "TP 1 \n" << std::endl;

    auto inventory = Inventory(20);
    inventory.AddItem(Item("Epee courte", 3.5f, 40));
    inventory.AddItem(Item("Potion de soin", 0.5f, 25));
    inventory.AddItem(Item("Bouclier", 6, 55));
    inventory.AddItem(Item("Enclume", 15, 10));

    auto sword = inventory.FindByName("Epee courte");
    EnchantCopy(*sword, 100);
    std::cout << "Valeur de l'epee apres EnchantCopy : " << sword->GetPrice() << std::endl;
    Enchant(sword, 100);
    std::cout << "Valeur de l'epee apres Enchant : " << sword->GetPrice() << std::endl;

    auto bow = inventory.FindByName("Arc court"); //Je suis original =}
    if (bow == nullptr)
        std::cout << "Pas d'Arc court dans le sac" << std::endl;
    else
        std::cout << bow->GetPrice() << std::endl;

    auto popo = *inventory.FindByName("Potion de soin"); //copy to keep it
    inventory.RemoveItem(popo);
    popo.Print();

    std::cout << "Most valuable : " << inventory.GetMostValuable()->ToString() << std::endl;
    inventory.Print();

    std::cout << "\nTP 1 end \n" << std::endl;
}

/// TP2 Simulation
void Tp2()
{
    std::cout << "TP 2 \n" << std::endl;

    auto simulation = SimulationManager();
    simulation.RunSimulation();
}

int main()
{
    Tp1();

    Tp2();
}