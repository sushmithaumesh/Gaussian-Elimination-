#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<vector>
#include<cmath>
#include"Gaussian.h"
#include"Start.h"


	//default constructor
	Start::Start()
	{
	  num_equations_ = 0;
	  gauss_ = new Gaussian();
	

	// clear simply "clears" a vector, and ensures you will be starting
	//with an empty vector
	  donemat_.clear();
	  input_mat_.clear();
	}



	void Start::readmatrix()
	{
	  double first_element;
	  double second_element;
	  double third_element;
	  double fourth_element;

	  std::cout << "number of equations to be used is 3 enter 3: " << std::endl;
	  std::cin >> num_equations_;

	 // continually prompt user until input matrix is filled
	for (int i = 0; i < num_equations_; i++) {
	    std::vector< double > mat_row;

	//asks the 1st element each time  it has new vector
	 std::cout << "Enter the [" << i << "][0] element: " << std::endl;
            std::cin >> first_element;
	    mat_row.push_back(first_element);
	    std::cout << "Enter the [" << i << "][1] element: " << std::endl;
	    std::cin >> second_element;
	    mat_row.push_back(second_element);
	    std::cout << "Enter the [" << i << "][2] element: " << std::endl;
	    std::cin >> third_element;
	    mat_row.push_back(third_element);
	    std::cout << "Enter the [" << i << "][3] element: " << std::endl;
	    std::cin >> fourth_element;
	    mat_row.push_back(fourth_element);
	    input_mat_.push_back(mat_row);
	  }  // input matrix is full
	}


	void Start::solve_equations(int method) 
	{

	std::cout<<"SOLVING SYSTEM OF EQUATIONS"<<std::endl;

	std::cout<<"\n";
	std::cout<<"solving the equation by Gaussian elimination"<<std::endl;
	std::cout<<std::endl;
	  readmatrix();
	  std::vector<std::vector< double > > upper_triangular_mat;

	  //if method is zero
	   if (method == 0) {
	 std::cout<<"\n";
	  upper_triangular_mat = gauss_->solve(input_mat_);
	  } else if (method == 1) 
	{

	// If other solving methods were implemented, this is where they would be called
	   }

	// Print upper triangular
	 for (unsigned i = 0; i < upper_triangular_mat.size(); i++) {
   	 for (unsigned j = 0; j < upper_triangular_mat.at(i).size(); j++) {

	
     	 std::cout << upper_triangular_mat.at(i).at(j) << " ";
    	}

    	std::cout << std::endl;
  	}
	}

	Start::~Start()
	{
	delete(gauss_);
	

	}


