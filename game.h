#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Vector{
    int x, y;
};

//ENTITÉ DE BASE

class Entity{
    public:
    SDL_Rect sre, dre;
    Vector velocity;
    void setDre(int x, int y, int h, int w);
    void setSre(int x, int y, int h, int w);
    void drawEntity(SDL_Texture *tex, SDL_Renderer *ren);
};

//SOUS TYPES D'ENTITÉS

class Player:public Entity{

};

class Obstacle:public Entity{

};

class Hostile:public Entity{

};

class Projectile:public Entity{

};

//AFFICHAGE

class Display{
    public:
   Display();
   Display(const char *title,int x, int y, int h, int w, Uint32 flags);
   ~Display();
   void DisplayUpdate();
   void DisplayDrawScreen();
   void DisplayDrawEntity();
   void DisplayDrawPlayer();
    bool quit;
    SDL_Event event;
    SDL_Window * win;
    SDL_Renderer *ren;
    SDL_Texture *playerTex;
    SDL_Texture *defaultTex;
    Player you;
};
