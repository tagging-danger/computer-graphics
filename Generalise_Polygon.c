#include <stdio.h>
#include <graphics.h>

#define MAX_POINTS 10

// Structure to represent a point
struct Point {
    int x;
    int y;
};

// Function to draw a polygon
void drawPolygon(struct Point* points, int numPoints) {
    int i;
    for (i = 0; i < numPoints - 1; i++) {
        line(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
    line(points[numPoints - 1].x, points[numPoints - 1].y, points[0].x, points[0].y);
}

// Function to implement the Generalized Polygon Clipping algorithm
void polygonClipping(struct Point* subjectPolygon, int subjectSize, struct Point* clipPolygon, int clipSize) {
    struct Point resultPolygon[MAX_POINTS];
    int i, j, k;
    int resultSize = 0;

    for (i = 0; i < subjectSize; i++) {
        int current = (i + 1) % subjectSize;
        int prev = (i + subjectSize - 1) % subjectSize;
        struct Point currentPoint = subjectPolygon[current];
        struct Point prevPoint = subjectPolygon[prev];

        int insideClip = 0;
        struct Point intersectionPoint;

        for (j = 0; j < clipSize; j++) {
            struct Point clipStart = clipPolygon[j];
            struct Point clipEnd = clipPolygon[(j + 1) % clipSize];

            int clipResult = calculateIntersection(prevPoint, currentPoint, clipStart, clipEnd, &intersectionPoint);

            if (clipResult == 0) {
                if (!insideClip) {
                    resultPolygon[resultSize++] = currentPoint;
                }
                insideClip = 1;
                resultPolygon[resultSize++] = intersectionPoint;
            } else if (clipResult == 1) {
                if (insideClip) {
                    resultPolygon[resultSize++] = intersectionPoint;
                }
                insideClip = 0;
            }
        }
    }

    cleardevice();
    drawPolygon(resultPolygon, resultSize);
}

// Function to calculate the intersection of two line segments
int calculateIntersection(struct Point a1, struct Point a2, struct Point b1, struct Point b2, struct Point* intersectionPoint) {
    int dx1 = a2.x - a1.x;
    int dy1 = a2.y - a1.y;
    int dx2 = b2.x - b1.x;
    int dy2 = b2.y - b1.y;

    int determinant = dx1 * dy2 - dy1 * dx2;

    if (determinant == 0) {
        return 0; // Lines are parallel
    }

    int xdiff = a1.x - b1.x;
    int ydiff = a1.y - b1.y;

    double t1 = (double)(dx2 * ydiff - dy2 * xdiff) / determinant;
    double t2 = (double)(dx1 * ydiff - dy1 * xdiff) / determinant;

    if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
        intersectionPoint->x = a1.x + t1 * dx1;
                intersectionPoint->y = a1.y + t1 * dy1;
        return 0; // Intersection point found
    }

    return -1; // Lines do not intersect
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    struct Point subjectPolygon[MAX_POINTS];
    struct Point clipPolygon[MAX_POINTS];
    int subjectSize, clipSize;

    // Menu-driven loop
    int choice;
    do {
        cleardevice();

        printf("---------- Generalized Polygon Clipping ----------\n");
        printf("1. Enter subject polygon\n");
        printf("2. Enter clip polygon\n");
        printf("3. Perform polygon clipping\n");
        printf("4. Exit\n");
        printf("-------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of vertices for the subject polygon: ");
                scanf("%d", &subjectSize);
                printf("Enter the coordinates of the subject polygon (x, y):\n");
                for (int i = 0; i < subjectSize; i++) {
                    scanf("%d%d", &subjectPolygon[i].x, &subjectPolygon[i].y);
                }
                break;

            case 2:
                printf("Enter the number of vertices for the clip polygon: ");
                scanf("%d", &clipSize);
                printf("Enter the coordinates of the clip polygon (x, y):\n");
                for (int i = 0; i < clipSize; i++) {
                    scanf("%d%d", &clipPolygon[i].x, &clipPolygon[i].y);
                }
                break;

            case 3:
                if (subjectSize > 0 && clipSize > 0) {
                    polygonClipping(subjectPolygon, subjectSize, clipPolygon, clipSize);
                    delay(2000);
                } else {
                    printf("Please enter the subject and clip polygons first!\n");
                    delay(1000);
                }
                break;

            case 4:
                closegraph();
                return 0;

            default:
                printf("Invalid choice. Please try again!\n");
                delay(1000);
        }
    } while (1);

    closegraph();
    return 0;
}

