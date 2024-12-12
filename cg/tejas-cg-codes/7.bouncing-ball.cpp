// ) Write a C++ program to implement bouncing ball using sine wave form. 
// Apply the concept of polymorphism.  

#include <iostream> 
#include <cstdlib> 
#include <graphics.h> 
using namespace std; 
int main() 
{ 
int gd = DETECT, gm; 
int i, x, y, flag=0; 
initgraph(&gd, &gm,NULL); 
/* get mid posiƟons in x and y-axis */ 
x = getmaxx()/2; 
y = 30; 
while (1) 
{ 
if(y >= getmaxy()-30 || y <= 30) 
f
 lag = !flag; 
/* draws the gray board */ 
setcolor(RED); 
//seƞillstyle(SOLID_FILL, RED); 
circle(x, y, 30); 
f
 loodfill(x, y, RED); 
/* delay for 50 milli seconds */ 
delay(50); 
/* clears screen */ 
cleardevice(); 
if(flag) 
{ 
y = y + 5; 
} 
else 
{ 
y = y - 5; 
} 
} 
delay(5000); 
closegraph(); 
return 0; 
}
