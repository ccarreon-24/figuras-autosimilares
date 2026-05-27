#include "../turtlec.h"

void koch(Turtle *t, float length, int level){
  if(level == 0){
    turtleForward(t, length);
    return ;
  }
  koch(t, length/3.00, level - 1);
  turtleLeft(t, 60);
  koch(t, length/3.00, level - 1);
  turtleRight(t, 120);
  koch(t, length/3.00, level - 1);
  turtleLeft(t, 60);
  koch(t, length/3.00, level -1);
}

void koch2(Turtle *t, float length, int level){
  if(level == 0){
    turtleForward(t, length);
    turtleRight(t, 120);
    turtleForward(t, length);
    turtleRight(t, 120);
    turtleForward(t, length);
    return ;
  }
  
}

void fractalTree(Turtle *, int , int){
  if(depht == 0)
}



int main(void){
  TurtleApp *app = turtleAppCreate(400, 200, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 50.0f, 100.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 5.0f);
//  turtleForward(t, 300.0f);
//  koch(t, 100, 4);
  koch2(t, 100, 0);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
