//
// Created by Guill on 14/10/2026.
//

#ifndef TELEPORT_H
#define TELEPORT_H
#include "../Interfaces/IMovement.h"


class Teleport : public IMovement
{
public:
    void Move(const std::string& who) const override;
};



#endif //TELEPORT_H
