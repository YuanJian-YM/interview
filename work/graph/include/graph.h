//
// Created by bytedance on 2021/8/29.
//

#ifndef WORK_GRAPH_H
#define WORK_GRAPH_H

#include <vector>

struct Node {
    int x, y;

    Node(int x, int y) : x(x), y(y) {};
};

struct Edge {
    int src, target;
    unsigned int value;
    Edge(int src, int target, unsigned int value) : src(src), target(target), value(value) {};
};

class Graph {
public:
    Graph();

public:
    void BFS(std::vector<std::vector<int>> &input, int start);

    void DFS(std::vector<std::vector<int>> &input, int start);

    void Dijkstra(std::vector<std::vector<unsigned int>> &input, int start, int end);
};

#endif //WORK_GRAPH_H
