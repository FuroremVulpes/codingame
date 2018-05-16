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
    int indexMax = 0;
    for (int j = 0; j < n - 1; ++j) {
        if (stockValues[j] > stockValues[indexMax]) indexMax = j;
    }
    int indexMin = indexMax;
    cerr << "indexMax: " << indexMax << " value: " << stockValues[indexMax] << endl;
    for (int k = indexMax; k < n; ++k) {
        if (stockValues[k] < stockValues[indexMin]) indexMin = k;
    }
    cerr << "indexMin: " << indexMin << " value: " << stockValues[indexMin] << endl;
    cout << stockValues[indexMin] - stockValues[indexMax] << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


}
