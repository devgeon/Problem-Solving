# BOJ-02839 / 설탕 배달
# devgeon, 2023.01.14, Python3
# https://www.acmicpc.net/problem/2839


class sugar_bags():
    def __init__(self, weight, bags):
        self.weight = weight
        self.bags = bags
        self.counter = dict(zip(self.bags, [0]*len(self.bags)))

    def fill(self, bag, num=1):
        if num == 0:
            num = self.weight // bag
        self.weight -= bag * num
        self.counter[bag] += num

    def empty(self, bag, num=1):
        if num == 0:
            num = self.weight // bag
        self.weight += bag * num
        self.counter[bag] -= num

    def get_weight(self):
        return self.weight

    def get_counter(self):
        return self.counter

    def get_num_of_bags(self):
        return sum(self.counter.values())


def main():
    target_value = int(input())
    
    bags = sugar_bags(target_value, (3, 5))
    bags.fill(5, 0)
    bags.fill(3, 0)

    while bags.get_counter()[5] > 0:
        if bags.get_weight() == 0:
            break
        bags.empty(5)
        bags.fill(3, 0)

    if bags.get_weight() != 0:
        print(-1)
    else:
        print(bags.get_num_of_bags())

if __name__ == "__main__":
    main()
