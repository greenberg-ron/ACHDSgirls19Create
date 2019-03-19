#include <kipr/botball.h>

//analog sensors
#define LIGHT 0
#define LINE 1

//motor ports
#define LEFT 0
#define RIGHT 2
#define FIRE 1

int speed=100;

int followline (int mm){
    int ticks=mm;
    cmpc(RIGHT);
    while(gmpc(RIGHT)<ticks){if (analog(LINE)>1100)
                             {motor(LEFT,.9*speed);motor(RIGHT,speed);}
                             else {motor(LEFT,speed);motor(RIGHT,.9*speed);}}
    ao();return 0;}
int gostraight (int mm){
   int ticks=mm;
   cmpc(RIGHT);
   motor(LEFT,speed);motor(RIGHT,speed);
   while(gmpc(RIGHT)<ticks){msleep(20);}
   ao();return 0;}
int gostraighttoblack (){
   motor(LEFT,speed);motor(RIGHT,speed);
   while(analog(LINE)<2000){msleep(20);}
   ao();return 0;}
int gobackward(int mm){
   int ticks=mm;
   cmpc(RIGHT);
   motor(LEFT,-speed);motor(RIGHT,-speed);
   while(gmpc(RIGHT)>-ticks){msleep(20);}
   ao();return 0;}
int turnleft(){
   cmpc(LEFT);cmpc(RIGHT);
   motor(LEFT,-speed);motor(RIGHT,speed);//set up motors
   while(gmpc(RIGHT)<880){msleep(25);}
   ao();return 0;}
int turnright(){
   cmpc(RIGHT);cmpc(LEFT);
   motor(RIGHT,0);motor(LEFT,speed);
   while(gmpc(LEFT)<2300){msleep(20);}
   ao();return 0;}
int turnfire(int ticks){
   cmpc(FIRE);
   motor(FIRE,speed);
   while(gmpc(FIRE)<ticks){msleep(20);}
   ao();return 0;}
int main(){
  printf("Hello World.\n");
  //wait_for_light(0);/*light sensor in digital port*/
  //shut_down_in(119.5);
    turnfire(400);
    gostraighttoblack();
    msleep(2600);
    turnleft();
    msleep(500);
    gostraight(5700);
    turnright();
    gostraight(3000);
   // turnfire(665);
    turnleft();
    gobackward(2500);
    turnright();
    msleep(1000);
    gobackward(5000);
    turnleft();
    gostraight(50);
    //gobackward(100);
    turnfire(9625);
    gostraight(0);
    gobackward(3000);
    turnright();
    gostraight(1500);
    turnright();
    followline(10000);
    return 0;
}
//make sure ambulance is backwards
//starting mark for left corner: 17.5cm from bottom of black tape  
