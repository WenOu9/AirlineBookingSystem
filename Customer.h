# ifndef CUSTOMER_H_
# define CUSTOMER_H_

#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
  bool reserved;
  string name, address;
  int phoneNum;
  bool isChild; // children get 10% discount
  bool isWindow;
  double ticketCost; // determined by the flight, class, and isChild
  friend class BusinessClass;  // allows members of the class access to private variables of Customer (specifically used for the copy constructor)
  friend class EconomyClass;

public:
  Customer();
  Customer(string n, string a, int pN, bool isC);
  virtual ~Customer(); // ensures the deleting of memory not only from the base class, but also the derived classes
  bool getReserved();
  string getName();
  string getAddress();
  int getPhoneNum();
  bool getIsChild();
  bool getIsWindow();
  double getTicketCost();
  void setReserved(bool trueFalse);
  void setName(string n);
  void setAddress(string a);
  void setPhoneNum(int pN);
  void setIsChild(bool isC);
  virtual void setIsWindow() = 0;
  virtual void setTicketCost(double fC) = 0;
  virtual string toString() = 0; // Pure virtual function will be defined in each of the other classes individually in order to excecute differently. Customer is now an abstract class used by other classes as a base class
};

# endif