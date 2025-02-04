#pragma once
#include "HeraGui/Core/Layer.h"
#include "HeraGui/Core/Window.h"
#include "HeraGui/Core/EventHandler.h"

namespace HeraGui {
class HERA_API ImGuiLayer : public Layer, EventHandler {
 public:
     explicit ImGuiLayer(Window* window);
     virtual ~ImGuiLayer();
     void OnAttach() override;
     void OnDetach() override;
     void OnEvent(Event* e) override;
     void Begin();
     void End();
     void BlockEvents(bool block) { block_events_ = block; }
     void SetDarkThemeColors();
 private:
     bool block_events_ = true;
     Window* window_;
};
}  // namespace HeraGui
