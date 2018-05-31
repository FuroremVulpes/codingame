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
    Node() : is_gateway(false), distance_from_agent(0) {};
    void set_is_gateway(bool isGateway) { is_gateway = isGateway;}
    bool get_is_gateway() const { return  is_gateway;}
    void add_linked_node (int no);
    void delete_linked_node (int no);
    bool is_linked_node (int no) const;
    void set_distance_from_agent (int distance) {distance_from_agent = distance;}
    int get_distance_from_agent () const {return distance_from_agent;}
    int get_amount_of_linked_nodes() const { return linked_nodes.size();}
    int get_linked_node_id(int no) const { return linked_nodes[no];}
    void print_node();
private:
    bool is_gateway;
    vector <int> linked_nodes;
    int distance_from_agent;
};

pair<int, int>  prev_node_id_and_distance_BFS (int start_node, int end_node, const vector<Node> &nodes);

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    vector<Node> nodes(N);
    vector<int> gateways;
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        nodes[N1].add_linked_node(N2);
        nodes[N2].add_linked_node(N1);
        cerr << "connected " << N1 << " and " << N2 << endl;
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        gateways.push_back(EI);
        cerr << "gateway at " << i << " is " << gateways[i] << endl;
        nodes[EI].set_is_gateway(true);
        cerr << "node " << EI << endl;
        nodes[EI].print_node();
        cerr << endl;
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        cerr << "SI: " << SI << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        int endangered_gateway;
        int prev_endangered_node;
        int min_endangered_distance = L;
        for (size_t i = 0; i < E; ++i) {
            cerr << "gateway " << gateways[i] << endl;
            pair<int, int> prev_and_dist = prev_node_id_and_distance_BFS(SI, gateways[i], nodes);
            cerr << "Prev_node: " << prev_and_dist.first << " distance: " << prev_and_dist.second << endl;
            nodes[gateways[i]].set_distance_from_agent(prev_and_dist.second);
            if (min_endangered_distance >= prev_and_dist.second) {
                min_endangered_distance = prev_and_dist.second;
                endangered_gateway = gateways[i];
                prev_endangered_node = prev_and_dist.first;
            }
        }
        nodes[endangered_gateway].delete_linked_node(prev_endangered_node);
        nodes[prev_endangered_node].delete_linked_node(endangered_gateway);
        //cerr << "result: " << endangered_gateway << " " << prev_endangered_node << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << endangered_gateway << " " << prev_endangered_node << endl;
    }
}

void Node::add_linked_node (int no){
    if (find(linked_nodes.begin(), linked_nodes.end(), no) == linked_nodes.end()){
        linked_nodes.push_back(no);
        sort(linked_nodes.begin(), linked_nodes.end());
    }
}

void Node::delete_linked_node (int no){
    auto id = find(linked_nodes.begin(), linked_nodes.end(), no);
    if (id != linked_nodes.end()){
        linked_nodes.erase(id);
    }
}

bool Node::is_linked_node (int no) const{
    return find(linked_nodes.begin(), linked_nodes.end(), no) != linked_nodes.end();
}

void Node::print_node() {
    cerr << "Is gateway: " << is_gateway << endl;
    //cerr << "Distance from agent: " << distance << endl;
    cerr << "Lineked nodes:";
    for (auto node : linked_nodes) {
        cerr << " " << node;
    }
    cerr << endl;
}

pair<int, int> prev_node_id_and_distance_BFS (int start_node, int end_node, const vector<Node> &nodes) {
    cerr << "prev_node_id_and_distance_BFS ** start **" << endl;
    int prev_node = -1;
    int distance = 0;
    vector<int> queue;
    vector<bool> visited(nodes.size());
    queue.push_back(start_node);
    visited[start_node] = true;
    while (!queue.empty()) {
        size_t prev_size = queue.size();
        cerr << "prev_size: " << prev_size << endl;
        int curr_node;
        for (size_t i = 0; i < prev_size; ++i) {
            curr_node = queue[i];
            //cerr << "curr_node: " << curr_node << " i: " << i << endl;
            if (curr_node == end_node) {
                //cerr << "curr_node == end_node" << endl;
                //cerr << "prev_node: " << prev_node << " distance: " << distance << endl;
                //cerr << "prev_node_id_and_distance_BFS ** end **" << endl;
                return make_pair(prev_node, distance);
                //return prev_node_distance;
            }
            const Node &node = nodes[curr_node];
            visited[curr_node] = true;
            for (size_t j = 0; j < node.get_amount_of_linked_nodes(); ++j) {
                int linked_node = node.get_linked_node_id(j);
                if (!visited[linked_node]) {
                    queue.push_back(linked_node);
                }
            }
        }
        cerr << "Before cutting queue:";
        for (auto it : queue) {
            cerr << " " << it;
        }
        cerr << endl;
        if (queue.size() - prev_size != 0) prev_node = curr_node;
        queue.erase(queue.begin(), queue.begin() + prev_size);
        ++distance;
    }
    //cerr << "prev_node_id_and_distance_BFS ** end **" << endl;
    return make_pair(prev_node, distance);
    //return prev_node_distance;
}
