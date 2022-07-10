#ifndef BALL_H
#define BALL_H
#include <graphics.h>
#include <math.h>

float random_angle()
{
    int q;
    for(; ;)
    {
        q = rand()%360;
        q /= 10;
        q *= 10;
        if(((q  > 70) && (q < 110)) || ((q > 250) && (q < 290))) continue;
        else break;
    }
    return (q * 0.017453) ;

}

class ball
{
public:
    int x, y, xv, yv;
    int speed = 17;
    int width = 900;
    int height = 600;
    float angle;
    void show()
    {
        setfillstyle(1, 15);
        fillellipse(x, y, 10, 10);


    }
    void update()
    {
        xv = speed * cos(angle);
        yv = speed * sin(angle);
        x = x + xv;
        y = y + yv;
    }
    void rebound(int a, int seg)
    {
            int left_rebound[] = {-50, -35, -25, -10, 10, 25, 35, 50};
            int right_rebound[] = {-130, -145, -155, -190, 190, 155, 145, 130};
        if(a == 0) angle = 0.017453 * left_rebound[seg];
        else angle = 0.017453 * right_rebound[seg];


    }

    void reset()
    {
        x = width/ 2;
        y = height / 2;
        angle = random_angle();
        xv = speed * cos(angle);
        yv = speed * sin(angle);
    }

    int checksegment(int paddle_y)
    {
        int segment;
        for(int i = 0; i < 8; i++)
        {
            int x = (paddle_y + i*(100/8));
            if((y >= x) && (y < x + (100/8)))
            {
                segment = i;
                break;
            }
        }
        return segment;

    }
    ball()
    {
        x = width/ 2;
        y = height / 2;
        angle = random_angle();
        xv = speed * cos(angle);
        yv = speed * sin(angle);

    }


};

#endif // BALL_H
