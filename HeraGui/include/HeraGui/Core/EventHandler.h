
#pragma once

/// sdl2 specific code------
#include <SDL2/SDL.h>
typedef SDL_Event Event;


namespace HeraGui {
class EventHandler {
 public:
    virtual ~EventHandler() {}
    virtual void OnEvent(Event* e) = 0;
};
}
