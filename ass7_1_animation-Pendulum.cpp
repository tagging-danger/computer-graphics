#include <graphics.h>
#include <conio.h>
#include <math.h>
const int windowWidth = 800;
const int windowHeight = 600;
const float pendulumLength = 200.0f;
const float pendulumRadius = 20.0f;
const int pivotX = windowWidth / 2;
const int pivotY = 100;
void drawPendulum(float angle) {
 int x = pendulumLength * sin(angle);
 int y = pendulumLength * cos(angle);
 circle(pivotX + x, pivotY + y, pendulumRadius);
 line(pivotX, pivotY, pivotX + x, pivotY + y);
}
int main() {
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 float angle = 0.0f;
 int moveDirection = 1; // 1 represents moving right, -1 represents moving left
 while (!kbhit()) {
 cleardevice();
 drawPendulum(angle);
 angle += 0.05f * moveDirection; // Increment angle based on moveDirection
 // Check if angle reaches the limit, then change direction
 if (angle >= 3.14f / 4)
 moveDirection = -1;
 else if (angle <= -3.14f / 4)
 moveDirection = 1;
 getch();
 }
 closegraph();
 return 0;
}