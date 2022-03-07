// comp-thinking-main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    
    unique_ptr<Graph> graph = make_unique<Graph>();

    graph->addNode("Oliver");
    graph->addNode("Martin");
    graph->addNode("Preston");
    graph->addNode("UCLan");
    graph->addNode("Larnaka");

    Node::Edge teachesAt = { "teaches at", (graph->getNode("UCLan")) };
    Node::Edge livesIn = { "lives in", (graph->getNode("Preston")) };
    Node::Edge hasCampus = { "has campus in", (graph->getNode("Preston")) };
    Node::Edge hasCampusL = { "has campus in", (graph->getNode("Larnaka")) };


    graph->getNode("Oliver")->addEdge(teachesAt);
    graph->getNode("Martin")->addEdge(teachesAt);
    graph->getNode("Oliver")->addEdge(livesIn);
    graph->getNode("Martin")->addEdge(livesIn);
    graph->getNode("UCLan")->addEdge(hasCampus);
    graph->getNode("UCLan")->addEdge(hasCampusL);


    graph->displayAll();


}
