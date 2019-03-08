#include <kipr/botball.h>

//analog sensors
#define LIGHT 0
#define GRABBER 2
// servo ports
#define ELECTRIC 0
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
    create_stop(); gobackward(1); return 0;}
	// stringer down is 1830 and up is 800
int stringerup() {set_servo_position(ELECTRIC,500); return 0;}
int stringerdown() {set_servo_position(ELECTRIC,1830); return 0;}
int grabberup(){set_servo_position(GRABBER,112); return 0;} // This procedure and the next two need to be filled in     
int grabbermiddle(){set_servo_position(GRABBER,1160); return 0;}//  112 is up, 1160is middle, anddownis 1500
int grabberdown(){set_servo_position(GRABBER,1500); return 0;}
int main() {
  	printf("Hello World.\n");
    enable_servos();
    grabberup();
    stringerdown();
   	create_connect();
  	printf("Create connected.\n");
  	// wait_for_light(0);
  	// shut_down_in(119.5); /*seconds*/
  	gobackward(20);
  	turnleft();
  	forwardtobump();
    turnright();
    
    gobackward(10);
    stringerup();
    goforward(25.5);
    stringerdown();
    gobackward(40);
    stringerup();
    
    gobackward(20);
    stringerdown();
   
    speed=100;
    turnright();
  	create_disconnect();
  	return 0;}