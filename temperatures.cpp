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
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        temp[i] = t;
        //cout << t << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    int result = ((temp.size() == 0)?0:temp[0]);
    for (int t: temp){
        //cout<<"result = " << result<<endl;
        if(abs(t) <= abs(result)){
            //cout << "abs <="<<endl;
            if (abs(t) == abs(result) and (t<0 or result<0)){
                //cout<<"5 -5"<< endl;
                result = t>result?t:result;
            } else {
                //cout<<"just lower" << endl;
                result = t;
            }
            //cout<<"new result = " << result << endl;
        }
    }
    cout << result << endl;
}
