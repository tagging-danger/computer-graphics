#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

void flood(int, int, int, int);
void boundaryFill4(int, int, int, int);
void drawPolygon(int[][2], int);
void fenceFill(int, int, int, int);
void scanlineFill(int[][2], int);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int choice;
    printf("Choose algorithm:\n");
    printf("1. Flood Fill Algorithm\n");
    printf("2. Boundary Fill Algorithm\n");
    printf("3. Fence Fill Algorithm\n");
    printf("4. Scanline Fill Algorithm\n");
    scanf("%d", &choice);
    getchar(); // Consume newline character
    switch (choice) {
        case 1: {
            // Flood Fill Algorithm
            rectangle(50, 50, 250, 250);
            flood(55, 55, 10, 0);
            break;
        }
        case 2: {
            // Boundary Fill Algorithm
            int x = 250, y = 200, radius = 50;
            circle(x, y, radius);
            boundaryFill4(x, y, 6, 15);
            break;
        }
        case 3: {
            // Fence Fill Algorithm
            int vertices[][2] = {{100, 100}, {200, 100}, {200, 200}, {100, 200}};
            int n = sizeof(vertices) / sizeof(vertices[0]);
            drawPolygon(vertices, n);
            int start_x = 150, start_y = 150;
            fenceFill(start_x, start_y, 6, 15); // Fill color: 6, Boundary color: 15
            break;
        }
        case 4: {
            // Scanline Fill Algorithm
            int n, i;
            printf("\nEnter no. of edges of polygon: ");
            scanf("%d", &n);
            getchar(); // Consume newline character
            int a[20][2];
            printf("\nEnter coordinates of polygon:\n");
            for(i = 0; i < n; i++) {
                printf("X%d Y%d: ", i, i);
                scanf("%d %d", &a[i][0], &a[i][1]);
                getchar(); // Consume newline character
            }
            a[n][0] = a[0][0];
            a[n][1] = a[0][1];
            scanlineFill(a, n);
            break;
        }
        default:
            printf("Invalid choice.\n");
    }
    getch();
    closegraph();
    return 0;
}

void flood(int x, int y, int fillColor, int defaultColor) {
    if (getpixel(x, y) == defaultColor) {
        delay(100);
        putpixel(x, y, fillColor);
        flood(x + 1, y, fillColor, defaultColor);
        flood(x - 1, y, fillColor, defaultColor);
        flood(x, y + 1, fillColor, defaultColor);
        flood(x, y - 1, fillColor, defaultColor);
    }
}

void boundaryFill4(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}

void drawPolygon(int vertices[][2], int n) {
    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        line(vertices[i][0], vertices[i][1], vertices[next][0], vertices[next][1]);
    }
}

void fenceFill(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        fenceFill(x + 1, y, fill_color, boundary_color);
        fenceFill(x - 1, y, fill_color, boundary_color);
        fenceFill(x, y + 1, fill_color, boundary_color);
        fenceFill(x, y - 1, fill_color, boundary_color);
    }
}

void scanlineFill(int a[][2], int n) {
    int i, j, k, gd = DETECT, gm;
    int dy, dx;
    int x, y, temp;
    int xi[20];
    float slope[20];

    clrscr();
    printf("\nEnter no. of edges of polygon: %d", n);

    for(i = 0; i < n; i++) {
        printf("\nEnter coordinates of polygon: X%d Y%d: ", i, i);
        scanf("%d %d", &a[i][0], &a[i][1]);
        getchar(); // Consume newline character
    }

    a[n][0] = a[0][0];
    a[n][1] = a[0][1];
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "c:\\tc\\bgi");

    for(i = 0; i < n; i++) {
        line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }

    getch();

    for(i = 0; i < n; i++) {
        dy = a[i + 1][1] - a[i][1];
        dx = a[i + 1][0] - a[i][0];
        if(dy == 0) {
            slope[i] = 1.0;
        }
        if(dx == 0) {
            slope[i] = 0.0;
        }
        if(dy != 0 && dx != 0) {
            slope[i] = (float)dx / dy;
        }
    }

    for(y = 0; y < 480; y++) {
        k = 0;
        for(i = 0; i < n; i++) {
            if((a[i][1] <= y && a[i + 1][1] > y) || (a[i][1] > y && a[i + 1][1] <= y)) {
                xi[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));
                k++;
            }
        }
        for(j = 0; j < k - 1; j++) {
            for(i = 0; i < k; i++) {
                if(xi[i] > xi[i + 1]) {
                    temp = xi[i];
                    xi[i] = xi[i + 1];
                    xi[i + 1] = temp;
                }
            }
        }
        setcolor(35);
        for(i = 0; i < k; i += 2) {
            line(xi[i], y, xi[i + 1] + 1, y);
            getch();
        }
    }
}
