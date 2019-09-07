#include<bits/stdc++.h>
using namespace std;
struct Point {
	int x;
	int y;
	int a;
	int b;
	Point(int x, int y, int a, int b) {
		this->x = x;
		this->y = y;
		this->a = a;
		this->b = b;
	}
	Point() {}
};
Point rotate(Point p, int times) {
	int x = p.x;
	int y = p.y;
	int a = p.a;
	int b = p.b;
	int xx, yy;
	for (int i = 0; i < times; i++) {
		xx = a - y + b;
		yy = x - a + b;
		x = xx;
		y = yy;
	}
	return Point(x, y, a, b);
}
bool cmp(Point p1, Point p2) {
	if (p1.x != p2.x) {
		return p1.x < p2.x;
	}
	return p1.y < p2.y;
}
bool isRightAngle(Point p1, Point p2, Point p3) {
	int x = (p1.x - p2.x)*(p1.x - p3.x) + (p1.y - p2.y)*(p1.y - p3.y);
	if (x == 0) {
		return true;
	}
	return false;
}
int distance(Point p1, Point p2) {
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
bool isSquare(Point p1,Point p2,Point p3,Point p4) {
	vector<Point> points(4);
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	sort(points.begin(), points.end(), cmp);
	int s1 = distance(points[0],points[1]);
	int s2 = distance(points[0], points[2]);
	int s3 = distance(points[1], points[3]);
	int s4 = distance(points[2], points[3]);
	if (s1 == s2 && s2 == s3 && s3 == s4 && s1 != 0 && isRightAngle(points[0], points[1], points[2])) {
		return true;
	}
	else {
		return false;
	}
}


int main() 
{
	int N; cin >> N;
	vector<Point> nums(4);
	
	for (int index = 0; index < N; index++) {
		for (int i = 0; i < 4; i++) {
			cin >> nums[i].x >> nums[i].y >> nums[i].a >> nums[i].b;
		}
		int count = 0x3f3f3f3f;
		for (int m = 0; m < 4; m++) {
			for (int n = 0; n < 4; n++) {
				for (int p = 0; p < 4; p++) {
					for (int q = 0; q < 4; q++) {
						if (isSquare(rotate(nums[0], m), rotate(nums[1], n), rotate(nums[2], p), rotate(nums[3], q))) {
							count = min(count, m + n + p + q);
						}
					}
				}
			}
		}
		count = count == 0x3f3f3f3f ? -1 : count;
		cout << count << endl;
	}
	return 0;
}
