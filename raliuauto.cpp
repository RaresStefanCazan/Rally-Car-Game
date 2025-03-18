#include <windows.h>
#include <mmsystem.h>
#include <winbgim.h>
#include <graphics.h>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

#define MAX 10

void phill (int startx, int starty)
{
    floodfill(startx,starty,BLUE);
}
void phill2(int x1,int y1,int x2, int y2)
{
    for(int i=x1;i<=x2;i++)
       for (int j=y1;j<=y2;j++)
         rectangle(i,j,x2,y2);
}
int latime;
void deseneazaTabla(int n,int m)
{

    for (int i=0; i<=n; i=i+latime)
        line(i,0,i,m);
    for (int i=0; i<=m; i=i+latime)
        line(0,i,n,i);

}

void flood(int x, int y, int new_col, int old_col)
{
    // check current pixel is old_color or not
    if (getpixel(x, y) == old_col)
    {

        // put new pixel with new color
        putpixel(x, y, new_col);

        // recursive call for bottom pixel fill
        flood(x + 1, y, new_col, old_col);

        // recursive call for top pixel fill
        flood(x - 1, y, new_col, old_col);

        // recursive call for right pixel fill
        flood(x, y + 1, new_col, old_col);

        // recursive call for left pixel fill
        flood(x, y - 1, new_col, old_col);
    }
}
void deseneazaTraseuelipsa(int n, int m)
{
    ellipse(n/2, m/2, 0, 360, 525, 375);
    fillellipse(n/2, m/2, 400, 250);
}
void deseneazatraseu(int x,int y, int v[])
{
    int i=0;
    while(v[i]!=0)
    {
        if(v[i]==1)
        {
            line(x,y,x,y-20);
            y=y-20;
        }
        if(v[i]==2)
        {
            line (x,y,x+20,y);
            x= x+20;
        }
        if(v[i]==3)
        {
            line (x,y,x,y+20);
            y= y+20;
        }
        if(v[i]==4)
        {
            line (x,y,x-20,y);
            x= x-20;
        }
        if(v[i]==5)
        {
            line (x,y,x+20,y-20);
            x= x+20;
            y=y-20;
        }
        if(v[i]==6)
        {
            line (x,y,x+20,y+20);
            x= x+20;
            y=y+20;
        }
        if(v[i]==7)
        {
            line (x,y,x-20,y+20);
            x= x-20;
            y=y+20;
        }
        if(v[i]==8)
        {
            line (x,y,x-20,y-20);
            x= x-20;
            y=y-20;
        }
        i++;
    }
}
void deseneazatraseu2(int x,int y, int v[])
{
    int i=0;
    int l=13;
    while(v[i]!=0)
    {
        if(v[i]==1)
        {
            line(x,y,x,y-l);
            y=y-l;
        }
        if(v[i]==2)
        {
            line (x,y,x+l,y);
            x= x+l;
        }
        if(v[i]==3)
        {
            line (x,y,x,y+l);
            y= y+l;
        }
        if(v[i]==4)
        {
            line (x,y,x-l,y);
            x= x-l;
        }
        if(v[i]==5)
        {
            line (x,y,x+l,y-l);
            x= x+l;
            y=y-l;
        }
        if(v[i]==6)
        {
            line (x,y,x+l,y+l);
            x= x+l;
            y=y+l;
        }
        if(v[i]==7)
        {
            line (x,y,x-l,y+l);
            x= x-l;
            y=y+l;
        }
        if(v[i]==8)
        {
            line (x,y,x-l,y-l);
            x= x-l;
            y=y-l;
        }
        i++;
    }
}
void drawPoint (int x, int y)
{
    circle(x, y, 1);
    circle(x, y, 2);
    circle(x, y, 3);
    circle(x, y, 4);

}
struct pct
{
    int x, y;
};

bool drawAction(int x, int y, int prevx, int prevy, int viteza)
{
    setcolor(RED);
    pct v[20];
    int index = 0;
    pct a;
    a.x = x;
    a.y = y;
    v[index++] = a;
    a.x = x - 20;
    a.y = y - 20;
    v[index++] = a;
    a.x = x + 20;
    a.y = y - 20;
    v[index++] = a;
    a.x = x + 20;
    a.y = y + 20;
    v[index++] = a;
    a.x = x - 20;
    a.y = y + 20;
    v[index++] = a;
    a.x = x - 20;
    a.y = y;
    v[index++] = a;
    a.x = x + 20;
    a.y = y;
    v[index++] = a;
    a.x = x;
    a.y = y + 20;
    v[index++] = a;
    a.x = x;
    a.y = y - 20;
    v[index] = a;
    for (int i = 0; i<=index; ++i)
    {
        if (viteza == 0)
        {
            if (v[i].x == 460)
            {
                v[i].x = 0;
                v[i].y = 0;
            }
            else if (v[i].x == 500)
            {
                v[i].x = 0;
                v[i].y = 0;
            }
            else if (v[i].x == prevx && v[i].y == prevy)
            {
                v[i].x = 0;
                v[i].y = 0;
            }
            else if ((v[i].x - prevx + v[i].y - prevy) / 20 == 1 && v[i].x != x && v[i].y != y)
            {
                v[i].x = 0;
                v[i].y = 0;
            }
        }

        else if (viteza == 1)
        {
            if (v[i].x == prevx && v[i].y == prevy)
                v[i].x = 0, v[i].y = 0;
            else if ((v[i].x - prevx + v[i].y - prevy) / 20 == 1 && v[i].x != x && v[i].y != y)
                v[i].x = 0, v[i].y = 0;
        }
    }
    for (int i = 0; i<=index; ++i)
    {
        if (v[i].x == 0 || v[i].y == 0)
            continue;
        if (!(getpixel(v[i].x, v[i].y) == 0 || getpixel(v[i].x, v[i].y) == LIGHTCYAN || getpixel(v[i].x, v[i].y)==1))
            v[i].x = 0, v[i].y = 0;
        if (getpixel(v[i].x, v[i].y) == CYAN || getpixel(v[i].x, v[i].y) == LIGHTGREEN )
            v[i].x = 0, v[i].y = 0;
    }
    bool found = false;
    for (int i = 0; i<=index; ++i)
        if (v[i].x == 0 || v[i].y == 0)
            continue;
        else
        {
            drawPoint(v[i].x, v[i].y);
            found = true;
        }
    return found;
}
struct linie
{
    int x1, y1, x2, y2;
};

int numberLinii = 1;
linie linii[1001];

void drawAllLines ()
{
    setcolor(LIGHTCYAN);
    setlinestyle(SOLID_LINE, 0, 3);
    for (int i = 1; i<numberLinii; ++i)
        line(linii[i].x1, linii[i].y1, linii[i].x2, linii[i].y2);
}

int home=0;
int ok=0, k=0;
int v[210]= {4,4,4,4,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,8,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,5,5,2,2,2,5,5,5,5,5,5,5,2,2,2,2,2,2,2,2,2,2,6,6,6,6,6,6,2,2,2,2,6,6,6,6,6,2,2,2,2,2,6,6,6,6,6,6,6,3,3,3,3,3,3,7,7,7,7,4,4,4,4,4,7,7,7,7,4,4,4,4,4,4,4,4,4,4,7,7,7,4,4,4,4,0};
int n=1080, m=760;
int vs1[300]= {4,4,4,4,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,5,5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,6,2,2,2,5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,6,6,6,6,3,3,3,3,7,7,7,4,4,4,4,4,4,4,4,4,4,7,7,4,4,4,4,4,8,8,4,4,4,4,4,4,4,7,7,7,3,3,3,3,6,6,6,2,2,2,2,2,2,2,2,2,2,2,6,6,2,2,2,2,2,5,5,2,2,2,2,2,2,2,2,2,2,6,6,6,3,3,3,7,7,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0};
int vs2[300] = {4,4,4,4,8,8,4,4,4,8,8,4,4,4,8,1,1,1,1,1,1,1,1,1,5,1,1,1,1,5,5,5,2,2,2,2,2,2,2,2,2,2,2,6,6,2,2,2,2,2,2,2,2,2,5,5,2,2,2,2,2,2,2,2,2,6,3,7,4,4,4,4,4,4,7,7,4,4,4,4,4,8,8,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,3,3,3,3,6,6,6,6,6,6,6,6,2,2,2,2,2,2,2,2,2,6,2,2,2,2,2,2,2,2,2,2,2,2,5,5,2,2,2,6,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0 };
int poz1x = n/2-40, poz1y = 680;
int poz2x = n/2-40, poz2y = 700;
int nextMiddle1x = 480, nextMiddle1y = poz1y;
int nextMiddle2x = 480, nextMiddle2y = poz2y;
int v1 = 0;
int v2 = 0;
int turn = 1;
void usor(int hx,int hy)
{
    initwindow(hx,hy);
    while (true)
    {
        setbkcolor(WHITE);
        cleardevice();
        setlinestyle(SOLID_LINE, 0, 1);
        latime=20;
        setcolor(BLACK);
        deseneazaTabla(n,m);
        setcolor(BLACK);
            setlinestyle(SOLID_LINE, 0, 1);
            phill2(500,620,520,640);
            phill2(520,640,540,660);
            phill2(540,620,560,640);
            phill2(500,660,520,680);
            phill2(540,660,560,680);
            phill2(500,700,520,720);
            phill2(520,680,540,700);
            phill2(540,700,560,700);
            phill2(540,700,560,720);
            phill2(520,720,540,740);
            phill2(500,740,520,760);
            phill2(540,740,560,760);
        setlinestyle(SOLID_LINE, 0, 5);
        int nextx, nexty;
        drawAllLines();
        setcolor(CYAN);
        drawPoint(poz1x, poz1y);
        setcolor(LIGHTGREEN);
        drawPoint(poz2x, poz2y);
        if (turn == 1)
        {
            setcolor(BLUE);
            deseneazaTraseuelipsa(n,m);
            phill(20, 20);

            bool gasit = drawAction(nextMiddle1x, nextMiddle1y, poz1x, poz1y, v1);
            if (gasit == false)
            {
                cleardevice();
                readimagefile("C:\\proiect-ip\\raliuauto\\j2.jpg",200,100,900,493);
                system("pause");
            }
            int mousex = 0, mousey = 0;
            while (true)
            {
                while (!ismouseclick(WM_LBUTTONDOWN))
                    continue;
                getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
                int color = getpixel(mousex, mousey);
                if (color == 4)
                {
                    int findx, findy;
                    for (int p1 = mousex - 4; p1 <= mousex + 4; ++p1)
                        for (int p2 = mousey - 4; p2 <= mousey + 4; ++p2)
                            if (p1 % 20 == 0 && p2 % 20 == 0)
                                findx = p1, findy = p2;
                    int finish1x=poz1x;
                    int finish2x=findx;
                    int finish1y=poz1y;
                    int finish2y=findy;
                    linie a;
                    a.x1 = poz1x;
                    a.x2 = findx;
                    a.y1 = poz1y;
                    a.y2 = findy;
                    v1 = max(abs(poz1x - findx), abs(poz1y - findy));
                    if (v1>6) v1=6;
                    linii[numberLinii++] = a;
                    nextMiddle1x = findx + findx - poz1x;
                    nextMiddle1y = findy + findy - poz1y;
                    poz1x = findx;
                    poz1y = findy;
                    if(poz1x>=560 && poz1x<=500 && poz1y>620 && poz1y<760)
                    {
                        cleardevice();
                readimagefile("C:\\proiect-ip\\raliuauto\\j1.jpg",200,100,900,493);
                system("pause");
            }
                    }
                    break;
                }

            turn = 2;
        }
        else if (turn == 2)
        {
            setcolor(BLUE);
            deseneazaTraseuelipsa(n,m);
            phill(20, 20);
            bool gasit = drawAction(nextMiddle2x, nextMiddle2y, poz2x, poz2y, v2);
            if (gasit == false)
            {
                cleardevice();
                readimagefile("C:\\proiect-ip\\raliuauto\\j1.jpg",200,100,900,493);
                system("pause");
            }
            int mousex = 0, mousey = 0;
            while (true)
            {
                while (!ismouseclick(WM_LBUTTONDOWN))
                    continue;
                getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
                int color = getpixel(mousex, mousey);
                if (color == 4)
                {
                    int findx, findy;
                    for (int p1 = mousex - 4; p1 <= mousex + 4; ++p1)
                        for (int p2 = mousey - 4; p2 <= mousey + 4; ++p2)
                            if (p1 % 20 == 0 && p2 % 20 == 0)
                                findx = p1, findy = p2;
                    linie a;
                    a.x1 = poz2x;
                    a.x2 = findx;
                    a.y1 = poz2y;
                    a.y2 = findy;
                    linii[numberLinii++] = a;
                    v2 = max(abs(poz2x - findx), abs(poz2y - findy));
                    if (v2>6) v2=6;
                    if (v2>6) v2=6;
                    nextMiddle2x = findx + findx - poz2x;
                    nextMiddle2y = findy + findy - poz2y;
                    poz2x = findx;
                    poz2y = findy;
                    if(poz2x>=560 && poz2x<=500 && poz2y>620 && poz2y<760)
                    {
                        cleardevice();
                        readimagefile("C:\\proiect-ip\\raliuauto\\j2.jpg",200,100,900,493);
                        system("pause");
            }
                    break;
                }
            }
            turn = 1;
        }
    }

}
void mediu(int hx,int hy)
{
    initwindow(hx,hy);
    while (true)
    {
        setbkcolor(WHITE);
        cleardevice();
        setlinestyle(SOLID_LINE, 0, 1);
        latime=20;
        setcolor(BLACK);
        deseneazaTabla(n,m);
        phill2(520,600,540,620);
        phill2(540,580,560,600);
        phill2(500,620,520,640);
            phill2(520,640,540,660);
            phill2(540,620,560,640);
            phill2(500,660,520,680);
            phill2(540,660,560,680);
            phill2(500,700,520,720);
            phill2(520,680,540,700);
            phill2(540,700,560,700);
            phill2(540,700,560,720);
            phill2(520,720,540,740);
            phill2(500,740,520,760);
            phill2(540,740,560,760);
        setlinestyle(SOLID_LINE,0,10);
        setcolor(BLACK);
        setlinestyle(SOLID_LINE, 0, 5);
        int nextx, nexty;
        drawAllLines();
        setcolor(CYAN);
        drawPoint(poz1x, poz1y);
        setcolor(LIGHTGREEN);
        drawPoint(poz2x, poz2y);
        if (turn == 1)
        {
            setcolor(BLUE);
            deseneazatraseu(470,740,v);
            phill(20, 20);
            deseneazatraseu2(470,620,v);
            phill(500,600);
            bool gasit = drawAction(nextMiddle1x, nextMiddle1y, poz1x, poz1y, v1);
            if (gasit == false)
            {
                cleardevice();
                readimagefile("C:\\proiect-ip\\raliuauto\\j2.jpg",200,100,900,493);
                system("pause");
            }
            int mousex = 0, mousey = 0;
            while (true)
            {
                while (!ismouseclick(WM_LBUTTONDOWN))
                    continue;
                getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
                int color = getpixel(mousex, mousey);
                if (color == 4)
                {
                    int findx, findy;
                    for (int p1 = mousex - 4; p1 <= mousex + 4; ++p1)
                        for (int p2 = mousey - 4; p2 <= mousey + 4; ++p2)
                            if (p1 % 20 == 0 && p2 % 20 == 0)
                                findx = p1, findy = p2;
                    linie a;
                    a.x1 = poz1x;
                    a.x2 = findx;
                    a.y1 = poz1y;
                    a.y2 = findy;
                    v1 = max(abs(poz1x - findx), abs(poz1y - findy));
                    if (v1>6) v1=6;
                    linii[numberLinii++] = a;
                    nextMiddle1x = findx + findx - poz1x;
                    nextMiddle1y = findy + findy - poz1y;
                    poz1x = findx;
                    poz1y = findy;
                    break;
                }
            }
            turn = 2;
        }
        else if (turn == 2)
        {
            setcolor(BLUE);
            deseneazatraseu(470,740,v);
            phill(20, 20);
            deseneazatraseu2(470,620,v);
            phill(500,600);
            bool gasit = drawAction(nextMiddle2x, nextMiddle2y, poz2x, poz2y, v2);
            if (gasit == false)
            {
                cleardevice();
                readimagefile("C:\\proiect-ip\\raliuauto\\j1.jpg",200,100,900,493);
                system("pause");
            }
            int mousex = 0, mousey = 0;
            while (true)
            {
                while (!ismouseclick(WM_LBUTTONDOWN))
                    continue;
                getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
                int color = getpixel(mousex, mousey);
                if (color == 4)
                {
                    int findx, findy;
                    for (int p1 = mousex - 4; p1 <= mousex + 4; ++p1)
                        for (int p2 = mousey - 4; p2 <= mousey + 4; ++p2)
                            if (p1 % 20 == 0 && p2 % 20 == 0)
                                findx = p1, findy = p2;
                    linie a;
                    a.x1 = poz2x;
                    a.x2 = findx;
                    a.y1 = poz2y;
                    a.y2 = findy;
                    linii[numberLinii++] = a;
                    v2 = max(abs(poz2x - findx), abs(poz2y - findy));
                    if (v2>6) v2=6;
                    if (v2>6) v2=6;
                    nextMiddle2x = findx + findx - poz2x;
                    nextMiddle2y = findy + findy - poz2y;
                    poz2x = findx;
                    poz2y = findy;
                    break;
                }
            }
            turn = 1;
        }
    }
}


void dificil(int hx,int hy)
{
    initwindow(hx,hy);
    while (true)
    {
        setbkcolor(WHITE);
        cleardevice();
        setlinestyle(SOLID_LINE, 0, 1);
        latime=20;
        setcolor(BLACK);
        deseneazaTabla(n,m);
        setcolor(BLACK);
            setlinestyle(SOLID_LINE, 0, 1);
            phill2(500,660,520,680);
            phill2(540,660,560,680);
            phill2(500,700,520,720);
            phill2(520,680,540,700);
            phill2(540,700,560,720);
            phill2(520,720,540,740);
        setlinestyle(SOLID_LINE,0,10);
        setcolor(BLACK);
        setlinestyle(SOLID_LINE, 0, 5);
        int nextx, nexty;
        drawAllLines();
        setcolor(CYAN);
        drawPoint(poz1x, poz1y);
        setcolor(LIGHTGREEN);
        drawPoint(poz2x, poz2y);
        if (turn == 1)
        {
            setcolor(BLUE);
            deseneazatraseu(470,740,vs1);
            deseneazatraseu(470,660,vs2);
            phill(20,20);
            phill(500,640);
            bool gasit = drawAction(nextMiddle1x, nextMiddle1y, poz1x, poz1y, v1);
            if (gasit == false)
            {
                cleardevice();
                readimagefile("C:\\proiect-ip\\raliuauto\\j2.jpg",200,100,900,493);
                system("pause");
            }
            int mousex = 0, mousey = 0;
            while (true)
            {
                while (!ismouseclick(WM_LBUTTONDOWN))
                    continue;
                getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
                int color = getpixel(mousex, mousey);
                if (color == 4)
                {
                    int findx, findy;
                    for (int p1 = mousex - 4; p1 <= mousex + 4; ++p1)
                        for (int p2 = mousey - 4; p2 <= mousey + 4; ++p2)
                            if (p1 % 20 == 0 && p2 % 20 == 0)
                                findx = p1, findy = p2;
                    linie a;
                    a.x1 = poz1x;
                    a.x2 = findx;
                    a.y1 = poz1y;
                    a.y2 = findy;
                    v1 = max(abs(poz1x - findx), abs(poz1y - findy));
                    if (v1>6) v1=6;
                    linii[numberLinii++] = a;
                    nextMiddle1x = findx + findx - poz1x;
                    nextMiddle1y = findy + findy - poz1y;
                    poz1x = findx;
                    poz1y = findy;
                    break;
                }
            }
            turn = 2;
        }
        else if (turn == 2)
        {
            setcolor(BLUE);
            deseneazatraseu(470,740,vs1);
            deseneazatraseu(470,660,vs2);
            phill(20,20);
            phill(500,640);
            bool gasit = drawAction(nextMiddle2x, nextMiddle2y, poz2x, poz2y, v2);
            if (gasit == false)
            {
                cleardevice();
                readimagefile("C:\\proiect-ip\\raliuauto\\j1.jpg",200,100,900,493);
                system("pause");
            }
            int mousex = 0, mousey = 0;
            while (true)
            {
                while (!ismouseclick(WM_LBUTTONDOWN))
                    continue;
                getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
                int color = getpixel(mousex, mousey);
                if (color == 4)
                {
                    int findx, findy;
                    for (int p1 = mousex - 4; p1 <= mousex + 4; ++p1)
                        for (int p2 = mousey - 4; p2 <= mousey + 4; ++p2)
                            if (p1 % 20 == 0 && p2 % 20 == 0)
                                findx = p1, findy = p2;
                    linie a;
                    a.x1 = poz2x;
                    a.x2 = findx;
                    a.y1 = poz2y;
                    a.y2 = findy;
                    linii[numberLinii++] = a;
                    v2 = max(abs(poz2x - findx), abs(poz2y - findy));
                    if (v2>6) v2=6;
                    if (v2>6) v2=6;
                    nextMiddle2x = findx + findx - poz2x;
                    nextMiddle2y = findy + findy - poz2y;
                    poz2x = findx;
                    poz2y = findy;
                    break;
                }
            }
            turn = 1;
        }
    }

}

void homemenu(int hx, int hy)
{
    initwindow(hx,hy);
    readimagefile("C:\\proiect-ip\\raliuauto\\car1.jpg",0,0,1152,648);
    int mousex = 0, mousey = 0;
    while (!ismouseclick(WM_LBUTTONDOWN))
        continue;
    while(true)
    {
        getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
        int color = getpixel(mousex, mousey);
        if (mousex>=838 && mousex<=1001 && mousey>=260 && mousey<=321)
        {
            closegraph();
        }
        if (mousex>=362 && mousex<=715 && mousey>=481 && mousey<=538)
        {
            closegraph(CURRENT_WINDOW);
            initwindow(1000,500);
            readimagefile("C:\\proiect-ip\\raliuauto\\regulament.jpg",0,0,1000,500);
            while (!ismouseclick(WM_LBUTTONDOWN))
                continue;
            getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
            if(mousex>=60 && mousex<=106 && mousey>=403 && mousey<=464)
            {
                closegraph(CURRENT_WINDOW);
                homemenu(hx,hy);
            }
        }
        if(mousex>=126 && mousex<=310 && mousey>=256 && mousey<=313 )
        {
            closegraph();
            initwindow(629,750);
            readimagefile("C:\\proiect-ip\\raliuauto\\nivele.jpg",0,0,629,750);
            while (!ismouseclick(WM_LBUTTONDOWN))
                continue;
            getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
            if(mousex>=259 && mousex<=325 && mousey>=655 && mousey<=740)
            {
                closegraph(CURRENT_WINDOW);
                homemenu(hx,hy);
            }
            while(true)
            {
                getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
                if(mousex>=193 && mousey<=242 && mousex<=392 && mousey>=153)
                {

                    usor(n,m);
                    /*while (!ismouseclick(WM_LBUTTONDOWN))
                        continue;
                    getmouseclick(WM_LBUTTONDOWN, mousex, mousey);
                    if(mousex>=0 && mousex<=100 && mousey>=0 && mousey<=100)
                    {
                        closegraph(CURRENT_WINDOW);
                        homemenu(hx,hy);
                    }*/


                }
                else if(mousex>=193 && mousey<=400 && mousex<=390 && mousey>=242)
                {

                    mediu(n,m);
                    //if(home==1) if(mousex>=200 && mousey<=444 && mousex<=812 && mousey>=100) { closegraph(); homemenu(hx,hy);}
                }
                else if(mousex>=193 && mousey<=555 && mousex<=390 && mousey>=471)
                {
                    dificil(n,m);
                }
            }
        }

    }
}
int main()
{
    homemenu(1152,648);
    getch();
    closegraph();
    return 0;
}
