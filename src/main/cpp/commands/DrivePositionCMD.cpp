// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DrivePositionCMD.h"

DrivePositionCMD::DrivePositionCMD(ExtensionSubsystem* Extension, WinchSubsystem* Winch) : m_Extension(Extension), m_Winch(Winch) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(Extension);
  AddRequirements(Winch);
}

// Called when the command is initially scheduled.
void DrivePositionCMD::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DrivePositionCMD::Execute() {
  m_Extension->ZeroExtension();
  m_Winch->SetPosition(0.1);
}

// Called once the command ends or is interrupted.
void DrivePositionCMD::End(bool interrupted) {}

// Returns true when the command should end.
bool DrivePositionCMD::IsFinished() {
  if (m_Winch->GetPosition() == 0.1 && m_Extension->SwitchLow()) {
    return true;
  } else return false;
}
