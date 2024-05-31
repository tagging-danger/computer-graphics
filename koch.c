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

// Function to generate the Koch curve
void generateKochCurve(struct Point startPoint, struct Point endPoint, int iterations) {
    struct Point points[MAX_POINTS];
    int numPoints = 0;

    // Add the start and end points to the array
    points[numPoints++] = startPoint;
    points[numPoints++] = endPoint;

    // Generate Koch curve segments iteratively
    for (int i = 0; i < iterations; i++) {
        int prevNumPoints = numPoints;
        for (int j = 0; j < prevNumPoints - 1; j++) {
            struct Point p1 = points[j];
            struct Point p2 = points[j + 1];

            // Calculate the distances and angles
            int dx = p2.x - p1.x;
            int dy = p2.y - p1.y;
            double segmentLength = sqrt(dx * dx + dy * dy);
            double angle = atan2(dy, dx);

            // Calculate the four points of the Koch segment
            struct Point pA, pB, pC, pD;
            pA.x = p1.x + dx / 3;
            pA.y = p1.y + dy / 3;
            pD.x = p1.x + 2 * dx / 3;
            pD.y = p1.y + 2 * dy / 3;
            pB.x = pA.x + cos(angle - M_PI / 3) * segmentLength / 3;
            pB.y = pA.y + sin(angle - M_PI / 3) * segmentLength / 3;
            pC.x = pA.x + cos(angle + M_PI / 3) * segmentLength / 3;
            pC.y = pA.y + sin(angle + M_PI / 3) * segmentLength / 3;

            // Add the new points to the array
            points[numPoints++] = pA;
            points[numPoints++] = pB;
            points[numPoints++] = pC;
            points[numPoints++] = pD;
        }
    }

    // Draw the Koch curve
    for (int i = 0; i < numPoints - 1; i++) {
        drawLine(points[i], points[i + 1]);
    }
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Set the start and end points of the Koch curve
    struct Point startPoint, endPoint;
    printf("Enter the x-coordinate of the start point: ");
    scanf("%d", &startPoint.x);
    printf("Enter the y-coordinate of the start point: ");
    scanf("%d", &startPoint.y);
    printf("Enter the x-coordinate of the end point: ");
    scanf("%d", &endPoint.x);
    printf("Enter the y-coordinate of the end point: ");
    scanf("%d", &endPoint.y);

    // Set the number of iterations
    int iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

        // Generate and draw the Koch curve
    generateKochCurve(startPoint, endPoint, iterations);

    delay(5000);

    closegraph();

    return 0;
}

