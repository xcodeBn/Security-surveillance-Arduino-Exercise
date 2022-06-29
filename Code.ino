int msensor = 13;
int val = 0 ;
int state = LOW;
int red = 9;
int green = 10;
int blue = 11;
int wait = 30000;
int count=0;
//a6
//b7f13g12c4d2e1
//RGB 0-255 
int a = 8; //For displaying segment "a“
int b = 7; //For displaying segment "b" 
int c = 4; //For displaying segment "c" 
int d = 5; //For displaying segment "d" 
int e = 6; //For displaying segment "e" 
int f = 2; //For displaying segment "f“
 int g = 12; //For displaying segment "g“


void setup() {
  // put your setup code here, to run once:
  pinMode(msensor,INPUT);
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(a, OUTPUT); //A 
pinMode(b, OUTPUT); //B 
pinMode(c, OUTPUT); //C 
pinMode(d, OUTPUT); //D 
pinMode(e, OUTPUT); //E 
pinMode(f, OUTPUT); //F 
pinMode(g, OUTPUT); //G

displayDigit(count);

}

void loop() {
  
  val = digitalRead(msensor);
  
   if (val == HIGH) {           // check if the sensor is HIGH
     
    Serial.println("Added One");
    count ++;
    if(count>9){
    count = 0 ;
    Serial.println("Count>9,restarting count");
  }
    check(count);
    turnOff();
    displayDigit(count);  
    Serial.println(count);             

    if (state == LOW) {
      Serial.println("Motion detected!");
      
      state = HIGH;       // update variable state to HIGH
    }
    delay(wait); // delay 30 seconds
  }
  else {
    Serial.println("No Motion");
    if (state==HIGH){
      Serial.println("Motion stopped!");
      state==LOW;
    }
  }
 



}

void RGB(int r , int g , int b){
  digitalWrite(9, r);
  digitalWrite(10, g);
  digitalWrite(11, b);
}
void displayDigit(int digit) { 
//Conditions for displaying segment a 
if(digit!=1 && digit != 4) 
  digitalWrite(a,HIGH); 
//Conditions for displaying segment b 
if(digit != 5 && digit != 6) 
  digitalWrite(b,HIGH); 
//Conditions for displaying segment c
 if(digit !=2) 
  digitalWrite(c,HIGH); 
//Conditions for displaying segment d 
if(digit != 1 && digit !=4 && digit !=7) 
  digitalWrite(d,HIGH); 
//Conditions for displaying segment e 
if(digit == 2 || digit ==6 || digit == 8 || digit==0) 
  digitalWrite(e,HIGH); 
//Conditions for displaying segment f 
if(digit != 1 && digit !=2 && digit!=3 && digit !=7) 
  digitalWrite(f,HIGH); 
if (digit!=0 && digit!=1 && digit !=7) 
  digitalWrite(g,HIGH); 
} 
void turnOff(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  
}
void check(int val){
  if(val<4){
    RGB(0,255,0);
  }
  else if(val>=4 && val<8){
    RGB(255,255,255);
  }
  else if(val>8){
    RGB(255,0,0);
  }
   
}
