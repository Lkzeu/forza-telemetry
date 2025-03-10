#include <iostream>
#include <string>
#include <system_error>
#include <exception>
#include "win_socket.hpp"

wSocket::wSocket() {
   initWSA();
}

wSocket::~wSocket() {
   if (socket_ != INVALID_SOCKET)
      closesocket(socket_);

   if (hasinitWSA_) {
      WSACleanup();
   }
}

bool wSocket::createSocket(const char* address, const char* port) {
   addrinfo* serverInfo = nullptr;
   addrinfo  hints;

   std::memset(&hints, 0, sizeof(hints));
   hints.ai_family   = AF_INET;
   hints.ai_socktype = SOCK_DGRAM;
   hints.ai_protocol = IPPROTO_UDP;
   hints.ai_flags    = AI_PASSIVE;

   int status = getaddrinfo(nullptr, port, &hints, &serverInfo);
   
   if (status != 0) {
      throw std::system_error(WSAGetLastError(), std::system_category(), "getaddrinfo failed");
   }

   socket_ = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);

   if (socket_ == INVALID_SOCKET) {
      freeaddrinfo(serverInfo);
      throw std::system_error(WSAGetLastError(), std::system_category(), "socket creation failed");
   }

   status = bind(socket_, serverInfo->ai_addr, serverInfo->ai_addrlen);
   if (status != 0) {
      throw std::system_error(WSAGetLastError(), std::system_category(), "bind failed");
   }

   freeaddrinfo(serverInfo);
   return true;
}

bool wSocket::receive(char* buffer, int size, int& bytesRecv) {
   bytesRecv = recv(socket_, buffer, size - 1, 0); // don't care who sent the packet
   if (bytesRecv == SOCKET_ERROR) {
      throw std::system_error(WSAGetLastError(), std::system_category(), "recv failed");
   }
   return true;
}

void wSocket::initWSA() {
   auto wVersionRequired = MAKEWORD(2, 2);
   int result = WSAStartup(wVersionRequired, &wsaData_);

   if (result != 0) {
      throw std::system_error(result, std::system_category(), "WSAStartup failed");
   }

   if (LOBYTE(wsaData_.wVersion) != 2 || HIBYTE(wsaData_.wVersion) != 2) {
      // Clean up if WSAStartup failed, because if the object is not constructed, 
      // the destructor will not be called to cleanup.
      WSACleanup();
      throw std::runtime_error("Wrong version of winsock.dll, must be 2.2");
   }

   hasinitWSA_ = true;
}