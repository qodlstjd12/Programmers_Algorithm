#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
� ������ �� ���ĺ��� ������ �Ÿ���ŭ �о �ٸ� ���ĺ����� �ٲٴ� ��ȣȭ ����� ���� ��ȣ��� �մϴ�. 
���� ��� AB�� 1��ŭ �и� BC�� �ǰ�, 3��ŭ �и� DE�� �˴ϴ�. z�� 1��ŭ �и� a�� �˴ϴ�. 
���ڿ� s�� �Ÿ� n�� �Է¹޾� s�� n��ŭ �� ��ȣ���� ����� �Լ�, solution�� �ϼ��� ������.

���� ����
������ �ƹ��� �о �����Դϴ�.
s�� ���ĺ� �ҹ���, �빮��, �������θ� �̷���� �ֽ��ϴ�.
s�� ���̴� 8000�����Դϴ�.
n�� 1 �̻�, 25������ �ڿ����Դϴ�.
*/
string solution(string s, int n) {
	int i;
	for (i = 0; i < s.length(); i++) {
		if (s.at(i) == ' ') continue;
		s.at(i) >= 'a' ? s.at(i) + n > 'z' ? s.at(i) += n - 26 : s.at(i) += n 
			: s.at(i) + n > 'Z' ? s.at(i) += n - 26 : s.at(i) += n;
	}
	return s;
}
int main()
{
	string s = "a B z";
	string a = solution(s, 4);
	cout << a;
}