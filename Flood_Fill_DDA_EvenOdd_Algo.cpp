#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

#define MAX_QUEUE_SIZE 100000

// structure to store a point
typedef struct Point {
    int x;
    int y;
} Point;

// function to draw a line using DDA algorithm
void drawLine(Point p1, Point p2, int color) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float) dx / (float) steps;
    float yIncrement = (float) dy / (float) steps;

    float x = p1.x;
    float y = p1.y;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), color);
        x += xIncrement;
        y += yIncrement;
    }
}

// function to enqueue a point
void enqueue(Point queue[], int *rear, Point p) {
    queue[*rear] = p;
    (*rear)++;
}

// function to dequeue a point
Point dequeue(Point queue[], int *front) {
    (*front)++;
    return queue[*front - 1];
}

// function to perform flood fill using queue
void floodFill(Point seed, int fillColor, int borderColor) {
    Point queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    enqueue(queue, &rear, seed);

    while (front < rear) {
        Point current = dequeue(queue, &front);

        if (getpixel(current.x, current.y) == borderColor ||
            getpixel(current.x, current.y) == fillColor) {
            continue;
        }

        // fill current pixel with fill color
        putpixel(current.x, current.y, fillColor);

        // enqueue neighboring pixels
        Point north = {current.x, current.y - 1};
        Point south = {current.x, current.y + 1};
        Point east = {current.x + 1, current.y};
        Point west = {current.x - 1, current.y};

        enqueue(queue, &rear, north);
        enqueue(queue, &rear, south);
        enqueue(queue, &rear, east);
        enqueue(queue, &rear, west);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        printf("Enter vertex %d (x, y): ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Draw polygon
    for (int i = 0; i < n - 1; i++) {
        Point p1 = {x[i], y[i]};
        Point p2 = {x[i + 1], y[i + 1]};
        drawLine(p1, p2, WHITE);
    }
    Point p1 = {x[n - 1], y[n - 1]};
    Point p2 = {x[0], y[0]};
    drawLine(p1, p2, WHITE);

    // Get seed point for flood fill
    int seedX, seedY;
    printf("Enter the seed point (x, y): ");
    scanf("%d %d", &seedX, &seedY);

    Point seed = {seedX, seedY};
    floodFill(seed, YELLOW, WHITE);

    getch();
    closegraph();
    return 0;
}

