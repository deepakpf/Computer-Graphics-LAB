#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void draw(int a[2][5]);
void translate(int a[2][5], int b[2][5], int tx, int ty);
void scale(int a[2][5], int b[2][5]);
void rotate(int a[2][5], int b[2][5]);
void fixed_rotate(int a[2][5], int b[2][5]);

void main()
{
    int a[2][5], b[2][5], tx, ty, i, gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\TURBOC3\\bgi");
    printf("Enter the coordinate positions of the lines");
    for (i = 0; i < 5; i++)
        scanf("%d %d", &a[0][i], &a[1][i]);

    draw(a);
    printf("Enter the translation co_ordinates ");
    scanf("%d %d", &tx, &ty);
    translate(a, b, tx, ty);
    draw(b);
    getch();

    scale(a, b);
    draw(b);
    getch();

    rotate(a, b);
    draw(b);
    getch();
    fixed_rotate(a, b);
    draw(b);
    getch();
    closegraph();
}

void draw(int a[2][5])
{
    int i = 0;
    for (i = 0; i < 4; i++)
        line(a[0][i], a[1][i], a[0][i + 1], a[1][i + 1]);
}

void translate(int a[2][5], int b[2][5], int tx, int ty)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        b[0][i] = a[0][i] + tx;
        b[1][i] = a[1][i] + ty;
    }
}

void scale(int a[2][5], int b[2][5])
{
    int i, sx, sy;
    printf("Enter the scaling factor ");
    scanf("%d%d", &sx, &sy);
    for (i = 0; i < 5; i++)
    {
        b[0][i] = a[0][i] * sx;
        b[1][i] = a[1][i] * sy;
    }
}

void rotate(int a[2][5], int b[2][5])
{
    int i, temp1, temp2;
    float angle;
    printf("Enter the rotation angle ");
    scanf("%f", &angle);
    for (i = 0; i < 5; i++)
    {
        temp1 = a[0][i];
        temp2 = a[1][i];
        b[0][i] = temp1 * cos(angle) - temp2 * sin(angle);
        b[1][i] = temp1 * sin(angle) + temp2 * cos(angle);
    }
}

void fixed_rotate(int a[2][5], int b[2][5])
{
    int tx, ty;
    printf("Enter the fixed point ");
    scanf("%d%d", &tx, &ty);

    translate(a, b, -tx, -ty);
    rotate(b, a);
    translate(a, b, tx, ty);
}
