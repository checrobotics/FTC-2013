#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     lightSensor,    sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//******************************************************************************//
//                              Wait for Dark                                   //
//                              RobotC on NXT                                   //
//                                                                              //
//  This program allows your taskbot to run forward until it detects a dark     //
//  surface.                                                                    //
//                                                                              //
//******************************************************************************//
//				Focus                                           //
//                                                                              //
//  The robot runs while its light sensor reads values less than the threshold. //
//  The threshold in this case is 45, as soon as a reading is made that is      //
//  equal to or less than 45, the program will leave the while loop, stop       //
//  the motors, and end.                                                        //
//                                                                              //
//******************************************************************************//
//				Notes                                           //
//				                                                //
//  1. The light sensor is attached to the back of the robot                    //
//  2. Be sure to take readings of your light sensor over the light and dark    //
//     areas. Once you have the values, add them and divide by 2 to find your   //
//     threshold. Then, use your threshold as a comparison in your program.     //
//                                                                              //
//******************************************************************************//
//				Motors & Sensors                                //
//                                                                              //
//  [I/O Port]          [Name]          [Type]          [Description]           //
//  Port A              none            Motor           Right Motor             //
//  Port B              none            Motor           Left Motor              //
//  Port 3              lightsensor     Light Sensor    none                    //
//                                                                              //
//******************************************************************************//


task main()
{
   wait1Msec(100);                        //the program waits 100 milliseconds before running further code

   while(SensorValue(lightSensor) > 45)   //a while loop is delcared with the lightsensor value being greater than or equal to 45 as its true condition
   {
      motor[motorD] = 1000;                //motor A is run at a 100 power level
      motor[motorE] = 1000;                //motor B is run at a 100 power level
   }

   motor[motorD] = 0;                     //motor A is stopped with a 0 power level
   motor[motorE] = 0;                     //motor B is stopped with a 0 power level
}
