# Electronic Hospital Queue System

## Overview
This is a C++ program for managing an electronic queue for a hospital. It simulates the process of handling patients, adding them to queues for different doctors, processing them, and saving information about patients who attended or missed their appointments.

## Features
- Add patients to the queue for a specific doctor.
- Process queues with a timer to check if the patient is present.
- Save data on attended and missed patients to text files.
- Load patient data from a file.

## Requirements
- C++ compiler (e.g., GCC, MSVC).
- Windows environment for console support (optional for some features).
- Visual Studio Code or any C++ IDE for development.

## How to Use
1. Compile the program using your preferred C++ compiler.
2. Run the program. The user will be prompted with a menu to:
   - Add patients to the queue.
   - Process patients in the queue (with a 5-second timer to check if they are present).
   - Load patients from a file.
   - Save the processed data to text files.

### Menu Options
1. **Add a patient**: Prompts for patient information (name, surname, age, blood type, gender, doctor) and adds them to the appropriate doctor's queue.
2. **Process queue**: Displays the next patient in the queue and waits for user input. If no input is received within 5 seconds, the patient is considered missed.
3. **Load patients from file**: Loads patient data from a predefined text file.
4. **Save and exit**: Saves the data of attended and missed patients to separate files and exits the program.

### Roman:
- **Responsibilities**:
  - Developed the `Patient` class with relevant fields (ID, name, surname, age, blood type, gender, doctor).
  - Implemented file handling methods for saving and loading patient data.
  - Created the `queue` class to manage patient queues for doctors.

### Evgenia:
- **Responsibilities**:
  - Designed the main menu and program flow (input/output handling).
  - Managed the user interaction and implemented the patient processing logic.
  - Integrated the `queue` class into the main program.
