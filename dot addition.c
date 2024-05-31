#include <stdio.h>
#include <math.h>

// Function to calculate the rotation matrix
void rotate(double theta, double matrix[2][2]) {
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);

    // Initialize the rotation matrix
    matrix[0][0] = cos_theta;
    matrix[0][1] = -sin_theta;
    matrix[1][0] = sin_theta;
    matrix[1][1] = cos_theta;
}

// Function to multiply two 2x2 matrices
void multiplyMatrix(double matrix1[2][2], double matrix2[2][2], double result[2][2]) {
    int i, j, k;

    // Perform matrix multiplication
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (k = 0; k < 2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    double theta1, theta2;
    double rotationMatrix1[2][2];
    double rotationMatrix2[2][2];
    double resultMatrix[2][2];

    printf("Enter the value of theta1 in radians: ");
    scanf("%lf", &theta1);

    printf("Enter the value of theta2 in radians: ");
    scanf("%lf", &theta2);

    // Calculate the rotation matrices for theta1 and theta2
    rotate(theta1, rotationMatrix1);
    rotate(theta2, rotationMatrix2);

    // Multiply the rotation matrices
    multiplyMatrix(rotationMatrix1, rotationMatrix2, resultMatrix);

    // Display the result matrix
    printf("Resulting rotation matrix:\n");
    printf("[%.2lf  %.2lf]\n", resultMatrix[0][0], resultMatrix[0][1]);
    printf("[%.2lf  %.2lf]\n", resultMatrix[1][0], resultMatrix[1][1]);

    return 0;
}
