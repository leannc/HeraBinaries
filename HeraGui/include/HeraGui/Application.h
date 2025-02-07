#pragma once
#include <Hera.h>
#include <HeraGui/Core/Window.h>
#include <HeraGui/imgui/ImGuiLayer.h>
#include <HeraGui/Core/LayerStack.h>

namespace HeraGui {
struct ApplicationCommandLineArgs {
  int count = 0;
  char** args = nullptr;

  const char* operator[] (int index) const {
    HERA_CORE_ASSERT(index <count, "Invalid");
    return args[index];
  }
};

struct ApplicationSpecification {
  std::string name = "Hera Gui Application";
  std::string working_directory;
  ApplicationCommandLineArgs command_line_args;
};

class HERA_API Application {
 public:
  explicit Application(const ApplicationSpecification& spec);
  virtual ~Application() {}
  void Run();
  void Close();
  void PushLayer(Layer* layer);
  void PushOverlay(Layer* layer);


 private:
  ApplicationSpecification specification_;
  LayerStack layer_stack_;
  std::unique_ptr<Window> window_;
  ImGuiLayer* imgui_layer_;
  bool running_;

 private:
  static Application* s_Instance;  // 这个s_Instance纯粹是一个guard，保证程序不会被多开，这个方法简单便捷。
};

Application* CreateApplication(ApplicationCommandLineArgs args);
}  // namespace HeraGui
