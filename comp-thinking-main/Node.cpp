#include "Node.h"

void Node::setEdges(vector<Edge> edges)
{

	mEdges = edges;

}

vector<Node::Edge> Node::getEdges()
{

	return mEdges;

}

void Node::addEdge(Edge edge)
{

	mEdges.push_back(edge);

}

void Node::setName(string name)
{

	mName = name;

}

string Node::getName()
{
	return mName;
}
