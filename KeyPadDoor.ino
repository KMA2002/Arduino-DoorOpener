#include <Keypad.h>
#include <Servo.h>




const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
const byte PWM = 9; // Servo Out
const byte servoAn = A0; //Servo
byte n = 0;
const char correctNums[] = {'1','1','1','1'};
char test1;
char test2;
byte check = true;
char passcode[4]; // holds the numbers
int val;
int potpin = 700;
Servo myservo;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  myservo.attach(PWM);
  //pinMode(PWM, OUTPUT);
  //pinMode(servoAn, INPUT);
  for (byte i = 0; i<=3; i++){

    passcode[i] = '%';
  }
}

void loop(){
  char key = keypad.getKey(); // gets input


  if (key != NO_KEY){
    //passcode[0] = key;
    //Serial.print(passcode[3]);
  
    

      if(passcode[n] == '%'){

        passcode[n] = key;

      }

      else{
      }
      
      n++;
    
  

  if(passcode[3] != '%'){//restes pin after 4 inputs

    for(byte b = 0; b<=3; b++){// loops through passcode after 4 inputa
      
      test1 = passcode[b];// asign each index of arrays to test, one by one and compare
      test2= correctNums[b];

          if(test1 != test2){ // false if one number is not right

            check = false;
            //Serial.println(" wrong code ")
            //b=4;
            
            }

          else{

           
          }

      }

    
  

    for (byte q = 0; q<=3; q++){//resets inputs

      passcode[q] = '%';

    }
  
  

    if(check == true){

      motorOpen();
      Serial.println(" True ");
      

    }

    else{

      Serial.print(" Wrong ");

    }
    n=0;
    check = true;
  }
  for (byte w = 0; w<=3; w++){// test 

   Serial.println(passcode[w]);
  }
  }
}

void motorOpen(){// call for motor sequence 
     
      // create servo object to control a servo
    // twelve servo objects can be created on most boards
    
   int pos;    // variable to store the servo position
    
    
    
    
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      delay(2000);
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
                          // waits for the servo to get there
}



 
