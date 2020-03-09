#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iterator>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Coactor
{
public:
    string name;
    string movie;

    Coactor()
    {
        name = movie = "";
    }

    Coactor(string Name, string Movie)
    {
        name = Name;
        movie = Movie;
    }
    bool operator==(const Coactor &ca) const { return (name == ca.name && movie == ca.movie); }
    bool operator!=(const Coactor &ca) const { return (!operator==(ca)); }
};

class Graph
{
private:
    unordered_map<string, list<Coactor>> graph;
    int actorCount;

public:
    Graph();
    void insert(vector<string>);
    list<string> shortestPath(string, string);
    bool BFS(queue<string> *, unordered_map<string, bool> *, unordered_map<string, Coactor> *, string);
    string intersect(unordered_map<string, bool> *, unordered_map<string, bool> *);
    list<string> getfinalPath(unordered_map<string, Coactor>, unordered_map<string, Coactor>, string, string, string);
    void printMap();
    bool exists(string, string);
};

#endif
