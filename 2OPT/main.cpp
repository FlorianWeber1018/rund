#include "main.h"
#include "../Point.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <limits.h>
#include <cstdlib>
#include <time.h>
std::vector<Point> Points;


int main(){
	Points.push_back(Point(2,23,0));
	Points.push_back(Point(9,26,1));
	Points.push_back(Point(12,20,2));
	Points.push_back(Point(18,24,3));
	Points.push_back(Point(26,33,4));
	Points.push_back(Point(42,23,5));
	Points.push_back(Point(31,15,6));
	Points.push_back(Point(30,15,7));
	Points.push_back(Point(35,10,8));
	Points.push_back(Point(19,7,9));
	Points.push_back(Point(21,2,10));

	std::srand(time(0));

	plotAllPoints(Points,"before.csv");

	doTheShit(Points, 1000000);

	plotAllPoints(Points,"after.csv");
	return 0;
}




void doTheShit(std::vector<Point> &allPoints, int cnt){
	if (cnt<0) return;
	for (int i = 0; i < cnt; i++){
		int num0 = random(0,10);
		int num1 = random(0,10);
		double distance = calcDistanceInArray(allPoints);
		swapPoints(num0, num1, allPoints);
		if( calcDistanceInArray(allPoints) > distance ){
			swapPoints(num0, num1, allPoints);
		}
	}
}
