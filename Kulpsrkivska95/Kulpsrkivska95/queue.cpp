#include "queue.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <thread>
#include <chrono>
using namespace std;

// �����������
HospitalQueue::HospitalQueue() {
    idCounter = 1;
}

// ���� �������� �� �����
void HospitalQueue::addPatient() {
    string name, surname, bloodType, gender, doctor;
    int age;

    cout << "Enter patient's first name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter patient's surname: ";
    getline(cin, surname);

    cout << "Enter age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter blood type: ";
    getline(cin, bloodType);

    cout << "Enter gender: ";
    getline(cin, gender);

    cout << "Enter doctor's name: ";
    getline(cin, doctor);

    queues[doctor].emplace(idCounter++, name, surname, age, bloodType, gender, doctor);
    cout << "Patient added to queue for doctor: " << doctor << "\n";
}

// ��������� �� �����
void HospitalQueue::processQueues() {
    for (auto& pair : queues) {
        cout << "\n=== Queue for Doctor: " << pair.first << " ===\n";
        while (!pair.second.empty()) {
            Patient current = pair.second.front();
            cout << "Next patient: " << current.getSurname() << " " << current.getName()
                << " (ID #" << current.getId() << "), Age: " << current.getAge()
                << ", Gender: " << current.getGender()
                << ", Blood Type: " << current.getBloodType() << "\n";
            cout << "Press any key to confirm presence (5 seconds)...\n";

            bool confirmed = false;
            for (int i = 0; i < 50; ++i) {
                if (_kbhit()) {
                    _getch();
                    confirmed = true;
                    break;
                }
                this_thread::sleep_for(chrono::milliseconds(100));
            }

            if (confirmed) {
                cout << "Patient is present.\n";
                visited.push_back(current);
            }
            else {
                cout << "Patient missed the appointment.\n";
                missed.push_back(current);
            }

            pair.second.pop();
        }
    }
}

// ������ ������ � ����
void HospitalQueue::saveToFile(const string& fileName, const vector<Patient>& list) {
    ofstream file(fileName);
    for (const auto& p : list) {
        file << "ID #" << p.getId() << ": " << p.getSurname() << " " << p.getName()
            << ", Age: " << p.getAge()
            << ", Gender: " << p.getGender()
            << ", Blood Type: " << p.getBloodType()
            << ", Doctor: " << p.getDoctor() << "\n";
    }
    file.close();
    cout << "File saved: " << fileName << "\n";
}

// ������ ������ ������
void HospitalQueue::saveAll() {
    saveToFile("visited.txt", visited);
    saveToFile("missed.txt", missed);
}

void menu() {
    HospitalQueue hq;
    int choice;

    do {
        cout << "\n=== Electronic Hospital Queue ===\n";
        cout << "1. Add a patient\n";
        cout << "2. Process queue\n";
        cout << "3. Load patients from file\n";
        cout << "4. Save and exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hq.addPatient();
            break;
        case 2:
            hq.processQueues();
            break;
        case 3:
            hq.loadPatientsFromFile("patients.txt");  // ����������� �������� � �����
            break;
        case 4:
            hq.saveAll();
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

void HospitalQueue::loadPatientsFromFile(const string& fileName) {
    ifstream file(fileName);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, surname, bloodType, gender, doctor;
        int age, id;

        // ������ ����� � ����: ID #1: John Doe, 30, O+, Male, Dr. Smith
        // ������� ID
        ss.ignore(4);  // ���������� "ID #"
        ss >> id;
        ss.ignore(2);  // ���������� ": "

        // ������� ������� �� ��'�
        getline(ss, surname, ' ');
        getline(ss, name, ',');


        // ������� ��, ����� ����, �����, �����
        ss >> age;
        ss.ignore(2); // ���������� ", "
        getline(ss, bloodType, ',');
        getline(ss, gender, ',');
        getline(ss, doctor);

        // ������ �������� �� �����
        queues[doctor].emplace(id, name, surname, age, bloodType, gender, doctor);
    }
    file.close();
    cout << "Patients loaded from file: " << fileName << "\n";
}