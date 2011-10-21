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

bool Structure::operator==(const Structure& other) const
{
///TODO: return ...;
}

int Structure::addBall(int px, int py, int pz, int radius)
{
  for (int i = (x-radius); i <= (x+radius); i++)
  {
    for(int j = (y-radius); j <= (y+radius); j++)
    {
      for(int k = (z-radius); k <= (z+radius); k++)
      {
	//Ball function
	if ( pow(i-x,2)+pow(j-y,2)+pow(k-z,2) <= pow(radius, 2) )
	  Array[i][j][k].permitivity = 11.7;
      }
    }
  }
    return 0;
}

int Structure::addCube(int px, int py, int pz, int radius)
{
  for (int i = (x-radius); i <= (x+radius); i++)
  {
    for(int j = (y-radius); j <= (y+radius); j++)
    {
      for(int k = (z-radius); k <= (z+radius); k++)
      {
	Array[i][j][k].permitivity = 11.7;
      }
    }
  }
    return 0;
}

