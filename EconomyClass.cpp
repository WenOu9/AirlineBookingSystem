#include <iostream>
#include <sstream>
#include "Customer.h"
#include "EconomyClass.h"

using namespace std;

EconomyClass::EconomyClass(): Customer() {
  
}

EconomyClass::EconomyClass(string n, string a, int pN, bool isC, double fC): Customer(n, a, pN, isC) {
  setIsWindow();
  setTicketCost(fC);
}

EconomyClass::EconomyClass(const EconomyClass &other) {
  reserved = other.reserved;
  name = other.name;
  address = other.address;
  phoneNum = other.phoneNum;
  isChild = other.isChild;
  isWindow = other.isWindow;
  ticketCost = other.ticketCost;
}

EconomyClass& EconomyClass::operator = (const EconomyClass &other) {
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

EconomyClass::~EconomyClass() {

}

void EconomyClass::setIsWindow() {
  isWindow = false;
}

void EconomyClass::setTicketCost(double fC) {
  if (!isChild) {
    ticketCost = fC;
  } else {
    ticketCost = 0.9*fC;
  }
}

string EconomyClass::toString() {
  stringEconomyClass.str("");
  stringEconomyClass << "\nName: ";
  stringEconomyClass << getName();
  stringEconomyClass << "\nAddress: ";
  stringEconomyClass << getAddress();
  stringEconomyClass << "\nPhone Number: ";
  stringEconomyClass << getPhoneNum();
  stringEconomyClass << "\nStatus: "; 
  if (isChild) {
    stringEconomyClass << "Adult";
  } else {
    stringEconomyClass << "Child";
  }
  stringEconomyClass << "\nWindow Seat: ";
  stringEconomyClass << getIsWindow();
  stringEconomyClass << "\nTicket Cost: ";
  stringEconomyClass << getTicketCost();
  return stringEconomyClass.str();
}