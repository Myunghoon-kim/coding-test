#include <iostream>

using namespace std;
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


int main() {
  _pow(100);
}
