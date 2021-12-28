//
// Created by 10991 on 2021/10/10.
//

#ifndef ALGORITHMCPP_INCLUDE_STUDENT_H_
#define ALGORITHMCPP_INCLUDE_STUDENT_H_

#include <iostream>
using namespace std;

struct Student {
  string name;
  int score;

  bool operator<(const Student &otherStudent) {
    return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
  }

  friend ostream& operator<<(ostream &os, const Student &student) {
    os << "Student: " << student.name << " " << student.score << endl;
    return os;
  }

};

#endif //ALGORITHMCPP_INCLUDE_STUDENT_H_
