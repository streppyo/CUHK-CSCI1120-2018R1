#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

string endX(string str){
    if (str[0] == '\0') return "";
    if (str[0] == 'x') return endX(str.substr(1)) + "x";
    else return str[0] + endX(str.substr(1));
}
int main(){cout << "Enter: "; string x;
    getline(cin,x); cout << "Result: " << endX(x)<<endl;return 0;}
