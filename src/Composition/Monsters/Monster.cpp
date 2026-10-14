//
// Created by Guill on 14/10/2026.
//

#include "Monster.h"

Monster::Monster(std::string name,
                 std::unique_ptr<IMovement> movement,
                 std::unique_ptr<IAttack> attack)
    : name(std::move(name)),
      movement(std::move(movement)),
      attack(std::move(attack))
{
}

void Monster::TakeTurn(const std::string& target) const
{
    movement->Move(name);
    attack->Attack(name, target);
}

void Monster::SetMovement(std::unique_ptr<IMovement> newMovement)
{
    movement = std::move(newMovement);
}
