//
// Created by Guill on 16/10/2026.
//

#include "InputHandler.h"

void InputHandler::Bind(char key, std::unique_ptr<ICommand> command)
{
    commands[key] = std::move(command);
}

void InputHandler::Unbind(char key)
{
    commands.erase(key);
}

ICommand* InputHandler::GetCommand(char key) const
{
    auto it = commands.find(key);
    if (it == commands.end())
        return nullptr;
    return it->second.get();
}
