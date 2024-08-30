# erdosRenyi
Erdos-Renyi Graph Generator

This project implements the Erdos-Renyi Model for generating random graphs. The algorithm creates a graph with n nodes, where each possible edge between a pair of nodes is included with a probability p. The graph can be directed or undirected, depending on user input, and the resulting adjacency matrix is saved to a specified file.

Key Features:
1. Random Graph Generation: Generates a graph based on the Erdos-Renyi model, allowing for the creation of random structures with customizable node count and edge probability.
2. Directed or Undirected: Users can specify whether the graph should be directed or undirected.
3. File Output: The adjacency matrix representing the graph is saved to a file, which can be used for further analysis or visualization.

How It Works:
1. User Input: The user specifies the number of nodes (n), the probability (p) for edge creation, whether the graph is directed, and the file name to save the graph.
2. Graph Generation: The algorithm iteratively checks each possible edge between pairs of nodes, adding an edge based on the given probability p.
3. File Output: The generated adjacency matrix is written to a file specified by the user.
4. Memory Management: After the graph is generated and saved, the allocated memory for the adjacency matrix is freed.

This implementation is useful for studying random graph properties, simulating network structures, or testing algorithms on randomly generated graphs. The flexibility in specifying parameters makes it a versatile tool for various graph-related experiments.
