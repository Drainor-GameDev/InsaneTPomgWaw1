//
// Created by Guill on 14/10/2026.
//

#ifndef IMOVEMENT_H
#define IMOVEMENT_H
#include <string>


class IMovement {
public:
    virtual ~IMovement() = default;
    virtual void Move(const std::string& who) const = 0;
};


#endif //IMOVEMENT_H
