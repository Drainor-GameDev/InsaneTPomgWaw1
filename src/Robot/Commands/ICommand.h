//
// Created by Guill on 16/10/2026.
//

#pragma once
#include "../Level.h"


class ICommand {
public:
    virtual ~ICommand() {}
    virtual bool Execute(Level& level) = 0;
    virtual void Undo(Level& level) = 0;
    virtual bool IsUndoable() const { return true; }
};
