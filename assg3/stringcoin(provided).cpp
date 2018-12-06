#include <iostream>
#include <string>
using namespace std;

// Function prototypes
bool stringStatus(long long network, int pos);
void displayNetwork(long long network);
int playerScore(long long network, int p);
void updateNetwork(long long &network, int pos, int p);

/* Returns true if position pos of the game network still has a string; returns
   false otherwise */
bool stringStatus(long long network, int pos) {
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
    // TO DO


    return s;
}

/* Performs the task of Player p cutting a string in position pos of network.
   The reference parameter network should get updated, and if any coins are
   disconnected, the score of Player p should be incremented, to reflect the
   new network configuration */
void updateNetwork(long long &network, int pos, int p) {
    // TO DO


}

int main() {
    // TO DO


    return 0;
}
