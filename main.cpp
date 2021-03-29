#include <iostream>

using namespace std;

class Object {
public:

  void Moove (int shiftX, int shiftY, int shiftZ) {
    if (parent != NULL) {
        pivotX += parent->pivotX + shiftX;
        pivotY += parent->pivotY + shiftY;
        pivotZ += parent->pivotZ + shiftZ;
      }
    else {
        pivotX += shiftX;
        pivotY += shiftY;
        pivotZ += shiftZ;
      }

    if (child != NULL) {
        child->MooveChild(shiftX, shiftY, shiftZ);
      }
    else {
        pivotX += shiftX;
        pivotY += shiftY;
        pivotZ += shiftZ;
      }
  }

  void MooveChild (int shiftX, int shiftY, int shiftZ) {
    pivotX += shiftX;
    pivotY += shiftY;
    pivotZ += shiftZ;

  }

  void ShowCoordinates () {
    cout << pivotX << "|" << pivotY << "|" << pivotZ << endl;
  }

  void SetCoordinates(int x, int y, int z) {
    pivotX = x;
    pivotY = y;
    pivotZ = z;
  }

  void SetIerarchy (Object* parent, Object* child) {
    this->parent = parent;
    this->child = child;
  }

private:
  int pivotX;
  int pivotY;
  int pivotZ;
  Object* parent;
  Object* child = NULL;

};

int main()
{
  Object world;
  Object object1;
  Object object2;
  int shiftX = 10;
  int shiftY = 10;
  int shiftZ = 10;

  world.SetIerarchy(NULL, &object1);
  object1.SetIerarchy(&world, &object2);
  object2.SetIerarchy(&object1, NULL);

  world.SetCoordinates(0, 0, 0);
  object1.SetCoordinates(1 , 1, 1);
  object2.SetCoordinates(2, 2, 2);

  world.Moove(shiftX, shiftY, shiftZ);

  world.ShowCoordinates();
  object1.ShowCoordinates();
  object2.ShowCoordinates();

  return 0;
}
