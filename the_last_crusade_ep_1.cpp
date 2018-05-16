#include <iostream>
#include <sstream>
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
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    int pattern[H][W];
    for (int i = 0; i < H; i++) {
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        getline(cin, LINE);
        stringstream iss(LINE);
        int number, j = 0;
        while (iss >> number) {
           pattern[i][j]= number;
           ++j;
        }
    }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();

    // game loop
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        switch (pattern[YI][XI]){
            case 0:
                break;
            case 1:
                if (POS == "LEFT") cout << XI + 1 << " " << YI + 1 << endl;
                else if (POS == "RIGHT") cout << XI - 1 << " " << YI + 1 << endl;
                     else cout << XI + 1 << " " << YI + 1 << endl;
                break;
            case 2: case 6:
                if (POS == "LEFT") cout << XI + 1 << " " << YI << endl;
                else if (POS == "RIGHT") cout << XI - 1 << " " << YI << endl;
                break;
            case 3:
                cout << XI << " " << YI + 1 << endl;
                break;
            case 4: case 12:
                cout << XI - 1 << " " << YI + 1 << endl;
                break;
            case 5: case 13:
                cout << XI + 1 << " " << YI + 1 << endl;
                break;
            case 7:
                if (POS == "RIGHT") cout << XI - 1 << " " << YI + 1 << endl;
                else if (POS == "TOP") cout << XI << " " << YI + 1 << endl;
                break;
            case 8:
                if (POS == "RIGHT") cout << XI - 1 << " " << YI + 1 << endl;
                else if (POS == "LEFT") cout << XI + 1 << " " << YI + 1 << endl;
                break;
            case 9:
                if (POS == "LEFT") cout << XI + 1 << " " << YI + 1 << endl;
                else if (POS == "TOP") cout << XI << " " << YI + 1 << endl;
                break;
            case 10:
                cout << XI - 1 << " " << YI << endl;
                break;
            case 11:
                cout << XI + 1 << " " << YI << endl;
                break;

        }

        // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
        /*cout << "0 0" << endl;*/
    }
}
