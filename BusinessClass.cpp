#include <iostream>
#include <sstream>
#include "Customer.h"
#include "BusinessClass.h"

using namespace std;

BusinessClass::BusinessClass(): Customer() {

}

BusinessClass::BusinessClass(string n, string a, int pN, bool isC, double fC): Customer(n, a, pN, isC) {
  setIsWindow();
  setTicketCost(fC);
}

BusinessClass::BusinessClass(const BusinessClass &other) {
  reserved = other.reserved;
  name = other.name;
  address = other.address;
  phoneNum = other.phoneNum;
  isChild = other.isChild;
  isWindow = other.isWindow;
  ticketCost = other.ticketCost;
}

BusinessClass& BusinessClass::operator = (const BusinessClass &other) {
  if (this != &other) {
    reserved = other.reserved;
    name = other.name;
    address = other.address;
    phoneNum = other.phoneNum;
    isChild = other.isChild;
    isWindow = other.isWindow;
    ticketCost = other.ticketCost;
  }
  return *this;
}

BusinessClass::~BusinessClass() {

}

void BusinessClass::setIsWindow() {
  isWindow = true;
}

void BusinessClass::setTicketCost(double fC) {
  if (!isChild) {
    ticketCost = fC + fC/2;
  } else {
    ticketCost = 0.9*fC + fC/2;
  }
}

string BusinessClass::toString() {
  stringBusinessClass.str("");
  stringBusinessClass << "\nReserved: ";
  stringBusinessClass << reserved;
  stringBusinessClass << "\nName: ";
  stringBusinessClass << getName();
  stringBusinessClass << "\nAddress: ";
  stringBusinessClass << getAddress();
  stringBusinessClass << "\nPhone Number: ";
  stringBusinessClass << getPhoneNum();
  stringBusinessClass << "\nStatus: "; 
  if (isChild) {
    stringBusinessClass << "Adult";
  } else {
    stringBusinessClass << "Child";
  }
  stringBusinessClass << "\nWindow Seat: ";
  stringBusinessClass << getIsWindow();
  stringBusinessClass << "\nTicket Cost: ";
  stringBusinessClass << getTicketCost();
  return stringBusinessClass.str();
}