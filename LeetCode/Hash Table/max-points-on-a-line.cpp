#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using std::vector;
using std::max;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::map;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
	int maxPoints(vector<Point>& points) { // Runtime: 28 ms
		if (points.size() < 3) {
			return points.size();
		}
		int res = 0;
		int size = points.size();
		bool checked[size] = { false }; // Runtime: 20 ms
		for (int i = 0; i < size - 1; ++i) {
			if (checked[i]) {
				continue;
			}
			int numVertical = 1, local = 0, duplicate = 0;
			unordered_map<double, int> map;
			for (int j = i + 1; j < size; ++j) {
				int dx = points[i].x - points[j].x, dy = points[i].y - points[j].y;
				if (!dx && !dy) {
					++duplicate;
					checked[j] = true;
					continue;
				}
				else if (!dx) {
					++numVertical;
				}
				else {
					double slope = dy * 1.0 / dx;
					++map[slope];
					local = max(local, map[slope]);
				}
			}
			local = max(local + 1, numVertical) + duplicate;
			res = max(res, local);
		}
		return res;
	}

	int maxPoints2(vector<Point>& points) { // Runtime: 28 ms
		if (points.size() <= 2) {
			return points.size();
		}
		int res = 0;
		const int size = points.size();
		for (int i = 0; i < size - 1; ++i) {
			int numVertical = 1, local = 0, duplicate = 0;
			unordered_map<double, int> map;
			for (int j = i + 1; j < size; ++j) {
				if (points[i].x == points[j].x) {
					if (points[i].y == points[j].y) {
						++duplicate;
					}
					else {
						++numVertical;
					}
				}
				else {
					double slope = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);
					++map[slope];
					local = max(local, map[slope]);
				}
			}
			local = max(local + duplicate + 1, numVertical + duplicate);
			res = max(res, local);
		}
		return res;
	}
	int maxPoints3(vector<Point>& points) { // Runtime: 36 ms
	    if (points.size() <= 2) {
	        return points.size();
	    }
	    int res = 0;
	    for (int i = 0; i < points.size(); ++i) {
	        map<pair<int, int>, int> lines;
	        // unordered_map<pair<int, int>, int> lines;
	        // required from ¡®struct std::__and_<std::__is_fast_hash<std::hash<std::pair<int, int> > >, std::__detail::__is_noexcept_hash<std::pair<int, int>, std::hash<std::pair<int, int> > > >¡¯
	        int localmax = 0, overlap = 0, vertical = 0;
	        for (int j = i + 1; j < points.size(); ++j) {
	            if (points[i].x == points[j].x) {
	                if (points[i].y == points[j].y) {
	                    ++overlap;
	                } else {
	                    ++vertical;
	                }
	            } else {
	                int a = points[i].x - points[j].x, b = points[i].y - points[j].y;
	                int gcd = GCD(a, b);
	                a /= gcd;
	                b /= gcd;
	                ++lines[make_pair(a, b)];
	                localmax = max(lines[make_pair(a, b)], localmax);
	            }
	        }
	        localmax = max(vertical, localmax);
	        res = max(res, localmax + overlap + 1);
	    }
	    return res;
	}

private:
	int GCD(int a, int b) {
	    if (b == 0) {
	        return a;
	    } else {
	        return GCD(b, a % b);
	    }
	}
	 
};