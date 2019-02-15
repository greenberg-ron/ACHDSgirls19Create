//analog sensors
#define LIGHT 0
int speed=200
//maxis500
// servo ports
#define ELECTRIC 0
int turnleft(){
set_create_total_angle(0);
create_drive_direct (0,speed);
//left@,0speed
while (get_create_angle()<90){}
 create_stop();return 0;}

int turnright(){
set_create_total_angle(0);
create_drive_direct (speed,0);
//right@,0speed
while (get_create_angle()<-90){}
 create_stop();return 0;}
 
main() {
printf("Hello World.\n");
  create_connect();
 // wait_for_light(0);
 // shut_down_in(119.5)/*seconds*/
 create_disconnect();
}
