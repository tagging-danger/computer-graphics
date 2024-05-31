#include<stdio.h>
#include<graphics.h>

typedef struct {
    int x;
    int y;
} Point;

void drawLineDDA(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xInc = dx / (float) steps;
    float yInc = dy / (float) steps;
    float x = p1.x;
    float y = p1.y;

    for(int i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE);
        x += xInc;
        y += yInc;
        delay(10);
    }
}

void enqueue(Point queue[], Point point, int *rear) {
    queue[*rear] = point;
    (*rear)++;
}

Point dequeue(Point queue[], int *front) {
    (*front)++;
    return queue[*front - 1];
}

void fenceFill(Point seed, int boundaryColor, int fillColor) {
    Point queue[100000];
    int front = 0, rear = 0;

    //Enqueue seed point
    enqueue(queue, seed, &rear);

    while(front != rear) {
        Point current = dequeue(queue, &front);

        //Check if current point is inside the boundary
        if(getpixel(current.x, current.y) != boundaryColor && getpixel(current.x, current.y) != fillColor) {

            //Fill current point with fill color
            putpixel(current.x, current.y, fillColor);

            //Enqueue its 4-neighbors
            Point left = {current.x-1, current.y};
            enqueue(queue, left, &rear);

            Point right = {current.x+1, current.y};
            enqueue(queue, right, &rear);

            Point up = {current.x, current.y-1};
            enqueue(queue, up, &rear);

            Point down = {current.x, current.y+1};
            enqueue(queue, down, &rear);
        }
    }

    //Fill any remaining pixels inside the polygon boundary
    for(int y = 0; y < getmaxy(); y++) {
        int inside = 0;
        for(int x = 0; x < getmaxx(); x++) {
            if(getpixel(x, y) == boundaryColor) {
                inside = !inside;
            }
            else if(inside && getpixel(x, y) != fillColor) {
                putpixel(x, y, fillColor);
            }
        }
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    //Draw fence using user input vertices
    int n, x, y;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Point vertices[n];

    for(int i = 0; i < n; i++) {
        printf("Enter vertex %d coordinates (x, y): ", i+1);
        scanf("%d %d", &x, &y);
        vertices[i].x = x;
        vertices[i].y = y;
    }

    for(int i = 0; i < n-1; i++) {
        drawLineDDA(vertices[i], vertices[i+1]);
    }
    drawLineDDA(vertices[n-1], vertices[0]);

    //Fill the region inside the fence using user input seed point
    Point seed;
    printf("Enter the seed point coordinates (x, y): ");
    scanf("%d %d", &x, &y);
    seed.x = x;
    seed.y = y;
    fenceFill(seed, WHITE, RED);

    getch();
    closegraph();
    return 0;
}
