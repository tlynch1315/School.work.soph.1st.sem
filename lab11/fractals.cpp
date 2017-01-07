// ******MADE WITH PAIR PROGRAMMING******
// Tommy Lynch NDID: Tlynch2
// Will Fritz NDID: Wfritz
// fractals.cpp
#include"gfxnew.h"
#include<cmath>
#include<unistd.h>
using namespace std;
void choice(char c, bool &loop, float , float);
void triangles(float x1,float y1, float x2, float y2, float x3, float y3);
void shrinksquares(float, float, float);
void spiralsquares(float, float, float, float);
void circularlace(float, float, float);
void snowflake(float, float, float);
void tree(float, float, float, float);
void fern(float , float, float, float);
void spiralspiral();
                                // functions for fractals
void drawtriangle(float ,float,float,float,float,float);
void drawsquare(float, float, float);
void drawflake(float, float, float);
                                // functions for drawing shapes 
int main(){
  float xsize = 600, ysize = 600;             // window size
  char c;                                     // initialize a char for input
  bool loop = true;                           // initialize loop as true 
  gfx_open(xsize, ysize, "fractals.cpp");     // opens window
  gfx_clear();                                // clears window 
  gfx_color(255,255,255);                     // sets color to white
  while(loop){
    c = gfx_wait();
    if(c >48 && c < 58){
      gfx_clear();
      choice(c, loop, xsize, ysize);
    }
    else if(c == 113){
      return 0;
    }
                                              // while loop only calls choice()
                                              // if the input is a number and 
                                              // quits if it is q
    gfx_flush();
  }
}

void choice(char c, bool &loop, float xsize, float ysize){
  switch(c){  
    case '1':
      triangles(0,0,ysize, 0, (xsize/2), ysize);
      break;
    case '2':
      shrinksquares((xsize/2),(ysize/2),300);
      break;
    case '3':
      spiralsquares((xsize/2),(ysize/2),2,0);
      break;
    case '4':
      circularlace((xsize/2), (ysize/2), 250);
      break;
    case '5':
      snowflake((xsize/2),(ysize/2),200);
      break;
    case '6':
      tree((xsize/2), ysize, 200, (M_PI/2));
      break;
    case '7':
      fern((xsize/2),ysize,400,(M_PI/2));
      break;
    case '8':
      spiralspiral();
      break;
    case 'q':
      loop = false;
      break;
    default:
      c = gfx_wait();
      choice(c, loop, xsize, ysize);
      break;
  }
}
                          // function uses the users input to call different 
                          // fractal functions

void triangles(float x1, float y1, float x2, float y2, float x3, float y3){
  if(abs(x2-x1) < 5) return;
  
  drawtriangle(x1,y1,x2,y2,x3,y3);
  
  triangles(x1,y1,(x1+x2)/2,(y1+y2)/2,(x1+x3)/2,(y1+y3)/2);
  triangles((x1+x2)/2,(y1+y2)/2,x2,y2,(x2+x3)/2,(y2+y3)/2);
  triangles((x1+x3)/2,(y1+y3)/2,(x2+x3)/2,(y2+y3)/2, x3,y3);
}
                          // draws a large triangle then three triangles
                          // recursively until the base is less than 5
void shrinksquares(float x1,float y1, float sidelength){
  if(sidelength < 5) return;
  
  drawsquare(x1,y1,sidelength);
  sidelength/=2;

  shrinksquares(x1-sidelength,y1-sidelength, sidelength);
  shrinksquares(x1+sidelength,y1-sidelength, sidelength);
  shrinksquares(x1+sidelength,y1+sidelength, sidelength);
  shrinksquares(x1-sidelength,y1+sidelength, sidelength);

}
                          // draws the large square then calls itself four times 
                          // to draw the four sections of squares
void spiralsquares(float x1, float y1, float sidelength, float theta){
  if(sidelength > 300) return;
  drawsquare(x1,y1,sidelength);
  theta+=(M_PI/6);
  float xnew = x1+ (1.5*sidelength*cos(theta));
  float ynew = y1 - (1.5*sidelength*sin(theta));
  sidelength*=1.1;
  spiralsquares(xnew,ynew, sidelength, theta);
}
                          // uses the input of x and the sidelength to draw
                          // a square then increments theta and x and y and
                          // calls itself to draw another square
void circularlace(float x1, float y1, float rad){
  if (rad < 2) return;
  gfx_circle(x1,y1,rad);
  float x, y;

  for(float theta = 0; theta < (2*M_PI); theta+=(M_PI/3)){
    x = x1 +(rad*cos(theta));
    y = y1 -(rad*sin(theta));
    gfx_circle(x,y,(rad/3));
    circularlace(x,y,(rad/3));
  }
}
                          // draws a large circle, then every PI/3 radians it draws
                          // another circle and does the same for that circle 
                          // until the radius is less than two
void snowflake(float x1, float y1, float sidelength){
  if(sidelength < 5) return;
  drawflake(x1, y1, sidelength);
  float x,y;
  
  for(float theta = (3*M_PI/2); theta < (31*M_PI/10); theta+=(2*M_PI/5)){
    x = x1 + (sidelength*cos(theta));
    y = y1 - (sidelength*sin(theta));
    drawflake(x,y,(sidelength/3));
    //gfx_flush();
    //usleep(8000);
    snowflake(x,y,(sidelength/3));
  }

}
                          // draws five lines using the drawflake function then 
                          // increments x and y and draws a flake at the end of
                          // the 5 lines of the flake
void tree(float x1, float y1, float length, float theta){
  if (length < 1) return;
  float x2,y2;
  x2 = x1 + (length*cos(theta));
  y2 = y1 - (length*sin(theta));

  gfx_line(x1,y1,x2,y2);
  tree(x2,y2,(length*.7), (theta+(M_PI/5)));
  tree(x2,y2,(length*.7), (theta-(M_PI/5)));

}
                          // draws a line, then two lines coming from that, then
                          // another two lines from each line and so on until
                          // the length is less than 1
void fern(float x1, float y1, float length, float theta){
  if (length < 3) return;
  float x2 = x1 + (length*cos(theta));
  float y2 = y1 - (length*sin(theta));
  
  gfx_line(x1,y1,x2,y2);
  float startx1 = x1 + (length*cos(theta));
  float startx2 = x1 + (.75*length*cos(theta));
  float startx3 = x1 + (.5*length*cos(theta));
  float startx4 = x1 + (.25*length*cos(theta));

  float starty1 = y1 - (length*sin(theta));
  float starty2 = y1 - (.75*length*sin(theta));
  float starty3 = y1 - (.5*length*sin(theta));
  float starty4 = y1 - (.25*length*sin(theta));

  length*=.3;
  
  fern(startx1,starty1,length,(theta+(M_PI/6)));
  fern(startx1,starty1,length,(theta-(M_PI/6)));

  fern(startx2,starty2,length,(theta+(M_PI/6)));
  fern(startx2,starty2,length,(theta-(M_PI/6)));

  fern(startx3,starty3,length,(theta+(M_PI/6)));
  fern(startx3,starty3,length,(theta-(M_PI/6)));

  fern(startx4,starty4,length,(theta+(M_PI/6)));
  fern(startx4,starty4,length,(theta-(M_PI/6)));


 
}
                          // takes in an x and y and length and theta and uses
                          // them to get the end of the next line, then 
                          // uses them to get the starting points of the branches
                          // off of that line
void spiralspiral(){

}
void drawtriangle(float x1, float y1, float x2, float y2, float x3, float y3){
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x1,y1);
}
                          // draws a triangle
void drawsquare(float x1, float y1, float sidelength){
  float half = sidelength/2;
  gfx_line(x1-half, y1-half, x1+half, y1-half);
  gfx_line(x1+half,y1-half,x1+half,y1+half);
  gfx_line(x1+half, y1+half, x1-half, y1+half);
  gfx_line(x1-half, y1+half, x1-half, y1-half);
} 
                          // draws a square
void drawflake(float x1, float y1, float sidelength){
  float theta;
  float x2, y2;
  for(theta = (3*M_PI/2); theta < (9*M_PI/2); theta+=(2*M_PI/5)){
    x2 = x1 + (sidelength*cos(theta));
    y2 = y1 - (sidelength*sin(theta));
    gfx_line(x1,y1,x2,y2);
  }
}
                          // draws a flake with one line pointing straight down
