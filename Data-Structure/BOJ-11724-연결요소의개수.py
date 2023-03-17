# BOJ-11724 / 연결 요소의 개수
# devgeon, 2023.03.17, Python3
# https://www.acmicpc.net/problem/11724

import sys

def read_graph_line():
    return [int(x) for x in sys.stdin.readline().rstrip().split(" ")]

def find_point(graphs, point):
    for i in range(len(graphs)):
        if point in graphs[i]:
            return i + 1
    return -1

def main():
    points = set()
    graphs = []
    num_point, num_line = read_graph_line()

    for i in range(num_line):
        point_a, point_b = read_graph_line()
        points.update([point_a, point_b])
        graph_point_a = find_point(graphs, point_a)
        graph_point_b = find_point(graphs, point_b)
        if graph_point_a > graph_point_b:
            point_a, point_b = point_b, point_a
            graph_point_a, graph_point_b = graph_point_b, graph_point_a

        if graph_point_a == -1 and graph_point_b == -1:
            graphs.append(set([point_a, point_b]))
        elif graph_point_a == graph_point_b:
            continue
        elif graph_point_a * graph_point_b < 0:
            graphs[graph_point_b - 1].add(point_a)
        elif graph_point_a * graph_point_b > 0:
            new_graph = graphs[graph_point_a - 1].union(graphs[graph_point_b - 1])
            graphs.append(new_graph)
            del graphs[graph_point_b - 1]
            del graphs[graph_point_a - 1]

    print(len(graphs) + num_point - len(points))

if __name__ == "__main__":
    main()
