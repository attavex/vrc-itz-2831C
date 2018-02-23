#pragma config(Sensor, in1,    mogopot,        sensorPotentiometer)
#pragma config(Sensor, in2,    liftpot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  leftLiftEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  rightLiftEncoder, sensorQuadEncoder)
#pragma config(Motor,  port2,           Mani,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           DriveR,        tmotorVex393HighSpeed_MC29, openLoop, reversed, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port4,           leftLift,      tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, dgtl5)
#pragma config(Motor,  port5,           LMOGO,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Intake,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           DriveL,        tmotorVex393HighSpeed_MC29, openLoop, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port8,           rightLift,     tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, dgtl7)
#pragma config(Motor,  port9,           RMOGO,         tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

void leftBase(int speed) //declaring what is left-base
{
	motor[DriveL] = speed;

}

void rightBase(int speed) //declaring what is right-base
{
	motor[DriveR] = speed;

}

void stopbase()
{
	rightBase(0);
	leftBase(0);
}

void drive(int speed, int time)
{
	leftBase(speed);
	rightBase(speed);
	wait1Msec(time);
	stopMotor(DriveL);
	stopMotor(DriveR);


}

void turnright(int time, int speed)
{
	leftBase(speed);
	rightBase(-speed);
	wait1Msec(time);
	stopMotor(DriveR);
	stopMotor(DriveL);
}
void turnleft(int time, int speed)
{
	leftBase(-speed);
	rightBase(speed);
	wait1Msec(time);
	stopMotor(DriveR);
	stopMotor(DriveL);

}

void mogodown()
{
	setMotor(LMOGO, -127);
	setMotor(RMOGO, 127);
}

void mogostop()
{
	stopMotor(LMOGO);
	stopMotor(RMOGO);
}

void mogoup()
{
	setMotor(LMOGO, 127);
	setMotor(RMOGO, -127);
}

void maniup()
{
	setMotor(Mani, -127);
	wait1Msec(1200);
	stopMotor(Mani);
}

void manidown()
{
	setMotor(Mani, 127);
	wait1Msec(1500);
	stopMotor(Mani);
}

void liftup(int time, int power)
{
	motor[leftLift] = power;
	motor[rightLift] = -power;
	wait1Msec(time);
}

void liftdown(int time, int power)
{
	motor[leftLift] = -power;
	motor[rightLift] = power;
	wait1Msec(time);
}

void automogodown()
{
	SensorValue[mogopot] = 250;
	while(SensorValue(mogopot) > 400)
	{
		mogodown();
	}
	mogostop();
}

void automogoup()
{
	while(SensorValue(mogopot) < 1400)
	{
		mogoup();
	}
	mogostop();
}

void moveForward(int amount,int power) //ABOUT 22 TICKS PER INCH
{

	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(abs(SensorValue[rightEncoder]) < amount && (abs(SensorValue[leftEncoder]) < amount))
	{
		motor[DriveR] = power;
		motor[DriveL] = power;


	}
	motor[DriveR] = 0;
	motor[DriveL] = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

void moveBackward(int amount,int power)
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(abs(SensorValue[rightEncoder]) < amount && (abs(SensorValue[leftEncoder]) < amount))
	{
		motor[DriveR] = -power;
		motor[DriveL] = -power;
	}

	motor[DriveR] = 0;
	motor[DriveL] = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

void rightTurn(int amount, int power)
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(abs(SensorValue[rightEncoder]) < amount && (abs(SensorValue[leftEncoder]) < amount))
	{
		motor[DriveR] = -power;
		motor[DriveL] = power;
	}

	motor[DriveR] = 0;
	motor[DriveL] = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

void leftTurn(int amount, int power)
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(abs(SensorValue[rightEncoder]) < amount && (abs(SensorValue[leftEncoder]) < amount))
	{
		motor[DriveR] = power;
		motor[DriveL] = -power;
	}

	motor[DriveR] = 0;
	motor[DriveL] = 0;
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

/*
void driveStraightDistance(int in, int masterPower)
{
int tickGoal = (42 * in);

int totalTicks = 0;

int slavePower = masterPower - 5;

int error = 0;

int kp = 5;

SensorValue[leftEncoder] = 0;
SensorValue[rightEncoder] = 0;


while (sgn(tickGoal) == 1 && totalTicks < tickGoal || sgn(tickGoal) == -1 && totalTicks > tickGoal) {
//(abs(totalTicks) < tickGoal)


motor[DriveR] = masterPower;
motor[DriveL] = slavePower;

error = SensorValue[leftEncoder] - SensorValue[rightEncoder];

slavePower += error / kp;
/*
SensorValue[leftEncoder] = 0;
SensorValue[rightEncoder] = 0;


wait1Msec(100);

totalTicks += SensorValue[leftEncoder];
}
motor[DriveR] = masterPower;
motor[DriveL] = slavePower;

}
*/

//LCD Auton

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}

void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}



int count = 0;

void pre_auton()
{
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Turn On LCD Backlight
	bLCDBacklight = true;

	if(bIfiRobotDisabled == 1) {


		while(nLCDButtons != centerButton)
		{
			switch(count){
			case 0:
				//Display first choice
				displayLCDCenteredString(0, "LeftMogo Auton");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count = 3;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
			case 1:
				//Display second choice
				displayLCDCenteredString(0, "RightMogo Auton");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
			case 2:
				//Display third choice
				displayLCDCenteredString(0, "Station Auton");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count++;
				}
				break;
			case 3:
				//Display fourth choice
				displayLCDCenteredString(0, "Prog Skills");
				displayLCDCenteredString(1, "<		 Enter		>");
				waitForPress();
				//Increment or decrement "count" based on button press
				if(nLCDButtons == leftButton)
				{
					waitForRelease();
					count--;
				}
				else if(nLCDButtons == rightButton)
				{
					waitForRelease();
					count = 0;
				}
				break;
			default:
				count = 2;
				break;
			}
		}
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous                                   */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task liftfulldown
{
	while(SensorValue[liftpot] < 350)
	{
		motor[leftLift] = -125;
		motor[rightLift] = 127;
	}
}
task liftlow
{
	while(SensorValue[liftpot] < 700)
	{
		motor[leftLift] = 125;
		motor[rightLift] = -127;
	}
}

task maniup
{
	motor[Mani] = -127;
	wait1Msec(800);
	motor[Mani] = 0;
}

task manidown
{
	motor[Mani] = 127;
	wait1Msec(1000);
	motor[Mani] = 0;
}

task mogodeploy
{
	mogodown();
	wait1Msec(1000);
	mogostop();
}

task mogointake
{
	mogoup();
	wait1Msec(1200);
	mogostop();
}

void encoderprac()
{
	//	moveForward(12, 127);
	//	moveForward(-3, 127);
	rightTurn(1000,127);
	wait1Msec(500);
	leftTurn(1000,127);

	/*wait1Msec(100);
	driveStraightDistance(-12, 127);
	wait1Msec(100);
	driveStraightDistance(12, 127);
	*/
}
void auton() //left side prac

{
	//automogodown();
	//driveStraightDistance(16, 127); //work on this more... continue when bot is optimized at opc :D

	//automogodown();
	drive(127, 2000);
	wait1Msec(1000);
	//automogoup();
	wait1Msec(1000);
	drive(-127, 2000);
	wait1Msec(700);
	turnleft(100, 900);
	wait1Msec(700);
	drive(50, 300);
	wait1Msec(700);
	turnright(50, 450);
	wait1Msec(700);
	drive(127, 1000);
	//automogodown();
	wait1Msec(500);
	drive(-50, 200);
	wait1Msec(500);
	//automogoup();
	wait1Msec(500);
	drive(-127, 1000);

}

void skillsprac() //left side skills prac
{
	//automogodown();
	drive(127, 2000);
	wait1Msec(1000);
	//automogoup();
	wait1Msec(1000);
	drive(-127, 2000);
	turnleft(100, 900);
	wait1Msec(700);
	drive(50, 300);
	wait1Msec(700);
	turnright(50, 450);
	drive(127, 1000);
	//automogodown();
	wait1Msec(200);
	drive(-50, 200);
	wait1Msec(500);
	//automogoup();
	wait1Msec(500);
	drive(-127, 1000);
	turnright(50, 100);
	drive(-50, 200);
	turnleft(50, 100);
	drive(-127, 7000);
}



task autonomous()
{

	bLCDBacklight = true;
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run left side mogo
		displayLCDCenteredString(0, "LeftMogo Auton");
		displayLCDCenteredString(1, "is running!");
		motor[Intake] = 20;
		moveForward(44, 127);
		moveBackward(22, 127);
		startTask(liftlow);
		startTask(maniup);
		wait1Msec(200);
		stopTask(liftlow);
		stopTask(maniup);
		startTask(mogodeploy);
		moveForward(1200, 127);
		startTask(mogointake);
		wait1Msec(400);
		stopTask(mogodeploy);
		stopTask(mogointake);
		motor[Intake] = -127;
		wait1Msec(400);
		stopMotor(Intake);
		startTask(liftfulldown);
		startTask(manidown);
		motor[Intake] = 127; //intake second cone
		wait1Msec(400);
		stopMotor(Intake);
		stopTask(manidown);
		stopTask(liftfulldown);
		startTask(maniup);
		motor[Intake] = 127; //drop second cone
		wait1Msec(400);
		stopMotor(Intake);
		stopTask(maniup);
		moveBackward(1000, 127);
		wait1Msec(200);
		leftTurn(300, 127);
		moveBackward(50, 127);
		leftTurn(850, 127);
		moveForward(10, 127);
		startTask(liftlow);
		startTask(mogodeploy);
		wait1Msec(100);
		stopTask(mogodeploy);
		stopTask(liftlow);
		moveBackward(10, 127);
		startTask(mogointake);
		wait1Msec(200);
		moveBackward(100, 127);
		stopAllTasks();

		break;
	case 1:
		//If count = 1, run right side mogo
		displayLCDCenteredString(0, "RightMogo Auton");
		displayLCDCenteredString(1, "is running!");
		motor[Intake] = 20;
		moveForward(44, 127);
		moveBackward(22, 127);
		startTask(liftlow);
		startTask(maniup);
		wait1Msec(200);
		stopTask(liftlow);
		stopTask(maniup);
		startTask(mogodeploy);
		moveForward(1200, 127);
		startTask(mogointake);
		wait1Msec(400);
		stopTask(mogodeploy);
		stopTask(mogointake);
		motor[Intake] = -127;
		wait1Msec(400);
		stopMotor(Intake);
		startTask(liftfulldown);
		startTask(manidown);
		motor[Intake] = 127; //intake second cone
		wait1Msec(400);
		stopMotor(Intake);
		stopTask(manidown);
		stopTask(liftfulldown);
		startTask(maniup);
		motor[Intake] = 127; //drop second cone
		wait1Msec(400);
		stopMotor(Intake);
		stopTask(maniup);
		moveBackward(1000, 127);
		wait1Msec(200);
		rightTurn(300, 127);
		moveBackward(50, 127);
		rightTurn(850, 127);
		moveForward(10, 127);
		startTask(liftlow);
		startTask(mogodeploy);
		wait1Msec(100);
		stopTask(mogodeploy);
		stopTask(liftlow);
		moveBackward(10, 127);
		startTask(mogointake);
		wait1Msec(200);
		moveBackward(100, 127);
		stopAllTasks();


		break;
	case 2:
		//If count = 2, run stationary goal
		displayLCDCenteredString(0, "Station Auton");
		displayLCDCenteredString(1, "is running!");
		/*
		setMotor(Intake, 127);
		wait1Msec(500);
		setMotor(Intake, 25);
		drive(127, 400);
		drive(-127, 300);
		drive(127, 200);
		maniup();
		wait1Msec(1000);
		liftup(500, 127);
		wait1Msec(500);
		drive(127, 700);
		wait1Msec(500);
		setMotor(Mani, 127);
		wait1Msec(1500);
		stopMotor(Mani);
		wait1Msec(300);
		liftdown(200, 127);
		wait1Msec(300);
		motor[Intake] = -127;
		wait1Msec(400);
		stopMotor(Intake);
		maniup();
		drive(-127, 300);
		liftdown(400, 127);
		stopAllMotors();


		*/


	case 3:
		//If count = 3, run prog skills
		displayLCDCenteredString(0, "Prog Skills");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(15000);						// Robot waits for 2000 milliseconds


		break;
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
/*
static int kp = 5;
static int ki = 5;
int error;
int output;
int target;
static int integralMax
*/
void tank(int left_speed  , int right_speed) {
	setMotor(DriveL , left_speed);
	setMotor(DriveR , right_speed);
}

void arcade(int turn, int power) {
	setMotor(DriveL, power + turn);
	setMotor(DriveR, power - turn);

}
/*
task holdLift()
{
target = SensorValue[liftpot];
error = target - SensorValue[liftpot];
output = error * kp + error * ki;
motor[LY1] = output;
motor[LY2] = -output;
while (true) {
error = target - current
if (error < 100) {
ki += error
if (integral > integralMax) {
integral = integralMax; //sets limit
}
}
}
}
*/

task usercontrol()
{
	string mainBattery ;
	bLCDBacklight = true;
	clearLCDLine(0);
	clearLCDLine(1);
	while (true)
	{



		//LCD(Bat Level and phrase)
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDString(0, 0, "MainBat: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);
		displayLCDCenteredString(1, "2831 : Caliber 2.0");

		//Drive
		//tank(vexRT[Ch3] + vexRT[Ch3Xmtr2], vexRT[Ch2] + vexRT[Ch2Xmtr2]); //setting tank drive for both controllers...
		//adding values creates equal drive for both main and 2nd controller.
		//arcadeControl(Ch3, Ch4, 15);
		arcade(vexRT[Ch4], vexRT[Ch3]);




		//MOGO Intake (2nd Controller)
		if (vexRT[Btn6UXmtr2] == 1){
			motor[LMOGO] = 127;
			motor[RMOGO] = -127;
		}
		else if (vexRT[Btn6DXmtr2] == 1){
			motor[LMOGO] = -127;
			motor[RMOGO] = 127;
		}
		else if (vexRT[Btn8U] == 1){ //main
			motor[LMOGO] = 127;
			motor[RMOGO] = -127;
		}
		else if (vexRT[Btn8L] == 1){
			motor[LMOGO] = -127;
			motor[RMOGO] = 127;
		}
		else
		{
			motor[LMOGO] = 0;
			motor[RMOGO] = 0;
		}


		//Lift(Main Controller
		/*
		if (SensorValue[liftpot] > 20)//not tested... in theory keeps the task from not running if lift is not up
		{
		startTask(holdLift);
		}
		else {
		stopTask(holdLift);
		}
		*/

		if (vexRT[Btn6U] == 1){
			motor[leftLift] = 125;
			motor[rightLift] = -127;
			SensorValue[liftpot] = 0;
		}
		else if (vexRT[Btn6D] == 1){
			motor[leftLift] = -120;
			motor[rightLift] = 75;
			SensorValue[liftpot] = 0;
		}

		else if(SensorValue[liftpot] < 250)
		{
			motor[leftLift] = -5;
			motor[rightLift] = 5;
		}
		else if(SensorValue[liftpot] > 300)
		{
			motor[leftLift] = 9;
			motor[rightLift] = -12;
		}
		else
		{
			motor[leftLift] = 0;
			motor[rightLift] = 0;
		}
		//Mani(Main Controller)
		if (vexRT[Btn5U] == 1){
			motor[Mani] = -127;
		}
		else if (vexRT[Btn5D] == 1){
			motor[Mani] = 127;
		}
		else
		{
			motor[Mani] = -11;
		}


		//intake

		if (vexRT[Btn7L] == 1){
			motor[Intake] = -127;
		}
		else if (vexRT[Btn8R] == 1){
			motor[Intake] = 127;
		}
		else {
			motor[Intake] = 25;
		}
		/*
		//encoder prac
		if(vexRT[Btn8U] == 1) {
		encoderprac();
		}
		/*
		//automogoprac
		if(vexRT[Btn8D] == 1) {
		automogodown();
		}

		*/
	}
}
