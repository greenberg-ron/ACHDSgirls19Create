#include <kipr/botball.h>
//analog sensors
#define LIGHT 0
#define FLOOR 5
// servo ports
#define ELECTRIC 0
#define GRABBER 2

int speed=100;// max is 500
int turnleft(){
    set_create_total_angle(0);
  	create_drive_direct (-speed,speed); // left@0, right@speed
  	while (get_create_total_angle()<33){msleep(35);}
  	create_stop(); return 0;}
int turnright(){
  	set_create_total_angle(0);
  	create_drive_direct (speed,-speed); // right@0, left@speed
  	while (get_create_total_angle()>-33){msleep(35);}
  	create_stop(); return 0;}
int gobackward(int cm){
  	set_create_distance(0);
  	create_drive_direct(-speed,-speed); // left@0, right@speed
  	while (get_create_distance()<cm){msleep(35);}
  	create_stop(); return 0;}
int goforward(int cm){
  	set_create_distance(0);
  	create_drive_direct(speed,speed); // left@0, right@speed
  	while (get_create_distance()>-cm){msleep(35);}
  	create_stop(); return 0;}
int forwardtobump(){
    create_drive_direct(speed,speed);
    while (get_create_lbump()==0 && get_create_rbump()==0){msleep(35);}
    create_stop(); gobackward(2); return 0;}
int backwardtotape(){
    create_drive_direct(-speed,-speed);
    while (analog(FLOOR)<2000){msleep(35);}
    create_stop(); return 0;}
int forwardtotape(){
    create_drive_direct(speed,speed);
    while (analog(FLOOR)<2000){msleep(35);}
    create_stop(); return 0;}
int stringerup() {set_servo_position(ELECTRIC,375); return 0;}
int stringerdown() {set_servo_position(ELECTRIC,1830); return 0;}
int grabberup(){set_servo_position(GRABBER,112); return 0;} // This procedure and the next two need to be filled in     
int grabbermiddle(){set_servo_position(GRABBER,1300); return 0;}//  112 is up, 1160is middle, and down is 1500
int grabberdown(){set_servo_position(GRABBER,1575); return 0;}
int main() {
  	printf("Hello World.\n");
    enable_servos();
    grabberup();
    stringerdown();
   	create_connect();
  	printf("Create connected.\n");
  	// wait_for_light(0);
  	// shut_down_in(119.5); /*seconds
    backwardtotape(); gobackward(16); turnleft(); forwardtobump(); turnright(); backwardtotape();//get in position for 1st electric
    stringerup(); goforward(26); gobackward(2); stringerdown(); gobackward(38);//do 1st elec & get in position for 2nd 
    stringerup(); gobackward(28); goforward(4); stringerdown();// do 2nd electric 
    forwardtotape(); turnright(); goforward(44); stringerup(); msleep(1000);//prepare for grabbing
    grabbermiddle(); turnleft();  gobackward(30); grabberdown();msleep(1000); goforward(30);turnleft(7);gobackward(34);turnright(6);
    msleep(2000);
  	create_disconnect();
  	return 0;}