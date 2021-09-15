Background

Adjacency matrix

An adjacency matrix is a way of representing the connections between nodes in a graph. For example, the graph

0 -- 1  
    / \ 
   2 - 3
can be represented as

[0, 1, 0, 0]
[1, 0, 1, 1]
[0, 1, 0, 1]
[0, 1, 1, 0]
 
Clique

A clique is a complete subgraph -- that is, some subset of the nodes in the graph which are all interconnected to each other. In the example above, [0,1], [1,2], and [1,2,3] are some (but not all) of the cliques in the graph.

[1,2,3] is also the maximum clique -- that is, the largest clique in the graph.

Task

Write a function that finds the maximum clique for a given adjacency matrix.

Output should be a set or a list of the nodes of the clique.

Notes

The graph may contain several maximum cliques. Return any one of them.
The graph will always be undirected.
The graph may be disconnected.
Order does not matter (You may also return a set).
Also note that the graph might contain self-loops, and the inclusion of self-loops has nothing to do with criteria of cliqueness.

Performance

Consider the performance of your code. Input matrix size will be n*n where 0 <= n <= 100.

Random Tests Setup

Each randomly generated graph G(n, p) is characterized by two parameters: n is the number of vertices, p is the probability of an edge between any two vertices.

90 tests with 4 <= n <= 8 and 0.2 <= p <= 0.8.

90 tests with 8 <= n <= 16 and 0.2 <= p <= 0.8.

90 tests with 30 <= n <= 40 and 0.2 <= p <= 0.8.

90 tests with 40 <= n <= 100 and p = 0.5.

90 tests with 40 <= n <= 100, p = 0.5 and randomly selected large cliques (a subset of vertices is selected and all vertices in the subset are connected with edges).

