#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    cin >> n; cin.ignore();
    vector <int> stockValues;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        stockValues.push_back(v);
    }
    int diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int temp = stockValues[j] - stockValues[i];
            if (temp < diff){
                diff = stockValues[j] - stockValues[i];
            } else if (temp > 0) break;
        }
    }
    cout << diff << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


}
