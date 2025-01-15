#pragma once
#include "HeraGui/Core/Layer.h"
#include "HeraGui/Core/Window.h"
#include "HeraGui/Core/EventHandler.h"

namespace HeraGui {
    class HERA_API ImGuiLayer : public Layer,EventHandler {
    public:
        ImGuiLayer(Window* window);
        virtual ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnEvent(Event* e) override;

        void Begin();
        void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }

        void SetDarkThemeColors();

    private:
        bool m_BlockEvents = true;
        Window* m_Window;
    };

}