#pragma once

#include <HeraGui/Core/Window.h>
#include <SDL2/SDL.h>

namespace HeraGui {

class HERA_API SDLWindow : public Window {
 public:
    explicit SDLWindow(const WindowProps& props);
    ~SDLWindow();

    void OnUpdate() override;
    void* GetNativeWindow() const override { return window_; }
    uint32_t GetWidth() const override { return data_.Width; }
    uint32_t GetHeight() const override { return data_.Height; }
    void* GetWindowContext() override { return &context_; }
    void RegisterEventHandler(EventHandler* e_handler) override { event_handlers_.push_back(e_handler); }

 private:
    SDL_Window* window_;
    SDL_GLContext context_;

    struct WindowData {
        std::string Title = "SDL Window";
        uint32_t Width = 800, Height = 600;
        bool Running = true;
    };

    WindowData data_;
    std::vector<EventHandler*> event_handlers_;
};

}  // namespace HeraGui
