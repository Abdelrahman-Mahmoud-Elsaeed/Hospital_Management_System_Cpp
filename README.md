# Hospital Management System (Console-Based)

A modular **Hospital Management System** project in C++ designed for collaborative development, allowing multiple developers to contribute efficiently.

---

## **Project Structure**

```
Hospital_Management_System_Cpp/
├─ include/        # Header files (.h/.hpp)
│   ├─ models/         # Patient, Doctor, Appointment classes
│   ├─ repositories/   # PatientRepository, DoctorRepository, AppointmentRepository
│   ├─ services/       # HospitalService class
│   └─ storage/        # FileManager class
├─ src/            # Source files (.cpp)
│   ├─ models/         # Implementations of entity classes
│   ├─ repositories/   # Implementations of repositories
│   ├─ services/       # Implementation of HospitalService
│   └─ storage/        # FileManager implementation
├─ data/           # Persistent data files (patients.txt, doctors.txt, appointments.txt)
├─ CMakeLists.txt  # Build configuration
└─ README.md       # Project documentation
```

**Folder Details:**

* `include/` → Contains all header files and class declarations
* `models/` → Defines `Patient`, `Doctor`, `Appointment` entities
* `repositories/` → Manages in-memory data and file interaction for each entity
* `services/` → Contains `HospitalService` for business logic
* `src/` → Implements methods declared in headers
* `storage/` → Contains `FileManager` for file operations (read/write/append)
* `data/` → Stores persistent patient, doctor, and appointment records (.txt files)
* `CMakeLists.txt` → Build system configuration
* `README.md` → Project documentation

---

## **Getting Started**

### **Prerequisites**

* C++ compiler (C++17 or above)
* CMake >= 3.10
* Git

### **Clone the project**

```bash
git clone https://github.com/Abdelrahman-Mahmoud-Elsaeed/Hospital_Management_System_Cpp.git
cd Hospital_Management_System_Cpp
```

### **Build the project**

```bash
mkdir build
cd build
cmake ..
make
```

### **Run the program**

```bash
./Hospital_Management_System_Cpp
```

---

## **Contribution Guide**

We welcome contributions! Follow these steps:

1. **Fork the repository** and clone it.
2. **Create a branch** for your feature/fix:

```bash
git checkout -b feature/my-feature
```

3. **Make changes** in a modular way:

   * Keep related functions in separate `.cpp` files
   * Update or add header files in `include/`
   * Write tests in `tests/` if possible

4. **Commit changes** with descriptive messages:

```bash
git add .
git commit -m "Add feature X"
```

5. **Push branch** to your fork and open a Pull Request.

---

## **Code Architecture Rules**

1. **Modular Design**

   * Each `.cpp` file implements **one module or feature**
   * Corresponding `.h` header file defines the interface

2. **Single Responsibility**

   * Each function should do **one thing only**

3. **Naming Conventions**

   * Functions: `camelCase`
   * Classes/Structs: `PascalCase`
   * Constants: `ALL_CAPS`

4. **Testing**

   * Write tests for all new features in `tests/`

5. **No Global Variables**

   * Use parameters or class members

6. **Code Review**

   * Always create Pull Requests
   * Review code for readability, modularity, and correctness

---

## **Task List**

### Abdo – Storage & Repository Layer**

**Focus:** Handle all file operations and data persistence.

**Tasks:**

* Implement **FileManager**:

  * `readAllLine(path)`
  * `readLine(path, index)`
  * `writeAllLines(path, vector<string> lines)`
  * `writeToLine(path, string line, index)`
  * `appendLine(path, string line)`
  * `fileExists(path)`
  * `clearFile(path)`

* Implement **Repositories**:

  * `PatientRepository`: add, update, delete, fetch patient records
  * `DoctorRepository`: add, fetch doctor records
  * `AppointmentRepository`: add, fetch, cancel appointments

* Ensure repositories **use FileManager** for all file I/O.

---

### Ahmad – Services, Models & Console UI**

**Focus:** Define system data, implement logic, and build the console interface.

**Tasks:**

* Implement **Data Models**:

  * `Person` (base class)
  * `Patient`
  * `Doctor`
  * `Appointment`
  * Add attributes (ID, name, age, specialization, fees, dates, etc.)
  * Implement `toString()` / `fromString()` for file storage

* Implement **HospitalService**:

  * Patient management: register, update, remove, list
  * Doctor management: add, list, find
  * Appointment management: book, cancel, list by doctor/patient

* Implement **Console UI**:

  * Welcome screen, main menu, sub-menus
  * Handle user inputs (`cin`) and display outputs (`cout`)
  * Connect UI to `HospitalService` for all menu options
  * Validate inputs and display success/error messages

* Implement **sorting and filtering logic**:

  * Sort patients alphabetically
  * Filter patients by category or date
  * Filter doctors by specialization

---

### Mostfa – Services & Business Logic**

**Focus:** Application logic and operations on the system.

**Tasks:**

* Implement **HospitalService** to coordinate repositories
* Ensure business rules are applied (e.g., no double booking, valid doctor/patient IDs)
* Provide methods to query, filter, and sort records
* Handle interactions between repositories and UI

---

## **System Architecture**

```
Console UI
    ↓
HospitalService
    ↓
Repositories
    ↓
FileManager
    ↓
Text Files
```

**Classes by Layer:**

| Layer        | Classes                                                          |
| ------------ | ---------------------------------------------------------------- |
| Models       | `Person`, `Patient`, `Doctor`, `Appointment`                     |
| Storage      | `FileManager`                                                    |
| Repositories | `PatientRepository`, `DoctorRepository`, `AppointmentRepository` |
| Services     | `HospitalService`                                                |
| UI           | `ConsoleUI`                                                      |

---

## **Project Requirements Checklist**

* [ ] Use Object-Oriented Programming (OOP) concepts
* [ ] Implement appropriate data structures
* [ ] Draw and submit UML Class Diagram before coding
* [ ] Implement file persistence via `FileManager`
* [ ] Implement sorting, filtering, and appointment booking
* [ ] Create a GitHub repository and push all code

