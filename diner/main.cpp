#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int result;

void backTracking(const vector<int> &products, int start, int target) {
    if (target < 0) {
        return;
    } else {
        if (target == 0) {
            result++;
        } else {
            for (int i = start; i < products.size(); i++) {
                backTracking(products, i + 1, target - products[i]);
            }
        }
    }
}

void backTracking(vector<int> products, int target) {
    sort(products.rbegin(), products.rend());
    backTracking(products, 0, target);

}

int main() {
    vector<int> products;
    int quantityOfTests, quantityOfProducts, target, product;
    ios_base::sync_with_stdio(false);
    cin >> quantityOfTests;
    for (int i = 0; i < quantityOfTests; i++) {
        result = 0;
        std::ios_base::sync_with_stdio(false);
        cin >> quantityOfProducts;
        for (int j = 0; j < quantityOfProducts; j++) {
            ios_base::sync_with_stdio(false);
            cin >> product;
            products.push_back(product);
        }
        ios_base::sync_with_stdio(false);
        cin >> target;
        cin.tie(nullptr);
        backTracking(products, target);
        ios_base::sync_with_stdio(false);
        cout << result << " ";
        products.clear();
    }


    return 0;
}