#include <iostream>
#include <sstream>
#include "Customer.h"

using namespace std;

Customer::Customer() {
  reserved = false;
  name = "";
  address = "";
  int phoneNum = 0;
  bool isChild = false;
  int ticketCost = 0;
}

Customer::Customer(string n, string a, int pN, bool isC) {
  setReserved(true);
  setName(n);
  setAddress(a);
  setPhoneNum(pN);
  setIsChild(isC);
}

Customer::~Customer() {

}

bool Customer::getReserved() {
  return reserved;
}

string Customer::getName() {
  return name;
}

string Customer::getAddress() {
  return address;
}

int Customer::getPhoneNum() {
  return phoneNum;
}

bool Customer::getIsChild() {
  return isChild;
}

bool Customer::getIsWindow() {
  return isWindow;
}

double Customer::getTicketCost() {
  return ticketCost;
}

void Customer::setReserved(bool trueFalse) {
  reserved = trueFalse;
}

void Customer::setName(string n) {
  name = n;
}

void Customer::setAddress(string a) {
  address = a;
}

void Customer::setPhoneNum(int pN) {
  phoneNum = pN;
}

void Customer::setIsChild(bool isC) {
  isChild = isC;
}