/*function with prototypes, includes and features*/
#include "desafio7.h"

int main(void)
{
    srand(time(NULL));

    t_map m;
    char ch = ' '; //'ch' get the keyboard keys to move the '@'
    m = init_map(m);

    while (ch != 'q')
    { 
       ch = getch();   
       m = movePlayer(m, ch);
       m = get_chest(m);
       sleep(0.1);
    }
    
    return EXIT_SUCCESS;
}

/*this fuction get a screen coordenates, get a exactly sorted pixel and move the cursor till the position */
void gotoxy(int x,int  y) //use some functions in windows
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*Move the player*/
t_map movePlayer(t_map m, char ch)
{
    int prev_x = m.player.pos.x;
    int prev_y = m.player.pos.y;
    int next_x = m.player.pos.x;
    int next_y = m.player.pos.y;
    switch (ch)
    {
    case 'w':
        next_y--;
        break;
    case 's':
        next_y++;
        break;
    case 'a':
        next_x--;
        break;
    case 'd':
        next_x++;
        break;
    }
    if (m.map[next_x][next_y] != '*' && next_x != MAX_C && next_y != MAX_L)
    {
        m.map[prev_x][prev_y] = ' ';
        gotoxy(prev_x, prev_y);
        printf(" ");
        
        m.player.pos.x = next_x;
        m.player.pos.y = next_y;
        m.map[m.player.pos.x][m.player.pos.y] = '@';
        gotoxy(m.player.pos.x, m.player.pos.y);
        printf("@");
        return m;
    }
}

t_map init_map(t_map m)
{   /*Creating a map*/
    for (int i = 0; i < MAX_C ; i++)
    {
        m.map[i][MIN_L] = '*';
        m.map[i][MAX_L] = '*';
        gotoxy(i, MIN_L);
        printf("*");
        gotoxy(i, MAX_L);
        printf("*");
    }

    for (int i = 0; i < MAX_L ; i++)
    {
        m.map[MIN_C][i] = '*';
        m.map[MAX_C][i] = '*';
        gotoxy(MIN_C, i);
        printf("*");
        gotoxy(MAX_C, i);
        printf("*");
    }
    
    //Score
    m.score = 0;
    gotoxy(35, 10);
    printf("SCORE: %d", m.score);
    //Exit the game
    gotoxy(35, 9);
    printf("Press 'q' to exit the game");
    //Starting player position 
    m.player.pos.x = 1;
    m.player.pos.y = 1;
    //Starting chest position
    m.chest.pos.x = 20;
    m.chest.pos.y = 15;

    //Writing the player and chest position in memory
    m.map[m.player.pos.x][m.player.pos.y] = '@';
    m.map[m.chest.pos.x][m.chest.pos.y] = 'O';

    //Show in screen the positions
    gotoxy(m.chest.pos.x, m.chest.pos.y);
    printf("O");
    gotoxy(m.player.pos.x, m.player.pos.y);
    printf("@");

    return m;
}

/*When a get the chest a reset the positions and get a new rand positions*/
t_map get_chest(t_map m)
{
    if (m.map[m.chest.pos.x][m.chest.pos.y] == '@' )
    {
        gotoxy(m.player.pos.x, m.player.pos.y);
        printf(" ");
        m.score++;
        gotoxy(35, 10);
        printf("SCORE: %d", m.score);
        m.player.pos.x = rand() % 28 + 1;
        m.player.pos.y = rand() % 18 + 1;
        
        do
        {
            m.chest.pos.x = rand() % 28 + 1;
            m.chest.pos.y = rand() % 18 + 1;
        }while (m.player.pos.x == m.chest.pos.x && m.player.pos.y == m.chest.pos.y);
        
        m.map[m.player.pos.x][m.player.pos.y] = '@';
        m.map[m.chest.pos.x][m.chest.pos.y] = 'O';

        gotoxy(m.chest.pos.x, m.chest.pos.y);
        printf("O");
        gotoxy(m.player.pos.x, m.player.pos.y);
        printf("@");
        return m;
    }
}
