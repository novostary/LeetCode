#include <iostream>
using namespace std;

class Solution {
private:
	static Solution* m_instance;
	Solution() {}

public:
	/**
	* @return: The same instance of this class every time
	*/
	static Solution* getInstance() {
		// write your code here
		if (m_instance == NULL) {
			m_instance = new Solution();
		}
		return m_instance;
	}
};

Solution* Solution::m_instance = NULL;

int main() {
	Solution* a = Solution::getInstance();
	Solution* b = Solution::getInstance();

	cout << (a == b) << endl;
	return 0;
}