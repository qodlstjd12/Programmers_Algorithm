#include <vector>
#include <iostream>

using namespace std;
/*
���� ������ ����� ���� �ʾ� ���÷� ����ϰڽ��ϴ�.
�� ������ �����ϴ�. 
10��¥�� 50��¥�� 100��¥�� 500��¥�� ������ �̿��ؼ�
�Ű������� ���� num�� �ּ����� ���� ������ ǥ���ϴ� �����Դϴ�.

EX) num = 1000, cards = [10,50,100,500] return = 2;
500��¥�� �ΰ��� ǥ���� �� ������ 2���� ������ �˴ϴ�.

�� ������ ���� �����Դϴ�.
������������ ���ĵǾ��ִ� cards�迭�� �ְ� �� ���ҵ�� num�� �ּ����� ������ ǥ���ϴ°��Դϴ�.

� ������ε� num�� ǥ���� �� ������ -1�� �����մϴ�.

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