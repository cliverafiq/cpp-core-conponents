#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <algorithm>

using namespace std;

struct pos { int x, y; }; 

bool inside(const vector<string>& grid, int x, int y) {
    return x >= 0 && y >= 0
        && x < (int)grid.size()
        && y < (int)grid[0].size();
}

vector<pos> neighbors(const vector<string>& grid, pos p) {
    static int dx[4] = { 1, -1, 0, 0 };
    static int dy[4] = { 0,  0, 1, -1 };   
    vector<pos> out;
    for (int k = 0; k < 4; ++k) {
        int nx = p.x + dx[k];
        int ny = p.y + dy[k];
        if (inside(grid, nx, ny) && grid[nx][ny] != '#') {
            out.push_back({ nx, ny });
        }
    }
    return out;
}

int manhattan(pos a, pos b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    vector<string> map = {
        ".....#..",
        ".##.###.",
        ".#....#.",
        ".#.#..#.",
        ".#.#..#.",
        "......#.",
        ".###.##.",
        "..#....."
    };

    pos start{0, 0};
    pos goal{7, 7};   

    int X = (int)map.size();
    int Y = (int)map[0].size();

    const int INF = numeric_limits<int>::max() / 4;
    vector<vector<int>> g(X, vector<int>(Y, INF));
    vector<vector<pos>> parent(X, vector<pos>(Y, { -1, -1 }));
    vector<vector<bool>> closed(X, vector<bool>(Y, false));

    using State = tuple<int, int, int>;
    auto cmp = [](const State& a, const State& b) { return a > b; };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

    g[start.x][start.y] = 0;
    int f0 = manhattan(start, goal);
    pq.emplace(f0, start.x, start.y);

    bool found = false;

    while (!pq.empty()) {
        auto [f, x, y] = pq.top(); pq.pop();
        if (closed[x][y]) continue;
        closed[x][y] = true;

        if (x == goal.x && y == goal.y) { 
            found = true;
            break;
        }

        for (auto nb : neighbors(map, { x, y })) {
            if (closed[nb.x][nb.y]) continue;
            int tentative = g[x][y] + 1; 
            if (tentative < g[nb.x][nb.y]) {
                g[nb.x][nb.y] = tentative;
                parent[nb.x][nb.y] = { x, y };
                int fscore = tentative + manhattan(nb, goal);
                pq.emplace(fscore, nb.x, nb.y);
            }
        }
    }

    if (found) {
        pos cur = goal;
        while (!(cur.x == start.x && cur.y == start.y)) {
            if (!(cur.x == goal.x && cur.y == goal.y)) {
                map[cur.x][cur.y] = '*';
            }
            cur = parent[cur.x][cur.y];
        }
    } else {
        cout << "No path found.\n";
    }

    for (int x = 0; x < X; ++x) {
        for (int y = 0; y < Y; ++y) {
            if (x == start.x && y == start.y) cout << 'S'; 
            else if (x == goal.x && y == goal.y) cout << 'G';
            else cout << map[x][y];
        }
        cout << "\n";
    }

    return 0; 
}
