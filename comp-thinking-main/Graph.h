#pragma once

#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

class Graph {

public:
	typedef vector<unique_ptr<Node>> Nodes;

	void addNode(string name);
	Node* getNode(string name);
	void displayAll();

private:
	Nodes mNodes;


};