#include <graphics.h>
#include <math.h>
#include <stdio.h>

void drawFractalLine(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        line(x1, y1, x2, y2);
    } else {
        int deltaX = x2 - x1;
        int deltaY = y2 - y1;

        int xA = x1 + deltaX / 3;
        int yA = y1 + deltaY / 3;

        int xB = xA + (int)(deltaX * cos(M_PI / 3) + deltaY * sin(M_PI / 3));
        int yB = yA + (int)(deltaY * cos(M_PI / 3) - deltaX * sin(M_PI / 3));

        int xC = x1 + 2 * deltaX / 3;
        int yC = y1 + 2 * deltaY / 3;

        drawFractalLine(x1, y1, xA, yA, depth - 1);
        drawFractalLine(xA, yA, xB, yB, depth - 1);
        drawFractalLine(xB, yB, xC, yC, depth - 1);
        drawFractalLine(xC, yC, x2, y2, depth - 1);
    }
}
void drawTriadicKochCurve(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        line(x1, y1, x2, y2);
    } else {
        int deltaX = x2 - x1;
        int deltaY = y2 - y1;

        int xA = x1 + deltaX / 3;
        int yA = y1 + deltaY / 3;

        int xC = x2 - deltaX / 3;
        int yC = y2 - deltaY / 3;

        int xB = xA + (xC - xA) / 2 - (yC - yA) * sqrt(3) / 2;
        int yB = yA + (yC - yA) / 2 + (xC - xA) * sqrt(3) / 2;

        drawTriadicKochCurve(x1, y1, xA, yA, depth - 1);
        drawTriadicKochCurve(xA, yA, xB, yB, depth - 1);
        drawTriadicKochCurve(xB, yB, xC, yC, depth - 1);
        drawTriadicKochCurve(xC, yC, x2, y2, depth - 1);
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int choice, depth;
    int x1, y1, x2, y2;

    do {
        printf("Fractal Line Menu\n");
        printf("1. Draw Koch Curve\n");
        printf("2. Draw Triadic Koch Curve\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the starting point (x1, y1): ");
                scanf("%d%d", &x1, &y1);
                printf("Enter the ending point (x2, y2): ");
                scanf("%d%d", &x2, &y2);
                printf("Enter the depth: ");
                scanf("%d", &depth);

                drawFractalLine(x1, y1, x2, y2, depth);
                break;

            case 2:
                printf("Enter the starting point (x1, y1): ");
                scanf("%d%d", &x1, &y1);
                printf("Enter the ending point (x2, y2): ");
                scanf("%d%d", &x2, &y2);
                printf("Enter the depth: ");
                scanf("%d", &depth);

                drawTriadicKochCurve(x1, y1, x2, y2, depth);
                break;

            case 3:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    closegraph();
    return 0;
}

