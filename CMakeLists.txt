cmake_minimum_required(VERSION 3.31)
project(.)

set(CMAKE_CXX_STANDARD 20)

add_executable(InsaneTPomgWaw1 main.cpp
        src/Inventory/Item.cpp
        src/Inventory/Item.h
        src/Inventory/Inventory.cpp
        src/Inventory/Inventory.h
        src/Composition/Interfaces/IMovement.h
        src/Composition/Interfaces/IAttack.h
        src/Composition/Actions/Walk.cpp
        src/Composition/Actions/Walk.h
        src/Composition/Actions/Fly.cpp
        src/Composition/Actions/Fly.h
        src/Composition/Actions/Teleport.cpp
        src/Composition/Actions/Teleport.h
        src/Composition/Actions/Melee.cpp
        src/Composition/Actions/Melee.h
        src/Composition/Actions/Bow.cpp
        src/Composition/Actions/Bow.h
        src/Composition/Actions/Spell.cpp
        src/Composition/Actions/Spell.h
        src/Composition/Monsters/Monster.h
        src/Composition/Simulation/SimulationManager.cpp
        src/Composition/Simulation/SimulationManager.h
        src/Composition/Monsters/Monster.cpp
        src/Robot/Level.cpp
        src/Robot/Level.h
        src/Robot/GameLoop.cpp
        src/Robot/GameLoop.h
        src/Robot/Commands/ICommand.h
        src/Robot/Commands/MoveCommand.cpp
        src/Robot/Commands/MoveCommand.h
        src/Robot/Commands/InputHandler.cpp
        src/Robot/Commands/InputHandler.h
        src/Robot/Commands/ReBindCommand.cpp
        src/Robot/Commands/ReBindCommand.h
        src/Robot/Commands/CommandHistory.cpp
        src/Robot/Commands/CommandHistory.h
        src/Robot/Commands/UndoCommand.cpp
        src/Robot/Commands/UndoCommand.h
        src/Robot/Commands/RedoCommand.cpp
        src/Robot/Commands/RedoCommand.h
)
