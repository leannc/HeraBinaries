#pragma once

#include <Core/Window.h>
#include <SDL2/SDL.h>

namespace HeraGui {

class SDLWindow : public Window {
public:
    SDLWindow(const WindowProps& props);
    ~SDLWindow();

    void OnUpdate() override;
    uint32_t GetWidth() const override { return m_Data.Width; }
    uint32_t GetHeight() const override { return m_Data.Height; }

private:
    SDL_Window* m_Window;
    SDL_GLContext m_Context;
    void* m_ImGuiContext;
    
    struct WindowData {
        std::string Title;
        uint32_t Width, Height;
        bool Running = true;
    };
    
    WindowData m_Data;
};

}
