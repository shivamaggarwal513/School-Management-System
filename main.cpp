#include <iostream>
#include <assert.h>

#include "headers/student.hpp"
#include "headers/admin.hpp"

#define _padding_ "\t\t"

enum PersonType
{
    Student,
    Teacher,
    SaveAndExit
};
enum MenuOption
{
    Create,
    Search,
    Read,
    Update,
    Delete,
    GoBack,
    Exit
};

using namespace std;

inline void drawHorizontalSeperator()
{
    cout << _padding_;
    for (int i = 0; i < 20; i++)
        cout << '*';
    cout << endl;
}

void drawMainMenu()
{
    string arr[] = {"Select an option",
                    "1.) Student",
                    "2.) Teacher",
                    "3.) Save & Exit"};
    for (auto x : arr)
    {
        cout << _padding_ << x << endl;
    }
}

PersonType selectMainMenuOption()
{
    char temp;
    while (true)
    {
        drawHorizontalSeperator();
        drawMainMenu();
        cout << _padding_;
        cin >> temp;
        switch (temp)
        {
        case '1':
        {
            return PersonType::Student;
        }
        case '2':
        {
            return PersonType::Teacher;
        }
        case '3':
        {
            return PersonType::SaveAndExit;
        }
        default:
        {
            system("cls");
            cout << _padding_ << "Try again" << endl;
            break;
        }
        }
    }
}

void drawSubMenu(bool isStudent)
{
    string studentArr[] = {"Select an option", "1.) Create data for new student",
                           "2.) Search for a student",
                           "3.) Display all students",
                           "4.) Update data for an existing student",
                           "5.) Delete a record",
                           "6.) Go back",
                           "7.) Exit the application"};
    string teacherArr[] = {"Select an option", "1.) Create data for new teacher",
                           "2.) Search for a teacher",
                           "3.) Display all teachers",
                           "4.) Update data for an existing teacher",
                           "5.) Delete a record",
                           "6.) Go back",
                           "7.) Exit the application"};
    if (isStudent)
        for (auto x : studentArr)
        {
            cout << _padding_ << x << endl;
        }
    else
        for (auto x : teacherArr)
        {
            cout << _padding_ << x << endl;
        }
}

MenuOption selectSubMenuOption(bool isStudent)
{
    char temp;
    while (true)
    {
        drawHorizontalSeperator();
        drawSubMenu(isStudent);
        cout << _padding_;
        cin >> temp;
        switch (temp)
        {
        case '1':
        {
            return MenuOption::Create;
        }
        case '2':
        {
            return MenuOption::Search;
        }
        case '3':
        {
            return MenuOption::Read;
        }
        case '4':
        {
            return MenuOption::Update;
        }
        case '5':
        {
            return MenuOption::Delete;
        }
        case '6':
        {
            return MenuOption::GoBack;
        }
        case '7':
        {
            return MenuOption::Exit;
        }
        default:
        {
            system("cls");
            cout << _padding_ << "Try again" << endl;
            break;
        }
        }
    }
}

int main()
{
    Admin admin;

MAINMENU:
    PersonType mainMenuOption = selectMainMenuOption();
    if (mainMenuOption == PersonType::Student)
    {
    // Student menu
    STUDENTMENU:
        MenuOption menuOption = selectSubMenuOption(true);
        switch (menuOption)
        {
        case MenuOption::Create:
        {
            cin.ignore();
            admin.addStudent();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::Search:
        {
            admin.searchStudent();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::Read:
        {
            admin.viewAllStudents();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::Update:
        {
            admin.updateAStudent();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::Delete:
        {
            admin.removeAStudent();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::GoBack:
        {
            goto MAINMENU;
            break;
        }
        case MenuOption::Exit:
        {
            cout << "Thank you for using our app!" << endl;
            return 0;
        }
        default:
            break;
        }
    }
    else if (mainMenuOption == PersonType::Teacher)
    {
    TEACHERMENU:
        MenuOption menuOption = selectSubMenuOption(false);
        switch (menuOption)
        {
        case MenuOption::Create:
        {
            cin.ignore();
            admin.addATeacher();
            goto TEACHERMENU;
            break;
        }
        case MenuOption::Search:
        {
            admin.searchATeacher();
            goto TEACHERMENU;
            break;
        }
        case MenuOption::Read:
        {
            admin.viewAllTeachers();
            goto TEACHERMENU;
            break;
        }
        case MenuOption::Update:
        {
            admin.updateATeacher();
            goto TEACHERMENU;
            break;
        }
        case MenuOption::Delete:
        {
            admin.removeATeacher();
            goto TEACHERMENU;
            break;
        }
        case MenuOption::GoBack:
        {
            goto MAINMENU;
            break;
        }
        case MenuOption::Exit:
        {
            cout << "Thank you for using our app!" << endl;
            return 0;
        }
        default:
            break;
        }
    }
    else if (mainMenuOption == PersonType::SaveAndExit)
    {
        cout << "Thank you for using our app!" << endl;
        return 0;
    }
    else
    {
        assert(0 && "No option matched in while selecting person type");
    }
    drawHorizontalSeperator();
    cout << "Thank you for using our app!" << endl;
    return 0;
}