#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <limits.h>


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


	TSMnearest();

	return 0;
}



Point::Point(int x, int y, int index)
{
	this->x = static_cast<double>(x);
	this->y = static_cast<double>(y);
	this->index = index;
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
bool allPointsArrived(std::vector<Point> &allPoints){
	for(Point& actualPoint : allPoints){
		if(actualPoint.arrived == false){
			return false;
		}
	}
	return true;
}
void TSMnearest(){
	std::ofstream myfile;
  myfile.open ("TSMnearest.csv");
	myfile << "x,y,index,distance" << std::endl;

	int first=0;
	int start=0;
	Point* temp = nullptr;
	double sum = 0;
	std::cout << "Please enter the start Number (0..10)";
	std::cin >> first;
	start = first;
	Points[start].arrived=true;
	plotPoint(myfile, &Points[start], 0);
	while(!allPointsArrived(Points)){
		temp  =  Points[start].PointWithMinDistance(Points);
		plotPoint(myfile, temp, Points[start].distance(temp));
		temp->arrived=true;
		sum += Points[start].distance(temp);
		start = temp->index;
	}
	temp = &Points[first];
	plotPoint(myfile, temp, Points[start].distance(temp));
	sum += Points[start].distance(temp);

	myfile << ",,Sum of Distance:," << sum << std::endl;
	myfile.close();
}
