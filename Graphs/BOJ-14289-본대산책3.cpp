// BOJ-14289 / 본대 산책 3
// devgeon, 2024.05.10, C++17
// https://www.acmicpc.net/problem/14289

#include <iostream>
#include <vector>

using namespace std;

using matrix_row = vector<int>;
using matrix = vector<matrix_row>;

const int DIVISOR = 1'000'000'007;

matrix mul_matrix(const matrix &graph_a, const matrix &graph_b,
                  const int divisor = DIVISOR);

matrix pow_matrix(matrix graph, const int exponent);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertex = 0, edge = 0, length = 0;
    cin >> vertex >> edge;
    matrix graph(vertex, matrix_row(vertex, 0));
    matrix result;

    for (int i = 0, a = 0, b = 0; i < edge; i++) {
        cin >> a >> b;
        a--, b--;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    cin >> length;

    result = pow_matrix(graph, length);
    cout << result[0][0] << endl;

    return 0;
}

matrix mul_matrix(const matrix &graph_a, const matrix &graph_b,
                  const int divisor) {
    matrix result = matrix(graph_a.size(), matrix_row(graph_b[0].size(), 0));

    for (int k = 0; k < graph_b.size(); k++) {
        for (int r = 0; r < graph_a.size(); r++) {
            for (int c = 0; c < graph_b[0].size(); c++) {
                result[r][c] =
                    (result[r][c] + (long long)graph_a[r][k] * graph_b[k][c]) %
                    divisor;
            }
        }
    }

    return result;
}

matrix pow_matrix(matrix graph, int exponent) {
    if (exponent == 0) {
        return matrix(graph.size(), matrix_row(graph.size(), 1));
    } else if (exponent < 0) {
        return matrix();
    }

    matrix result = matrix(graph.size(), matrix_row(graph.size(), 0));
    for (int i = 0; i < graph.size(); i++) {
        result[i][i] = 1;
    }

    while (exponent > 0) {
        if (exponent & 1) {
            result = mul_matrix(result, graph);
        }
        graph = mul_matrix(graph, graph);
        exponent >>= 1;
    }

    return result;
}
