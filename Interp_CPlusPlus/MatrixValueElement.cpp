////////////////////////////////////////////////////////////////////////
// MatrixValueElement.cpp: holds the data needed to represent an Matrix 
// values.
// version: 1.0
// author: Mahesh Uma Gudladona (ugudlado@syr.edu)
// language: C++/CLI
////////////////////////////////////////////////////////////////////////
#include "MatrixValueElement.h"
#include "Visitor.h"
#include <string>
#include <iostream>

void MatrixValueElement::Accept(Visitor * visitor){
  visitor->VisitMatrixValueElement(this);
}

std::string MatrixValueElement::getText() { 
  return mText; 
}

void MatrixValueElement::setText(std::string value) { 
  mText = value; 
  convertTextToMatrix(value);
}

void MatrixValueElement::convertTextToMatrix(std::string text){
	std::string temp=text;
	std::string row;
	int order=0;
	std::vector<int> rvalues;
	int i=1;
	for(i=1;temp.find(":")!=-1;i++){		
		row=temp.substr(0,temp.find(":")-1);
		rvalues=rowBuilder(row);
		if(order==0||rvalues.size()==order)
			order=rvalues.size();
		else {
			m.clear();
		    std::cout<<"\nInvalid Matrix Order";
			return;
		}				
		m.push_back(rvalues);
		temp.erase(0,temp.find(":")+1);
	}
	if(temp.find("}")==temp.length()-1){
		row=temp.substr(0,temp.find("}"));		
		rvalues=rowBuilder(row);
		if(order==0||rvalues.size()==order)
			order=rvalues.size();
		else {
			m.clear();
		    std::cout<<"\nInvalid Matrix Order";
			return;
		}	
		m.push_back(rvalues);
		temp.clear();
	}
}

std::vector<int> MatrixValueElement::rowBuilder(std::string row){
	std::vector<int> r;
	std::string temp;
	row.erase(0,1);
	row.erase(row.length(),1);
	for(int j=0;row.length()!=0;){
		if(row.find(",")!=-1){
			temp=row.substr(0,row.find(","));
			r.push_back(parseInt(temp));
			row.erase(0,row.find(",")+1);
		}
		else{
			r.push_back(parseInt(row));
			row.clear();
		}
	}
	return r;
}

std::vector<std::vector<int>> MatrixValueElement::getMatrix(){
	return m;
}
int MatrixValueElement::parseInt(std::string value){
   std::istringstream iss(value);
   int ret;
   iss >> ret;
   return ret;
}