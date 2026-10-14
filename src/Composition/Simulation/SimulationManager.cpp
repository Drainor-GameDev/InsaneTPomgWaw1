//
// Created by Guill on 14/10/2026.
//

#include "SimulationManager.h"

#include <iostream>

#include "../Actions/Bow.h"
#include "../Actions/Fly.h"
#include "../Actions/Melee.h"
#include "../Actions/Spell.h"
#include "../Actions/Teleport.h"
#include "../Actions/Walk.h"

void SimulationManager::RunSimulation()
{
    Setup();

    for (const Monster& monster : monsters)
    {
        monster.TakeTurn("Fergal Jenkins");
    }

    std::cout << "\nBat part : \n" << std::endl;

    Monster& bat = monsters[2];

    bat.TakeTurn("Fergal Jenkins");

    std::cout << "\nBat hit by Fergal Jenkins : \n" << std::endl;

    bat.SetMovement(std::make_unique<Walk>());

    bat.TakeTurn("Fergal Jenkins");
}

void SimulationManager::Setup()
{
    monsters.emplace_back("Gobelin",          std::make_unique<Walk>(),     std::make_unique<Melee>());
    monsters.emplace_back("Archer squelette", std::make_unique<Walk>(),     std::make_unique<Bow>());
    monsters.emplace_back("Chauve-souris",    std::make_unique<Fly>(),      std::make_unique<Melee>());
    monsters.emplace_back("Spectre",          std::make_unique<Fly>(),      std::make_unique<Spell>());
    monsters.emplace_back("Gargouille",       std::make_unique<Fly>(),      std::make_unique<Bow>());
    monsters.emplace_back("Necromancien",     std::make_unique<Walk>(),     std::make_unique<Spell>());
    monsters.emplace_back("Diablotin",        std::make_unique<Teleport>(), std::make_unique<Melee>());
}
