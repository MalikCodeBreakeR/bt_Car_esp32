#define in1 5 
#define in2 6
#define in3 9
#define in4 10

int Speed1,Speed2;

void setup() 
{
  //motors
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  //buzzer
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  //Front right LED
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  
  //Front left LED
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

  //Back right LED
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);

  //Back left LED
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  pinMode(A0,OUTPUT);
  pinMode(2,OUTPUT);

  //Upper light for arduino indicator (working or not)
  digitalWrite(A0,LOW);
  digitalWrite(2,HIGH);
  
  Serial.begin(9600); //Baud rate serial monitering...
}

char c; //For switch case for speed
String str;
void loop() {
  str = "";
  if(Serial.available()>0)
  {    
    while(Serial.available())
    {
      c = Serial.read();
      if(c >='A' && c<='Z')
      {
        c +=32;
      } 
      str += c;
      delay(3);
    }
    Serial.println(str);
    if(c<12)
    {
      switch(c)
      {
        case 0:
          Speed1 = 0;
          Speed2 = 0;
          break;
        case 1:
          Speed1 = 25;
          Speed2 = 5;
          break;
        case 2:
          Speed1 = 50;
          Speed2 = 20;
          break;
        case 3:
          Speed1 = 75;
          Speed2 = 30;
          break;
        case 4:
          Speed1 = 100;
          Speed2 = 40;
          break;
        case 5:
          Speed1 = 125;
          Speed2 = 50;
          break;
        case 6:
          Speed1 = 150;
          Speed2 = 60;
          break;
        case 7:
          Speed1 = 175;
          Speed2 = 70;
          break;
        case 8:
          Speed1 = 200;
          Speed2 = 80;
          break;
        case 9:
          Speed1 = 225;
          Speed2 = 85;
          break;
        case 10:
          Speed1 = 240;
          Speed2 = 90;
          break;
        case 11:
          Speed1 = 255;
          Speed2 = 95;
          break;
      }
    }
      
    //dance 
    if(str == "dance")
    {
      Serial.println("ok");
      for(int i=0; i<3; i++)
      {
        right();
        allLon();
        digitalWrite(12,LOW);
        digitalWrite(13,HIGH);
        delay(500);
        left();
        delay(500);
      }
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      allLof();
      
    }
    
    if(str == "move forward")
    {
      forward();
    }
    else if(str == "fr")
    {
      forwardRight();
    }
    else if(str == "fl")
    {
      forwardLeft();
    }
    
    else if(str == "move backward")
    {
      backward();
    }
    else if(str == "br")
    {
      backwardRight();
    }
    else if(str == "bl")
    {
      backwardLeft();
    }
    
    else if(str == "move right")
    {
      right();
    }
        
    else if(str == "move left")
    {
      left();
    }
    
    else if(str == "stop" || str == "off" || str == "of")
    {
      Stop();
    }
    else
    {
      Stop();
    }

    //horn
    if(str == "horn on")
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW); 
    }
    else if(str == "horn off" || str == "horn of")
    {
      digitalWrite(13,LOW);
      digitalWrite(12,LOW); 
    }
    
    //lights
    if(str == "lights on" || str == "all lights on" || str == "all light on")
    {
      allLon(); 
    }
    else if(str == "lights off" || str == "lights of" || str == "all lights of")
    {
      allLof(); 
    }

    ///front light
    else if(str == "front lights on" || str == "front light on")
    {
      frLon();
      flLon();
      brLof();
      blLof(); 
    }
    else if(str == "front lights off" || str == "front lights of" || str == "front light off" || str == "front light of" || str == "frontlights off" || str == "frontlights of" || str == "frontlight off" || str == "frontlight of")
    {
      frLof();
      flLof();
    }

    //back light
    else if(str == "back lights on" || str == "back light on" || str == "backlights on" || str == "backlight on")
    {
      brLon();
      blLon();
      frLof();
      flLof();
    }
    else if(str == "back lights off" || str == "back lights of" || str == "back light off" || str == "back light of" || str == "backlights off" || str == "backlights of" || str == "backlight off" || str == "backlight of")
    {
      brLof();
      blLof();
    }

    //right
    else if(str == "right lights on" || str == "right light on" || str == "right indicator on")
    {
      frLon();
      brLon();
      flLof();
      blLof();
    }
    else if(str == "right lights off" || str == "right lights of" || str == "right light off" || str == "right light of" || str == "right indicator of" || str == "right indicator off" )
    {
      frLof();
      brLof();
    }

    //left
    else if(str == "left lights on" || str == "left light on" || str == "left idicator on")
    {
      flLon();
      blLon();
      frLof();
      brLof();
    }
    else if(str == "left lights off" || str == "left lights of" || str == "left light off" || str == "left light of" || str == "left indicator of" || str == "left indicator off" )
    {
      flLof();
      blLof();
    }

    //right front_back
    else if(str == "right front lights on" || str == "right front light on" || str == "right front indicator on")
    {
      frLon();
      flLof();
      brLof();
      blLof();
    }
    else if(str == "right front lights off" || str == "right front lights of" || str == "right front light off" || str == "right front light of" || str == "right front indicator off" || str == "right front indicator of" )
    {
       frLof();
    }

    else if(str == "right back lights on" || str == "right back light on"  || str == "right back indicator on")
    {
      brLon(); 
      flLof();
      frLof();
      blLof();
    }
    else if(str == "right back lights off" || str == "right back lights of" || str == "right back light off" || str == "right back light of" || str == "right back indicator off" || str == "right back indicator of")
    {
      brLof();
    }

    //left front_back
    else if(str == "left front lights on" || str == "left front light on" || str == "left front indicator on")
    {
      flLon();
      frLof();
      brLof();
      blLof(); 
    }
    else if(str == "left front lights off" || str == "left front lights of" || str == "left front light off" || str == "left front light of" || str == "left front indicator off" || str == "left front indicator of")
    {
      flLof(); 
    }

    else if(str == "left back lights on" || str == "left back light on"  || str == "left back indicator on")
    {
      blLon();
      flLof();
      brLof();
      frLof();
    }
    else if(str == "left back lights off" || str == "left back lights of" || str == "left back light off" || str == "left back light of" || str == "left back indicator off" || str == "left back indicator of")
    {
      blLof(); 
    }

    //all off
    else if(str == "all off" || str == "off" || str == "of" || str == "all of")
    {
      allLof(); 
    }
  }
}

void forward()
{
  digitalWrite(in1,LOW);
  analogWrite(in2,Speed1);
  analogWrite(in3,Speed1);
  digitalWrite(in4,LOW);
}
void forwardRight()
{
  digitalWrite(in1,LOW);
  analogWrite(in2,Speed2);
  analogWrite(in3,Speed1);
  digitalWrite(in4,LOW);
}
void forwardLeft()
{
  digitalWrite(in1,LOW);
  analogWrite(in2,Speed1);
  analogWrite(in3,Speed2);
  digitalWrite(in4,LOW);
}

void backward()
{
  digitalWrite(in2,LOW);
  analogWrite(in1,Speed1);
  analogWrite(in4,Speed1);
  digitalWrite(in3,LOW);
}
void backwardRight()
{
  digitalWrite(in2,LOW);
  analogWrite(in1,Speed2);
  analogWrite(in4,Speed1);
  digitalWrite(in3,LOW);
}
void backwardLeft()
{
  digitalWrite(in2,LOW);
  analogWrite(in1,Speed1);
  analogWrite(in4,Speed2);
  digitalWrite(in3,LOW);
}

void right()
{
  digitalWrite(in2,LOW);
  analogWrite(in1,Speed1);
  analogWrite(in3,Speed1);
  digitalWrite(in4,LOW);
}

void left()
{
  digitalWrite(in1,LOW);
  analogWrite(in2,Speed1);
  analogWrite(in4,Speed1);
  digitalWrite(in3,LOW);
}

void Stop()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in3,LOW);
}

//lights
void frLon()
{
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH);
}
void frLof()
{
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
}

void flLon()
{
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
}
void flLof()
{
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
}

//backLight
void brLon()
{
  digitalWrite(A3,LOW);
  digitalWrite(A4,HIGH);
}
void brLof()
{
  digitalWrite(A3,LOW);
  digitalWrite(A4,LOW);
}

void blLon()
{
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}
void blLof()
{
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}

//all lights on off

void allLon()
{
  flLon();
  frLon();
  blLon();
  brLon();
}

void allLof()
{
  flLof();
  frLof();
  blLof();
  brLof();
}
