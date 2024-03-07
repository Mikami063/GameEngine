//
//  Collision.cpp
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-06.
//

#include "Collision.h"

bool Collision::AABB(const SDL_Rect &rectA, const SDL_Rect &rectB){
    if(rectA.x+rectA.w>=rectB.x &&
       rectB.x+rectB.w>=rectA.x &&
       rectA.y+rectA.h>=rectB.y &&
       rectB.y+rectB.h>=rectA.y){
        return true;
    }
    return false;
}
