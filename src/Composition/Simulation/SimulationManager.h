//
// Created by Guill on 14/10/2026.
//

#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H
#include <vector>

#include "../Monsters/Monster.h"


class SimulationManager {
public:
    void RunSimulation();
private:
    std::vector<Monster> monsters;
    void Setup();
};



#endif //SIMULATIONMANAGER_H
