#include <queue>
using std::queue;
// One queue is enough
// class Stack { // Runtime: 0 ms
// public:
//     // Push element x onto stack.
//     void push(int x) {
//         if (q2.empty()) {
//             q1.push(x);
//         } else {
//             q2.push(x);
//         }
//     }

//     // Removes the element on top of the stack.
//     void pop() {
//         if (!q1.empty()) {
//             int tmp = q1.front();
//             q1.pop();
//             while (!q1.empty()) {
//                 q2.push(tmp);
//                 tmp = q1.front();
//                 q1.pop();
//             }
//         } else if (!q2.empty()) {
//             int tmp = q2.front();
//             q2.pop();
//             while (!q2.empty()) {
//                 q1.push(tmp);
//                 tmp = q2.front();
//                 q2.pop();
//             }
//         }
//     }

//     // Get the top element.
//     int top() {
//         int tmp = 0;
//         if (!q1.empty()) {
//             while (!q1.empty()) {
//                 tmp = q1.front();
//                 q1.pop();
//                 q2.push(tmp);
//             }
//         } else if (!q2.empty()) {
//             while (!q2.empty()) {
//                 tmp = q2.front();
//                 q2.pop();
//                 q1.push(tmp);
//             }
//         }
//         return tmp;
//     }

//     // Return whether the stack is empty.
//     bool empty() {
//         return q1.empty() && q2.empty();
//     }
// private:
//     queue<int> q1;
//     queue<int> q2;
// };
class Stack { // Runtime: 0 ms
public:
	// Push element x onto stack.
	void push(int x) {
		q.push(x);
		int size = q.size();
		for (int i = 0; i < size - 1; i++) {
			q.push(q.front());
			q.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		if (!q.empty()) {
			q.pop();
		}
	}

	// Get the top element.
	int top() {
		if (q.empty()) {
			return 0;
		}
		else {
			return q.front();
		}
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q;
};