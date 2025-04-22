#include "Patient.h"

Patient::Patient(int _id, const string& _name, const string& _surname, int _age,
    const string& _bloodType, const string& _gender, const string& _doctor)
    : id(_id), name(_name), surname(_surname), age(_age),
    bloodType(_bloodType), gender(_gender), doctor(_doctor) {}

int Patient::getId() const {
    return id;
}

string Patient::getName() const {
    return name;
}

string Patient::getSurname() const {
    return surname;
}

int Patient::getAge() const {
    return age;
}

string Patient::getBloodType() const {
    return bloodType;
}

string Patient::getGender() const {
    return gender;
}

string Patient::getDoctor() const {
    return doctor;
}
