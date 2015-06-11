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
const int COUNTS_PER_DEGREE         = 12;                   // Encoder Counts per degree of ROBOT rotation //
                                                            // NOTE:  This is not wheel rotation!!!!       //




/////////////////////////////////////
//      Drive Functions            //
/////////////////////////////////////



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

    int counts          = COUNTS_PER_INCH * degrees;             // convert degrees to encoder counts //
    int powerLeft       = power;                                 // set power for Left Motor //
    int powerRight      = -1 * power;                            // set power for Right Motor //
    
    
    nMotorEncoder[Left_drive] 					= 0;            // Set Encoder's Initial Position //
	nMotorEncoder[Right_drive]					= 0;
    nMotorEncoderTarget[Left_drive]             = counts;  		// Set Encoder's Target Position //
    //nMotorEncoderTarget[Right_drive]          = counts;
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
    


}                                                               // END rotateClockwise function //




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void rotateCounterclockwise(int degrees) {


}








///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void driveForward(int distance, int power) {

    //////////////////////////////////////////////////////////////
    //  This function takes 2 arguments as input:               //
    //                                                          //
    //      distance    an integer, measured in inches          //
    //                  that specifies how far the robot        //
    //                  should travel                           //
    //                                                          //
    //      power       an integer (0 through +100)             //
    //                  that specifies the desired motor power  //
    //////////////////////////////////////////////////////////////


    ///////////////////////////////
    //  Set up                   //
    ///////////////////////////////

    int counts = COUNTS_PER_INCH * distance;                    // convert distance to encoder counts //
	power = power * -1;
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

}                                                               // END of driveForward function //




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void driveReverse(int distance, int power) {

    //////////////////////////////////////////////////////////////
    //  This function takes 2 arguments as input:               //
    //                                                          //
    //      distance    an integer, measured in inches          //
    //                  that specifies how far the robot        //
    //                  should travel                           //
    //                                                          //
    //      power       an integer (0 through +100)             //
    //                  that specifies the desired motor power  //
    //////////////////////////////////////////////////////////////


    ///////////////////////////////
    //  Set up                   //
    ///////////////////////////////

    int counts = COUNTS_PER_INCH * distance;                    // convert distance to encoder counts //
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

}                                                               // END of driveReverse function //



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



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool findBeacon() {


//    while (beacon not found) {
        // run beacon search routine

//        return FALSE;
//    }
//    return true;


}                                                                   // END of findBeacon function //
