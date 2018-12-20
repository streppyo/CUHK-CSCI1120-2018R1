//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87
#include <iostream>
#include "DualKnightsTour.h"
bool inrange(short var){if (var > -1 && var < 6) return true; else return false;}
int main(){
    short a, b, c, d; std::cout << "Knights' starting positions (row1 col1 row2 col2): ";
    std::cin >> a >> b >> c >> d;
    while (!(inrange(a)&&inrange(b)&&inrange(c)&&inrange(d)&&(!((a == c)&&(b == d))))) {
        std::cout << "Invalid position(s)!" << (char) 10 << "Knights' starting positions (row1 col1 row2 col2): "; std::cin >> a >> b >> c >> d;}
    DualKnightsTour z(a,b,c,d);
    z.print();
    while (z.hasMoreMoves()){
        char p; short q, r;
        std::cout << "Move (knight row col): ";
        std::cin >> p >> q >> r; while (!z.isValid(p, q, r)) {
            std::cout << "Invalid move!" << (char) 10 << "Move (knight row col): ";
            std::cin >> p >> q >> r;} z.move(p, q, r); z.print();
        
    } std::cout << "No more moves!";
    
}
