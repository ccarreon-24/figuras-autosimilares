#include "../turtlec.h"

void fractalTree(Turtle *t, int length, int depth){
  if(depth == 0 || length < 6)
		return ;
	if(depth > 1){
		turtleSetColor(t, 120, 70, 20);
	}
	else
		turtleSetColor(t, 0, 255, 0);
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
  turtleSetSpeed(t, 8.0f);
	fractalTree(t, 80, 6);
	turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
