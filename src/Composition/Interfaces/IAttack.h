//
// Created by Guill on 14/10/2026.
//

#ifndef IATTACK_H
#define IATTACK_H
#include <string>

class IAttack
{
public:
    virtual ~IAttack() = default;
    virtual void Attack(const std::string& who, const std::string& target) const = 0;
};

#endif //IATTACK_H
