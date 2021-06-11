#ifndef START_H_EXISTS
#define START_H_EXISTS

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Gaussian.h"


//3 rows and four coulmns 

class Gaussian;

class Start{
	
private:
	
	int num_equations_;
	std::vector<std::vector<double> >donemat_;
	Gaussian* gauss_;
	std::vector< std::vector< double > > input_mat_;

public:
	Start();	
	void  readmatrix();	
	void solve_equations(int method);
	~Start();

};
#endif

