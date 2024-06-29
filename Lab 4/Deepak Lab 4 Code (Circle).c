#include <graphics.h>
#include <stdith.h> 
#include <stdio.h>
#include <conio.h>
#include <dos.h>
void circles(int,int,int);
int main(void)
{
int gdriver= DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "C:\\tc\\bgi" );
errorcode = graphresult():
if (errorcode != gr0k)
{
printf(Graphics error: %s\n", grapherrormsg(errorcode));
printf (Press any key to halt);
getch();
exit(1); }
int midx= getmaxx()/2;
int midy getmaxy()/2; 
for(int i=10;1<=230;i=i+10) 
{circles(midx,midy,i);
}
getch();
closegraph(); 
return 0;
}
void circles(int xc, int yc, int r)
{
int x0,y0,x,y;
float pk, p0;
x0=0;
J0=r;
x=x0;
y=y0;
putpixel(x,y,RED);
p0=1-r;
pk=p0;
do
if (pk<0)
{x=x+1;
y=y;
pk=pk+2*x+1;
}
else
{
x=x+1;
y=y-1;
pk=pk+2*x-2*y+1;
}
putpixel(x+xc,y+yc,RED);
putpixel(x+xc,-y+yc, RED);
putpixel (y+xc,x+yc, RED);
putpixel(y+xc,-x+yc, RED);
putpixel(-x+xc,y+yc, RED);
putpixel(-y+xc,x+yc, RED ); 
putpixel(-x+xc,-y+yc, RED); 
putpixel(-y+xc,-x+yc, RED); 
delay(5);
}while(x<y);
}
