//
//  PositionComponent.h
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-06.
//

#pragma once
#include "Components.h"

class PositionComponent: public Component{
private:
    int xpos;
    int ypos;
    
public:
    PositionComponent(){
        xpos=0;
        ypos=0;
    }
    PositionComponent(int x, int y){
        xpos=x;
        ypos=y;
    }
    int x(){
        return xpos;
    }
    int y(){
        return ypos;
    }
    
    
    void update() override{
        xpos++;
        ypos++;
    }
    void setPos(int x,int y){
        xpos=x;
        ypos=y;
    }
};
