// Tommy Lynch NDID: TLynch2

#include<iostream>
#include"gfx.h"
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265
using namespace std;
void square(float , float , float );
void triangle(float , float , float );
void polygon(float, float, float, float );
  int main(){
  const float xsize = 400, ysize = 400, rad = 30;
  char c;
  float  xpos, ypos;
  bool loop = true;
  gfx_open(xsize, ysize, "Symbol.cpp");
  gfx_clear();      // Need this on linuz computers to make background black
  while(loop){
    c = gfx_wait();
    gfx_clear();
    xpos = gfx_xpos();
    ypos = gfx_ypos();
    if (c == 1){
      gfx_color(0, 0, 255);
      square(xpos, ypos, rad);
    }
    else if(c == 't'){
      gfx_color(0,255,0);
      triangle(xpos, ypos, rad);
    }
    else if(c == 'c'){
      gfx_color(255,255,255);
      gfx_circle(xpos, ypos, rad);
    }
    else if(c == 'q'){
      loop = false;
    }
    else{
      float cf = c-'0';
      if(cf>=3 && cf <=9){
        gfx_color(255,0,255);
        polygon(xpos,ypos,rad,cf);
      }
    }
                  // Else statement makes the c value into a float and tests to see
                  // if it is between 3 and 9
    gfx_flush();
                  // flushes all of the outputs to the grpahics window
  }
  return 0;
}

void square(float x, float y, float rad){ 
    gfx_line(x+rad,y+rad,x-rad,y+rad);
    gfx_line(x-rad,y+rad,x-rad,y-rad);
    gfx_line(x-rad,y-rad,x+rad,y-rad);
    gfx_line(x+rad,y-rad,x+rad,y+rad);
}
                  // creates four lines around the mouse

void triangle(float x, float y, float rad){
    gfx_line(x+(rad*cos(PI/6)),y+(rad*sin(PI/6)), x, y-rad);
    gfx_line(x,y-rad,x-(rad*cos(PI/6)), y+(rad*sin(PI/6)));
    gfx_line(x-(rad*(cos(PI/6))), y+(rad*sin(PI/6)), x+(rad*cos(PI/6)), y+(rad*sin(PI/6)));;

}
                  // creates three lines around the mouse

void polygon(float x, float y, float rad, float c){
  float x1 = x + rad;
  float y1 = y;
  float x2, y2;
  float theta = 0;
  for (float side = 0; side <= c;side++){
    x2 = x + (rad*cos(theta));
    y2 = y - (rad*sin(theta));
    gfx_line(x1,y1,x2, y2);
    x1 = x2;
    y1 = y2;
    theta+=(2*PI/c);
  }

}
                  // initializes the first x and y points then initializes the x2 and y2
                  // and then draws a line between the two then makes the new starting
                  // point the old end point and increments
