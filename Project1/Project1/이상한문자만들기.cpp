#include <string>
#include <iostream>
using namespace std;
/*
���� ����
���ڿ� s�� �� �� �̻��� �ܾ�� �����Ǿ� �ֽ��ϴ�. 
�� �ܾ�� �ϳ� �̻��� ���鹮�ڷ� ���еǾ� �ֽ��ϴ�. 
�� �ܾ��� ¦����° ���ĺ��� �빮�ڷ�, 
Ȧ����° ���ĺ��� �ҹ��ڷ� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���.

���� ����
���ڿ� ��ü�� ¦/Ȧ�� �ε����� �ƴ϶�, �ܾ�(������ ����)���� ¦/Ȧ�� �ε����� �Ǵ��ؾ��մϴ�.
ù ��° ���ڴ� 0��° �ε����� ���� ¦����° ���ĺ����� ó���ؾ� �մϴ�.
*/
string solution(string s) {
	int i;

	for (i = 0; i < s.length(); i++) s[i] = tolower(s[i]);

	for (i = 0; i < s.length(); i += 2) s.at(i) == ' ' ? i-- : s.at(i) -= 32;

	return s;
}
int main()
{
	string s = "tryy hello world hihi Helolo";
	string a = solution(s);	
	cout << a;
}