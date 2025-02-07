#pragma once

namespace HeraGui {
class HERA_API Layer {
 public:
  explicit Layer(const std::string& name = "Layer"):m_DebugName(name) {}
  virtual ~Layer() {}
  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUpdate() {}
  virtual void OnImGuiRender() {}
  // virtual void OnEvent(Event& event) {}
  inline const std::string& GetName() const { return m_DebugName; }
 protected:
  std::string m_DebugName;
};
}  // namespace HeraGui
