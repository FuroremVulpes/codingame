#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 map <int, vector<string>> number_table;

 void set_number_table(string[] numbers, int L, int H);

int main()
{
    int L;
    int H;
    string numbers[H];
    int result;
    cin >> L >> H; cin.ignore();
    for (int i = 0; i < H; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        numbers[i] = numeral;
    }
    int S1;
    cin >> S1; cin.ignore();
    for (int i = 0; i < S1; i++) {
        string num1Line;
        cin >> num1Line; cin.ignore();
    }
    int S2;
    cin >> S2; cin.ignore();
    for (int i = 0; i < S2; i++) {
        string num2Line;
        cin >> num2Line; cin.ignore();
    }
    string operation;
    cin >> operation; cin.ignore();

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "result" << endl;
}

void set_number_table(string[] numbers, int L, int H) {
    for (size_t  i = 0; i < 20; ++i) {
        vector<string> one_number;
        for (size_t j = 0; j < H; ++j) {
            one_number.push_back(numbers[j].substr(i*L, L));
        }
        number_table.insert(pair<int, vector<string>>(i, one_number));
    }
  }
}
