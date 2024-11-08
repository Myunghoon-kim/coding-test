#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> dragons(n + 1 ,0);
	vector<int> dragons_no_egg(n + 1 ,0);
	vector<int> eggs(n + 1 ,0);
	
	if( n == 0 || n == 1) {
		cout << "1\n";
		return 1;
	}
	
	eggs[0] = 1;
	eggs[1] = 1;

	for(int day = 2 ; day <= n ; day++) {
		if(day > 5) {
			if(dragons[day - 4] == dragons[day - 5])
				dragons_no_egg[day] = dragons[day - 4] + dragons_no_egg[day - 1];
			else 
				dragons_no_egg[day] = dragons[day - 4] - dragons[day - 5]  + dragons_no_egg[day - 1];
		}

		
		//  오늘의 드래곤의 수는 어떻게 결정이 되는가? 
		//  이틀 전에 낳았던 알에서 깨어나고, 그 전날 드래곤 수와 더하면 되는거 아닌가?
		//  이틀 전에 낳았다는건 어떻게 알 수 있나? 이틀 전에 드래곤의 수가 이틀 전에 낳은 알이 아닌가?
		if(day == 2)
			dragons[day] = 1;
		else 	
			dragons[day] = dragons[day - 1] + dragons[day - 2] - dragons_no_egg[day];


		eggs[day] = dragons[day] + dragons[day -1];


		cout <<"dragon[" << day<< "]  :: " << dragons[day] << "\n";
		cout <<"eggs[" << day<< "]  :: " << eggs[day] << "\n";
		cout <<"dragon_no_egg[" << day<< "]  :: " << dragons_no_egg[day] << "\n\n";
	}
	cout << dragons[n] +  dragons_no_egg[n] + eggs[n] << "\n";
	return 0;
}
