#include "Structure.h"

Structure::Structure()
{

}

Structure::Structure(const Structure& other)
{

}

Structure::~Structure()
{

}

Structure& Structure::operator=(const Structure& other)
{
return *this;
}

int Structure::addBall(int px, int py, int pz, int radius)
{
  for (int i = (x-radius)*accuracy; i <= (x+radius)*accuracy; i++)
  {
    for(int j = (y-radius)*accuracy; j <= (y+radius)*accuracy; j++)
    {
      for(int k = (z-radius)*accuracy; k <= (z+radius)*accuracy; k++)
      {
	//Ball function
	if ( pow(i-x,2)+pow(j-y,2)+pow(k-z,2) <= pow(radius, 2) )
	  substrate[i][j][k].permitivity = 11.7;
      }
    }
  }
    return 0;
}

int Structure::addCube(int px, int py, int pz, int radius)
{
  for (int i = (x-radius)*accuracy; i <= (x+radius)*accuracy; i++)
  {
    for(int j = (y-radius)*accuracy; j <= (y+radius); j++)
    {
      for(int k = (z-radius)*accuracy; k <= (z+radius)*accuracy; k++)
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
