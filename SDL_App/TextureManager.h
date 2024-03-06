//
//  TextureManager.h
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-05.
//

#pragma once

#include "Game.h"

class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
};
