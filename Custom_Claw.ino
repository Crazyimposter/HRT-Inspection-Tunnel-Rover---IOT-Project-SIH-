#include <Servo.h>

#define servo1 9
#define servo2 8
#define servo3 7
#define servo4 6
#define servo5 5

int Lin1 = 11;
int Lin2 = 12;

int Rin1 = 10;
int Rin2 = 13;

Servo mservo1, mservo2, mservo3, mservo4, mservo5;

int pos = 0;
char Incoming_value = 0;
char usechar = "0";

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
  mservo1.attach(servo1); // 150-50
  mservo2.attach(servo2); // 0-180
  mservo3.attach(servo3); // 40-120
  mservo4.attach(servo4); // 0-35
  mservo5.attach(servo5);

  //default servo position
  mservo1.write(100); //up-down
  mservo2.write(0); //left-right
  mservo3.write(80); //forward-back
  mservo4.write(0); //clamp
  mservo5.write(0); //clamp

  
  pinMode(Lin1, OUTPUT);
  pinMode(Lin2, OUTPUT);

  digitalWrite(Lin1, LOW);
  digitalWrite(Lin2, LOW);
}

int srv1 = 0;
int srv2 = 0;
int srv3 = 0;
int srv4 = 0;
int srv5 = 0;

void loop() 
{

  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();
    Serial.println(Incoming_value);
    usechar = Incoming_value;
    Serial.println(usechar);
  }

  if(usechar=='0')
  {
    digitalWrite(Lin1, LOW);
    digitalWrite(Lin2, LOW);
    digitalWrite(Rin1, LOW);
    digitalWrite(Rin2, LOW);
  }
  
  if(usechar=='A')
  {
    if(srv1<180)
    {
      srv1++;
      mservo1.write(srv1);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
  }
  
  if(usechar=='B')
  {
    if(srv1>10)
    {
      srv1--;
      mservo1.write(srv1);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
  }

  if(usechar=='C')
  {
    if(srv2<180)
    {
      srv2++;
      mservo2.write(srv2);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
  }

  if(usechar=='D')
  {
    if(srv2>0)
    {
      srv2--;
      mservo2.write(srv2);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
  }

  if(usechar=='E')
  {
    if(srv3<180)
    {
      srv3++;
      mservo3.write(srv3);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
   }
   
   if(usechar=='G')
   {
    if(srv3>2)
    {
      srv3--;
      mservo3.write(srv3);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
   }

   //-----

   if(usechar=='F')
  {
    if(srv4<180)
    {
      srv4++;
      mservo4.write(srv4);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
   }
   
   if(usechar=='H')
   {
    if(srv4>0)
    {
      srv4--;
      mservo4.write(srv4);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
   }

   if(usechar=='I')
   {
    if(srv5<180)
    {
      srv5++;
      mservo5.write(srv5);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
   }

   if(usechar=='J')
   {
    if(srv5>0)
    {
      srv5--;
      mservo5.write(srv5);
      if(usechar=='m'){
        return 0;
        }
      
      delay(10);
     }
   }

   if(usechar == 'K'){
   
    digitalWrite(Lin1, HIGH);
    digitalWrite(Rin1, HIGH);
    if(usechar=='0'){
        digitalWrite(Lin1, LOW);
        digitalWrite(Rin1, LOW);
        }
   }

    if(usechar == 'L'){
   
    digitalWrite(Lin2, HIGH);
    digitalWrite(Rin2, HIGH);
    if(usechar=='0'){
        digitalWrite(Lin2, LOW);
        digitalWrite(Rin2, LOW);
        }
   }


   
      
}
