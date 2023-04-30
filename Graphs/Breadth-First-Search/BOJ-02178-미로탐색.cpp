// BOJ-02178 / 미로 탐색
// devgeon, 2022.08.20, C++17
// https://www.acmicpc.net/problem/2178
 
// N×M 크기의 배열에 0은 이동할 수 없는 칸, 1은 이동할 수 있는 칸으로 미로를 나타내었다.
// 이 미로의 (1,1)에서 출발하여 (N,M)으로 이동할 때 지나야 하는 칸 수의 최솟값을 구하는 프로그램을 작성하시오.
// 칸을 셀 때에는 시작 위치와 도착 위치도 포함하며, 다른 칸으로 이동할 때 서로 인접한 칸으로만 이동할 수 있다.

// 입력: 첫째 줄에 두 정수 N,M(2 ≤ N,M ≤ 100)이 주어진다.
//      다음 N개의 줄에는 M개의 정수로 나타낸 미로가 각 숫자 사이에 공백 없이 주어진다.
//      도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
// 출력: 지나야 하는 칸 수의 최솟값을 출력한다.


#include<iostream>
#include<vector>
#include<queue>

class Pos {
    public:
        int row;
        int col;
        Pos(const int& r, const int& c) {
            row = r;
            col = c;
        }
        bool operator == (const Pos& pos) {
            if(row == pos.row && col == pos.col) {
                return true;
            } else {
                return false;
            }
        }
};

int main()
{
    std::vector<std::vector<char>> maze;
    std::queue<Pos> schedule;
    int width = 0, height = 0;
	int length = 0;
    bool isEscaped = false;
	
	std::cin >> height >> width;
    maze.reserve(height);
	for(int i=0; i<height; i++) {
        std::cin.get();
        maze[i].reserve(width);
        for(int j=0; j<width; j++) {
            maze[i].push_back((std::cin.get() == '1' ? 1 : 0));
        }
    }
    
    schedule.push(Pos(0,0));
    while(!isEscaped) {
        int row = 0, col = 0, tmp_idx = 0;
        int num = schedule.size();
        for(int i=0; i<num; i++) {
            Pos pos = schedule.front();
            schedule.pop();
            if(pos == Pos(height-1,width-1)) {
                isEscaped = true;
                break;
            }
            row = pos.row;
            col = pos.col;
            if((tmp_idx = row-1) != -1 && maze[tmp_idx][col] == 1) {
                schedule.push(Pos(tmp_idx,col));
                maze[tmp_idx][col] = 2;
            }
            if((tmp_idx = row+1) != height && maze[tmp_idx][col] == 1) {
                schedule.push(Pos(tmp_idx,col));
                maze[tmp_idx][col] = 2;
            }
            if((tmp_idx = col-1) != -1 && maze[row][tmp_idx] == 1) {
                schedule.push(Pos(row,tmp_idx));
                maze[row][tmp_idx] = 2;
            }
            if((tmp_idx = col+1) != width && maze[row][tmp_idx] == 1) {
                schedule.push(Pos(row,tmp_idx));
                maze[row][tmp_idx] = 2;
            }
            maze[pos.row][pos.col] = 0;
        }
        length++;
    }
	
	std::cout << length << std::endl;
	
    return 0;
}
