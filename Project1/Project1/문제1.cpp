#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
2019 카카오 개발자 겨울 인턴십 문제입니다
문제설명이 사진으로 길게 되어있어서 링크로 대체합니다.
문제설명 : https://velog.io/@yoonah97/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-LEVEL-1-%ED%81%AC%EB%A0%88%EC%9D%B8-%EC%9D%B8%ED%98%95%EB%BD%91%EA%B8%B0-%EA%B2%8C%EC%9E%84
*/
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int i, j;
	vector<int> stack;

	for (i = 0; i < moves.size(); i++) {

		for (j = 0; j < board.size() && board[j][moves[i] - 1] == 0; j++); //0아닌 원소를 만날때까지 밑으로

		if (j != board.size()) {
			stack.push_back(board[j][moves[i] - 1]);
			board[j][moves[i] - 1] = 0;
			if (stack.size() > 1 && (stack[stack.size() - 1] == stack[stack.size() - 2])) {
				stack.pop_back();
				stack.pop_back();
				answer += 2;
			}
		}
	}
	return answer;
}
int main()
{
	vector<vector<int>> board{ 
		{0,0,0,0,0},
		{0,0,1,0,3},
		{0,2,5,0,1},
		{4,2,4,4,2},
		{3,5,1,3,1} 
	};	
	vector<int> moves{ 1,5,3,5,1,2,1,4 };
	cout << solution(board, moves) << endl;
	return 0;
}