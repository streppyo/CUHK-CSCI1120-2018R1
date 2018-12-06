//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87

#include <iostream>

using namespace std;

int main() {
    int dd, mm, yy; //define variable for date, month and year
    int sdd, bdd, syy, byy; //define output variable for date, month and year
    int vart, varr, varc, vara, varg, varz, svarc, svara, svarr; //declare a list of intemediate variables, with some var serves as floor functions
    cout << "Enter a date (D M Y): ";
    cin >> dd >> mm >> yy;
    syy = (yy - 4) % 10 + 1; //expressed piecewise-defined function in a closed form
    byy = (yy - 4) % 12 + 1; //same as above
    vart = (mm + yy * 12 - 2.002)/ 12; //same as above
    varr = (mm + 9) % 12 + 3; //same as above
    varc = vart / 100;
    vara = vart % 100;
    svara = vara / 4;
    svarc = varc / 4;
    svarr = (3 * (varr + 1))/ 5;
    varg = 4 * varc + svarc + 5 * vara + svara + svarr + dd - 3;
    varz = 8 * varc + svarc + 5 * vara + svara + svarr + dd + 1 + 6 * (varr % 2);
    sdd = (varg - 1) % 10 + 1;
    bdd = (varz - 1) % 12 + 1;
    cout << "\n" << "Year:  " << "S" << syy << "-B" << byy << endl << "Month: " <<
    mm << endl << "Day:   " << "S" << sdd << "-B" << bdd <<endl; //print the output

    return 0;
    }
