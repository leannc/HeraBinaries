#pragma once
#include <HeraGui.h>

extern HeraGui::Application* HeraGui::CreateApplication(HeraGui::ApplicationCommandLineArgs args);



int main(int argc, char** argv) {
  Hera::Init();

  HeraGui::ApplicationCommandLineArgs args;
  auto app = HeraGui::CreateApplication(args);
  app->Run();
  delete app;

  return 0;
}
