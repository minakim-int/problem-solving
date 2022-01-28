/* 
 * https://www.acmicpc.net/problem/2493
 * input: numbers of towers
 * output: the number of tower which one tower catches the signal from.
 */

#include <iostream>
#include <stack>

using namespace std;
int main(){
	int N;
	scanf("%d", &N);
	int* tower = new int[N];
	stack<pair<int, int>>h; //stack includes the towers which have the chance of being answer
	int input;
	scanf("%d", &tower[0]);
	printf("0 "); //first tower never met the other tower
	h.push({1, tower[0]});
  
	for(int i=1; i<N; i++){
		scanf("%d", &input);
		if(h.top().second<input){
			while(!h.empty()&&h.top().second<input) //input is taller than current tallest tower
				h.pop(); //pop until meeting tallest tower
			if(h.empty()) printf("0 "); //there's no tower
			else printf("%d ", h.top().first); //meet a tower
			h.push({i+1, input}); //push current input
		}
		else{ //input is shorter than current tallest tower
			printf("%d ", h.top().first); //answer is current tallest tower
			h.push({i+1, input});
		}
		tower[i] = input;
	}
}
