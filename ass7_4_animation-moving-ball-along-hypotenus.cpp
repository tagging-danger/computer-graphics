#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>

#define PI 3.14159265

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Coordinates of triangle vertices
    int x1 = 100, y1 = 100;
    int x2 = 500, y2 = 100;
    int x3 = 500, y3 = 400;

    // Draw triangle
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);

    // Calculate hypotenuse length and angle
    float hypotenuse = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    float angle = atan2((y3 - y1), (x3 - x1)) * 180 / PI;

    // Ball coordinates (starting from the top of the triangle)
    int ballRadius = 10;
    int ballX = x1, ballY = y1;

    // Move ball along hypotenuse
    while (ballX <= x2 && ballY <= y3) {
        cleardevice(); // Clear previous frame
        line(x1, y1, x2, y2); // Redraw triangle
        line(x1, y1, x3, y3);
        line(x2, y2, x3, y3);
        
        // Draw ball
        circle(ballX, ballY, ballRadius);
        floodfill(ballX, ballY, WHITE);

        // Calculate new ball position
        ballX += hypotenuse * cos(angle * PI / 180) / 100; // Adjusted for a smoother movement
        ballY += hypotenuse * sin(angle * PI / 180) / 100; // Adjusted for a smoother movement

        delay(50); // Delay for smoother animation
    }

    getch();
    closegraph();
    return 0;
}   


