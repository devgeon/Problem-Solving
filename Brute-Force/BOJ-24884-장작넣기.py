# BOJ-24884 / 장작 넣기
# devgeon, 2024.01.13, Python3
# https://www.acmicpc.net/problem/24884


from copy import deepcopy


def play(status, k, timeout):
    count = 0
    status["time"] += 1

    # 화력 감소
    reduction = [-3] * len(status["heat"])
    for i, heat in enumerate(status["heat"]):
        if heat <= 0 or (status["time"] > 1 and i == status["pos"]):
            reduction[i] = 0
            continue
        if i > 0 and status["heat"][i - 1] > 0:
            reduction[i] += 1
        if i < len(status["heat"]) - 1 and status["heat"][i + 1] > 0:
            reduction[i] += 1
    for i, r in enumerate(reduction):
        status["heat"][i] += r
    status["min"] = min(status["min"], len([None for x in status["heat"] if x > 0]))

    # 놀이 종료
    if status["time"] == timeout:
        if status["min"] >= k:
            return 1
        return 0

    # 장작 추가
    for d in [-1, 0, 1]:
        if 0 <= status["pos"] + d and status["pos"] + d < len(status["heat"]):
            new_status = deepcopy(status)
            new_status["pos"] += d
            count += play(new_status, k, timeout)
    return count


def main():
    num, pos, timeout, k = [int(x) for x in input().split()]
    heat = [int(x) for x in input().split()]
    status = {
        "pos": pos,
        "time": 0,
        "min": num - heat.count(0),
        "heat": heat,
    }

    print(play(status, k, timeout))


if __name__ == "__main__":
    main()
