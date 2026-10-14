//
// Created by Guill on 14/10/2026.
//

#ifndef FLY_H
#define FLY_H
#include "../Interfaces/IMovement.h"


class Fly : public IMovement
{
public:
    void Move(const std::string& who) const override;
};



#endif //FLY_H
