#ifndef Point__h
#define Point__h
#include <vector>
#include <iostream>
#include <fstream>



#ifndef Matrix
  #define Matrix std::vector<std::vector<int>>
#endif


class Point{      //Klassendeklaratin ( wie ist die Äußere Gestalt der KLasse )
public:
    Point(int x, int y, int index); //Kontruktor mit Übergabe von initialparametern
    Point();                        //Kontruktor welcher index, x,y mit 0 initialisiert
    double x;                     //Speicher für x Koordinate
    double y;                     //Speicher für y Koordinate
    bool arrived = false;         //bool ob Punkt bereits abgefahren wurde (wird nur in 2OPT genutzt)
    double distance (Point* otherPoint);  //berechnet die Distanz zu einem anderen, als Pointer übergebenen Punkts
    Point* PointWithMinDistance(std::vector<Point>& allPoints); //funktion die den Punkt in dem übergebenen Vektor
                                                                //mit der minimalen Distanz zu diesem Punkt ermittelt und als POinter zurückgibt
    int index;                  //speicher mitdem der Punkt "weis" an welcher stelle er im Globalen Vektor steht
};

void plotAllPoints(std::vector<Point> &allPoints, std::string filename);    //Schreibt den übergebenen Vektor aus Punkten in den angegeben Dateinamen CSV Kodiert
void plotPoint(std::ofstream& myFile, Point* pointToPlot, double distance); //Schreibt einen Punkt als Zeile csv Kodiert in geöffnete datein (übergeben als ofstream(outputFileStream))
void swapPoints(int index0, int index1, std::vector<Point> &allPoints);  //vertauscht 2 Punkte in einem Vektor
double calcDistanceInArray(std::vector<Point> &allPoints);  //berechnet den weg der abgeschritten werden muss um alle Punkte in einem Vektor der Reihe nach abzufahren und wieder zum Startpunbkt zurückzukehren
int random(int lowerbounds, int upperbounds);   //generiert eine zufallszahl welche im angegebenen bereich liegt
bool allPointsArrived(std::vector<Point>& allPoints); //überprüft ob alle punkte in einem vector abgefahren wurden

#endif
