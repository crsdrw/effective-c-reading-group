#include "stdafx.h"

#include <iostream>

class String {
  public:
    String() {} 
    String(const String& string) { std::cout << "String copied" << std::endl; }
    String(String&&) {}
   ~String() {}
};

class Person {
    String name_;
    String address_;	
  public:
    Person(String name) : name_(std::move(name)) {}
    virtual ~Person() {}
};

class Student: public Person {
    String schoolName_;
    String schoolAddress_;  
  public:
    Student(String name, String schoolName) : Person(std::move(name)),
      schoolName_(std::move(schoolName))  {}
   ~Student() {}
};

bool validateStudentByReference(const Student &s) {
  return true;
}

String getPlatoName() { 
  return String(); // return-by-value, see item 21
}

String getPlatoSchool() {
  return String();// return-by-value, see item 21
}

int main() {
  std::cout << "** Create plato **" << std::endl;
  Student plato(getPlatoName(), getPlatoSchool());
  
  std::cout << "** Validate Plato **" << std::endl;
  bool platoOk = validateStudentByReference(plato);
  if (platoOk)
    std::cout << "Plato is a valid student" << std::endl;
}

