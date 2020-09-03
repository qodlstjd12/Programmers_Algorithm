#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
안랩 코딩테스트 3번째 문제입니다.

체스판위의 비숍이 현재 위치에서 갈 수 없는 곳은 몇개인지 구하는 문제입니다.

매개변수로는 비숍들의 위치를 문자열로 받습니다.

1차원적으로 생각하여 풀었습니다.
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