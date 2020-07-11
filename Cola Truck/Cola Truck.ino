int state = 0;
int flag = 0;    
 
int motor1Pin1 = 4;
int motor1Pin2 = 5;
int motor2Pin1 = 6;
int motor2Pin2 = 7;
int ledFrontLeft = 8;
int ledFrontRight = 10;
int ledBackLeft = 2;
int ledBackRight = 12;
int ground1 = 9;
int ground2 = 11;
int ground3 = 3;
int ground4 = 13;
void setup() 
{
    
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    
    pinMode(ledFrontLeft, OUTPUT);
    pinMode(ground1, OUTPUT);
    
    pinMode(ledFrontRight, OUTPUT);
    pinMode(ground2, OUTPUT);
    
    pinMode(ledBackLeft, OUTPUT);
    pinMode(ground3, OUTPUT);
    
    pinMode(ledBackRight, OUTPUT);
    pinMode(ground4, OUTPUT);
    
    digitalWrite(ground1, LOW);
    digitalWrite(ground2, LOW);
    digitalWrite(ground3, LOW);
    digitalWrite(ground4, LOW);
    Serial.begin(9600);
    
}

void loop() 
{
    if(Serial.available() > 0)
    {     
      state = Serial.read();
      flag = 1;
      if(flag == 1) Serial.println(state);
    }       
    // Forward
    if (state == 'F') 
    {
        Forward();
        digitalWrite(ledFrontLeft, HIGH);
        digitalWrite(ledFrontRight, HIGH);
        digitalWrite(ledBackLeft, LOW);
        digitalWrite(ledBackRight, LOW);
        
       
    }
    // Backward
    else if (state == 'B') 
    {
        Backward();
        digitalWrite(ledFrontLeft, LOW);
        digitalWrite(ledFrontRight, LOW);
        digitalWrite(ledBackLeft, HIGH);
        digitalWrite(ledBackRight, HIGH);
    }
    // Stop
    else if (state == 'S') 
    {
        Stop();
        digitalWrite(ledFrontLeft, LOW);
        digitalWrite(ledFrontRight, LOW);
        digitalWrite(ledBackLeft, LOW);
        digitalWrite(ledBackRight, LOW);
    }
    // Right
    else if (state == 'R') 
    {
        Right();
        digitalWrite(ledFrontLeft, LOW);
        digitalWrite(ledFrontRight, HIGH);
        digitalWrite(ledBackLeft, LOW);
        digitalWrite(ledBackRight, HIGH);
    }
    // Left
    else if (state == 'L') 
    {
        Left();
        digitalWrite(ledFrontLeft, HIGH);
        digitalWrite(ledFrontRight, LOW);
        digitalWrite(ledBackLeft, HIGH);
        digitalWrite(ledBackRight, LOW);
    }
    flag = 0;
}

void Forward()
{
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 1) Serial.println("FORWARD");
        delay(10);
}

void Backward()
{
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 1) Serial.println("BACKWARD");
        delay(10);
}

void Stop()
{
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 1) Serial.println("STOP");
        delay(10);
}

void Left()
{
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 1) Serial.println("LEFT");
        delay(10);
}

void Right()
{
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 1) Serial.println("RIGHT");
        delay(10);
}
