# 🎓 Student Survival System
### A C++ Student Management & Daily Life Organizer

## 📌 Project Overview

The **Student Survival System** is a menu-driven console application developed in C++. It is designed to help university students manage their academic activities and daily expenses in one integrated system.

The application provides tools for student profile management, monthly budgeting, expense tracking, attendance calculation, GPA calculation, study planning, exam countdown, and daily task management.

The project uses fundamental and intermediate C++ programming concepts, including functions, arrays, structures, loops, conditional statements, and file handling.

## 🎯 Project Objectives

- Manage student personal information.
- Calculate monthly income, expenses, and remaining balance.
- Track daily and monthly expenses.
- Calculate attendance percentage.
- Calculate semester GPA using credit hours.
- Organize weekly study schedules.
- Track upcoming examination dates.
- Manage daily academic tasks.
- Plan food and transportation budgets.
- Store student records permanently using text files.

## ✨ Main Features

| No. | Feature | Description |
|---|---|---|
| 1 | Student Profile Management | Stores name, roll number, department, and semester. |
| 2 | Monthly Budget Calculator | Calculates income, expenses, and remaining balance. |
| 3 | Expense Tracker | Adds and displays expense records. |
| 4 | Attendance Calculator | Calculates attendance percentage. |
| 5 | GPA Calculator | Calculates GPA based on grade points and credit hours. |
| 6 | Study Timetable | Creates a weekly study schedule. |
| 7 | Exam Countdown | Calculates remaining days until an examination. |
| 8 | Daily Task Manager | Adds, views, and completes tasks. |
| 9 | Food & Transport Budget | Plans monthly and daily food and transport budgets. |
| 10 | Student Information | Displays combined student information. |
| 11 | Save Records | Saves all records into text files. |
| 12 | Exit | Saves records and closes the application. |

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Application Type:** Console-Based Application
- **File Storage:** Text Files (.txt)
- **Compiler:** GCC / G++ or any compatible C++ compiler
- **Standard:** C++11

## 📚 C++ Concepts Used

This project demonstrates the following programming concepts:

1. Variables and Data Types
2. Input and Output Statements
3. Conditional Statements (`if-else`)
4. Switch Statements
5. Loops (`for`, `while`, `do-while`)
6. Functions
7. Arrays
8. Structures (`struct`)
9. File Handling (`ifstream`, `ofstream`)
10. Input Validation
11. Mathematical Calculations
12. Date and Time Handling (`ctime`)

## 📂 Project Structure

```text
StudentSurvivalSystem/
│
├── StudentSurvivalSystem.cpp
├── README.md
│
├── student.txt
├── expenses.txt
├── attendance.txt
├── gpa.txt
├── tasks.txt
├── budget.txt
├── timetable.txt
└── exam.txt
```

**Note:** Text files are automatically created when the application saves the corresponding records.

## ⚙️ Installation and Execution

### Step 1: Download or Copy the Project

Place `StudentSurvivalSystem.cpp` in a folder on your computer.

### Step 2: Open a C++ Compiler

You can use:
- Code::Blocks
- Visual Studio
- Dev-C++
- GCC / G++

### Step 3: Compile the Program

Using GCC:

```bash
g++ -std=c++11 StudentSurvivalSystem.cpp -o StudentSurvivalSystem
```

### Step 4: Run the Program

On Windows:

```bash
StudentSurvivalSystem.exe
```

On Linux:

```bash
./StudentSurvivalSystem
```

## 💾 Data Storage and File Handling

The system uses text files to preserve information between program executions.

| File Name | Stored Information |
|---|---|
| student.txt | Student profile |
| expenses.txt | Expense records |
| attendance.txt | Attendance information |
| gpa.txt | Subject and GPA information |
| tasks.txt | Daily tasks |
| budget.txt | Income and budget information |
| timetable.txt | Weekly timetable |
| exam.txt | Examination information |

When the program starts, it loads previously saved records. Records are saved when relevant features are updated and when the user exits.

## 🧮 Important Formulas

### 1. Attendance Percentage

Attendance Percentage = (Attended Classes / Total Classes) × 100

### 2. GPA Calculation

GPA = Sum of (Grade Points × Credit Hours) / Total Credit Hours

### 3. Remaining Balance

Remaining Balance = Monthly Income − Total Recorded Expenses

### 4. Daily Budget

Daily Budget = Monthly Budget / 30

### 5. Exam Countdown

Remaining Days = Exam Date − Current Date

## 🧪 Testing

The following test cases can be used to evaluate the application:

| Test | Input | Expected Result |
|---|---|---|
| Attendance | 35/40 classes | 87.50% |
| GPA | 3.5 points, 3 credits | 3.50 GPA |
| Monthly Income | Rs. 30,000 | Income recorded |
| Expense | Rs. 1,500 | Expense recorded |
| Food Budget | Rs. 8,000 | Rs. 266.67 daily |
| Transport Budget | Rs. 4,000 | Rs. 133.33 daily |

## 🚀 Future Improvements

Possible future enhancements include:

- Graphical User Interface (GUI).
- Database integration.
- Multiple student accounts.
- Expense categories and monthly reports.
- Editing and deleting existing records.
- Improved GPA and CGPA management.
- Automatic assignment reminders.
- Improved data validation and backup.

## 🎓 Learning Outcomes

Through this project, students can learn how to:

- Develop a complete menu-driven C++ application.
- Divide a large program into smaller functions.
- Work with arrays and structures.
- Implement file handling for permanent storage.
- Apply mathematical formulas in programming.
- Manage and organize academic information.

## 👨‍💻 Project Information

**Project Name:** Student Survival System

**Language:** C++

**Project Type:** University Semester Project

**Difficulty Level:** Intermediate

**Application:** Console-Based Student Management System

## 📝 Conclusion

The Student Survival System provides a simple and integrated solution for managing university life. It combines academic management, financial planning, and daily task organization in one C++ application.

This project demonstrates the practical application of intermediate C++ programming concepts and provides a foundation for developing more advanced student management systems.
