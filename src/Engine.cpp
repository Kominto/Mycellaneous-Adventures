#include "Engine.h"

const char* title = "Hewwo";
const int x=0,y=0,h=500,w=500;
const Uint32 flag = SDL_WINDOW_RESIZABLE;
const char* file = "data/master.png";

//WINDOW

Window::Window()
{
    SDL_Init(SDL_INIT_VIDEO);
    win = SDL_CreateWindow("Hewwo",0,0,500,500,SDL_WINDOW_RESIZABLE);
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    tex = IMG_LoadTexture(ren,file);
}

Window::~Window()
{
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Window::windowLoop()
{
    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
            break;
        }
    }
}

void Window::windowRender()
{
}

//OBJECT

Object::Object()
{
}

Object::~Object()
{
}

void Object::setDre(int x, int y, int h, int w)
{
    dre.x=x;
    dre.y=y;
    dre.h=h;
    dre.w=w;
}

void Object::setSre(int x, int y, int h, int w)
{
    sre.x=x;
    sre.y=y;
    sre.h=h;
    sre.w=w;
}

SDL_Rect Object::getDre()
{
    return this->dre;
}

SDL_Rect Object::getSre()
{
      return this->sre;
}
