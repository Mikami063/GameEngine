//
//  Collision.h
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-06.
//

#pragma once

#include "SDL2/SDL.h"

class Collision{
public:
    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
};
