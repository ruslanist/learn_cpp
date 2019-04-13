#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::make_pair;

int main()
{
    vector<pair<int, int>> friend_edges;

    friend_edges.push_back(make_pair(1,2));
    friend_edges.push_back(make_pair(1,3));
    friend_edges.push_back(make_pair(1,4));

    friend_edges.push_back(make_pair(2,1));
    friend_edges.push_back(make_pair(3,1));
    friend_edges.push_back(make_pair(4,1));

    map<int, vector<int>> friend_to_links;

    for (auto edge : friend_edges) {

        friend_to_links[edge.first].push_back(edge.second);
    }

    for (auto server : friend_to_links) {

        cout << server.first << " " << "has friends" << endl;

        for (auto link : server.second) {

            cout << link << endl;
        }
    }

    cout << "Informations of server and public gests" << endl;

    vector<pair<string, string>> info_of_pc;

    info_of_pc.push_back(make_pair("Server_ID", "192.168.1.01"));
    info_of_pc.push_back(make_pair("Andrei_Ivanov", "192.168.1.02"));
    info_of_pc.push_back(make_pair("Olga_Petrova", "192.168.1.03"));
    info_of_pc.push_back(make_pair("Gana_Aleksandrova", "192.168.1.04"));

    map<string, vector<string>> id_PC;

    for (auto id_comp : info_of_pc) {

        id_PC[id_comp.first].push_back(id_comp.second);
        cout << endl;
    }


    for (auto id : id_PC) {

        cout << "Name of Client"<< " " << "-" << " " << id.first << endl;

        for (auto id2 : id.second) {

            cout << "IP Adress:" << " " << id2 << endl;
            cout << endl;
        }
    }

    return 0;
}
