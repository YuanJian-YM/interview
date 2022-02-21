//
// Created by bytedance on 2021/8/29.
//
#include <iostream>
#include <queue>
#include <stack>
#include "../include//graph.h"

Graph::Graph() {
}


//Graph graph = Graph();
//std::vector<std::vector<int>> data{{1, 1, 0, 1, 0},
//                                   {1, 1, 1, 0, 1},
//                                   {0, 1, 1, 0, 0},
//                                   {1, 0, 0, 1, 0},
//                                   {0, 1, 0, 0, 1}};
// graph.BFS(data, 4);
void Graph::BFS(std::vector<std::vector<int>> &input, int start) {
    int size = input.size();
    if (start > size) {
        return;
    }
    std::vector<int> visit(size, 0);
    std::queue<Node> queue;
    queue.push(Node(start, start));
    while (!queue.empty()) {
        Node element = queue.front();
        queue.pop();
        std::cout << element.x << std::endl;
        visit[element.x] = 1;
        for (int i = 0; i < size; ++i) {
            if (input[element.x][i] != 0 && visit[i] == 0) {
                queue.push(Node(i, i));
            }
        }
    }
}

//Graph graph = Graph();
//std::vector<std::vector<int>> data{{1, 1, 0, 1, 0},
//                                   {1, 1, 1, 0, 1},
//                                   {0, 1, 1, 0, 0},
//                                   {1, 0, 0, 1, 0},
//                                   {0, 1, 0, 0, 1}};
//graph.DFS(data, 4);
void Graph::DFS(std::vector<std::vector<int>> &input, int start) {
    int size = input.size();
    if (start > size) {
        return;
    }
    std::vector<int> visit(size, 0);
    std::stack<Node> path;
    path.push(Node(start, start));
    while (!path.empty()) {
        Node element = path.top();
        std::cout << element.x << std::endl;
        visit[element.x] = 1;
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (input[element.x][i] != 0 && visit[i] != 1) {
                found = true;
                path.push(Node(i, i));
                break;
            }
        }
        if (!found) {
            path.pop();
        }
        // 可添加visit全部为1提前终止遍历
    }
}
