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
    graph->addNode("England");

    graph->addEdge("Oliver", { "teaches at", "UCLan" });
    graph->addEdge("Martin", { "teaches at", "UCLan" });
    graph->addEdge("Oliver", { "lives in", "Preston" });
    graph->addEdge("Martin", { "lives in", "Preston" });
    graph->addEdge("UCLan", { "has campus in", "Preston" });
    graph->addEdge("UCLan", { "has campus in", "Larnaka" });
    graph->addEdge("Preston", { "is in", "England" });


    // The problem
    vector<string> p = { "teaches at", "has campus in"};
    vector<string> q = { "lives in" };

    graph->solve(p, q);


}
