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

include/ → Contains all header files and class declarations

models/ → Defines Patient, Doctor, Appointment entities

repositories/ → Manages in-memory data and file interaction for each entity

services/ → Contains HospitalService for business logic

src/ → Contains all source files (.cpp)

Implements methods declared in headers

storage/ → Contains FileManager for file operations (read/write/append)

data/ → Stores persistent patient, doctor, and appointment records (.txt files)

CMakeLists.txt → Build system configuration

README.md → Project documentation

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

To keep the project organized:

1. **Modular Design**

   * Each `.cpp` file should implement **one module or feature**
   * Corresponding `.h` header file must define the interface

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


### 1. Abdo - File Operations & Core Logic

**Focus:** Handling persistent data storage without data loss. Reading, writing, searching, modifying, and deleting records from text files.

* **Classes:** `FileHandler` / `DatabaseManager`
* **Responsibilities:**
* `saveRecord(Patient p)`
* `searchRecord(String idOrName)`
* `updateRecord(String idOrName, Patient updatedInfo)`
* `deleteRecord(String id)`
* `fetchAllRecords()`



### 2. Ahmad - Sorting, Filtering & Financials

**Focus:** Managing the logic for displaying lists of patients based on specific criteria and calculating hospital expenditures.

* **Classes:** `RecordManager`, `FinancialRecord`
* **Responsibilities:**
* List patients alphabetically.
* List patients by category (Emergency vs. O.P.D.).
* List patients by a specific admission date.
* Calculate `totalCharge`, `totalDeposited`, and `totalMoneyToReturn`.



### 3. Mostfa - Data Models, UI & Menus

**Focus:** Building the blueprint for the data and creating the console user interface, formatting the outputs exactly as required.

* **Classes:** `Patient`, `UserInterface`
* **Responsibilities:**
* Define the `Patient` properties (Name, ID, Age, Sex, Disease, Room, etc.).
* Build `showWelcomeScreen()` and `showMainMenu()`.
* Handle user inputs and display success/error messages (e.g., "No records available").



---

## System Architecture

* **`Patient`**: Base data model holding personal and medical details.
* **`FinancialRecord`**: Data model attached to a patient holding billing details.
* **`UserInterface`**: Handles all `cin` and `cout` operations and menu navigation.
* **`RecordManager`**: Handles sorting and filtering arrays/lists of `Patient` objects.
* **`FileHandler`**: Handles all file stream operations (`ifstream`, `ofstream`).

---

## Project Requirements Checklist

* [ ] Use Object-Oriented Programming (OOP) concepts.
* [ ] Implement appropriate Data Structures.
* [ ] Draw and submit a UML Class Diagram before coding.
* [ ] Create a GitHub repository and push all code.

