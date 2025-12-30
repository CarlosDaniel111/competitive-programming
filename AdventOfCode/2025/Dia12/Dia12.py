def main(lines):
    shape_areas = {}
    current_shape_idx = 0
    valid_regions = 0

    for line in lines:
        if line.strip().endswith(":"):
            current_shape_idx = int(line[:-1])
            shape_areas[current_shape_idx] = 0

        elif "#" in line:
            shape_areas[current_shape_idx] += line.count("#")

        elif "x" in line:
            raw_dims, raw_counts = line.split(":")
            width, height = map(int, raw_dims.split("x"))
            counts = map(int, raw_counts.split())

            presents_area = sum(count * shape_areas[i] for i, count in enumerate(counts))

            if presents_area <= width * height:
                valid_regions += 1

    return valid_regions

FILE = "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/AdventofCode/2025/Dia12/input.txt"
print(main(open(FILE).read().splitlines()))