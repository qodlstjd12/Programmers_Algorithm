#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

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
			if (abs(reserve[j] - lost[i]) <= 1) {//ºô¸°°ÅÀÝ¾Æ
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