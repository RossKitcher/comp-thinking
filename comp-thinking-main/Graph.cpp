#include "Graph.h"

void Graph::addNode(string name)
{

	Node node;

	node.name = name;

	mNodes.push_back(node);

}





void Graph::addEdge(string name, Edge edge)
{

	auto iter = find_if(mNodes.begin(), mNodes.end(), [&name](Node& testNode) {
		return (name == testNode.name);
		});


	iter->edges.push_back(edge);

	references ref;
	ref.to = edge.to;
	ref.from = iter->name;
	ref.label = edge.label;

	all_edges.insert(make_pair(mEdgeID, ref));

	mEdgeID++;


}

void Graph::displayAll()
{

	for (auto& node : mNodes) {

		auto edges = node.edges;

		cout << "Node: " << node.name << endl;;

		for (auto edge : edges) {
			cout << "\t" << edge.label << " " << edge.to << endl;;
		}



	}

}

void Graph::displayAllEdges()
{

	for (auto& edge : all_edges) {
		cout << edge.second.label << "; From: " << edge.second.from << "; To: " << edge.second.to << endl;
	}

}

void Graph::solve(vector<string> p, vector<string> q)
{

	vector<Pair> pPairs;
	vector<Pair> qPairs;


	findMatchingPairs(pPairs, p);
	findMatchingPairs(qPairs, q);

	vector<Pair> finalPairs;

	for (Pair& pPair : pPairs) {
		for (Pair& qPair : qPairs) {
			if (pPair.from == qPair.from && pPair.to == qPair.to) {
				finalPairs.push_back(pPair);
			}
		}
	}	

	for (auto& pair : finalPairs) {
		cout << pair.from << " : " << pair.to << endl;
	}

}

void Graph::findMatchingPairs(vector<Pair>& pairs, vector<string> labels)
{

	vector<vector<references>> all_matches;

	getAllMatches(labels, all_matches);

	splitAllMatches(pairs, all_matches);

}

void Graph::getAllMatches(vector<string> labels, vector<vector<references>>& all_matches)
{

	for (string label : labels) {

		vector<references> matches;

		for (auto edge : all_edges) {
			if (edge.second.label == label) {
				matches.push_back(edge.second);
			}
		}

		all_matches.push_back(matches);

	}

}

void Graph::splitAllMatches(vector<Pair>& pairs, vector<vector<references>>& all_matches)
{

	for (size_t i = 0; i < all_matches.size(); i += 2) {

		if (i + 1 == all_matches.size()) {

			combine(pairs, all_matches[i]);

		}
		else {

			combine(pairs, all_matches[i], all_matches[i + 1]);

		}
	}

}

void Graph::combine(vector<Pair>& pairs, vector<references> left_ref)
{

	vector<Pair> oldPairs = pairs;
	pairs.clear();

	for (auto& left : left_ref) {

		Pair newpair = { left.to, left.from };

		auto iter = find(oldPairs.begin(), oldPairs.end(), newpair);	// O(n)

		if (iter != oldPairs.end()) {
			newpair.from = iter->from;
		}

		pairs.push_back(newpair);

	}

}

void Graph::combine(vector<Pair>& pairs, vector<references> left_ref, vector<references> right_ref)
{
	vector<Pair> oldPairs = pairs;
	pairs.clear();

	for (auto& left : left_ref) {
		for (auto& right : right_ref) {	
			if (left.to == right.from) {

				Pair newpair = {right.to, left.from};

				auto iter = find(oldPairs.begin(), oldPairs.end(), newpair);

				if (iter != oldPairs.end()) {
					newpair.from = iter->from;
				}

				pairs.push_back(newpair);

			}
		}
	}

}
