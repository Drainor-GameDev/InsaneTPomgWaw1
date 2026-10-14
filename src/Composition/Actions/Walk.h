//
// Created by Guill on 14/10/2026.
//

#ifndef WALK_H
#define WALK_H
#include "../Interfaces/IMovement.h"


class Walk : public IMovement
{
public:
    void Move(const std::string& who) const override;
};



#endif //WALK_H
