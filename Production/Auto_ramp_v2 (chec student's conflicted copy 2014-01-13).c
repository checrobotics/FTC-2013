#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S2,     rearSonar,      sensorSONAR)
#pragma config(Sensor, S3,     IRSeek,         sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touchBucketZero, sensorTouch)
#pragma config(Motor,  mtr_S1_C2_1,     Right_drive,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     Left_drive,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     bucket,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    Right_Flipper,        tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    Left_Flipper,         tServoStandard)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an Tetrix robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
//#include "HTIRS2-driver.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC.
  // They may need a brief time to stabilize.

 // servo[Right_Flipper] = 42;        // Open Right Flipper for start of match to allow bucket to dump
 // servo[Left_Flipper] = 200;        // Open Left Flipper for start of match to allow bucket to dump

//  wait1Msec(500);            // wait for servos to get to position

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

   waitForStart(); // Wait for the beginning of autonomous phase.

  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////


  	// CONFIGURATION VARIABLES //
    int driveTime = 		1500;					//in MILLISECONDS   1000 MS = 1 second //
    int bucketDump = 		1600;
    int bucketStop = 		800;
    int L_Flip_Open = 	15;
    int L_Flip_Close = 	150;
   	int R_Flip_Close = 	85;
    int R_Flip_Open = 	230;


    ///////////////////////////////////////////////////////
    //    BEGIN AUTONOMOUS ROUTINE                       //
    ///////////////////////////////////////////////////////



		// Drive backward for drivetime @ 20% power //
				  motor[Left_drive] = -20;
				  motor[Right_drive] = -20;
				  wait1Msec(driveTime);
				  motor[Left_drive] = 0;
				  motor[Right_drive] = 0;

		// Set Flippers to Open //

				  servo[Left_Flipper] = L_Flip_Open;
				  servo[Right_Flipper] = R_Flip_Open;
				  wait1Msec(2000);

   // Perform lift cycle //

				  nMotorEncoderTarget[bucket] = bucketDump;  // target bucket dumping position
				  motor[bucket] = -25;
				  while(nMotorRunState[bucket] != runStateIdle)  // While Motor is still running, allow to go to target posititon
						{
				  	// Do not continue.
						}
				  motor[bucket] = 0;

				  // if(SensorValue(touchBucketZero)== 0)
				  // {
				  nMotorEncoderTarget[bucket] = bucketStop;  // target bucket drive position
				  motor[bucket] = 25;
				  while(nMotorRunState[bucket] != runStateIdle)  // While Motor is still running, allow to go to target posititon
						{
				  	// Do not continue.
						}
				  motor[bucket] = 0;

	  	// Set Flippers to Close //

				  servo[Left_Flipper] = L_Flip_Close;
				  servo[Right_Flipper] = R_Flip_Close;
				  wait1Msec(1000);

		// Drive forward for 1000ms = drivetime/3 @ 20% power //
				  motor[Left_drive] = 20;
				  motor[Right_drive] = 20;
				  wait1Msec(driveTime/3);
				  motor[Left_drive] = 0;
				  motor[Right_drive] = 0;

		// Rotate clockwise for 1000ms  @ 20% power //
				  motor[Left_drive] = -20;
				  motor[Right_drive] = 20;
				  wait1Msec(1000);
				  motor[Left_drive] = 0;
				  motor[Right_drive] = 0;

	// Drive forward for 2500ms @ 20% power //
				  motor[Left_drive] = 20;
				  motor[Right_drive] = 20;
				  wait1Msec(1300);
				  motor[Left_drive] = 0;
				  motor[Right_drive] = 0;

	// Rotate clockwise for 500ms @ 20% power //
				  motor[Left_drive] = -20;
				  motor[Right_drive] = 20;
				  wait1Msec(750);
				  motor[Left_drive] = 0;
				  motor[Right_drive] = 0;

	// Drive forward for 3500ms @ 20% power //
				  motor[Left_drive] = 40;
				  motor[Right_drive] = 40;
				  wait1Msec(1500);
				  motor[Left_drive] = 0;
				  motor[Right_drive] = 0;

		////////////////////////////
  	// End Autonomous Routine //
  	////////////////////////////
}
