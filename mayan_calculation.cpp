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

 void set_number_table(const string[] &numbers, int L, int H);

 int get_dec_from_mayan(const vector <string> &number);

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
    int S1_number = 0;
    cin >> S1; cin.ignore();
    int reg = S1/L;
    for (int i = reg - 1; i >= 0; --i) {
        vector <string> str_number;
        for (int j = 0; j < L; ++j) {
            string num1Line;
            cin >> num1Line; cin.ignore();
            str_number.push_back(num1Line);
        }
        S1_number += pow(20, i) * get_dec_from_mayan(str_number);
    }
    int S2;
    int S2_number = 0;
    cin >> S2; cin.ignore();
    reg = S2/L;
    for (int i = reg - 1; i >= 0; --i) {
        vector <string> str_number;
        for (int j = 0; j < L; ++j) {
            string num2Line;
            cin >> num2Line; cin.ignore();
            str_number.push_back(num2Line);
        }
        S2_number += pow(20, i) * get_dec_from_mayan(str_number);
    }
    int num_result;
    string operation;
    cin >> operation; cin.ignore();
    switch (operation) {
        case '+': num_result = S1_number + S2_number;
        case '-': num_result = S1_number - S2_number;
        case '/': num_result = S1_number / S2_number;
        case '*': num_result = S1_number * S2_number;
    }
    int output = num_result % 20;
    while (output != 0){
        
        output %= 20;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "result" << endl;
}

void set_number_table(const string[] &numbers, int L, int H) {
    for (size_t  i = 0; i < 20; ++i) {
        vector<string> one_number;
        for (size_t j = 0; j < H; ++j) {
            one_number.push_back(numbers[j].substr(i*L, L));
        }
        number_table.insert(pair<int, vector<string>>(i, one_number));
    }
  }
}

int get_dec_from_mayan(const vector <string> &number) {
    for (auto it : number_table) {
        if (it->second ==  number) {
            return it->first;
        }
    }
    return -1;
}
