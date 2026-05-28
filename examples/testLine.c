#include "../turtlec.h"

void fractalTree(Turtle *t, int length, int depth){
  if(depth == 0 || length < 6)
		return ;
	turtleForward(t, length);
	turtleLeft(t, 30);
	fractalTree(t, length * 0.7, depth - 1);

	turtleRight(t, 60);
	fractalTree(t, length * 0.7, depth - 1);

	turtleLeft(t, 30);
	turtleBackward(t, length);
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
	fractalTree(t, 100, 4);
	turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
