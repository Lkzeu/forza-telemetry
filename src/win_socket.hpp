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
      const char* address, const char* port) override;
   bool receive(char* buffer, int size, int& bytesRecv) override;

private:
   WSAData wsaData_;
   bool hasinitWSA_ = false;
   SOCKET socket_   = INVALID_SOCKET;

   void initWSA();

};
