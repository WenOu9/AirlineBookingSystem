# ifndef BUSINESSCLASS_H_
# define BUSINESSCLASS_H_

#include <iostream>
#include <sstream>

using namespace std;

class BusinessClass: public Customer {
private:
  stringstream stringBusinessClass;

public:
  BusinessClass();
  BusinessClass(string n, string a, int pN, bool isC, double fC);
  BusinessClass(const BusinessClass &other); // copy constructor
  BusinessClass& operator = (const BusinessClass &other); //overloaded assignment operator
  ~BusinessClass(); // destructor
  void setIsWindow(); 
  void setTicketCost(double fC);
  string toString();
};

# endif