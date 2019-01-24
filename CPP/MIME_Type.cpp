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
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    map<string, string> fileExtensions;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        for (auto & c: EXT) c = toupper(c);
        fileExtensions.insert(make_pair(EXT, MT));
    }

    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);

        string extension;
        if(FNAME.find_last_of(".") != string::npos){
            extension = FNAME.substr(FNAME.find_last_of('.') + 1);
        }
        for (auto & c: extension) c = toupper(c);
        if (fileExtensions.find(extension) != fileExtensions.end()) {
            cout << fileExtensions[extension] << endl;
        } else {
            cout << "UNKNOWN" << endl;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    //cout << "UNKNOWN" << endl;
}
