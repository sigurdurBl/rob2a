#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward at full power for three seconds.  There is a    *|
|*  two second pause at the beginning of the program.                                                 *|                                                                   *|                 *|
\*-----------------------------------------------------------------------------------------------4246-*/
int power = 127;
int rewerse = -127;

void drive(){
	motor[rightMotor] = power;
	motor[leftMotor]  = power;
	wait1Msec(940);

	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(2000);

	motor[rightMotor] = rewerse;
	motor[leftMotor] = rewerse;
	wait1Msec(940);


}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	  drive();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
