#include <bits/stdc++.h>
using namespace std;

struct stack_ {
	int a[100000];
	int topIndex;
	stack_ () {
		topIndex = -1;
	}
	void push (int x) {
		topIndex++;
		a[topIndex] = x;
	}
	void pop () {
		topIndex--;
	}
	void back () {
		cout << a[topIndex] << '\n';
	}
	int size () {
		return (topIndex + 1);
	}
	void clear () {
		topIndex = -1;
	}
};

signed main () {
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	stack_ st;
	while (true) {
		string s;
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			st.push (n);
			cout << "ok\n";
		}
		else if (s == "pop") {
			if (st.size () == 0) {
				cout << "error\n";
			}
			else {
				st.back ();
				st.pop ();
			}
		}
		else if (s == "back") {
			if (st.size () == 0) {
				cout << "error\n";
			}
			else {
				st.back ();	
			}
		}
		else if (s == "size") {
			cout << st.size () << '\n';
		}
		else if (s == "clear") {
			st.clear ();
			cout << "ok\n";
		}
		else if (s == "exit") {
			cout << "bye\n";
			break;
		}
	}
	return 0;
}