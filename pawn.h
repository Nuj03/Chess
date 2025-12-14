#include "util.h"

int check_first_move(move x, int color)
{
    if (x.start_poz[1] - '0' == 2 && color == 1)
        return 1;
    else if (x.start_poz[1] - '0' == 7 && color == 0)
        return 1;
    else
        return 0;
}

int check_enemy(move x, int color)
{
    if (color == 1)
    {
        if (get_piece(x.end_poz) < 0)
            return 1;
        else
            return 0;
    }

    if (color == 0)
    {
        if (get_piece(x.end_poz) > 0)
            return 1;
        else
            return 0;
    }
}

int check_pawn(move x, int piece)
{
    int color;
    if (piece > 0)
        color = 1; // white piece
    else
        color = 0; // black piece

    if (color == 1) // for white
    {
        if (x.end_poz[1] - x.start_poz[1] == 1) // forward move
        {
            if (get_piece(x.end_poz) != 0)
            {
                printf("Invalid move (piece in way)\n");
                return 0;
            }
            else
                return 1;
        }

        else if ((abs(x.end_poz[0] - x.start_poz[0]) == 1) && (x.end_poz[1] - x.start_poz[1] == 1)) // attack move
        {

            if (check_enemy(x, color))
                return 1;
            else
            {
                printf("Invalid move (no enemy around)\n");
                return 0;
            }
        }

        else if (x.end_poz[1] - x.start_poz[1] == 2) // first move
        {
            if (check_first_move(x, color))
            {
                char temp_poz[] = {x.start_poz[0], x.start_poz[1] + 1, '\0'};
                if (get_piece(x.end_poz) != 0)
                {
                    printf("Invalid move (piece in way)\n");
                    return 0;
                }
                else
                    return 1;
            }
            else
            {
                printf("Invalid move\n");
                return 0;
            }
        }
    }
    else if (color == 0) // for black
    {
        if (x.start_poz[1] - x.end_poz[1] == 1) // forward move
        {
            if (get_piece(x.end_poz) != 0)
            {
                printf("Invalid move (piece in way)\n");
                return 0;
            }
            else
                return 1;
        }

        else if ((abs(x.end_poz[0] - x.start_poz[0]) == 1) && (x.start_poz[1] - x.end_poz[1] == 1)) // attack move
        {
            if (check_enemy(x, color))
                return 1;
            else
            {
                printf("Invalid move (no enemy around)\n");
                return 0;
            }
        }

        else if (x.start_poz[1] - x.end_poz[1] == 2) // first move
        {
            if (check_first_move(x, color))
            {
                char temp_poz[] = {x.start_poz[0], x.start_poz[1] + 1, '\0'};
                printf("%s\n", temp_poz);

                if (get_piece(x.end_poz) != 0 || get_piece(temp_poz) != 0)
                {
                    printf("Invalid move (piece in way)\n");
                    return 0;
                }
                else
                    return 1;
            }
            else
            {
                printf("Invalid move\n");
                return 0;
            }
        }
    }
}