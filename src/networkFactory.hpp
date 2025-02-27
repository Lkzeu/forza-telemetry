#pragma once
#include "network.hpp"
#include <memory>

#ifdef _WIN32
#include "win_socket.hpp"
#else
#include "linux_socket.hpp"
#endif

class NetworkFactory {
public:
   static std::unique_ptr<Network> createNetwork() {
      #ifdef _WIN32
         return std::make_unique<wSocket>();
      #else
         return std::make_unique<lSocket>();
      #endif
   }
};
