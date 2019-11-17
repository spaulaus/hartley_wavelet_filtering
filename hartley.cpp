#include <math.h>
#include <vector>
#include <stdio.h>
#include <complex.h>
#include <iostream>
#include <fstream>

using namespace std;

#define N 100
#define PI 3.141592654

int main()
{

  vector<double> instuff(N), outstuff(N);
  double a=0, b=0, c=0;
  double alpha, beta, gamma;

  for(a=0; a < N; a++)
    {
      instuff[a] = 0;
      outstuff[a] = 0;
    }

  ifstream inputFile;
  inputFile.open ("trace_start.txt");
  
  for( a=0; a < N; a++)
    inputFile >> instuff[a];

  inputFile.close();
    

  for(b=0; b < N; b++)
    {
      alpha = -(2*PI*b)/N;

      for(c=0; c < N; c++)
	{
	  beta = alpha*c;
	  
	  outstuff[b] += instuff[c]*(cos(beta) + sin(beta));
	}
    }
      
  for(a=0; a < N; a++)
    {
      cout << instuff[a] << "  " << outstuff[a] << endl;
    }
  
  return 0;
}
