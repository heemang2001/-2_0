#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int YacSoo(int num)
{
	int value = 1;

	for (int i = 1; i <= num/2; i++)
	{
		if ((num % i) == 0)
		{
			value++;
		}
	}

	return value;
}

int solution(int left, int right)
{
	int answer = 0;

	for (int i = left; i <= right; i++)
	{
		int nTemp = YacSoo(i);

		// 약수 개수가 짝수면
		if (nTemp % 2 == 0)
		{
			answer += i;
		}

		// 약수 개수가 홀수면
		else
		{
			answer -= i;
		}
	}

	return answer;
}

int main()
{
	cout << solution(13,17) << '\n'; // 43
	cout << solution(24,27) << '\n'; // 52

	return 0;
}