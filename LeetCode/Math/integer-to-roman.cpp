#include <string>
using std::string;
// Runtime: 28 ms
class Solution {
public:
	// // Runtime: 40 ms
	string intToRoman(int num) {
		string M[] = { "", "M", "MM", "MMM" };
		string C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		string X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		string I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
	}

	// Runtime: 68 ms
	string intToRoman1(int num) {
		int weights[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string tokens[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string ret = "";
		int start = 0;
		while (num>0) {
			for (int i = start; i < 13; i++){
				if (num >= weights[i]){
					num -= weights[i];
					ret += tokens[i];
					break;
				}
				start = i + 1; // skip those impossible check, make it faster
			}
		}
		return ret;
	}

	string intToRoman2(int num) {
		string ret = "";
		if (num >= 1000) {
			ret += string(num / 1000, 'M');
			num = num % 1000;
		}
		if (num >= 900) {
			ret += "CM";
			num -= 900;
		}
		if (num >= 500) {
			ret += 'D';
			num -= 500;
		}
		if (num >= 400) {
			ret += "CD";
			num -= 400;
		}
		if (num >= 100) {
			ret += string(num / 100, 'C');
			num = num % 100;
		}
		if (num >= 90) {
			ret += "XC";
			num -= 90;
		}
		if (num >= 50) {
			ret += 'L';
			num -= 50;
		}
		if (num >= 40) {
			ret += "XL";
			num -= 40;
		}
		if (num >= 10) {
			ret += string(num / 10, 'X');
			num %= 10;
		}
		if (num >= 9) {
			ret += "IX";
			num -= 9;
		}
		if (num >= 5) {
			ret += 'V';
			num -= 5;
		}
		if (num >= 4) {
			ret += "IV";
			num -= 4;
		}
		if (num > 0) {
			ret += string(num, 'I');
		}
		return ret;
	}
};