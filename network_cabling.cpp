#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    vector <int> Xs, Ys;
    for (int i = 0; i < N; ++i) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        Xs.push_back(X);
        Ys.push_back(Y);
    }
    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());
    double medianX = Xs.size()%2 ? Xs[Xs.size()/2] : (Xs[Xs.size()/2 - 1] + Xs[Xs.size()/2])/2;
    double medianY = Ys.size()%2 ? Ys[Ys.size()/2] : (Ys[Ys.size()/2 - 1] + Ys[Ys.size()/2])/2;;
    long long int cableAmount = 0;
    for (size_t i = 0; i < N; ++i) {
        cableAmount += abs(medianX - Xs[i]) + abs(medianY - Ys[i]);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << cableAmount << endl;
}
