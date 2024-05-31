#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx, dy, steps, k;
    float x, y, x_inc, y_inc;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    x_inc = (float)dx / steps;
    y_inc = (float)dy / steps;

    x = x1;
    y = y1;

    for (k = 0; k < steps; k++) {
        x += x_inc;
        y += y_inc;
        putpixel(round(x), round(y), YELLOW);
    }
}

int main() {
    int x[4], y[4], i;
    double put_x, put_y, t;
    int gr = DETECT, gm;
    initgraph(&gr, &gm, "C:\\TURBOC3\\BGI");

    printf("\n****** Bezier Curve ***********");
    printf("\nPlease enter x and y coordinates:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d%d", &x[i], &y[i]);
        putpixel(x[i], y[i], 3);  // Control Points
    }

    // Joining the points with lines
    for (i = 0; i < 3; i++) {
        drawLine(x[i], y[i], x[i + 1], y[i + 1]);
    }

    // Drawing the Bezier curve
    for (t = 0.0; t <= 1.0; t += 0.001) {
        put_x = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * t * t * (1 - t) * x[2] + pow(t, 3) * x[3];
        put_y = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * t * t * (1 - t) * y[2] + pow(t, 3) * y[3];
        putpixel(put_x, put_y, RED);
    }

    getch();
    closegraph();
    return 0;
}
