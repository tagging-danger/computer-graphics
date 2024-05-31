#include <graphics.h>
#include <stdlib.h>

// Function to draw a fractal line
void drawCoastline(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        line(x1, y1, x2, y2);
    } else {
        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;
        int displacement = rand() % (2 * depth) - depth;

        xm += displacement;

        drawCoastline(x1, y1, xm, ym, depth - 1);
        drawCoastline(xm, ym, x2, y2, depth - 1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, depth;

    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the depth of the fractal line: ");
    scanf("%d", &depth);

    drawCoastline(x1, y1, x2, y2, depth);

    getch();
    closegraph();
    return 0;
}

