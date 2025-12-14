#include "pieces.h"

int main(void)
{
    create_Board();
    print_board();
    char poz[5];
    int end_game = 0;
    int first_move = 1;
    printf("White's turn:\n");
    int turn = 1;
    while (scanf("%s", &poz) == 1)
    {

        if (first_move == 0)
        {
            if (turn == 1)
            {
                printf("White's turn:\n");
            }
            else
            {
                printf("Black's turn:\n");
            }
        }
        else
            first_move = 0;
        move miscare;
        strncpy(miscare.start_poz, poz, 2);
        miscare.start_poz[2] = '\0';
        strncpy(miscare.end_poz, poz + 2, 2);
        miscare.end_poz[2] = '\0';
        if (check_move(miscare, turn))
        {
            execute_move(miscare);
            if (turn)
                turn = 0;
            else
                turn = 1;
            print_board();
        }
    }
}