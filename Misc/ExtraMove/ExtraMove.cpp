// For stackoverflow question http://stackoverflow.com/questions/22425679/pass-by-value-resulting-in-extra-move.
//

#include "stdafx.h"


#include <iostream>

struct Data {
  Data()                 { std::cout << "  constructor\n";}
  Data(const Data& data) { std::cout << "  copy constructor\n";} 
  Data(Data&& data)      { std::cout << "  move constructor\n";}
};

struct DataWrapperWithMove {
  Data data_;
  DataWrapperWithMove(Data&& data) : data_(std::move(data)) { }
};

struct DataWrapperByValue {
  Data data_;
  DataWrapperByValue(Data data) : data_(std::move(data)) { }
};

Data
function_returning_data() {
  Data d;
  return d;
}

int _tmain() {
	std::cout << "1. DataWrapperWithMove:\n";	
	Data d1;
    DataWrapperWithMove a1(std::move(d1));
	
	std::cout << "2. DataWrapperByValue:\n";	
	Data d2;
	DataWrapperByValue a2(std::move(d2));

	std::cout << "3. RVO:\n";
	DataWrapperByValue a3(function_returning_data());
}

