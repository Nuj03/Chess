#include "knight.h"

int check_rook(move x, int piece)
{
    if (x.start_poz[0] == x.end_poz[0] || x.start_poz[1] == x.end_poz[1])
    {
        if (piece > 0) // for white
        {
            if (x.start_poz[0] == x.end_poz[0]) // vertical movement
            {
                if (x.start_poz[1] < x.end_poz[1]) // upward movement
                {
                    for (int i = 8 - (x.start_poz[1] - '0'); i > 8 - (x.end_poz[1] - '0'); i--)
                    {
                        char temp_poz[] = {x.start_poz[0], 8 - i + '0', '\0'};
                        if (get_piece(temp_poz))
                        {
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) > 0)
                        return 0;
                    else
                        return 1;
                }
                else // downward movement
                {
                    for (int i = 8 - (x.start_poz[1] - '0'); i < 8 - (x.end_poz[1] - '0'); i++)
                    {
                        char temp_poz[] = {x.start_poz[0], 8 - i + '0', '\0'};
                        if (get_piece(temp_poz))
                        {
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) > 0)
                        return 0;
                    else
                        return 1;
                }
            }
            else if (x.end_poz[1] == x.start_poz[1]) // horizontal movement
            {
                if (x.start_poz[0] < x.end_poz[0]) // right movement
                {
                    for (int i = x.start_poz[0] - 'a'; i < x.end_poz[0] - 'a'; i++)
                    {
                        char temp_poz[] = {i + 'a', x.start_poz[1], '\0'};
                        if (get_piece(temp_poz))
                        {
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) > 0)
                        return 0;
                    else
                        return 1;
                }
                else // left movement
                {
                    for (int i = x.start_poz[1] - 'a'; i > x.end_poz[1] - 'a'; i--)
                    {
                        char temp_poz[] = {i + 'a', x.start_poz[1], '\0'};
                        if (get_piece(temp_poz))
                        {
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) > 0)
                        return 0;
                    else
                        return 1;
                }
            }
        }
        else // for black
        {
            if (x.start_poz[0] == x.end_poz[0]) // vertical movement
            {
                if (x.start_poz[1] < x.end_poz[1]) // upward movement
                {
                    for (int i = 8 - (x.start_poz[1] - '0'); i > 8 - (x.end_poz[1] - '0'); i--)
                    {
                        char temp_poz[] = {x.start_poz[0], 8 - i + '0', '\0'};
                        if (get_piece(temp_poz))
                        {
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) < 0)
                        return 0;
                    else
                        return 1;
                }
                else // downward movement
                {
                    for (int i = 8 - (x.start_poz[1] - '0'); i < 8 - (x.end_poz[1] - '0'); i++)
                    {
                        char temp_poz[] = {x.start_poz[0], 8 - i + '0', '\0'};
                        if (get_piece(temp_poz))
                        {
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) < 0)
                        return 0;
                    else
                        return 1;
                }
            }
            else if (x.end_poz[1] == x.start_poz[1]) // horizontal movement
            {
                if (x.start_poz[0] < x.end_poz[0]) // right movement
                {
                    for (int i = x.start_poz[0] - 'a'; i < x.end_poz[0] - 'a'; i++)
                    {
                        char temp_poz[] = {i + 'a', x.start_poz[1], '\0'};
                        if (get_piece(temp_poz))
                        {
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) < 0)
                        return 0;
                    else
                        return 1;
                }
                else
                {
                    for (int i = x.start_poz[1] - 'a'; i > x.end_poz[1] - 'a'; i--)
                    {
                        char temp_poz[] = {i + 'a', x.start_poz[1], '\0'};
                        if (get_piece(temp_poz))
                        {
                            return 0;
                        }
                    }
                    if (get_piece(x.end_poz) < 0)
                        return 0;
                    else
                        return 1;
                }
            }
        }
    }
    else
        return 0;
}