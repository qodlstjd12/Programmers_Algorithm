#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
���α׷��ӽ� �������� ��� ���� �۾��� ���� ���Դϴ�. 
�� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� �ֽ��ϴ�.

��, �� ����� ���߼ӵ��� ��� �ٸ��� ������ �ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�, 
�̶� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����˴ϴ�.

���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� ���� �迭 progresses�� 
�� �۾��� ���� �ӵ��� ���� ���� �迭 speeds�� �־��� �� 
�� �������� �� ���� ����� �����Ǵ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
�۾��� ����(progresses, speeds�迭�� ����)�� 100�� �����Դϴ�.
�۾� ������ 100 �̸��� �ڿ����Դϴ�.
�۾� �ӵ��� 100 ������ �ڿ����Դϴ�.
������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����ٰ� �����մϴ�. 
���� ��� �������� 95%�� �۾��� ���� �ӵ��� �Ϸ翡 4%��� ������ 2�� �ڿ� �̷�����ϴ�. */

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int i, j, temp;
	int count;
	for(i = 0; i < progresses.size(); i++) {
		temp = (100 - progresses[i]) / speeds[i];
		(100 - progresses[i]) % speeds[i] != 0 ? progresses[i] = temp + 1 : progresses[i] = temp;
	} //progresses ���͸� ������

	for (i = 0; i < progresses.size(); i = j) {
		for (j = i + 1, count = 1; 
			j < progresses.size() && progresses[i] >= progresses[j]; 
			j++, count++);
		answer.push_back(count);
	}

	return answer;
}

int main()
{
	vector<int> progresses{ 93,30,80 };
	vector<int> speeds{ 1,30,5 };

	vector<int> arr = solution(progresses, speeds);
	
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
}