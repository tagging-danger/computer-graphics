#include <stdio.h>
#include <graphics.h>
#include <math.h>

void midPointLineClipping(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    // Calculate the slope and intercept of the line
    float m = (float)(y2 - y1) / (x2 - x1);
    float b = y1 - m * x1;

    // Initialize the start and end points of the clipped line
    int x1c = x1, y1c = y1, x2c = x2, y2c = y2;

    // Check if the line is inside the left boundary
    if (x1 < xmin && x2 >= xmin) {
        y1c = m * xmin + b;
        x1c = xmin;
    } else if (x2 < xmin && x1 >= xmin) {
        y2c = m * xmin + b;
        x2c = xmin;
    }

    // Check if the line is inside the right boundary
    if (x1 > xmax && x2 <= xmax) {
        y1c = m * xmax + b;
        x1c = xmax;
    } else if (x2 > xmax && x1 <= xmax) {
        y2c = m * xmax + b;
        x2c = xmax;
    }

    // Check if the line is inside the bottom boundary
    if (y1 < ymin && y2 >= ymin) {
        x1c = (ymin - b) / m;
        y1c = ymin;
    } else if (y2 < ymin && y1 >= ymin) {
        x2c = (ymin - b) / m;
        y2c = ymin;
    }

    // Check if the line is inside the top boundary
    if (y1 > ymax && y2 <= ymax) {
        x1c = (ymax - b) / m;
        y1c = ymax;
    } else if (y2 > ymax && y1 <= ymax) {
        x2c = (ymax - b) / m;
        y2c = ymax;
    }

    // Draw the clipped line
    line(x1c, y1c, x2c, y2c);
}
int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int xmin, ymin, xmax, ymax;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Get the line endpoints from the user
//    int x1, y1, x2, y2;
    printf("Enter the coordinates of the line endpoints:\n");
    printf("x1: ");
    scanf("%d", &x1);
    printf("y1: ");
    scanf("%d", &y1);
    printf("x2: ");
    scanf("%d", &x2);
    printf("y2: ");
    scanf("%d", &y2);

    // Get the rectangle boundaries from the user
//    int xmin, ymin, xmax, ymax;
    printf("Enter the coordinates of the rectangle boundaries:\n");
    printf("xmin: ");
    scanf("%d", &xmin);
    printf("ymin: ");
    scanf("%d", &ymin);
    printf("xmax: ");
    scanf("%d", &xmax);
    printf("ymax: ");
    scanf("%d", &ymax);

    // Draw the rectangle boundaries
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(RED);
    getch();

    // Clip and draw the line
    midPointLineClipping(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
    setcolor(BLUE);

    getch();
    closegraph();
    return 0;
}

