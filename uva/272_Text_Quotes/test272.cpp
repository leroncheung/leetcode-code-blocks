#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    bool flag;
    while (getline(cin, line) != EOF) {
        flag = true;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '"') {
                if (flag)   cout << "``";
                else    cout << '"';
                flag = !flag;
            } else {
                cout << line[i];
            }
        }
    }

    return 0;
}
