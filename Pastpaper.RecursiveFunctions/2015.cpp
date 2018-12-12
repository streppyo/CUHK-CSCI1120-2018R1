#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

void triangle (int n){if (n!=0){
    for (int i = 0; i < n; i++) cout << '*'; cout << (char)10;
    triangle (n-1);}
}

int main(){cout << "Enter: "; int x;
    cin >> x; triangle(x); return 0;}
