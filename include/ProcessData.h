#include "include/IoClass.h"
#include <vector>
using namespace std;
class ProcessData
	{
	public: 
		void process(IoClass);
		vector<vector<double> > findTranspose(vector<vector<double> >);
		vector<vector<double> > matrixMultiply(vector<vector <double> > , vector<vector<double> >  );
		vector<vector<double> > calculateHypoMinusOpt(vector<vector <double> > , vector<vector<double> > );
		vector<vector<double> > mulWithFeature(vector<vector <double> > , vector<vector<double> > );
		vector<vector<double> > findUpdatedWeight( vector<vector <double>> ,vector<vector<double> >,double);
		void showOutput(vector<vector<double> >);
		double calculateRMS(vector<vector <double> > ,vector<vector<double> >);
	
	};
