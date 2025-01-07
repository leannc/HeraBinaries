#pragma once
#include "Base.h"


namespace Hera {
    class HERA_API Application {
        public:
            virtual ~Application() {};
            virtual void Run() = 0;
    };

    Application* CreateApplication();
}