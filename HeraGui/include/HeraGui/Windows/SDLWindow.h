#pragma once

#include <HeraGui/Core/Window.h>
#include <SDL2/SDL.h>

namespace HeraGui {

class HERA_API SDLWindow : public Window {
public:
    SDLWindow(const WindowProps& props);
    ~SDLWindow();

    void OnUpdate() override;
    void* GetNativeWindow() const override { return m_Window; }
    uint32_t GetWidth() const override { return m_Data.Width; }
    uint32_t GetHeight() const override { return m_Data.Height; }
    void* GetWindowContext() override { return &m_Context; }
    void RegisterEventHandler(EventHandler* e_handler) override { m_EventHandlers.push_back(e_handler); }

private:
    SDL_Window* m_Window;
    SDL_GLContext m_Context;
    
    struct WindowData {
        std::string Title = "SDL Window";
        uint32_t Width =800, Height=600;
        bool Running = true;
    };
    
    WindowData m_Data;
    std::vector<EventHandler*> m_EventHandlers;
};

}
