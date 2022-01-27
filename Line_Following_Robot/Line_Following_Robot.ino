#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define IR_left A0  
#define IR_mid A1
#define IR_right A2 
#define MAX_SPEED 255 //speed tu 0-255
#define RUN_SPEED 100
#define TURN_SPEED 200
#define MIN_SPEED 0
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IR_left, INPUT);
//  pinMode(IR_mid, INPUT);
  pinMode(IR_right, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int left = analogRead(IR_left);
//  int mid = analogRead(IR_mid);
  int right = analogRead(IR_right);
  //int right = digitalRead(IRright);
  //den la 1, trang la 0
  //den la > 500, trang la < 500
  
//  Serial.print("left ");
//  Serial.println(left);
//  Serial.print("mid ");
//  Serial.println(mid);
//  Serial.print("right ");
//  Serial.println(right);

  /*
  if (left == 1 && mid == 1 && right == 1) {forward();}
  if (left == 0 && mid == 0 && right == 0) {Stop();}
  if (left == 0 && mid == 1 && right == 0) {forward();}
  if (left == 0 && mid == 1 && right == 0) {turn_left();}
  if (left == 1 && mid == 0 && right == 0) {turn_left();}
  if (left == 0 && mid == 1 && right == 1) {turn_right();}
  if (left == 0 && mid == 0 && right == 1) {turn_right();}
  */

//turn right
  if(right > 500 && left< 500){
    turn_right();
    delay(20);
  
  }

//turn_left
  if(right < 500 && left > 500){
    turn_left();
  
   delay(20);
  }

if(right > 500 && left > 500){
  forward();

   delay(20);
  
  }

if(right < 500 && left < 500)
{ 
  forward();
   delay(20);
  
  }

  
}//end loop

void banh_trai_tien(int speed) {
  //Đưa tín hiệu digital 0 ra 1 chân, đưa tín hiệu analog ra chân còn lại, chân này là băm xung
  digitalWrite(IN1, LOW);// chân này không có PWM
  analogWrite(IN2, speed);
}
 
void banh_phai_tien(int speed) {
  analogWrite(IN3, speed);
  digitalWrite(IN4, LOW);// chân này không có PWM
}
 
void banh_trai_dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
 
void banh_phai_dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward(){
  banh_trai_tien(RUN_SPEED);
  banh_phai_tien(RUN_SPEED);
}

void turn_left(){
  banh_trai_dung();
  banh_phai_tien(TURN_SPEED);
}

void turn_right(){
  banh_phai_dung();
  banh_trai_tien(TURN_SPEED);
}

void Stop(){
  banh_trai_dung();
  banh_phai_dung();
}
