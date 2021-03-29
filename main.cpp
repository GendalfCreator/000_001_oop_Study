#include <iostream>

using namespace std;

class Object {
public:
  int pivotX;
  int pivotY;
  int pivotZ;
};

int main()
{
  Object world;
  Object object1;
  int shiftX = 10;
  int shiftY = 10;
  int shiftZ = 10;

  world.pivotX = 0;
  world.pivotY = 1;
  world.pivotZ = 0;

  object1.pivotX = world.pivotX + shiftX;
  object1.pivotY = world.pivotY + shiftY;
  object1.pivotZ = world.pivotZ + shiftZ;

  cout << world.pivotX << "|" << world.pivotY << "|" << world.pivotZ << endl;
  cout << object1.pivotX << "|" << object1.pivotY << "|" << object1.pivotZ << endl;

  return 0;
}
