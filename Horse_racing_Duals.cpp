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
    int N;
    cin >> N; cin.ignore();
    int D;
    int arr[N] = {};
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        arr[i] = Pi;
    }
    sort(arr, arr+N);
    D = arr[1] - arr[0];
    for (int i = 1; i < N; i++){
        if (D > (arr[i] - arr[i-1])) {
            D = arr[i] - arr[i-1];
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << D << endl;
}
