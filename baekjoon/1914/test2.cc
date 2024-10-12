#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n;

void hanoi(int n, int start, int mid, int to)
{
  if (n == 1) {
    cout << start << " " << to << endl;
    return;
  }

  hanoi(n - 1, start, to, mid);

  cout << start << " " << to << endl;

  hanoi(n - 1, to, mid, start);

}

int main()
{

  cin >> n;

  string str = to_string(pow(2, n));

  int a = str.find('.');
  str = str.substr(0, a);
  str[str.length() - 1] -= 1;

  cout << str << endl;

  if(n <= 20)
    hanoi(n, 1, 2, 3);

  return 0;
}
