#ifndef BLOCK_H
#define BLOCK_H

class block
{
public:

    int x, y;
    void show()
    {
        setfillstyle(1, 15);
        bar(x, y, x + 20, y + 100);

    }

};



#endif // BLOCK_H
