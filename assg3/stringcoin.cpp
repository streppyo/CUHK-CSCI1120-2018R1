//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
bool stringStatus(long long, int);
void displayNetwork(long long);
int playerScore(long long, int);
void updateNetwork(long long&, int, int);
int getisolatedcoin(long long);


/* Performs the task of Player p cutting a string in position pos of network.
 The reference parameter network should get updated, and if any coins are
 disconnected, the score of Player p should be incremented, to reflect the
 new network configuration */
void updateNetwork(long long &network, int pos, int p) {
    long long multi = 10000000000000;
    for (int k = pos; k > 1; k--)
    {multi /= 10;}
    int older = getisolatedcoin(network);
    network -= multi;
    int newer = getisolatedcoin(network);
    if (older < newer) {
        if (p == 1) {network += 10 * (newer - older);}
        if (p == 2) {network += (newer - older);}
    }
}

/* Returns true if position pos of the game network still has a string; returns
 false otherwise */
/* WARNING: CANNOT return FALSE for pos < 1 and pos > 12 */
bool stringStatus(long long network, int pos){
    network /= 100;
    for (int i = 0; i < 12 - pos; i++)
        network /= 10;
    return (network % 10 != 0);
}

/* Prints the network to the screen */
void displayNetwork(long long network) {
    int p1, p2;
    string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;
    
    p1 = network / 10 % 10;    // Player 1 score
    p2 = network % 10;         // Player 2 score
    
    s1 = stringStatus(network, 1)   ? "|"  : " ";
    s2 = stringStatus(network, 2)   ? "|"  : " ";
    s3 = stringStatus(network, 3)   ? "--" : "  ";
    s4 = stringStatus(network, 4)   ? "--" : "  ";
    s5 = stringStatus(network, 5)   ? "--" : "  ";
    s6 = stringStatus(network, 6)   ? "|"  : " ";
    s7 = stringStatus(network, 7)   ? "|"  : " ";
    s8 = stringStatus(network, 8)   ? "--" : "  ";
    s9 = stringStatus(network, 9)   ? "--" : "  ";
    s10 = stringStatus(network, 10) ? "--" : "  ";
    s11 = stringStatus(network, 11) ? "|"  : " ";
    s12 = stringStatus(network, 12) ? "|"  : " ";
    
    cout << "##########\n";
    cout << "#  " << s1 << "  " << s2 << "  #\n";
    cout << "#" << s3 << "$" << s4 << "$" << s5 << "#\n";
    cout << "#  " << s6 << "  " << s7 << "  #\n";
    cout << "#" << s8 << "$" << s9 << "$" << s10 << "#\n";
    cout << "#  " << s11 << "  " << s12 << "  # Player 1 score: " << p1 << "\n";
    cout << "########## Player 2 score: " << p2 << "\n";
}

/* Returns the score of Player p in network */
int playerScore(long long network, int p) {
    int s = 0;
    switch (p){
        case 1: s = network / 10 % 10 ; break;
        case 2: s = network % 10; break;
    }
    return s;
}

/* return the numbers of isolated coins */
int getisolatedcoin(long long network1) {
    int cnt = 0;
    if ((stringStatus(network1, 1) == 0 && stringStatus(network1, 3) == 0 && stringStatus(network1, 4) == 0 && stringStatus(network1, 6) == 0)) cnt++; //1, 3, 4, 6 TopLeft
    if ((stringStatus(network1, 2) == 0 && stringStatus(network1, 4) == 0 && stringStatus(network1, 5) == 0 && stringStatus(network1, 7) == 0)) cnt++; //2, 4, 5, 7 TopRight
    if ((stringStatus(network1, 6) == 0 && stringStatus(network1, 8) == 0 && stringStatus(network1, 9) == 0 && stringStatus(network1, 11) == 0)) cnt++; //6, 8, 9, 11 BotLeft
    if ((stringStatus(network1, 7) == 0 && stringStatus(network1, 9) == 0 && stringStatus(network1, 10) == 0 && stringStatus(network1, 12) == 0))  cnt++; //7, 9, 10, 12 BotRight
    return cnt++;
}

int main() {
    int p = 1; //Player 1 plays first
    int pos;
    long long network = 11111111111100;
    /* main game start here */
    while (playerScore(network, 1) + playerScore(network, 2) != 4){
        displayNetwork(network);
        cout << "Player " << p << " , make your move (1-12): ";
        cin >> pos ;
        int oldscore = playerScore(network, p);
        while ((stringStatus(network, pos) == 0) || (pos < 1) || (pos > 12)){
            cout << "Invalid. Try again!" << endl;
            cout << "Player " << p << " , make your move (1-12): ";
            cin >> pos;
        }
        updateNetwork(network, pos, p);
        if (playerScore(network, 1) + playerScore(network, 2) == 4) break;
        if (playerScore(network, p) > oldscore) {cout << "Player " << p << " scores! Gets another turn." << endl;
            continue;
        }
        if (playerScore(network, p) == oldscore) p = p == 1 ? 2 : 1;
    }
    //Game ends when sum of scores hit 4 for while loop
    if (playerScore(network, 1) != playerScore(network, 2)) {displayNetwork(network);
        cout << "Player " << p << " wins!" << endl; }
    else {displayNetwork(network);
        cout << "Draw game!" << endl;}
    
    return 0;
}
