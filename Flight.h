# ifndef FLIGHT_H_
# define FLIGHT_H_

#include <iostream>
#include <string>
#include "Customer.h"
#include "BusinessClass.h"
#include "EconomyClass.h"

using namespace std;

class Flight {
private:
  string flightName;
  double flightCost;
  bool flightTime;
  BusinessClass *bC; // array that stores BusinessClass objects
  EconomyClass *eC; // array that stores EconomyClass objects
  friend class BusinessClass;
  friend class EconomyClass;
  stringstream stringFlight;

public:
  Flight();
  Flight(string fN, double fC, bool fT);
  ~Flight();
  string getFlightName();
  double getFlightCost();
  bool getFlightTime();
  BusinessClass getBusinessClass(int n);
  EconomyClass getEconomyClass(int n);
  void setBusinessClass(int n, BusinessClass &busCla);
  void setEconomyClass(int n, EconomyClass &ecoCla);
  void cancelSeat(int n); //reset reserved to false to allow for new assignments
  void setFlightName(string fN);
  void setFlightCost(double fC);
  void setFlightTime(bool trueFalse);
  string toString();
};

# endif