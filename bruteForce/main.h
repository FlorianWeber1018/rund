#ifndef main__h
#define main__h
#ifndef Matrix
  #define Matrix std::vector<std::vector<int>>
#endif
#include <vector>
#include <iostream>
#include <fstream>
#include "../Point.h"


void doTheShit(std::vector<Point> &allPoints, Matrix &transMtx);
void genTransMtx(Matrix &mtx);

#endif
