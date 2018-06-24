#ifndef main__h
#define main__h
#include <vector>
#include <iostream>
#include <fstream>
#define Matrix std::vector<std::vector<int>>
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
double calcDistanceInArray(std::vector<Point> &allPoints);
void doTheShit(std::vector<Point> &allPoints, Matrix &transMtx);
void genTransMtx(Matrix &mtx);
bool duplicatedValuesPresent(std::vector<int> &target);
int countMatchingElementsInVector(std::vector<int> &target, int cmpValue);
#endif
