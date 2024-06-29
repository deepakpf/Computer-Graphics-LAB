#include<stdio.h>
#include<conio.h> #include<graphics.h> void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
int xc=300,yc=200,rx,ry;
float p1,p2,x,y;
printf("Enter radius xc and yc");
scanf("%d%d",&rx,&ry);
x=0;
y=ry;
p1=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
while((2*ry*ry*x)<=(2*rx*rx*y))
{ if(p1<0){
    x++;
    p1=p1+(2*ry*ry*x)+(ry*ry);
} else{ x++;
y--;
p1=p1+(2*ry*ry*x)-(2*rx*rx*y)+(ry*ry);
}
putpixel(xc+x,yc+y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
} while(y!=0) {
    if(p2<0){
x++;
y--;
p2=p2+(2*ry*ry*x)-(2*rx*rx*y)+(rx*rx);
} else{ y--;
p2=p2-(2*rx*rx*y)+(rx*rx);
}
putpixel(xc+x,yc+y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
}
getch();
closegraph();
}
