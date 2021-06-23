#define NOTE_C3  131
#define NOTE_D3  147
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262


byte buttonPin[8] = {7, 6, 5, 4, 3, 2, 1, 0};
int previousState[8]= {1}, presentState[8]= {1};


int latchPin = 8;
int clockPin = 12;
int dataPin =11;

int buttonread;
byte buttonPrev = 1, buttonPresent = 1; 
int buttonflag=0;

int currentNote = -1;

byte colDataMatrix[8] = {
  B11111110,
  B11111101,
  B11111011,
  B11110111,
  B11101111,
  B11011111,
  B10111111,
  B01111111
};

byte rowDataMatrix[8] = {
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000
};


byte rowC3[8] = {
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001
};//選圖案 C3

byte rowD3[8] = {
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010
};//選圖案 D3

byte rowE3[8] = {
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100
};//選圖案 E3

byte rowF3[8] = {
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
};//選圖案 F3

byte rowG3[8] = {
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
};//選圖案 G3

byte rowA3[8] = {
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000
};//選圖案 A3

byte rowB3[8] = {
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000
};//選圖案 B3

byte rowC4[8] = {
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000
};//選圖案 C4

byte colC4[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111111
};//選圖案 C4

byte rowX[8] = {
  B00000000,
  B00000000,
  B00111100,
  B00111100,
  B00111100,
  B00111100,
  B00000000,
  B00000000
    
};



 void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  for(int i = 0; i < 9; i++)pinMode(buttonPin[i], INPUT_PULLUP);
}

void loop()
{ 
  
  for(int i=0; i<8; i++){   
    presentState[i] = digitalRead(buttonPin[i]);
  }
  
     
  
  
  //C3
  if(presentState[0] == 0 ){
    currentNote++;
    tone(10, NOTE_C3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[currentNote]);
  shiftOut(dataPin, clockPin, MSBFIRST, rowC3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
      currentNote = -1;
    }
    
     previousState[0]=0;
  }

  
  //D3
  else if(presentState[1] ==0){
    currentNote++;
    tone(10, NOTE_D3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[currentNote]);
  shiftOut(dataPin, clockPin, MSBFIRST, rowD3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
      currentNote = -1;
    }
    previousState[1]=0;
  }
    
  
  //E3
  else if(presentState[2] == 0){
    currentNote++;
    tone(10, NOTE_E3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[currentNote]);
  shiftOut(dataPin, clockPin, MSBFIRST, rowE3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
      currentNote = -1;
    }
    previousState[2]=0;
  }
  
  
  //F3
  else if(presentState[3] == 0){
    currentNote++;
    tone(10, NOTE_F3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[currentNote]);
  shiftOut(dataPin, clockPin, MSBFIRST, rowF3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
      currentNote = -1;
    }
    
    previousState[3]=0;
  }
   
  
  //G3
  else if(presentState[4] == 0){
    currentNote++;
    
    tone(10, NOTE_G3, 500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[currentNote]);
  shiftOut(dataPin, clockPin, MSBFIRST, rowG3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
      currentNote = -1;
    }
    
    previousState[4]=0;
  }
    
  //A3
  else if(presentState[5] == 0){
    currentNote++;
    tone(10, NOTE_A3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[currentNote]);
  shiftOut(dataPin, clockPin, MSBFIRST, rowA3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
      currentNote = -1;
    }
    
    previousState[5]=0;
  }
  
  //B3
  else if(presentState[6] == 0){
    currentNote++;
    tone(10, NOTE_B3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[currentNote]);
  shiftOut(dataPin, clockPin, MSBFIRST, rowB3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
      currentNote = -1;
    }
    
    previousState[6]=0;
   }
  
  //C4
  else if(presentState[7] == 0){
    currentNote++;
    tone(10, NOTE_C4,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[currentNote]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowC4[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
      currentNote = -1;
    }
    
    previousState[7]=0;
  }
  
  
  for(int i=0;i<8;i++){
    if(presentState[i]==1&&previousState[i]==0){
    noTone(10);
      previousState[i]=1;
    }
  }

}
