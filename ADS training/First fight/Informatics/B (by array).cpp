#include <bits/stdc++.h>
using namespace std;

struct queue_ {
	int a[100000];
	int leftIndex, rightIndex;
	
	queue_ () {
		leftIndex = -1;
		rightIndex = -1;
	}
	void push (int x) {
		if (leftIndex == -1) {
			leftIndex = 0;
		}
		rightIndex++;
		a[rightIndex] = x;
	}
	void pop () {
		leftIndex++;
		if (leftIndex > rightIndex) {
			leftIndex = -1;
			rightIndex = -1;
		}
	}
	int front () {
		return a[leftIndex];
	}
	int size () {
		if (leftIndex == -1 && rightIndex == -1) {
			return 0;
		}
		else {
			return (rightIndex - leftIndex + 1);
		}
	}
	void clear () {
		leftIndex = -1;
		rightIndex = -1;
	}
};

signed main () {
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	queue_ q;
	while (true) {
		string s;
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			q.push (n);
			cout << "ok\n";
		}
		else if (s == "pop") {
			if (q.size () == 0) {
				cout << "error\n";
			}
			else {
				cout << q.front () << '\n';
				q.pop ();
			}
		}
		else if (s == "front") {
			if (q.size () == 0) {
				cout << "error\n";
			}
			else {
				cout << q.front () << '\n';
			}
		}
		else if (s == "size") {
			cout << q.size () << '\n';
		}
		else if (s == "clear") {
			q.clear ();
			cout << "ok\n";
		}
		else if (s == "exit") {
			cout << "bye\n";
			break;
		}
	}
	return 0;
}