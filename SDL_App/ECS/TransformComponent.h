//
//  PositionComponent.h
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-06.
//

#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent: public Component{
public:
    Vector2D position;
    TransformComponent(){
        position.x=0.0f;
        position.y=0.0f;
    }
    TransformComponent(float x, float y){
        position.x=x;
        position.y=y;
    }
    
    void update() override{
        
    }

};
