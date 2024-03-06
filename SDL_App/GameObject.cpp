//
//  GameObject.cpp
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-05.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y){
    this->renderer=renderer;
    objTexture=TextureManager::LoadTexture(textureSheet, renderer);
    
    xpos=x;
    ypos=y;
}

void GameObject::Update(){

    xpos++;
    ypos++;
    
    destRect.x=xpos;
    destRect.y=ypos;
    destRect.h=64;
    destRect.w=64;
}

void GameObject::Render(){
    SDL_RenderCopy(renderer, objTexture, nullptr, &destRect);
}