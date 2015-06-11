/////////////////////////////////////
//  DRIVE ROUTINES FOR AUTONOMOUS  //
//  Griffins Robotics - Team 7418  //
//  "Block Party" - 2013-2014      //
/////////////////////////////////////


///////////////////////////////////////////
// ########    ##   ##         #######   //
// ##    ##  ####   ##    ##  ##     ##  //
//     ##      ##   ##    ##  ##     ##  //
//    ##       ##   ##    ##   #######   //
//   ##        ##   ######### ##     ##  //
//   ##        ##         ##  ##     ##  //
//   ##      ######       ##   #######   //
///////////////////////////////////////////





/////////////////////////////////////
//      GLOBAL VARIABLES           //
/////////////////////////////////////


const int COUNTS_PER_INCH           = 1440/21;              // Encoder Counts per Inch //
const int COUNTS_PER_DEGREE         = 12;                   // Encoder Counts per degree of ROBOT rotation //// NOTE:  This is not wheel rotation!!!!       //

const int L_FLIPPER_OPEN_POSITION   = 15;
const int R_FLIPPER_OPEN_POSITION   = 230;

const int L_FLIPPER_CLOSED_POSITION = 150;
const int R_FLIPPER_CLOSED_POSITION = 85;

const int BUCKET_DUMP_POSITION      = 1600;
const int BUCKET_MID_POSITION       = 800;
const int BUCKET_MOTOR_POWER        = 25;

const int FORWARD                   = -1;                   // Specifies the direction for the motors //
const int REVERSE                   = 1;




/////////////////////////////////////
//      Drive Functions            //
/////////////////////////////////////

void driveForward(int power) {
    power = power * FORWARD;

    motor[Left_drive]    = power;                                   // Set Motor Power to //
    motor[Right_drive]	 = power;

}



void driveReverse(int power) {
    power = power * REVERSE;

    motor[Left_drive]    = power;                                   // Set Motor Power //
    motor[Right_drive]	 = power;




}

void driveForwardByTime(int time, int power) {
    power = power * FORWARD;


    motor[Left_drive]    = power;                                   // Set Motor Power //
    motor[Right_drive]	 = power;
    wait1Msec(time);

}

void driveReverseByTime(int time, int power) {
    power = power * REVERSE;


    motor[Left_drive]    = power;                                   // Set Motor Power //
    motor[Right_drive]	 = power;
    wait1Msec(time);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void stopRobot() {

    //////////////////////////////////////////////////////////////
    //  This function takes no arguments.                       //
    //                                                          //
    //  Call this function to set the robot's                   //
    //  motors to power level 0                                 //
    //////////////////////////////////////////////////////////////


	motor[Left_drive] 		= 0;
	motor[Right_drive] 		= 0;


}                                                               // END of stopRobot function //



void rotateClockwise(int degrees, int power) {

    //////////////////////////////////////////////////////////////
    //  This function takes 2 arguments as input:               //
    //                                                          //
    //      degrees     an integer, measured in inches          //
    //                  that specifies how far the robot        //
    //                  should travel                           //
    //                                                          //
    //      power       an integer (0 through +100)             //
    //                  that specifies the desired motor power  //
    //////////////////////////////////////////////////////////////


    ///////////////////////////////
    //  Set up                   //
    ///////////////////////////////

    int counts          = COUNTS_PER_DEGREE * degrees *-1;             // convert degrees to encoder counts //
    int powerLeft       = power * FORWARD;                                // set power for Left Motor //
    int powerRight      = power * REVERSE;                            // set power for Right Motor //


    nMotorEncoder[Left_drive]                   = 0;            // Set Encoder's Initial Position //
    nMotorEncoder[Right_drive]					= 0;
    nMotorEncoderTarget[Left_drive]             = counts;  		// Set Encoder's Target Position //
    //nMotorEncoderTarget[Right_drive]          = counts;
    motor[Left_drive]                           = powerLeft;        // Set Power level of Motors //
    motor[Right_drive]                          = powerRight;



    ///////////////////////////////
    //  Drive Routine            //
    ///////////////////////////////

    while((nMotorRunState[Left_drive] != runStateIdle))         // While Motor is still running:
    {
        // Debugging Output:  Show current encoder count //
		nxtDisplayTextLine(2, "Count: %i",nMotorEncoder[Left_drive]);
		writeDebugStreamLine("Count: %i",nMotorEncoder[Left_drive]);
        // Do not continue.
    }

    motor[Left_drive]       = 0;                                   // Set Motor Power to 0 //
    motor[Right_drive]      = 0;



}                                                               // END rotateClockwise function //




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void rotateCounterclockwise(int degrees, int power) {

    //////////////////////////////////////////////////////////////
    //  This function takes 2 arguments as input:               //
    //                                                          //
    //      degrees     an integer, measured in inches          //
    //                  that specifies how far the robot        //
    //                  should travel                           //
    //                                                          //
    //      power       an integer (0 through +100)             //
    //                  that specifies the desired motor power  //
    //////////////////////////////////////////////////////////////


    ///////////////////////////////
    //  Set up                   //
    ///////////////////////////////

    int counts          = COUNTS_PER_DEGREE * degrees *-1;            // convert degrees to encoder counts //
    int powerLeft       = power * FORWARD;                           // set power for Left Motor //
    int powerRight      = power * REVERSE;                            // set power for Right Motor //


    nMotorEncoder[Left_drive] 					= 0;            // Set Encoder's Initial Position //
	nMotorEncoder[Right_drive]					= 0;
    nMotorEncoderTarget[Left_drive]             = counts;  		// Set Encoder's Target Position //
    //nMotorEncoderTarget[Right_drive]          = counts;
    motor[Left_drive]                           = powerLeft;        // Set Power level of Motors //
    motor[Right_drive]                          = powerRight;



    ///////////////////////////////
    //  Drive Routine            //
    ///////////////////////////////

    while((nMotorRunState[Left_drive] != runStateIdle))         // While Motor is still running:
    {
        // Debugging Output:  Show current encoder count //
		nxtDisplayTextLine(2, "Count: %i",nMotorEncoder[Left_drive]);
		writeDebugStreamLine("Count: %i",nMotorEncoder[Left_drive]);
        // Do not continue.
    }

    motor[Left_drive]    = 0;                                   // Set Motor Power to 0 //
    motor[Right_drive]	 = 0;

}








///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int driveForwardByDistance(int distance, int power) {

    //////////////////////////////////////////////////////////////
    //  This function takes 2 arguments as input:               //
    //                                                          //
    //      distance    an integer, measured in inches          //
    //                  that specifies how far the robot        //
    //                  should travel                           //
    //                                                          //
    //      power       an integer (0 through +100)             //
    //                  that specifies the desired motor power  //
    //                                                          //
    //  This function returns an integer:                       //
    //                                                          //
    //      value of distance traveled (same as input)          //
    //////////////////////////////////////////////////////////////


    ///////////////////////////////
    //  Set up                   //
    ///////////////////////////////

    int counts = COUNTS_PER_INCH * distance;                    // convert distance to encoder counts //
	power = power * FORWARD;
	counts = counts * -1;                                       // Encoder is counting in the NEGATIVE direction //


	nMotorEncoder[Left_drive] 					= 0;            // Set Encoder's Initial Position //
	nMotorEncoder[Right_drive]					= 0;
    nMotorEncoderTarget[Left_drive]             = counts;  		// Set Encoder's Target Position //
  //nMotorEncoderTarget[Right_drive]            = counts;
    motor[Left_drive]                           = power;        // Set Power level of Motors //
    motor[Right_drive]                          = power;



    ///////////////////////////////
    //  Drive Routine            //
    ///////////////////////////////

    while((nMotorRunState[Left_drive] != runStateIdle))         // While Motor is still running:
		{
        // Debugging Output:  Show current encoder count //
		nxtDisplayTextLine(2, "Count: %i",nMotorEncoder[Left_drive]);
		writeDebugStreamLine("Count: %i",nMotorEncoder[Left_drive]);
        // Do not continue.
		}

    motor[Left_drive]    = 0;                                   // Set Motor Power to 0 //
    motor[Right_drive]	 = 0;


    return distance;                                            // returns the distance travelled //
}                                                               // END of driveForward function //




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int driveReverseByDistance(int distance, int power) {

    //////////////////////////////////////////////////////////////
    //  This function takes 2 arguments as input:               //
    //                                                          //
    //      distance    an integer, measured in inches          //
    //                  that specifies how far the robot        //
    //                  should travel                           //
    //                                                          //
    //      power       an integer (0 through +100)             //
    //                  that specifies the desired motor power  //
    //                                                          //
    //  This function returns an integer:                       //
    //                                                          //
    //      value of distance traveled (same as input)          //
    //////////////////////////////////////////////////////////////


    ///////////////////////////////
    //  Set up                   //
    ///////////////////////////////

    int counts = COUNTS_PER_INCH * distance;                    // convert distance to encoder counts //
		counts = counts * -1;
        power = power * REVERSE;                                // Encoder is counting in the NEGATIVE direction //

	nMotorEncoder[Left_drive] 					= 0;            // Set Encoder's Initial Position //
	nMotorEncoder[Right_drive]					= 0;
    nMotorEncoderTarget[Left_drive]             = counts;  		// Set Encoder's Target Position //
  //nMotorEncoderTarget[Right_drive]            = counts;
    motor[Left_drive]                           = power;        // Set Power level of Motors //
    motor[Right_drive]                          = power;



    ///////////////////////////////
    //  Drive Routine            //
    ///////////////////////////////

    while((nMotorRunState[Left_drive] != runStateIdle))         // While Motor is still running:
    {
        // Debugging Output:  Show current encoder count //
		nxtDisplayTextLine(2, "Count: %i",nMotorEncoder[Left_drive]);
		writeDebugStreamLine("Count: %i",nMotorEncoder[Left_drive]);
        // Do not continue.
    }

    motor[Left_drive]    = 0;                                   // Set Motor Power to 0 //
    motor[Right_drive]	 = 0;

    return distance;                                            // returns the distance travelled //

}                                                               // END of driveReverse function //





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool findBeacon(int zone, int power) {
    power = power * -1;

    while (SensorValue[s2] != zone) {
        return FALSE;
    }

    return TRUE;


}                                                              // END of findBeacon function //

void openFlippers() {

    servo[Left_Flipper]     = L_FLIPPER_OPEN_POSITION;
    servo[Right_Flipper]    = R_FLIPPER_OPEN_POSITION;
    wait1Msec(2000);

}

void closeFlippers() {

    servo[Left_Flipper]     = L_FLIPPER_CLOSED_POSITION;
    servo[Right_Flipper]    = R_FLIPPER_CLOSED_POSITION;
    wait1Msec(2000);

}


void dumpBucket() {

    openFlippers();     // open flippers before running dump //

    nMotorEncoderTarget[bucket] = BUCKET_DUMP_POSITION;  // target bucket dumping position
    motor[bucket] = BUCKET_MOTOR_POWER * -1;
    while(nMotorRunState[bucket] != runStateIdle)  // While Motor is still running, allow to go to target posititon
    {
        // Do not continue.
    }
    motor[bucket] = 0;

    // if(SensorValue(touchBucketZero)== 0)
    // {
    nMotorEncoderTarget[bucket] = BUCKET_MID_POSITION;  // target bucket drive position
    motor[bucket] = BUCKET_MOTOR_POWER;
    while(nMotorRunState[bucket] != runStateIdle)  // While Motor is still running, allow to go to target posititon
    {
        // Do not continue.
    }
    motor[bucket] = 0;



}
