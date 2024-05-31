#include <stdio.h>
#include <graphics.h>

// Function to draw a line using DDA algorithm
void drawLineDDA(int X1, int Y1, int X2, int Y2)
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    float X = X1;
    float Y = Y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(X, Y, WHITE);
        X += Xinc;
        Y += Yinc;
        delay(10);
    }
}

// Function to implement Flood Fill algorithm for convex polygons
void floodFillConvex(int x[], int y[], int n, int fill_color, int boundary_color)
{
    int seedX, seedY;
    int stackX[1000], stackY[1000];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        drawLineDDA(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    seedX = (x[0] + x[1]) / 2;
    seedY = (y[0] + y[1]) / 2;

    // Initialize the stack with seed point
    stackX[++top] = seedX;
    stackY[top] = seedY;

    while (top >= 0)
    {
        int currentX = stackX[top];
        int currentY = stackY[top--];

        if (getpixel(currentX, currentY) != boundary_color && getpixel(currentX, currentY) != fill_color)
        {
            delay(10);
            putpixel(currentX, currentY, fill_color);

            // Push neighboring points onto the stack
            stackX[++top] = currentX + 1;
            stackY[top] = currentY;
            stackX[++top] = currentX - 1;
            stackY[top] = currentY;
            stackX[++top] = currentX;
            stackY[top] = currentY + 1;
            stackX[++top] = currentX;
            stackY[top] = currentY - 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");

    int n;
    printf("Enter the number of vertices of the convex polygon: ");
    scanf("%d", &n);

    int x[n], y[n];
    printf("Enter the coordinates of the vertices:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    int fill_color = GREEN;
    int boundary_color = WHITE;

    floodFillConvex(x, y, n, fill_color, boundary_color);

    getch();
    closegraph();
    return 0;
}
