from typing import List
import z3

FILE = "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/AdventofCode/2025/Dia10/input.txt"

def read_lines_to_list() -> List[str]:
    lines: List[str] = []
    with open(FILE, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            lines.append(line)

    return lines


def parse_lines(lines):
    machines = []

    for line in lines:
        split = line.split(" ")
        indicator = split[0][1:-1]
        schematics = []

        for s in split[1:-1]:
            if s.startswith("("):
                inner = s[1:-1]
                inner = inner.split(",")

                schematics.append([int(x) for x in inner])

        joltage = [int(x) for x in split[-1][1:-1].split(",")]

        machines.append((indicator, schematics, joltage))

    return machines


def main():
    lines = read_lines_to_list()
    answer = 0

    machines = parse_lines(lines)

    for machine in machines:
        (_, buttons, joltages) = machine

        bs = [z3.Int(f"b{i}") for i in range(len(buttons))]
        optimizer = z3.Optimize()

        optimizer.add(
            [
                z3.Sum(bs[b] for b, button in enumerate(buttons) if j in button)
                == joltage
                for (j, joltage) in enumerate(joltages)
            ]
        )
        optimizer.add([b >= 0 for b in bs])

        optimizer.minimize(z3.Sum(bs))
        assert optimizer.check() == z3.sat
        model = optimizer.model()

        answer += sum(model[b].as_long() for b in bs)

    print(answer)

if __name__ == '__main__':
    main()
