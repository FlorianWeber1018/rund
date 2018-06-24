#include "main.h"
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



Point::Point(int x, int y, int index)
{
	this->x = static_cast<double>(x);
	this->y = static_cast<double>(y);
	this->index = index;
}
Point::Point(){
	this->x = 0;
	this->y = 0;
	this->index = 0;
}
double Point::distance (Point* otherPoint){
	return sqrt(pow(this->x - otherPoint->x,2) + pow(this->y - otherPoint->y,2));
}
Point* Point::PointWithMinDistance(std::vector<Point> &allPoints){
	double lastDistance = 99999999999;
	Point* nearestPoint = nullptr;
	for(Point& actualPoint : allPoints){
		if(actualPoint.arrived == false){
			if(actualPoint.distance(this) < lastDistance){
				lastDistance = actualPoint.distance(this);
				nearestPoint = &actualPoint;
			}
		}
	}
	return nearestPoint;
}
void plotPoint(std::ofstream& myFile, Point* pointToPlot, double distance){
	myFile << pointToPlot->x << "," << pointToPlot->y << ","
	<< pointToPlot->index << "," << distance << std::endl;
}
void plotAllPoints(std::vector<Point> &allPoints, std::string filename){
	std::ofstream myfile;
  myfile.open (filename);
	myfile << "x,y,index,distance" << std::endl;
	double sum=0;
	double distance=0;
	bool firstRun=true;
	Point* lastPoint = nullptr;
	for(Point& actualPoint : allPoints){
		if(!firstRun){
			distance = actualPoint.distance(lastPoint);
			sum += distance;
		}
		firstRun=false;
		plotPoint(myfile, &actualPoint, distance);
		lastPoint = &actualPoint;
	}
	distance = allPoints[0].distance(lastPoint);
	plotPoint(myfile, &allPoints[0], distance);
	sum += distance;
	myfile << ",,Sum of Distance:," << sum << std::endl;
	myfile.close();
}
void swapPoints(int index0, int index1,std::vector<Point> &allPoints){
	Point temp;
	temp = allPoints[index0];
	allPoints[index0] = allPoints[index1];
	allPoints[index1] = temp;
}
double calcDistanceInArray(std::vector<Point> &allPoints){
	double sum=0;
	double distance=0;
	bool firstRun=true;
	Point* lastPoint = nullptr;
	for(Point& actualPoint : allPoints){
		if(!firstRun){
			distance = actualPoint.distance(lastPoint);
			sum += distance;
		}
		firstRun = false;
		lastPoint = &actualPoint;

	}
	distance = allPoints[0].distance(lastPoint);
	sum += distance;
	return sum;
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
int random(int lowerbounds, int upperbounds)
{
   	return lowerbounds + std::rand() % (upperbounds - lowerbounds + 1);
}
