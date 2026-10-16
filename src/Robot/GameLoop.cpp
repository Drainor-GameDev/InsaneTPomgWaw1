//
// Created by Guill on 16/10/2026.
//

#include "GameLoop.h"

#include <iostream>

#include <iostream>
#include <string>
#include <vector>
#include "Level.h"
#ifdef  _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

#include "Level.h"
#include "Commands/CommandHistory.h"
#include "Commands/InputHandler.h"
#include "Commands/MoveCommand.h"
#include "Commands/ReBindCommand.h"
#include "Commands/RedoCommand.h"
#include "Commands/UndoCommand.h"

void GameLoop::Init()
{
    inputHandler = InputHandler();
    commandHistory = CommandHistory();
    Bind();
}

void GameLoop::Bind()
{
    inputHandler.Bind('m', Commands::Rebind(inputHandler, azerty));
    inputHandler.Bind('u', Commands::Undo(commandHistory));
    inputHandler.Bind('r', Commands::Redo(commandHistory));
    inputHandler.Bind('z', Commands::Move(0,-1));
    inputHandler.Bind('q', Commands::Move(-1,0));
    inputHandler.Bind('s', Commands::Move(0,1));
    inputHandler.Bind('d', Commands::Move(1,0));
}

void GameLoop::Run()
{
    Init();
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    Level level(kLevel);

    while (true)
    {
        level.Print();
        if (level.IsSolved())
        {
            std::cout << "Bravo, niveau terminé !\n";
            Level freshLevel(kLevel);
            commandHistory.Replay(freshLevel);
            break;
        }
        std::cout << "> ";
        std::string line;
        if (!std::getline(std::cin, line))
            break; // fin de l'entrée
        if (line.empty())
            continue;
        if (line[0] == 'x')
            break;
        auto cmd = inputHandler.GetCommand(line[0]);
        if (cmd == nullptr)
            std::cout << "Touche inconnue\n";
        else
            commandHistory.Execute(std::move(cmd), level);
    }
}
