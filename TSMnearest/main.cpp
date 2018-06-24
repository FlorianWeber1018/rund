#include "main.h"
#include "../Point.h"
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
	Points.push_back(Point(21,2,10));		//Punkte zu Vektor hinzufügen


	TSMnearest();	//Algorithmus spezifische Funktion aufrufen

	return 0;
}


void TSMnearest(){
	std::ofstream myfile;
  myfile.open ("TSMnearest.csv");								//Datei öffen/erstellen
	myfile << "x,y,index,distance" << std::endl;	//Überschriften von tabelle schreiben

	int first = 0;
	int start = 0;
	Point* temp = nullptr;
	double sum = 0;
	std::cout << "Please enter the start Number (0..10)";
	std::cin >> first;
	start = first;
	Points[start].arrived=true;
	plotPoint(myfile, &Points[start], 0);

	while(!allPointsArrived(Points)){														//TSM Algorithmus
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
