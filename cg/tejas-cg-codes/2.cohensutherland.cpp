// 9. Write C++ program to implement Cohen Southerland line clipping algorithm. 

#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    float X1, Y1, X2, Y2, x1, y1, x2, y2;

    cout << "Enter the coordinates of diagonal vertices X1|Y1|X2|Y2 \n";
    cin >> X1 >> Y1 >> X2 >> Y2;

    cout << "\nEnter the coordinates of vertices of lines x1,y1,x2,y2\n";
    cin >> x1 >> y1 >> x2 >> y2;

    int opcode[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}}; // [ABRL.0123]

    // Point 1
    if (y1 > Y2) opcode[0][0] = 1; // A
    if (y1 < Y1) opcode[0][1] = 1; // B
    if (x1 > X2) opcode[0][2] = 1; // R
    if (x1 < X1) opcode[0][3] = 1; // L

    // Point 2  
    if (y2 > Y2) opcode[1][0] = 1; // A
    if (y2 < Y1) opcode[1][1] = 1; // B
    if (x2 > X2) opcode[1][2] = 1; // R
    if (x2 < X1) opcode[1][3] = 1; // L

    cout << opcode[0][0] << opcode[0][1] << opcode[0][2] << opcode[0][3];
    cout << opcode[1][0] << opcode[1][1] << opcode[1][2] << opcode[1][3];

    float m;
    if ((x2 - x1) == 0)
    {
        m = 0;
    }
    else
    {
        m = (y2 - y1) / (x2 - x1);
    }

    initgraph(&gd, &gm, NULL);

    // Before clipping
    outtextxy(100, 100, "Before");
    rectangle(X1, Y1, X2, Y2);
    line(x1, y1, x2, y2);
    delay(3000);
    cleardevice();

    bool visible = true;
    for (int i = 0; i < 2; i++)
    {
        if ((opcode[0][0] & opcode[1][0]) || 
            (opcode[0][1] & opcode[1][1]) || 
            (opcode[0][2] & opcode[1][2]) || 
            (opcode[0][3] & opcode[1][3]))
        {
            visible = false;
            break;
        }
    }

    if (visible)
    {
        if (opcode[0][0] == 1)
        {
            x1 = x1 + (Y1 - y1) / m;
            y1 = Y1;
        }
        if (opcode[0][1] == 1)
        {
            x1 = x1 + (Y2 - y1) / m;
            y1 = Y2;
        }
        if (opcode[0][2] == 1)
        {
            y1 = y1 + m * (X2 - x1);
            x1 = X2;
        }
        if (opcode[0][3] == 1)
        {
            y1 = y1 + m * (X1 - x1);
            x1 = X1;
        }

        if (opcode[1][0] == 1)
        {
            x2 = x2 + (Y1 - y2) / m;
            y2 = Y1;
        }
        if (opcode[1][1] == 1)
        {
            x2 = x2 + (Y2 - y2) / m;
            y2 = Y2;
        }
        if (opcode[1][2] == 1)
        {
            y2 = y2 + (X2 - x2) * m;
            x2 = X2;
        }
        if (opcode[1][3] == 1)
        {
            y2 = y2 + m * (X1 - x2);
            x2 = X1;
        }
    }
    else
    {
        x1 = x2 = y1 = y2 = 0;
    }

    // After clipping
    outtextxy(100, 100, "After");
    rectangle(X1, Y1, X2, Y2);
    line(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
