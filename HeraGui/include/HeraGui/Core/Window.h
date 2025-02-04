#pragma once
#include "EventHandler.h"

namespace HeraGui {
struct HERA_API WindowProps {
      std::string Title = "Hera";
      uint32_t Width;
      uint32_t Height;
      WindowProps(const std::string& title = "Hera Engine",
                  uint32_t width = 1600,
                  uint32_t height = 900)
                  :Title(title), Width(width), Height(height) {}
};

  // Interface representing a desktop system based Window
class HERA_API Window {
 public:
    virtual ~Window() {}
    virtual void OnUpdate() = 0;
    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;
    virtual void* GetNativeWindow() const = 0;
    virtual void* GetWindowContext() = 0;
    virtual void RegisterEventHandler(EventHandler* e_handler) = 0;
    static std::unique_ptr<Window> Create(const WindowProps& specification = WindowProps());
};
}  // namespace HeraGui

