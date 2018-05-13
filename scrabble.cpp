#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int countPoints (string word){//, map <char, int> points) {
    int result = 0;
    map <char, int> points;
        points.insert(make_pair('e', 1));
        points.insert(make_pair('a', 1));
        points.insert(make_pair('i', 1));
        points.insert(make_pair('o', 1));
        points.insert(make_pair('n', 1));
        points.insert(make_pair('r', 1));
        points.insert(make_pair('t', 1));
        points.insert(make_pair('l', 1));
        points.insert(make_pair('s', 1));
        points.insert(make_pair('u', 1));
        points.insert(make_pair('d', 2));
        points.insert(make_pair('g', 2));
        points.insert(make_pair('b', 3));
        points.insert(make_pair('c', 3));
        points.insert(make_pair('m', 3));
        points.insert(make_pair('p', 3));
        points.insert(make_pair('f', 4));
        points.insert(make_pair('h', 4));
        points.insert(make_pair('v', 4));
        points.insert(make_pair('w', 4));
        points.insert(make_pair('y', 4));
        points.insert(make_pair('k', 5));
        points.insert(make_pair('j', 8));
        points.insert(make_pair('x', 8));
        points.insert(make_pair('q', 10));
        points.insert(make_pair('z', 10));


    for (string::iterator it = word.begin(); it < word.end(); it++) {
        result += points[*it];
    }

    return result;
}

int main()
{
    int N;
    cin >> N; cin.ignore();


    vector <string> dictionary;
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        dictionary.push_back(W);
    }

    string LETTERS;
    getline(cin, LETTERS);
    map <int, string> possibleResults;
    for (int c = 0; c < N; ++c) {
        bool isAllIn = true;    //all letters word r from LETTERS
        if (dictionary[c].length() <= LETTERS.length()) {
            string l(LETTERS);
            for (string::iterator it = dictionary[c].begin(); it < dictionary[c].end(); it++){
                int pos = l.find(*it);
                if (pos == string::npos){
                    isAllIn = false;
                    break;
                }
                l.erase(pos, 1);
            }
            if (isAllIn) {
                possibleResults.insert(make_pair(countPoints(dictionary[c]), dictionary[c]));
            }
        }

    }
    cout << possibleResults.rbegin()->second;

}
