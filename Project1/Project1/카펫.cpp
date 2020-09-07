#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
/*
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만,
전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown,
노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로,
세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

*/
vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int size = brown + yellow; //사각형의 넓이
	int i;
	for (i = sqrt(size); i > 0 && ((i - 2) * (size / i - 2) != yellow || size % i != 0); i--);

	size / i > i ? answer = { size / i, i } : answer = { i, size / i };
	return answer;
}

int main()
{
	vector<int> answer = solution(8,1);

	for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
}