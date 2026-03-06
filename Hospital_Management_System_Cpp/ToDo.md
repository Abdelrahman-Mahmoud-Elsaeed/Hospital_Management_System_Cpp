Below is a **clean requirement document** for your project.
It only lists **responsibilities, key data, and required methods** for each file — no detailed explanations.

---

# Hospital Management System

### File Responsibilities & Required Methods

---

# data/

### patients.txt

Stores patient records.

Format:

```text
patientID|name|address|age|sex|disease|serviceType|date|totalCharge|totalDeposit
```

---

### doctors.txt

Stores doctor records.

Format:

```text
doctorID|name|specialization|roomNumber
```

---

### appointments.txt

Stores appointment records.

Format:

```text
appointmentID|patientID|doctorID|date|time
```

---

# models/

---

# Patient.h

### Purpose

Defines patient entity.

### Data Members

```text
int patientID
string name
string address
int age
string sex
string disease
string serviceType
string date
double totalCharge
double totalDeposit
```

### Methods

```text
Patient()
Patient(parameters)

int getID()
string getName()

void updateInfo(...)
double getBalance()

string serialize()
static Patient deserialize(string line)

void display()
```

---

# Patient.cpp

### Purpose

Implements all `Patient` methods.

Includes:

```text
serialization
deserialization
display formatting
balance calculation
```

---

# Doctor.h

### Purpose

Defines doctor entity.

### Data Members

```text
int doctorID
string name
string specialization
int roomNumber
```

### Methods

```text
Doctor()
Doctor(parameters)

int getID()
string getName()

string serialize()
static Doctor deserialize(string line)

void display()
```

---

# Doctor.cpp

### Purpose

Implements all `Doctor` methods.

Includes:

```text
serialization
deserialization
display
```

---

# Appointment.h

### Purpose

Defines appointment entity.

### Data Members

```text
int appointmentID
int patientID
int doctorID
string date
string time
```

### Methods

```text
Appointment()
Appointment(parameters)

int getID()
int getPatientID()
int getDoctorID()

string serialize()
static Appointment deserialize(string line)

void display()
```

---

# Appointment.cpp

### Purpose

Implements appointment logic.

Includes:

```text
serialization
deserialization
display
```

---

# repositories/

Repositories manage **data in memory**.

---

# PatientRepository.h

### Data Members

```text
unordered_map<int, Patient> patients
string filePath
```

### Methods

```text
void load()
void save()

void addPatient(Patient patient)
bool deletePatient(int patientID)

Patient* findByID(int patientID)
Patient* findByName(string name)

vector<Patient> getAll()

vector<Patient> getEmergencyPatients()
vector<Patient> getOPDPatients()

vector<Patient> getSortedByName()
vector<Patient> getByDate(string date)
```

---

# PatientRepository.cpp

### Implements

```text
load patients from file
save patients to file
search operations
delete operations
sorting
filtering
```

Uses:

```text
FileManager
```

---

# DoctorRepository.h

### Data Members

```text
unordered_map<int, Doctor> doctors
string filePath
```

### Methods

```text
void load()
void save()

void addDoctor(Doctor doctor)

Doctor* findByID(int doctorID)
Doctor* findByName(string name)

vector<Doctor> getAll()
```

---

# DoctorRepository.cpp

### Implements

```text
doctor loading
doctor saving
doctor searching
```

---

# AppointmentRepository.h

### Data Members

```text
vector<Appointment> appointments
string filePath
```

### Methods

```text
void load()
void save()

void addAppointment(Appointment appointment)

vector<Appointment> getAll()

vector<Appointment> getByPatientID(int patientID)
vector<Appointment> getByDoctorID(int doctorID)
vector<Appointment> getByDate(string date)
```

---

# AppointmentRepository.cpp

### Implements

```text
appointment loading
appointment saving
appointment filtering
```

---

# storage/

Handles file operations.

---

# FileManager.h

### Methods

```text
vector<string> readAllLines(string path)

void writeAllLines(string path, vector<string> lines)

void appendLine(string path, string line)

bool fileExists(string path)
```

---

# FileManager.cpp

### Implements

```text
file reading
file writing
file appending
file existence check
```

Uses:

```text
fstream
sstream
```

---

# services/

Contains **business logic**.

---

# HospitalService.h

### Data Members

```text
PatientRepository patientRepo
DoctorRepository doctorRepo
AppointmentRepository appointmentRepo
```

### Methods

```text
void addPatient()

void searchPatient()
void editPatient()

void listPatientsAlphabetical()
void listEmergencyPatients()
void listOPDPatients()
void listPatientsByDate()

void deletePatient()

void addDoctor()

void bookAppointment()

void listAppointments()
```

---

# HospitalService.cpp

### Implements

```text
user input processing
validation
business rules
repository calls
display logic
```

Coordinates:

```text
patients
doctors
appointments
```

---

# main.cpp

### Purpose

Program entry point.

### Responsibilities

```text
initialize HospitalService
display menu
read user input
call service functions
loop until exit
```

### Menu

```text
1 Add Patient
2 Search / Edit Patient
3 List Patients
4 Delete Patient
5 Add Doctor
6 Book Appointment
7 List Appointments
8 Exit
```

---

# System Data Flow

```text
User
 ↓
main.cpp
 ↓
HospitalService
 ↓
Repositories
 ↓
FileManager
 ↓
TXT Files
```

---

This structure ensures:

```text
clear responsibilities
clean OOP design
easy maintenance
separation of concerns
```
