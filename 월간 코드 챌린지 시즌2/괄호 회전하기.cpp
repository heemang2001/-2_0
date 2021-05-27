#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string s)
{
	int answer = 0;

	for (int i = 0; i < s.size(); i++)
	{
		stack<char> st;
		bool bStart = false;

		for (int j = 0; j < s.size(); j++)
		{
			// ¿©´Â °ýÈ£¸é
			if (s[j] == '[' || s[j] == '(' || s[j] == '{')
			{
				bStart = true;
				st.push(s[j]);
			}

			// ´Ý´Â °ýÈ£¸é
			else
			{
				if (st.empty())
				{
					continue;
				}

				else if (s[j] == ']' && st.top() == '[')
				{
					st.pop();
				}

				else if (s[j] == '}' && st.top() == '{')
				{
					st.pop();
				}

				else if (s[j] == ')' && st.top() == '(')
				{
					st.pop();
				}
			}
		}

		if (st.empty() && bStart)
		{
			answer++;
		}

		// È¸Àü
		char ch = s.front();
		s.erase(s.begin());
		s.push_back(ch);
	}

	return answer;
}

int main()
{
	cout << solution("[](){}") << '\n'; // 3
	cout << solution("}]()[{") << '\n'; // 2
	cout << solution("[)(]") << '\n';	// 0
	cout << solution("}}}") << '\n';	// 0

	return 0;
}