//
// Created by Guill on 16/10/2026.
//

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <map>
#include <memory>

#include "ICommand.h"
#include <functional>

using CommandFactory = std::function<std::unique_ptr<ICommand>()>;


class InputHandler {
public:
    void Bind(char key, CommandFactory);
    void Unbind(char key);
    std::unique_ptr<ICommand> GetCommand(char key) const;
private:
    std::map<char, CommandFactory> commands;
};



#endif //INPUTHANDLER_H
