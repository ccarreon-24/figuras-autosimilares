#include "../turtlec.h"
#include <math.h>
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

void levy(Turtle *t, float length, int depth){
	if(depth == 0){
		turtleForward(t, length);
		return ;
	}
	turtleLeft(t, 45);
	levy(t, length / sqrt(2), depth - 1);
	turtleRight(t, 90);
	levy(t, length / sqrt(2), depth - 1);
	turtleLeft(t, 45);
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
//	fractalTree(t, 80, 6);
	levy(t, 100, 5);
	turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
