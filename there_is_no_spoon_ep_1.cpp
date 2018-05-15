#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    vector <string> input;
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        input.push_back(line);
        cerr << line << endl;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; ++j) {
            if (input[i][j] == '0') {
                cout << j << " " << i;
                //right node
                bool isFound = false;
                for (int k = i; k < height && !isFound; ++k) {
                    for (int l = j + 1; l < width && !isFound; ++l) {
                        if (input[k][l] == '0') {
                            cout << " " << l << " " << k;
                            isFound = true;
                        }
                    }
                }
                if (!isFound) cout << " -1 -1";
                //bottom node
                isFound = false;
                for (int k = i + 1; k < height && !isFound; ++k) {
                    for (int l = j; l < width && !isFound; ++l) {
                        if (input[k][l] == '0') {
                            cout << " " << l << " " << k;
                            isFound = true;
                        }
                    }
                }
                if (!isFound) cout << " -1 -1";
                cout << endl;
            }
        }
    }


    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    //cout << "0 0 1 0 0 1" << endl;
}
