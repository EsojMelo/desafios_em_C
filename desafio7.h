/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>

//----------------------------------------------
/*Defines*/
#define MAX_C 30
#define MAX_L 20
#define MIN_C 0
#define MIN_L 0
//----------------------------------------------
/*structs*/
typedef struct s_pos
{
    int x;
    int y;
} t_position;

typedef struct s_player
{ 
    t_position pos;
    char dir;
} t_player;

typedef struct s_ches
{
    t_position pos;
} t_chest;

typedef struct s_map
{
    char map[MAX_C][MAX_L]; 
    t_player player;
    t_chest chest;
    int score;
}t_map;

//----------------------------------------------
/*Prototypes*/
void gotoxy(int x, int y);
t_map init_map(t_map m);
t_map movePlayer(t_map m, char ch);
t_map get_chest(t_map m);