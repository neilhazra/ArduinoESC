// Hall C
int dir1PinC = 12;
int dir2PinC = 13;
int speedPinC = 11; // Needs to be a PWM pin to be able to control motor speed

// Hall B
int dir1PinB = 7;
int dir2PinB =8;
int speedPinB = 9; // Needs to be a PWM pin to be able to control motor speed
int newTiming = 0;
//Hall A
int dir1PinA = 2;
int dir2PinA =4;
int speedPinA = 3; // Needs to be a PWM pin to be able to control motor speed
unsigned long startingMillis;
int timing = 5360;
int backEMF;
int prevX = 0;
void setup() {  // Setup runs once per reset
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
  startingMillis = millis(); 
  accl(8000,1015,1); 
}

void loop() {
   fwdSpin();   
}  
  
void accl(int currentTiming,int desiredTiming,int mode)  {
    int prevMillis = millis();
    int duration = currentTiming - desiredTiming;
   
     while(millis()-prevMillis < duration)  {
        timing = currentTiming - ((millis()-prevMillis));
        if(mode = 1)  {
          fwdSpin(); 
        }
        else if(mode = 2)  {
          revSpin(); 
        }
        else if(mode = 3)  {
          fwdPowerSpin(); 
        }
        else if(mode = 4)  {
          revPowerSpin(); 
        }
        else if(mode = 5)  {
           fwdIntermediateSpin(); 
        }
        else if(mode = 6)  {
           revIntermediateSpin(); 
        }
     }
}
  
void dccl(int currentTiming,int desiredTiming, int mode)  {
    int prevMillis = millis();
    int duration = abs(currentTiming - desiredTiming);
   
     while(millis()-prevMillis < duration)  {
        timing = currentTiming + ((millis()-prevMillis));
        if(mode = 1)  {
          fwdSpin(); 
        }
        else if(mode = 2)  {
          revSpin(); 
        }
        else if(mode = 3)  {
          fwdPowerSpin(); 
        }
        else if(mode = 4)  {
           revPowerSpin(); 
        }
        else if(mode = 5)  {
           fwdIntermediateSpin(); 
        }
        else if(mode = 6)  {
           revIntermediateSpin(); 
        }
     }
}
    







void revSpin()  {
  hallBHigh();///////////B+A-
  hallALow();
  hallCOff();
  delayMicroseconds(timing);    
  hallBHigh();////////////B+C-
  hallCLow();
  hallAOff();
  //backEMF = analogRead(A0);
  delayMicroseconds(timing);  
  hallAHigh();////////////A+C-
  hallCLow();
  hallBOff();
  delayMicroseconds(timing);  
  hallAHigh();///////////////A+B- 
  hallBLow();
  hallCOff();
  delayMicroseconds(timing);
  hallAOff();///////////C+B-
  hallCHigh();
  hallBLow();
  //backEMF = analogRead(A0);
  delayMicroseconds(timing);
  hallALow();/////////////C+A-
  hallCHigh();
  hallBOff();
  delayMicroseconds(timing);
} 

void fwdSpin()  {
  hallALow();/////////////C+A-
  hallCHigh();
  hallBOff();
  delayMicroseconds(timing);
  hallAOff();///////////C+B-
  hallCHigh();
  hallBLow();
  delayMicroseconds(timing);
  hallAHigh();///////////////A+B- 
  hallBLow();
  hallCOff();
  delayMicroseconds(timing);
  hallAHigh();////////////A+C-
  hallCLow();
  hallBOff();
  delayMicroseconds(timing);
  hallBHigh();////////////B+C-
  hallCLow();
  hallAOff();
  delayMicroseconds(timing);
  hallBHigh();///////////B+A-
  hallALow();
  hallCOff();
  delayMicroseconds(timing);  
}

void fwdPowerSpin()  {
  hallALow();///////////////B+C+A- 
  hallBHigh();
  hallCHigh();
  delayMicroseconds(timing);
  hallALow();////////////C+A-B-
  hallCHigh();
  hallBLow();
  delayMicroseconds(timing);
  hallBLow();/////////////A+C+B-
  hallCHigh();
  hallAHigh();
  delayMicroseconds(timing);
  hallBLow();///////////A+B-C-
  hallAHigh();
  hallCLow();
  delayMicroseconds(timing);
  hallAHigh();/////////////A+B+C-
  hallCLow();
  hallBHigh();
  delayMicroseconds(timing);
  hallALow();///////////B+C+A-
  hallCHigh();
  hallBHigh();
  delayMicroseconds(timing);
}


void revPowerSpin(){
  hallALow();///////////B+C+A-
  hallCHigh();
  hallBHigh();
  delayMicroseconds(timing);
  hallAHigh();/////////////A+B+C-
  hallCLow();
  hallBHigh();
  delayMicroseconds(timing);
  hallBLow();///////////A+B-C-
  hallAHigh();
  hallCLow();
  delayMicroseconds(timing); 
  hallBLow();/////////////A+C+B-
  hallCHigh();
  hallAHigh();
  delayMicroseconds(timing);
  hallALow();////////////C+A-B-
  hallCHigh();
  hallBLow();
  delayMicroseconds(timing);
  hallALow();///////////////B+C+A- 
  hallBHigh();
  hallCHigh();
  delayMicroseconds(timing);
}


void fwdIntermediateSpin()  {
  hallALow();///////////////B+C+A- 
  hallBHigh();
  hallCHigh();
  delayMicroseconds(timing);
  hallALow();/////////////C+A-
  hallCHigh();
  hallBOff();
 delayMicroseconds(timing);
  hallALow();////////////C+A-B-
  hallCHigh();
  hallBLow();
  delayMicroseconds(timing);
  hallAOff();///////////C+B-
  hallCHigh();
  hallBLow();
  delayMicroseconds(timing);
  hallBLow();/////////////A+C+B-
  hallCHigh();
  hallAHigh();
  delayMicroseconds(timing);
  hallAHigh();///////////////A+B- 
  hallBLow();
  hallCOff();
  delayMicroseconds(timing);
  hallBLow();///////////A+B-C-
  hallAHigh();
  hallCLow();
  delayMicroseconds(timing);
  hallAHigh();////////////A+C-
  hallCLow();
  hallBOff();
  delayMicroseconds(timing);
  hallAHigh();/////////////A+B+C-
  hallCLow();
  hallBHigh();
  delayMicroseconds(timing);
  hallBHigh();////////////B+C-
  hallCLow();
  hallAOff();
  delayMicroseconds(timing);
  hallALow();///////////B+C+A-
  hallCHigh();
  hallBHigh();
  delayMicroseconds(timing);
  hallBHigh();///////////B+A-
  hallALow();
  hallCOff();
 delayMicroseconds(timing);
}


void revIntermediateSpin()  {
  hallBHigh();///////////B+A-
  hallALow();
  hallCOff();
  delayMicroseconds(timing);
  hallALow();///////////B+C+A-
  hallCHigh();
  hallBHigh();
  delayMicroseconds(timing); 
  hallBHigh();////////////B+C-
  hallCLow();
  hallAOff();
  delayMicroseconds(timing);
  hallAHigh();/////////////A+B+C-
  hallCLow();
  hallBHigh();
  delayMicroseconds(timing);
  hallAHigh();////////////A+C-
  hallCLow();
  hallBOff();
  delayMicroseconds(timing);
  hallBLow();///////////A+B-C-
  hallAHigh();
  hallCLow();
  delayMicroseconds(timing);
  hallAHigh();///////////////A+B- 
  hallBLow();
  hallCOff();
  delayMicroseconds(timing);
  hallBLow();/////////////A+C+B-
  hallCHigh();
  hallAHigh();
  delayMicroseconds(timing);
  hallAOff();///////////C+B-
  hallCHigh();
  hallBLow();
  delayMicroseconds(timing);
  hallALow();////////////C+A-B-
  hallCHigh();
  hallBLow();
  delayMicroseconds(timing);
  hallALow();/////////////C+A-
  hallCHigh();
  hallBOff();
  delayMicroseconds(timing);
  hallALow();///////////////B+C+A- 
  hallBHigh();
  hallCHigh();
  delayMicroseconds(timing);
}

void hallAHigh()  {
  analogWrite(speedPinA, 255);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);  
}

void hallBHigh()  {
  analogWrite(speedPinB, 255);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);  
  
}

void hallCHigh()  {
  analogWrite(speedPinC, 255);
  digitalWrite(dir1PinC, LOW);
  digitalWrite(dir2PinC, HIGH);  
}


void hallALow()  {
  analogWrite(speedPinA, 255);
  digitalWrite(dir2PinA, LOW);
  digitalWrite(dir1PinA, HIGH); 
}

void hallBLow()  {
  analogWrite(speedPinB, 255); 
  digitalWrite(dir2PinB, LOW);
  digitalWrite(dir1PinB, HIGH);  
}

void hallCLow()  {
    analogWrite(speedPinC, 255);
  digitalWrite(dir2PinC, LOW);
  digitalWrite(dir1PinC, HIGH);
}


void hallAOff()  {
  analogWrite(speedPinA, 0);
 
}

void hallBOff()  {
  analogWrite(speedPinB, 0); 
 
}

void hallCOff()  {
  analogWrite(speedPinC, 0);

}

void allOff()  {
   hallAOff();
   hallBOff();
   hallCOff();
  
}








