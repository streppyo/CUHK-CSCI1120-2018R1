//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87

#include "Customer.h"
#include "GoldCustomer.h"
#include "DiamondCustomer.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include <stdio.h>


using namespace std;

int main() {
    int n = 1 , i = 0;
    string x, fname;
    //vector<Customer *> customers(n);
    //cin >> x;
    //customers[i] = new Customer(x);
    cout << "Enter file name: " ;
    getline(cin, fname);
    ifstream fin(fname.c_str());//insert path here, if fail in testing
    if (fin.fail()) {cout << "Cannot open data file. Program exit!" << endl; exit(1);}
    fin >> x;
    //cout << x;
    n = stoi(x);
    vector<Customer *> customers(n);
    while(!fin.eof()){
        fin >> x;
        if(x.compare("SC") == 0) {
            fin >> x;
            customers[i] = new Customer(x);
            fin >> x;
            customers[i]->setCustomerName(x);
            fin >> x;
            customers[i]->setPurchaseAmount(stod(x));
            fin >> x;
            customers[i]->setWeight(stod(x));
            }
        else if(x.compare("GC") == 0){//((GoldCustomer *)customers[i])
            fin >> x;
            customers[i] = new GoldCustomer(x);
            fin >> x;
            customers[i]->setCustomerName(x);
            fin >> x;
            customers[i]->setPurchaseAmount(stod(x));
            fin >> x;
            customers[i]->setWeight(stod(x));
            fin >> x;
            ((GoldCustomer *)customers[i])->setShippingDiscount(stod(x));
            }
        else if(x.compare("DC") == 0){//((DiamondCustomer *)customers[i])
            fin >> x;
            customers[i] = new DiamondCustomer(x);
            fin >> x;
            customers[i]->setCustomerName(x);
            fin >> x;
            customers[i]->setPurchaseAmount(stod(x));
            fin >> x;
            customers[i]->setWeight(stod(x));
            fin >> x;
            ((DiamondCustomer *)customers[i])->setShippingDiscount(stod(x));
            fin >> x;
            ((DiamondCustomer *)customers[i])->setPremium(stod(x));
        }
        if (i < n-1) i++;
    }
    fin.close();
    cout << "Process "<< n <<" customer(s):" << (char) 10;
    for(int i = 0; i < n ; i++){
        cout << customers[i]->getCustomerID() <<' ';
        cout << fixed << setprecision(2) << customers[i]->rebate() << ' ';
        cout << fixed << setprecision(2) << customers[i]->shippingFee();
        cout << endl;
    }
    for(short k = 0; k < n; k++) delete customers[k];
     return 0;
}

