#pragma once
#include <map>
#include <queue>
#include <vector>
#include "Patient.h"
using namespace std;

// Клас електронної черги
class HospitalQueue {
private:
    map<string, queue<Patient>> queues;
    vector<Patient> visited;
    vector<Patient> missed;
    int idCounter;

public:
    HospitalQueue();
    void addPatient();
    void processQueues();
    void saveToFile(const string& fileName, const vector<Patient>& list);
    void loadPatientsFromFile(const string& fileName);  
    void saveAll();
};

void menu();
