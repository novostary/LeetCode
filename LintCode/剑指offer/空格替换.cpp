//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//	/**
//	* @param string: An array of Char
//	* @param length: The true length of the string
//	* @return: The true length of new string
//	*/
//	int replaceBlank(char string[], int length) {
//		// Write your code here
//		int spaceNum = 0;
//		for (int i = 0; i < length; ++i) {
//			if (string[i] == ' ') {
//				++spaceNum;
//			}
//		}
//		int j = length + 2 * spaceNum;
//		for (int i = length; i >= 0 && i != j; --i) {
//			if (string[i] == ' ') {
//				string[j--] = '0';
//				string[j--] = '2';
//				string[j--] = '%';
//			}
//			else {
//				string[j--] = string[i];
//			}
//		}
//		return length + 2 * spaceNum;
//	}
//};
//
//int main() {
//	Solution s;
//	char str[100] = "Mr John Smith";
//	cout << s.replaceBlank(str, strlen(str)) << endl;
//	cout << str << endl;
//	return 0;
//}