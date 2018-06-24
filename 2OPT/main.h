#ifndef main__h
#define main__h
#include <vector>
#include <iostream>
#include <fstream>
class Point{
public:
    Point(int x, int y, int index);
    Point();
    double x;
    double y;
    bool arrived = false;
    double distance (Point* otherPoint);
    Point* PointWithMinDistance(std::vector<Point>& allPoints);
    int index;
};
void plotAllPoints(std::vector<Point> &allPoints, std::string filename);
void plotPoint(std::ofstream& myFile, Point* pointToPlot, double distance);
void swapPoints(int index0, int index1,std::vector<Point> &allPoints);
double calcDistanceInArray(std::vector<Point> &allPoints);
void doTheShit(std::vector<Point> &allPoints, int cnt);
int random(int lowerbounds, int upperbounds);
#endif
