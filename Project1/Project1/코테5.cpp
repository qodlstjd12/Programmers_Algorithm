#include <vector>
#include <iostream>

using namespace std;
/*
문제 설명이 기억이 나질 않아 예시로 대신하겠습니다.
그 문제와 같습니다. 
10원짜리 50원짜리 100원짜리 500원짜리 동전을 이용해서
매개변수로 받은 num을 최소한의 동전 갯수로 표현하는 문제입니다.

EX) num = 1000, cards = [10,50,100,500] return = 2;
500원짜리 두개로 표현할 수 있으니 2개가 리턴이 됩니다.

위 문제와 같은 문제입니다.
오름차순으로 정렬되어있는 cards배열이 있고 이 원소들로 num을 최소한의 개수로 표현하는것입니다.

어떤 방법으로도 num을 표현할 수 없으면 -1을 리턴합니다.

*/
int solution(int num, vector<int> cards) {
	int answer = 0, temp = 50000;
	int i, j, temp_num = num, DEADLINE = 0;
	for (i = cards.size() - 1; i >= 0; i--) {
		answer = 0; num = temp_num;		
		for (j = i; j >= 0 && num > 0; ) {
			if (num >= cards[j]) {
				num -= cards[j];
				answer++;
			}
			else {
				if (j == 0 && num < cards[j]) {
					answer = temp;
					DEADLINE++;
					break;
				}
				j--;
			}
		}
		if (temp > answer) temp = answer;
	}
	return DEADLINE == cards.size() ? -1 : temp;
}

int main()
{
	vector<int> cards{ 3,9,12,17 };
	cout << solution(29, cards);
	return 0;
}