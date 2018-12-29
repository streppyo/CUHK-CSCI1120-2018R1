#include "Customer.h"
#include "GoldCustomer.h"
#include "DiamondCustomer.h"

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip>

using namespace std;

int main()
{
  Customer cus_1("5ad78e9f");
  cout<<cus_1.getCustomerID()<<endl;
  cout<<cus_1.getWeight()<<endl;
  cout<<cus_1.getPurchaseAmount()<<endl;


  Customer cus_2("3478562109");
  cout<<cus_2.getCustomerID()<<endl;
  cout<<cus_1.getWeight()<<endl;
  cout<<cus_1.getPurchaseAmount()<<endl;


  Customer cus_3("zs790xfe821cdef0324667");
  cout<<cus_3.getCustomerID()<<endl;
  cout<<cus_1.getWeight()<<endl;
  cout<<cus_1.getPurchaseAmount()<<endl;


  Customer cus_4("zftyefcba");
  cout<<cus_4.getCustomerID()<<endl;
  cout<<cus_1.getWeight()<<endl;
  cout<<cus_1.getPurchaseAmount()<<endl;

  cus_1.setCustomerName("test1");
  cout<<cus_1.getCustomerName()<<endl;

  cus_1.setWeight(8.3);
  cus_3.setWeight(8.3);
  cout<<"weight(8.3): "<<cus_1.getWeight()<<endl;
  cus_2.setWeight(0.3);
  cus_4.setWeight(2.8);
  cout<<"weight(0.3): "<<cus_2.getWeight()<<endl;

  cus_1.setPurchaseAmount(176);
  cus_3.setPurchaseAmount(1982);
  cout<<"PushchaseAmound(176)\t"<<cus_1.getPurchaseAmount()<<endl;
  cout<<"PushchaseAmound(1982)\t"<<cus_3.getPurchaseAmount()<<endl;
  cus_2.setPurchaseAmount(176);
  cus_4.setPurchaseAmount(1400);


  // 8.3, 176
  cout<<"cus_1(8.3,176) shipping Fee:\t "<<cus_1.shippingFee()<<endl;
  // 8.3, 1982
  cout<<"cus_3(8.3,1982) shipping Fee:\t "<<cus_3.shippingFee()<<endl;
  //0.3, 176
  cout<<"cus_2(0.3,176) shipping Fee:\t "<<cus_2.shippingFee()<<endl;
  //2.8, 1400
  cout<<"cus_4(2.8,1400) shipping Fee:\t "<<cus_4.shippingFee()<<endl;

  cout<<"rebate(176)\t"<<cus_1.rebate()<<endl;
  cout<<"rebate(1982)\t"<<cus_3.rebate()<<endl;
  cout<<"rebate(1400)\t"<<cus_4.rebate()<<endl;

  cout<<"****************GoldCustomer*********"<<endl;

  GoldCustomer gold_cus1("5ad78e9f",1.1);
  cout<<"Intialize GoldCustomer (5ad78e9f, 1.1)\t"<<gold_cus1.getCustomerID()<<'\t'<<gold_cus1.getShippingDiscount()<<endl;

  GoldCustomer gold_cus2("8790281635",0);
  cout<<"Intialize GoldCustomer (8790281635, 0)\t"<<gold_cus2.getCustomerID()<<'\t'<<gold_cus2.getShippingDiscount()<<endl;
  

  GoldCustomer gold_cus3("zs790xfe821cdef0324667",0.4);
  cout<<"Intialize GoldCustomer (zs790xfe821cdef0324667, 0.4)\t"<<gold_cus3.getCustomerID()<<'\t'<<gold_cus3.getShippingDiscount()<<endl;

  gold_cus1.setShippingDiscount(1.6);
  cout<<"setShippingDiscount(1.6)\t"<<gold_cus1.getShippingDiscount()<<endl;

  gold_cus2.setShippingDiscount(0.2);
  cout<<"setShippingDiscount(0.2)\t"<<gold_cus2.getShippingDiscount()<<endl;

  gold_cus3.setShippingDiscount(-0.5);
  cout<<"setShippingDiscount(-0.5)\t"<<gold_cus3.getShippingDiscount()<<endl;



  gold_cus1.setPurchaseAmount(176);
  gold_cus1.setWeight(2.8);
  gold_cus1.setShippingDiscount(0.1);
  cout<<"GoldCustomer ShippingFee (1): "<<gold_cus1.getPurchaseAmount()<<'\t'<<gold_cus1.getWeight()<<'\t'<<gold_cus1.getShippingDiscount()<<'\t'<<gold_cus1.shippingFee()<<endl;


  gold_cus2.setPurchaseAmount(1982);
  gold_cus2.setWeight(8.3);
  gold_cus2.setShippingDiscount(0.5);
  cout<<"GoldCustomer ShippingFee (2): "<<gold_cus2.getPurchaseAmount()<<'\t'<<gold_cus2.getWeight()<<'\t'<<gold_cus2.getShippingDiscount()<<'\t'<<gold_cus2.shippingFee()<<endl;

  cout<<"rebate (176): "<< gold_cus1.rebate()<<endl;
  cout<<"rebate (1982): "<< gold_cus2.rebate()<<endl;

  gold_cus3.setPurchaseAmount(1400);
  cout<<"rebate (1400): "<< gold_cus3.rebate()<<endl;


  cout<<"****************DiamondCustomer*********"<<endl;
  DiamondCustomer dia_cus1("5ad78e9f", 0.4, 1.6);
  cout<<"DiamondCustomer(5ad78e9f, 0.4, 1.6)\t"<<dia_cus1.getCustomerID()<<'\t'<<dia_cus1.getShippingDiscount()<<'\t'<<dia_cus1.getPremium()<<endl;

  DiamondCustomer dia_cus2("87902816354", 0, 1.0);
  cout<<"DiamondCustomer(87902816354, 0, 1.0)\t"<<dia_cus2.getCustomerID()<<'\t'<<dia_cus2.getShippingDiscount()<<'\t'<<dia_cus2.getPremium()<<endl;

  dia_cus1.setPremium(1.05);
  cout<<"setPremium(1.05)\t"<<dia_cus1.getPremium()<<endl;

  dia_cus2.setPremium(1.2);
  cout<<"setPremium(1.2)\t"<<dia_cus2.getPremium()<<endl;

  dia_cus1.setPurchaseAmount(176);
  dia_cus1.setWeight(2.8);
  dia_cus1.setShippingDiscount(0.1);
  cout<<"Diamond ShippingFee (1): "<<dia_cus1.getPurchaseAmount()<<'\t'<<dia_cus1.getWeight()<<'\t'<<dia_cus1.getShippingDiscount()<<'\t'<<dia_cus1.shippingFee()<<endl;


  dia_cus2.setPurchaseAmount(1982);
  dia_cus2.setWeight(8.3);
  dia_cus2.setShippingDiscount(0.5);
  cout<<"Diamond ShippingFee (2): "<<dia_cus2.getPurchaseAmount()<<'\t'<<dia_cus2.getWeight()<<'\t'<<dia_cus2.getShippingDiscount()<<'\t'<<dia_cus2.shippingFee()<<endl;

  dia_cus2.setPurchaseAmount(176);
  dia_cus2.setWeight(8.3);
  dia_cus2.setShippingDiscount(0.1);
  cout<<"Diamond ShippingFee (3): "<<dia_cus2.getPurchaseAmount()<<'\t'<<dia_cus2.getWeight()<<'\t'<<dia_cus2.getShippingDiscount()<<'\t'<<dia_cus2.shippingFee()<<endl;

  dia_cus1.setPurchaseAmount(1982);
  dia_cus1.setPremium(1.2);
  cout<<"Diamond rebate (1) "<< dia_cus1.getPurchaseAmount()<<'\t'<<dia_cus1.getPremium()<<'\t'<< dia_cus1.rebate()<<endl;

  dia_cus1.setPurchaseAmount(489);
  dia_cus1.setPremium(1.6);
  cout<<"Diamond rebate (2) "<< dia_cus1.getPurchaseAmount()<<'\t'<<dia_cus1.getPremium()<<'\t'<< dia_cus1.rebate()<<endl;

  dia_cus1.setPurchaseAmount(1687);
  dia_cus1.setPremium(1.5);
  cout<<"Diamond rebate (3) "<< dia_cus1.getPurchaseAmount()<<'\t'<<dia_cus1.getPremium()<<'\t'<< dia_cus1.rebate()<<endl;

}

