#include <stdio.h>
#include <stdlib.h>
#include "io_utils.h"


/**
 * 结构体
 * struct <结构体名> {
 * <成员类型> <成员名>;
 * ....
 * }<结构体变量>;
 * @return
 */
int main(void) {
  typedef struct Company {
    char *name;
    char *id;
    char *locaiton;
  }Company;
  struct Person {
    char *name;
    int age;
    char *id;
    Company *company;
    Company company2;
    struct {
      int extra;
      char *extra_str;
    }extra_value;
    struct Person *partner;
  };
  struct Company company = {.name='unicom', .id="111"};
  struct Person person = {"yinlei", .id ="120", .company=&company,
      .company2={.name="unicom"}};

  PRINT_INT(person.age);
  person.age = 23;

  PRINT_HEX(&person);

  struct Person *person_ptr = &person;
  puts(person_ptr->name);
//  person.company->name
//  person.extra_value.extra

  PRINT_INT(sizeof(struct Person));
  PRINT_INT(sizeof(person));

  struct {
    char *name;
    int age;
    char *id;
  } anonymous_person;

  typedef struct Person Person;
  Person person1 = {.name="yinlei", .age = 23};



  return 0;
}
