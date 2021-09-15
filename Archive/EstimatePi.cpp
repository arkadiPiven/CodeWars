#include <time>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>


bool InsideCircle(double x, double y){
	if(pow(x - 0.5,2) + pow(y - 0.5,2) < 1/4) return true;
	return false;
}


int main(){
	int InsideCircle;
	double x;
	double y;
	srand(time(NULL));
	for(int i = 0; i < 1000; ++i){
		x = ((double)rand())/((double)RAND/MAX);
		y = ((double)rand())/((double)RAND/MAX);
		if(InsideCircle(x,y)) InsideCircle++;
	}
	return (InsideCircle/100) * 4;
}