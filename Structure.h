#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cerrno>


struct material {
  double permitivity;
  double Nd;
  double Na;
};

typedef material Material;


class Structure
{

public:

  Structure(int xlen, int ylen, int zlen, int accu);

  ~Structure();
  Structure& operator=(const Structure& other);

  int addCube(int px,int py,int pz,int radius);
  int addBall(int px,int py, int pz, int radius);

  Material*** retSubstrate();
  Material retSubstrate(int, int, int);
  
  void printSubstratetoFile(char* );
  void printSubstrate();

private:

  void free_data( int xlen, int ylen);

  Material ***substrate;

  int x,y,z;
  int accuracy;

};

#endif // STRUCTURE_H
