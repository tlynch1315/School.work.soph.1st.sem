// Tommy Lynch NDID: Tlynch2

#include"gfx.h"
#include<math.h>
#include<unistd.h>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
using namespace std;
int main(){
  float xsize = 500, ysize = 500, rad = 30, dx =1, dy = 1, dt = 3;
  float xi = 250, yi = 250;           // initial x and y position of circle
  float x2 = xi,y2 = yi;              // allows the xi and yi values to be
                                      // changed in the loop
  srand(time(NULL));                  // seeding the random number generator
  float vx = rand()%10, vy = rand()%20;
                                      // velocities
  char c = ' ';
  gfx_open(xsize,ysize,"bounce.cpp"); // opening the window
  gfx_clear();                        // needed on linux computers
  gfx_circle(xi,yi,rad);              // starting circle in middle
  while(c!='q'){
    usleep(5000);                     // pauses the process
    gfx_clear();                      // clears what was on the screen
    gfx_color(255,255,255);           // white
    x2+=dx*vx;                        // new x value of center
    y2+=dy*vy;                        // new y value of center
    if(y2-rad < 0 || y2+rad>500){
      dy*=(-1);
    }                                 // changes the direction of the y velocity
    if(x2+rad > 500 || x2-rad < 0){
      dx*=(-1);
    }                                 // changes the direction of the x velocity
    if(y2-rad < 0){
      y2 = 0+rad;
    }                                 // fixes when ball goes off top
    if(y2+rad > 500){
      y2 =  500-rad;
    }                                 // fixes when ball goes off bottom
    if(x2-rad < 0){
      x2 = 0+rad;
    }                                 // fixes when ball goes off left
    if(x2+rad > 500){
      x2 = 500-rad;
    }                                 // fixes when ball goes off right
    if(c == 1){
      x2=gfx_xpos();
      y2=gfx_ypos();
      vx = rand()%10;
      vy = rand()%10;
      c = ' ';
    }                                 // making the x and y values the position of the
                                      // mouse then generating a new x and y velocity
    gfx_circle(x2,y2,rad);            // drawing the actual circle
    gfx_flush();                      // flush everything to window
    if(gfx_event_waiting()){
      c = gfx_wait();
    }                                 // if an event is happening, set c = to the value
  }
}
