//
// Created by Guill on 16/10/2026.
//

#pragma once
#include "../Level.h"


class ICommand {
public:
    virtual ~ICommand() {}
    virtual void Execute(Level& level) = 0;
};
