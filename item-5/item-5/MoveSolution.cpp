// Visual Studio 2012 does not define default move constructor, the solution.
//

#include "stdafx.h"

#include <iostream>

struct Vector {
  Vector() { std::cout << "Default Vector constructor" << std::endl;}
  Vector(const Vector &in) { std::cout << "Expensive Vector copy constructor" << std::endl;}
  Vector(Vector&& in) { std::cout << "Cheap Vector move constructor" << std::endl;}
};

struct DataWrapper {
  Vector data_; // imagine this is std::vector<float>, using Vector to print behaviour
  DataWrapper(Vector&& data) : data_(std::move(data)) { }
  DataWrapper(DataWrapper&& in) : data_(std::move(in.data_)) { }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Vector data;
  DataWrapper dataWrapper(std::move(data));
  DataWrapper anotherDataWrapper(std::move(dataWrapper));
}

