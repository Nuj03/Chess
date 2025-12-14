#include "bishop.h"

int check_move(move x, int turn)
{
    int piece = get_piece(x.start_poz);
    if (piece < 0 && turn == 1)
    {
        printf("Not black's turn\n");
        return 0;
    }
    else if (piece > 0 && turn == 0)
    {
        printf("Not white's turn\n");
        return 0;
    }
    else
    {
        switch (abs(piece))
        {
        case 5:
            return check_rook(x, piece);
        case 9:
        {
            printf("%d", check_bishop(x, piece));
            return check_bishop(x, piece);
        }
        case 4:
            return check_knight(x, piece);
        case 10:
            return check_king(x, piece);
        // TO DO case 9: return check_queen(x, piece);
        case 1:
            return check_pawn(x, piece);
        case 0:
        {
            printf("No piece selected (empty square/wrong input)\n");
            return 0;
        }
        }
    }
}

void execute_move(move x)
{
    int col1 = x.start_poz[0] - 'a';
    int linie1 = x.start_poz[1] - '0' - 1;
    int col2 = x.end_poz[0] - 'a';
    int linie2 = x.end_poz[1] - '0' - 1;
    if (get_piece(x.end_poz) != 0)
        board[x.end_poz[0] - 'a'][x.end_poz[1] - '0'] = 0;
    int start_piece = get_piece(x.start_poz);
    int end_piece = get_piece(x.end_poz);
    swap(&start_piece, &end_piece);
    board[7 - linie1][col1] = start_piece;
    board[7 - linie2][col2] = end_piece;
}