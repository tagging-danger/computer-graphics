#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void bezierCurve(int x[4], int y[4]) {
    double t;
    for (t = 0.0; t < 1.0; t += 0.0005) {
        double xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
        double yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
        putpixel(xt, yt, WHITE);
    }
}

void kochCurve(int x1, int y1, int x2, int y2, int n) {
    if (n == 0) {
        line(x1, y1, x2, y2);
    } else {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int x3 = x1 + dx / 3;
        int y3 = y1 + dy / 3;
        int x4 = x1 + 2 * dx / 3;
        int y4 = y1 + 2 * dy / 3;
        int x5 = x1 + dx / 2 - dy / 2;
        int y5 = y1 + dx / 2 + dy / 2;

        kochCurve(x1, y1, x3, y3, n - 1);
        kochCurve(x3, y3, x5, y5, n - 1);
        kochCurve(x5, y5, x4, y4, n - 1);
        kochCurve(x4, y4, x2, y2, n - 1);
    }
}

void fractalLine(int x1, int y1, int x2, int y2, int n) {
    if (n == 0) {
        line(x1, y1, x2, y2);
    } else {
        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;
        int dx = x2 - x1;
        int dy = y2 - y1;
        int xn = xm - dy / 4;
        int yn = ym + dx / 4;

        fractalLine(x1, y1, xn, yn, n - 1);
        fractalLine(xn, yn, x2, y2, n - 1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int choice;
    printf("Choose the curve to draw:\n");
    printf("1. Four-point Bezier curve\n");
    printf("2. Triadic Koch Curve\n");
    printf("3. Fractal Line\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int x[4], y[4];
            printf("Enter the coordinates of the four control points (x1, y1, x2, y2, x3, y3, x4, y4): ");
            scanf("%d %d %d %d %d %d %d %d", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);
            bezierCurve(x, y);
            break;
        }
        case 2: {
            int x1, y1, x2, y2, n;
            printf("Enter the coordinates of the two endpoints (x1, y1, x2, y2): ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("Enter the number of iterations: ");
            scanf("%d", &n);
            kochCurve(x1, y1, x2, y2, n);
            break;
        }
        case 3: {
            int x1, y1, x2, y2, n;
            printf("Enter the coordinates of the two endpoints (x1, y1, x2, y2): ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("Enter the number of iterations: ");
            scanf("%d", &n);
            fractalLine(x1, y1, x2, y2, n);
            break;
        }
        default:
            printf("Invalid choice.");
            break;
    }

    getch();
    closegraph();
    return 0;
}
