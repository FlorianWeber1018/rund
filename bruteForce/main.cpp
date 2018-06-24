#include "main.h"
#include "../Point.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <limits.h>
#include <cstdlib>
#include <time.h>





std::vector<Point> Points;
Matrix transMtx;
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

	genTransMtx(transMtx);
	doTheShit(Points, transMtx);


	return 0;
}




void doTheShit(std::vector<Point> &allPoints, Matrix &transMtx){
	std::vector<int> bestTrans = transMtx[0];
	double bestDistance=999999999999;
	double actualDistance=0;
	std::vector<Point> tempPoints(11);
	for(std::vector<int> &transVec : transMtx){				//versuche jede Transformation
		for(int i=0; i<11;i++){									//vollzieht aktuelle transformation
			tempPoints[i]=allPoints[transVec[i]];
		}
		actualDistance=calcDistanceInArray(tempPoints);
		if(actualDistance<bestDistance){		//transformation besser als die aktuell beste?
			bestDistance=actualDistance;
			bestTrans = transVec;
		}
	}
	for(int i=0; i<11;i++){				//vollzieht beste transformation
		tempPoints[i]=allPoints[bestTrans[i]];
	}
	plotAllPoints(tempPoints, "bestResultBruteforce.csv");
}
void genTransMtx(Matrix& mtx){
	for(int a=0;a < 11; a++){
		for(int b=0;b < 11; b++){
			if(b==a){
				continue;
			}
			for(int c=0;c < 11; c++){
				if(c==a || c==b){
					continue;
				}
				for(int d=0;d < 11; d++){
					if(d==a || d==b || d==c){
						continue;
					}
					for(int e=0;e < 11; e++){
						if(e==a || e==b || e==c || e==d){
							continue;
						}
						for(int f=0;f < 11; f++){
							if(f==a || f==b || f==c || f==d || f==e){
								continue;
							}
							for(int g=0;g < 11; g++){
								if(g==a || g==b || g==c || g==d || g==e || g==f){
									continue;
								}
								for(int h=0;h < 11; h++){
									if(h==a || h==b || h==c || h==d || h==e || h==f || h==g){
										continue;
									}
									for(int i=0;i < 11; i++){
										if(i==a || i==b || i==c || i==d || i==e || i==f || i==g || i==h){
											continue;
										}
										for(int j=0;j < 11; j++){
											if(j==a || j==b || j==c || j==d || j==e || j==f || j==g || j==h || j==i){
												continue;
											}
											for(int k=0;k < 11; k++){
												if(k==a || k==b || k==c || k==d || k==e || k==f || k==g || k==h || k==i || k==j){
													continue;
												}
												std::vector<int> tempRow;
												tempRow.push_back(a);
												tempRow.push_back(b);
												tempRow.push_back(c);
												tempRow.push_back(d);
												tempRow.push_back(e);
												tempRow.push_back(f);
												tempRow.push_back(g);
												tempRow.push_back(h);
												tempRow.push_back(i);
												tempRow.push_back(j);
												tempRow.push_back(k);

												mtx.push_back(tempRow);

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
