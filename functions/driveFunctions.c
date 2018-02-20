#include "../headers/myconstants.h";
void drive(int dist,bool bf){
	int dir = (bf) ? (1):(-1);
	while(abs(SensorValue[leftEncoder]) < dist)
	{
		if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightMotor] = dir*80;		    // Right Motor is run at power level 80
			motor[leftMotor]  = dir*80;		    // Left Motor is run at power level 80
		}
		else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightMotor] = dir*60;		    // Right Motor is run at power level 60
			motor[leftMotor]  = dir*80;		    // Left Motor is run at power level 80
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightMotor] = dir*80;		    // Right Motor is run at power level 80
			motor[leftMotor]  = dir*60;		    // Left Motor is run at power level 60
		}
	}
};

void resetEncoder(){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

};

void turn(int deg,bool lr){
	while(deg*BASETURN > abs(Sensorvalue[leftEncoder])){
	if(lr){
		motor[rightMotor] = 80;
		motor[leftMotor] = -80;
	}
	else{
		motor[rightMotor] = -80;
		motor[leftMotor] = 80;
	}
}
}
