#include <iostream>
using namespace std;

bool iseven(int x) { return x % 2 == 0; }

int maxnumber(int a, int b) { return (a >= b) * a + (b > a) * b; }

string touppercase(string text) {
  for (int i = 0; i < text.length(); i++) {
    if (text[i] >= 97 && text[i] <= 122) {
      text[i] = text[i] - 32;
    }
  }
  return text;
}

int main() {
  cout << "Hello World!" << endl;
  cout << "H" << "e" << "l" << "l" << "o" << endl;
  int x = 3;
  int y = 4;
  cout << "The result of " << x << " + " << y << " is equal to " << x + y << "!"
       << endl;
  string test = "Hi"
                " there";
  cout << test << endl;
  cout << "Hi!\n\nWhat's up??\n";

  int a = 22;
  cout << a << endl;
  a += 2;
  cout << a << endl;
  a = 10;
  cout << a << endl;
  cout << a + 20.2 << endl;
  int b = 30;
  cout << a + b << endl;
  b = a;
  cout << a << " " << b << endl;

  cout << a << " " << iseven(a) << endl;
  cout << maxnumber(410, 10) << endl;

  char aLetter = 'a';
  cout << aLetter << endl;
  aLetter += 1;
  cout << aLetter << endl;

  string text = "hello there, how are you?";
  cout << text << " " << touppercase(text) << endl;

  cout << "\n\n" << touppercase("abcdefghijklmnoprqstuwxyz") << endl;
  return 0;
}
