#include "king.h"

int check_knight(move x, int piece)
{
    if ((abs(x.start_poz[0] - x.end_poz[0]) == 1) && (abs(x.start_poz[1] - x.end_poz[1]) == 2) || ((abs(x.start_poz[0] - x.end_poz[0]) == 2) && (abs(x.start_poz[1] - x.end_poz[1]) == 1)))
    {
        if (piece > 0) // for white
        {

            if (get_piece(x.end_poz) > 0)
            {
                printf("Invalid move\n");
                return 0;
            }
            else
                return 1;
        }
        else // for black
        {
            if (get_piece(x.end_poz) < 0)
            {
                printf("Invalid move\n");
                return 0;
            }
            else
                return 1;
        }
    }
    return 0;
}