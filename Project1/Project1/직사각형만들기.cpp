#include <iostream>
#include <vector>

using namespace std;

/*
직사각형을 만드는 데 필요한 4개의 점 중 3개의 좌표가 주어질 때, 나머지 한 점의 좌표를 구하려고 합니다. 
점 3개의 좌표가 들어있는 배열 v가 매개변수로 주어질 때, 
직사각형을 만드는 데 필요한 나머지 한 점의 좌표를 return 하도록 solution 함수를 완성해주세요. 
단, 직사각형의 각 변은 x축, y축에 평행하며, 반드시 직사각형을 만들 수 있는 경우만 입력으로 주어집니다.

제한사항
v는 세 점의 좌표가 들어있는 2차원 배열입니다.
v의 각 원소는 점의 좌표를 나타내며, 좌표는 [x축 좌표, y축 좌표] 순으로 주어집니다.
좌표값은 1 이상 10억 이하의 자연수입니다.
직사각형을 만드는 데 필요한 나머지 한 점의 좌표를 [x축 좌표, y축 좌표] 순으로 담아 return 해주세요.

*/
vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;
	int i, j, p1;
	for (i = 0; i < v.size() - 1; i++) {
		for (j = i + 1; j < v.size() && v[i][0] != v[j][0]; j++);
		if (j != v.size()) break;
	} //일단 x좌표가 같은좌표의 인덱스를 찾은 다음

	p1 = 3 - (i + j); // x좌표가 혼자인 곳의 인덱스를 잡아낸다.
	ans.push_back(v[p1][0]); //우선 x좌표 먼저 push
	
	v[p1][1] == v[i][1] ? ans.push_back(v[j][1]) : ans.push_back(v[i][1]); //정해진 채로 y축의 값도 비교

	return ans;
}
int main()
{
	vector<vector<int> > v{ {1,1}, {2,2}, {1,2} };

	vector<int> ans = solution(v);

	cout << "[" << ans[0] << "," << ans[1] << "]" << endl;

	return 0;
}