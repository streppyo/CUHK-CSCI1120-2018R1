//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87

#include "GoldCustomer.h"
#include <string>
#include <iostream>

GoldCustomer::GoldCustomer(string id, double d): Customer(id) {
    setShippingDiscount(d);
};
double GoldCustomer::getShippingDiscount() const{
    return shippingDiscount;
};
void GoldCustomer::setShippingDiscount(double d){
    if (d > 1) d = 1; if (d < 0.1) d = 0.1;
    shippingDiscount = d;
};
double GoldCustomer::rebate() const{
    double a, b, c;
    a = (Customer::getPurchaseAmount() < 500)? Customer::getPurchaseAmount() : 500 ;
    b = (Customer::getPurchaseAmount() < 1500)? Customer::getPurchaseAmount() - 500 : 1000;
    if (Customer::getPurchaseAmount() < 500) b = 0;
    c = (Customer::getPurchaseAmount() < 1500)? 0 : Customer::getPurchaseAmount() - 1500;
    return 0.01 * a + 0.017 * b + 0.024 * c;
};
double GoldCustomer::shippingFee() const{
    return Customer::shippingFee() * (1-getShippingDiscount());
};

