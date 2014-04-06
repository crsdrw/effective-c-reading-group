// BadExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <memory>

int treasury = 1000000;

class Investment {
	int value_;
  public:
    static const int MINIMUM = 25;
  
    Investment() : value_(0) {}
    virtual ~Investment() { }
    void buy(int amount) { value_ += amount; }
    
    static void seize(Investment *inv){
    	if(inv) {
    	  treasury += inv->value_;
      }
    	delete inv;
    }
};

class Bond : public Investment  {
};

class Stock : public Investment {
};

std::shared_ptr<Investment> createInvestment(bool buy_stock) {
  // Why bother with the deleter here:
  //std::shared_ptr<Investment> inv(nullptr, Investment::seize);
  
  // this works just as well:
  std::shared_ptr<Investment> inv;
  
  if (buy_stock) {
    //inv = std::shared_ptr<Investment>(new Stock(), Investment::seize);
    inv.reset(new Stock(), Investment::seize);
    //inv.reset(new Stock()); // This seems to remove the existing deleter
  } else {
  	inv.reset(new Bond(), Investment::seize);
  }
  
  inv->buy(Investment::MINIMUM);
  
  return inv;
}

void playTheMarkets() {
  std::shared_ptr<Investment> stocks(createInvestment(true)); 
  std::shared_ptr<Investment> bonds(createInvestment(false));	
}

int _tmain() {
  treasury = 1000000;
  playTheMarkets();
  std::cout << treasury << std::endl;
}

