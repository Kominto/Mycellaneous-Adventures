#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef ENGINE_H
#define ENGINE_H

struct Vector
    {
        int x, y;
    };

class Object
    {
        private:
        SDL_Rect sre, dre;

        public:
        Object();
        ~Object();
        void setDre(int x, int y, int h, int w);
        void setSre(int x, int y, int h, int w);
        SDL_Rect getDre();
        SDL_Rect getSre();
    };


class Window
    {
        public:
        Window();
        ~Window();
        void windowLoop();
        void windowRender();

        private:
        SDL_Event event;
        bool quit;
        SDL_Window * win;
        SDL_Renderer *ren;
        SDL_Texture *tex;
 };

#endif
