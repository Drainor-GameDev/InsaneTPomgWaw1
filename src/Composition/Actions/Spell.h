//
// Created by Guill on 14/10/2026.
//

#ifndef SPELL_H
#define SPELL_H
#include "../Interfaces/IAttack.h"


class Spell : public IAttack
{
public:
    void Attack(const std::string& who, const std::string& target) const override;
};



#endif //SPELL_H
