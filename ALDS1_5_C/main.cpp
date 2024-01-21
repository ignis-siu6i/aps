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
	if (from == to) {
		return;
	}
	Point firstP = start.getKochFirstPoint(end);
	Point thirdP = start.getKochThirdPoint(end);
	Point secondP = getKochSecondPoint(firstP, thirdP);

	cout << firstP.x << " " << firstP.y << endl;
		solve(firstP, secondP, from + 1, to);
		cout << secondP.x << " " << secondP.y << endl;
		solve(secondP, thirdP, from + 1, to);
	cout << thirdP.x << " " << thirdP.y << endl;
}

int main(void)
{
	int n;

	cin >> n;

	Point p1 = Point(0, 0);
	Point p2 = Point(100, 0);
	
	cout << p1.x << " " << p1.y << endl;
	solve(p1, p2, 0, 1);
	cout << p2.x << " " << p2.y << endl;

	return 0;
}