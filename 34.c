#include <graphics.h>
#include <math.h>
#include "Bresenham_Line.c"

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // get circle center and radius from user
    int xc, yc, r;
    printf("Enter circle center x-coordinate: ");
    scanf("%d", &xc);
    printf("Enter circle center y-coordinate: ");
    scanf("%d", &yc);
    printf("Enter circle radius: ");
    scanf("%d", &r);

    int x = xc + r, y = yc;
    int angle = 0, delta = 1;

    while (1)
    {
        // clear the screen
        cleardevice();

        // draw the circle
        bresenhamCircleDraw(xc, yc, r);

        // draw the ball
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(x, y, 10, 10);

        // update the position of the ball
        angle += delta;
        if (angle > 360)
        {
            angle -= 360;
        }
        x = xc + r * cos(angle * M_PI / 180.0);
        y = yc - r * sin(angle * M_PI / 180.0);

        // pause for a moment
        delay(50);
    }

    closegraph();
    return 0;
}
