#include "game.h"

//ENTITÉS

void Entity::setDre(int x, int y, int w, int h){
    sre = {x, y, w, h};
}

void Entity::setSre(int x, int y, int w, int h){
    dre = {x, y, w, h};
}

//AFFICHAGE

Display::Display(){
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG);
        win = SDL_CreateWindow("Default Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, 0);
        ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}

Display::Display(const char *title,int x, int y, int h, int w, Uint32 flags){
        SDL_Init(SDL_INIT_VIDEO);
        win = SDL_CreateWindow(title,x,y,h,w,flags);
        ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
        playerTex = IMG_LoadTexture(ren,"data/mushroom.png");
       defaultTex = IMG_LoadTexture(ren,"data/debut.png");
        you.setDre(0,0,30,32);
        you.setSre(0,0,15,16);
}


Display::~Display(){
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            SDL_Quit();
}


void Display::DisplayUpdate(){
    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
            case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_LEFT:  you.velocity.x-=1; break;
                case SDLK_RIGHT: you.velocity.x+=1; break;
                case SDLK_UP:    you.velocity.y-=1; break;
                case SDLK_DOWN:  you.velocity.y+=1; break;
            }
        break;
        }
        this->DisplayDrawScreen();
    }
}

void Display::DisplayDrawScreen(){
    SDL_RenderClear(ren);
    this->DisplayDrawEntity();
    SDL_RenderPresent(ren);
}

void Display::DisplayDrawEntity(){
    this->DisplayDrawPlayer();
}

void Display::DisplayDrawPlayer(){
    you.setDre(you.dre.x+you.velocity.x, you.dre.y+you.velocity.y,30,32);
    SDL_RenderCopy(ren, this->playerTex,&you.dre,& you.sre);
}

