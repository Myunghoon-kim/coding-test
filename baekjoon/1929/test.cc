#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M,N;


  cin >> M >> N ;

  vector<int> primes(N);
  for(int i = 0; i <= N; i++) {
    primes[i] = i;
  }
  primes[1] = 0;
  for(int i = 2 ; i <= sqrt(N) ; i++) {
    if(primes[i] == 0)
      continue;

    for(int j = i + i ; j <= N ; j = j + i) {
      primes[j] = 0;
    }
  }

  for(int i = M ; i < N; i++) {
    if( primes[i] != 0)
      cout << primes[i] << '\n';
  }
}
