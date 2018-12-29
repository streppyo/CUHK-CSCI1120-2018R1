//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87

#include "DiamondCustomer.h"
#include <string>

DiamondCustomer::DiamondCustomer(string id, double d, double p):GoldCustomer(id, d){
    setPremium(p);
};
double DiamondCustomer::getPremium() const{
    return premium;
};
void DiamondCustomer::setPremium(double p){
    premium = (p < 1.1)? 1.1 : p;
};
double DiamondCustomer::rebate() const{
    return GoldCustomer::rebate() * premium;
};
double DiamondCustomer::shippingFee() const{
    return (GoldCustomer::shippingFee()-30 < 0)? 0 : GoldCustomer::shippingFee()-30;
};
