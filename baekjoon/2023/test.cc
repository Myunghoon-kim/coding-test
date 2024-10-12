#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> odd = {1, 3, 5, 7, 9};
vector<int> start = {2, 3, 5, 7};

bool sosu(int number) {
  for(int i = 2 ; i < number / 2 ; i++) {
    if((number % i) == 0)
      return false;
  }
  return true;
}

void dfs(int number, int deps) {
  if( deps == N) {
    if(sosu(number)) {
      cout << number << endl;
    }
    return ;
  }

  for(int i = 0 ; i < odd.size() ; i++) {
    if(sosu((number * 10) + odd[i]))
      dfs((number * 10) + odd[i] , deps + 1);
  }
}

int main() {
  cin >> N;

  for(int i = 0 ; i < start.size() ; i++) {
    dfs(start[i], 1);
  }
}
