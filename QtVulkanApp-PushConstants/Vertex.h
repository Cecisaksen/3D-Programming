#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

struct Vertex {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float u;
    float v;

    // Overloaded ostream operator which writes all vertex data to an open
    // textfile stream
    friend std::ostream& operator<<(std::ostream&, const Vertex&);

    // Overloaded istream operator which reads all vertex data from an open
    // textfile stream
    friend std::istream& operator>>(std::istream&, Vertex&);
};

#endif // VERTEX_H
