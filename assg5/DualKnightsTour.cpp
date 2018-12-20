//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87
#include <iostream>
#include "DualKnightsTour.h"

DualKnightsTour::DualKnightsTour(int r1, int c1, int r2, int c2){
    for(short i = 0; i < 6; i++){for (short j = 0; j < 6; j++) board[i][j] = '.';}//initialise the board with .
    steps1 = 0; steps2 = 0; consec1 = 0; consec2 = 0;
    board[r1][c1] = '@'; board[r2][c2] = '#';//place chess in private board
    posR1 = r1; posC1 = c1; posR2 = r2; posC2 = c2;//place chess in private current pos
    };

void DualKnightsTour::print() const{
        std::cout<<"  0 1 2 3 4 5" << (char) 10;
        for(short i = 0; i < 6; i++){std::cout<< i; for (short j = 0; j < 6; j++) std::cout << ' ' << board[i][j]; std::cout << std::endl;}
    };

bool DualKnightsTour::isValid(char knight, int r, int c) const{
    //cond 1: @ or #
    if (!(knight == '@' || knight == '#')) return false;
    //cond 2: r and c within[0, 5]
    if (!(r >= 0 && r <= 5 && c >= 0 && c <= 5)) return false;
    //cond 3: destination is unvisited
    if (board[r][c] != '.') return false;
    //cond 4: the move is L-shaped, @ case
    if (knight == '@') {if (!(((((r-posR1 == 2)||(r-posR1 == -2))&&((c-posC1 == 1)||(c-posC1 == -1))))||(((r-posR1 == 1)||(r-posR1 == -1))&&((c-posC1 == 2)||(c-posC1 == -2))))) return false;}
    //cond 4: the move is L-shaped, # case
    if (knight == '#') {if (!(((((r-posR2 == 2)||(r-posR2 == -2))&&((c-posC2 == 1)||(c-posC2 == -1))))||(((r-posR2 == 1)||(r-posR2 == -1))&&((c-posC2 == 2)||(c-posC2 == -2))))) return false;}
    //cond 5: not the 3rd consec move
    if (knight == '@' && consec1 < 2) return true;
    if (knight == '#' && consec2 < 2) return true;
    return false;
}
bool DualKnightsTour::hasMoreMoves() const{
    for (short i = 0; i < 6; i++) {for (short j = 0; j < 6; j++) if (isValid('@', i, j)||isValid('#', i, j)) return true;} return false;// wow I am even impressed by myself writing this function in one line
}

bool DualKnightsTour::move(char knight, int r, int c){
    if (!isValid(knight, r, c)) return false;
    if (knight == '@') {board[posR1][posC1] = 'A'+ steps1++; board[r][c] = '@'; posR1 = r; posC1 = c; consec1++; consec2 = 0; return true;}
    if (knight == '#') {board[posR2][posC2] = 'a'+ steps2++; board[r][c] = '#'; posR2 = r; posC2 = c; consec2++; consec1 = 0; return true;}
    return false;
}
