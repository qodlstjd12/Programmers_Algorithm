#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
���� ��ų�̶� � ��ų�� ���� ���� ���� ����� �ϴ� ��ų�� ���մϴ�.

���� ��� ���� ��ų ������ ����ũ �� ����Ʈ�� ��Ʈ �� ����϶�, 
����� ������ ���� ����Ʈ�� ��Ʈ�� ����� �ϰ�, 
����Ʈ�� ��Ʈ�� ������ ���� ����ũ�� ����� �մϴ�.

�� ������ ���� �ٸ� ��ų(���� ��)�� ������ ������� ��� �� �ֽ��ϴ�. 
���� ����ũ �� ���� �� ����Ʈ�� ��Ʈ �� ����� ���� ��ųƮ���� ����������, 
��� �� ����ũ�� ����Ʈ�� ��Ʈ �� ����ũ �� ���� �� ����� ���� ��ųƮ���� �Ұ����մϴ�.

���� ��ų ���� skill�� �������� ���� ��ųƮ��1�� ���� �迭 skill_trees�� �Ű������� �־��� ��, 
������ ��ųƮ�� ������ return �ϴ� solution �Լ��� �ۼ����ּ���.

���� ����
-��ų�� ���ĺ� �빮�ڷ� ǥ���ϸ�, ��� ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
-��ų ������ ��ųƮ���� ���ڿ��� ǥ���մϴ�.
-���� ���, C �� B �� D ��� CBD�� ǥ���մϴ�
-���� ��ų ���� skill�� ���̴� 1 �̻� 26 �����̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.
-skill_trees�� ���� 1 �̻� 20 ������ �迭�Դϴ�.
-skill_trees�� ���Ҵ� ��ų�� ��Ÿ���� ���ڿ��Դϴ�.
-skill_trees�� ���Ҵ� ���̰� 2 �̻� 26 ������ ���ڿ��̸�, ��ų�� �ߺ��� �־����� �ʽ��ϴ�.
*/

bool issort(vector<int> arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
}
int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int i, j, pos;
	vector<int> arr;
	for (i = 0; i < skill_trees.size(); i++) {
		
		for (j = 0; j < skill.length(); j++) {
			pos = skill_trees[i].find(skill[j]);
			pos != string::npos ? arr.push_back(pos) : arr.push_back(skill_trees[i].length());
		}
		if (issort(arr)) answer++;
		arr.clear();
	}
	return answer;
}

int main()
{
	string skill = "CBD";
	vector<string> skill_trees {"BACDE", "CBADF", "AE", "BDA"};
	

	cout << solution(skill, skill_trees);
}
/* for (i = 0; i < skill_trees.size(); i++) {
		temp = 0;
		for (j = 0; j < skill.length(); j++) {
			for (k = 0; skill[j] != skill_trees[i][k] && k < skill_trees[i].length(); k++);
			if (temp > k) break;
			k == skill_trees[i].length() ?
		}
		if (j == skill.length()) answer++;
	}*/
