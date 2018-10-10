//pins for Motor H-Bridge
int motor1In2=2;
int motor1In1=4;
int motor1Enable=6;

int motor2In1=13;
int motor2In2=12;
int motor2Enable=11;

//pins for Light sensors
int frontLeft=A0;
int frontRight=A1;
int backLeft=A2;
int backRight=A3;
//pin for distance
int distancePin=A4;

//variable for readings of  sensors
float light[4];
int baselineLight[4];
int isReading;
bool isDark;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor2In2,OUTPUT);
  pinMode(motor2In1,OUTPUT);
  pinMode(motor1In1,OUTPUT);
  pinMode(motor1In2,OUTPUT);

  Serial.begin(9600);
  setBaseLine();
  
}



void loop() {
  // put your main code here, to run repeatedly:
  readLightSensors();
  readDistance();
  checkCollision();
  if(!isReading)
  {
    checkDarkness();
    findRotation();
    
    //setSound();
  }
    
  delay(10);
  //turnTowards(225,0);
  //delay(500);
  
  /*turnTowards(0);
  delay(500);
  turnTowards(255,315);
  delay(500);
  turnToards(255,0);*/
  //circle();
  
}

void circle()
{
  turnTowards(90,0);
  delay(2000);
  turnTowards(100,0);
  delay(1000);
}



