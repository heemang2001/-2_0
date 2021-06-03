#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<string> solution(vector<string> s)
{
	vector<string> answer(s.size());

	for (int i = 0; i < s.size(); ++i)
	{
		stack<char> st;
		int count = 0; // s[i] 문자열에서 만들 수 있는 "110" 개수

		// 1️. 모든 "110" 을 찾아 그 개수(count)를 세고 제거한다.
		for (int j = 0; j < s[i].length(); ++j)
		{
			st.push(s[i][j]);

			if (st.size() >= 3)
			{
				// 스택의 위에 있는 3 개를 일단 pop 시키자. (스택은 top 을 제외한 중간 원소 임의 접근 불가능하기 때문에 일단 빼내서 볼 수 밖에 없다. ㅠ)
				char three = st.top(); st.pop();
				char two = st.top(); st.pop();
				char one = st.top(); st.pop();

				// 스택의 위에 있는 3 개가 1 1 0 이라면 count 를 증가시킨다. (이미 pop 시켰음)
				if (one == '1' && two == '1' && three == '0')
				{
					++count;
					continue;
				}
				// 아니라면 다시 스택에 넣어 준다.
				else
				{
					st.push(one);
					st.push(two);
					st.push(three);
				}
			}
		}

		// "110" 이 하나도 없는 문자열이라면 현재 모습 그대로 answer 에 넣고 끝낸다.
		if (count == 0)
		{
			answer[i] = s[i];
			continue;
		}

		// 2️. 스택에 남아 있는 문자들("110"이 모두 제거된 형태의 문자열)을 꺼내 문자열로 만듬과 동시에 count 개수의 연속된 "110" 문자열을 삽입할 위치가 될 인덱스를 찾는다. 
		// 스택에 1011 이 있는 상태라면 1👉1👉0👉1 순으로 꺼내지게 되며 각각 str의 맨 앞에 삽입한다. 결론적으로 str은 "1011" 이 되고 인덱스는 2가 된다. 
		int insert_idx = st.size(); // 삽입할 위치가 될 인덱스
		string str = "";
		// 스택에서 하나씩 꺼내면서 연속된 1 인지 검사. 인덱스 업뎃. 동시에 꺼낸 문자는 str 맨 앞에 삽입 
		while (!st.empty() && st.top() == '1')
		{
			--insert_idx;
			str = st.top() + str;
			st.pop();
		}

		// 연속된 1은 다 빼냈고, 스택에 있는 나머지 문자들 꺼내서 str 맨 앞에 삽입 
		while (!st.empty())
		{
			str = st.top() + str;
			st.pop();
		}

		// 3️. 이전 과정에서 구한 삽입 인덱스에(오른쪽에서부터 연속된 1이 시작되는 곳) count 개수의 연속된 "110"을 삽입하면 된다.
		while (count-- > 0)
		{
			str.insert(insert_idx, "110");
		}
			
		// 완성! 
		answer[i] = str;
	}

	return answer;
}

int main()
{
	vector<string> vecAnswer = solution({ "1110", "100111100", "0111111010" });

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}