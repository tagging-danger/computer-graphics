#include <stdio.h>

// Structure representing a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Function to perform reflection about the line y=x
void reflectAboutYEqualsX(Point* point) {
    double temp = point->x;
    point->x = point->y;
    point->y = temp;
}

// Function to perform reflection about the X-axis
void reflectAboutXAxis(Point* point) {
    point->y = -(point->y);
}

// Function to perform counterclockwise rotation of 90 degrees (π/2 radians)
void rotate90Degrees(Point* point) {
    double temp = point->x;
    point->x = -(point->y);
    point->y = temp;
}

int main() {
    Point point;

    // Read the initial coordinates of the point
    printf("Enter the initial x-coordinate: ");
    scanf("%lf", &point.x);
    printf("Enter the initial y-coordinate: ");
    scanf("%lf", &point.y);

    // Perform the reflection about Y=X
    reflectAboutYEqualsX(&point);

    // Perform the reflection about X-axis
    reflectAboutXAxis(&point);

    // Perform the counterclockwise rotation of 90 degrees
    rotate90Degrees(&point);

    // Display the final coordinates
    printf("Final coordinates: (%.2lf, %.2lf)\n", point.x, point.y);

    return 0;
}
