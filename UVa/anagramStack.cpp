//UVa id 00732

#include <bits/stdc++.h>

using namespace std;

void step(string in, string out, stack<char> letters, string value) {
    if (!in.empty()) {
        letters.push(in.front());
        step(in.substr(1), out, letters, value + "i ");
        letters.pop();
    } 
    if (!letters.empty() && letters.top() == out.front()) {
        letters.pop();
        out.erase(0, 1);
        if (out.empty()) {cout << value + "o\n";}
        else {step(in, out, letters, value + "o ");}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in, out, value;
    stack<char> letters;

    while (getline(cin, in)) {
        while (in.empty()) {getline(cin, in);} 
        out.clear();
        while (out.empty()) {getline(cin, out);}

        while (!letters.empty()) {letters.pop();}
        value.clear();

        cout << "[\n";

        step(in, out, letters, value);

        cout << "]\n";
        flush(cout);
    }

    return 0;
}