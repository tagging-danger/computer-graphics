#include <stdio.h>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xIncrement, yIncrement;
    float x = x1, y = y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = dx / (float) steps;
    yIncrement = dy / (float) steps;

    putpixel(round(x), round(y), WHITE);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE);
    }
}

void edgeFill(int x[], int y[], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        drawLineDDA(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    for (i = 0; i < getmaxx(); i++) {
        for (j = 0; j < getmaxy(); j++) {
            if (getpixel(i, j) == WHITE) {
                putpixel(i, j, RED);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int n, i;

    printf("Enter the number of sides of the convex polygon: ");
    scanf("%d", &n);

    int x[n], y[n];

    printf("Enter the coordinates of the polygon vertices:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    initgraph(&gd, &gm, "");

    edgeFill(x, y, n);

    delay(5000);
    closegraph();

    return 0;
}
