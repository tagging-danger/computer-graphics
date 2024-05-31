void drawLine(int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float) dx / (float) steps;
    float yIncrement = (float) dy / (float) steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), color);
        x += xIncrement;
        y += yIncrement;
    }
}
