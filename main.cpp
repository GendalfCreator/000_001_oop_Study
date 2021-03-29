#include <iostream>

using namespace std;

class Object {
public:
  int pivotX;
  int pivotY;
  int pivotZ;

  Object* parent;
  Object* child = NULL;

  void Moove (int shiftX, int shiftY, int shiftZ) {
    pivotX += parent->pivotX + shiftX;
    pivotY += parent->pivotY + shiftY;
    pivotZ += parent->pivotZ + shiftZ;
    if (child != NULL) {
        child->Moove(shiftX, shiftY, shiftZ);
      }
  }

  void ShowCoordinates () {
    cout << pivotX << "|" << pivotY << "|" << pivotZ << endl;
  }

  void SetCoordinates(int x, int y, int z) {
    pivotX = x;
    pivotY = y;
    pivotZ = z;
  }

};

int main()
{
  Object world;
  Object object1;
  Object object2;
  int shiftX = 9;
  int shiftY = 10;
  int shiftZ = 10;

  object1.parent = &world;
  object1.child = &object2;
  object2.parent = &object1;

  world.SetCoordinates(1, 0, 0);
  object1.SetCoordinates(0 , 0, 0);
  object2.SetCoordinates(2, 2, 2);

  object1.Moove(shiftX, shiftY, shiftZ);

  world.ShowCoordinates();
  object1.ShowCoordinates();
  object2.ShowCoordinates();

  return 0;
}
