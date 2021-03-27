#include <vector>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <ctime>
#include <fstream>

const int t = 2;
const int n = 8;	

int get(int a, int i) {
	return (a & (1 << i)) != 0;
}

std::vector<int> dot(std::vector<int> a, std::vector<int> b, int n) {
	std::vector<int> res(a.size());

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < b.size(); k++) {
				res[i] ^= ((get(a[i], k) * get(b[k], j)) << j);
			}
		}
	}
	return res;
}

std::vector<int> mPow(std::vector<int> a, int n, int b) {
	std::vector<int> res(a.size());
	for (int i = 0; i < n; i++) {
		res[i] = 1 << i;
	}

	for (int i = 0; i < b; i++) {
		res = dot(res, a, n);
	}
	return res;
}

std::vector<int> T(std::vector<int> a, int n) {
	std::vector<int> res(n);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < n; j++) {
			res[j] |= (get(a[i], j) << i);
		}
	}
	return res;
}

std::vector<int> foo(std::vector<int> a, std::vector<int> b, int n) {
	std::vector<int> res(a.size());
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < n; j++) {
			res[i] |= ((get(a[i], j) ^ get(b[i], j)) << j);
		}
	}
	return res;
}

bool equal(std::vector<int> a, std::vector<int> b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

std::vector<std::vector<int>> f(std::vector<int> a, std::vector<int> c, int s0, int n) {
	std::vector<std::vector<int>> ans(t);
	for (int i = 0; i < t; i++) {
		ans[i] = dot(dot(c, mPow(a, n, i), n), T({ s0 }, n), 1);
	}
	return ans;
}

std::vector<int> gen(int a, int n) {
	std::vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = rand() % (1 << a);
	}
	return res;
}

std::vector<int> solve(int t, int s0, std::vector<int> u, std::vector<int> a, std::vector<int> b, std::vector<int> c, std::vector<int> d) {
	std::vector<int> s(t + 1);
	s[0] = s0;
	std::vector<int> ans(t);

	for (int i = 0; i < t; i++) {
		s[i + 1] = T(
						foo(
							dot(a, T({ s[i] }, n), 1), dot(b, T({ u[i] }, n), 1), 1
							), 1
					)
					[0];
		ans[i] = T(foo(dot(c, T({ s[i] }, n), 1), dot(d, T({ u[i] }, n), 1), 1), 1)[0];
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	srand(time(0));
	setlocale(LC_ALL, "Russian");
	std::ofstream out("output.txt");

	const std::vector<int> a = { 1, 235, 32, 2, 15, 3, 32, 100 };
	const std::vector<int> b = { 12, 45, 56, 13, 127, 214, 1, 11};
	const std::vector<int> c = { 134, 230, 200, 6, 9, 3, 101, 201};
	const std::vector<int> d = { 154, 254, 16, 18, 20, 154, 3, 7 };

	std::vector<int> u = gen(n, t);
	out << "Входная последовательность: ";
	for (auto i : u)
		out << i << ' ';
	std::map<std::vector<int>, int> m0;
	for (int s0 = 0; s0 < 256; s0++) {
		std::vector<int> ans = solve(t, s0, u, a, b, c, d);
		m0[ans]++;
		out << "\nВыходная последовательность при s0 = "<<s0  << ": ";
		for (auto i : ans)
			out << i << ' ';
	}
	out << "\nКоличество классов эквивалентности: " << m0.size() << std::endl;

	std::map<std::vector<std::vector<int>>, int> m;
	for (int i = 0; i < (1 << n); i++) {
		m[f(a, c, i, n)]++;
	}
	std::cout << "Количество: " << m.size() << std::endl;
	return 0;
}