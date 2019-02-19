#include <kipr/botball.h>

//analog sensors
#define LIGHT 0
// servo ports
#define ELECTRIC 0
int speed=200; // max is 500
int turnleft(){
  set_create_total_angle(0);
  create_drive_direct (-speed,speed); // left@0, right@speed
  while (get_create_total_angle()<30){}
  create_stop(); return 0;}
int turnright(){
  set_create_total_angle(0);
  create_drive_direct (speed,-speed); // right@0, left@speed
  while (get_create_total_angle()>-27.5){}
  create_stop(); return 0;}
int goforward(int cm){
  set_create_distance(0);
  create_drive_direct(-speed,-speed); // left@0, right@speed
  while (get_create_distance()<cm){}
  create_stop(); return 0;}
int main() {
  printf("Hello World.\n");
  create_connect();
  // wait_for_light(0);
  // shut_down_in(119.5); /*seconds*/
    goforward(10);
    create_disconnect();
  return 0;
}
