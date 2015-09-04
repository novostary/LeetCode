#include <stack>
#include <algorithm>
using std::stack;
using std::min;
// https://leetcode.com/discuss/15679/share-my-java-solution-with-only-one-stack
// https://leetcode.com/discuss/48825/accepted-104ms-c-solution-with-maxqueue max queue
class MinStack { // Runtime: 32 ms
public:
	void push(int x) {
		s.push(x);
		if (smin.empty()) {
			smin.push(x);
		}
		else {
			// smin.push(min(smin.top(), x));
			if (x <= smin.top()) {
				smin.push(x);
			}
		}
	}

	void pop() {
		if (!s.empty()) {
			// smin.pop();
			if (s.top() == smin.top()) {
				smin.pop();
			}
			s.pop();
		}
	}

	int top() {
		if (s.empty()) {
			return 0;
		}
		return s.top();
	}

	int getMin() {
		if (smin.empty()) {
			return 0;
		}
		return smin.top();
	}
private:
	stack<int> s;
	stack<int> smin;
};
class MinStackWithOneStack {// Runtime: 28 ms
public:
	void push(int x) {
		if (s.empty()) {
			smin = x;
			s.push(0ll);
		}
		else {
			s.push(x - smin);
			if (x < smin) {
				smin = x;
			}
		}
	}

	void pop() {
		if (!s.empty()) {
			if (s.top() < 0) {
				smin = smin - s.top();
			}
			s.pop();
		}
	}

	int top() {
		if (s.empty()) {
			return 0;
		}

		if (s.top() < 0) {
			return smin;
		}
		else {
			return s.top() + smin;
		}
	}

	int getMin() {
		if (s.empty()) {
			return 0;
		}
		return smin;
	}
private:
	stack<long long> s;
	long long smin;
};