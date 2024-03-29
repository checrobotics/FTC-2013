#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     touchBucketUp,  sensorTouch)
#pragma config(Sensor, S4,     touchBucketZero, sensorTouch)
#pragma config(Motor,  motorA,           ,             tmotorNXT, PIDControl)
#pragma config(Motor,  motorB,           ,             tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,           ,             tmotorNXT, PIDControl)
#pragma config(Motor,  mtr_S1_C2_1,     Right_drive,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Left_drive,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     bucket,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    Right_Flipper,        tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    Left_Flipper,         tServoStandard)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*--------------------------------------------------------------------------------------------------------*\
|*                                                                                                        *|
|*                                    - Tetrix Simple Tank Drive -                                        *|
|*                                          ROBOTC on Tetrix                                              *|
|*                                                                                                        *|
|*  This program allows you to drive a robot via remote control using the ROBOTC Debugger.                *|
|*  This particular method uses "Tank Drive" where each side is controlled individually like a tank.      *|
|*                                                                                                        *|
|*                                        ROBOT CONFIGURATION                                             *|
|*    NOTES:                                                                                              *|
|*                                                                                                        *|
|*    MOTORS & SENSORS:                                                                                   *|
|*    [I/O Port]              [Name]              [Type]              [Description]                       *|
|*    Port D                  motorD              12V                 Right motor                         *|
|*    Port E                  motorE              12V                 Left motor                          *|
\*---------------------------------------------------------------------------------------------------4246-*/

#include "JoystickDriver.c"

task main()
{
  while(true)                            // Infinite loop:
  {
    getJoystickSettings(joystick);

    motor[Right_drive] = joystick.joy2_y2;         // Motor D is assigned a power level equal to the right analog stick's Y-axis reading.
    motor[Left_drive] = joystick.joy2_y1;         // Motor E is assigned a power level equal to the left analog stick's Y-axis reading.



    // BUTTONS TO CONTOL SERVO ARM
    // Control arm via shoulder buttons, 5 and 6... 6=up, 5=down

    if(joy1Btn(7))          // If Button 5 on controller 1 is pressed:
    {
      servo[Left_Flipper] = 25;      // Lower left flipper to position 225.
    }

    if(joy1Btn(5))          // If Button 7 on controller 1 is pressed:
    {
      servo[Left_Flipper] = 200;       // Raise left flipper to open 0 degrees.
    }


  if(joy1Btn(6))          // If Button  6 on controller 1 is pressed:
    {
      servo[Right_Flipper] = 42;      // Raise the rigt flipper to open 150 degrees.
    }

    if(joy1Btn(8))          // If Button 8 on controller 1 is pressed:
    {
      servo[Right_Flipper] = 225;       // Lower rigth flipper to position 0.
	  }


  if(joy1Btn(4))      // If the button 4 on controller 1 is pressed
  {
  nMotorEncoder[bucket] = 0;
  nMotorEncoderTarget[bucket] = 200;  // target 240 degrees (960 encoder counts) to dump the bucket
  motor[bucket] = -25;
  while(nMotorRunState[bucket] != runStateIdle)  // While Motor is still running:
		{
  	// Do not continue.
		}
  motor[bucket] = 0;
	}
  else
	{
	motor[bucket] = 0;
	}


 if(joy1Btn(2)& SensorValue(touchBucketZero)== 0)      // If the button 2 on controller 1 is pressed & touch sensor is not pressed :
  {

  while (SensorValue(touchBucketZero) != 1)							// bucket motor will move clockwise until touch sensor is pressed
  {
  	motor[bucket] = 25;

  }
  motor[bucket] = 0;
	}
  else
  {
  	motor[bucket] = 0;
  }
if(joy1Btn(3)& SensorValue(touchBucketUp)== 0)      // If the button 3 on controller 1 is pressed & touch sensor is not pressed :
  {

  while (SensorValue(touchBucketUp) != 1)							// bucket motor will move counterclockwise until touch sensor is pressed
 {
  	motor[bucket] = -20;

  }
  motor[bucket] = 0;
	}
  else
  {
  	motor[bucket] = 0;
  }







  }

}
