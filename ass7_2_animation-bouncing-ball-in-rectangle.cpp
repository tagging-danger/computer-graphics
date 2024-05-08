#include <graphics.h>
#include <conio.h>
#include <dos.h>
const int windowWidth = 800;
const int windowHeight = 600;
const int rectangleWidth = 400;
const int rectangleHeight = 300;
const int rectangleX = (windowWidth - rectangleWidth) / 2;
const int rectangleY = (windowHeight - rectangleHeight) / 2;
const int ballRadius = 10;
void drawRectangle()
{
    rectangle(rectangleX, rectangleY, rectangleX + rectangleWidth, rectangleY + rectangleHeight);
}
void drawBall(int x, int y)
{
    circle(x, y, ballRadius);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int ballX = rectangleX + ballRadius;
    int ballY = rectangleY + ballRadius;
    int dx = 0;            // Change in x-coordinate (initially 0)
    int dy = 1;            // Change in y-coordinate (initially 1)
    int delayDuration = 3; // Initial delay duration (in milliseconds)
    while (!kbhit())
    {
        cleardevice();
        drawRectangle();
        drawBall(ballX, ballY);
        ballX += dx;
        ballY += dy;
        // Check collision with rectangle boundaries
        if (ballX == rectangleX + ballRadius && ballY < rectangleY + rectangleHeight -
                                                            ballRadius)
        {
            dy = 1; // Move downward along left edge
            dx = 0;
        }
        else if (ballY == rectangleY + rectangleHeight - ballRadius && ballX < rectangleX + rectangleWidth - ballRadius)
        {
            dx = 1; // Move rightward along bottom edge
            dy = 0;
        }
        else if (ballX == rectangleX + rectangleWidth - ballRadius && ballY > rectangleY + ballRadius)
        {
            dy = -1; // Move upward along right edge
            dx = 0;
        }
        else if (ballY == rectangleY + ballRadius && ballX > rectangleX + ballRadius)
        {
            dx = -1; // Move leftward along top edge
            dy = 0;
        }
        delay(1000);
        if (delayDuration > 1) // Decrease delay duration gradually to increase speed
            delayDuration -= 0.05;
    }
    getch();
    closegraph();
    return 0;
}
