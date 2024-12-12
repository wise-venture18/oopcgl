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
