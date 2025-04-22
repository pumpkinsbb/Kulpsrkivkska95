#pragma once
#include <string>
#include "sstream"
using namespace std;

//  лас пац≥Їнта
class Patient {
private:
    int id;
    string name;
    string surname;
    int age;
    string bloodType;
    string gender;
    string doctor;

public:
    Patient(int _id, const string& _name, const string& _surname, int _age,
        const string& _bloodType, const string& _gender, const string& _doctor);

    int getId() const;
    string getName() const;
    string getSurname() const;
    int getAge() const;
    string getBloodType() const;
    string getGender() const;
    string getDoctor() const;
};
