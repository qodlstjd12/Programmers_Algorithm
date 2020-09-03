#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
�ȷ� �ڵ��׽�Ʈ 3��° �����Դϴ�.

ü�������� ����� ���� ��ġ���� �� �� ���� ���� ����� ���ϴ� �����Դϴ�.

�Ű������δ� ������ ��ġ�� ���ڿ��� �޽��ϴ�.

1���������� �����Ͽ� Ǯ�����ϴ�.
*/

int solution(vector<string> bishops) {
	int answer = 0;
	bool bitmap[8][8] = { false, };
	int i, j, k;
	for (i = 0; i < bishops.size(); i++) {
		for (j = bishops[i].at(0) - 65, k = bishops[i].at(1) - 49; j >= 0 && j < 8 && k >= 0 && k < 8; bitmap[j--][k--] = true);
		for (j = bishops[i].at(0) - 65, k = bishops[i].at(1) - 49; j >= 0 && j < 8 && k >= 0 && k < 8; bitmap[j--][k++] = true);
		for (j = bishops[i].at(0) - 65, k = bishops[i].at(1) - 49; j >= 0 && j < 8 && k >= 0 && k < 8; bitmap[j++][k--] = true);
		for (j = bishops[i].at(0) - 65, k = bishops[i].at(1) - 49; j >= 0 && j < 8 && k >= 0 && k < 8; bitmap[j++][k++] = true);
	}
	for (i = 0; i < 8; i++) 
		for (j = 0; j < 8; j++) 
			if (!bitmap[i][j]) answer++;
		
	
	return answer;
}
int main()
{
	vector<string> bishops{ "C6", "A4", "E5" };

	int answer = solution(bishops);
	cout << answer;
}