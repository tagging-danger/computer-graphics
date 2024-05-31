#include <graphics.h>
#include <stdlib.h>

// Function to draw a fractal surface
void drawMountain(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        line(x1, y1, x2, y2);
    } else {
        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;
        int displacement = rand() % (2 * depth) - depth;

        ym += displacement;

        drawMountain(x1, y1, xm, ym, depth - 1);
        drawMountain(xm, ym, x2, y2, depth - 1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 50, y1 = 350, x2 = 550, y2 = 350;
    int depth;

    printf("Enter the depth of the fractal surface: ");
    scanf("%d", &depth);

    drawMountain(x1, y1, x2, y2, depth);

    getch();
    closegraph();
    return 0;
}
