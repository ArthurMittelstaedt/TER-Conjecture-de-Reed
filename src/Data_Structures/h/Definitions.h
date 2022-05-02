#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdlib.h>

// Definition of the type for representing vertex ids
// As we will work on small graphs ~20 vertices, we chose the smallest
// type available.
typedef unsigned char VertexId;

// We don't need more colors than vertices.
typedef VertexId Color;

// We want to be able to represent a subgraph as an array of bits
// we chose a type represented on a number of bits that fits well
// for the project : unsigned int which has 32.
typedef unsigned int binarySubG;
// this sets the limit on the number of vertices in our implementation.
const size_t MAX_N = sizeof(binarySubG) * 8;

#endif