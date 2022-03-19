#include <bits/stdc++.h>
using namespace std;

const int len = 200000;

struct deque_ {
	int a[len];
	int leftIndex, rightIndex;
	deque_ () {
		leftIndex = len / 2;
		rightIndex = len / 2;
	}
	void push_front (int x) {
		a[leftIndex] = x;
		if (leftIndex == len / 2 && rightIndex == len / 2) {
			rightIndex++;
		}
		leftIndex--;
	}
	void push_back (int x) {
		a[rightIndex] = x;
		if (leftIndex == len / 2 && rightIndex == len / 2) {
			leftIndex--;
		}
		rightIndex++;
	}
	void pop_front () {
		leftIndex++;
		if (leftIndex > rightIndex) {
			leftIndex = len / 2;
			rightIndex = len / 2;
		}
	}
	void pop_back () {
		rightIndex--;
		if (leftIndex > rightIndex) {
			leftIndex = len / 2;
			rightIndex = len / 2;
		}
	}
	int front () {
		return a[leftIndex + 1];
	}
	int back () {
		return a[rightIndex - 1];
	}
	int size () {
		int ans = rightIndex - leftIndex - 1;
		if (ans == -1) {
			return 0;
		}
		else {
			return ans;
		}
	}
	void clear () {
		leftIndex = len / 2;
		rightIndex = len / 2;
	}
};

signed main () {
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	deque_ d;
	while (true) {
		string s;
		cin >> s;
		if (s == "push_front") {
			int n;
			cin >> n;
			d.push_front (n);
			cout << "ok\n";
		}
		else if (s == "push_back") {
			int n;
			cin >> n;
			d.push_back (n);
			cout << "ok\n";
		}
		else if (s == "pop_front") {
			if (d.size () == 0) {
				cout << "error\n";
			}
			else {
				cout << d.front () << '\n';
				d.pop_front ();
			}
		}
		else if (s == "pop_back") {
			if (d.size () == 0) {
				cout << "error\n";
			}
			else {
				cout << d.back () << '\n';
				d.pop_back ();
			}
		}
		else if (s == "front") {
			if (d.size () == 0) {
				cout << "error\n";
			}
			else {
				cout << d.front () << '\n';
			}
		}
		else if (s == "back") {
			if (d.size () == 0) {
				cout << "error\n";
			}
			else {
				cout << d.back () << '\n';
			}
		}
		else if (s == "size") {
			cout << d.size () << '\n';
		}
		else if (s == "clear") {
			d.clear ();
			cout << "ok\n";
		}
		else if (s == "exit") {
			cout << "bye\n";
			break;
		}
	}
	return 0;
}