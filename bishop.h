#include "rook.h"

int check_bishop(move x, int piece)
{
    if (abs(x.start_poz[0] - x.end_poz[0]) == abs(x.start_poz[1] - x.end_poz[1]))
    {
        if (piece > 0) // for white
        {
            if (x.start_poz[1] < x.end_poz[1]) // upward movement
            {
                if (x.start_poz[0] > x.end_poz[0]) // diagonally left
                {
                    for (int i = x.start_poz[0] - 'a', j = x.start_poz[1] - '0'; i > x.end_poz[0] - 'a', j < x.end_poz[1] - '0'; i--, j++)
                    {
                        char temp_poz[] = {i + 'a', j + '0', '\0'};
                        if (get_piece(temp_poz))
                        {
                            printf("Invalid move (friendly piece in way)\n");
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) > 0)
                    {
                        printf("Invalid move (friendly piece in way)\n");
                        return 0;
                    }
                    else
                        return 1;
                }
                else // diagonally right
                {
                    for (int i = x.start_poz[0] - 'a', j = x.start_poz[1] - '0'; i < x.end_poz[0] - 'a', j < x.end_poz[1] - '0'; i++, j++)
                    {
                        char temp_poz[] = {i + 'a', j + '0', '\0'};
                        if (get_piece(temp_poz))
                        {
                            printf("Invalid move (friendly piece in way)\n");
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) > 0)
                    {
                        printf("Invalid move (friendly piece in way)\n");
                        return 0;
                    }
                    else
                        return 1;
                }
            }
            else // downward movement
            {
                if (x.start_poz[0] > x.end_poz[0]) // diagonally left
                {
                    for (int i = x.start_poz[0] - 'a', j = x.start_poz[1] - '0'; i > x.end_poz[0] - 'a', j > x.end_poz[1] - '0'; i--, j--)
                    {
                        char temp_poz[] = {i + 'a', j + '0', '\0'};
                        if (get_piece(temp_poz))
                        {
                            printf("Invalid move (friendly piece in way)\n");
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) > 0)
                    {
                        printf("Invalid move (friendly piece in way)\n");
                        return 0;
                    }
                    else
                        return 1;
                }
                else // diagonally right
                {
                    for (int i = x.start_poz[0] - 'a', j = x.start_poz[1] - '0'; i<x.end_poz[0] - 'a', j> x.end_poz[1] - '0'; i++, j--)
                    {
                        char temp_poz[] = {i + 'a', j + '0', '\0'};
                        if (get_piece(temp_poz))
                        {
                            printf("Invalid move (friendly piece in way)\n");
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) > 0)
                    {
                        printf("Invalid move (friendly piece in way)\n");
                        return 0;
                    }
                    else
                        return 1;
                }
            }
        }
        // else // for black
    }
    else
    {
        printf("Invalid move\n");
        return 0;
    }
}