#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
/*
안랩 코딩테스트 문제 1
네가지 조건에 부합하는 문자열을 거르는 문제입니다.
조건에 하나라도 만족하게되면 0, 조건 네가지에 모두 만족하지 않으면 1을 넣어야합니다.

조건1 - 모음이 4번연속 나오면 안됩니다.
조건2 - 자음이 4번연속 나오면 안됩니다.
조건3 - 세번연속 같은 알파벳이 나오면 안됩니다.
조건4 - 알파벳이 4번째동안 연속하면 안됩니다.
*/
bool Condition1(string s) {
	int i, c1 = 0, c2 = 0;
	for (i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			c1++; c2 = 0;
		}
		else {
			c2++; c1 = 0;
		}
		if (c1 >= 4 || c2 >= 4) return false;
	}
	return true;
}
bool Condition2(string s) {
	int i;
	for (i = 0; i < s.length() - 2; i++)
		if (s[i] == s[i + 1] && s[i] == s[i + 2]) return false;
	return true;
}
bool Condition3(string s) {
	int i;
	for (i = 0; i < s.length() - 3; i++)
		if (abs(s[i + 3] - s[i]) == 3 && s[i] + s[i + 3] == s[i + 1] + s[i + 2]) return false;
	return true;
}
vector<int> solution(vector<string> words) {
	vector<int> answer;
	int i, j;
	for (i = 0; i < words.size(); i++)
		answer.push_back(Condition1(words[i]) && Condition2(words[i]) && Condition3(words[i]));

	return answer;
}
int main() {
	vector<string> arr = {"aeiou", "iaboe","xxabcd","qwertyuiop" };
	vector<int> a = solution(arr);
	for (int i = 0; i < a.size(); i++) cout << a[i] << "";
	
}