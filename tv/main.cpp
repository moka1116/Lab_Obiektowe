#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int quantityOfTests, quantityOfPrograms, firstMinutPrice, minutPrice, startMinut, endMinut, price;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> quantityOfTests;
    vector<int> start;
    vector<int> end;
    for (int i = 0; i < quantityOfTests; i++) {

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> quantityOfPrograms;
        cin >> firstMinutPrice;
        cin >> minutPrice;
        int price = 0, pesimistic = 0;
        for (int j = 0; j < quantityOfPrograms; j++) {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            cin >> startMinut;
            start.push_back(startMinut);
            cin >> endMinut;
            end.push_back(endMinut);

        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for (int r = 0; r < start.size(); r++) {
            pesimistic += firstMinutPrice + (end[r] - start[r]) * minutPrice;

        }

        auto tmp = start.begin();
        auto it = end.end();

        while (it != end.begin()) {
            it--;
            tmp = upper_bound(start.begin(), start.end(), *it);
            if (tmp == start.end())
                continue;
            if ((*tmp - *it) * minutPrice < firstMinutPrice) {//
                pesimistic -= (firstMinutPrice - (*tmp - *it) * minutPrice);
                cout<<" b";
                start.erase(tmp);
            }

        }

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << pesimistic << "\n";
        start.clear();
        end.clear();
    }
    return 0;
}
