#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int P, S;
int checksum = 0;
vector<int> checkout(4, 0); // A C G T
vector<int> cur_check(4, 0); // A C G T
string A;

void Add(char c) {
  switch(c) {
    case 'A':
      cur_check[0]++;
      if(checkout[0] == cur_check[0])
        checksum++;
      break;
    case 'C':
      cur_check[1]++;
      if(checkout[1] == cur_check[1])
        checksum++;
      break;
    case 'G':
      cur_check[2]++;
      if(checkout[2] == cur_check[2])
        checksum++;
      break;
    case 'T':
      cur_check[3]++;
      if(checkout[3] == cur_check[3])
        checksum++;
      break;
  }
}

void Remove(char c) {
  switch(c) {
    case 'A':
      if(checkout[0] == cur_check[0])
        checksum--;
      cur_check[0]--;
      break;
    case 'C':
      if(checkout[1] == cur_check[1])
        checksum--;
      cur_check[1]--;
      break;
    case 'G':
      if(checkout[2] == cur_check[2])
        checksum--;
      cur_check[2]--;
      break;
    case 'T':
      if(checkout[3] == cur_check[3])
        checksum--;
      cur_check[3]--;
      break;
  }
}

int main() {
  int res = 0 ;
  cin >> P >> S;


  cin >> A;

  for(int i = 0; i < checkout.size(); i++) {
    cin >> checkout[i];
    // 0이면 해당 문자는 검사를 안해도 되니 자동으로 카운트가 하나 증가
    if(checkout[i] == 0)
      checksum++;
  }

  for(int i = 0,  j = S + i - 1; j < A.length() ; i++, j++) {
    if ( i == 0 ) {
      for (int k = 0 ; k < S ; k++) {
        Add(A[k]);
      }
    } else {
      Remove(A[i-1]);
      Add(A[j]);
    }
    if(checksum == 4)
      res++;
  }

  cout << res << endl;
}
