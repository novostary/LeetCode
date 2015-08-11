#include <vector>
#include <set>
using std::vector;
using std::set;
// 20 ms
// Best: 16 ms??
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		set<int> s;
		for (auto num : nums) {
			if (s.find(num) == s.end()) {
				s.insert(num);
			}
			else {
				s.erase(num);
			}
		}
		return *(s.begin());
	}
	// int singleNumber(vector<int>& nums) {
	//     unordered_map<int, int> m;
	//     for (auto num: nums) {
	//         // could not convert ¡®m.std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::find<int, int, std::hash<int>, std::equal_to<int>, std::allocator<std::pair<const int, int> > >((*(const key_type*)(& num)))¡¯ from ¡®std::unordered_map<int, int>::iterator {aka std::__detail::_Node_iterator<std::pair<const int, int>, false, false>}¡¯ to ¡®bool¡¯
	//         if (m.find(num) != m.end()) {
	//             m.erase(num);
	//         } else {
	//             m[num] = num;
	//         }
	//     }
	//     // return (*(m.begin()).first);
	//     return m.begin()->first;
	// }
	// int singleNumber(vector<int>& nums) {
	//     int ret = 0;
	//     for (auto num: nums) {
	//         ret ^= num;
	//     }
	//     return ret;
	// }
};