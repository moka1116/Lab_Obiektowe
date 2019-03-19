#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Vehicle {
public:
    Vehicle() = default;

    string name;

    double millage{};
    unsigned int diameter{};
    long long int turnNumber{};

    void setTurnNumber() {
        this->turnNumber = (long long int) ((millage * 100000) / (7.97964622 * diameter));/*3,14*2,54*/
    }

};

struct Comparator {
    bool operator()(const Vehicle &vehicle, const Vehicle &vehicle1) const {
        if (vehicle.turnNumber == vehicle1.turnNumber) {
            return !(lexicographical_compare(vehicle.name.begin(), vehicle.name.end(),
                                             vehicle1.name.begin(), vehicle1.name.end()));
        } else {
            return (vehicle.turnNumber > vehicle1.turnNumber);
        }
    }
};

int main() {

    long long int counter;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> counter;
    long long int i;

    vector<Vehicle> pd;
    Vehicle unit;
    for (i = 0; i < counter; i++) {

        getline(cin, unit.name);
        getline(cin, unit.name);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> unit.millage >> unit.diameter;
        unit.setTurnNumber();
        switch (i) {
            case 0:
                pd.push_back(unit);
                break;
            case 1:
                pd.push_back(unit);
                break;
            case 2:
                pd.push_back(unit);
                break;
            default:
                pd.push_back(unit);
                sort(begin(pd), end(pd), Comparator());
                pd.erase(pd.begin());
        }

    }

    ios_base::sync_with_stdio(false);
    cout << pd[2].name << "\n" << pd[2].turnNumber << "\n" << pd[1].name << "\n" << pd[1].turnNumber << "\n"
         << pd[0].name << "\n" << pd[0].turnNumber;


    return 0;


}