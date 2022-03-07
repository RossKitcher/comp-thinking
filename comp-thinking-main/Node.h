#pragma once

#include <iostream>
#include <vector>
//#include "Edge.h"
using namespace std;

class Node {
public:

	struct Edge {
		string label;
		Node* to;
	};

	void setEdges(vector<Edge> edges);
	vector<Edge> getEdges();
	void addEdge(Edge edge);
	void setName(string name);
	string getName();

private:
	string mName;
	vector<Edge> mEdges;
};