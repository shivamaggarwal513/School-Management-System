#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "person.hpp"

class TeacherClass : private Person
{
private:
    friend class Admin;
    string subject, designation, id;


public:
    TeacherClass(string name, string age, string subject, string designation, string id)
    {
        this->name = name;
        this->age = age;
        this->subject = subject;
        this->designation = designation;
        this->id = id;
    }

    TeacherClass(string rawData)
    {
        char str[100];
        strcpy(str, rawData.c_str());

        char *tok = strtok(str, ";");
        this->name = string(tok);
        tok = strtok(NULL, ";");
        this->age = string(tok);
        tok = strtok(NULL, ";");
        this->subject = string(tok);
        tok = strtok(NULL, ";");
        this->designation = string(tok);
        tok = strtok(NULL, ";");
        this->id = string(tok);
    }
    
    TeacherClass() {}

private:
    void view()
    {
        cout << name << " " << age << " " << subject << " " << designation << " " << id << endl;
    }
};