#pragma once

#include "include/controller.hpp"
#include "include/robot.hpp"

int main(void)
{

    char menuLabels[4][20] = { "System Chk", "Run", "Calibrate", "Quit" };

/*
    DigitalEncoder leftEncoder(FEHIO::P1_7);
    DigitalEncoder rightEncoder(FEHIO::P1_0);


    //IGWAN Motors
    FEHMotor leftIGWAN(FEHMotor::Motor0, 9.0);
    FEHMotor rightIGWAN(FEHMotor::Motor1, 9.0);

    //Servo Motors
    FEHServo plateServo(FEHServo::Servo0);
    FEHServo armServo(FEHServo::Servo1);
    */

    float xPos;
    float yPos;

    Controller controller;

    controller.GUIControl(menuLabels);

    float x = 0;
    float y = 0;

    bool actionSelected = false;

    LCD.Clear();

    FEHIcon::Icon menu[4];

    FEHIcon::DrawIconArray(menu, 2, 2, 10, 10, 5, 5, menuLabels, RED, WHITE);



    // controller.SetMotor(leftIGWAN, 15);
    // controller.SetMotor(rightIGWAN, -15);

    // rightEncoder.ResetCounts();

    // while (rightEncoder.Counts() < 300);

    // controller.SetMotor(leftIGWAN, 0);
    // controller.SetMotor(rightIGWAN, 0);

	return 0;
}
