#include "functions.h"

// ==========================================
// INPUT FUNCTIONS
// ==========================================

int getInt(string message)
{
    int value;

    while(true)
    {
        cout << message;

        if(cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input! Enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double getDouble(string message)
{
    double value;

    while(true)
    {
        cout << message;

        if(cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(value >= 0)
                return value;
        }

        cout << "Invalid input! Enter a non-negative number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string getLine(string message)
{
    string value;

    cout << message;
    getline(cin, value);

    return value;
}

// ==========================================
// MAIN MENU
// ==========================================

void showMenu()
{
    cout << "\n";
    cout << "========================================\n";
    cout << "       STUDENT SURVIVAL SYSTEM\n";
    cout << "========================================\n";

    cout << "\n--- STUDENT PROFILE ---\n";
    cout << "1. Add Student Profile\n";
    cout << "2. View Student Profile\n";

    cout << "\n--- BUDGET MANAGER ---\n";
    cout << "3. Set Monthly Budget\n";
    cout << "4. Add Expense\n";
    cout << "5. Add Food/Transport Expense\n";
    cout << "6. View Budget Report\n";

    cout << "\n--- ATTENDANCE ---\n";
    cout << "7. Add Attendance Record\n";
    cout << "8. View Attendance Report\n";

    cout << "\n--- ACADEMIC MANAGER ---\n";
    cout << "9. Calculate GPA\n";
    cout << "10. Add Timetable\n";
    cout << "11. View Timetable\n";

    cout << "\n--- TASK MANAGER ---\n";
    cout << "12. Add Assignment/Task\n";
    cout << "13. View Tasks\n";

    cout << "\n--- EXAM MANAGER ---\n";
    cout << "14. Add Exam\n";
    cout << "15. View Exams and Countdown\n";

    cout << "\n0. Exit\n";

    cout << "========================================\n";
}

// ==========================================
// 1. ADD STUDENT PROFILE
// ==========================================

void addStudent()
{
    Student s;

    s.name = getLine("\nEnter Student Name: ");
    s.university = getLine("Enter University: ");
    s.department = getLine("Enter Department: ");
    s.semester = getInt("Enter Semester: ");

    if(s.semester < 1)
    {
        cout << "Invalid semester!\n";
        return;
    }

    ofstream file("student.txt");

    if(!file)
    {
        cout << "File could not be opened!\n";
        return;
    }

    file << s.name << endl;
    file << s.university << endl;
    file << s.department << endl;
    file << s.semester << endl;

    file.close();

    cout << "\nStudent Profile Saved Successfully!\n";
}

// ==========================================
// 2. VIEW STUDENT PROFILE
// ==========================================

void viewStudent()
{
    Student s;

    ifstream file("student.txt");

    if(!file)
    {
        cout << "\nNo student profile found!\n";
        return;
    }

    getline(file, s.name);
    getline(file, s.university);
    getline(file, s.department);
    file >> s.semester;

    cout << "\n========== STUDENT PROFILE ==========\n";

    cout << "Name: " << s.name << endl;
    cout << "University: " << s.university << endl;
    cout << "Department: " << s.department << endl;
    cout << "Semester: " << s.semester << endl;

    cout << "=====================================\n";

    file.close();
}

// ==========================================
// 3. SET MONTHLY BUDGET
// ==========================================

void setBudget()
{
    double budget = getDouble("\nEnter Monthly Budget (Rs): ");

    ofstream file("budget.txt");

    if(!file)
    {
        cout << "Unable to save budget!\n";
        return;
    }

    file << budget;
    file.close();

    cout << "\nMonthly Budget Saved Successfully!\n";
}

// ==========================================
// 4. ADD EXPENSE
// ==========================================

void addExpense()
{
    Expense e;

    e.date = getLine("\nEnter Date (YYYY-MM-DD): ");
    e.category = getLine("Enter Expense Category: ");
    e.amount = getDouble("Enter Expense Amount (Rs): ");

    ofstream file("expenses.txt", ios::app);

    if(!file)
    {
        cout << "Unable to open expense file!\n";
        return;
    }

    file << e.date << "|"
         << e.category << "|"
         << e.amount << endl;

    file.close();

    cout << "\nExpense Added Successfully!\n";
}

// ==========================================
// 5. FOOD AND TRANSPORT EXPENSE
// ==========================================

void addFoodTransportExpense()
{
    cout << "\n1. Food Expense\n";
    cout << "2. Transport Expense\n";

    int choice = getInt("Choose Category: ");

    string category;

    if(choice == 1)
        category = "Food";
    else if(choice == 2)
        category = "Transport";
    else
    {
        cout << "Invalid choice!\n";
        return;
    }

    string date = getLine("Enter Date (YYYY-MM-DD): ");
    double amount = getDouble("Enter Amount (Rs): ");

    ofstream file("expenses.txt", ios::app);

    if(!file)
    {
        cout << "Unable to open file!\n";
        return;
    }

    file << date << "|" << category << "|" << amount << endl;

    file.close();

    cout << "\nRecord Saved Successfully!\n";
}

// ==========================================
// 6. VIEW BUDGET REPORT
// ==========================================

void viewBudget()
{
    double budget, amount, total = 0;
    string line, date, category, amountText;

    ifstream budgetFile("budget.txt");

    if(!budgetFile)
    {
        cout << "\nPlease set your budget first!\n";
        return;
    }

    budgetFile >> budget;
    budgetFile.close();

    ifstream expenseFile("expenses.txt");

    if(expenseFile)
    {
        while(getline(expenseFile, line))
        {
            stringstream ss(line);

            getline(ss, date, '|');
            getline(ss, category, '|');
            getline(ss, amountText);

            try
            {
                amount = stod(amountText);
                total += amount;
            }
            catch(...)
            {
                continue;
            }
        }

        expenseFile.close();
    }

    cout << fixed << setprecision(2);

    cout << "\n========== BUDGET REPORT ==========\n";

    cout << "Monthly Budget: Rs. " << budget << endl;
    cout << "Total Recorded Expenses: Rs. " << total << endl;
    cout << "Remaining Balance: Rs. " << budget - total << endl;

    if(total > budget)
        cout << "Warning: Budget exceeded!\n";

    cout << "==================================\n";
}

// ==========================================
// 7. ADD ATTENDANCE
// ==========================================

void addAttendance()
{
    string subject;

    subject = getLine("\nEnter Subject Name: ");

    int attended = getInt("Classes Attended: ");
    int total = getInt("Total Classes: ");

    if(total <= 0 || attended > total)
    {
        cout << "Invalid attendance record!\n";
        return;
    }

    ofstream file("attendance.txt", ios::app);

    if(!file)
    {
        cout << "Unable to open file!\n";
        return;
    }

    file << subject << "|" << attended << "|" << total << endl;

    file.close();

    cout << "\nAttendance Saved Successfully!\n";
}

// ==========================================
// 8. VIEW ATTENDANCE
// ==========================================

void viewAttendance()
{
    ifstream file("attendance.txt");

    if(!file)
    {
        cout << "\nNo attendance records found!\n";
        return;
    }

    string line, subject, attendedText, totalText;

    int attended, total;
    double percentage;

    cout << "\n========== ATTENDANCE REPORT ==========\n";

    while(getline(file, line))
    {
        stringstream ss(line);
        getline(ss, subject, '|');
        getline(ss, attendedText, '|');
        getline(ss, totalText);

        try
        {
            attended = stoi(attendedText);
            total = stoi(totalText);
            percentage = (static_cast<double>(attended) / total) * 100.0;

            cout << fixed << setprecision(2);
            cout << subject << ": " << attended << "/" << total 
                 << " (" << percentage << "%)\n";
        }
        catch(...)
        {
            continue;
        }
    }

    cout << "=======================================\n";
    file.close();
}

// ==========================================
// MAIN FUNCTION (Fixes WinMain Error)
// ==========================================

int main()
{
    int choice;

    while(true)
    {
        showMenu();
        choice = getInt("Enter your choice: ");

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: viewStudent(); break;
            case 3: setBudget(); break;
            case 4: addExpense(); break;
            case 5: addFoodTransportExpense(); break;
            case 6: viewBudget(); break;
            case 7: addAttendance(); break;
            case 8: viewAttendance(); break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
