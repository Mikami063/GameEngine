//
//  SpriteComponent.h
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-06.
//

#pragma once
#include "Components.h"
#include "SDL2/SDL.h"

class SpriteComponent: public Component{
private:
    PositionComponent* position;
    SDL_Texture* texture;
    SDL_Rect srcRect,destRect;
    //bool active=true;
    
public:
    SpriteComponent()=default;
    SpriteComponent(const char* path){
        texture=TextureManager::LoadTexture(path);
    }
    void init() override{
        position=&entity->getComponent<PositionComponent>();
        
        srcRect.x=srcRect.y=0;
        srcRect.w=srcRect.h=32;
        destRect.w=destRect.h=64;
    }
    void update() override{
        destRect.x=position->x();
        destRect.y=position->y();
    }
    void draw() override{
        TextureManager::Draw(texture, nullptr, &destRect);
    }
};
