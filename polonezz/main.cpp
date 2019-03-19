#include <iostream>

using namespace std;

class Student {

public:
    string id;
    int distance{};
    int month{};
    double srednia{};


    int getDistance() {
        return distance;
    }

    const string getId() {
        return id;
    }

    int getMonth() {
        return month;
    }

    double getSrednia() {
        return srednia;
    }


};

bool compareSMD(Student student, Student student1) {
    if (student.getSrednia() == student1.getSrednia()) {
        if (student.getMonth() == student1.getMonth()) {
            return student.getDistance() < student1.getDistance();
        } else {
            return (student.getMonth() < student1.getMonth());
        }
    } else {
        return student.getSrednia() < student1.getSrednia();
    }
}


bool compareSDM(Student student, Student student1) {
    if (student.getSrednia() == student1.getSrednia()) {
        if (student.getDistance() == student1.getDistance()) {
            return student.getMonth() < student1.getMonth();
        } else {
            return (student.getDistance() < student1.getDistance());
        }
    } else {
        return student.getSrednia() < student1.getSrednia();
    }
}


bool compareDSM(Student student, Student student1) {
    if (student.getDistance() == student1.getDistance()) {
        if (student.getSrednia() == student1.getSrednia()) {
            return (student.getMonth() < student1.getMonth());
        } else {
            return student.getSrednia() < student1.getSrednia();
        }
    } else {
        return student.getDistance() < student1.getDistance();
    }
}


bool compareDMS(Student student, Student student1) {
    if (student.getDistance() == student1.getDistance()) {
        if (student.getMonth() == student1.getMonth()) {
            return student.getSrednia() < student1.getSrednia();
        } else {
            return student.getMonth() < student1.getMonth();
        }
    } else {
        return student.getDistance() < student1.getDistance();
    }
}


bool compareMSD(Student student, Student student1) {
    if (student.getMonth() == student1.getMonth()) {
        if (student.getSrednia() == student1.getSrednia()) {
            return (student.getDistance() < student1.getDistance());
        } else {
            return student.getSrednia() < student1.getSrednia();
        }
    } else {
        return student.getMonth() < student1.getMonth();
    }
}


bool compareMDS(Student student, Student student1) {
    if (student.getMonth() == student1.getMonth()) {
        if (student.getDistance() == student1.getDistance()) {
            return (student.getSrednia() < student1.getSrednia());
        } else {
            return student.getDistance() < student1.getDistance();
        }
    } else {
        return student.getMonth() < student1.getMonth();
    }
}

int main() {

    int counter;
    std::ios_base::sync_with_stdio(false);
    cin >> counter;
    Student male[counter];
    Student female[counter];
    char a, b, c;
    std::ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    bool (*wsk_f)(Student student, Student student1);

    if (a == 'm') {
        if (b == 'd') {
            wsk_f = &compareMDS;

        } else {
            wsk_f = &compareMSD;

        }
    } else {
        if (a == 'd') {
            if (b == 'm') {
                wsk_f = &compareDMS;

            } else {
                wsk_f = &compareDSM;

            }

        } else {
            if (b == 'd') {
                wsk_f = &compareSDM;

            } else {
                wsk_f = &compareSMD;

            }
        }
    }


    for (long k = 0; k < counter; k++) {
        std::ios_base::sync_with_stdio(false);
        cin >> male[k].id >> male[k].srednia >> male[k].distance >> male[k].month
            >> female[k].id >> female[k].srednia >> female[k].distance >> female[k].month;

    }

    Student placeholder;
    Student placeholder1;
    for (int i = 1; i < counter; ++i) {
        for (int j = i; j > 0 && wsk_f(male[j - 1], male[j]); --j) {
            placeholder = male[j - 1];
            male[j - 1] = male[j];
            male[j] = placeholder;
        }
    }
    for (int i = 1; i < counter; ++i) {
        for (int j = i; j > 0 && wsk_f(female[j - 1], female[j]); --j) {
            placeholder1 = female[j - 1];
            female[j - 1] = female[j];
            female[j] = placeholder1;
        }
    }


    for (int g = 0; g < counter; g++) {
        std::ios_base::sync_with_stdio(false);
        cout << male[g].getId() << " " << female[g].getId() << " ";
    }

    return 0;
}