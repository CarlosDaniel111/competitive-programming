import shapely
from shapely import Polygon

def calc_area(a,b):
    c = abs(b[0]-a[0])+1
    d = abs(b[1]-a[1])+1
    return c*d

def main() -> None:
    pts = []
    path = '/Users/CarlosBeltran/Documents/ICPC/competitive-programming/AdventofCode/2025/Dia9/input.txt'
    with open(path, 'r') as file:
        for row in file:
            row = list(str(row.replace('\n', '')).split(','))
            row = [ int(i) for i in row ]
            pts.append(row)

    area_full = Polygon(pts)
    max_area = 0
    for i in range(len(pts)):
        pt1 = pts[i]
        for j in range(i+1,len(pts)):
            pt2 = pts[j]
            area_partly = Polygon([(pt1[0],pt2[1]), (pt2[0], pt2[1]), (pt2[0],pt1[1]), (pt1[0],pt1[1]) ])
            if shapely.within(area_partly,area_full):
                temp = calc_area(pt1, pt2)
                if max_area < temp:
                    max_area = temp
    print(max_area)
    

if __name__ == '__main__':
    main()