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
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    transform(T.begin(), T.end(), T.begin(), ::toupper);
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        for (int letter = 0; letter < T.length(); letter++){
            int start_index = ((int(T[letter]) >= int('A') and int(T[letter]) <= int('Z'))?int(T[letter]) - int('A'):26);
            for (int j = start_index*L; j < start_index*L+L; j++){
                cout << ROW[j];
            }
            //cout<<" ";
        }
        cout << endl;

    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    //cout << "answer" << endl;
}
