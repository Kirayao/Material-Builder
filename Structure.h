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
  Structure();
  Structure(const Structure& other);
  ~Structure();
  Structure& operator=(const Structure& other);
  bool operator==(const Structure& other) const;

  int addCube(int px,int py,int pz,int radius);
  int addBall(int px,int py, int pz, int radius);

private:
  Material ***substrate;

  int x,y,z;
  int accuracy;

};

#endif // STRUCTURE_H
