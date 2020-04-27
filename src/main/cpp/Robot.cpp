// Copyright (c) 2020 FRC Team 3512. All Rights Reserved.

// Implementation code by Adan Silva

#include "Robot.h"

#include <iostream>
#include <string>

#include <frc/smartdashboard/SmartDashboard.h>
#include <units/units.h>
#include <wpi/math>

using namespace Constants;

Robot::Robot(){
    encoder0.SetVelocityConversionFactor(wpi::math::pi * 2.0 / 60.0);
    encoder1.SetVelocityConversionFactor(wpi::math::pi * 2.0 / 60.0);

    controller0.SetP(0.5);
    controller1.SetP(0.5);
    controller0.SetI(0);
    controller1.SetI(0);
    controller0.SetD(0);
    controller1.SetD(0);
}
void Robot::RobotInit() {

    //Color Sensor Registeration
    m_ColorMatch.AddColorMatch(kBlueArea);
    m_ColorMatch.AddColorMatch(kRedArea);
    m_ColorMatch.AddColorMatch(kGreenArea);
    m_ColorMatch.AddColorMatch(kYellowArea);

}

void Robot::RobotPeriodic() {
    //std::cout << "Left Vel:" << encoder0.GetVelocity() << std::endl;
    //std::cout << "Right Vel:" << encoder1.GetVelocity() << std::endl;
    //std::cout << "Left Temp: " << spark0.GetMotorTemperature() << std::endl;
    //std::cout << "Left Temp: " << spark1.GetMotorTemperature() << std::endl;

    logger.Log(spark0.GetMotorTemperature(), spark1.GetMotorTemperature(), encoder0.GetVelocity(), encoder1.GetVelocity());

    //Initalize values to controll identifying colors
    frc::Color m_detectedColor = m_ColorSensor.GetColor();
    std::string kColorString;
    double kConfidence = 0.0;
    frc::Color matchedColor = m_ColorMatch.MatchClosestColor(m_detectedColor, kConfidence);

     //Logic statements for checking the colors
    if (matchedColor == kBlueArea)
        kColorString = "Blue";
    else if (matchedColor == kYellowArea)
        kColorString = "Yellow";
    else if (matchedColor == kRedArea)
        kColorString = "Red";
    else if (matchedColor == kGreenArea)
        kColorString = "Green";
    else
        kColorString = "Unknown";

    frc::SmartDashboard::PutNumber("Red", m_detectedColor.red);
    frc::SmartDashboard::PutNumber("Blue", m_detectedColor.blue);
    frc::SmartDashboard::PutNumber("Green", m_detectedColor.green);
    frc::SmartDashboard::PutNumber("Confidence", kConfidence);
    frc::SmartDashboard::PutString("Detected Color", kColorString);

}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
    constexpr units::radians_per_second_t kMaxSpeed = 558.904_rad_per_s;
    
    // Spark Max # 0
    /*if (joystick0.GetRawButtonPressed(5)) {
        reference = kMaxSpeed * 0.1;
    } else if (joystick0.GetRawButtonPressed(6)) {
        reference = kMaxSpeed * 0.2;
    } else if (joystick0.GetRawButtonPressed(3)) {
        reference = kMaxSpeed * 0.3;
    } else if (joystick0.GetRawButtonPressed(4)) {
        reference = kMaxSpeed * 0.4;
    } else if (joystick0.GetRawButtonPressed(7)) {
        reference = kMaxSpeed * 0.5;
    } else if (joystick0.GetRawButtonPressed(8)) {
        reference = kMaxSpeed * 0.6;
    } else if (joystick0.GetRawButtonPressed(9)) {
        reference = kMaxSpeed * 0.7;
    } else if (joystick0.GetRawButtonPressed(10)) {
        reference = kMaxSpeed * 0.8;
    } else if (joystick0.GetRawButtonPressed(11)) {
        reference = kMaxSpeed * 0.9;
    } else if (joystick0.GetRawButtonPressed(12)) {
        reference = kMaxSpeed;
    } else if (joystick0.GetRawButtonPressed(2)) {
        reference = 0_rpm;
    } else if (joystick0.GetRawButtonPressed(1)) {
        reference = kMaxSpeed * 0.65;
    } 

    controller0.SetReference(
        units::radians_per_second_t(reference).to<double>(),
        rev::ControlType::kVelocity, reference / kMaxSpeed * 12.0);

    controller1.SetReference(
        units::radians_per_second_t(-reference).to<double>(),
        rev::ControlType::kVelocity, -reference / kMaxSpeed * 12.0); */
    
     if (joystick0.GetRawButtonPressed(5)){ 
      spark0.Set(0.1);
      spark1.Set(-.1);
     }
     else if (joystick0.GetRawButtonPressed(6)) {
       spark0.Set(0.2);
       spark1.Set(-.2);
     }
     else if (joystick0.GetRawButtonPressed(3)) {
       spark0.Set(0.3);
       spark1.Set(-.3);
     }
     else if (joystick0.GetRawButtonPressed(4)) {
       spark0.Set(0.4);
       spark1.Set(-.4);
     }
     else if (joystick0.GetRawButtonPressed(7)) {
       spark0.Set(0.5);
       spark1.Set(-.5);
     }
     else if (joystick0.GetRawButtonPressed(8)) {
       spark0.Set(0.6);
       spark1.Set(-.6);
     }
     else if (joystick0.GetRawButtonPressed(9)) {
       spark0.Set(0.7);
       spark1.Set(-.7);
     }
     else if (joystick0.GetRawButtonPressed(10)) {
       spark0.Set(0.8);
       spark1.Set(-.8);
     }
     else if (joystick0.GetRawButtonPressed(11)) {
        spark0.Set(0.55);
        spark1.Set(-0.55);
     } else if (joystick0.GetRawButtonPressed(12)) {
        spark0.Set(0.65);
        spark1.Set(-0.65);
     } else if (joystick0.GetRawButtonPressed(2)) {
        spark0.Set(0);
        spark1.Set(0);
     } 
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
