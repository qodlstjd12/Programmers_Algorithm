#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
안랩 코딩테스트 문제 2
매개변수로 < 와 > 로 이루어진 문자열과 pos이라는 위치를 받습니다.

block[pos - 1]부터 시작해서 
'>' 를 만나면 그 원소를 '<'로 바꾸고 한칸 오른쪽으로,
'<' 를 만나면 그 원소를 '>'로 바꾸고 한칸 왼쪽으로 움직입니다.

이렇게 계속 반복하다가 문자열을 빠져나가는데 몇 초가 걸리는지를 계산하는 문제입니다.

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