#define ROOT_3 (1.73205081)

#include <iostream>

using namespace std;

struct Point {
	double x;
	double y;
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	Point getKochFirstPoint(Point p2) {
		return Point((x + p2.x) / 3, (y + p2.y) / 3);
	}

	Point getKochThirdPoint(Point p2) {
		return Point((x + p2.x) / 3 * 2, (y + p2.y) / 3 * 2);
	}
};

Point getKochSecondPoint(Point kFirstP, Point kThirdP) {
	Point mP = Point(kThirdP.x - kFirstP.x, kThirdP.y - kFirstP.y);
	Point rP = Point(mP.x / 2 - mP.y * ROOT_3 / 2, mP.x * ROOT_3 / 2 + mP.y / 2);
	return Point(kFirstP.x + rP.x, kFirstP.y + rP.y);
}

void solve(Point start, Point end, int from, int to) {
	cout << start.x << " " << start.y << endl;

	Point firstP = start.getKochFirstPoint(end);
	Point thirdP = start.getKochThirdPoint(end);
	Point secondP = getKochSecondPoint(firstP, thirdP);

	cout << end.x << " " << end.y << endl;
}

int main(void)
{
	int n;

	cin >> n;

	Point p1 = Point(0, 0);
	Point p2 = Point(100, 0);
	Point pFirst = p1.getKochFirstPoint(p2);
	Point pThird = p1.getKochThirdPoint(p2);
	Point pSecond = getKochSecondPoint(pFirst, pThird);
	cout << pFirst.x << ", " << pFirst.y << " " << pSecond.x << ", " << pSecond.y << " " << pThird.x << ", " << pThird.y << endl;

	return 0;
}