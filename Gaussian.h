#ifndef GAUSSIAN_H_EXISTS
#define GAUSSIAN_H_EXISTS

#include<iostream>
#include<vector> 
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include"Start.h"


class Gaussian{

public:

	//Gaussian();
	std::vector<std::vector< double > > solve(std::vector<std::vector< double> >);

	//function which calls all the other functions
		
	// This function takes in a 3 by 4 matrix and returns the same matrix
	//but with the first column zeroed out
	 std::vector<std::vector< double > > reduce_first_col(std::vector<std::vector< double > >);

	// This function takes in a 3 by 4 matrix and returns the same matrix
	//  but with the second column zeroed out
	std::vector<std::vector< double > > reduce_second_col(std::vector<std::vector< double > >);

	// Produces an identical copy of the input matrix so the original
	//  won't be modified. This assumes mat is a 3 by 4 2D vector to simplify
	// things
	//Prints the input matrix
	void print_mat(std::vector<std::vector< double> >);
	// Performs backsubstitution an input matrix. The input matrix is assumed to
	//  be in upper triangular form
	// Returns a vector of the values for x,y, and z. The first element is the
	// value for x, the second is the value for y, and the third is the value for z
	// The input matrix is also assumed to be 3 by 4


	 std::vector<double> back_substitution(std::vector<std::vector< double > >);


};
#endif 


