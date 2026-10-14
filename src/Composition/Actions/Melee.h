//
// Created by Guill on 14/10/2026.
//

#ifndef MELEE_H
#define MELEE_H
#include "../Interfaces/IAttack.h"


class Melee : public IAttack
{
public:
    void Attack(const std::string& who, const std::string& target) const override;
};



#endif //MELEE_H
