#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to reflect a point about the X-axis
void reflectXAxis(int* y) {
    *y = getmaxy() - *y;
}

// Function to reflect a point about the Y-axis
void reflectYAxis(int* x) {
    *x = getmaxx() - *x;
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Coordinates of the triangle
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 200;
    int x3 = 300, y3 = 100;

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);
    delay(2000);
    cleardevice();

    // Reflect the triangle about the X-axis
    int tx1 = x1, ty1 = y1;
    int tx2 = x2, ty2 = y2;
    int tx3 = x3, ty3 = y3;
    reflectXAxis(&ty1);
    reflectXAxis(&ty2);
    reflectXAxis(&ty3);
    drawTriangle(tx1, ty1, tx2, ty2, tx3, ty3);
    delay(2000);
    cleardevice();

    // Reflect the triangle about the Y-axis
    int rx1 = x1, ry1 = y1;
    int rx2 = x2, ry2 = y2;
    int rx3 = x3, ry3 = y3;
    reflectYAxis(&rx1);
    reflectYAxis(&rx2);
    reflectYAxis(&rx3);
    drawTriangle(rx1, ry1, rx2, ry2, rx3, ry3);
    delay(2000);
    cleardevice();

    closegraph();

    return 0;
}
