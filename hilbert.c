#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define MAX_POINTS 10000

// Structure to represent a point
struct Point {
    int x;
    int y;
};

// Function to draw a line segment
void drawLine(struct Point p1, struct Point p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

// Function to draw a Hilbert curve
void drawHilbertCurve(int startX, int startY, int length, int iterations) {
    int i, j, n, rx, ry, t;

    for (n = 1; n <= iterations; n++) {
        int numPoints = pow(4, n);
        struct Point points[MAX_POINTS];

        points[0].x = startX;
        points[0].y = startY;

        int sign = 1;
        int rotate = 1;

        for (i = 1; i < numPoints; i++) {
            points[i] = points[i - 1];

            rx = 1 & (i >> 1);
            ry = 1 & (i ^ rx);

            if (ry == 0) {
                if (rx == 1) {
                    points[i].x += sign * length;
                } else {
                    points[i].x -= sign * length;
                    points[i].y += sign * length;
                }
            } else {
                if (rx == 1) {
                    points[i].x += sign * length;
                    points[i].y -= sign * length;
                } else {
                    points[i].x -= sign * length;
                }
            }

            if (rotate) {
                t = points[i].x;
                points[i].x = points[i].y;
                points[i].y = t;
            }

            sign *= -1;
        }

        for (j = 0; j < numPoints - 1; j++) {
            drawLine(points[j], points[j + 1]);
        }

        startX = points[numPoints - 1].x;
        startY = points[numPoints - 1].y;
        length /= 2;
    }
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Set the start position and length of the Hilbert curve
    int startX, startY, length;
    printf("Enter the x-coordinate of the start position: ");
    scanf("%d", &startX);
    printf("Enter the y-coordinate of the start position: ");
    scanf("%d", &startY);
    printf("Enter the length of the Hilbert curve: ");
    scanf("%d", &length);

    // Set the number of iterations
    int iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    // Draw the Hilbert curve
    drawHilbertCurve(startX, startY, length, iterations);

    delay(5000);

    closegraph();

    return 0;
}
