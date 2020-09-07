#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
/*
Leo�� ī���� �緯 ���ٰ� �Ʒ� �׸��� ���� �߾ӿ��� ��������� ĥ���� �ְ� �׵θ� 1���� �������� ĥ���� �ִ� ���� ��� ī���� �ý��ϴ�.

Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������,
��ü ī���� ũ��� ������� ���߽��ϴ�.

Leo�� �� ī�꿡�� ���� ������ �� brown,
����� ������ �� yellow�� �Ű������� �־��� �� ī���� ����,
���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

*/
vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	int size = brown + yellow; //�簢���� ����
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