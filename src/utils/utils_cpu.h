#pragma once
#include <functional>

template <typename T, typename... Args> class ExitScope {
public:
  explicit ExitScope(std::function<T(Args...)> func, Args... args) {
    func_ = std::bind(func, std::forward<Args>(args)...);
  }
  ~ExitScope() { func_(); }

private:
  std::function<T()> func_;
};
