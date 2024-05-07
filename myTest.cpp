#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
            {0, 1, 0, 0},
            {1, 0, 1, 1},
            {0, 1, 0, 0},
            {0, 1, 0, 0}
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}


TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0 -> 1 -> 2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1 (invalid path)");

    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0}
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0 -> 1 -> 2 -> 3 -> 4");
}


TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph3 = {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}


TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}.");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite.");

    vector<vector<int>> graph3 = {
            {0, 1, 1, 0, 1, 0},
            {1, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {0, 1, 1, 0, 1, 1},
            {1, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0}
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 3}, B={1, 2, 4, 5}.");
}

TEST_CASE("Test negativeCycle") {
    ariel::Graph g;

    // Graph with no negative cycle
    vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == false);

    // Graph with negative cycle
    vector<vector<int>> graph2 = {
            {0, 1, 1},
            {0, 0, -1},
            {0, -1, 0}
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == true);

    // Graph with negative weights and negative cycle
    vector<vector<int>> graph3 = {
            {0, -2, 0, 0},
            {-2, 0, -2, 0},
            {0, -2, 0, -1},
            {0, 0, -1, 0}
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == true);

    vector<vector<int>> graph4 = {
            {0, -1, 0, 0},
            {-1, 0, 2, 0},
            {0, -3, 0, 1},
            {0, 0, 1, 0}
    };
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == true);
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

int main(int argc, char* argv[]) {
    // Initialize Doctest runner
    doctest::Context context;
    context.applyCommandLine(argc, argv);  // Apply command line arguments

    // Run tests
    int result = context.run();

    return result;  // Return test result
}
