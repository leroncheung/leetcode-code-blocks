#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	char ch;
	int vowelCnt = 0;
	cin >> ch;
	switch (ch)
	{
		case 'a': case 'o': case 'e': case 'i': case 'u':
		vowelCnt++;
	}

	// For Sample
	vector<char> s{"helloworld"};
	for (decltype(s.size()) index = 0; index != s.size() && isspace(s[index]); ++index) {
		s[index] = toupper(s[index]);
	}

	for (decltype(s.size()) i = 0, sz = s.size(); i != sz; ++i) {
		s.push_back(s[i]);
	}

	for (auto beg = s.begin(); beg != v.end() && *beg >= 0; ++i)
		;	// Do nothing

	// get input
	vecotr<int> vi;
	for (int i; cin >> i;)
		vi.push_back(i);

	// cin ?
	char c;
	cin >> c;
	if (!cin || c == 'n')
		return;

	// range for statement
	vector<int> v = {0,1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (auto &r : v) {
		r *= 2;
	}

	return 0;
}
