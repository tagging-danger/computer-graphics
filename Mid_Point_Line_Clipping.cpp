#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

/*float fmin(float a, float b) {
    return (a < b) ? a : b;
}

float fmax(float a, float b) {
    return (a > b) ? a : b;
}*/
void midPointLineClipping(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {

    int dx = x2 - x1, dy = y2 - y1;
    int p[4], q[4], i;

    float t1 = 0, t2 = 1;

    p[0] = -dx; q[0] = x1 - xmin;
    p[1] = dx; q[1] = xmax - x1;
    p[2] = -dy; q[2] = y1 - ymin;
    p[3] = dy; q[3] = ymax - y1;

    for (i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0)
            return;
        if (p[i] < 0)
            t1 = fmax(t1, (float) q[i] / p[i]);
        else if (p[i] > 0)
            t2 = fmin(t2, (float) q[i] / p[i]);
    }

    if (t1 > t2)
        return;

    int x11 = x1 + t1 * dx, y11 = y1 + t1 * dy;
    int x22 = x1 + t2 * dx, y22 = y1 + t2 * dy;

    setcolor(WHITE);
    line(x1, y1, x2, y2);
    setcolor(BLUE);
    line(x11, y11, x22, y22);
}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, xmin, ymin, xmax, ymax;

    printf("Enter the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the window coordinates (xmin, ymin, xmax, ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    rectangle(xmin, ymin, xmax, ymax);
    midPointLineClipping(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}

