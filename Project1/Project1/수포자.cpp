#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
문제 설명
수포자는 수학을 포기한 사람의 준말입니다.
수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다.
수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때,
가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
*/
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int man2[] = { 1,3,4,5 };
	int man3[] = { 3,1,2,4,5 };
	int c[3] = { 0,0,0 };
	int max;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == (i % 5) + 1)  c[0]++; //1번 수포자 공식
		
		if (i % 2 == 0 && answers[i] == 2) c[1]++;
		else if (i % 2 != 0 && answers[i] == man2[(i % 8) / 2]) c[1]++; //2번 수포자 공식
		
		if (answers[i] == man3[(i % 10) / 2]) c[2]++; //3번 수포자 공식
	}
	
	max = c[0] > c[1] ? ((c[0] > c[2]) ? c[0] : c[2]) : ((c[1] > c[2]) ? c[1] : c[2]);

	for (int i = 0; i < 3; i++)
		if (c[i] == max) answer.push_back(i + 1);
	return answer;
}
int main() {
	vector<int> answers1{ 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 };
	vector<int> answers2{ 1,3,2,4,2,1,3,2,4,2,1,3,2,4,2 };

	vector<int> a1 = solution(answers1);
	vector<int> a2 = solution(answers2);

	for (int i = 0; i < a1.size(); i++)
		cout << a1[i] << " ";
	cout << endl;
	for (int i = 0; i < a2.size(); i++)
		cout << a2[i] << " ";
	cout << endl;

}