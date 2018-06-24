#include "Point.h"
#include <map>
#include <math.h>
#include <limits.h>
#include <cstdlib>
#include <time.h>






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





//UTIL FX

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
int random(int lowerbounds, int upperbounds)
{
   	return lowerbounds + std::rand() % (upperbounds - lowerbounds + 1);
}
bool allPointsArrived(std::vector<Point> &allPoints){
	for(Point& actualPoint : allPoints){
		if(actualPoint.arrived == false){
			return false;
		}
	}
	return true;
}
