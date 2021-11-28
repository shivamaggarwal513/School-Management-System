#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person{
    public:
    string name, age;
    virtual void view() = 0;
    Person() {}
};