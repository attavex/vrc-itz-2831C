#include "main.h"

TaskHandle driveTask, turnTask;

int driveGet() 
{
    return((encoderGet(LEFT_ENCODER) + encoderGet(RIGHT_ENCODER)) / 2);
}




void testPIDRotate(int gyDes)
{
  turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
//anything here will run
  while(gyroGet(GYRO) < gyDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(turnTask);
}

void testPIDDrive(int dDes)
{
  driveTask = taskCreate(pidDrive, TASK_DEFAULT_STACK_SIZE, (void*)dDes, TASK_PRIORITY_DEFAULT);
 //anything here will run
  while(driveGet() < dDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(driveTask);
}

int dDes;
int gyDes;
void aStationaryAuton(char cGtfo[], int iCone) {
  lift(127);
  mogo(127);
  mani(-127);
  driveSpeed(127);
  while(analogRead(LIFT_POT) > 2845 || analogRead(MANI_POT) > 2800 || driveGet() < 200 || analogRead(MOGO_POT) < 1400) 
  {  
    if(analogRead(LIFT_POT) < 2845) lift(10);
    if(analogRead(MANI_POT) < 2800) mani(-10);
    if(analogRead(MOGO_POT) > 1400) mogo(20);
    if(driveGet() > 200) driveSpeed(0);
    delay(20);
  }
   lift(10); mogo(30); driveSpeed(0); mani(-10);
  driveSpeed(127);
  wait(250); driveSpeed(0); wait(500);
  lift(-127);
  wait(250);
  roller(-127);
  wait(50);
  lift(127);
  wait(250);
  lift(10);
  roller(0);
  mani(0);
  mani(127);
  mogo(-127);
  while(analogRead(MANI_POT) < 3900 || analogRead(MOGO_POT) > 500)
  {
  if(analogRead(MANI_POT) > 3800) mani(0);
  if(analogRead(MOGO_POT) < 200) mogo(0);
  delay(20);
  }
  wait(1000);
  dDes = -200;
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  driveTask = taskCreate(pidDrive, TASK_DEFAULT_STACK_SIZE, (void*)dDes, TASK_PRIORITY_DEFAULT);
    while(driveGet() < dDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(driveTask);
  wait(1000);
  gyDes = 81;
  gyroReset(GYRO);
  turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
  while(gyroGet(GYRO) < gyDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(turnTask);
  motorStopAll();
  dDes = 200;
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  driveTask = taskCreate(pidDrive, TASK_DEFAULT_STACK_SIZE, (void*)dDes, TASK_PRIORITY_DEFAULT);
    while(driveGet() < dDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(driveTask);
  motorStopAll();
  wait(2000);
  lift(-80);
  mani(-127);
  roller(127);
  while(analogRead(LIFT_POT) > 3400 || analogRead(MANI_POT) > 2200) 
  {  
    if(analogRead(LIFT_POT) > 3550) lift(5);
    if(analogRead(MANI_POT) < 2100) mani(-10);
    delay(20);
  }
  mani(127);
  while(analogRead(MANI_POT) < 3900)
  {
  if(analogRead(MANI_POT) > 3800)
  {
    mani(10);
    roller(30);
  }
  delay(20);
  }
  gyDes = -100;
  wait(2000);
  gyroReset(GYRO);
  turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
  while(gyroGet(GYRO) > gyDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(turnTask);
  motorStopAll();
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  roller(20);
   lift(127); mogo(127);
   wait(300);
 
  mani(-127);
  driveSpeed(127);
  while(analogRead(LIFT_POT) > 2845 || analogRead(MANI_POT) > 2800 || driveGet() < 200 || analogRead(MOGO_POT) < 1400) 
  {  
    if(analogRead(LIFT_POT) < 2845) lift(10);
    if(analogRead(MANI_POT) < 2800) mani(-10);
    if(analogRead(MOGO_POT) > 1400) mogo(20);
    if(driveGet() > 200) driveSpeed(0);
    delay(20);
  }
   lift(10); mogo(30); driveSpeed(0); mani(-10);
  driveSpeed(127);
  wait(250); driveSpeed(0); wait(500);
  lift(-127);
  wait(250);
  roller(-127);
  wait(50);
  lift(127);
  wait(250);
  lift(10);
  roller(0);
  mani(0);
  mani(127);
  mogo(-127);
  while(analogRead(MANI_POT) < 3900 || analogRead(MOGO_POT) > 500)
  {
  if(analogRead(MANI_POT) > 3800) mani(0);
  if(analogRead(MOGO_POT) < 200) mogo(0);
  delay(20);
  }
  //end of second cone
  wait(1000);
  //start of third cone 
  dDes = -100;
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  driveTask = taskCreate(pidDrive, TASK_DEFAULT_STACK_SIZE, (void*)dDes, TASK_PRIORITY_DEFAULT);
    while(driveGet() < dDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(driveTask);
  wait(1000);
  gyDes = 100;
  gyroReset(GYRO);
  turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
  while(gyroGet(GYRO) < gyDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(turnTask);
  motorStopAll();
  dDes = 100;
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  driveTask = taskCreate(pidDrive, TASK_DEFAULT_STACK_SIZE, (void*)dDes, TASK_PRIORITY_DEFAULT);
    while(driveGet() < dDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(driveTask);
  motorStopAll();
  wait(2000);
  lift(-80);
  mani(-127);
  roller(127);
  while(analogRead(LIFT_POT) > 3400 || analogRead(MANI_POT) > 2200) 
  {  
    if(analogRead(LIFT_POT) > 3550) lift(5);
    if(analogRead(MANI_POT) < 2100) mani(-10);
    delay(20);
  }
  mani(127);
  while(analogRead(MANI_POT) < 3900)
  {
  if(analogRead(MANI_POT) > 3800)
  {
    mani(10);
    roller(30);
  }
  delay(20);
  }
  gyDes = -105;
  wait(2000);
  gyroReset(GYRO);
  turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
  while(gyroGet(GYRO) > gyDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(turnTask);
  motorStopAll();
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  roller(20);
  lift(127); mogo(127);
  wait(300);
  mani(-127);
  driveSpeed(127);
  while(analogRead(LIFT_POT) > 2845 || analogRead(MANI_POT) > 2800 || driveGet() < 200 || analogRead(MOGO_POT) < 1400) 
  {  
    if(analogRead(LIFT_POT) < 2845) lift(10);
    if(analogRead(MANI_POT) < 2800) mani(-10);
    if(analogRead(MOGO_POT) > 1400) mogo(20);
    if(driveGet() > 200) driveSpeed(0);
    delay(20);
  }
  lift(10); mogo(30); driveSpeed(0); mani(-10);
  driveSpeed(127);
  wait(250); driveSpeed(0); wait(500);
  lift(-127);
  wait(250);
  roller(-127);
  wait(50);
  lift(127);
  wait(250);
  lift(10);
  roller(0);
  mani(0);
  mani(127);
  mogo(-127);
  while(analogRead(MANI_POT) < 3900 || analogRead(MOGO_POT) > 500)
  {
  if(analogRead(MANI_POT) > 3800) mani(0);
  if(analogRead(MOGO_POT) < 200) mogo(0);
  delay(20);
  }
  wait(1000);

}


void mogoAutonMaster20(int choice) 
{
    if(choice == 1)
    {
        //insert red-side, 20 point, 2 cone auton
    }
    else if(choice == 2)
    {
        //insert blue-side, 20 point, 2 cone auton
    }
    else if(choice == 3)
    {
        //insert red-side, 20 point, 3 cone auton
    }
    else if(choice == 4)
    {
        //insert blue-side, 20 point, 3 cone auton
    }
}

void mogoAutonMaster5(int choice)
{
    if(choice == 1)
    {
        //insert red-side, 5 point, 2 cone auton
    }
    else if(choice == 2)
    {
        //insert blue-side, 5 point, 2 cone auton
    }
    else if(choice == 3)
    {
        //insert red-side, 5 point, 3 cone auton
    }
    else if(choice == 4)
    {
        //insert blue-side, 5 point, 3 cone auton
    }
}

void stationaryAuton()
{
    //insert stationary 3 cone auton
}

void progSkills()
{
    //insert prog skills 
}










void autonomous() 
{
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  gyroReset(GYRO);
  aStationaryAuton("red", 1);
}