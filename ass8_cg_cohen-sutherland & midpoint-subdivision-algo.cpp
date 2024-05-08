#include <graphics.h>
#include <conio.h>
#include <iostream.h> // For Turbo C++, use iostream.h instead of iostream

// Define true
#define true 1

// Define region codes for Cohen-Sutherland algorithm
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Define the window coordinates
#define X_MIN 100
#define Y_MIN 100
#define X_MAX 500
#define Y_MAX 400

// Function to compute region code for a point (x, y)
int computeCode(double x, double y) {
    int code = INSIDE;

    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;
    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;

    return code;
}

// Function to clip the line using Cohen-Sutherland algorithm
void cohenSutherland(double &x1, double &y1, double &x2, double &y2) {
    int code1, code2;
    double x, y;
    int code_out;

    code1 = computeCode(x1, y1);
    code2 = computeCode(x2, y2);

    while (true) {
        if (!(code1 | code2)) {
            // Bitwise OR is 0. Trivially accept and get out of loop
            break;
        } else if (code1 & code2) {
            // Bitwise AND is not 0. Trivially reject and get out of loop
            break;
        } else {
            // Calculate intersection line to clip
            code_out = code1 ? code1 : code2;

            if (code_out & TOP) {           // point is above the clip rectangle
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (code_out & BOTTOM) { // point is below the rectangle
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (code_out & RIGHT) {  // point is to the right of rectangle
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (code_out & LEFT) {   // point is to the left of rectangle
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            // Update the point after clipping
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
}

// Function to clip the line using Midpoint subdivision algorithm
void midPointSubdivision(double &x1, double &y1, double &x2, double &y2) {
    int x1_new = x1, y1_new = y1, x2_new = x2, y2_new = y2;

    // Determine the region codes for both endpoints
    int code1 = computeCode(x1_new, y1_new);
    int code2 = computeCode(x2_new, y2_new);

    while (true) {
        if (!(code1 | code2)) {
            // Trivially accept if both endpoints are inside the window
            break;
        } else if (code1 & code2) {
            // Trivially reject if both endpoints are outside the same region
            break;
        } else {
            // Calculate midpoint
            double xm = (x1_new + x2_new) / 2;
            double ym = (y1_new + y2_new) / 2;

            // Determine the region code for the midpoint
            int code_m = computeCode(xm, ym);

            // Check if the midpoint is inside the window
            if (code_m == INSIDE) {
                // Move the endpoint which is outside the window to the midpoint
                if (code1 != INSIDE) {
                    x1_new = xm;
                    y1_new = ym;
                    code1 = computeCode(x1_new, y1_new);
                } else {
                    x2_new = xm;
                    y2_new = ym;
                    code2 = computeCode(x2_new, y2_new);
                }
            } else {
                // Choose the endpoint to be replaced by the midpoint
                // If the first endpoint is inside, replace it; otherwise, replace the second endpoint
                if (code1 != INSIDE) {
                    x1_new = xm;
                    y1_new = ym;
                    code1 = computeCode(x1_new, y1_new);
                } else {
                    x2_new = xm;
                    y2_new = ym;
                    code2 = computeCode(x2_new, y2_new);
                }
            }
        }
    }

    // Update the original endpoints with the new clipped endpoints
    x1 = x1_new;
    y1 = y1_new;
    x2 = x2_new;
    y2 = y2_new;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Define the coordinates of the window
    int x1, y1, x2, y2;

    // Draw the window using rectangle function
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Prompt user for line coordinates
    cout << "Enter line coordinates for Cohen-Sutherland algorithm (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the original line
    line(x1, y1, x2, y2);

    // Clip the line using Cohen-Sutherland algorithm
    cohenSutherland(x1, y1, x2, y2);

    // Draw the clipped line using Cohen-Sutherland algorithm
    setcolor(RED); // Change color for visualization
    line(x1, y1, x2, y2);

    // Prompt user for line coordinates again for Midpoint subdivision algorithm
    cout << "Enter line coordinates for Midpoint subdivision algorithm (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the original line
    line(x1, y1, x2, y2);

    // Clip the line using Midpoint subdivision algorithm
    midPointSubdivision(x1, y1, x2, y2);

    // Draw the clipped line using Midpoint subdivision algorithm
    setcolor(GREEN); // Change color for visualization
    line(x1, y1, x2, y2);

    // Wait for a key press before closing the window
    getch();
    closegraph();
    return 0;
}
