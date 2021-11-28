#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "student.hpp"
#include "teacher.hpp"

#define _padding_ "\t\t"

using namespace std;

class Admin
{
public:
    vector<StudentClass> studentsArray;
    vector<TeacherClass> teachersArray;
    Admin()
    {
        studentsArray = {};
        teachersArray = {};
        fstream inputDB;

        try
        {
            inputDB.open("students.txt", ios::in);
            if(inputDB.is_open());
            else throw "Unable to open File";
        }
        catch (string error)
        {
            inputDB.open("students.txt", ios::out | ios::in);
        }

        if (inputDB.is_open())
            while (!inputDB.eof())
            {
                string rawStudent;
                getline(inputDB, rawStudent);
                if (inputDB.eof())
                    break;
                studentsArray.push_back(StudentClass(rawStudent));
            }
        inputDB.close();

        try
        {
            inputDB.open("teachers.txt", ios::in);
            if(inputDB.is_open());
            else throw "Unable to open File";
        }
        catch (string error)
        {
            inputDB.open("teachers.txt", ios::out | ios::in);
        }

        if (inputDB.is_open())
            while (!inputDB.eof())
            {
                string rawTeacher;
                getline(inputDB, rawTeacher);
                if (inputDB.eof())
                    break;
                teachersArray.push_back(TeacherClass(rawTeacher));
            }
        inputDB.close();
    }

    ~Admin()
    {
        fstream outputDB;
        outputDB.open("students.txt", ios::out);
        for (auto x : studentsArray)
        {
            outputDB << x.name << ";" << x.age << ";" << x.batch << ";" << x.rollNo << endl;
        }
        outputDB.close();
        outputDB.open("teachers.txt", ios::out);
        for (auto x : teachersArray)
        {
            outputDB << x.name << ";" << x.age << ";" << x.subject << ";" << x.designation << ";" << x.id << endl;
        }
    }

    void addStudent()
    {
        // Making a temporary Student type object
        StudentClass temp;
        // Taking input of it's properties
        cout << _padding_ << "Enter name of the Student...\n";
        cout << _padding_;
        getline(cin, temp.name);

        cout << _padding_ << "Enter the age of the Student...\n";
        cout << _padding_;
        getline(cin, temp.age);

        cout << _padding_ << "Enter the roll no for " << temp.name << endl;
        cout << _padding_;
        getline(cin, temp.rollNo);

        cout << _padding_ << "Enter the batch for " << temp.name << endl;
        cout << _padding_;
        getline(cin, temp.batch);

        // Finally, adding it to the array
        studentsArray.push_back(temp);
        cout << _padding_ << "Student added!\n";

        system("pause");
        system("cls");
    }

    void searchStudent()
    {
        string key;
        
        cout << _padding_;
        cout << "Enter roll no. of a student to search: ";
        cin.ignore();
        getline(cin, key);

        int i = 0;
        while (i < studentsArray.size())
        {
            if (studentsArray[i].rollNo == key)
            {
                cout << studentsArray[i].name << endl
                     << studentsArray[i].rollNo << " " << studentsArray[i].batch << endl;
                system("pause");
                system("cls");
                return;
            }
            i++;
        }
        cout << "No such student found!" << endl;
        system("pause");
        system("cls");
    }

    void viewAllStudents()
    {
        for (auto x : studentsArray)
        {
            cout << _padding_;
            x.view();
        }
        system("pause");
        system("cls");
    }

    void updateAStudent()
    {
        if (studentsArray.size() == 0)
        {
            cout << "No students exist to modify\n";
            return;
        }
        int modselector, opselector, modifyagain = 0;
        for (int i = 0; i < studentsArray.size(); i++)
        {
            cout << i + 1 << ". " << studentsArray[i].name << endl;
        }

        cin >> modselector;

    labelModifyAgain:
        cout << "Details for " << studentsArray[modselector - 1].name << " are:\n";
        cout << "1. Name: " << studentsArray[modselector - 1].name << endl;
        cout << "2. Roll no.: " << studentsArray[modselector - 1].rollNo << endl;
        cout << "3. Batch: " << studentsArray[modselector - 1].batch << endl;

        cout << "Choose a property to modify\n";
        cin >> opselector;

        switch (opselector)
        {

        case 1:

            cout << "Enter new name for student " << studentsArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, studentsArray[modselector - 1].name);

            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelModifyAgain;

            break;

        case 2:

            cout << "Enter new Roll no. for student " << studentsArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, studentsArray[modselector - 1].rollNo);
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelModifyAgain;

            break;

        case 3:

            cout << "Enter new batch for student " << studentsArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, studentsArray[modselector - 1].batch);
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelModifyAgain;

            break;

        default:

            cout << "No matching option found!\n";
        }

        system("pause");
        system("cls");
    }

    void removeAStudent()
    {
        int delselector;
        bool del, confirm;

        // Printing the names of all the available students
        for (auto x : studentsArray)
        {
            x.view();
        }

        cin >> delselector;

        cout << "Details for " << studentsArray[delselector - 1].name << " are:\n";
        cout << "1. Name: " << studentsArray[delselector - 1].name << endl;
        cout << "2. Roll no.: " << studentsArray[delselector - 1].rollNo << endl;
        cout << "3. Batch: " << studentsArray[delselector - 1].batch << endl;

        cout << "Do you want to delete " << studentsArray[delselector - 1].name << "?\n";
        cout << "0. No\n1. Yes\n";
        cin >> del;
        if (del)
            studentsArray.erase(studentsArray.begin() + delselector - 1);
    }

    void addATeacher()
    {
        TeacherClass tempTeacher;
        cout << "Enter the name of the Teacher: ";
        getline(cin, tempTeacher.name);

        cout << "Enter the age of the Teacher: ";
        getline(cin, tempTeacher.age);

        cout << "Enter the subject of the Teacher: ";
        getline(cin, tempTeacher.subject);

        cout << "Enter the designation of the Teacher: ";
        getline(cin, tempTeacher.designation);

        cout << "Enter the id of the teacher: ";
        getline(cin, tempTeacher.id);

        teachersArray.push_back(tempTeacher);
        cout << "Teacher Added!" << endl;

        system("pause");
        system("cls");
    }

    void searchATeacher()
    {
        string key;
        cout << "Enter the id of the teacher to search: ";
        cin.ignore();
        getline(cin, key);
        for (auto x : teachersArray)
        {
            if (x.id == key)
            {
                x.view();
                system("pause");
                system("cls");
                return;
            }
        }
        cout << "No such teacher found!" << endl;
        system("pause");
        system("cls");
        return;
    }

    void viewAllTeachers()
    {
        for (auto x : teachersArray)
        {
            x.view();
        }
    }

    void updateATeacher()
    {

        if (teachersArray.size() == 0)
        {
            cout << "No teachers exist to modify\n";
            return;
        }
        int modselector, opselector, modifyagain = 0;
        for (int i = 0; i < teachersArray.size(); i++)
        {
            cout << i + 1 << ". " << teachersArray[i].name << endl;
        }

        cin >> modselector;

    labelmodifyteacher:
        cout << "Details for " << teachersArray[modselector - 1].name << " are:\n";
        teachersArray[modselector - 1].view();

        cout << "Choose a property to modify\n";
        cin >> opselector;

        switch (opselector)
        {

        case 1:

            cout << "Enter new name for teacher " << teachersArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, teachersArray[modselector - 1].name);

            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelmodifyteacher;

            break;

        case 2:

            cout << "Enter new age for teacher " << teachersArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, teachersArray[modselector - 1].age);
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelmodifyteacher;

            break;

        case 3:

            cout << "Enter new subject for teacher " << teachersArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, teachersArray[modselector - 1].subject);
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelmodifyteacher;

            break;

        case 4:

            cout << "Enter new designation for student " << teachersArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, teachersArray[modselector - 1].designation);
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelmodifyteacher;

            break;

        default:

            cout << "No matching option found!\n";
        }

        system("pause");
        system("cls");
    }

    void removeATeacher()
    {
        int delselector;
        bool del, confirm;

        // Printing the names of all the available teachers
        for (auto x : teachersArray)
        {
            x.view();
        }

        cin >> delselector;

        cout << "Details for " << teachersArray[delselector - 1].name << " are:\n";
        cout << "1. Name: " << teachersArray[delselector - 1].name << endl;
        cout << "2. Age: " << teachersArray[delselector - 1].age << endl;
        cout << "3. Subject: " << teachersArray[delselector - 1].subject << endl;
        cout << "4. Designation: " << teachersArray[delselector - 1].designation << endl;
        cout << "5. ID: " << teachersArray[delselector - 1].id << endl;

        cout << "Do you want to delete " << teachersArray[delselector - 1].name << "?\n";
        cout << "0. No\n1. Yes\n";
        cin >> del;
        if (del)
            teachersArray.erase(teachersArray.begin() + delselector - 1);
    }
};