#pragma once
#include <vector>
using namespace std;
class IoClass
{
  public:
	vector<vector<double> >featureMat;
        vector<vector<double> >outputMat;
        vector<vector<double> >weightMat;
        double learningRate;
        int noOfIter;
	double convTol;
  public :
	void getData();
	vector<vector<double> > getFeatureMatrix();
	vector<vector<double> > getOutputMatrix();
	vector<vector<double> > getWeightMatrix();
	double getLearningRate();
	int    getNoOfIteration();
	double getConvTol();
};
