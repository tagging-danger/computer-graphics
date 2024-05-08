#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int gd = DETECT, gm;


void drawCircleMidpoint(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);

        x++;

        if (p < 0)
            p = p + 2 * x + 1;
        else {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }
}


void drawCircleBresenham(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y) {
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);

        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else
            d = d + 4 * x + 6;
    }
}


void drawDifferentObject() {
  
    int x1 = 100, y1 = 100, x2 = 250, y2 = 100;
    int x3 = 250, y3 = 200, x4 = 100, y4 = 200;

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);


    int xc = (x1 + x3) / 2;
    int yc = (y1 + y3) / 2;
    int r = (x3 - x1) / 4;

    
    drawCircleMidpoint(xc, yc, r);
    drawCircleBresenham(xc + 250, yc, r);
}

int main() {
    int choice;

   
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    printf("Menu:\n");
    printf("1. Draw a circle using Midpoint algorithm\n");
    printf("2. Draw a circle using Bresenham's algorithm\n");
    printf("3. Draw a different object using both algorithms\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                int xc, yc, r;
                printf("Enter circle parameters (xc yc r): ");
                scanf("%d%d%d", &xc, &yc, &r);
                drawCircleMidpoint(xc, yc, r);
                break;

            case 2:
                
                printf("Enter circle parameters (xc yc r): ");
                scanf("%d%d%d", &xc, &yc, &r);
                drawCircleBresenham(xc, yc, r);
                break;

            case 3:
              
                drawDifferentObject();
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
