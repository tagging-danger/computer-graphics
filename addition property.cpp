#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void multiplyRotations(float theta1, float theta2) {
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
    float result[2][2] = {
        {R1[0][0] * R2[0][0] + R1[0][1] * R2[1][0], R1[0][0] * R2[0][1] + R1[0][1] * R2[1][1]},
        {R1[1][0] * R2[0][0] + R1[1][1] * R2[1][0], R1[1][0] * R2[0][1] + R1[1][1] * R2[1][1]}
    };

    // Compute the resulting angle
    float resultAngle = atan2(result[1][0], result[0][0]) * (180 / PI);

    printf("R(%.2f) * R(%.2f) = R(%.2f)\n", theta1, theta2, resultAngle);
}

int main() {
    float theta1, theta2;

    printf("Enter the angle theta1: ");
    scanf("%f", &theta1);

    printf("Enter the angle theta2: ");
    scanf("%f", &theta2);

    multiplyRotations(theta1, theta2);

    return 0;
}

