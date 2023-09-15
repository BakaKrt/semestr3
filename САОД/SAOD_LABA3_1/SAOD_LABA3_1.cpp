
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 8; // Размер шахматной доски
const int INF = 10000; // Максимальное количество ходов коня

class Solution {
	int start, finish;
	vector<vector<int>> dist;
	vector<vector<bool>> used;
	vector<pair<int, int>> moves = { {1, 2}, {1, -2}, {2, 1}, {2, -1},
	{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };

public:
	Solution(int start, int finish) : start(start), finish(finish) {
		dist.resize(N, vector<int>(N, INF));
		used.resize(N);
		for (int i = 0; i < N; ++i) {
			used[i].resize(N, false);
			dist[start][i] = 0;
		}
    }

    void solve() {
        vector<int> min_dist(N), prev_pos(N);

        for (int start = 0; start < N; start++) {
            int current_min_dist = INF;
            for (int pos = 0; pos < N; pos++) {
                if (!used[start][pos]) {
                    used[start][pos] = true;
                    current_min_dist = min(current_min_dist, dist[start][pos]);
                }
            }
            min_dist[start] = current_min_dist;
        }

        while (min_dist != vector<int>()) {
            vector<int> next_min_dist(min_dist);
            prev_pos = min_dist;
            min_dist.clear();

            for (int v = 0; v < N; v++) {
                for (int u = 0; u < N; u++) {
                    if (dist[v][u] == INF)
                        continue;

                    for (auto &a : moves){
                        int dx = a.first; int dy = a.second;
                        int x = u + dx, y = v + dy;
                        if (x < 0 || x >= N || y < 0 || y >= N)
                            continue; int new_dist = dist[v][u] + 1;
                        if (new_dist < dist[x][y]){
                            dist[x][y] = new_dist;
                            if (u != start && v != start)
                                min_dist[y] = INF;
                        }
                    }

                }
            }
        }

        vector<bool> visited(N);
        vector<pair<int, int>> path;
        int cur_pos = finish;

        do {
            path.emplace_back(cur_pos);
            visited[cur_pos] = true;
            cur_pos = prev_pos[cur_pos];
        } while (cur_pos != start);

        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (auto p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    for (int k = 0; k < n; ++k) {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;

        Solution sol(sx - 1, gy - 1);
        sol.solve();
    }

}


/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> start;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d %d\n", i, j);
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                start.push_back(j);
                q.push(j);
            }
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : start) {
            graph[v][to] = INF;
            for (int from = 0; from < n; ++from) {
                    graph[to][from] = min(graph[to][from], graph[v][from] + 1);
            }
            q.push(to);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << start[i] << " ";
    }
}
*/



/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 8; // Размер шахматной доски
const int INF = 100; // Максимальное количество ходов коня

class Solution {
    int start, finish;
    vector<vector<int>> dist;
    vector<vector<bool>> used;
    vector<pair<int, int>> moves = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };

public:
    Solution(int start, int finish) : start(start), finish(finish) {
        dist.resize(N, vector<int>(N, INF));
        used.resize(N);
        for (int i = 0; i < N; i++) {
            dist[start][i] = 0;
        }
    }
    void solve() {
    int u = start;
    while (true) {
        used[u].resize(N);
        for (auto& a : moves) {
            int dx = a.first; int dy = a.second;
            int x = u + dx, y = u + dy;
            if (x >= 0 && x < N && y >= 0 && y < N && dist[u][x] > dist[u][y] + 1) {
                dist[u][x] = dist[u][y] + 1;
                if (u == finish) {
                    return;
                }
            }
        }
        int v = -1;
        for (int y = 0; y < N; y++) {
            if (!used[y][u]) {
                v = y;
                break;
            }
        }
        u = v;
    }
}
};

int main() {
    Solution solver(0, 7);
    solver.solve();
    return 0;
}
*/