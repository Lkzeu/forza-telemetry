#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>
#include "network.hpp"

class wSocket : public Network {
public:
   wSocket();
   ~wSocket() override;
   bool createSocket(
      const char* address, const int port) override;
   bool recv(char* buffer, int size, int& bytesRecv) override;

private:
   bool init();

};
