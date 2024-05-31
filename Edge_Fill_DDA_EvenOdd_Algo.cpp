#include <graphics.h>
#include <stdlib.h>

// Define a linked list node to store pixel coordinates
typedef struct Pixel
{
    int x;
    int y;
    struct Pixel *next;
} Pixel;

// Define a stack to store pixels
typedef struct Stack
{
    Pixel *top;
} Stack;

// Push a pixel onto the stack
void push(Stack *stack, int x, int y)
{
    Pixel *pixel = (Pixel*) malloc(sizeof(Pixel));
    pixel->x = x;
    pixel->y = y;
    pixel->next = stack->top;
    stack->top = pixel;
}

// Pop a pixel from the stack
Pixel* pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }
    Pixel *pixel = stack->top;
    stack->top = stack->top->next;
    return pixel;
}

// Check if a pixel is within the polygon
int insidePolygon(int x, int y, int *polyX, int *polyY, int numVertices)
{
    int i, j, c = 0;
    for (i = 0, j = numVertices-1; i < numVertices; j = i++)
    {
        if (((polyY[i]>y) != (polyY[j]>y)) &&
                (x < (polyX[j]-polyX[i]) * (y-polyY[i]) / (polyY[j]-polyY[i]) + polyX[i]) )
            c = !c;
    }
    return c;
}

// Draw a line using DDA algorithm
void drawLineDDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, i;
    float x = x1, y = y1, xIncrement, yIncrement;

    if(abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    xIncrement = dx / (float) steps;
    yIncrement = dy / (float) steps;

    for(i = 0; i < steps; i++)
    {
        x += xIncrement;
        y += yIncrement;
        putpixel(x, y, WHITE);
    }
}

// Fill the polygon using edge fill algorithm
void fillPolygon(int seedX, int seedY, int *polyX, int *polyY, int numVertices)
{
    Stack stack;
    stack.top = NULL;

    push(&stack, seedX, seedY);

    while(stack.top != NULL)
    {
        Pixel *pixel = pop(&stack);
        int x = pixel->x;
        int y = pixel->y;

        if(getpixel(x, y) == BLACK && insidePolygon(x, y, polyX, polyY, numVertices))
        {
            putpixel(x, y, WHITE);

            push(&stack, x+1, y);
            push(&stack, x-1, y);
            push(&stack, x, y+1);
            push(&stack, x, y-1);
        }

        free(pixel);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int numVertices, seedX, seedY, i;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int polyX[numVertices], polyY[numVertices];

    printf("Enter the polygon coordinates:\n");
    for (i = 0; i < numVertices; i++)
    {
        printf("Vertex %d: ", i+1);
        scanf("%d %d", &polyX[i], &polyY[i]);
    }

    printf("Enter the seed point: ");
    scanf("%d %d", &seedX, &seedY);

    // Draw the polygon
    for (i = 0; i < numVertices; i++)
    {
        int j = (i+1) % numVertices;
        drawLineDDA(polyX[i], polyY[i], polyX[j], polyY[j]);
    }

    // Fill the polygon using edge fill algorithm
    fillPolygon(seedX, seedY, polyX, polyY, numVertices);

    getch();
    closegraph();
    return 0;
}


