#include "Graph.hpp"
#include <iostream>
#include <vector>

namespace ariel {

    Graph::Graph() : numVertices(0), directed(false), weighted(false) {}

    void Graph::loadGraph( std::vector<std::vector<int>> matrix) {
        size_t n = matrix.size();
        for (size_t i = 0; i < n; ++i) {
            if (matrix[i].size() != n) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        if (matrix.size() != matrix[0].size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        numVertices = static_cast<int>(matrix.size()); // Convert size_type to int
        adjacencyMatrix = matrix;
        directed = false;
        weighted = false;

        // Determine if the graph is directed or weighted based on the matrix
        for (std::vector<std::vector<int>>::size_type i = 0; i < matrix.size(); i++) {
            for (std::vector<int>::size_type j = 0; j < matrix[i].size(); j++) {
                if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                    directed = true;
                    break;
                }
            }
            if (directed) break;
        }

        for (const auto& row : matrix) {
            for (int val : row) {
                if (val != row[0] && val != 0) {
                    weighted = true;
                }
            }
        }
    }


    void Graph::printGraph()  {
        std::cout << "Graph with " << numVertices << " vertices and " << countEdges() << " edges." << std::endl;
    }

    int Graph::countEdges()  {
        int edges = 0;
        for (const auto& row : adjacencyMatrix) {
            for (int val : row) {
                if (val > 0) {
                    edges++;
                }
            }
        }
      return edges;
    }

    int Graph::getNumVertices()  {
        return numVertices;
    }

    int Graph::getAdjacency(int row, int col)  {
        if (row < 0 || col < 0 || static_cast<size_t>(row) >= adjacencyMatrix.size() || static_cast<size_t>(col) >= adjacencyMatrix[0].size()) {
            // Handle out-of-bounds access
            return 0; // or throw an exception, or return a default value
        }
        return adjacencyMatrix[static_cast<size_t>(row)][static_cast<size_t>(col)];
    }

}
