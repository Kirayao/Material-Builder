#include "Structure.h"
#include <fstream>

using namespace std;

Structure::Structure(int xlen = 10, int ylen = 10, int zlen = 10, int accu = 100): x(xlen), y(ylen), z(zlen), accuracy(accu)
{
  x*=accuracy; y*=accuracy; z*=accuracy;

  if ( ( substrate =(Material***) malloc( x * sizeof(Material) ) ) == NULL )
  {
    perror("malloc 1");
  }
  for (int i=0; i < x  ; ++i)
    substrate[i] = NULL;
    for (int i=0; i < x  ; ++i)
    {
      if ((substrate[i] = (Material**) malloc(y  * sizeof *substrate[i]) ) == NULL)
      {
	perror("malloc 2");
	  free_data(x, y);
      }
    }
  for (int i=0; i < x  ; ++i)
    {
    for (int j=0; j < y  ; ++j)
      substrate[i][j] = NULL;
      for (int i=0; i < x  ; ++i)
      {
	for (int j=0; j < y  ; ++j)
	{
	  if ((substrate [i][j] = (Material*) malloc(z * sizeof * substrate [i][j])) == NULL) {
	    perror("malloc 3");
	    free_data( x, y);
	  }
	}
      }
  }
  for (int i = 0; i < x; i++)
  {
    for(int j = 0; j < y; j++)
    {
      for(int k = 0; k < z; k++)
      {
	 substrate[i][j][k].permitivity = 3.9;
      }
    }
  }
}

Structure::~Structure()
{
  free_data(x,y);
}


Material Structure::retSubstrate(int px, int py, int pz)
{
  return this->substrate[px][py][pz];
}

Material*** Structure::retSubstrate()
{
  return this->substrate;
}

void Structure::printSubstrate()
{
  for (int i=0; i<x; i++)
  {
    for ( int j=0; j<y; j++)
    {
      for (int k=0; k<z;k++)
      {
	printf("%f %f %f %f\n", double(i)/accuracy , double(j)/accuracy , double(k)/accuracy , substrate[i][j][k].permitivity );
      }
    }
  }
}

void Structure::printSubstratetoFile(char*  path)
{
  fstream output;
  output.open(path, fstream::out | fstream::trunc);
  
  for (int i=0; i<x; i++)
  {
    for ( int j=0; j<y; j++)
    {
      for (int k=0; k<z;k++)
      {
	output << " " <<  double(i)/accuracy << " " <<  double(j)/accuracy << " " <<  double(k)/accuracy << " " << substrate[i][j][k].permitivity << endl;
      }
    }
  }
  output.close();
}



Structure& Structure::operator=(const Structure& other)
{
  return *this;
}

int Structure::addBall(int px, int py, int pz, int radius)
{
  for (int i = (px-radius)*accuracy; i <= (px+radius)*accuracy; i++)
  {
    for(int j = (py-radius)*accuracy; j <= (py+radius)*accuracy; j++)
    {
      for(int k = (pz-radius)*accuracy; k <= (pz+radius)*accuracy; k++)
      {
	//Ball function
	if ( pow(i-px,2)+pow(j-py,2)+pow(k-pz,2) <= pow(radius, 2) )
	  substrate[i][j][k].permitivity = 11.7;
      }
    }
  }
    return 0;
}

int Structure::addCube(int px, int py, int pz, int radius)
{
  for (int i = (px-radius)*accuracy; i <= (px+radius)*accuracy; i++)
  {
    for(int j = (py-radius)*accuracy; j <= (py+radius); j++)
    {
      for(int k = (pz-radius)*accuracy; k <= (pz+radius)*accuracy; k++)
      {
	substrate[i][j][k].permitivity = 11.7;
      }
    }
  }
    return 0;
}

void Structure::free_data(int xlen, int ylen)
{

  for (int i=0; i < xlen; ++i) {
    if (substrate[i] != NULL) {
      for (int j=0; j < ylen; ++j)
	free(substrate[i][j]);
      free(substrate[i]);

    }
  }
      free(substrate);
}
