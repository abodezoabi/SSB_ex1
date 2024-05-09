/*
 * ID: 211407424
 * abodezoabi2000@gmail.com
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept> // For std::invalid_argument

namespace ariel {

    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        int numVertices;
       // bool directed;
        bool weighted;

    public:
        bool directed;
        // Constructor
        Graph();

        // Load graph from adjacency matrix
        void loadGraph( std::vector<std::vector<int>> matrix);

        // Print graph information
        void printGraph() ;

        // Count edges in the graph
        int countEdges() ;

        // Get number of vertices in the graph
        int getNumVertices() ;

        // Get adjacency value between two vertices
        int getAdjacency(int row, int col) ;
    };

} // namespace ariel

#endif // GRAPH_HPP
