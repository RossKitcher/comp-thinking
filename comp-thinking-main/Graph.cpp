#include "Graph.h"

void Graph::addNode(string name)
{

	unique_ptr<Node> node = make_unique<Node>();

	node->setName(name);

	mNodes.push_back(move(node));

}

Node* Graph::getNode(string name)
{
	
	auto iter = find_if(mNodes.begin(), mNodes.end(), [&name](unique_ptr<Node>& testNode) {
		return (testNode->getName() == name);
		});

	return (*iter).get();

}

void Graph::displayAll()
{

	for (auto& node : mNodes) {

		auto edges = node->getEdges();

		cout << "Node: " << node->getName() << endl;;

		for (auto edge : edges) {
			cout << "\t" << edge.label << " " << edge.to->getName() << endl;;
		}



	}

}
