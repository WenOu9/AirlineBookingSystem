# ifndef ECONOMYCLASS_H_
# define ECONOMYCLASS_H_

#include <iostream>
#include <sstream>

using namespace std;

class EconomyClass: public Customer {
private:
  stringstream stringEconomyClass;

public:
  EconomyClass();
  EconomyClass(string n, string a, int pN, bool isC, double fC);
  EconomyClass(const EconomyClass &other); // copy constructor
  EconomyClass& operator = (const EconomyClass &other); // overloaded assignment operator
  ~EconomyClass(); // destructor
  void setIsWindow();
  void setTicketCost(double fC);
  string toString();
};

# endif