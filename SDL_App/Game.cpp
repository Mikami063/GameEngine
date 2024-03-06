//
//  Game.cpp
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-05.
//

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"


/*
SDL_Texture* playerTex;
SDL_Rect srcR, destR;
 */
GameObject* player;

Game::Game(){
    
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags=0;
    if(fullscreen){
        flags=SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"subsystem initialized"<<std::endl;
        
        window=SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            std::cout<<"window created"<<std::endl;
        }
        
        renderer=SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"renderer created"<<std::endl;
        }
        isRunning=true;
    }else{
        isRunning=false;
    }
    
    /*
    SDL_Surface* tmpSurface =IMG_Load("assets/woman-idle/woman-idle-1.png");
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    */
    /*
    playerTex=TextureManager::LoadTexture("assets/woman-idle/woman-idle-1.png", renderer);
    */
    player=new GameObject("assets/woman-idle/woman-idle-1.png", renderer, 0, 0);
}
void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning=false;
            break;
            
        default:
            break;
    }
}
void Game::update(){
    /*
    cnt++;
    destR.h=64;
    destR.w=64;
    destR.x=cnt;
    std::cout<<cnt<<std::endl;
    */
    player->Update();
}
void Game::render(){
    SDL_RenderClear(renderer);
    /*
    SDL_RenderCopy(renderer, playerTex, nullptr, &destR);
    */
    player->Render();
    SDL_RenderPresent(renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game cleared"<<std::endl;
}