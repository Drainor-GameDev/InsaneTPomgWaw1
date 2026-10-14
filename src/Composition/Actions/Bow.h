//
// Created by Guill on 14/10/2026.
//

#ifndef BOW_H
#define BOW_H
#include "../Interfaces/IAttack.h"


class Bow : public IAttack
{
public:
    void Attack(const std::string& who, const std::string& target) const override;
};



#endif //BOW_H
