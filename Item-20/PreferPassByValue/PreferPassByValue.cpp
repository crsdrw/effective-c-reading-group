#include "stdafx.h"

#include <iostream>

class String {
  public:
    String() {} 
    String(const String& string) { std::cout << "String copied" << std::endl; }
    String(String&&) {  }
   ~String() { }
};

class Person {
    String name_;
    String address_;	
  public:
    Person(const String &name) : name_(name) {}
    virtual ~Person() {}
};

class Student: public Person {
    String schoolName_;
    String schoolAddress_;  
  public:
    Student(const String &name, const String &schoolName) : Person(name),
      schoolName_(schoolName)  {}
   ~Student() {}
};

bool validateStudentByValue(Student student) {
  return true;	
}

bool validateStudentByReference(const Student &s) {
  return true;
}

String getPlatoName() {
	return String(); // Return-by-value, see item 21
}

String getPlatoSchool() {
	return String(); // Return-by-value, see item 21
}

int main() {
  std::cout << "** Create plato **" << std::endl;
  Student plato(getPlatoName(), getPlatoSchool());
  
  std::cout << "** Validate Plato **" << std::endl;
  bool platoOk = validateStudentByValue(plato);
  //bool platoOk = validateStudentByReference(plato);
  if (platoOk)
    std::cout << "Plato is a valid student" << std::endl;
}

