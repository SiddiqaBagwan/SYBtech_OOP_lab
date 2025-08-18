#include<iostream>
#include<string>
using namespace std;

class Staff {
protected:
    string name, dept;
    int ID;

public:
    void accept1();
    void display1();
};

class Teacher : public Staff {
private:
    string subject;
    int experience;

public:
    void accept2();
    void display2();
};

class SupportStaff : public Staff {
private:
    string area;

public:
    void accept3();
    void display3();
};

// Staff functions
void Staff::accept1() {
    cout << "Enter staff name: ";
    cin >> name;
    cout << "Enter staff department: ";
    cin >> dept;
    cout << "Enter staff ID: ";
    cin >> ID;
}

void Staff::display1() {
    cout << "Name: " << name << endl;
    cout << "Department: " << dept << endl;
    cout << "ID: " << ID << endl;
}

// Teacher functions
void Teacher::accept2() {
    accept1();
    cout << "Enter subject name: ";
    cin >> subject;
    cout << "Enter staff experience: ";
    cin >> experience;
}

void Teacher::display2() {
    display1();
    cout << "Subject: " << subject << endl;
    cout << "Experience: " << experience << endl;
}

// SupportStaff functions
void SupportStaff::accept3() {
    accept1();
    cout << "Enter area name: ";
    cin >> area;
}

void SupportStaff::display3() {
    display1();
    cout << "Area: " << area << endl;
}

int main() {
    int n, m;
    int choice;

    cout << "Enter number of teachers: ";
    cin >> n;
    Teacher t1[n];

    cout << "Enter number of support staff: ";
    cin >> m;
    SupportStaff ss1[m];

    // Take teacher details 
    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter Teacher " << i + 1 << " Details ---\n";
        t1[i].accept2();
    }

    // Take support staff details
    for (int i = 0; i < m; i++) {
        cout << "\n--- Enter Support Staff " << i + 1 << " Details ---\n";
        ss1[i].accept3();
    }

    // menu for display
    do {
        cout << "\n===== STAFF MENU =====\n";
        cout << "3. Display Teacher Details\n";
        cout << "4. Display Support Staff Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 3:
            for (int i = 0; i < n; i++) {
                cout << "\n--- Teacher " << i + 1 << " Details ---\n";
                t1[i].display2();
            }
            break;

        case 4:
            for (int i = 0; i < m; i++) {
                cout << "\n--- Support Staff " << i + 1 << " Details ---\n";
                ss1[i].display3();
            }
            break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
