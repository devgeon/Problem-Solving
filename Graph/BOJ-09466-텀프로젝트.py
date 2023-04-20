# BOJ-09466 / 텀 프로젝트
# devgeon, 2023.04.20, PyPy3
# https://www.acmicpc.net/problem/9466


import sys
readline = sys.stdin.readline


def main():
    cases = int(readline())

    for _ in range(cases):
        student_count = int(readline())
        vote_result = [int(n) for n in readline().rstrip().split(" ")]
        member_count = 0

        for current, _ in enumerate(vote_result):
            team_found = -1
            pre_team = []
            while team_found < 0:
                if vote_result[current] == -1:
                    break
                if vote_result[current] == current + 1:
                    member_count += 1
                    vote_result[current] = -1
                    break

                pre_team.append(current + 1)
                try:
                    team_start = pre_team.index(vote_result[current])
                except ValueError:
                    current = vote_result[current] - 1
                else:
                    team_found = team_start

            for member in pre_team:
                vote_result[member - 1] = -1
            if team_found != -1:
                member_count += len(pre_team) - team_found

        print(student_count - member_count)


if __name__ == "__main__":
    main()
