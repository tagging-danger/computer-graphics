#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <stdio.h> // Include stdio.h for sprintf
const int windowWidth = 600;
const int windowHeight = 600;
const int centerX = windowWidth / 2;
const int centerY = windowHeight / 2;
const int clockRadius = 160;
void drawClockFace()
{
    // Draw clock outline
    circle(centerX, centerY, clockRadius);
    // Draw hour marks
    for (int i = 1; i <= 12; ++i)
    {
        int markAngle = 90 - i * 30; // Angle for each hour mark starting from 12 o'clock
        int markX = centerX + (clockRadius - 20) * cos(markAngle * 3.14 / 180);
        int markY = centerY - (clockRadius - 20) * sin(markAngle * 3.14 / 180);
        char hourText[3];
        sprintf(hourText, "%d", i);
        outtextxy(markX - 5, markY - 5, hourText); // Display hour number near the mark
    }
}
void drawHourHand(int hour, int minute)
{
    float angle = 3.14 / 2 - (hour % 12 + minute / 60.0) * 30 * 3.14 / 180;
    int hourHandX = centerX + 0.5 * clockRadius * cos(angle);
    int hourHandY = centerY - 0.5 * clockRadius * sin(angle);
    line(centerX, centerY, hourHandX, hourHandY);
}
void drawMinuteHand(int minute, int second)
{
    float angle = 3.14 / 2 - (minute + second / 60.0) * 6 * 3.14 / 180;
    int minuteHandX = centerX + 0.8 * clockRadius * cos(angle);
    int minuteHandY = centerY - 0.8 * clockRadius * sin(angle);
    line(centerX, centerY, minuteHandX, minuteHandY);
}
void drawSecondHand(int second)
{
    float angle = 3.14 / 2 - second * 6 * 3.14 / 180;
    int secondHandX = centerX + 0.9 * clockRadius * cos(angle);
    int secondHandY = centerY - 0.9 * clockRadius * sin(angle);
    line(centerX, centerY, secondHandX, secondHandY);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    // Set the time to 9:00 PM
    int hour = 9;
    int minute = 0;
    int second = 0;
    while (!kbhit())
    {
        cleardevice();
        drawClockFace();
        drawHourHand(hour, minute);
        drawMinuteHand(minute, second);
        drawSecondHand(second);
        getch(); // Update clock every second
        second++;
        // Adjust time
        if (second >= 60)
        {
            second = 0;
            minute++;
            if (minute >= 60)
            {
                minute = 0;
                hour++;
                if (hour >= 24)
                {
                    hour = 0;
                }
            }
        }
    }
    closegraph();
    return 0;
}