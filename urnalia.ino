#define leftCenterSensor A2
#define leftNearSensor A1
#define leftFarSensor A0
#define rightCenterSensor A3
#define rightNearSensor A4
#define rightFarSensor A5
#define leftMotor1  4
#define leftMotor2  6
#define rightMotor1 5
#define rightMotor2 8
#define led 13
int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;
int rightFarReading;
void setup() {
  pinMode(leftCenterSensor, INPUT);
  pinMode(leftNearSensor, INPUT);
  pinMode(leftFarSensor, INPUT);
  pinMode(rightCenterSensor, INPUT);
  pinMode(rightNearSensor, INPUT);
  pinMode(rightFarSensor, INPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  x:
  int leftCenterReading  = analogRead(leftCenterSensor);
  //Serial.println(leftCenterReading );
  //delay(100);
  int leftNearReading    = analogRead(leftNearSensor);
  //Serial.println(leftNearReading);
  //delay(100);
  int leftFarReading     = analogRead(leftFarSensor);
 //Serial.println(leftFarReading);
 //delay(100);
  int rightCenterReading = analogRead(rightCenterSensor);
  //Serial.println(rightCenterReading);
 //delay(100);
  int rightNearReading   = analogRead(rightNearSensor);
  //Serial.println(rightNearReading);
  //delay(100);
  int rightFarReading    =analogRead(rightFarSensor);
  //Serial.println(rightFarReading);
 //delay(100);
  
    
   if(leftFarReading<680 && rightFarReading<600 && leftCenterReading>690 && rightCenterReading>650)
    {   digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);//straight
    digitalWrite(rightMotor2, LOW);
    delay(500);
    goto x;
    }
  if(leftFarReading<680 && leftCenterReading>650 && rightCenterReading>620 
   && rightFarReading>600 && leftNearReading<610 && rightNearReading<600)
    { 
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);//turn right
    digitalWrite(rightMotor2, LOW);
    delay(500);
    goto x;  
    }
    if(leftFarReading<680 && leftCenterReading>650 && rightCenterReading>620 
   && rightFarReading>600 && leftNearReading<610 && rightNearReading>600)
    { 
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);//turn right
    digitalWrite(rightMotor2, LOW);
    delay(500);
    goto x;  
    }
    if(leftFarReading>680 && leftCenterReading>650 && rightCenterReading>620 
    && rightFarReading<600 && leftNearReading<610 &&rightNearReading<600)
    {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);//turn left
    digitalWrite(rightMotor2, LOW);
    delay(500);
    goto x;
    }
     if(leftFarReading<680 && leftCenterReading>650 && rightCenterReading>620 
    && rightFarReading<600 && leftNearReading>610 &&rightNearReading<600)
    {
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);//turn left
    digitalWrite(rightMotor2, LOW);
    delay(500);
    goto x;
    }
    
    if(leftFarReading<680 && leftCenterReading<650 && rightCenterReading<620 
    && rightFarReading<600 && leftNearReading<610 && rightNearReading<600)
    { 
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, HIGH);//turn around
      digitalWrite(rightMotor2, LOW);
      delay(500);
      goto x;        
    }
    
    if(leftFarReading>680 && leftCenterReading>650 && rightCenterReading>620
    && rightFarReading>600 && leftNearReading>610 && rightNearReading>600)
    {
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1,LOW);
    digitalWrite(rightMotor2,LOW);//stop
    }
}

