#include <SFML/Window.hpp>
#include <iostream>
#include "engine.h"

int main()
{
    Engine engine;
    engine.SetMaxFps(60);
    engine.Start("MineWithoutCraft", 800, 600, false);
}
