#pragma once
class Network {
public:
   virtual ~Network() = default;

   virtual bool createSocket(const char* address, const char* port) = 0;
   virtual bool receive(char* buffer, int size, int& bytesRecv) = 0;
protected:
   Network() = default;
};
