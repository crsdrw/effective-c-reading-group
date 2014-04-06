// item-13.cpp : Code up of the examples.
//

#include "stdafx.h"

#include <iostream>
#include <memory>

struct Investment {
  Investment() { std::cout << "Investment constructed" << std::endl;}
  ~Investment() { std::cout << "Investment destroyed" << std::endl;}
  Investment(const Investment& in) { std::cout << "Investment copied" << std::endl;}
};

Investment*
createInvestment() {
  // Don't do this yourself! See item 18 (but you may have to call APIs that do).
  return new Investment();
}

std::unique_ptr<Investment>
createInvestment2() {
  // Do this instead
  return std::unique_ptr<Investment>(new Investment());
}

Investment
createInvestment3() {
  // Or even this
  return Investment(); // RVO happens here.
}

std::shared_ptr<Investment>
createInvestment4() {
  return std::make_shared<Investment>();
}

int _tmain( )
{
  std::unique_ptr<Investment> pInv(createInvestment()); 
  //std::unique_ptr<Investment> pInv2(createInvestment2());
  //Investment inv(createInvestment3());
  
  // Want to share it?
  // raw pointer or reference-to-unique is fine if you know the lifetime
  Investment* rawPInv = pInv.get();  
  std::unique_ptr<Investment>& pInvRef = pInv;  
  
  // shared_ptr for occasions when you don't have one owner
  //std::shared_ptr<Investment> sharedInv(createInvestment2());  // Move unique_ptr to shared_ptr
  std::shared_ptr<Investment> sharedInv2(std::move(pInv));       // Move unique_ptr to shared_ptr
  //std::shared_ptr<Investment> sharedInv3(createInvestment4()); // Create shared_ptr directly 
  // See also std::weak_ptr
  
  std::cout << "Do something with Investment" << std::endl;
}

