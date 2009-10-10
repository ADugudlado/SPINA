#include "Threads.h"
#include "locks.h"
#include<string>
#include<vector>


class AddThread : public Thread_Processing
{
public:
  AddThread* clone() const
  {
    return new AddThread(*this);   // applications must have this line, e.g.,
                                  // clone creating a copy of self
  }
  ~AddThread() { }
  AddThread(const AddThread& tp) 
  {
	  row1=tp.row1;
	  row2=tp.row2;
	  sum=tp.sum;
	  _str=tp._str;
    sout << locker << "\n  " << _str << unlocker;
  }
  AddThread(const std::string& str) 
  {
    sout << locker << "\n  " << _str << unlocker;
  }
  std::vector<int> returnSum(){
	  return sum;
  }
  void updateThread(std::vector<int> a,std::vector<int> b){
	 row1=a;
	 row2=b;
  }
  virtual void run()
  {
	  for(unsigned i=0;i<row1.size();i++){
		sum.push_back(row1[i]+row2[i]);			
	  }
  }
  
private:
  std::string _str;
  std::vector<int> row1,row2;
  int rowlength;
  std::vector<int> sum;
};

class MultiplyThread : public Thread_Processing
{
public:
  MultiplyThread* clone() const
  {
    return new MultiplyThread(*this);   // applications must have this line, e.g.,
                                  // clone creating a copy of self
  }
  ~MultiplyThread() { }
  MultiplyThread(const MultiplyThread& tp) 
  {
	  row=tp.row;
	  col=tp.col;
	  product=tp.product;
	  _str=tp._str;
    sout << locker << "\n  " << _str << unlocker;
  }
  MultiplyThread(const std::string& str) 
  {
    sout << locker << "\n  " << _str << unlocker;
  }
  int returnProduct(){
	  return product;
  }
  void updateThread(std::vector<int> a,std::vector<int> b){
	 row=a;
	 col=b;
  }
  virtual void run()
  {
	  product=0;
	  for(unsigned i=0;i<row.size();i++){
		 product+=row[i]*col[i];
	  }
  }
  
private:
  std::string _str;
  std::vector<int> row,col;
  int rowlength;
  int product;
};


