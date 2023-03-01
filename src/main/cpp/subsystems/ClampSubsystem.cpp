// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClampSubsystem.h"

ClampSubsystem::ClampSubsystem(frc::PowerDistribution* PDP) : m_PDP(PDP) {}

// This method will be called once per scheduler run
void ClampSubsystem::Periodic() {}

void ClampSubsystem::Run(double set) {
    m_motor.Set(set);
}

double ClampSubsystem::GetCurrent() {
  return m_PDP->GetCurrent(9);
}