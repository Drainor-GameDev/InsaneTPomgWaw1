//
// Created by Guill on 14/10/2026.
//

#ifndef MONSTER_H
#define MONSTER_H
#include <memory>
#include <string>
#include "../Interfaces/IMovement.h"
#include "../Interfaces/IAttack.h"


class IMovement;
class IAttack;

class Monster {
public:
    Monster(std::string name, std::unique_ptr<IMovement> movement, std::unique_ptr<IAttack> attack);
    void TakeTurn(const std::string& target) const;
    void SetMovement(std::unique_ptr<IMovement> newMovement);
private:
    std::string name;
    std::unique_ptr<IMovement> movement;
    std::unique_ptr<IAttack> attack;
};



#endif //MONSTER_H
