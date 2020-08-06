#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/*
���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�. 
������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�. 
�л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. 
���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. 
ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� �ִ��� ���� �л��� ü�������� ���� �մϴ�.

��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, 
������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, 
ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��ü �л��� ���� 2�� �̻� 30�� �����Դϴ�.
ü������ �������� �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
������ ü������ ������ �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
���� ü������ �ִ� �л��� �ٸ� �л����� ü������ ������ �� �ֽ��ϴ�.
���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�. 
�̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, 
���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.*/
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0, i, j, index = 0;
	answer = n - lost.size();
	
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (i = 0; i < lost.size(); i++) {
		for (j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost[i] = 2000;
				reserve[j] = 4000;
				answer++;
			}
		}
	}
	
	for (i = 0; i < lost.size(); i++) {
		j = index;
		while (j < reserve.size()) {
			if (abs(reserve[j] - lost[i]) <= 1) {//�������ݾ�
				index++;
				answer++;
				break;
			}
			j++;
		}		
	}
	return answer;
}
int main()
{
	vector<int> lost{ 2,3,5 };
	vector<int> reserve{ 2,4 };
	int n = 5;
	cout << solution(n, lost, reserve) << endl;

	return 0;
}