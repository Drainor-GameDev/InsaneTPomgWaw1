#pragma once
#include <string>
#include <vector>
class Level
{
public:
    explicit Level(std::vector<std::string> rows);
    bool TryMoveRobot(int dx, int dy, bool& pushedBox);
    void UndoMove(int dx, int dy, bool pushedBox);
    bool IsSolved() const;
    void Print() const;
private:
    bool IsWall(int x, int y) const;
    bool HasBox(int x, int y) const;
    void SetBox(int x, int y, bool box);
    std::vector<std::string> grid;
    int robotX = 0;
    int robotY = 0;
};

