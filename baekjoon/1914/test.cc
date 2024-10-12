#include <iostream>
using namespace std;

int N;
unsigned long cnt = 1;

void _pow(int n){
  long long a = 0, b = 0, mod = 1000000000000000000;
  for(int i=0; i<n; i++){
    b*=2;
    a = 2 * a + 1;
    b += a / mod;
    a %= mod;
  }
  if(b>0) cout << b << a << '\n';
  else cout << a << '\n';
}


void hanoi(int n, int from, int by, int to)
{
  if(n == 0) return;
  hanoi(n - 1, from, to, by);
  printf("%d %d\n" ,from,to);
  hanoi(n - 1, by, from, to);
}

int main() {
  scanf("%d", &N);
  _pow(N);
  if(N <= 20)
    hanoi(N,1,2,3);
}
