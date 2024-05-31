
#include <stdio.h>
#include <graphics.h>

void drawMidPointCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 1 - r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0)
        {
            d += 2 * x + 3;
        }
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

void drawBresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int option, xc, yc, r;
    printf("Choose an option: \n");
    printf("1. Draw a bear using Mid-Point Circle Drawing Algorithm.\n");
    printf("2. Draw a bear using Bresenham Circle Drawing Algorithm.\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        xc = 250;
        yc = 250;
        r = 100;
        drawMidPointCircle(xc, yc, r);
        drawMidPointCircle(xc - 75, yc - 75, r / 3);
        drawMidPointCircle(xc + 75, yc - 75, r / 3);
        drawMidPointCircle(xc + 0, yc + 0, r / 6);

        drawMidPointCircle(xc - 45, yc + -45, r / 10);
        drawMidPointCircle(xc + 45, yc - 45, r / 10);
        // putpixel(xc - 50, yc + 50, WHITE);
        // putpixel(xc + 50, yc + 50, WHITE);
        break;
    case 2:
        xc = 250;
        yc = 250;
        r = 100;
        drawBresenhamCircle(xc, yc, r);
        drawBresenhamCircle(xc - 75, yc - 75, r / 3);
        drawBresenhamCircle(xc + 75, yc - 75, r / 3);
        drawMidPointCircle(xc + 0, yc + 0, r / 6);

        drawMidPointCircle(xc - 45, yc + -45, r / 10);
        drawMidPointCircle(xc + 45, yc - 45, r / 10);
        /*putpixel(xc - 50, yc + 50, WHITE);
        putpixel(xc + 50, yc + 50, WHITE);
        putpixel(xc - 25, yc - 25, WHITE);
        putpixel(xc + 25, yc - 25, WHITE);
        putpixel(xc - 25, yc - 75, WHITE);
        putpixel(xc + 25, yc - 75, WHITE);
        putpixel(xc - 75, yc - 25, WHITE);
        putpixel(xc + 75, yc - 25, WHITE);*/
        break;
    default:
        printf("Invalid option chosen.");
    }

    // delay(5000);
    getch();
    closegraph();
    return 0;
}
