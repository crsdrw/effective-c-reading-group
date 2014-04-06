#include "stdafx.h"

#include <iostream>
#include <exception>
#include <memory>

struct Widget {
  Widget() { std::cout << "  Widget constructed" << std::endl; }
  ~Widget() { std::cout << "  Widget destroyed" << std::endl; }
};

int
priority() {
  throw std::exception();
}

void
processWidget(int priority, std::shared_ptr<Widget> pw) {
  
}

int _tmain() {

  std::cout << "1. Not exception safe:" << std::endl; 
  try {
    processWidget(priority(), std::shared_ptr<Widget>(new Widget()));
  } catch (std::exception &) {}
  
  std::cout << "2. Is exception safe:" << std::endl;   
  try {
    std::shared_ptr<Widget> widget(new Widget());
    processWidget(priority(), widget); 
  } catch (std::exception &) {}
  
  std::cout << "3. Also exception safe:" << std::endl;   
  try {
    processWidget(priority(), std::make_shared<Widget>());
  } catch (std::exception &) {}
  
  // No std::make_unique until C++14 :-(
}

