//--------------------------------------------------------------------------//
//                                                                          //
//  Project Assignment 2 - Eren Limon - 0054129                             //
//                                                                          //
//--------------------------------------------------------------------------//



#include "Angel.h"

typedef vec4  color4;
typedef vec4  point4;

const int NumVertices = 36;

point4 pointsCube_1[NumVertices]; // middle center cube points
color4 colorsCube_1[NumVertices]; // middle center cube colors
mat4  Model_view[28]; // 29th cube is invisible and used for picking the correct face

GLfloat offsetBetweenCubes = 0.05;
GLfloat squareEdge = 0.4; // edge of one small cube

point4 Points[28][NumVertices] = {};
point4 VerticesCube[28][8] = {};

point4 Colors[28][NumVertices] = {};

point4 distanceXToCentralCube[27] = { // distance x of all small cubes to the middle central cube.
    /* Front 9 */
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0),
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0),
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0),
    
    /* Middle 9 */
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0),
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0),
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0),
    
    /* Back 9 */
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0),
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0),
    point4(-squareEdge-offsetBetweenCubes,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(+squareEdge+offsetBetweenCubes,0.0,0.0,0.0)
};
point4 distanceYToCentralCube[27] = { // distance y of all small cubes to the middle central cube.
    /* Front 9 */
    point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0), point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0), point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0),
    point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0),
    point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0), point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0), point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0),
    
    /* Middle 9 */
    point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0), point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0), point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0),
    point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0),
    point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0), point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0), point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0),
    
    /* Back 9 */
    point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0), point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0), point4(0.0,+squareEdge+offsetBetweenCubes,0.0,0.0),
    point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0),
    point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0), point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0), point4(0.0,-squareEdge-offsetBetweenCubes,0.0,0.0)
};
point4 distanceZToCentralCube[27] = { // distance z of all small cubes to the middle central cube.
    /* Front 9 */
    point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0), point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0), point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0),
     point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0), point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0), point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0),
     point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0), point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0), point4(0.0,0.0,+squareEdge+offsetBetweenCubes,0.0),
    
    /* Middle 9 */
    point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0),
    point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0),
    point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0), point4(0.0,0.0,0.0,0.0),
    
    /* Back 9 */
    point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0), point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0), point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0),
    point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0), point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0), point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0),
    point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0), point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0), point4(0.0,0.0,-squareEdge-offsetBetweenCubes,0.0),
};

// Vertices of a unit cube centered at origin, sides aligned with axes
point4 verticesCube_1[8] = {
    point4( -squareEdge/2, -squareEdge/2,  squareEdge/2, 1.0 ),
    point4( -squareEdge/2,  squareEdge/2,  squareEdge/2, 1.0 ),
    point4(  squareEdge/2,  squareEdge/2,  squareEdge/2, 1.0 ),
    point4(  squareEdge/2, -squareEdge/2,  squareEdge/2, 1.0 ),
    point4( -squareEdge/2, -squareEdge/2, -squareEdge/2, 1.0 ),
    point4( -squareEdge/2,  squareEdge/2, -squareEdge/2, 1.0 ),
    point4(  squareEdge/2,  squareEdge/2, -squareEdge/2, 1.0 ),
    point4(  squareEdge/2, -squareEdge/2, -squareEdge/2, 1.0 )
};

// this function fills all our vertex arrays.
void fillVertexArrays(){
    
    for(int i = 0; i < 27; i++){
        
        for(int j = 0; j < 9 ; j++){
            
            VerticesCube[i][j]   = verticesCube_1[j] + distanceXToCentralCube[i] + distanceYToCentralCube[i] + distanceZToCentralCube[i];
            
        }
    }
    // last cube is going to be the enlarged version of the middle center cube
    for(int j = 0; j < 9; j++){
        VerticesCube[27][j] = VerticesCube[13][j];
    }
    
}



// RGBA olors
color4 vertex_colors_cube_1[8] = {
    color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    color4( 1.0, 0.0, 0.0, 1.0 ),  // red
    color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
    color4( 0.0, 1.0, 0.0, 1.0 ),  // green
    color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
    color4( 1.0, 0.0, 1.0, 1.0 ),  // magenta
    color4( 1.0, 1.0, 1.0, 1.0 ),  // white
    color4( 0.0, 1.0, 1.0, 1.0 )   // cyan
};


// all color info of all sides of all cubes
color4 ColorsCube[28][6] = {
    {
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
    },
    {
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
    },
    {
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        //front 6
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
        
    },
    {
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        // front is over
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
    },
    {
        // center cube
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        // middle layer over
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 1.0, 0.5, 0.0, 1.0 )   // orange
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    {
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 0.0, 0.0, 0.0, 1.0 ),  // black
    },
    { // invisible cube that helps to pick
        color4( 1.0, 0.0, 0.0, 1.0 ),  // red
        color4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
        color4( 0.0, 1.0, 0.0, 1.0 ),  // green
        color4( 0.0, 0.0, 1.0, 1.0 ),  // blue
        color4( 1.0, 0.0, 1.0, 1.0 ),  // magenta
        color4( 1.0, 1.0, 1.0, 1.0 ),  // white
    }
};


// Array of rotation angles (in degrees) for each coordinate axis
enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
int  Axis = Xaxis;

GLfloat  Initial[NumAxes] = { 30.0, -40.0, 0.0 }; // initial rotation angles

GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 }; // Angles of ccw face rotations
GLfloat  Beta[NumAxes] = { 0.0, 0.0, 0.0 }; // Angles of cw face rotations

GLfloat ViewerRotation[NumAxes] = {0.0, 0.0, 0.0}; // angle of viewer rotations

// Model-view and projection matrices uniform location
GLuint  ModelView, Projection;

//----------------------------------------------------------------------------

// quad generates two triangles for each face and assigns colors
// to the vertices

int Index = 0;
void
quad( int a, int b, int c, int d, int cubeIndex, int face )
{
    // Initialize colors
    
    Colors[cubeIndex][Index] = ColorsCube[cubeIndex][face]; Points[cubeIndex][Index] = VerticesCube[cubeIndex][a]; Index++;
    Colors[cubeIndex][Index] = ColorsCube[cubeIndex][face]; Points[cubeIndex][Index] = VerticesCube[cubeIndex][b]; Index++;
    Colors[cubeIndex][Index] = ColorsCube[cubeIndex][face]; Points[cubeIndex][Index] = VerticesCube[cubeIndex][c]; Index++;
    Colors[cubeIndex][Index] = ColorsCube[cubeIndex][face]; Points[cubeIndex][Index] = VerticesCube[cubeIndex][a]; Index++;
    Colors[cubeIndex][Index] = ColorsCube[cubeIndex][face]; Points[cubeIndex][Index] = VerticesCube[cubeIndex][c]; Index++;
    Colors[cubeIndex][Index] = ColorsCube[cubeIndex][face]; Points[cubeIndex][Index] = VerticesCube[cubeIndex][d]; Index++;
}

//----------------------------------------------------------------------------

// generate 12 triangles: 36 vertices and 36 colors for each cube
void
colorcube(int cubeIndex)
{
    quad( 1, 0, 3, 2, cubeIndex, 0  );
    quad( 2, 3, 7, 6, cubeIndex, 1  );
    quad( 3, 0, 4, 7, cubeIndex, 2  );
    quad( 6, 5, 1, 2, cubeIndex, 3  );
    quad( 4, 5, 6, 7, cubeIndex, 4  );
    quad( 5, 4, 0, 1, cubeIndex, 5  );
    Index = 0;
}

// this is just a signature for initialRandomization(), implementation is below.
void initialRandomization();

// OpenGL initialization
GLuint vaoArray[28];
GLuint buffer;
GLuint vPosition;
GLuint vColor;

void
init()
{
    fillVertexArrays();
    
    for(int i = 0; i < 28; i++){
        colorcube(i);
    }
    
    GLuint program = InitShader( "vshader.glsl", "fshader.glsl" );
    const vec3 displacement( 0.0, 0.0, 0.0 );
    
    glGenVertexArrays( 28, vaoArray );
    for (int i = 0; i < 28; i++) {
        
        glBindVertexArray( vaoArray[i] );
        glGenBuffers( 1, &buffer );
        glBindBuffer( GL_ARRAY_BUFFER, buffer );
        glBufferData( GL_ARRAY_BUFFER, sizeof(point4)*36 + sizeof(Colors[i]), NULL, GL_STATIC_DRAW );
        glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(point4)*36, Points[i] );
        glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4)*36, sizeof(Colors[i]), Colors[i] );
        
        vPosition = glGetAttribLocation( program, "vPosition" );
        
        glEnableVertexAttribArray( vPosition );
        glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
        
        vColor = glGetAttribLocation( program, "vColor" );
        glEnableVertexAttribArray( vColor );
        glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(point4)*36) );
        
        Model_view[i] = identity();
        
        if(i == 27){
            // this invisible cube will be slightly bigger than our rubik's cube so that when we click on faces, we get its color instead of
            // the smaller cubes of the rubik's cube.
            Model_view[i] =  Scale(3.26, 3.26, 3.26) * RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * Model_view[i];
        } else {
            Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * Model_view[i];
        }
        
    }
    
    // Retrieve uniform variable locations
    ModelView = glGetUniformLocation( program, "ModelView" );
    Projection = glGetUniformLocation( program, "Projection" );
    
    // Set current program object
    glUseProgram( program );
   
    
    
    /*
     
     glBindVertexArray( vaoArray[1] );
     
     // sphere methods
     glGenBuffers( 1, &buffer );
     glBindBuffer( GL_ARRAY_BUFFER, buffer );
     glBufferData( GL_ARRAY_BUFFER, sizeof(pointsCube_2) + sizeof(colorsCube_1), NULL, GL_STATIC_DRAW );
     glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(pointsCube_2), pointsCube_2 );
     glBufferSubData( GL_ARRAY_BUFFER, sizeof(pointsCube_2), sizeof(colorsCube_1), colorsCube_1 );
     
     vPosition = glGetAttribLocation( program, "vPosition" );
     
     glEnableVertexAttribArray( vPosition );
     glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
     
     vColor = glGetAttribLocation( program, "vColor" );
     glEnableVertexAttribArray( vColor );
     glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(pointsCube_2)) );
     
     
     // Retrieve transformation uniform variable locations
     ModelView = glGetUniformLocation( program, "ModelView" );
     Projection = glGetUniformLocation( program, "Projection" );
     
     // Set current program object
     glUseProgram( program );
     
     
     */
    
    
    // Set projection matrix
    mat4  projection;
    projection = Ortho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Ortho(): user-defined function in mat.h
    //projection = Perspective( 45.0, 1.0, 0.5, 3.0 );
    glUniformMatrix4fv( Projection, 1, GL_TRUE, projection );
    
    // Enable hiddden surface removal
    glEnable( GL_DEPTH_TEST );
    
    // Set state variable "clear color" to clear buffer with.
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
}

//----------------------------------------------------------------------------

// Indices of cubes that are located specific sides

int rightSide[9] = {2,5,8,11,14,17,20,23,26};
int leftSide[9] = {0,3,6,9,12,15,18,21,24};
int frontSide[9] = {0,1,2,3,4,5,6,7,8};
int backSide[9] = {18,19,20,21,22,23,24,25,26};
int topSide[9] = {0,1,2,9,10,11,18,19,20};
int bottomSide[9] = {6,7,8,15,16,17,24,25,26};

bool keyAPressed = false;
bool keyDPressed = false;
bool keyWPressed = false;
bool keySPressed = false;
bool keyRPressed = false; // right face, rotate ccw
bool keyCPressed = false; // right face, rotate cw
bool keyFPressed = false; // front face, rotate ccw
bool keyVPressed = false; // front face, rotate cw
bool keyTPressed = false; // top face, rotate ccw
bool keyGPressed = false; // top face, rotate cw
bool lockForYView = false;
bool lockForXView = false;
bool lockForThetaX = false;
bool lockForThetaZ = false;
bool lockForThetaY = false;
bool lockForBetaX = false;
bool lockForBetaZ = false;
bool lockForBetaY = false;
bool anotherKeyIsActive = false;

int arrayMax(int arr[]){
    int max = -999;
    for(int i = 0; i < 9;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    //std::cout << "max: " << max << std::endl;
    return max;
}

void printArray(int arr[]){
    for(int i = 0; i < 9;i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int tempRightSide[9] = {0,0,0,0,0,0,0,0,0};
int tempLeftSide[9] = {0,0,0,0,0,0,0,0,0};
int tempFrontSide[9] = {0,0,0,0,0,0,0,0,0};
int tempBackSide[9] = {0,0,0,0,0,0,0,0,0};
int tempTopSide[9] = {0,0,0,0,0,0,0,0,0};
int tempBottomSide[9] = {0,0,0,0,0,0,0,0,0};

void resetTempArrays(){
    
    for(int j = 0; j < 9; j++){
        tempRightSide[j] = rightSide[j];
    }
    
    
    for(int j = 0; j < 9; j++){
        tempLeftSide[j] = leftSide[j];
    }
    
    
    for(int j = 0; j < 9; j++){
        tempFrontSide[j] = frontSide[j];
    }
    
   
    for(int j = 0; j < 9; j++){
        tempBackSide[j] = backSide[j];
    }
    
    for(int j = 0; j < 9; j++){
        tempTopSide[j] = topSide[j];
    }
    
    for(int j = 0; j < 9; j++){
        tempBottomSide[j] = bottomSide[j];
    }
}

void
display( void )
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for(int i = 0; i < 27; i++){
        glBindVertexArray( vaoArray[i] );
        
        
        const vec3 displacement( 0.0, 0.0, 0.0 );
        
        if((std::find(std::begin(rightSide), std::end(rightSide), i) != std::end(rightSide))){ // if i is found in rightSide array
            // TODO: to be filled
            
            /*Model_view[i] =  Translate( displacement ) * RotateX( Theta[Xaxis] ) * RotateY( Theta[Yaxis] ) *
            RotateZ( Theta[Zaxis] ) * Translate( -displacement ) * Model_view[i];*/
            
               /* Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) *
                                 RotateX( 0 ) *
                                 RotateY( 1 ) *
                                 RotateZ( 0 ) * Model_view[i]); */
               /*Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) * RotateX( ViewerRotation[Xaxis] ) *
                                 RotateY( ViewerRotation[Yaxis] ) *
                                 RotateX( Theta[Xaxis] ) *
                                 RotateY( Theta[Yaxis] ) *
                                 RotateZ( Theta[Zaxis] ) );*/
            
                
                //Model_view[i] =  Translate( displacement ) * RotateX( Theta[Xaxis] ) * RotateY( Theta[Yaxis] ) *
                //RotateZ( Theta[Zaxis] ) * Translate( -displacement ) * Model_view[i];
            
            
            
            /*Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement )  *
                             RotateZ( Theta[Zaxis] ) * RotateX( ViewerRotation[Xaxis] ) *
                             RotateY( ViewerRotation[Yaxis] ) * RotateX( ViewerRotation[Zaxis] ) * RotateX( Theta[Xaxis] ) * RotateY( Theta[Yaxis] ));*/
            if(((int)Theta[Xaxis] % 90 == 0) && lockForThetaX){
                Model_view[i] = RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateX( 2.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
                
                
                
                if(i == arrayMax(rightSide)){
                    
                    
                    resetTempArrays();
                    
                    for(int j = 0; j < 9; j++){
                        
                        if(j == 2){
                            frontSide[j] = tempTopSide[8];
                            topSide[j] = tempBackSide[2];
                            backSide[j] = tempBottomSide[8];
                            bottomSide[j] = tempFrontSide[2];
                        }
                        if(j == 5){
                            frontSide[j] = tempTopSide[5];
                            topSide[j] = tempBackSide[5];
                            backSide[j] = tempBottomSide[5];
                            bottomSide[j] = tempFrontSide[5];
                        }
                        if(j == 8){
                            frontSide[j] = tempTopSide[2];
                            topSide[j] = tempBackSide[8];
                            backSide[j] = tempBottomSide[2];
                            bottomSide[j] = tempFrontSide[8];
                        }
                        
                    }
                    rightSide[0] = tempRightSide[6];
                    rightSide[1] = tempRightSide[3];
                    rightSide[2] = tempRightSide[0];
                    rightSide[3] = tempRightSide[7];
                    rightSide[5] = tempRightSide[1];
                    rightSide[6] = tempRightSide[8];
                    rightSide[7] = tempRightSide[5];
                    rightSide[8] = tempRightSide[2];
                    
                    
                    lockForThetaX = false;
                    anotherKeyIsActive = false;
                    
                }
            }
            
            if(keyRPressed){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateX( 1.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
            }
            
            
            
            if(((int)Beta[Xaxis] % 90 == 0) && lockForBetaX){
                Model_view[i] = RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateX( -2.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
                
                if(i == arrayMax(rightSide)){
                    
                    resetTempArrays();
                    
                    rightSide[0] = tempRightSide[2];
                    rightSide[1] = tempRightSide[5];
                    rightSide[2] = tempRightSide[8];
                    rightSide[3] = tempRightSide[1];
                    rightSide[4] = tempRightSide[4];
                    rightSide[5] = tempRightSide[7];
                    rightSide[6] = tempRightSide[0];
                    rightSide[7] = tempRightSide[3];
                    rightSide[8] = tempRightSide[6];
                    
                    frontSide[2] = tempBottomSide[2];
                    frontSide[5] = tempBottomSide[5];
                    frontSide[8] = tempBottomSide[8];
                    
                    topSide[2] = tempFrontSide[8];
                    topSide[5] = tempFrontSide[5];
                    topSide[8] = tempFrontSide[2];
                    
                    backSide[2] = tempTopSide[2];
                    backSide[5] = tempTopSide[5];
                    backSide[8] = tempTopSide[8];
                    
                    bottomSide[2] = tempBackSide[8];
                    bottomSide[5] = tempBackSide[5];
                    bottomSide[8] = tempBackSide[2];
                    
                    lockForBetaX = false;
                    anotherKeyIsActive = false;
                    
                }
            }
            
            if(keyCPressed){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateX( -1.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
            }
           
            // right check finishes
        }
        
        
        if((std::find(std::begin(frontSide), std::end(frontSide), i) != std::end(frontSide))){ // if i is found in frontSide array
            
            if(((int)Theta[Zaxis] % 90 == 0) && lockForThetaZ){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateZ( 2.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
                
                if(i == arrayMax(frontSide)){ // when the 9th cube updates, we need to modify side arrays.
                    
                    
                    resetTempArrays();
                    
                    frontSide[0] = tempFrontSide[2];
                    frontSide[1] = tempFrontSide[5];
                    frontSide[2] = tempFrontSide[8];
                    frontSide[3] = tempFrontSide[1];
                    frontSide[4] = tempFrontSide[4];
                    frontSide[5] = tempFrontSide[7];
                    frontSide[6] = tempFrontSide[0];
                    frontSide[7] = tempFrontSide[3];
                    frontSide[8] = tempFrontSide[6];
                    
                    rightSide[0] = tempBottomSide[2];
                    rightSide[1] = tempBottomSide[1];
                    rightSide[2] = tempBottomSide[0];
                    
                    topSide[0] = tempRightSide[0];
                    topSide[1] = tempRightSide[1];
                    topSide[2] = tempRightSide[2];
                    
                    leftSide[0] = tempTopSide[2];
                    leftSide[1] = tempTopSide[1];
                    leftSide[2] = tempTopSide[0];
                    
                    bottomSide[0] = tempLeftSide[0];
                    bottomSide[1] = tempLeftSide[1];
                    bottomSide[2] = tempLeftSide[2];
                    
                    lockForThetaZ = false;
                    anotherKeyIsActive = false;
                    
                }
            }
            
            if(keyFPressed){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateZ( 1.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
            }
            
            if(((int)Beta[Zaxis] % 90 == 0) && lockForBetaZ){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateZ( -2.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
                
                if(i == arrayMax(frontSide)){ // when the 9th cube updates, we need to modify side arrays.
                    
                    
                    resetTempArrays();
                    
                    frontSide[0] = tempFrontSide[6];
                    frontSide[1] = tempFrontSide[3];
                    frontSide[2] = tempFrontSide[0];
                    frontSide[3] = tempFrontSide[7];
                    frontSide[4] = tempFrontSide[4];
                    frontSide[5] = tempFrontSide[1];
                    frontSide[6] = tempFrontSide[8];
                    frontSide[7] = tempFrontSide[5];
                    frontSide[8] = tempFrontSide[2];
                    
                    rightSide[0] = tempTopSide[0];
                    rightSide[1] = tempTopSide[1];
                    rightSide[2] = tempTopSide[2];
                    
                    topSide[0] = tempLeftSide[2];
                    topSide[1] = tempLeftSide[1];
                    topSide[2] = tempLeftSide[0];
                    
                    leftSide[0] = tempBottomSide[0];
                    leftSide[1] = tempBottomSide[1];
                    leftSide[2] = tempBottomSide[2];
                    
                    bottomSide[0] = tempRightSide[2];
                    bottomSide[1] = tempRightSide[1];
                    bottomSide[2] = tempRightSide[0];
                    
                    lockForBetaZ = false;
                    anotherKeyIsActive = false;
                    
                }
            }
            
            if(keyVPressed){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateZ( -1.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
            }
            
            
           // front side check end
        }
        
        
        if((std::find(std::begin(topSide), std::end(topSide), i) != std::end(topSide))){ // if i is found in topside array
            
            if(((int)Theta[Yaxis] % 90 == 0) && lockForThetaY){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateY( 2.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
                
                if(i == arrayMax(topSide)){ // when the 9th cube updates, we need to modify side arrays.
                    
                    
                    resetTempArrays();
                    
                    
                    topSide[0] = tempTopSide[6];
                    topSide[1] = tempTopSide[3];
                    topSide[2] = tempTopSide[0];
                    topSide[3] = tempTopSide[7];
                    topSide[4] = tempTopSide[4];
                    topSide[5] = tempTopSide[1];
                    topSide[6] = tempTopSide[8];
                    topSide[7] = tempTopSide[5];
                    topSide[8] = tempTopSide[2];
                    
                    rightSide[0] = tempFrontSide[0];
                    rightSide[3] = tempFrontSide[1];
                    rightSide[6] = tempFrontSide[2];
                    
                    backSide[0] = tempRightSide[6];
                    backSide[1] = tempRightSide[3];
                    backSide[2] = tempRightSide[0];
                    
                    leftSide[0] = tempBackSide[0];
                    leftSide[3] = tempBackSide[1];
                    leftSide[6] = tempBackSide[2];
                    
                    frontSide[0] = tempLeftSide[6];
                    frontSide[1] = tempLeftSide[3];
                    frontSide[2] = tempLeftSide[0];
                    
                    lockForThetaY = false;
                    anotherKeyIsActive = false;
                    
                }
            }
            
            if(keyTPressed){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateY( 1.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
            }
            
            
            if(((int)Beta[Yaxis] % 90 == 0) && lockForBetaY){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateY( -2.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
                
                if(i == arrayMax(topSide)){ // when the 9th cube updates, we need to modify side arrays.
                    
                    resetTempArrays();
                    
                    topSide[0] = tempTopSide[2];
                    topSide[1] = tempTopSide[5];
                    topSide[2] = tempTopSide[8];
                    topSide[3] = tempTopSide[1];
                    topSide[4] = tempTopSide[4];
                    topSide[5] = tempTopSide[7];
                    topSide[6] = tempTopSide[0];
                    topSide[7] = tempTopSide[3];
                    topSide[8] = tempTopSide[6];
                    
                    rightSide[0] = tempBackSide[2];
                    rightSide[3] = tempBackSide[1];
                    rightSide[6] = tempBackSide[0];
                    
                    backSide[0] = tempLeftSide[0];
                    backSide[1] = tempLeftSide[3];
                    backSide[2] = tempLeftSide[6];
                    
                    leftSide[0] = tempFrontSide[2];
                    leftSide[3] = tempFrontSide[1];
                    leftSide[6] = tempFrontSide[0];
                    
                    frontSide[0] = tempRightSide[0];
                    frontSide[1] = tempRightSide[3];
                    frontSide[2] = tempRightSide[6];
                    
                    lockForBetaY = false;
                    anotherKeyIsActive = false;
                    
                }
            }
            
            if(keyGPressed){
                Model_view[i] =  RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateY( -1.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
            }
            
            
            
            // top check ends here
        }
        
        
        
        //  Generate tha model-view matrix
         /*Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) *
         RotateX( Theta[Xaxis] ) *
         RotateY( Theta[Yaxis] ) *
         RotateZ( Theta[Zaxis] ) );*/
        
        //model_view = Translate( displacement ) * RotateX( Theta[Xaxis] ) * Translate( -displacement ) * Scale(0.5, 0.5, 0.5);
        
        
        // Scale(), Translate(), RotateX(), RotateY(), RotateZ(): user-defined functions in mat.h
        
        //use this to have rotation around fixed axes
        /*Model_view[i] =  Translate( displacement ) * RotateX( Theta[Xaxis] ) * RotateY( Theta[Yaxis] ) *
         RotateZ( Theta[Zaxis] ) * Translate( -displacement ) * Model_view[i];*/
        
        if((int)ViewerRotation[Yaxis] % 90 == 0 && lockForYView){
            
            Model_view[i] = RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateY( 2.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) * Model_view[i];
            
            if(i == 26){
                
                resetTempArrays();
                
                rightSide[0] = tempFrontSide[0];
                rightSide[1] = tempFrontSide[3];
                rightSide[2] = tempFrontSide[6];
                rightSide[3] = tempFrontSide[1];
                rightSide[4] = tempFrontSide[4];
                rightSide[5] = tempFrontSide[7];
                rightSide[6] = tempFrontSide[2];
                rightSide[7] = tempFrontSide[5];
                rightSide[8] = tempFrontSide[8];
                
                backSide[0] = tempRightSide[6];
                backSide[1] = tempRightSide[3];
                backSide[2] = tempRightSide[0];
                backSide[3] = tempRightSide[7];
                backSide[4] = tempRightSide[4];
                backSide[5] = tempRightSide[1];
                backSide[6] = tempRightSide[8];
                backSide[7] = tempRightSide[5];
                backSide[8] = tempRightSide[2];
                
                leftSide[0] = tempBackSide[0];
                leftSide[1] = tempBackSide[3];
                leftSide[2] = tempBackSide[6];
                leftSide[3] = tempBackSide[1];
                leftSide[4] = tempBackSide[4];
                leftSide[5] = tempBackSide[7];
                leftSide[6] = tempBackSide[2];
                leftSide[7] = tempBackSide[5];
                leftSide[8] = tempBackSide[8];
                
                frontSide[0] = tempLeftSide[6];
                frontSide[1] = tempLeftSide[3];
                frontSide[2] = tempLeftSide[0];
                frontSide[3] = tempLeftSide[7];
                frontSide[4] = tempLeftSide[4];
                frontSide[5] = tempLeftSide[1];
                frontSide[6] = tempLeftSide[8];
                frontSide[7] = tempLeftSide[5];
                frontSide[8] = tempLeftSide[2];
                
                topSide[0] = tempTopSide[6];
                topSide[1] = tempTopSide[3];
                topSide[2] = tempTopSide[0];
                topSide[3] = tempTopSide[7];
                topSide[4] = tempTopSide[4];
                topSide[5] = tempTopSide[1];
                topSide[6] = tempTopSide[8];
                topSide[7] = tempTopSide[5];
                topSide[8] = tempTopSide[2];
                
                bottomSide[0] = tempBottomSide[6];
                bottomSide[1] = tempBottomSide[3];
                bottomSide[2] = tempBottomSide[0];
                bottomSide[3] = tempBottomSide[7];
                bottomSide[4] = tempBottomSide[4];
                bottomSide[5] = tempBottomSide[1];
                bottomSide[6] = tempBottomSide[8];
                bottomSide[7] = tempBottomSide[5];
                bottomSide[8] = tempBottomSide[2];
                
                lockForYView = false;
                anotherKeyIsActive = false;
            
            }
            
        }
        if(keyDPressed && !keyAPressed){ // user rotates around Y
            /*Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) * RotateX( ViewerRotation[Xaxis] ) *
                             RotateY( ViewerRotation[Yaxis] ) * RotateX( ViewerRotation[Zaxis] ) );*/
            Model_view[i] = RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateY( 1.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) *  Model_view[i];
            
        }
        
        
        if((int)ViewerRotation[Xaxis] % 90 == 0 && lockForXView){
            
            Model_view[i] = RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateX( 2.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) *  Model_view[i];
            
            if(i == 26){
                
                resetTempArrays();
                
                rightSide[0] = tempRightSide[6];
                rightSide[1] = tempRightSide[3];
                rightSide[2] = tempRightSide[0];
                rightSide[3] = tempRightSide[7];
                rightSide[4] = tempRightSide[4];
                rightSide[5] = tempRightSide[1];
                rightSide[6] = tempRightSide[8];
                rightSide[7] = tempRightSide[5];
                rightSide[8] = tempRightSide[2];
                
                backSide[0] = tempBottomSide[6];
                backSide[1] = tempBottomSide[7];
                backSide[2] = tempBottomSide[8];
                backSide[3] = tempBottomSide[3];
                backSide[4] = tempBottomSide[4];
                backSide[5] = tempBottomSide[5];
                backSide[6] = tempBottomSide[0];
                backSide[7] = tempBottomSide[1];
                backSide[8] = tempBottomSide[2];
                
                leftSide[0] = tempLeftSide[6];
                leftSide[1] = tempLeftSide[3];
                leftSide[2] = tempLeftSide[0];
                leftSide[3] = tempLeftSide[7];
                leftSide[4] = tempLeftSide[4];
                leftSide[5] = tempLeftSide[1];
                leftSide[6] = tempLeftSide[8];
                leftSide[7] = tempLeftSide[5];
                leftSide[8] = tempLeftSide[2];
                
                frontSide[0] = tempTopSide[6];
                frontSide[1] = tempTopSide[7];
                frontSide[2] = tempTopSide[8];
                frontSide[3] = tempTopSide[3];
                frontSide[4] = tempTopSide[4];
                frontSide[5] = tempTopSide[5];
                frontSide[6] = tempTopSide[0];
                frontSide[7] = tempTopSide[1];
                frontSide[8] = tempTopSide[2];
                
                topSide[0] = tempBackSide[0];
                topSide[1] = tempBackSide[1];
                topSide[2] = tempBackSide[2];
                topSide[3] = tempBackSide[3];
                topSide[4] = tempBackSide[4];
                topSide[5] = tempBackSide[5];
                topSide[6] = tempBackSide[6];
                topSide[7] = tempBackSide[7];
                topSide[8] = tempBackSide[8];
                
                bottomSide[0] = tempFrontSide[0];
                bottomSide[1] = tempFrontSide[1];
                bottomSide[2] = tempFrontSide[2];
                bottomSide[3] = tempFrontSide[3];
                bottomSide[4] = tempFrontSide[4];
                bottomSide[5] = tempFrontSide[5];
                bottomSide[6] = tempFrontSide[6];
                bottomSide[7] = tempFrontSide[7];
                bottomSide[8] = tempFrontSide[8];
                
                lockForXView = false;
                anotherKeyIsActive = false;
                
            }
            
        }
        
        if(keySPressed && !keyWPressed){
            Model_view[i] = RotateY( Initial[Yaxis] ) * RotateX( Initial[Xaxis] ) * RotateX( 1.0 ) * RotateX( -Initial[Xaxis] ) * RotateY( -Initial[Yaxis] ) *  Model_view[i];
        }
        
        
        if(keyAPressed && !keyDPressed){
            Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) * RotateX( ViewerRotation[Xaxis] ) *
                             RotateY( ViewerRotation[Yaxis] ) * RotateX( ViewerRotation[Zaxis] ) );
        }
        
        if(keyWPressed && !keySPressed){ // user rotates around X
            Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) * RotateX( ViewerRotation[Xaxis] ) *
                             RotateY( ViewerRotation[Yaxis] ) * RotateX( ViewerRotation[Zaxis] ) );
        }
        
        
        
        
        glUniformMatrix4fv( ModelView, 1, GL_TRUE, Model_view[i] );
        
        
        
        glDrawArrays( GL_TRIANGLES, 0, NumVertices );
        
    }
    
    mat4  projection;
    projection = Ortho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); // Ortho(): user-defined function in mat.h
    //projection = Perspective( 45.0, 1.0, 0.5, 3.0 );
    glUniformMatrix4fv( Projection, 1, GL_TRUE, projection );
    
    glutSwapBuffers();
    
    //keyAPressed = false;
    //Theta[0] = Theta[1] = Theta[2] = 0.0;
    /////////////////
    
    
}

//----------------------------------------------------------------------------
int dCounter = 0;
int aCounter = 0;


void
idle( void )
{
    /*if(keyAPressed){
        Theta[Axis] += 2.0;
        
        if ( Theta[Axis] > 360.0 ) {
            Theta[Axis] -= 360.0;
        }
    }*/
    if(keyAPressed && !keyDPressed && ((int)ViewerRotation[Yaxis] % 90 != 0)){
        ViewerRotation[Yaxis] -= 1.0;
        /*
        if(aCounter == 4 && ViewerRotation[Yaxis] >= 360.0){
            aCounter = 0;
            ViewerRotation[Yaxis] -= 360.0;
        }
        */
        if ( ViewerRotation[Yaxis] <= -360.0 ) {
            ViewerRotation[Yaxis] += 360.0;
        }
        
        if(((int)ViewerRotation[Yaxis] % 90 == 0)){
            
            keyAPressed = false;
        }
    }
    
    if(keyDPressed && !keyAPressed && ((int)ViewerRotation[Yaxis] % 90 != 0)){
        lockForYView = true;
        ViewerRotation[Yaxis] += 1.0;
        /*
        if(dCounter == 4 && ViewerRotation[Yaxis] >= 360.0){
            dCounter = 0;
            ViewerRotation[Yaxis] -= 360.0;
        }
        */
        if ( ViewerRotation[Yaxis] >= 360.0 ) {
            ViewerRotation[Yaxis] -= 360.0;
        }
        
        if(((int)ViewerRotation[Yaxis] % 90 == 0)){
            
            keyDPressed = false;
            lockForYView = true;
        }
        
    }
    
    if(keyRPressed && ((int)Theta[Xaxis] % 90 != 0)){
        lockForThetaX = true;
        Theta[Xaxis] += 1.0;
        
        if ( Theta[Xaxis] >= 360.0 ) {
            Theta[Xaxis] -= 360.0;
        }
        
        if(((int)Theta[Xaxis] % 90 == 0)){
            keyRPressed = false;
            lockForThetaX = true;
        }
    }
    
    if(keyCPressed && ((int)Beta[Xaxis] % 90 != 0)){
        lockForBetaX = true;
        Beta[Xaxis] -= 1.0;
        
        if ( Beta[Xaxis] <= 360.0 ) {
            Beta[Xaxis] += 360.0;
        }
        
        if(((int)Beta[Xaxis] % 90 == 0)){
            keyCPressed = false;
            lockForBetaX = true;
        }
    }
    
    
    if(keyFPressed && ((int)Theta[Zaxis] % 90 != 0)){
        lockForThetaZ = true;
        Theta[Zaxis] += 1.0;
        
        if ( Theta[Zaxis] >= 360.0 ) {
            Theta[Zaxis] -= 360.0;
        }
        
        if(((int)Theta[Zaxis] % 90 == 0)){
            keyFPressed = false;
            lockForThetaZ = true;
        }
    }
    
    if(keyVPressed && ((int)Beta[Zaxis] % 90 != 0)){
        lockForBetaZ = true;
        Beta[Zaxis] -= 1.0;
        
        if ( Beta[Zaxis] <= -360.0 ) {
            Beta[Zaxis] += 360.0;
        }
        
        if(((int)Beta[Zaxis] % 90 == 0)){
            keyVPressed = false;
            lockForBetaZ = true;
        }
    }
    
    if(keyTPressed && ((int)Theta[Yaxis] % 90 != 0)){
        lockForThetaY = true;
        Theta[Yaxis] += 1.0;
        
        if ( Theta[Yaxis] >= 360.0 ) {
            Theta[Yaxis] -= 360.0;
        }
        
        if(((int)Theta[Yaxis] % 90 == 0)){
            keyTPressed = false;
            lockForThetaY = true;
        }
    }
    
    if(keyGPressed && ((int)Beta[Yaxis] % 90 != 0)){
        lockForBetaY = true;
        Beta[Yaxis] -= 1.0;
        
        if ( Beta[Yaxis] <= -360.0 ) {
            Beta[Yaxis] += 360.0;
        }
        
        if(((int)Beta[Yaxis] % 90 == 0)){
            keyGPressed = false;
            lockForBetaY = true;
        }
    }
    
    if(keySPressed && !keyWPressed && ((int)ViewerRotation[Xaxis] % 90 != 0)){
        lockForXView = true;
        ViewerRotation[Xaxis] += 1.0;
        
        if ( ViewerRotation[Xaxis] >= 360.0 ) {
            ViewerRotation[Xaxis] -= 360.0;
        }
        
        if(((int)ViewerRotation[Xaxis] % 90 == 0)){
            keySPressed = false;
            lockForXView = true;
        }
        
    }
    
    
    if(keyWPressed && !keySPressed && ((int)ViewerRotation[Xaxis] % 90 != 0)){
        ViewerRotation[Xaxis] -= 1.0;
        
        if ( ViewerRotation[Xaxis] <= -360.0 ) {
            ViewerRotation[Xaxis] += 360.0;
        }
        
        if(((int)ViewerRotation[Xaxis] % 90 == 0)){
            keyWPressed = false;
        }
        
    }
    
    
    
    
    
    
    // use this to have rotation around fixed axes
    //if(keyAPressed){
    //  Theta[0] = Theta[1] = Theta[2] = 0.0;
    //Theta[1] = 1.0;
    //}
    //Theta[0] = Theta[1] = Theta[2] = 0.0;
    //Theta[Axis] = 1.0;
    
    glutPostRedisplay();
}
//----------------------------------------------------------------------------

void
keyboard( unsigned char key,int x, int y )
{
    if(key == 'Q' | key == 'q')
        exit(0);
    else if(key == 'A' | key == 'a'){
        
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            keyAPressed = true;
            ViewerRotation[Yaxis] -= 1.0;
            //aCounter++;
            //dCounter++;
        }
        
    }
    else if(key == 'D' | key == 'd'){
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            keyDPressed = true;
            ViewerRotation[Yaxis] += 1.0;
            //aCounter++;
            //dCounter++;
        }
    }
    else if(key == 'W' | key == 'w'){
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            keyWPressed = true;
            ViewerRotation[Xaxis] -= 1.0;
            //aCounter++;
            //dCounter++;
        }
    }
    else if(key == 'S' | key == 's'){
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            keySPressed = true;
            ViewerRotation[Xaxis] += 1.0;
            //aCounter++;
            //dCounter++;
        }
    }
    else if(key == 'R' | key == 'r'){
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            Theta[Xaxis] += 1.0;
            keyRPressed = true;
        }
        
    }
    else if(key == 'C' | key == 'c'){
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            Beta[Xaxis] -= 1.0;
            keyCPressed = true;
        }
        
    }
    else if(key == 'F' | key == 'f'){
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            Theta[Zaxis] += 1.0;
            keyFPressed = true;
        }
        
    }
    else if(key == 'V' | key == 'v'){ // v rotates CW around Z axis
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            Beta[Zaxis] -= 1.0;
            keyVPressed = true;
        }
        
    }
    else if(key == 'T' | key == 't'){
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            Theta[Yaxis] += 1.0;
            keyTPressed = true;
        }
        
    }
    else if(key == 'G' | key == 'g'){
        
        if(!anotherKeyIsActive){
            anotherKeyIsActive = true;
            Beta[Yaxis] -= 1.0;
            keyGPressed = true;
        }
        
    }
    else if(key == 'M' | key == 'm'){
        
        if(!anotherKeyIsActive){
            initialRandomization();
        }
        
    }
    
}
int movementSequence[10] = {0,1,2,0,0,1,1,2,2,2};



//---------------------------------------------------------------------

void mouse( int button, int state, int x, int y )
{
    if ( state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        
        glBindVertexArray( vaoArray[27] );
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glUniformMatrix4fv( ModelView, 1, GL_TRUE, Model_view[27] );
        glDrawArrays( GL_TRIANGLES, 0, NumVertices );
        
        glFlush();
        
        y = glutGet( GLUT_WINDOW_HEIGHT ) - y;
        
        unsigned char pixel[4];
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        
        if((int)pixel[0] == 255 && (int)pixel[1] == 0 && (int)pixel[2] == 0){
            //std::cout << "X Coord: " << x << std::endl;
            if(!anotherKeyIsActive){
                anotherKeyIsActive = true;
                Theta[Zaxis] += 1.0;
                keyFPressed = true;
            }
        }
        if((int)pixel[0] == 255 && (int)pixel[1] == 255 && (int)pixel[2] == 0){
            //std::cout << "X Coord: " << x << std::endl;
            if(!anotherKeyIsActive){
                anotherKeyIsActive = true;
                Theta[Xaxis] += 1.0;
                keyRPressed = true;
            }
        }
        if((int)pixel[0] == 0 && (int)pixel[1] == 0 && (int)pixel[2] == 255){
            if(!anotherKeyIsActive){
                anotherKeyIsActive = true;
                Theta[Yaxis] += 1.0;
                keyTPressed = true;
            }
            
        }
        
        std::cout << "R: " << (int)pixel[0] << std::endl;
        std::cout << "G: " << (int)pixel[1] << std::endl;
        std::cout << "B: " << (int)pixel[2] << std::endl;
        std::cout << std::endl;
        
        //glutSwapBuffers(); //try if you want to display the current back buffer
        glutPostRedisplay(); //redraw the scene with true colors
    }
    
    
    if ( state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
        
        glBindVertexArray( vaoArray[27] );
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glUniformMatrix4fv( ModelView, 1, GL_TRUE, Model_view[27] );
        glDrawArrays( GL_TRIANGLES, 0, NumVertices );
        
        glFlush();
        
        y = glutGet( GLUT_WINDOW_HEIGHT ) - y;
        
        unsigned char pixel[4];
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        
        if((int)pixel[0] == 255 && (int)pixel[1] == 0 && (int)pixel[2] == 0){
            //std::cout << "X Coord: " << x << std::endl;
            
            if(!anotherKeyIsActive){
                anotherKeyIsActive = true;
                Beta[Zaxis] -= 1.0;
                keyVPressed = true;
            }
        }
        
        if((int)pixel[0] == 255 && (int)pixel[1] == 255 && (int)pixel[2] == 0){
            //std::cout << "X Coord: " << x << std::endl;
            if(!anotherKeyIsActive){
                anotherKeyIsActive = true;
                Beta[Xaxis] -= 1.0;
                keyCPressed = true;
            }
        }
        if((int)pixel[0] == 0 && (int)pixel[1] == 0 && (int)pixel[2] == 255){
            if(!anotherKeyIsActive){
                anotherKeyIsActive = true;
                Beta[Yaxis] -= 1.0;
                keyGPressed = true;
            }
            
        }
        
        std::cout << "R: " << (int)pixel[0] << std::endl;
        std::cout << "G: " << (int)pixel[1] << std::endl;
        std::cout << "B: " << (int)pixel[2] << std::endl;
        std::cout << std::endl;
        
        //glutSwapBuffers(); //try if you want to display the current back buffer
        glutPostRedisplay(); //redraw the scene with true colors
    }
    
    
}
//---------------------------------------------------------------------
//
// reshape
//

void reshape( int w, int h )
{
    glViewport( 0, 0, w, h );
    
    mat4  projection;
    if (w <= h)
        projection = Ortho(-1.0, 1.0, -1.0 * (GLfloat) h / (GLfloat) w,
                           1.0 * (GLfloat) h / (GLfloat) w, -1.0, 1.0);
    else  projection = Ortho(-1.0* (GLfloat) w / (GLfloat) h, 1.0 *
                             (GLfloat) w / (GLfloat) h, -1.0, 1.0, -1.0, 1.0);
    glUniformMatrix4fv( Projection, 1, GL_TRUE, projection );
    
}

//----------------------------------------------------------------------------
/*
void mouse( int button, int state, int x, int y )
{
    if ( state == GLUT_DOWN ) {
        switch( button ) {
            case GLUT_LEFT_BUTTON:    Axis = Xaxis;  break;
            case GLUT_MIDDLE_BUTTON:  Axis = Yaxis;  break;
            case GLUT_RIGHT_BUTTON:   Axis = Zaxis;  break;
        }
    }
}
*/
int secs = 0;
int seq = 0;
//----------------------------------------------------------------------------
void timer( int p )
{
   
    
    if(seq != 9){
        secs++;
    } else {
        secs = 9;
    }
    if(secs % 2 == 0){
        
            if(movementSequence[seq] == 0){
                //while(anotherKeyIsActive);
                if(!anotherKeyIsActive){ // button D
                    anotherKeyIsActive = true;
                    keyDPressed = true;
                    ViewerRotation[Yaxis] += 1.0;
                    //aCounter++;
                    //dCounter++;
                }
            }
            else if(movementSequence[seq] == 1){
                //while(anotherKeyIsActive);
                if(!anotherKeyIsActive){ // button R
                    anotherKeyIsActive = true;
                    Theta[Xaxis] += 1.0;
                    keyRPressed = true;
                }
            }
            else if(movementSequence[seq] == 2){
                //while(anotherKeyIsActive);
                if(!anotherKeyIsActive){
                    anotherKeyIsActive = true;
                    Theta[Zaxis] += 1.0;
                    keyFPressed = true;
                }
            }
            
        seq++;
    }
    glutTimerFunc(1000,timer,0);
    std::cout << secs << std::endl;
}

//---------------------------------------------------------------------
void initialRandomization(){
    
    std::random_shuffle(std::begin(movementSequence), std::end(movementSequence));
    printArray(movementSequence);
    glutTimerFunc(1000,timer,0);
    
}
//----------------------------------------------------------------------------

int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode(  GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 512, 512 );
    glutCreateWindow( "Project 2 - 0054129" );
    std::cout << "Hello";
    
    init();
    
    glutDisplayFunc( display ); // set display callback function
    glutReshapeFunc( reshape );
    glutIdleFunc( idle );
    glutMouseFunc( mouse );
    glutKeyboardFunc(keyboard);
    
    //glutTimerFunc(5,timer,0);
    
    
    glutMainLoop();
    return 0;
}



