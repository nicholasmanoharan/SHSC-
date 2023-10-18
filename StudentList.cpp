/*

Nicholas Manoharan

Mr Galbraith

10/17/23

Student List - Allows user to input names, student id, and GPA. 
Also allows users to remove certain users, and print out current student list
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>
#include <locale>  

struct Student {
    std::wstring first_name;
    std::wstring last_name;
    int student_id;
    float GPA;
};

void ClearInputBuffer() {
    std::wcin.clear();
    while (std::wcin.get() != L'\n'); // taking in the new characters from the user
}

void AddStudent(std::vector<Student*>& students) {
    students.push_back(new Student{});
   
    std::wcout << L"Enter first name: ";
    std::wcin.ignore();
    std::getline(std::wcin, students.back()->first_name);
   
    std::wcout << L"Enter last name: ";
    std::getline(std::wcin, students.back()->last_name);
   
    while (true) {
        std::wcout << L"Enter student ID: ";
        if (std::wcin >> students.back()->student_id) {
            ClearInputBuffer();
            break;
        } else {
            std::wcout << L"Invalid input. Please enter a valid student ID." << std::endl;
            ClearInputBuffer();
        }
    }

    while (true) {
        std::wcout << L"Enter GPA: ";
        if (std::wcin >> students.back()->GPA) {
            ClearInputBuffer();
            break;
        } else {
            std::wcout << L"Invalid input. Please enter a valid GPA." << std::endl;
            ClearInputBuffer();
        }
    }
}

void PrintStudents(const std::vector<Student*>& students) {
    std::wcout << L"Student List:\n";
    for (const auto& s : students) {
        std::wcout << L"Name: " << s->first_name << L" " << s->last_name << L", ID: " << s->student_id
                  << L", GPA: " << std::fixed << std::setprecision(2) << s->GPA << L'\n';
    }
}

void DeleteStudent(std::vector<Student*>& students, int id) {
    for (auto it = students.begin(); it != students.end(); ) {
        if ((*it)->student_id == id) {
            std::wcout << L"Deleting student with ID: " << id << L'\n';
            delete *it;
            it = students.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    std::vector<Student*> students;
    wchar_t command[10];
   
    while (true) {
        std::wcout << L"Enter command (ADD, DELETE, PRINT, or QUIT): ";
        std::wcin >> command;
        
        // checking commands and converting to lowercase
        std::wstring lowercaseCommand = command;
        std::transform(lowercaseCommand.begin(), lowercaseCommand.end(), lowercaseCommand.begin(), ::towlower);
       
        if (lowercaseCommand == L"add") {
            AddStudent(students);
        } else if (lowercaseCommand == L"delete") {
            int id;
            std::wcout << L"Enter student ID to delete: ";
            std::wcin >> id;
            DeleteStudent(students, id);
        } else if (lowercaseCommand == L"quit") {
            for (const auto& s : students)
                delete s;
            students.clear();
            return 0; // Exiting the program if the user wants to quit
        } else {
            // printing student list when the user requests to
            PrintStudents(students);
        }
    }
}
