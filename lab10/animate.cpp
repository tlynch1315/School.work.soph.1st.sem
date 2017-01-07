// Tommy Lynch NDID: Tlynch2
// Game where you have to avoid the circles coming at your spaceship

#include"gfx.h"
#include<cstdlib>
#include<cmath>
#include<unistd.h>
#include<ctime>
using namespace std;

void drawShip(float xpos, float ypos, float theta, float size);
void bounds(float &xpos, float &ypos, float xsize, float ysize);
void check_collision(float circlex,float circley,float circlesize,float circlex2,    float circley2,float circlesize2,float xpos,float ypos, bool &loop);

void new_circle(float &circlex,float &circley,float &circlesize,float &circlex2,     float &circley2,float &circlesize2,float &xpos,float &ypos,float &dx,float &dy,    float &dx2, float &dy2, float xsize, float ysize);


int main(){
  float xsize = 600, ysize = 600;     // window sizes
  float xpos = 300, ypos = 300;       // initial position of spaceship
  float velocity = 0;                 // initial velocity is 0
  float theta = 0;                    // initial angle
  float shipsize = 20;                // size of spaceship
  srand(time(NULL));                  // seed the random number generator
  float dx = rand()%5+(-2);           // random int between -2 and 2
  float dy = rand()%5+(-2);
  float dx2 = rand()%5+(-2);
  float dy2 = rand()%5+(-2);
  float circlex = rand()% 600;        // random x position of incoming circle
  float circlex2 = rand()% 600;
  float circlesize = rand()%50;       // random size of incoming circle
  float circlesize2 = rand()%50;
  float circley = 0+ circlesize;      // initial y value of circle
  float circley2 = 0 + circlesize2;
  bool loop = true;
  char c;
  gfx_open(xsize,ysize,"Spaceship Game"); 
  while(loop){
    gfx_clear();
    gfx_text(0,50,"use arrows to control spaceship and avoid circles");   
    gfx_circle(circlex, circley,circlesize);
    gfx_circle(circlex2, circley2, circlesize2);
    drawShip(xpos, ypos, theta, shipsize);
    gfx_flush();
    xpos = xpos + velocity*sin(theta);
    ypos = ypos - velocity*cos(theta);
    circlex+=dx;
    circlex2+=dx2;
    circley+=dy;
    circley2+=dy2;
    usleep(8000);
    new_circle(circlex,circley,circlesize,circlex2,circley2,circlesize2,xpos,ypos,     dx,dy, dx2, dy2, xsize,ysize);
                                  // checks to see if there should be a new
                                  // circle
    check_collision(circlex,circley,circlesize,circlex2,circley2,circlesize2,xpos,ypos, loop);
                                  // checks to see if the spaceship and circles
                                  // are colliding
    if (gfx_event_waiting()){
      c = gfx_wait();
      switch(c){
        case 'R':                 // up arrow
          velocity+=.5;
          break;
        case 'Q':                 // left arrow
          theta-=.25;
          break;
        case 'T':                 // down arrow
          velocity = (velocity-.25 <0) ? 0 : velocity - .25;
          break;
        case 'S':                 // right arrow
          theta+=.25;
          break;
        case 'q':
          loop = false;
          break;
      }
    }
    bounds(xpos,ypos,xsize,ysize);
                                  // makes the spaceship always be on screen
  } 
}

void drawShip(float xpos, float ypos, float theta, float size){
  float xtop, ytop, xleft, yleft, xright, yright;
  float angle = 2*M_PI/3;
  xtop = xpos + size*sin(theta);
  ytop = ypos - size*cos(theta);
  xleft = xpos + .5*size*sin(theta-angle);
  yleft = ypos - .5*size*cos(theta-angle);
  xright = xpos + .5*size*sin(theta+angle);
  yright = ypos - .5*size*cos(theta+angle);
                                  // creates points for spaceship vertices
  gfx_line(xtop,ytop,xleft,yleft);
  gfx_line(xleft,yleft,xright,yright);
  gfx_line(xright,yright,xtop,ytop);
}

void bounds(float &xpos, float &ypos, float xsize, float ysize){
  if(xpos < 0){
    xpos = xsize;
  }
  else if (xpos > xsize){
    xpos = 0;
  }
  if(ypos < 0){
    ypos = ysize;
  }
  else if (ypos > ysize){
    ypos = 0;
  }
}      

void check_collision(float circlex,float circley,float circlesize,float circlex2,float circley2,float circlesize2,float xpos,float ypos, bool &loop){

  if (xpos > (circlex-circlesize) && xpos < (circlex+circlesize) && ypos > (circley-circlesize) && ypos < (circley+circlesize)){
    loop = false;
  }
                                      // first statement tests if the spaceship
                                      // is inside the first circle
  else if (xpos > (circlex2-circlesize2) && xpos < (circlex2+circlesize2) && ypos > (circley2-circlesize2) && ypos < (circley2+circlesize2)){
    loop = false;
  }
                                      // second statement tests if the spaceship 
                                      // is inside the second circle
}


void new_circle(float &circlex,float &circley,float &circlesize,float &circlex2,     float &circley2,float &circlesize2,float &xpos,float &ypos,float &dx,float &dy,    float &dx2, float &dy2, float xsize, float ysize){
  
  if (circley > ysize || circley < 0 || circlex > xsize || circlex < 0){
      circlex = rand()% 600;
      circlesize = rand()% 50;
      circley = 0 + circlesize;
      dx = rand()%5+(-2);
      dy = rand()%5+(-2);
      while(dx == 0 || dy == 0){
        dx = rand()%5+(-2);
        dy = rand()%5+(-2);
      }
    }
                                      // if the first circle is out of bounds
                                      // make a new one with dx and dy !=0
    if (circley2 > ysize || circley2 < 0 || circlex2 > xsize || circlex2 < 0){
      circlex2 = rand()% 600;
      circlesize2 = rand()% 50;
      circley2 = 0 + circlesize;
      dx2 = rand()%5+(-2);
      dy2 = rand()%5+(-2);
      while(dx2 == 0 || dy2 == 0){
        dx2 = rand()%5+(-2);
        dy2 = rand()%5+(-2);
      }
    }
                                      // if the second circle is out of bounds
                                      // make a new one with dx and dy !=0
}





