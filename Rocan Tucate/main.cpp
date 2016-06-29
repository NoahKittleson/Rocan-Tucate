
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//


//#include "ResourcePath.hpp"
#include <RocanTucatePrefix.pch>
#include "game.h"


int main(int, char const**)
{
    Game::Start();
        
    return 0;
}