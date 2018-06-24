#ifndef main__h
#define main__h
#include <vector>
#include <iostream>
#include <fstream>
class Point{
public:
    Point(int x, int y, int index);
    double x;
    double y;
    bool arrived = false;
    double distance (Point* otherPoint);
    Point* PointWithMinDistance(std::vector<Point>& allPoints);
    int index;
};
void plotPoint(std::ofstream& myFile, Point* pointToPlot, double distance);
bool allPointsArrived(std::vector<Point>& allPoints);

void TSMnearest();

#endif