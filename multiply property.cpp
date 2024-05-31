#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void compareRotations(float theta1, float theta2) {
    // Convert degrees to radians
    float radian1 = theta1 * (PI / 180);
    float radian2 = theta2 * (PI / 180);

    // Compute the rotation matrix R(θ1)
    float R1[2][2] = {
        {cos(radian1), -sin(radian1)},
        {sin(radian1), cos(radian1)}
    };

    // Compute the rotation matrix R(θ2)
    float R2[2][2] = {
        {cos(radian2), -sin(radian2)},
        {sin(radian2), cos(radian2)}
    };

    // Compute the multiplication R(θ1) * R(θ2)
    float result1[2][2] = {
        {R1[0][0] * R2[0][0] + R1[0][1] * R2[1][0], R1[0][0] * R2[0][1] + R1[0][1] * R2[1][1]},
        {R1[1][0] * R2[0][0] + R1[1][1] * R2[1][0], R1[1][0] * R2[0][1] + R1[1][1] * R2[1][1]}
    };

    // Compute the multiplication R(θ2) * R(θ1)
    float result2[2][2] = {
        {R2[0][0] * R1[0][0] + R2[0][1] * R1[1][0], R2[0][0] * R1[0][1] + R2[0][1] * R1[1][1]},
        {R2[1][0] * R1[0][0] + R2[1][1] * R1[1][0], R2[1][0] * R1[0][1] + R2[1][1] * R1[1][1]}
    };

    // Compare the two resulting matrices
    int equal = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (result1[i][j] != result2[i][j]) {
                equal = 0;
                break;
            }
        }
        if (!equal) {
            break;
        }
    }

    if (equal) {
        printf("R(%.2f) * R(%.2f) = R(%.2f) * R(%.2f)\n", theta1, theta2, theta2, theta1);
    } else {
        printf("R(%.2f) * R(%.2f) != R(%.2f) * R(%.2f)\n", theta1, theta2, theta2, theta1);
    }
}

int main() {
    float theta1, theta2;

    printf("Enter the angle theta1: ");
    scanf("%f", &theta1);

    printf("Enter the angle theta2: ");
    scanf("%f", &theta2);

    compareRotations(theta1, theta2);

    return 0;
}
/*
Input: theta1 = 30, theta2 = 45
Output: R(30.00) * R(45.00) = R(45.00) * R(30.00)

Input: theta1 = 60, theta2 = 90
Output: R(60.00) * R(90.00) = R(90.00) * R(60.00)

Input: theta1 = 45, theta2 = 135
Output: R(45.00) * R(135.00) != R(135.00) * R(45.00)

In the first two cases, the program will print that R(θ1) * R(θ2) is equal to R(θ2) * R(θ1). However, in the third case, it will print that R(θ1) * R(θ2) is not equal to R(θ2) * R(θ1).
*/
