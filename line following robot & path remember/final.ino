#include <Servo.h>


Servo L,R;
int strt=0, f=0, arr[500];
int mn=0,mx=0,mid=0;

void setup() {
  L.attach(9);
  R.attach(8);

  Serial.begin(9600);

  for(int i=0; i<5000; i++){
    int val = 0;
      for(int j=2; j<=5; j++)//Calibrating the sensor, finding max and 
      {                      //min reflectance values.
        val = analogRead(j);
        if(val >= mx)
        mx = val;
        if(val <= mn)
        mn = val;
      }
      delay(1);
    }
    
  mid = ((mx + mn)/2);

  R.write(91);
  L.write(91);

  pinMode(12,INPUT); // Switch
}
//****************************************//

void loop() {
  
  int s0=0,s1=0,s2=0,s3=0;
  s0 = analogRead(2);
  s1 = analogRead(3);
  s2 = analogRead(4);
  s3 = analogRead(5);

  Serial.print(s0); Serial.print(" , "); Serial.print(s1); Serial.print(" , "); Serial.print(s2); Serial.print(" , "); Serial.print(s3); Serial.print("\n");

  int RAvg = (s0+s1)/2, LAvg = (s2+s3)/2;

  int bttn = digitalRead(12);
  
  if(bttn == 0 && f == 0){
    //L.write(105); R.write(65);
    L.write(160); R.write(20); arr[strt]=1; strt++;
  
    if( LAvg-240 > RAvg ){
        L.write(91); R.write(20);    Serial.println("Left");  arr[strt]=2; strt++;
        delay(30);
      }
     
     if( RAvg > LAvg+240 ){
        L.write(160); R.write(91);  Serial.println("Right"); arr[strt]=3; strt++;
        delay(30);
      }
      
      if(s0<mid && s1<mid && s2<mid && s3<mid){
        L.write(91); R.write(91);   Serial.println("Stop");
      }  
  }

  if(bttn == 0 && f == 1){
      for(int i=0; i<strt; i++){
        if( arr[i] == 1 ){
            L.write(160); R.write(20);    Serial.println("Front");
            //delay(30);
        }
        if( arr[i] == 2 ){
            L.write(91); R.write(20);    Serial.println("Left");
            delay(30);
        }
        if(arr[i] == 3 ){
            L.write(160); R.write(91);  Serial.println("Right");
            delay(30);
        }
      }
      L.write(91); R.write(91);
      delay(5000);
  }
  
  if(bttn == 1){
    if(f == 0){
      f = 1;
    }
    L.write(91); R.write(91);
  }
}
