#include <vector>
#include <iostream>

using namespace std;
/*
�迭 arr�� �־����ϴ�. 
�迭 arr�� �� ���Ҵ� ���� 0���� 9������ �̷���� �ֽ��ϴ�. 
�̶�, �迭 arr���� ���������� ��Ÿ���� ���ڴ� �ϳ��� ����� ���� �����Ϸ��� �մϴ�. 
��, ���ŵ� �� ���� ������ ��ȯ�� ���� �迭 arr�� ���ҵ��� ������ �����ؾ� �մϴ�. 

���� ���,
arr = [1, 1, 3, 3, 0, 1, 1] �̸� [1, 3, 0, 1] �� return �մϴ�.
arr = [4, 4, 4, 3, 3] �̸� [4, 3] �� return �մϴ�.
�迭 arr���� ���������� ��Ÿ���� ���ڴ� �����ϰ� ���� ������ return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
�迭 arr�� ũ�� : 1,000,000 ������ �ڿ���
�迭 arr�� ������ ũ�� : 0���� ũ�ų� ���� 9���� �۰ų� ���� ����
*/
vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int i, j;
	for (i = 0; i < arr.size();) {
		answer.push_back(arr[i]);
		for (j = i + 1; j < arr.size() && arr[i] == arr[j]; j++);
		i = j;
	}
	return answer;
}

int main()
{
	vector<int> arr{ 4,4,4,4,4,4,4,3,3,3,3,3,4,4,3,4,3,3};
	
	vector<int> temp = solution(arr);

	for (int i = 0; i < temp.size(); i++) cout << temp[i] << " ";
}