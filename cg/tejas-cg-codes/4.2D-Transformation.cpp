// ) Write C++ program to draw 2-D object and perform following basic 
// transformations, Scaling, Translation c) Rotation. Apply the concept of 
// operator overloading.
#include <iostream>  
#include <graphics.h>  
#include <math.h>  
  
using namespace std;  
  
class Transformation {  
public:  
    int x1, x2, y1, y2;  
    void accept() {  
        cout << "Enter coordinate x1 : ";  
        cin >> x1;  
  
        cout << "Enter coordinate y1 : ";  
        cin >> y1;  
  
        cout << "Enter coordinate x2 : ";  
        cin >> x2;  
  
        cout << "Enter coordinate y2 : ";  
        cin >> y2;  
  
        line(x1, y1, x2, y2);  
    }  
  
    void translate(){  
    int tx, ty;  
    cout << "Enter coordinate for point x : ";  
    cin >> tx;  
    cout << "Enter coordinate for point y : ";  
    cin >> ty;  
  
    line(x1+tx, y1+ty, x2+tx, y2+ty);  
    }  
  
    void scaling(){  
    int sx, sy;  
    cout << "Enter coordinate for point x : ";  
    cin >> sx;  
    cout << "Enter coordinate for point y : ";  
    cin >> sy;  
  
    line(x1*sx, y1*sy, x2*sx, y2*sy);  
    }  
  
    void rotation() {  
    int Rx1, Ry1, Rx2, Ry2;  
    double s, c, angle;  
  
    cout << "Enter the angle to rotate the line : ";  
    cin >> angle;  
  
    // Convert the angle from degrees to radians  
    c = cos(angle * 3.14 / 180);  
    s = sin(angle * 3.14 / 180);  
  
    // Find the midpoint of the line  
    int mx = (x1 + x2) / 2;  
    int my = (y1 + y2) / 2;  
  
    // Translate the line to the origin (midpoint)  
    int tx1 = x1 - mx;  
    int ty1 = y1 - my;  
    int tx2 = x2 - mx;  
    int ty2 = y2 - my;  
  
    // Apply the rotation matrix  
    Rx1 = floor(tx1 * c - ty1 * s);  
    Ry1 = floor(tx1 * s + ty1 * c);  
    Rx2 = floor(tx2 * c - ty2 * s);  
    Ry2 = floor(tx2 * s + ty2 * c);  
  
    // Translate back to the original position  
    Rx1 += mx;  
    Ry1 += my;  
    Rx2 += mx;  
    Ry2 += my;  
  
    // Draw the rotated line  
    line(Rx1, Ry1, Rx2, Ry2);  
}  
  
};  
  
int main() {  
    int gd = DETECT, gm;  
    initgraph(&gd, &gm, " ");  
  
    Transformation t;  
    int ch;  
    char q;  
  
    t.accept();  
    do {  
        cout << "Menu : ";  
        cout << "\n1. Translate";  
        cout << "\n2. Scale";  
        cout << "\n3. Rotate";  
        cout << "\n4. Exit"<<endl;  
        cout << "Enter your choice : ";  
  
        cin >> ch;  
  
    switch(ch){  
    case 1 :  
        t.translate();  
        break;  
    case 2 :  
        t.scaling();  
        break;  
    case 3 :  
        t.rotation();  
        break;  
    case 4 :  
        exit(0);  
  
    default :  
        cout << "Invalid choice...";  
        break;  
        }  
  
        cout << "Do you want to continue? (y/n): ";  
        cin >> q;  
    } while(q == 'y' || q == 'Y');  
  
    getch();  
    closegraph();  
    return 0;  
}  

