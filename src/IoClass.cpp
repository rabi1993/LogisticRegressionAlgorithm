#include <iostream>
#include "include/IoClass.h"
#include <string>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;

//Variable declaration
vector<string> result,result1,result2,res;
vector<double> f_mat;
vector<double> out;
vector<vector<double> > outputMatrix;
vector<vector<double> > featureMatrix;
vector<double> wt;
vector<vector<double> > weightMatrix;
ifstream nameFileout;
string line;
int i=0,j=0,k=0,l=0,m=0,n=0;

/**
This function reads Feature Matrix from file
and return 2D vector of this Matrix
*/
vector<vector<double> >IoClass::getFeatureMatrix()
	{
	nameFileout.open("inputFile.txt");
	while(std::getline(nameFileout, line))
		{
		if(line.compare(0,4,"----" )  ==0 && i==0)
			{
			i++;
			continue;
			}
			if(i==1)
			{	
				if(line.compare(0,4,"----" )  ==0)
					break;
       				boost::split(result1, line, boost::is_any_of(" "));
       				for(std::vector<int>::size_type i = 0; i != result1.size(); i++)
        			{
          				string str = result1[i];
          				if (str.length()!=0)
          					{
            					double dd = stod(str);
						f_mat.push_back(dd);
          					}
        			}
				//Converting f_mat in to 2D vactor 
				featureMatrix.push_back(f_mat);		
				f_mat.clear();
                        }
		}
	nameFileout.close();	
	return featureMatrix;
	}

/**
This function reads initial Output Matrix from file 
and returns 2D vector of this Matrix
*/

vector<vector<double> >IoClass::getOutputMatrix()
        {
        nameFileout.open("inputFile.txt");
        while(std::getline(nameFileout, line))
                {
                if(line.compare(0,4,"----" )  ==0 && j==0)
                        {
                        j++;
                        continue;
                        }
		if(line.compare(0,4,"----" )  ==0 && j==1)
                        {
                        j++;
                        continue;
                        }

                        if(j==2)
                        {	if(line.compare(0,4,"----" )  ==0)
                                        break;
                                boost::split(result, line, boost::is_any_of(" "));
                                for(std::vector<int>::size_type i = 0; i != result.size(); i++)
                                {
                                        string str = result[i];
                                        if (str.length()!=0)
                                                {
                                                double dd = stod(str);
                                                out.push_back(dd);
                                                }
                                }
                        //Converting f_mat in to 2D vactor 
                        outputMatrix.push_back(out);
                        out.clear();
                        }
                  }
	nameFileout.close();
	return outputMatrix;
        } 

/**
This function reads initial weight matrix from file 
and return 2D vector for this matrix
*/

vector<vector<double> >IoClass::getWeightMatrix()
        {
        nameFileout.open("inputFile.txt");
        while(std::getline(nameFileout, line))
                {
                if(line.compare(0,4,"----" )  ==0 && k==0)
                        {
                        k++;
                        continue;
                        }
                if(line.compare(0,4,"----" )  ==0 && k==1)
                        {
                        k++;
                        continue;
                        }
                if(line.compare(0,4,"----" )  ==0 && k==2)
                        {
                        k++;
                        continue;
                        }
                        if(k==3)
                        {       if(line.compare(0,4,"----" )  ==0)
                                        break;
                                boost::split(result2, line, boost::is_any_of(" "));
                                for(std::vector<int>::size_type i = 0; i != result2.size(); i++)
                                {
                                        string str = result2[i];
                                        if (str.length()!=0)
                                                {
                                                double dd = stod(str);
                                                wt.push_back(dd);
                                                }
                                }
                                weightMatrix.push_back(wt);
                                wt.clear();
                        }
                }
        nameFileout.close();
        return weightMatrix;
        }

/**
This Function reads learning rate from file
and returns it in double datatype
*/
double IoClass::getLearningRate()
	{
	double learnRate;
	nameFileout.open("inputFile.txt");
        while(std::getline(nameFileout, line))
                {
                	if(line.compare(0,4,"----" )  ==0 && l==0)
                        {
                        l++;
                        continue;
                        }
			if(line.compare(0,4,"----" )  ==0 && l==1)
                        {
                        l++;
                        continue;
                        }
			if(line.compare(0,4,"----" )  ==0 && l==2)
                        {
                        l++;
                        continue;
                        }
			if(line.compare(0,4,"----" )  ==0 && l==3)
                        {
                        l++;
                        continue;
                        }
			if(l==4)
			{
				if(line.compare(0,4,"----" )  ==0)
                                        break;
				learnRate = stod(line);
			}
		}
	nameFileout.close();
	return learnRate;
	}
	
/**
This Function reads number of Iteration from file and returns it in integer datatype
*/

int IoClass::getNoOfIteration()
	{
	int noOfIteration;
	nameFileout.open("inputFile.txt");
        while(std::getline(nameFileout, line))
                {
                	if(line.compare(0,4,"----" )  ==0 && m==0)
                        {
                        m++;
                        continue;
                        }
			if(line.compare(0,4,"----" )  ==0 && m==1)
                        {
                        m++;
                        continue;
                        }
			if(line.compare(0,4,"----" )  ==0 && m==2)
                        {
                        m++;
                        continue;
                        }
			if(line.compare(0,4,"----" )  ==0 && m==3)
                        {
                        m++;
                        continue;
                        }
			if(line.compare(0,4,"----" )  ==0 && m==4)
                        {
                        m++;
                        continue;
                        }
			if(m==5)
			{
                                if(line.compare(0,4,"----" )  ==0)
                                        break;
                                noOfIteration = stoi(line);
                        }
                }
        nameFileout.close();
	return noOfIteration;
	}
/**
This function reads convergence tolerance from file and returns this in double data structure 
*/
double IoClass::getConvTol()
	{
	double tolerance;
	nameFileout.open("inputFile.txt");	
        while(std::getline(nameFileout, line))
                {
                        if(line.compare(0,4,"----" )  ==0 && n==0)
                        {
                        n++;
                        continue;
                        }
                        if(line.compare(0,4,"----" )  ==0 && n==1)
                        {
                        n++;
                        continue;
                        }
                        if(line.compare(0,4,"----" )  ==0 && n==2)
                        {
                        n++;
                        continue;
                        }
                        if(line.compare(0,4,"----" )  ==0 && n==3)
                        {
                        n++;
                        continue;
                        }
                        if(line.compare(0,4,"----" )  ==0 && n==4)
                        {
                        n++;
                        continue;
                        }
			if(line.compare(0,4,"----" )  ==0 && n==5)
                        {
                        n++;
                        continue;
                        }
                        if(n==6)
                        {
                                if(line.compare(0,4,"----" )  ==0)
                                        break;
                                tolerance  = stod(line);
                        }
		}
		nameFileout.close();
        	return tolerance;
                                                     
	}



/** 
 This function reads each input from file and returns 
*/

void IoClass::getData()
	{          
	IoClass io;
	this->featureMat =  this->getFeatureMatrix();
	this->outputMat =  this->getOutputMatrix();
       	this->weightMat =  this->getWeightMatrix();
	this->learningRate = this->getLearningRate();
	this->noOfIter = this->getNoOfIteration();
	this->convTol = this->getConvTol();
	//cout << "Value of Tolerance is " << endl<< io.convTol<<endl;
	}

