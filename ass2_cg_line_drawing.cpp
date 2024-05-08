#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

int gd = DETECT, gm;


int myRound(float num) {
    return (num >= 0) ? (int)(num + 0.5) : (int)(num - 0.5);
}


void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(myRound(x), myRound(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}


void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    if (dx >= dy) {
        int d = 2 * dy - dx;
        int ds = 2 * dy;
        int dt = 2 * (dy - dx);
        if (x1 < x2) {
            x = x1;
            y = y1;
        } else {
            x = x2;
            y = y2;
            x2 = x1;
            y2 = y1;
        }
        putpixel(x, y, WHITE);
        while (x < x2) {
            x++;
            if (d < 0)
                d += ds;
            else {
                if (y1 < y2)
                    y++;
                else
                    y--;
                d += dt;
            }
            putpixel(x, y, WHITE);
        }
    } else {
        int d = 2 * dx - dy;
        int ds = 2 * dx;
        int dt = 2 * (dx - dy);
        if (y1 < y2) {
            x = x1;
            y = y1;
        } else {
            x = x2;
            y = y2;
            y2 = y1;
            x2 = x1;
        }
        putpixel(x, y, WHITE);
        while (y < y2) {
            y++;
            if (d < 0)
                d += ds;
            else {
                if (x1 > x2)
                    x--;
                else
                    x++;
                d += dt;
            }
            putpixel(x, y, WHITE);
        }
    }
}


void drawRectangle() {
    
    int x1 = 150, y1 = 150, x2 = 250, y2 = 150;
    int x3 = 250, y3 = 200, x4 = 150, y4 = 200;

    
    drawLineDDA(x1, y1, x2, y2);
    drawLineDDA(x2, y2, x3, y3);
    drawLineDDA(x3, y3, x4, y4);
    drawLineDDA(x4, y4, x1, y1);

  
    drawLineBresenham(x1 + 250, y1, x2 + 250, y2);
    drawLineBresenham(x2 + 250, y2, x3 + 250, y3);
    drawLineBresenham(x3 + 250, y3, x4 + 250, y4);
    drawLineBresenham(x4 + 250, y4, x1 + 250, y1);
}

int main() {
    int choice;

   
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Menu:\n");
    printf("1. Draw a line using DDA algorithm\n");
    printf("2. Draw a line using Bresenham's algorithm\n");
    printf("3. Draw a rectangle using both algorithms\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                int x1, y1, x2, y2;
                printf("Enter coordinates (x1 y1 x2 y2): ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                drawLineDDA(x1, y1, x2, y2);
                break;

            case 2:
                
                printf("Enter coordinates (x1 y1 x2 y2): ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                drawLineBresenham(x1, y1, x2, y2);
                break;

            case 3:
                
                drawRectangle();
                break;

            case 4:
               
                closegraph();
                getch();
                return 0;

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
