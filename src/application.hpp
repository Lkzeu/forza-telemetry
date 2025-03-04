#pragma once
#include <memory>
#include "network.hpp"
#include "telemetryDataout.hpp"

class application {
public:
   application();
   ~application() = default;
   void run();

private:
   udpPacket packet_{};
   carTelemetry* car_;
   std::unique_ptr<Network> net_;

};