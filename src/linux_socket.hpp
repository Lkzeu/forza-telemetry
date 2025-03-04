#pragma once
#include "network.hpp"

class lSocket : public Network {
public:
   lSocket();
   ~lSocket() override;
   bool createSocket(
      const char* address, const char* port) override;
   bool receive(char* buffer, int size, int& bytesRecv) override;

private:
   bool init();
};
