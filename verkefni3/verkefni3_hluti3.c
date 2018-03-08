#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           ClawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex269, openLoop)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses both the Left and the Right joysticks to run the robot using "tank control".    *|
|*  The Group 6 buttons on the top-right of the VEXnet Joystick are used to raise and lower an arm.   *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
|*    Motor - Port 6          armMotor             VEX Motor           Arm motor                      *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
#include "../functions/Drivefunctions.c";

bool lr = true;
int nopower = 0;
int  dist = 429.5;

// Functions Prototypes


// Declare Global Variables     /* 'rotations' will be a counter for every 360 encoder clicks */


task verk3(){

  	resetEncoder();
    drive(dist,true);
}

task main()
{
	StartTask(verk3);
		while(true){
		if(vexRT[Btn8D] ==1){
		StopAllTasks();
		}
	}
}


//  while(1 == 1)
//  {
//    //Driving Motor Control
//    motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;
//    motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;

//    //Arm Control
//    if(vexRT[Btn6U] == 1)
//    {
//      motor[armMotor] = -40;
//    }
//    else if(vexRT[Btn6D] == 1)
//    {
//      motor[armMotor] = 40;
//    }
//    else
//    	motor[armMotor] = 0;
//    {

//  }
//  if(vexRT[Btn5U] == 1)
//    {
//      motor[ClawMotor] = -40;
//    }
//    else if(vexRT[Btn5D] == 1)
//    {
//      motor[ClawMotor] = 40;
//    }
//    else
//    	motor[ClawMotor] = 0;
//    {

//  }
//}
//}