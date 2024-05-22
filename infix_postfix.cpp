#include<iostream>
#include <stack>

using namespace std;

int prec(char ch)
{
	if (ch == '^')
	{
		return 3;
	}
	else if (ch == '/' || ch == '*')
	{
		return 2;
	}
	else if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

string infixTopostfix(string s)
{
	stack<char> st;
	string ans = "";
	char ch;

	for (int i = 0; i < s.length(); i++)
	{
		ch = s[i];

		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			ans += ch;
		}
		else if (ch == '(')
		{
			st.push('(');
		}
		else if (ch == ')')
		{
			while (!st.empty() && st.top() != ('('))
			{
				ans += st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && prec(ch) <= prec(st.top()))
			{
				ans += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	return ans;
}

void main()
{
	string s;
	cout << "enter infix expression: ";
	cin >> s;
	cout << "Post Fix Exoression: " << infixTopostfix(s);
}