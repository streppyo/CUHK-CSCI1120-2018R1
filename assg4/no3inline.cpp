//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87

//header
#include <iostream>
#include <string>
#include <iomanip>
/*---------------------Marker Use Area----------------------*/

const int SIZE=12;

/*---------------------Marker Use Area Ends----------------------*/

using namespace std;

//prototypes
void printBoard(char[][SIZE]);
bool check(char[][SIZE], short, short);
bool validator(char[][SIZE], short, short);
bool range(short, short);
void requestGrid(char[][SIZE], char&, short&);
int count(char[][SIZE]);
bool endGame(char[][SIZE]);
void updateGrid(char[][SIZE], short, short);
void initialiseBoard(char[][SIZE]);
//code
// '.'=46, '@'=64, '='=61

void printBoard(char board[][SIZE]){
    cout << "  ";
    for (char i = 65; i < 65 + SIZE; i++) cout << ' ' << i ;
    cout << endl;
    for (short i = 0; i < SIZE; i++){
        if (i < 10) cout << ' ';
        cout << i;
        for (short j = 0; j < SIZE ; j++)
            cout << ' ' << board[i][j];
        cout << endl;
    }
}

//these two functions together check if input is ok.........................
bool check(char board[][SIZE], short x, short y){
    if (board[x][y] == 46) return true;
    else return false;
}
bool range(short x, short y){
    if (x > -1 && x < SIZE && y > -1 && y < SIZE) return true;
    else return false;
}

//get input
void requestGrid(char board[][SIZE], char &x, short &y){
    cout << "Put a piece (col row): ";
    cin >> x >> y;
    while (!(check(board, y, x - 65) && range( y, x - 65)))
    {cout << "Invalid. Try again!" << endl << "Put a piece (col row): ";
        cin >> x >> y;
    }
}

// '.'=46, '@'=64, '='=61
void updateGrid(char board[][SIZE], short col, short row){
    board[row][col] = 64;
    short a = 0, b = 0, c = 0, d = 0;
    //col update
    for (short i = 0; i < SIZE; i++) if (board[i][col]==64) a++;
    if (a > 1) for (short i = 0; i < SIZE; i++) {if (board[i][col] != 64) board[i][col] = 61;}
    
    //row update
    for (short i = 0; i < SIZE; i++) if (board[row][i]==64) b++;
    if (b > 1) for (short i = 0; i < SIZE; i++) {if (board[row][i] != 64) board[row][i] = 61;}
    
    //RT-LB diag update
    bool eatenByLeftTop = (row + col <= SIZE - 1) ? true : false;
    if (eatenByLeftTop) {for (short i = 0; i < row + col + 1; i++) if (board[row + col - i][i]==64) c++;}
    if (!eatenByLeftTop) {for (short i = 0; i < row + col + 1; i++) if (board[row + col + i][SIZE - i]==64) c++;}
    if ((eatenByLeftTop)&&(c > 1)){for (short i = 0; i < row + col + 1; i++) {if (board[row + col - i][i] != 64) board[row + col - i][i] = 61;}}
    if ((!eatenByLeftTop)&&(c > 1)){for (short i = 0; i < row + col + 1; i++) {if (board[row + col + i][SIZE - i] != 64) board[row + col + i][SIZE - i] = 61;}}
    
    //LT-RB diag update
    bool eatenByLeftBot = (row >= col) ? true : false;
    if (eatenByLeftBot) {for (short i = 0; i < SIZE - col + row ; i++) if (board[row - col + i][i]==64) d++;}
    if (!eatenByLeftBot) {for (short i = 0; i < SIZE - col + row ; i++) if (board[i][col - row + i]==64) d++;}
    if ((eatenByLeftBot)&&(d > 1)) {for (short i = 0; i < SIZE + 1 - col + row ; i++) if (board[row - col + i][i] != 64) {board[row - col + i][i] = 61;}}
    if ((!eatenByLeftBot)&&(d > 1)) {for (short i = 0; i < SIZE - col + row  ; i++) if (board[i][col - row + i] != 64) {board[i][col - row + i] = 61;}}
}


int count(char board[][SIZE]){
    int cnt = 0;
    for (short i = 0; i < SIZE; i++){
        for (short j = 0; j < SIZE; j++)
            if (board[i][j] == 64) cnt++;
    }
    return cnt;
}

bool endGame(char board[][SIZE]){
    int cnt = 0;
    for (short i = 0; i < SIZE; i++){
        for (short j = 0; j < SIZE; j++)
            if (board[i][j] == 46) cnt++;
    }
    if (cnt == 0) return true;
    else return false;
}


int main(){
    static char board[SIZE][SIZE];
    initialiseBoard(board);
    while (!endGame(board)){
        char x; short y;
        printBoard(board);
        requestGrid(board, x , y);
        updateGrid(board, (short) x - 65, y);
    }
    printBoard(board);
    cout << "Num of pieces: " << count(board) << endl;
    return 0;
}

void initialiseBoard(char board[][SIZE]){
    for (short i = 0; i < SIZE; i++){
        for (short j = 0; j < SIZE ; j++) board[i][j]=46;
    }
}
