#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
/*
1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�.
2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�. 
��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�.
3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
  3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�.
4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�.
  4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�.
  4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�.
  4-3. ')'�� �ٽ� ���Դϴ�.
  4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�.
  4-5. ������ ���ڿ��� ��ȯ�մϴ�.
*/
bool RIGHT_STRING(string p) {
	stack<char> arr;
	try {
		for (int i = 0; i < p.length(); i++) 
		{
			p[i] == '(' ? arr.push(p[i]) : (arr.empty() ? throw 1 : arr.pop());
		}
	}
	catch (int a) {
		return false;
	}
	return true;
}

bool balance(string p) {
	int c1 = 0;
	for (int i = 0; i < p.length(); i++)
		p[i] == '(' ? c1++ : c1--;
	return c1 == 0;
}
string solution(string p) {
	if (p.empty()) return "";
	string u = "", v = "";
	int i = 2;
	for (u = p.substr(0, 2); !balance(u); u = p.substr(0, i += 2));
	v = p.substr(i, p.length() - i);

	if (RIGHT_STRING(u)) return u + solution(v);
	
	string answer = "";
	for (i = 1; i < u.length() - 1; i++)
		u[i] == ')' ? answer += '(' : answer += ')';

	answer = '(' + solution(v) + ')' + answer;

	return answer;
}

int main()
{
	string s = "(()())()";
	string s1 = ")(";
	string s2 = "()))((()";
	cout << solution(s) << endl;
	cout << solution(s1) << endl;
	cout << solution(s2) << endl;
}