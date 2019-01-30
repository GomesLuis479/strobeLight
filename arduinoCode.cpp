int i, t;
char data = 0;  //to store char from serial buffer conected to bluetooth
int outPin = 10;

void changeMode();

void modeUpDown();
void modeStationary();
void modeUp();
void modeDown();

void setup() {
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);
}

void loop() {
  modeUpDown();  //default mode to start
}

void changeMode() {
  data = Serial.read();
  
  switch(data) {
    case 'a':
            modeUpDown();
            break;
    
    case 'b':
            modeUp();
            break;
            
    case 'c':
            modeDown();
            break;
            
    case 'd':
            modeStationary();
            break;
            
    default:
            modeUpDown();
            break;
  }
}

void modeUpDown() {
  
  while(1) {
    for(i = 16; i < 20; i++) {
      for(t = 1; t < 100; t++) {
        
        if(Serial.available() > 0) {
          changeMode();
        }
        
        digitalWrite(outPin, HIGH);
        delay(i);
        digitalWrite(outPin, LOW);
        delay(3);
      }
    }
    
    for(i = 19; i > 20; i--) {
      for(t = 1; t < 100; t++) {
        
        if(Serial.available() > 0) {
          changeMode();
        }
        
        digitalWrite(outPin, HIGH);
        delay(i);
        digitalWrite(outPin, LOW);
        delay(3);
      }
    }
  }  
}

void modeDown() {
  i = 12; ///set i value for down flow
  
  while(1) {
    if(Serial.available() > 0) {
      changeMode();
    }
  
    digitalWrite(outPin, HIGH);
    delay(i);
    digitalWrite(outPin, LOW);
    delay(3);
  }
}

void modeUp() {
  i = 12; ///set i value for up flow
  
  while(1) {
    if(Serial.available() > 0) {
      changeMode();
    }
  
    digitalWrite(outPin, HIGH);
    delay(i);
    digitalWrite(outPin, LOW);
    delay(3);
  }
}

void modeStationary() {
  i = 12; ///set i value for stationary
  
  while(1) {
    if(Serial.available() > 0) {
      changeMode();
    }
  
    digitalWrite(outPin, HIGH);
    delay(i);
    digitalWrite(outPin, LOW);
    delay(3);
  }
}