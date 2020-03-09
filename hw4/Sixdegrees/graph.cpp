#include "graph.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

Graph::Graph()
{
    actorCount = 0;
}

void Graph::insert(vector<string> data)
{
    string movie = data[0];
    vector<string> actors(data.begin() + 1, data.end());
    list<Coactor> coactors;
    for (string actor : actors)
        coactors.push_back(Coactor(actor, movie));
    for (string actor : actors)
    {
        list<Coactor> temp = coactors;
        temp.remove(Coactor(actor, movie));
        if (graph.find(actor) == graph.end())
            graph.insert(pair<string, list<Coactor>>(actor, temp));
        else
        {
            graph[actor].insert(graph.at(actor).end(), temp.begin(), temp.end());
        }
    }
}

bool Graph::BFS(queue<string> *queue, unordered_map<string, bool> *visited, unordered_map<string, Coactor> *parent, string dest)
{
    string current = queue->front();
    queue->pop();
    for (Coactor ca : graph[current])
    {
        if (visited->at(ca.name) == false)
        {
            parent->insert(pair<string, Coactor>(ca.name, Coactor(current, ca.movie)));
            visited->at(ca.name) = true;
            queue->push(ca.name);
            if (ca.name == dest)
                return true;
        }
    }
    return false;
}

list<string> getfinalPath(unordered_map<string, Coactor> s_parent, string src, string dest)
{
    list<string> path;
    string actor = dest;
    path.push_back(actor);
    while (actor != src)
    {
        path.push_back(s_parent.at(actor).movie);
        path.push_back(s_parent.at(actor).name);
        actor = s_parent.at(actor).name;
    }
    // cout << "path complete" << endl;
    reverse(path.begin(), path.end());
    return path;
}

list<string> Graph::shortestPath(string src, string dest)
{
    unordered_map<string, bool> s_visited;
    unordered_map<string, Coactor> s_parent;
    queue<string> s_queue;
    for (pair<string, list<Coactor>> pair : graph)
    {
        s_visited.insert(::pair<string, bool>(pair.first, false));
    }

    s_queue.push(src);
    s_visited[src] = true;

    s_parent.insert(::pair<string, Coactor>(src, Coactor("", "")));

    while (!s_queue.empty())
    {
        if (BFS(&s_queue, &s_visited, &s_parent, dest))
        {
            // cout << "finding path" << endl;
            return ::getfinalPath(s_parent, src, dest);
        }
    }
    list<string> temp = {""};
    return temp;
}

void Graph::printMap()
{
    for (pair<string, list<Coactor>> pair : graph)
    {
        cout << "\033[1;32m" << pair.first << "\033[1;37m||";
        for (Coactor coactor : pair.second)
        {
            cout << "\033[1;31m" << coactor.name << "\033[1;37m:" << coactor.movie << "|";
        }
        cout << endl;
    }
}

bool Graph::exists(string src, string dest)
{
    return ((graph.find(src) != graph.end()) && (graph.find(dest) != graph.end()));
}