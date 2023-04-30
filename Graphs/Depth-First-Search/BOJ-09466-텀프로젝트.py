# BOJ-09466 / 텀 프로젝트
# devgeon, 2023.04.21, PyPy3
# https://www.acmicpc.net/problem/9466


import sys
readline = sys.stdin.readline


def main():
    cases = int(readline())
    buffer = ""

    for _ in range(cases):
        student_count = int(readline())
        vote_result = [int(n) for n in readline().rstrip().split(" ")]
        member_count = 0

        for current, _ in enumerate(vote_result):
            team_found = -1
            pre_team = set()
            while team_found < 0:
                if vote_result[current] == -1:
                    break
                if vote_result[current] == current + 1:
                    member_count += 1
                    vote_result[current] = -1
                    break

                pre_team.add(current + 1)
                if vote_result[current] in pre_team:
                    team_found = current
                else:
                    current = vote_result[current] - 1

            if team_found != -1:
                member_count += 1
                back = vote_result[team_found]
                while back != team_found + 1:
                    member_count += 1
                    back = vote_result[back - 1]
            for member in pre_team:
                vote_result[member - 1] = -1

        buffer += str(student_count - member_count) + "\n"
    print(buffer, end="")


if __name__ == "__main__":
    main()
