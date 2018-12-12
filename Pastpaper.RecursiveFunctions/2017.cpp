#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int cntUpper(string str){
    if (str[0] == '\0') return 0;
    if (isupper(str[0])) return 1 + cntUpper(str.substr(1));
    else return cntUpper(str.substr(1));
}
int main(){cout << "Enter: "; string x;
    getline(cin,x); cout << "Result: " << cntUpper(x)<<endl;return 0;}
