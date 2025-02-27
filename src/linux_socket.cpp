#include "linux_socket.hpp"
#include <iostream>

lSocket::lSocket() {
   std::cout << "lSocket obj created\n";
}
lSocket::~lSocket() {
   std::cout << "bye, bye, socket..\n";
}
bool lSocket::createSocket(const char* address, const int port) {
   std::cout << "linux socket created\n";
   return true;
}
bool lSocket::recv(char* buffer, int size, int& bytesRecv) {
   std::cout << "listening..\n";
   return true;
}
