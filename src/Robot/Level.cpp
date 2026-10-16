#include "Level.h"
#include <iostream>
#include <utility>
Level::Level(std::vector<std::string> rows) : grid(std::move(rows))
{
    for (int y = 0; y < static_cast<int>(grid.size()); ++y)
    {
        for (int x = 0; x < static_cast<int>(grid[y].size()); ++x)
        {
            char& c = grid[y][x];
            if (c == '@' || c == '+')
            {
                robotX = x;
                robotY = y;
                c = (c == '+') ? '.' : ' ';
            }
        }
    }
}
bool Level::IsWall(int x, int y) const { return grid[y][x] == '#'; }
bool Level::HasBox(int x, int y) const { return grid[y][x] == '$' ||grid[y][x] == '*'; }
void Level::SetBox(int x, int y, bool box)
{
    const bool goal = (grid[y][x] == '.' || grid[y][x] == '*');
    grid[y][x] = box ? (goal ? '*' : '$') : (goal ? '.' : ' ');
}
bool Level::TryMoveRobot(int dx, int dy, bool& pushedBox)
{
    pushedBox = false;
    const int nx = robotX + dx;
    const int ny = robotY + dy;
    if (IsWall(nx, ny))
        return false;
    if (HasBox(nx, ny))
    {
        const int bx = nx + dx;
        const int by = ny + dy;
        if (IsWall(bx, by) || HasBox(bx, by))
            return false;
        SetBox(nx, ny, false);
        SetBox(bx, by, true);
        pushedBox = true;
    }
    robotX = nx;
    robotY = ny;
    return true;
}
void Level::UndoMove(int dx, int dy, bool pushedBox)
{
    if (pushedBox)
    {
        SetBox(robotX + dx, robotY + dy, false);
        SetBox(robotX, robotY, true);
    }
    robotX -= dx;
    robotY -= dy;
}
bool Level::IsSolved() const
{
    for (const std::string& row : grid)
        for (char c : row)
            if (c == '$')
                return false;
    return true;
}
void Level::Print() const
{
    for (int y = 0; y < static_cast<int>(grid.size()); ++y)
    {
        std::string row = grid[y];
        if (y == robotY)
            row[robotX] = (row[robotX] == '.') ? '+' : '@';
        std::cout << row << '\n';
    }
}
