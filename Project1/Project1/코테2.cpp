#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
�ȷ� �ڵ��׽�Ʈ ���� 2
�Ű������� < �� > �� �̷���� ���ڿ��� pos�̶�� ��ġ�� �޽��ϴ�.

block[pos - 1]���� �����ؼ� 
'>' �� ������ �� ���Ҹ� '<'�� �ٲٰ� ��ĭ ����������,
'<' �� ������ �� ���Ҹ� '>'�� �ٲٰ� ��ĭ �������� �����Դϴ�.

�̷��� ��� �ݺ��ϴٰ� ���ڿ��� ���������µ� �� �ʰ� �ɸ������� ����ϴ� �����Դϴ�.

*/

long long solution(string block, int pos) {
	long long answer = 0;
	int i;
	for (i = pos - 1; i >= 0 && i < block.length(); answer++)
		block.at(i) == '>' ? block.at(i++) = '<' : block.at(i--) = '>';
	return answer;
}
int main()
{
	string s = ">";
	long long a = solution(s, 1);
	cout << a;
}