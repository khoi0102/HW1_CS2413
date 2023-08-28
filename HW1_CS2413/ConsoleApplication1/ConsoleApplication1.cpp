#include <iostream>
using namespace std;

// ======= Task 2 =======

class Student {
public:
    void set_SID(int x);
    void prt_SID();
    void set_GPA(float y);
    void prt_GPA();
    void reset();
    float get_GPA();
    Student();
private:
    int SID;
    float GPA;
};

class University {
public:
    void set_Stu(Student x[]);
    float GPA_Mean();
    float GPA_Max();
    float GPA_Min();
    University();
private:
    Student Sooner[5];
};

// Student member function implementations
Student::Student() {
    SID = -1;
    GPA = -1.0;
}

void Student::set_SID(int x) {
    SID = x;
}

void Student::prt_SID() {
    cout << SID;
}

void Student::set_GPA(float y) {
    GPA = y;
}

void Student::prt_GPA() {
    cout << GPA;
}

void Student::reset() {
    SID = -1;
    GPA = -1.0;
}

float Student::get_GPA() {
    return GPA;
}

// University member function implementations
University::University() {
    for (int i = 0; i < 5; i++) {
        Sooner[i].reset();
    }
}

void University::set_Stu(Student x[]) {
    for (int i = 0; i < 5; i++) {
        Sooner[i] = x[i];
    }
}

float University::GPA_Mean() {
    float sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += Sooner[i].get_GPA();
    }
    return sum / 5;
}

float University::GPA_Max() {
    float max = Sooner[0].get_GPA();
    for (int i = 1; i < 5; i++) {
        if (Sooner[i].get_GPA() > max) {
            max = Sooner[i].get_GPA();
        }
    }
    return max;
}

float University::GPA_Min() {
    float min = Sooner[0].get_GPA();
    for (int i = 1; i < 5; i++) {
        if (Sooner[i].get_GPA() < min) {
            min = Sooner[i].get_GPA();
        }
    }
    return min;
}

int main() {
    Student x[5];
    University OU;
    int sid;
    float gpa;

    // Test 1
    for (int i = 0; i < 5; i++) {
        x[i].prt_SID(); cout << ' ';
        x[i].prt_GPA(); cout << endl;
    }

    // Task 3: Input SID and GPA
    cout << "Enter SID and GPA for 5 students (format: SID1 GPA1 SID2 GPA2 ...): ";
    for (int i = 0; i < 5; i++) {
        cin >> sid >> gpa;
        x[i].set_SID(sid);
        x[i].set_GPA(gpa);
    }

    // Test 2
    for (int i = 0; i < 5; i++) {
        x[i].prt_SID(); cout << ' ';
        x[i].prt_GPA(); cout << endl;
    }

    // Test 3
    OU.set_Stu(x);
    cout << OU.GPA_Mean() << ' ';
    cout << OU.GPA_Max() << ' ';
    cout << OU.GPA_Min() << endl;

    // Test 4
    for (int i = 0; i < 5; i++) {
        x[i].reset();
        x[i].prt_SID(); cout << ' ';
        x[i].prt_GPA(); cout << endl;
    }

    return 0;
}
