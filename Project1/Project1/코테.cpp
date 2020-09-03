#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
/*
�ȷ� �ڵ��׽�Ʈ ���� 1
�װ��� ���ǿ� �����ϴ� ���ڿ��� �Ÿ��� �����Դϴ�.
���ǿ� �ϳ��� �����ϰԵǸ� 0, ���� �װ����� ��� �������� ������ 1�� �־���մϴ�.

����1 - ������ 4������ ������ �ȵ˴ϴ�.
����2 - ������ 4������ ������ �ȵ˴ϴ�.
����3 - �������� ���� ���ĺ��� ������ �ȵ˴ϴ�.
����4 - ���ĺ��� 4��°���� �����ϸ� �ȵ˴ϴ�.
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