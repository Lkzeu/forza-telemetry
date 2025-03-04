#pragma once
#include <cstdint>
#include <cstring>

namespace constant {
   inline constexpr std::uint16_t fudp_dash_size = 332;
}

struct alignas(float) udpPacket {
   char payload[constant::fudp_dash_size];

   udpPacket() {
      std::memset(payload, 0, constant::fudp_dash_size);
   }
};

struct alignas(float) carTelemetry {
   std::int32_t                IsRaceOn;
   std::uint32_t               TimestampMS;
   float                       EngineMaxRpm;
   float                       EngineIdleRpm;
   float                       CurrentEngineRpm;
   float                       AccelerationX; // right
   float                       AccelerationY; // up
   float                       AccelerationZ; // foward
   float                       VelocityX;     // right
   float                       VelocityY;     // up
   float                       VelocityZ;     // foward
   float                       AngularVelocityX; // pitch
   float                       AngularVelocityY; // yaw
   float                       AngularVelocityZ; // roll
   float                       Yaw;
   float                       Pitch;
   float                       Roll;
   float                       NormalizedSuspensionTravelFrontLeft;
   float                       NormalizedSuspensionTravelFrontRight;
   float                       NormalizedSuspensionTravelRearLeft;
   float                       NormalizedSuspensionTravelRearRight;
   float                       TireSlipRatioFrontLeft;
   float                       TireSlipRatioFrontRight;
   float                       TireSlipRatioRearLeft;
   float                       TireSlipRatioRearRight;
   float                       WheelRotationSpeedFrontLeft;
   float                       WheelRotationSpeedFrontRight;
   float                       WheelRotationSpeedRearLeft;
   float                       WheelRotationSpeedRearRight;
   std::int32_t                WheelOnRumbleStripFrontLeft;
   std::int32_t                WheelOnRumbleStripFrontRight;
   std::int32_t                WheelOnRumbleStripRearLeft;
   std::int32_t                WheelOnRumbleStripRearRight;
   float                       WheelInPuddleDepthFrontLeft;
   float                       WheelInPuddleDepthFrontRight;
   float                       WheelInPuddleDepthRearLeft;
   float                       WheelInPuddleDepthRearRight;
   float                       SurfaceRumbleFrontLeft;
   float                       SurfaceRumbleFrontRight;
   float                       SurfaceRumbleRearLeft;
   float                       SurfaceRumbleRearRight;
   float                       TireSlipAngleFrontLeft;
   float                       TireSlipAngleFrontRight;
   float                       TireSlipAngleRearLeft;
   float                       TireSlipAngleRearRight;
   float                       TireCombinedSlipFrontLeft;
   float                       TireCombinedSlipFrontRight;
   float                       TireCombinedSlipRearLeft;
   float                       TireCombinedSlipRearRight;
   float                       SuspensionTravelMetersFrontLeft;
   float                       SuspensionTravelMetersFrontRight;
   float                       SuspensionTravelMetersRearLeft;
   float                       SuspensionTravelMetersRearRight;
   std::int32_t                CarOrdinal;
   std::int32_t                CarClass;
   std::int32_t                CarPerformanceIndex;
   std::int32_t                DrivetrainType;
   std::int32_t                NumCylinders;

   // dash *********************************************
   float                       PositionX;
   float                       PositionY;
   float                       PositionZ;
   float                       Speed;
   float                       Power;
   float                       Torque;
   float                       TireTempFrontLeft;
   float                       TireTempFrontRight;
   float                       TireTempRearLeft;
   float                       TireTempRearRight;
   float                       Boost;
   float                       Fuel;
   float                       DistanceTraveled;
   float                       BestLap;
   float                       LastLap;
   float                       CurrentLap;
   float                       CurrentRaceTime;
   std::uint16_t               LapNumber;
   std::uint8_t                RacePosition;
   std::uint8_t                Accel;
   std::uint8_t                Brake;
   std::uint8_t                Clutch;
   std::uint8_t                HandBrake;
   std::uint8_t                Gear;
   std::int8_t                 Steer;
   std::int8_t                 NormalizedDrivingLine;
   std::int8_t                 NormalizedAIBrakeDifference;
   float                       TireWearFrontLeft;
   float                       TireWearFrontRight;
   float                       TireWearRearLeft;
   float                       TireWearRearRight;
   std::int32_t                TrackOrdinal;
};
