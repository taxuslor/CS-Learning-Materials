# CS106B: Graphs

## Graph

- A structured way to represent relationships between different entities.

- A graph consists of a set of nodes connected by edges.

- Two nodes are **neighbors** if they are directly connected by an edge.
- A **path** between two nodes is defined be a sequence of edges that can be followed to traverse between the two nodes.
- The **length** of a path is the number of edges that make up the path.
- A **cycle** is a path that begins and ends at the same node.
- A **loop** is an edge directly from a node back to itself.
- A node is **reachable** from another node if a path exists between the two nodes.
- A graph is **connected** if all nodes are reachable from all other nodes.
- A graph is **complete** if every node has an edge connecting it to every other node.

## Dijkstra's Algorithm

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max(); // 无穷大值

// 图的邻接矩阵表示
class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    Graph(int numVertices) : numVertices(numVertices) {
        adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, INF));
    }

    void addEdge(int src, int dest, int weight) {
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight;
    }

    // Dijkstra算法
    std::vector<int> dijkstra(int startVertex) {
        std::vector<bool> visited(numVertices, false); // 记录顶点是否已访问
        std::vector<int> distances(numVertices, INF); // 记录起始顶点到其他顶点的最短距离

        distances[startVertex] = 0; // 起始顶点到自身的距离为0

        for (int i = 0; i < numVertices - 1; ++i) {
            int minDistanceVertex = -1;
            int minDistance = INF;

            // 找到当前未访问的顶点中距离起始顶点最近的顶点
            for (int j = 0; j < numVertices; ++j) {
                if (!visited[j] && distances[j] < minDistance) {
                    minDistance = distances[j];
                    minDistanceVertex = j;
                }
            }

            visited[minDistanceVertex] = true;

            // 更新最短距离
            for (int j = 0; j < numVertices; ++j) {
                if (!visited[j] && adjacencyMatrix[minDistanceVertex][j] != INF &&
                    distances[minDistanceVertex] != INF &&
                    distances[minDistanceVertex] + adjacencyMatrix[minDistanceVertex][j] < distances[j]) {
                    distances[j] = distances[minDistanceVertex] + adjacencyMatrix[minDistanceVertex][j];
                }
            }
        }

        return distances;
    }
};

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    // 添加边
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 1, 2);
    graph.addEdge(2, 3, 5);
    graph.addEdge(3, 4, 3);
    graph.addEdge(4, 1, 3);
    graph.addEdge(4, 0, 2);
    graph.addEdge(4, 5, 6);

    std::vector<int> distances = graph.dijkstra(0);

    // 输出最短距离
    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < numVertices; i++) {
        std::cout << i << "\t" << distances[i] << "\n";
    }

    return 0;
}
```

## A* Search

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// 定义节点结构体
struct Node {
    int x;  // 节点的横坐标
    int y;  // 节点的纵坐标
    int g;  // 从起始节点到当前节点的实际路径长度
    int h;  // 从当前节点到目标节点的估计路径长度
    int f;  // f = g + h
};

// 定义比较函数，用于优先队列的排序
struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.f > b.f;
    }
};

// 判断节点是否在地图范围内
bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// 判断节点是否是障碍物
bool isObstacle(int x, int y, vector<vector<int>>& grid) {
    return (grid[x][y] == 1);
}

// 计算两个节点之间的曼哈顿距离
int calculateManhattanDistance(const Node& a, const Node& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// A*搜索算法实现
vector<Node> AStarSearch(vector<vector<int>>& grid, Node& start, Node& end) {
    int rows = grid.size();
    int cols = grid[0].size();

    // 定义移动方向（上、下、左、右）
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // 定义访问数组，用于标记节点是否已被访问过
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // 定义父节点数组，用于记录路径
    vector<vector<Node>> parent(rows, vector<Node>(cols));

    // 定义优先队列，用于选择f值最小的节点进行扩展
    priority_queue<Node, vector<Node>, CompareNode> pq;

    // 初始化起始节点
    start.g = 0;
    start.h = calculateManhattanDistance(start, end);
    start.f = start.g + start.h;
    pq.push(start);
    visited[start.x][start.y] = true;

    // 开始搜索
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        // 到达目标节点，搜索结束
        if (current.x == end.x && current.y == end.y) {
            break;
        }

        // 扩展当前节点的邻居节点
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // 邻居节点不在地图范围内或者是障碍物，则跳过
            if (!isValid(nx, ny, rows, cols) || isObstacle(nx, ny, grid)) {
                continue;
            }

            // 计算邻居节点的g值、h值和f值
            int ng = current.g + 1;
            int nh = calculateManhattanDistance(Node{nx, ny}, end);
            int nf = ng + nh;

            // 如果邻居节点已被访问过且新路径的f值不小于原路径的f值，则跳过
            if (visited[nx][ny] && nf >= parent[nx][ny].f) {
                continue;
            }

            // 更新邻居节点的父节点和f值，并加入优先队列
            parent[nx][ny] = current;
            visited[nx][ny] = true;
            pq.push(Node{nx, ny, ng, nh, nf});
        }
    }

    // 回溯路径
    vector<Node> path;
    Node current = end;
    while (!(current.x == start.x && current.y == start.y)) {
        path.push_back(current);
        current = parent[current.x][current.y];
    }
    path.push_back(start);

    // 反转路径，使其从起始节点到目标节点
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    // 定义地图
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // 定义起始节点和目标节点
    Node start = {0, 0};
    Node end = {4, 4};

    // 调用A*搜索算法
    vector<Node> path = AStarSearch(grid, start, end);

    // 打印路径
    for (const auto& node : path) {
        cout << "(" << node.x << ", " << node.y << ")" << endl;
    }

    return 0;
}
```

