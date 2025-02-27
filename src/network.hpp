#pragma once
class Network {
public:
   virtual ~Network() = default;

   virtual bool createSocket(const char* address, const int port) = 0;
   virtual bool recv(char* buffer, int size, int& bytesRecv) = 0;
protected:
   Network() = default;
};
