#include <string>
#include <vector>
#include <iostream>
/*

*/
using namespace std;
int UNIT_PER_LENGTH(string s, int unit) {
	int i, j, count;
	string temp = "";
	string temp2 = "";
	for (i = 0; i < s.length(); i = j) {
		temp = s.substr(i, unit);
		count = 1;
		for (j = i + unit; j + unit <= s.length() && temp.compare(s.substr(j,unit)) == 0; j += unit, count++);
		count > 1 ? temp2 += to_string(count) + temp : temp2 += s.substr(i, j - i);
	}
	return temp2.length();
}

int solution(string s) {
	int answer = 0;
	int unit, min = 1001;
	
	for (unit = 1; unit <= s.length() / 2 + 1; unit++) {
		answer = UNIT_PER_LENGTH(s, unit);
		if (min > answer) min = answer;
	}
	return min;
}

int main() {
	string s = "aabbaccc";
	string s1 = "ababcdcdababcdcd";
	string s2 = ""
	cout << solution(s1);
}