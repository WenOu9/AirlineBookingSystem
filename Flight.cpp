#include <iostream>
#include <sstream>
#include "Flight.h"

using namespace std;

Flight::Flight() {
  flightName = "";
  flightCost = 0;
  flightTime = false;
  bC = new BusinessClass[3];
  eC = new EconomyClass[7];
  for (int i = 0; i < 10; i++) {
    if (i < 3) {
      bC[i] = BusinessClass();
    } else {
      eC[i-3] = EconomyClass();
    }
  }
}

Flight::Flight(string fN, double fC, bool fT) {
  setFlightName(fN);
  setFlightCost(fC);
  setFlightTime(fT);
  bC = new BusinessClass[3];
  eC = new EconomyClass[7];
  for (int i = 0; i < 10; i++) {
    if (i < 3) {
      bC[i] = BusinessClass();
    } else {
      eC[i-3] = EconomyClass();
    }
  }
}

Flight::~Flight() {
  delete[] bC;
  delete[] eC;
}

string Flight::getFlightName() {
  return flightName;
}

double Flight::getFlightCost() {
  return flightCost;
}

bool Flight::getFlightTime() {
  return flightTime;
}

BusinessClass Flight::getBusinessClass(int n) {
  return bC[n];
}

EconomyClass Flight::getEconomyClass(int n) {
  return eC[n];
}

void Flight::setBusinessClass(int n, BusinessClass &busCla) {
  bC[n-1] = busCla;
}

void Flight::setEconomyClass(int n, EconomyClass &ecoCla) {
  eC[n-4] = ecoCla;
}

void Flight::cancelSeat(int n) {
  if (n <= 3) {
    bC[n-1].setReserved(false);
  } else {
    eC[n-4].setReserved(false);
  }
}

void Flight::setFlightName(string fN) {
  flightName = fN;
}

void Flight::setFlightCost(double fC) {
  flightCost = fC;
}

void Flight::setFlightTime(bool trueFalse) {
  flightTime = trueFalse;
}

string Flight::toString() {
  stringFlight.str("");
  stringFlight << "\nFlight Name: ";
  stringFlight << getFlightName();
  stringFlight << "\nFlight Cost: ";
  stringFlight << getFlightCost();
  stringFlight << "\nFlight Time: ";
  stringFlight << getFlightTime();
  stringFlight << "\nSeat Info (reserved or not): \n";
  for (int i = 1; i <= 10; i++) {
    if (i <= 3) {
      stringFlight << i << ": " << bC[i-1].getReserved() << "\n";
    } else {
      stringFlight << i << ": " << eC[i-4].getReserved() << "\n";
    }
  }
  return stringFlight.str();
}