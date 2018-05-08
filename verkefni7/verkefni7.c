#pragma config(Sensor, in1,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, in4,    LightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  sonarSensor,    sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           ClawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex269, openLoop)


#include "../functions/Drivefunctions.c";

task remote(){
	while(true){
		motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;

		if(vexRT[Btn6U] == 1)
		{
			motor[armMotor] = -40;
		}
		if(vexRT[Btn6D] == 1)
		{
			motor[armMotor] = 40;
		}

		if(vexRT[Btn5U] == 1)
		{
			motor[ClawMotor] = -40;
		}
		if(vexRT[Btn5D] == 1)
		{
			motor[ClawMotor] = 40;
		}
		else
		{
			motor[ClawMotor] = 0;
			motor[armMotor] = 0;
		}
	}
}

task verk5(){

int threshold = 2000;

while(true)
{
if(vexRT[Btn8D] ==1){
	StopAllTasks();
}

if(SensorValue(lineFollowerRIGHT) > threshold)
{

	motor[leftMotor]  = 63;
	motor[rightMotor] = 0;
}

if(SensorValue(lineFollowerCENTER) > threshold)
{

	motor[leftMotor]  = 63;
	motor[rightMotor] = 63;
}

if(SensorValue(lineFollowerLEFT) > threshold)
{

	motor[leftMotor]  = 0;
	motor[rightMotor] = 63;
}
}


}

task verk4(){

while(true){
if(vexRT[Btn8D] ==1){
	StopAllTasks();
}
if(SensorValue(LightSensor) > 600){
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}
else if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1 )
{
	motor[rightMotor] = 80;
	motor[leftMotor] = 80;
}
else{
	turn(127,true);
	resetEncoder();
}
}
}
task verkefni3(){
int  dist = 429.5;
resetEncoder();
drive(dist,true);
}
task verk3()

{
StartTask(verkefni3);
while(true){
if(vexRT[Btn8D] ==1){
	StopAllTasks();

}
}
}
task verk2(){
bool lr = true;
int nopower = 0;
int  dist = 429.5;
wait1Msec(2000);
for(int i=0; i<3; i++){

resetEncoder();
drive(dist,true);

resetEncoder();
turn(90,lr);
lr = false;
motor[rightMotor] = nopower;
motor[leftMotor]  = nopower;
wait1Msec(940);


}

resetEncoder();
drive(dist,true);




}


task main()
{
while(true){
if(vexRT[Btn8U]==1)
{
	StartTask(remote);
	StopTask(verk4);
	StopTask(verk3);
	StopTask(verk2);
	StopTask(verk5);

}
if(vexRT[Btn7U]==1)
{
	StartTask(verk5);
	StopTask(verk4);
	StopTask(verk3);
	StopTask(verk2);

}
if(vexRT[Btn7L])
{
	StartTask(verk4);
	StopTask(verk5);
	StopTask(verk3);
	StopTask(verk2);
}
if(vexRT[Btn7D]==1)
{
	StartTask(verk3);
	StopTask(verk5);
	StopTask(verk4);
	StopTask(verk2);
}
if(vexRT[Btn7R]==1)
{
	StartTask(verk2);
	StopTask(verk3);
	StopTask(verk4);
	StopTask(verk5);
}
else if(vexRT[Btn8D] ==1)
{
	StopAllTasks();
}
else{};


}


}
