#ifndef STICK_H
#define STICK_H
#include <graphics.h>

class stick
{
    public:
        int x, y;

    void show()
    {

    bar(x, y, x + 20,y + 50);

    }

};

#endif // BAR_H
