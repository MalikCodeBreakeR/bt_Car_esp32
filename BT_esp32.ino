#include <BluetoothSerial.h>

#define in1 5
#define in2 6
#define in3 10
#define in4 11

int Speed1, Speed2;

// Create BluetoothSerial object
BluetoothSerial SerialBT;

void setup() 
{
  // Initialize serial for debugging
  Serial.begin(9600);
  
  // Initialize Bluetooth serial
  SerialBT.begin("ESP32_BT"); // Change "ESP32_BT" to your preferred Bluetooth name
  
  // Set pin modes
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);

  pinMode(A0, OUTPUT);
  pinMode(2, OUTPUT);

  digitalWrite(A0, LOW);
  digitalWrite(2, HIGH);
}

char c;
String str;

void loop() {
  str = "";

  // Check if data is available over Bluetooth
  if (SerialBT.available() > 0) 
  {    
    while (SerialBT.available())
    {
      c = SerialBT.read();
      if (c >= 'A' && c <= 'Z') 
      {
        c += 32; // Convert uppercase to lowercase
      } 
      str += c;
      delay(3);
    }

    // Print the received command for debugging
    Serial.println(str);

    if (c < 12) 
    {
      switch (c)
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

    // Handle movement and lights based on received command
    if (str == "dance") 
    {
      Serial.println("ok");
      for (int i = 0; i < 3; i++) 
      {
        right();
        allLon();
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        delay(500);
        left();
        delay(500);
      }
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      allLof();
    }
    
    // Handle other commands (same as your original code)
    // For example, moving forward, backward, lights, etc.
    if (str == "move forward")
    {
      forward();
    }
    else if (str == "move backward")
    {
      backward();
    }
    else if (str == "stop" || str == "off" || str == "of")
    {
      Stop();
    }
    // Add other conditions for lights, horn, etc. here

  }
}

// Movement functions (same as your original code)
void forward()
{
  digitalWrite(5, LOW);
  analogWrite(6, Speed1);
  analogWrite(10, Speed1);
  digitalWrite(11, LOW);
}

void backward()
{
  digitalWrite(6, LOW);
  analogWrite(5, Speed1);
  analogWrite(11, Speed1);
  digitalWrite(10, LOW);
}

void right()
{
  digitalWrite(6, LOW);
  analogWrite(5, Speed1);
  analogWrite(10, Speed1);
  digitalWrite(11, LOW);
}

void left()
{
  digitalWrite(5, LOW);
  analogWrite(6, Speed1);
  analogWrite(11, Speed1);
  digitalWrite(10, LOW);
}

void Stop()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}

// Light functions (same as your original code)
void frLon()
{
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
}

void frLof()
{
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
}

void flLon()
{
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
}

void flLof()
{
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

// Add the rest of your light functions here (back lights, etc.)
