/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <cstddef>
#include <iostream>
#include <map>
#include <utility>
#include "GPS.h"

using namespace std;

 class Edge;
 class Graph;
 class Vertex;


/****************** Provided structures  ********************/


class Vertex {
    GPS info;                // contents
    vector<Edge> adj;  // list of outgoing edges
    bool visited;          // auxiliary field used by dfs and bfs
    bool processing;       // auxiliary field used by isDAG
    int indegree;          // auxiliary field used by topsort

    void addEdge(Vertex *dest, double w);
    bool removeEdgeTo(Vertex *d);
    GPS getInfo() const;

public:
    Vertex(GPS in);
    friend class Graph;
};


class Edge {
    Vertex * dest;      // destination vertex
    double weight;         // edge weight
    string name;
public:
    Edge(Vertex *d, double w);
    Edge(Vertex *d, double w, string name);
    friend class Graph;
    friend class Vertex;
};


class Graph {
    map<long long, Vertex *> vertexSet;    // vertex set

    void dfsVisit(Vertex *v,  vector<GPS> & res) const;
    bool dfsIsDAG(Vertex *v) const;
public:
    int getNumVertex() const;
    bool addVertex(const long long &id, const GPS &in);
    bool removeVertex(const long long &id);
    bool addEdge(const long long &sourcid, const long long &destid);
    bool addDoubleEdge(const long long &sourcid, const long long &destid);
    bool removeEdge(const long long &sourcid, const long long &destid);
    vector<GPS> dfs() const;
    vector<GPS> bfs(const long long &id) const;
    vector<GPS> topsort() const;
    int maxNewChildren(const long long &id, GPS &inf) const;
    bool isDAG() const;
    Vertex *findVertex(const long long &id) const;
};


#endif /* GRAPH_H_ */