#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph {

public:

	struct Edge {
		string label;
		string to;
	};

	struct Node {
		string name;
		vector<Edge> edges;
	};


	struct references {
		string label;
		string from;
		string to;
	};

	struct Pair {
		string to;
		string from;

		bool operator== (const Pair& testPair) const {
			return (testPair.from == to);
		};
	};

	unordered_map<int, references> all_edges;

	void addNode(string name);
	vector<Node>::iterator getNode(string name);
	void addEdge(string name, Edge edge);
	void displayAll();
	void displayAllEdges();

	void solve(vector<string> p, vector<string> q);

private:

	void findMatchingPairs(vector<Pair>& pairs, vector<string> labels);
	void getAllMatches(vector<string> labels, vector<vector<references>>& all_matches);
	void splitAllMatches(vector<Pair>& pairs, vector<vector<references>>& all_matches);
	void combine(vector<Pair>& pairs, vector<references> left_ref);
	void combine(vector<Pair>& pairs, vector<references> left_ref, vector<references> right_ref);

	vector<Node> mNodes;

	int mEdgeID = 0;

};