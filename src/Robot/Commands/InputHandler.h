//
// Created by Guill on 16/10/2026.
//

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <map>
#include <memory>

#include "ICommand.h"


class InputHandler {
public:
    void Bind(char key, std::unique_ptr<ICommand> command);
    void Unbind(char key);
    ICommand* GetCommand(char key) const;
private:
    std::map<char, std::unique_ptr<ICommand>> commands;
};



#endif //INPUTHANDLER_H
