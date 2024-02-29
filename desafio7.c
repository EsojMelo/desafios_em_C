/*function with prototypes, includes and features*/
#include "desafio7.h"

int main(void)
{
    t_map m;
    char ch = ' ';
    m = init_map(m);

    while (ch != 'q')
    { 
       ch = getch();   
       m = movePlayer(m, ch);
       sleep(0.1);
    }
    
    return EXIT_SUCCESS;
}

void gotoxy(int x,int  y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

t_map movePlayer(t_map m, char ch)
{
    int prev_x = m.player.pos.x;
    int prev_y = m.player.pos.y;
    switch (ch)
    {
    case 'w':
        m.player.pos.y--;
        break;
    case 's':
        m.player.pos.y++;
        break;
    case 'a':
        m.player.pos.x--;
        break;
    case 'd':
        m.player.pos.x++;
        break;
    }
    gotoxy(prev_x, prev_y);
    printf(" ");
    gotoxy(m.player.pos.x, m.player.pos.y);
    printf("@");

    return m;
}

t_map init_map(t_map m)
{
    for (int i = 0; i < C ; i++)
    {
        gotoxy(i, 0);
        printf("*");
        gotoxy(0, i);
        printf("*");
        gotoxy(25, i);
        printf("*");
        gotoxy(i, 25);
        printf("*");
    }
    
    m.player.pos.x = 1;
    m.player.pos.y = 1;
    m.chest.pos.x = 20;
    m.chest.pos.y = 20;

    m.map[m.player.pos.x][m.player.pos.y] = '@';
    m.map[m.chest.pos.x][m.chest.pos.y] = 'O';

    gotoxy(m.chest.pos.x, m.chest.pos.y);
    printf("O");
    gotoxy(m.player.pos.x, m.player.pos.y);
    printf("@");

    return m;
}
