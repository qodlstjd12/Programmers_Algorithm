#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
���� ����
�����ڴ� ������ ������ ����� �ظ��Դϴ�.
������ ���ι��� ���ǰ�翡 ���� ������ ���� ������ �մϴ�.
�����ڴ� 1�� �������� ������ �������� ������ ���� ����ϴ�.

1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��,
���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
������ �ִ� 10,000 ������ �����Ǿ��ֽ��ϴ�.
������ ������ 1, 2, 3, 4, 5�� �ϳ��Դϴ�.
���� ���� ������ ���� ����� ������ ���, return�ϴ� ���� �������� �������ּ���.
*/
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int man2[] = { 1,3,4,5 };
	int man3[] = { 3,1,2,4,5 };
	int c[3] = { 0,0,0 };
	int max;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == (i % 5) + 1)  c[0]++; //1�� ������ ����
		
		if (i % 2 == 0 && answers[i] == 2) c[1]++;
		else if (i % 2 != 0 && answers[i] == man2[(i % 8) / 2]) c[1]++; //2�� ������ ����
		
		if (answers[i] == man3[(i % 10) / 2]) c[2]++; //3�� ������ ����
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