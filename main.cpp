#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <sstream>
#include "block.h"
#include "ball.h"

using namespace std;
int width = 900;
int height = 600;
int page = 0;
int left_scr = 0;
int right_scr = 0;
int main()
{
    srand(time(0));
    initwindow(width, height, "PONG");
    block left, right;
    ball ball;
    left.x = 0;
    left.y = height/2 - 50;
    right.x = width - 20;
    right.y = height/2 - 50;
    int seg;
    for(;;)
    {
        setactivepage(page);
        setvisualpage(1 - page);
        setfillstyle(1, 0);
        bar(0,0,width,height);

        //Moving paddles based on the keyboard input
        if(GetAsyncKeyState('W') && left.y > 0) left.y -= 15;
        if(GetAsyncKeyState('S') && left.y < height - 100) left.y += 15;
        if(GetAsyncKeyState(VK_UP) && right.y > 0) right.y -= 15;
        if(GetAsyncKeyState(VK_DOWN) && right.y < height - 100) right.y += 15;

        setfillstyle(1, 15);
        setlinestyle(1, 0, 3);
        line(width/2, 0, width/2, height);
        left.show();
        right.show();
        setlinestyle(0, 0, 0);

        //score before drawing ball
        char c[4 + sizeof(char)];
        sprintf(c, "%d", left_scr);
        settextjustify(1, 1);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
        setcolor(15);
        outtextxy(210, 50, c);
        sprintf(c, "%d", right_scr);
        outtextxy(670, 50, c);
        page = 1 - page;

        //
        ball.show();
        ball.update();


        if(ball.x <= left.x + 30)
        {
            if((ball.y <= left.y + 100) && (ball.y >= left.y))
            {
             seg = ball.checksegment(left.y);
            ball.rebound(0, seg);
            }
            if(ball.x < 0)
                right_scr++;
        }
        if(ball.x + 12 >= right.x)
        {
            if((ball.y < right.y + 100) && (ball.y >= right.y))
            {
            seg = ball.checksegment(right.y);
            ball.rebound(1, seg);
            }
            if(ball.x > width)
        left_scr++;
        }
        if(ball.x < 0 || ball.x > width) ball.reset();
        if(ball.y < 10 ) ball.angle *= -1;
        if(ball.y > height - 10) ball.angle *= -1;
        delay(20);
    }
    getch();

    return 0;
}
