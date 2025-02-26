#pragma once
#include <cstdint>

namespace constant {
   inline constexpr std::uint16_t fudp_dash_size = 331;
}

struct alignas(float) udpPacket {
   char payload[constant::fudp_dash_size];
};

struct alignas(float) carTelemetry {
   std::int32_t                IsRaceOn;
   // Can overflow to 0 eventually
   std::uint32_t               TimestampMS;

   float                       EngineMaxRpm;
   float                       EngineIdleRpm;
   float                       CurrentEngineRpm;

   // In the car's local space
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
   // Suspension travel normalized: 0.0f = max stretch; 1.0 = max compression
   float                       NormalizedSuspensionTravelFrontLeft;
   float                       NormalizedSuspensionTravelFrontRight;
   float                       NormalizedSuspensionTravelRearLeft;
   float                       NormalizedSuspensionTravelRearRight;

   // Tire normalized slip ratio, = 0 means 100% grip and |ratio| > 1.0 means
   // loss of grip.
   float                       TireSlipRatioFrontLeft;
   float                       TireSlipRatioFrontRight;
   float                       TireSlipRatioRearLeft;
   float                       TireSlipRatioRearRight;

   // Wheels rotation speed radians/sec.
   float                       WheelRotationSpeedFrontLeft;
   float                       WheelRotationSpeedFrontRight;
   float                       WheelRotationSpeedRearLeft;
   float                       WheelRotationSpeedRearRight;

   // = 1 when wheel is on rumble strip, = 0 when off.
   std::int32_t                WheelOnRumbleStripFrontLeft;
   std::int32_t                WheelOnRumbleStripFrontRight;
   std::int32_t                WheelOnRumbleStripRearLeft;
   std::int32_t                WheelOnRumbleStripRearRight;

   // = from 0 to 1, where 1 is the deepest puddle
   float                       WheelInPuddleDepthFrontLeft;
   float                       WheelInPuddleDepthFrontRight;
   float                       WheelInPuddleDepthRearLeft;
   float                       WheelInPuddleDepthRearRight;
   // Non-dimensional surface rumble values passed to controller force feedback
   float                       SurfaceRumbleFrontLeft;
   float                       SurfaceRumbleFrontRight;
   float                       SurfaceRumbleRearLeft;
   float                       SurfaceRumbleRearRight;
   // Tire normalized slip angle, = 0 means 100% grip and |angle| > 1.0 means
   // loss of grip.
   float                       TireSlipAngleFrontLeft;
   float                       TireSlipAngleFrontRight;
   float                       TireSlipAngleRearLeft;
   float                       TireSlipAngleRearRight;

   // Tire normalized combined slip, = 0 means 100% grip and |slip| > 1.0 means
   // loss of grip.
   float                       TireCombinedSlipFrontLeft;
   float                       TireCombinedSlipFrontRight;
   float                       TireCombinedSlipRearLeft;
   float                       TireCombinedSlipRearRight;
   // Actual suspension travel in meters
   float                       SuspensionTravelMetersFrontLeft;
   float                       SuspensionTravelMetersFrontRight;
   float                       SuspensionTravelMetersRearLeft;
   float                       SuspensionTravelMetersRearRight;

   // Unique ID of the car make/model
   std::int32_t                CarOrdinal;
   // Between 0 (D -- worst cars) and 7 (X class -- best cars) inclusive
   std::int32_t                CarClass;
   // Between 100 (worst car) and 999 (best car) inclusive
   std::int32_t                CarPerformanceIndex;
   // 0 = FWD, 1 = RWD, 2 = AWD
   std::int32_t                DrivetrainType;
   // Number of cylinders in the engine
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
