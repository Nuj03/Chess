#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int board[8][8];

typedef struct
{
    char start_poz[3];
    char end_poz[3];
} move;

int get_piece(char *poz)
{
    int col = poz[0] - 'a';
    int linie = poz[1] - '0' - 1;
    return board[7 - linie][col];
}

void create_Board(void)
{

    for (int i = 0; i < 8; i++)
    {
        board[1][i] = -1;
        board[6][i] = 1;
    }
    board[0][0] = -5;
    board[0][7] = -5;
    board[7][7] = 5;
    board[7][0] = 5;
    board[0][1] = -4;
    board[0][6] = -4;
    board[7][1] = 4;
    board[7][6] = 4;
    board[0][2] = -3;
    board[0][5] = -3;
    board[7][2] = 3;
    board[7][5] = 3;
    board[0][3] = -9;
    board[0][4] = -10;
    board[7][3] = 9;
    board[7][4] = 10;
}

void print_board(void)
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d|", 8 - i);
        for (int j = 0; j < 8; j++)
        {
            switch (board[i][j])
            {
            case -1:
                printf(" p");
                break;
            case 1:
                printf(" P");
                break;
            case 0:
                printf(" O");
                break;
            case -5:
                printf(" r");
                break;
            case 5:
                printf(" R");
                break;
            case -4:
                printf(" n");
                break;
            case 4:
                printf(" N");
                break;
            case -3:
                printf(" b");
                break;
            case 3:
                printf(" B");
                break;
            case -9:
                printf(" q");
                break;
            case 9:
                printf(" Q");
                break;
            case -10:
                printf(" k");
                break;
            case 10:
                printf(" K");
                break;
            }
        }
        printf("\n\n");
    }
    printf(" -----------------\n");
    printf("   A B C D E F G H\n");
}
