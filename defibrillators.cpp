#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
vector<string> split(const string &s, char delim){
    stringstream ss;
    ss << s;
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

double degreesToRadians(const double degrees){
    //cout << "degrees: " << degrees << " radians: " << degrees / 180 * M_PI << endl;
    return degrees / 180 * M_PI;
}

double distance(const double longA, const double longB, const double latA, const double latB){
    double x = (longB - longA) * cos((latA + latB) / 2);
    double y = latB - latA;
    return sqrt(pow(x, 2) + pow(y, 2)) * 6371;      //result in km
}

double string_to_double( const std::string& s ){
    std::istringstream i(s);
    double x;
    if (!(i >> x))
        return 0;
    return x;
}

bool replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

double numComaToDot(string comaIn){
    replace(comaIn, ",", ".");
    return string_to_double(comaIn);
}

int closestDiffIndex(double array[], int size)
{
    int index = 0;

    for(int i = 1; i < size; i++){
        if(array[i] < array[index])
            index = i;
    }
    return index;
}

int main(){
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    vector<string> defibParams[N];
    double distances[N];
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        defibParams[i] = split(DEFIB, ';');
        distances[i] = abs(distance(degreesToRadians(numComaToDot(defibParams[i][4])),
            degreesToRadians(numComaToDot(LON)), degreesToRadians(numComaToDot(defibParams[i][5])),
            degreesToRadians(numComaToDot(LAT))));
        //cout << distances[i] << endl;
    }
    cout << defibParams[closestDiffIndex(distances, N)][1] << endl;
}
