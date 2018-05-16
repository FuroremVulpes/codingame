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
    vector <pair<int, int>> nodes;
    for (int i = 0; i < N; ++i) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        nodes.push_back({X, Y});
    }
    sort(nodes.begin(), nodes.end(),
         [](pair<int, int> pair1, pair<int, int> pair2) { return pair1.second < pair2.second;});

    double medianMainCableY;
    if (nodes.size()%2)
        medianMainCableY = nodes[nodes.size()/2].second;
    else
        medianMainCableY = (nodes[nodes.size()/2 - 1].second + nodes[nodes.size()/2].second)/2;;

    int minNodeX = numeric_limits<int>::max();
    int maxNodeX = numeric_limits<int>::min();
    for (auto& node : nodes) {
        if (node.first < minNodeX) minNodeX = node.first;
        if (node.first > maxNodeX) maxNodeX = node.first;
    }

    long long int cableAmount = maxNodeX - minNodeX;
    for (auto& node : nodes) {
        cableAmount += abs(medianMainCableY - node.second);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << cableAmount << endl;
}
