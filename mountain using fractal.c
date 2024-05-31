#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>

#define MAX_POINTS 100000

// Structure to represent a 2D point
struct Point {
    int x;
    int y;
};

// Function to draw a line segment
void drawLine(struct Point p1, struct Point p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

// Function to generate a random number between min and max
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate the midpoint between two points
struct Point calculateMidpoint(struct Point p1, struct Point p2) {
    struct Point midpoint;
    midpoint.x = (p1.x + p2.x) / 2;
    midpoint.y = (p1.y + p2.y) / 2;
    return midpoint;
}

// Function to generate a fractal mountain
void generateFractalMountain(struct Point startPoint, struct Point endPoint, int iterations, int randomness) {
    int i, j, n, rx, ry, t;

    struct Point points[MAX_POINTS];
    int numPoints = 0;

    points[numPoints++] = startPoint;
    points[numPoints++] = endPoint;

    for (n = 1; n <= iterations; n++) {
        int numIterations = numPoints - 1;
        int numNewPoints = numIterations * 2;

        for (i = 0; i < numIterations; i++) {
            struct Point p1 = points[i];
            struct Point p2 = points[i + 1];
            struct Point midpoint = calculateMidpoint(p1, p2);

            struct Point randomOffset;
            randomOffset.x = getRandomNumber(-randomness, randomness);
            randomOffset.y = getRandomNumber(-randomness, randomness);

            struct Point newPoint;
            newPoint.x = midpoint.x + randomOffset.x;
            newPoint.y = midpoint.y + randomOffset.y;

            // Insert new point at index i*2 + 1
            for (j = numPoints - 1; j > i; j--) {
                points[j + 1] = points[j];
            }
            points[i * 2 + 1] = newPoint;
            numPoints++;

            // Insert new point at index i*2 + 2
            for (j = numPoints - 1; j > i + 1; j--) {
                points[j + 1] = points[j];
            }
            points[i * 2 + 2] = p2;
            numPoints++;
        }

        randomness /= 2;
    }

    // Draw the mountain
    for (i = 0; i < numPoints - 1; i++) {
        drawLine(points[i], points[i + 1]);
    }
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Set the start and end points of the mountain
    struct Point startPoint, endPoint;
    startPoint.x = 50;
    startPoint.y = 200;
    endPoint.x = 550;
    endPoint.y = 200;

    // Set the number of iterations and randomness factor
    int iterations, randomness;
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);
    printf("Enter the randomness factor (between 0 and 100): ");
    scanf("%d", &randomness);

        // Generate the fractal mountain
    generateFractalMountain(startPoint, endPoint, iterations, randomness);

    delay(5000);

    closegraph();

    return 0;
}

