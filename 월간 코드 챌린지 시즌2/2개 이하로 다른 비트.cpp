#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

// �ð����⵵ ����
//vector<long long> solution(vector<long long> numbers)
//{
//	vector<long long> answer;
//
//	for (int i = 0; i < numbers.size(); i++)
//	{		
//		auto lTemp = bitset<32>(numbers[i]);	
//
//		int nBitValue = 0;
//		long long ltemp2 = numbers[i];
//
//		while (1)
//		{
//			ltemp2++;
//			auto bitTemp = bitset<32>(ltemp2);
//			nBitValue = 0;
//
//			for (int i = 0; i < bitTemp.size(); i++)
//			{
//				if (lTemp[i] != bitTemp[i])
//				{
//					nBitValue++;
//				}
//			}
//
//			if (nBitValue <= 2)
//			{
//				break;
//			}
//		}
//		answer.push_back(ltemp2);
//	}
//
//	return answer;
//}

vector<long long> solution(vector<long long> numbers)
{
	vector<long long> answer;

	for (int i = 0; i < numbers.size(); i++)
	{
		long long Num = numbers[i];
		
		// ¦���� 1 ���Ѽ��� �ּҰ�
		if (Num % 2 == 0)
		{
			answer.push_back(Num + 1);
		}

		// Ȧ���� ��������Ʈ 0�� 1�ιٲٰ� ������Ʈ�� 0����
		else
		{
			long long LastZero = (Num + 1) & (-Num);
			long long Result = (Num | LastZero) & (~(LastZero >> 1));
			answer.push_back(Result);
		}
	}
	return answer;
}

int main()
{
	vector<long long> answer = solution({ 2,7,47 });

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}