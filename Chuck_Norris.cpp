#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    string bin_message = "";
    for (int i = 0; i < MESSAGE.size(); ++i){
            bin_message += bitset<7>(MESSAGE[i]).to_string();
       }
        
        if (bin_message[0] == '1'){
            cout << "0 0";
        } else {
            cout << "00 0";
        }
        for (int j=1; j<bin_message.size(); j++){
            if (bin_message[j] != bin_message[j-1]){
                if (bin_message[j] == '1') {
                    cout << " 0 0";
                } else {
                    cout << " 00 0";
                }
            } else {
                cout << "0";
            }
        }

    

    cout <<endl;
}
