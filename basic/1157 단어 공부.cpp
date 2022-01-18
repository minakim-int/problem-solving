/*
 * from https://www.acmicpc.net/problem/1157
 * print the most used alphabet with capital letter from input word
 * if there is various answer, print "?"
*/

#include <iostream>
#include <vector>

using namespace std;

std::vector<int>vec(26,0);

int main(){
	char str[1000001];
	scanf("%s", str);
	int x = 0;
	while(str[x] != '\0'){ //store frequency of each alphabet used in input word
		if(str[x]>=97){ //vec[ASCII code] = frequency
			vec[str[x]-97]++;
		}
		else{
			vec[str[x]-65]++;
		}
		x++;
	}
	int max=vec[0];
	int max_idx = 0;
	bool same = false;
  //find the most frequency
	for(int i=1; i<26; i++){
		if(max<vec[i]){
			max = vec[i];
			max_idx = i;
			same = false;
		}
		else if(max == vec[i]){ //same frequency
			same = true;
		}
	}
	if(same){
		printf("?");
	}
	else{
		printf("%c", max_idx+65);
	}
	return 0;
}
