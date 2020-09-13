#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
��Ʈ��ũ�� ��ǻ�� ��ȣ ���� ������ ��ȯ�� �� �ֵ��� ����� ���¸� �ǹ��մϴ�. 
���� ���, ��ǻ�� A�� ��ǻ�� B�� ���������� ����Ǿ��ְ�, 
��ǻ�� B�� ��ǻ�� C�� ���������� ����Ǿ� ���� �� ��ǻ�� A�� ��ǻ�� C�� ���������� ����Ǿ� ������ ��ȯ�� �� �ֽ��ϴ�.
���� ��ǻ�� A, B, C�� ��� ���� ��Ʈ��ũ �� �ִٰ� �� �� �ֽ��ϴ�.

��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű������� �־��� ��, 
��Ʈ��ũ�� ������ return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.

���ѻ���
- ��ǻ���� ���� n�� 1 �̻� 200 ������ �ڿ����Դϴ�.
- �� ��ǻ�ʹ� 0���� n-1�� ������ ǥ���մϴ�.
- i�� ��ǻ�Ϳ� j�� ��ǻ�Ͱ� ����Ǿ� ������ computers[i][j]�� 1�� ǥ���մϴ�.
- computer[i][i]�� �׻� 1�Դϴ�.
*/
void solve(vector<vector<int>> &computers, int n) {
	for (int j = 0; j < computers[n].size(); j++) {
		if (!computers[n][j]) continue;
		computers[n][j] = 0; computers[j][n] = 0;
		solve(computers, j);
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int i;
	for (i = 0; i < computers.size(); i++) {
		if (!computers[i][i]) continue;
		solve(computers, i);
		answer++;
	}
	return answer;
}

int main() {
	vector<vector<int>> computers{ {1,1,0} ,{1,1,1}, {0,1,1} };

	cout << solution(3, computers);
	cout << endl;
	for (int i = 0; i < computers.size(); i++) {
		for (int j = 0; j < computers.size(); j++) {
			cout << computers[i][j] << " ";
		}
		cout << endl;
	}
}