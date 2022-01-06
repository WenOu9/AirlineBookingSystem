#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Flight.h"
#include "Customer.h"
#include "BusinessClass.h"
#include "EconomyClass.h"

using namespace std;

// some testings for input to maintain stability of program annotated in comments

int main() {
  Flight *f1 = new Flight("Toronto to Calgary", 200, false);
  Flight *f2 = new Flight("Ottawa to Vancouver", 500, false);
  bool reserve = true;
  int randomNum;
  srand(time(0)); //will determine when flights are cancelled or should take off, use srand() instead of rand() to ensure different results every run

  while (reserve) {
    // insert rand() right here so it will refresh every loop
    randomNum = (rand()%100) + 1;
    if (randomNum < 10) {
      // flight 1 cancelled
      cout << "Unpredicted circumstance, " << f1->getFlightName() << " flight cancelled. " << endl;
      for (int i = 0; i < 10; i++) {
        if (i < 3) {
          if (f1->getBusinessClass(i).getReserved()) {
            cout << "Calling " << to_string(f1->getBusinessClass(i).getPhoneNum()) << "... Hello " << f1->getBusinessClass(i).getName() << ", you have been refunded " << to_string(f1->getBusinessClass(i).getTicketCost()) << " dollars. We are sorry for the inconvenience." << endl;
            f1->cancelSeat(i+1);
          }
        } else {
          if (f1->getEconomyClass(i-3).getReserved()) {
            cout << "Calling " << to_string(f1->getEconomyClass(i-3).getPhoneNum()) << "... Hello " << f1->getEconomyClass(i-3).getName() << ", you have been refunded " << to_string(f1->getEconomyClass(i-3).getTicketCost()) << " dollars. We are sorry for the inconvenience." << endl;
            f1->cancelSeat(i+1);
          }
        }
      }

    } else if (randomNum < 20) {
      // flight 2 cancelled
      cout << "Unpredicted circumstance, " << f2->getFlightName() << " flight cancelled." << endl;
      for (int i = 0; i < 10; i++) {
        if (i < 3) {
          if (f2->getBusinessClass(i).getReserved()) {
            cout << "Calling " << to_string(f2->getBusinessClass(i).getPhoneNum()) << "... Hello " << f2->getBusinessClass(i).getName() << ", you have been refunded " << to_string(f2->getBusinessClass(i).getTicketCost()) << " dollars. We are sorry for the inconvenience." << endl;
            f2->cancelSeat(i+1);
          }
        } else {
          if (f2->getEconomyClass(i-3).getReserved()) {
            cout << "Calling " << to_string(f2->getEconomyClass(i-3).getPhoneNum()) << "... Hello " << f2->getEconomyClass(i-3).getName() << ", you have been refunded " << to_string(f2->getEconomyClass(i-3).getTicketCost()) << " dollars. We are sorry for the inconvenience." << endl;
            f2->cancelSeat(i+1);
          }
        }
      }

    } else if (randomNum > 80) {
      // both flights take off
      cout << "\nFlight time reached. " << endl;

      cout << endl << f1->getFlightName() << " flight passengers in seat order: " << endl;
      for (int i = 0; i < 10; i++) {
        if (i < 3) {
          if (f1->getBusinessClass(i).getReserved()) {
            cout << "Passenger name: " << f1->getBusinessClass(i).getName() << endl;
            cout << "Passenger phone number: " << to_string(f1->getBusinessClass(i).getPhoneNum()) << endl;
          }
        } else {
          if (f1->getEconomyClass(i-3).getReserved()) {
            cout << "Passenger name: " << f1->getBusinessClass(i-3).getName() << endl;
            cout << "Passenger phone number: " << to_string(f1->getBusinessClass(i-3).getPhoneNum()) << endl;
          }
        }
      }

      cout << endl << f1->getFlightName() << " flight passengers in alphabetic order: " << endl;
      int min, index, check;
      min = 200; // larger ascii value than all letters to start off
      bool run = true;
      while (run) {
        check = 2;
        for (int i = 0; i < 10; i++) {
          if (i < 3) {
            if (f1->getBusinessClass(i).getReserved() && (int)f1->getBusinessClass(i).getName().at(0) < min) {
              min = (int)f1->getBusinessClass(i).getName().at(0);
              index = i;
              check = 0;
            }
          } else {
            if (f1->getEconomyClass(i-3).getReserved() && (int)f1->getEconomyClass(i-3).getName().at(0) < min) {
              min = (int)f1->getEconomyClass(i-3).getName().at(0);
              index = i-3;
              check = 1;
            }
          }
        }
        if (check == 0) {
          cout << "Passenger name: " << f1->getBusinessClass(index).getName() << endl;
          cout << "Passenger phone number: " << to_string(f1->getBusinessClass(index).getPhoneNum()) << endl;
          f1->cancelSeat(index+1);
        } else if (check == 1) {
          cout << "Passenger name: " << f1->getEconomyClass(index).getName() << endl;
          cout << "Passenger phone number: " << to_string(f1->getEconomyClass(index).getPhoneNum()) << endl;        
          f1->cancelSeat(index+1);
        } else {
          run = false;
        }
      }

      cout << endl << f2->getFlightName() << " flight passengers in seat order: " << endl;
      for (int i = 0; i < 10; i++) {
        if (i < 3) {
          if (f2->getBusinessClass(i).getReserved()) {
            cout << "Passenger name: " << f2->getBusinessClass(i).getName() << endl;
            cout << "Passenger phone number: " << to_string(f2->getBusinessClass(i).getPhoneNum()) << endl;
          }
        } else {
          if (f2->getEconomyClass(i-3).getReserved()) {
            cout << "Passenger name: " << f2->getEconomyClass(i-3).getName() << endl;
            cout << "Passenger phone number: " << to_string(f2->getEconomyClass(i-3).getPhoneNum()) << endl;
          }
        }
      }
      cout << endl << f2->getFlightName() << " flight passengers in alphabetic order: " << endl; 
      run = true;
      min = 200; 
      while (run) {
        check = 2;
        for (int i = 0; i < 10; i++) {
          if (i < 3) {
            if (f2->getBusinessClass(i).getReserved() && (int)f2->getBusinessClass(i).getName().at(0) < min) {
              min = (int)f2->getBusinessClass(i).getName().at(0);
              index = i;
              check = 0;
            }
          } else {
            if (f2->getEconomyClass(i-3).getReserved() && (int)f2->getEconomyClass(i-3).getName().at(0) < min) {
              min = (int)f2->getEconomyClass(i-3).getName().at(0);
              index = i-3;
              check = 1;
            }
          }
        }
        if (check == 0) {
          cout << "Passenger name: " << f2->getBusinessClass(index).getName() << endl;
          cout << "Passenger phone number: " << to_string(f2->getBusinessClass(index).getPhoneNum()) << endl;
          f2->cancelSeat(index+1);
        } else if (check == 1) {
          cout << "Passenger name: " << f2->getEconomyClass(index).getName() << endl;
          cout << "Passenger phone number: " << to_string(f2->getEconomyClass(index).getPhoneNum()) << endl;        
          f2->cancelSeat(index+1);
        } else {
          run = false;
        }
      }
    }

    cout << "\nWelcome to Fly-By-Night Airlines! Please select one the choices below by inputting a number." << endl << endl;
    cout << "1. Request a ticket" << endl;
    cout << "2. Cancel a ticket" << endl;
    cout << "3. Access user guide" << endl;
    cout << "4. Exit program" << endl;

    int input;
    string name;
    string address;
    int phoneNum;
    bool isChild;
    cin >> input;

    if (input == 1) { 
      cout << "\nPlease select a flight:" << endl;
      cout << "1. " << f1->getFlightName() << endl;
      cout << "2. " << f2->getFlightName() << endl;
      cin >> input;

      if (input == 1) {
        cout << "\nInformation on the flight:" << endl;
        cout << f1->toString() << endl;
        cout << "\nPlease choose a seat (1-3 is Business Class, the rest is Economy Class): ";
        cin >> input; 

        if (input <= 3) {
          if (f1->getBusinessClass(input-1).getReserved()) {
            cout << "\nSeat has been reserved." << endl;
          } else {
            cout << "Please enter your name: "; 
            cin >> name; // crash resistant input
            cout << "Please enter your address: ";
            cin >> address; // crash resistant input
            cout << "Please enter your phone number: ";
            cin >> phoneNum;
            cout << "Are you below 12 years of age? (0 for no and 1 for yes) ";
            cin >> isChild;
            BusinessClass *bC = new BusinessClass(name, address, phoneNum, isChild, f1->getFlightCost());
            f1->setBusinessClass(input, *bC);
            cout << "\nYou have successfully booked a fight. Here's your info: " << endl;
            cout << f1->getBusinessClass(input-1).toString() << endl << endl;
            cout << "Flight info: " << endl;
            cout << f1->toString() << endl;
          }

        } else {

          if (f1->getEconomyClass(input).getReserved()) {
            cout << "\nSeat has been reserved." << endl;
          } else {
            cout << "\nPlease enter your name: "; 
            cin >> name;
            cout << "Please enter your address: ";
            cin >> address;
            cout << "Please enter your phone number: ";
            cin >> phoneNum;
            cout << "Are you below 12 years of age? (0 for no and 1 for yes) ";
            cin >> isChild;
            EconomyClass *eC = new EconomyClass(name, address, phoneNum, isChild, f1->getFlightCost());
            f1->setEconomyClass(input, *eC);
            cout << "\nYou have successfully booked a fight. Here's your info: " << endl;
            cout << f1->getEconomyClass(input-4).toString() << endl << endl;
            cout << "Flight info: " << endl;
            cout << f1->toString() << endl;
          }
        }

      } else if (input == 2) {

        cout << "\nInformation on the flight:" << endl;
        cout << f2->toString() << endl;
        cout << "\nPlease choose a seat (1-3 is Business Class, the rest is Economy Class): ";
        cin >> input; 

        if (input <= 3) {
          if (f2->getBusinessClass(input-1).getReserved()) {
            cout << "\nSeat has been reserved." << endl;
          } else {
            cout << "\nPlease enter your name: "; 
            cin >> name;
            cout << "Please enter your address: ";
            cin >> address;
            cout << "Please enter your phone number: ";
            cin >> phoneNum;
            cout << "Are you below 12 years of age? (0 for no and 1 for yes) ";
            cin >> isChild;
            BusinessClass *bC = new BusinessClass(name, address, phoneNum, isChild, f2->getFlightCost());
            f2->setBusinessClass(input, *bC);
            cout << "\nYou have successfully booked a fight. Here's your info: " << endl;
            cout << f2->getBusinessClass(input-1).toString() << endl << endl;
            cout << "Flight info: " << endl;
            cout << f2->toString() << endl;
          }

        } else {

          if (f2->getEconomyClass(input).getReserved()) {
            cout << "\nSeat has been reserved." << endl;
          } else {
            cout << "\nPlease enter your name: "; 
            cin >> name;
            cout << "Please enter your address: ";
            cin >> address;
            cout << "Please enter your phone number: ";
            cin >> phoneNum;
            cout << "Are you below 12 years of age? (0 for no and 1 for yes) ";
            cin >> isChild;
            EconomyClass *eC = new EconomyClass(name, address, phoneNum, isChild, f2->getFlightCost());
            f2->setEconomyClass(input, *eC);
            cout << "\nYou have successfully booked a fight. Here's your info: " << endl;
            cout << f2->getEconomyClass(input-4).toString() << endl << endl;
            cout << "Flight info: " << endl;
            cout << f2->toString() << endl;
          }
        }

      } else {

        // if input is int other than 1-2, will prompt user to enter again. If else, then reach flight time and exit program
        cout << "\nInvalid input. Please enter a number from 1-2." << endl;
        cin >> input;
      }

    } else if (input == 2) {

      cout << "\nPlease select a flight:" << endl;
      cout << "1. " << f1->getFlightName() << endl;
      cout << "2. " << f2->getFlightName() << endl;
      cin >> input;

      if (input == 1) {
        cout << "\nInformation on the flight:" << endl;
        cout << f1->toString() << endl;
        cout << "\nPlease choose a seat to cancel: ";
        cin >> input;
        f1->cancelSeat(input);
        cout << endl;
        cout << "\nSeat cancelled. Flight information below: " << endl;
        cout << f1->toString() << endl;

      } else if (input == 2) {

        cout << "\nInformation on the flight:" << endl;
        cout << f2->toString() << endl;
        cout << "\nPlease choose a seat to cancel: ";
        cin >> input;
        f2->cancelSeat(input);
        cout << endl;
        cout << "\nSeat cancelled. Flight information below: " << endl;
        cout << f2->toString() << endl; 

      } else {

        // if input is int other than 1-2, will prompt user to enter again. If else, then reach flight time and exit program
        cout << "\nInvalid input. Please enter a number from 1-2." << endl;
        cin >> input;
      }

    } else if (input == 3) {

      cout << "\nWelcome to the user guide! To purchase or cancel a ticket, input 1 and 2 respectively. After which you will be able to select the flight that you wish to access, and from there you can pick the seat to book/cancel. Booking a seat would prompt the program to ask for user info, so input that accordingly. Once done, the user can exit the program by pressing 4.\n" << endl;

    } else if (input == 4) {

      cout << "\nProgram exited, have a great day." << endl;
      delete f1;
      delete f2;
      reserve = false;

    } else {
      // if input is int other than 1-4, will prompt user to enter again. If else, then reach flight time and exit program
      cout << "\nInvalid input. Please enter a number from 1-4." << endl;
      cin >> input;
    }
  }
  return 0;
}