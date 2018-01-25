#include <iostream>
#include <string>
#include "include/ProcessData.h"
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
using namespace std;

void ProcessData::process(IoClass io)
	{
		vector<vector<double> > weightMat=io.weightMat;
		vector<vector<double> > featureMat=io.featureMat;
		vector<vector<double> > outputMat = io.outputMat;
		double learningRate = io.learningRate;	
		double rmsValue;
		int noOfIter = io.noOfIter;
		double convTolerance = io.convTol;
		for(int i = 0 ; i < noOfIter ; i++ )
		
			{	
			vector<vector<double> >transposeMat = findTranspose(weightMat); 
			vector<vector<double> >mulResult = matrixMultiply( featureMat , transposeMat );
			vector<vector<double> > transposeOutput =  findTranspose(outputMat);
			vector<vector <double> > intermediateResult = calculateHypoMinusOpt(mulResult,transposeOutput);
			vector<vector <double> > afterFeatureMulti = mulWithFeature( featureMat , intermediateResult );
			vector<vector<double > > updatedWeight = findUpdatedWeight(afterFeatureMulti , weightMat , learningRate);
			rmsValue = calculateRMS ( weightMat , updatedWeight );
			cout<<endl<<"rms"<<rmsValue<<endl;	
			if(rmsValue <= convTolerance )
				{	
					cout<<endl<<"You have reached to Optimized result before executing loop" <<"\t"<<(noOfIter-i)<<"\t"					              <<"times fewer than the given value"<<endl<<"And Optimized Result is"<<endl ;
					showOutput(updatedWeight );
					break;
				}
			weightMat = updatedWeight;
			cout<<endl<<endl<<"------------->"<< "\t"<<"Updated Weight Vactor"<<"\t" <<"after"<<"  "<< (i+1) <<" " <<"times optim"			      "zation"<<"\t"<<"<----------------"<<endl;
			showOutput( updatedWeight  );
			}
	
	}

/**
This function takes 2D vector as parameter and returns it transpose 
*/

vector <vector <double> > ProcessData::findTranspose(vector<vector <double> > input )
	{
	       	vector <vector <double> > output( input[0].size() , vector<double> (input.size() ) ) ;
		for(std::vector<int>::size_type i = 0;i !=input.size();i++)
		{	
			for(std::vector<int>::size_type j = 0; j !=input[i].size() ; j++)
			{
			output[j][i] = input[i][j];
			}
		}
	return output;
	}
/**
This function takes two 2D vectors as parameter and returns multiplication of these vectors in 2D vector
*/
vector<vector<double> > ProcessData::matrixMultiply(vector<vector <double>> inputA , vector<vector<double> > inputB )
	{
		vector <vector <double> >result;
		result.resize(inputA.size());
		for(std::vector<int>::size_type i = 0 ; i != inputA.size() ; i++)
		{      
			result[i].resize(inputB[0].size());
			for(std::vector<int>::size_type j = 0 ; j != inputB[0].size(); j++)
			{
				result[i][j] = 0;
				for(std::vector<int>::size_type k = 0 ; k != inputB.size() ; k++)
				{
					result[i][j] += inputA[i][k] * inputB[k][j];
				}	
			}
		}
		
	return result;	
	}
/**
This function takes two 2D vectors , one is output matrix and other is returned matrixMultiply() function.
This function also returns calcutaltion 2D vector ( of hypothesis minus output vector )
*/
vector<vector<double> > ProcessData::calculateHypoMinusOpt(vector<vector <double> > multipliedVec, vector<vector<double> > outputVec )
	{
		vector<vector<double> > result;
		result.resize(multipliedVec.size());
		for(std::vector<int>::size_type i = 0 ; i != multipliedVec.size() ; i++)
		{  
			result[i].resize( multipliedVec[0].size() );
			for(std::vector<int>::size_type j = 0 ; j != multipliedVec[0].size(); j++)
				{
					result[i][j] =  1 / ( 1 + exp( -(multipliedVec[i][j]) ) ) ;
					result[i][j] = result[i][j] - outputVec[i][j];
				}
		}	
		return result;
	}
/**
This function takes feature matrix and intermediate result matrix (output of calculateHypoMinusOpt() function)
and returns multiplication of feature with corresponding row of intermediate result matix 
*/
vector<vector<double> > ProcessData::mulWithFeature(vector<vector <double> > featureMat , vector<vector<double> > interResult)
	{	
		vector<vector<double> >result;
		result.resize(featureMat.size() );
		for(std::vector<int>::size_type i = 0 ; i != featureMat.size() ; i++)
		{  
			result[i].resize( featureMat[0].size() );
			for(std::vector<int>::size_type j = 0 ; j != featureMat[0].size(); j++)
				{
					result[i][j]  = ( featureMat[i][j] ) * (interResult[i][0]);
				}
		}
		return result;
	}
/**
This function takes two matrices and learning rate as parameter . First matrix is output of mulWithFeature() function 
and second is weight vector .
The function calculates sum of each column of first matrix and finally updates weight vector by multiplying with 
learning rate.
*/
vector<vector<double> > ProcessData::findUpdatedWeight( vector<vector <double> > mulFeature ,vector<vector<double> > weight, double learningRate )
	{
		vector<vector<double> > result;
		double sum = 0.0000,tempResult;
		int sizeOfArray=0;
		double colInterSum[1000];
		for(std::vector<int>::size_type j = 0 ; j != mulFeature[0].size() ; j++)
		{  
			for(std::vector<int>::size_type i = 0 ; i != mulFeature.size(); i++)
				{
					sum  = sum + mulFeature[i][j] ;
				}	
				colInterSum[j] = sum;
				sizeOfArray++;
				sum = 0.0000;
		}
		result.resize(1);
		for(std::vector<int>::size_type i = 0 ; i != 1; i++)
		{  
			result[i].resize( mulFeature[0].size() );
			for(std::vector<int>::size_type j = 0 ; j != mulFeature[0].size(); j++)
			{
				result[i][j] = weight[i][j] - ( colInterSum[j] * learningRate );
			}
		return result;
		}
	}

/**
This function takes a updates weight vector and shows it as output 
*/	
void ProcessData::showOutput( vector<vector<double> > weightMat )
	{
		for(std::vector<int>::size_type i = 0 ; i != weightMat.size() ; i++)
			{  
				for(std::vector<int>::size_type j = 0 ; j != weightMat[i].size(); j++)
				{
					cout <<weightMat[i][j]<<" ";
				}	
				cout << endl;
			}
	}
/**
This function calculates RMS error for weight vectors taken as parameter and retutns RMS in double data structure
*/

double ProcessData::calculateRMS(  vector<vector <double> > weightMat , vector <vector <double> > updatedWeight )
	{
		 double temp=0 , rms= 0.00 ;
		 for(std::vector<int>::size_type i = 0 ; i != weightMat.size() ; i++)
                        {
                                for(std::vector<int>::size_type j = 0 ; j != weightMat[i].size(); j++)
                                {	
					temp = temp + pow (  ( updatedWeight[i][j] - weightMat[i][j] ) , 2 );	
				}
			}
		 rms = sqrt(temp);
		 return rms;
	}




