//
//  TileComponent.h
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-07.
//

#pragma once
#include "ECS.h"
#include "TransformComponent.h"
#include "SDL2/SDL.h"

class TileComponent: public Component{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;
    
    SDL_Rect tileRect;
    int tileID;
    char* path;
    
    TileComponent()=default;
    TileComponent(int x, int y, int w, int h, int id){
        tileRect.x=x;
        tileRect.y=y;
        tileRect.w=w;
        tileRect.h=h;
        tileID=id;
        
        switch (tileID) {
            case 0:
                path= "assets/water.png";
                break;
            case 1:
                path= "assets/dirt.png";
                break;
            case 2:
                path= "assets/grass.png";
                break;
                
            default:
                break;
        }
    }
    void init() override{
        entity->addComponent<TransformComponent>(tileRect.x,tileRect.y,tileRect.w,tileRect.h,1);
        transform=&entity->getComponent<TransformComponent>();//save the quick ref
        
        entity->addComponent<SpriteComponent>(path);
        sprite=&entity->getComponent<SpriteComponent>();//save the quick ref
    }
    
};
