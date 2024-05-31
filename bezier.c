#include <stdio.h>
#include <graphics.h>

// Structure to represent a point
struct Point {
    int x;
    int y;
};

// Function to draw a line segment
void drawLine(struct Point p1, struct Point p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

// Function to calculate the Bezier point using the midpoint method
struct Point calculateBezierPoint(struct Point p0, struct Point p1, struct Point p2, struct Point p3, double t) {
    double tInv = 1 - t;
    double tInv2 = tInv * tInv;
    double t2 = t * t;

    struct Point bezierPoint;

    bezierPoint.x = tInv2 * tInv * p0.x + 3 * tInv2 * t * p1.x + 3 * tInv * t2 * p2.x + t2 * t * p3.x;
    bezierPoint.y = tInv2 * tInv * p0.y + 3 * tInv2 * t * p1.y + 3 * tInv * t2 * p2.y + t2 * t * p3.y;

    return bezierPoint;
}

// Function to draw a Bezier curve
void drawBezierCurve(struct Point p0, struct Point p1, struct Point p2, struct Point p3, int iterations) {
    int i, j;
    double t;

    for (i = 0; i <= iterations; i++) {
        t = (double)i / iterations;
        struct Point prevPoint = calculateBezierPoint(p0, p1, p2, p3, t);

        for (j = 1; j <= iterations; j++) {
            t = (double)(i * iterations + j) / (iterations * iterations);
            struct Point currPoint = calculateBezierPoint(p0, p1, p2, p3, t);
            drawLine(prevPoint, currPoint);
            prevPoint = currPoint;
        }
    }
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Set the control points of the Bezier curve
    struct Point p0, p1, p2, p3;
    printf("Enter the x-coordinate of control point P0: ");
    scanf("%d", &p0.x);
    printf("Enter the y-coordinate of control point P0: ");
    scanf("%d", &p0.y);
    printf("Enter the x-coordinate of control point P1: ");
    scanf("%d", &p1.x);
    printf("Enter the y-coordinate of control point P1: ");
    scanf("%d", &p1.y);
    printf("Enter the x-coordinate of control point P2: ");
    scanf("%d", &p2.x);
    printf("Enter the y-coordinate of control point P2: ");
    scanf("%d", &p2.y);
    printf("Enter the x-coordinate of control point P3: ");
    scanf("%d", &p3.x);
    printf("Enter the y-coordinate of control point P3: ");
    scanf("%d", &p3.y);

    // Set the number of iterations
    int iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    // Draw the Bezier curve
    drawBezierCurve(p0, p1, p2, p3, iterations);
    #include <stdio.h>
#include <graphics.h>

// Structure to represent a point
struct Point {
    int x;
    int y;
};

// Function to draw a line segment
void drawLine(struct Point p1, struct Point p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

// Function to calculate the Bezier point using the midpoint method
struct Point calculateBezierPoint(struct Point p0, struct Point p1, struct Point p2, struct Point p3, double t) {
    double tInv = 1 - t;
    double tInv2 = tInv * tInv;
    double t2 = t * t;

    struct Point bezierPoint;

    bezierPoint.x = tInv2 * tInv * p0.x + 3 * tInv2 * t * p1.x + 3 * tInv * t2 * p2.x + t2 * t * p3.x;
    bezierPoint.y = tInv2 * tInv * p0.y + 3 * tInv2 * t * p1.y + 3 * tInv * t2 * p2.y + t2 * t * p3.y;

    return bezierPoint;
}

// Function to draw a Bezier curve
void drawBezierCurve(struct Point p0, struct Point p1, struct Point p2, struct Point p3, int iterations) {
    int i, j;
    double t;

    for (i = 0; i <= iterations; i++) {
        t = (double)i / iterations;
        struct Point prevPoint = calculateBezierPoint(p0, p1, p2, p3, t);

        for (j = 1; j <= iterations; j++) {
            t = (double)(i * iterations + j) / (iterations * iterations);
            struct Point currPoint = calculateBezierPoint(p0, p1, p2, p3, t);
            drawLine(prevPoint, currPoint);
            prevPoint = currPoint;
        }
    }
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Set the control points of the Bezier curve
    struct Point p0, p1, p2, p3;
    printf("Enter the x-coordinate of control point P0: ");
    scanf("%d", &p0.x);
    printf("Enter the y-coordinate of control point P0: ");
    scanf("%d", &p0.y);
    printf("Enter the x-coordinate of control point P1: ");
    scanf("%d", &p1.x);
    printf("Enter the y-coordinate of control point P1: ");
    scanf("%d", &p1.y);
    printf("Enter the x-coordinate of control point P2: ");
    scanf("%d", &p2.x);
    printf("Enter the y-coordinate of control point P2: ");
    scanf("%d", &p2.y);
    printf("Enter the x-coordinate of control point P3: ");
    scanf("%d", &p3.x);
    printf("Enter the y-coordinate of control point P3: ");
    scanf("%d", &p3.y);

    // Set the number of iterations
    int iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    // Draw the Bezier curve
    drawBezierCurve(p0, p1, p2, p3, iterations);

    getch();
    closegraph();
    return 0;
}