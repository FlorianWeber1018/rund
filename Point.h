#ifndef Point__h
#define Point__h




#ifndef Matrix
  #define Matrix std::vector<std::vector<int>>
#endif


class Point{      //Klassendeklaratin ( wie ist die Äußere Gestalt der KLasse )
public:
    Point(int x, int y, int index); //Kontruktor mit Parameterb
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
int random(int lowerbounds, int upperbounds);
bool allPointsArrived(std::vector<Point>& allPoints);

#endif
