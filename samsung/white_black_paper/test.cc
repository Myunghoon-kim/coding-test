#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<pair<int,int>, pair<int,int>> get_union(int x1, int y1,
											 int x2, int y2,
											 int x3, int y3,
											 int x4, int y4) {
	int x = max(x1, x3);
	int y = max(y1, y3);
	int x_2 = max(x2, x4);
	int y_2 = max(y2, y4);
	
	if (x < x_2 && y < y_2)
		return {{x ,  y}, {x_2, y_2}};
	else 
		return {{-1, -1}, { -1,  -1}};
}

int calculate_region(int x, int y, int x1, int y2) {
	int width, height;
	
	x > x1 ? width = x - x1 : width = x1 - x;
	y > y1 ? height = y - y1 : height = y1 - y;
	
	return width * height;
}

void is_white_or_black(vector<vector<vector>>>& cases, int t ) {
	for(int i = 0 ; i < t ; i++) {
		int available = 0;
		vector<int> white  = cases[i][0];
		vector<int> black1 = cases[i][1];
		vector<int> black2 = cases[i][2];

		available = calculate_region(white[0], white[1], white[2], white[3]);
		//black 1 제거
		pair<pair<int,int>, pair<int,int>> black_union1 = get_union(white[0], white[1], white[2], white[3],
																	black1[0], black1[1], black1[2], black1[3]);
		if(black_union1.first.first != -1)
			available = available - calculate_region(black_union1[0], black_union1[1], black_union1[2], black_union1[3]);
		
		//black 2 제거
		pair<pair<int,int>, pair<int,int>> black_union2 = get_union(white[0], white[1], white[2], white[3],
																	black2[0], black2[1], black2[2], black2[3]);

		if(black_union2.first.first != -1)
			available = available - calculate_region(black_union2[0], black_union2[1], black_union2[2], black_union2[3]);
		//black 1과 2 교집합
		pair<pair<int,int>, pair<int,int>> black_union = get_union(black1[0], black1[1], black1[2], black1[3],
																	black2[0], black2[1], black2[2], black2[3]);

		if(black_union.first.first != -1)
			available = available - calculate_region(black_union[0], black_union[1], black_union[2], black_union[3]);



	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	vector<vector<vector<int>>> cases;
	for(test_case = 0; test_case < T; ++test_case)
	{
		vector<int> white(4), black1(4), black2(4);

		for( i = 0 ; i < 4 ; i++) cin >>white[i];
		for( i = 0 ; i < 4 ; i++) cin >>black1[i];
		for( i = 0 ; i < 4 ; i++) cin >>black2[i];
		cases[test_case] = {white, black1, black2};
	}

	is_white_or_black(cases, T);

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
