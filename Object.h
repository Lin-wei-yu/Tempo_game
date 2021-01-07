#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

class Object {
public:
    Object() {}
    ~Object() {}
    // pure function for drawing object
    virtual void draw() = 0;
    int getX() {
        return pos_x;
    }
    int getY() {
        return pos_y;
    }
protected:
    int pos_x;
    int pos_y;
    ALLEGRO_BITMAP* img;
};

#endif // OBJECT_H_INCLUDED