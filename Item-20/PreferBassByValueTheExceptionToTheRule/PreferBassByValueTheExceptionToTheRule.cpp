#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

int findBestGradeByReference( const std::vector<int>& grades) {
  std::vector<int> tmp(grades); // explicit-copy can't be optimized
  std::sort(tmp.begin(), tmp.end());
  return tmp.back();
}

// Simpler and compiler may be able to optimize out the copy
// See also Item 11. page 56 copy assignement operator
int findBestGradeByValue( std::vector<int> grades) {
  std::sort(grades.begin(), grades.end());
  return grades.back();
}

std::vector<int> getGrades() {
  std::vector<int> grades;
  grades.push_back(56);
  grades.push_back(90);
  grades.push_back(72);
  return grades;
}

int main() {
  //std::vector<int> grades{56, 90, 72} // Not available in VS2012 :-(
  int bestGrade = findBestGradeByValue(getGrades());
  std::cout << "Best grade is " << bestGrade << std::endl;
}

