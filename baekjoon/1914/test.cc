#include <iostream>
using namespace std;

int N;
unsigned long cnt = 1;

void hanoi(int n, int from, int by, int to)
{
  if(n == 0) return;
  hanoi(n - 1, from, to, by);
  printf("%d %d\n" ,from,to);
  hanoi(n - 1, by, from, to);
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N ; i++) {
    cnt = cnt * 2;
  }
  cnt--;
  printf("%lu\n",cnt);
  if(N <= 20)
    hanoi(N,1,2,3);
}
