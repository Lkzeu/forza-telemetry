#pragma once
#include "network.hpp"

class lSocket : public Network {
public:
   lSocket();
   ~lSocket() override;
   bool createSocket(
      const char* address, const int port) override;
   bool recv(char* buffer, int size, int& bytesRecv) override;

private:
   bool init();
};
