#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include"Gaussian.h"
#include"Start.h"


	
	std::vector<std::vector< double > > Gaussian::solve(std::vector<std::vector< double> > mat) 
	{


	  std::vector<std::vector< double> > first_row_zeroed_mat;
	  std::vector<std::vector< double> > second_row_zeroed_mat;

	   std::vector< double > back_sub;
	//first caluclates multipliers 
	 first_row_zeroed_mat = reduce_first_col(mat);
         second_row_zeroed_mat = reduce_second_col(first_row_zeroed_mat);

	 // Print matrices

	//std::cout<<"Upper triangular matrix"<<std::endl;
	 print_mat(first_row_zeroed_mat);
	std::cout<<"\n";
	 std::cout<<"Upper triangular matrix"<<std::endl;

         //print_mat(second_row_zeroed_mat);
	std::cout<<"\n";


	 back_sub = back_substitution(second_row_zeroed_mat);
         return second_row_zeroed_mat;
       }

	std::vector<std::vector< double > > Gaussian::reduce_first_col(std::vector<std::vector< double > > mat) 
	{
	// Get amounts by which the second and third rows should be subtracted

	double row2_multiplier = mat.at(1).at(0) * -1;
        double row3_multiplier = mat.at(2).at(0) * -1;

	
	  //Modify mat to the updated version without zeroes
 	 //Row 2
 	 // first caluclates multipliers 
 	 //multipliers taks second rw from first column and negating it 

	mat.at(1).at(0) += row2_multiplier * mat.at(0).at(0);
	  mat.at(1).at(1) += row2_multiplier * mat.at(0).at(1);
 	 mat.at(1).at(2) += row2_multiplier * mat.at(0).at(2);
 	 mat.at(1).at(3) += row2_multiplier * mat.at(0).at(3);

  	// Row 3
	 mat.at(2).at(0) += row3_multiplier * mat.at(0).at(0);
 	 mat.at(2).at(1) += row3_multiplier * mat.at(0).at(1);
 	 mat.at(2).at(2) += row3_multiplier * mat.at(0).at(2);
  	mat.at(2).at(3) += row3_multiplier * mat.at(0).at(3);

 	 return mat;
	}

	std::vector<std::vector< double > > Gaussian::reduce_second_col(std::vector<std::vector< double > > mat) 
	{

	//row three and row second are in the simplest form
	// Get the row 3 multiplier



      // Add row3_multiplier * row2 to row3
     //second elementt in the second row and second element in third row multiplier and then multily each and add to the row
	double row3_multiplier = mat.at(2).at(1) / mat.at(1).at(1) * -1;
	 mat.at(2).at(0) += row3_multiplier * mat.at(1).at(0);
  	mat.at(2).at(1) += row3_multiplier * mat.at(1).at(1);
	  mat.at(2).at(2) += row3_multiplier * mat.at(1).at(2);
 	 mat.at(2).at(3) += row3_multiplier * mat.at(1).at(3);

 	 return mat;
	}

//mat is a 2d matrix outer loop controls the row and inner loop controls the column
//then after each loop it prints out a newline

	void Gaussian::print_mat(std::vector<std::vector< double> > mat) 
	{
  	for (unsigned i = 0; i < mat.size(); i++) {
    	for (unsigned j = 0; j < mat.at(i).size(); j++) {
      	std::cout << mat.at(i).at(j) << " ";
    	}

    	std::cout << std::endl;
  		}
	}
	
	std::vector<double> Gaussian::back_substitution(std::vector<std::vector< double > > mat) 
	{
        std::vector< double > xyz_values;
	
	// Declaring separate ints for x,y,z to make the process more explicit
	  double x,y,z;

	
 	 z = mat.at(2).at(3)/mat.at(2).at(2);
	 y = (mat.at(1).at(3) - (z * mat.at(1).at(2)))/mat.at(1).at(1);
	  x = (mat.at(0).at(3) - (z * mat.at(0).at(2)) - (y * mat.at(0).at(1)))/mat.at(0).at(0);

	std::cout << "x: " << x << std::endl;
	  std::cout << "y: " << y << std::endl;
 	 std::cout << "z: " << z << std::endl;
	std::cout<<"\n";
 	 xyz_values.push_back(x);
 	 xyz_values.push_back(y);
 	 xyz_values.push_back(z);

  	return xyz_values;
	}

