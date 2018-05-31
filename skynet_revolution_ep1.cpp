#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Node {
public:
    Node() : isGateway(false), distanceFromAgent(0) {};
    void setIsGateway(bool isGateway) { this->isGateway = isGateway;}
    bool getIsGateway() { return  isGateway;}
    void addLinkedNode (int no);
    void deleteLinkedNode (int no);
    bool isLinkedNode (int no);
    void setDistanceFromAgent (int distance) {distanceFromAgent = distance;}
    int getDistanceFromAgent () {return distanceFromAgent;}
private:
    bool isGateway;
    vector <int> linkedNodes;
    int distanceFromAgent;
};

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    int adjMatrix[N][N] = {};    // adjacency matrix for graph
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        adjMatrix[N1][N2] = 1;
        adjMatrix[N2][N1] = 1;
    }
    int gateways[E] = {};
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        gateways[i] = 1;
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << "0 1" << endl;
    }
}

void Node::addLinkedNode (int no){
    if (find(linkedNodes.begin(), linkedNodes.end(), no) == linkedNodes.end()){
        linkedNodes.push_back(no);

    }
}
void deleteLinkedNode (int no);
bool isLinkedNode (int no);
