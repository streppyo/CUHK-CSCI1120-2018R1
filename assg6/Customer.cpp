//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87

#include <cstring>
#include "Customer.h"
//#include <iostream>
#include <string>

Customer::Customer(string id){
    short cnt = 9;
    cid = "0000000000";
    for(short n = id.length()-1; n > -1 ; n--){
        if (((char) id[n] >= '0') && ((char) id[n] <= '9')) {cid[cnt] = id[n]; cnt--; if (cnt == -1) break;}
    ;}
    purchase = 0.00;
    weight = 0.50;
    //std::cout << "I am a constructor! My cid is " << cid << "!" << (char) 10;
};
string Customer::getCustomerID() const{
    return cid;
};
string Customer::getCustomerName() const{
    return name;
};
void Customer::setCustomerName(string n){
    name = n;
};
double Customer::getPurchaseAmount() const{
    return purchase;
};
void Customer::setPurchaseAmount(double p){
    purchase = (p < 0)? 0 : p;
};
double Customer::getWeight() const{
    return weight;
};
void Customer::setWeight(double w){
    weight = (w < 0.5)? 0.5 : w;
};
double Customer::rebate() const{
    double a, b, c;
    a = (purchase < 500)? purchase : 500 ;
    b = (purchase < 1500)? purchase - 500 : 1000;
    if (purchase < 500) b = 0;
    c = (purchase < 1500)? 0 : purchase - 1500;
    return 0.01 * a + 0.015 * b + 0.02 * c;
};
double Customer::shippingFee() const{
    if ((weight >= 8.00)&&(purchase < 400.00)) return 60;
    if ((weight >= 8.00)||(purchase < 400.00)) return 40;
    return 0;
};
