#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;

const ll mod = 1000000007;

int allXor(int x, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	if ((x & (1 << i)) != 0)
    		cnt++;
	}
    return cnt % 2;
}

int b(int x, int n) {
	return x % 2;
}

int A(int x, int n, int k) {
    return (x >> 1) | (allXor(x & k, n) << (n - 1));
}

int An(int x, int n, int k, int cnt) {
    int a = x;
    for (int i = 0; i < cnt; i++)
        a = A(a, n, k);
    return a;
}

int solve1(int x, vector<int> &k, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (auto j : k) {
            c ^= b(An(x, n, j, i), n);
        }
        ans |= c << i;
    }
    return ans;
}

int solve2(int x, int y, vector<int>& k, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c = 0;
        c = b(An(x, n, k[0], i), n) ^ b(An(y, n, k[1], i), n);
        ans |= c << i;
    }
    return ans;
}

bool check(int f, vector<int> &v, int n) {
	vector<int> ff = {f};
	for (int i = 0; i < (1 << n); i++) {
		if (solve1(i, v, n) != solve1(i, ff, n))
			return 0;
	}
	return 1;
}
 
int main() {
	int x = 0b11101001001;
	int n = 11;

	int x1 = 0b10010100011, y1 = 0b11100001000;

	vector<int> k = {0b1101000101, 0b100100101, 0b1101100001};
	vector<int> k1 = {0b10000000, 0b10000000};

	cout << "Task1:\n";

	int ans = solve1(x, k, n);
	cout << ans << "\n";

	int cnt = 0;

	for (int i = 0; i < (1 << n); i++) {
		vector<int> v = {i};
		int c = solve1(x, v, n);
		if (c == ans) {
			if (check(i, v, n)) {
				cnt++;
			}
		}
	}

	cout << cnt << "\n";

	cout << "Task2:\n";

	ans = solve2(x1, y1, k1, n);
	cout << ans << "\n";

	cnt = 0;

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			vector<int> v = {j};
			int c = solve1(i, v, n);
			if (c == ans) {
				cnt++;
			}
		}
	}

	cout << cnt << endl;
}