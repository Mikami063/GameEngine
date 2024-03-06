//
//  Game.cpp
//  SDL_App
//
//  Created by Mikami Kirigaya on 2024-03-05.
//

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"//GO1
#include "Map.h"

#include "ECS.h"//M1
#include "Components.h"


/*
SDL_Texture* playerTex;
SDL_Rect srcR, destR;
 */
//GameObject* player;
GameObject* enemy;//GO2
Map* map;

SDL_Renderer* Game::renderer=nullptr;

Manager manager;//M2
auto& player(manager.addEntity());//M3


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
    //player=new GameObject("assets/woman-idle/woman-idle-1.png", 0, 0);
    enemy=new GameObject("assets/hat-man-idle/hat-man-idle-1.png", 50, 50);//GO3
    map=new Map();
    
    //newPlayer.addComponent<PositionComponent>();
    //newPlayer.getComponent<PositionComponent>().setPos(500,500);
    player.addComponent<PositionComponent>(0,0);//M4
    player.addComponent<SpriteComponent>("assets/woman-idle/woman-idle-1.png");//M5
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
    //player->Update();
    enemy->Update();//GO4
    manager.refresh();//M6
    manager.update();//M7
    std::cout<<player.getComponent<PositionComponent>().x()<<","<<player.getComponent<PositionComponent>().y()<<std::endl;
}
void Game::render(){
    SDL_RenderClear(renderer);
    /*
    SDL_RenderCopy(renderer, playerTex, nullptr, &destR);
    */
    map->DrawMap();
    //player->Render();
    enemy->Render();//GO5
    manager.draw();//M8
    SDL_RenderPresent(renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game cleared"<<std::endl;
}
