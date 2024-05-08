#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <dos.h>

void kochCurve(int x1, int y1, int x2, int y2, int it)
{
    if (it == 0)
    {
        line(x1, y1, x2, y2);
        return;
    }
    int deltaX = x2 - x1;
    int deltaY = y2 - y1; // Added semicolon here
    int x3 = x1 + deltaX / 3;
    int y3 = y1 + deltaY / 3; // Added semicolon and comma here
    int x4 = x3 + (int)((deltaX / 2.0 - deltaY * sqrt(3) / 6.0) + 0.5);
    int y4 = y3 + (int)((deltaY / 2.0 + deltaX * sqrt(3) / 6.0) + 0.5);
    int x5 = x1 + 2 * deltaX / 3;
    int y5 = y1 + 2 * deltaY / 3;

    kochCurve(x1, y1, x3, y3, it - 1);
    kochCurve(x3, y3, x4, y4, it - 1);
    kochCurve(x4, y4, x5, y5, it - 1);
    kochCurve(x5, y5, x2, y2, it - 1);
}

void kochSnowflake(int x, int y, int length, int iterations)
{
    int x2 = x + length * cos(M_PI / 3.0);
    int y2 = y - length * sin(M_PI / 3.0);
    int x3 = x - length * cos(M_PI / 3.0);
    int y3 = y - length * sin(M_PI / 3.0);
    kochCurve(x, y, x2, y2, iterations);
    kochCurve(x2, y2, x3, y3, iterations);
    kochCurve(x3, y3, x, y, iterations);
}

void hilbertCurve(int x, int y, int xi, int xj, int yi, int yj, int n)
{
    if (n <= 0)
    {
        int newX = x + (xi + yi) / 2;
        int newY = y + (xj + yj) / 2;
        line(x, y, newX, newY);
    }
    else
    {
        hilbertCurve(x, y, yi / 2, yj / 2, xi / 2, xj / 2, n - 1);
        hilbertCurve(x + xi / 2, y + xj / 2, xi / 2, xj / 2, yi / 2, yj / 2, n - 1);
        hilbertCurve(x + xi / 2 + yi / 2, y + xj / 2 + yj / 2, xi / 2, xj / 2, yi / 2, yj / 2, n - 1);
        hilbertCurve(x + xi / 2 + yi, y + xj / 2 + yj, -yi / 2, -yj / 2, -xi / 2, -xj / 2, n - 1);
    }
}

void drawSquarePattern(int x, int y, int size, int iterations)
{
    hilbertCurve(x, y, size, 0, 0, size, iterations);
    hilbertCurve(x, y + size, 0, -size, size, 0, iterations);
    hilbertCurve(x + size, y + size, -size, 0, 0, -size, iterations);
    hilbertCurve(x + size, y, 0, size, -size, 0, iterations);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    int choice;
    printf("Choose option:\n");
    printf("1. Koch Snowflake\n");
    printf("2. Hilbert Curve Square Pattern\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        // Koch Snowflake
        int snowflakeSize = 200;
        int snowflakeIterations = 3;
        int snowflakeX = getmaxx() / 2;
        int snowflakeY = getmaxy() / 2 + 50;
        kochSnowflake(snowflakeX, snowflakeY, snowflakeSize, snowflakeIterations);
        delay(5000);
        break;
    }
    case 2:
    {
        // Hilbert Curve Square Pattern
        int squareSize = 300;
        int squareIterations = 4;
        int squareX = getmaxx() / 2 - squareSize / 2;
        int squareY = getmaxy() / 2 - squareSize / 2;
        drawSquarePattern(squareX, squareY, squareSize, squareIterations);
        delay(5000);
        break;
    }
    default:
        printf("Invalid choice.\n");
    }
    getchar();
    closegraph();
    return 0;
}
