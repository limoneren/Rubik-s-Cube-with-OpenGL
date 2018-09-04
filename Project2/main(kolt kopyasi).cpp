//--------------------------------------------------------------------------//
//                                                                          //
//  Project Assignment 2 - Eren Limon - 0054129                             //
//                                                                          //
//--------------------------------------------------------------------------//
//
//  Display a rotating cube, around fixed axes
//

#include "Angel.h"

typedef vec4  color4;
typedef vec4  point4;

const int NumVertices = 36;

point4 pointsCube_1[NumVertices];
color4 colorsCube_1[NumVertices];
mat4  Model_view[27];

GLfloat offsetBetweenCubes = 0.05;
GLfloat squareEdge = 0.4;

point4 Points[27][NumVertices] = {};
point4 VerticesCube[27][8] = {};

point4 Colors[27][NumVertices] = {};

point4 distanceXToCentralCube[27] = {
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
point4 distanceYToCentralCube[27] = {
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
point4 distanceZToCentralCube[27] = {
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

void fillVertexArrays(){
    
    for(int i = 0; i < 27; i++){
        
        
        for(int j = 0; j < 9 ; j++){
            
            VerticesCube[i][j]   = verticesCube_1[j] + distanceXToCentralCube[i] + distanceYToCentralCube[i] + distanceZToCentralCube[i];
            //std::cout << VerticesCube[i][j] << std::endl;
            
        }
         //std::cout << std::endl;
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


// RGBA olors
color4 ColorsCube[27][6] = {
    
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
    }
};

// Array of rotation angles (in degrees) for each coordinate axis
enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
int  Axis = Xaxis;
//GLfloat  Theta[NumAxes] = { 30.0, -40.0, 0.0 };
GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 };
GLfloat ViewerRotation[NumAxes] = {0.0, 0.0, 0.0};


// Model-view and projection matrices uniform location
GLuint  ModelView, Projection;




//----------------------------------------------------------------------------

// quad generates two triangles for each face and assigns colors
//    to the vertices

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

// generate 12 triangles: 36 vertices and 36 colors
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

//----------------------------------------------------------------------------

// OpenGL initialization
GLuint vaoArray[27];
GLuint buffer;

void
init()
{
    fillVertexArrays();
    GLuint vPosition;
    GLuint vColor;
    
    for(int i = 0; i < 27; i++){
        
        colorcube(i);
        
    }
    
    
    GLuint program = InitShader( "vshader.glsl", "fshader.glsl" );
    const vec3 displacement( 0.0, 0.0, 0.0 );
    
    // Create a vertex array object
    glGenVertexArrays( 27, vaoArray );
    for (int i = 0; i < 27; i++) {
        
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
        
        
        //Model_view[i] =  Translate( displacement ) * RotateX( 30.0 ) * RotateY( -40.0 ) *
        //RotateZ( 0.0 ) * Translate( -displacement );
    }
    
    // Retrieve uniform variable locations
    ModelView = glGetUniformLocation( program, "ModelView" );
    Projection = glGetUniformLocation( program, "Projection" );
    
    // Set current program object
    glUseProgram( program );
   ;
    
    
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
bool keyRPressed = false;
bool lockForYView = false;
bool lockForThetaX = false;

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
                Model_view[i] =  RotateX( 2.0 ) * Model_view[i];
                if(i == 26){
                    lockForThetaX = false;
                }
            }
            
            if(keyRPressed){
                Model_view[i] =  RotateX( 1.0 ) * Model_view[i];
            }
            
            
           
            
        } else {
            //Model_view[i] =  RotateY( 1 ) * Model_view[i];
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
            Model_view[i] = RotateY( 2.0 ) *  Model_view[i];
            if(i == 26){
                lockForYView = false;
            }
        }
        if(keyDPressed && !keyAPressed){ // user rotates around Y
            /*Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) * RotateX( ViewerRotation[Xaxis] ) *
                             RotateY( ViewerRotation[Yaxis] ) * RotateX( ViewerRotation[Zaxis] ) );*/
            Model_view[i] = RotateY( 1.0 ) *  Model_view[i];
            
        }
        
        if(keyAPressed && !keyDPressed){
            Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) * RotateX( ViewerRotation[Xaxis] ) *
                             RotateY( ViewerRotation[Yaxis] ) * RotateX( ViewerRotation[Zaxis] ) );
        }
        
        if(keyWPressed && !keySPressed){ // user rotates around X
            Model_view[i] = ( Scale(1.0, 1.0, 1.0) * Translate( displacement ) * RotateX( ViewerRotation[Xaxis] ) *
                             RotateY( ViewerRotation[Yaxis] ) * RotateX( ViewerRotation[Zaxis] ) );
        }
        
        if(keySPressed && !keyWPressed){
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
    
    
    if(keyWPressed && !keySPressed && ((int)ViewerRotation[Xaxis] % 90 != 0)){
        ViewerRotation[Xaxis] -= 1.0;
        
        if ( ViewerRotation[Xaxis] <= -360.0 ) {
            ViewerRotation[Xaxis] += 360.0;
        }
        
        if(((int)ViewerRotation[Xaxis] % 90 == 0)){
            keyWPressed = false;
        }
        
    }
    
    if(keySPressed && !keyWPressed && ((int)ViewerRotation[Xaxis] % 90 != 0)){
        ViewerRotation[Xaxis] += 1.0;
        
        if ( ViewerRotation[Xaxis] >= 360.0 ) {
            ViewerRotation[Xaxis] -= 360.0;
        }
        
        if(((int)ViewerRotation[Xaxis] % 90 == 0)){
            keySPressed = false;
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
        
        
        if(!keyDPressed){
            keyAPressed = true;
            ViewerRotation[Yaxis] -= 1.0;
            //aCounter++;
            //dCounter++;
        }
        
    }
    else if(key == 'D' | key == 'd'){
        
        if(!keyAPressed){
            keyDPressed = true;
            ViewerRotation[Yaxis] += 1.0;
            //aCounter++;
            //dCounter++;
        }
    }
    else if(key == 'W' | key == 'w'){
        
        if(!keySPressed){
            keyWPressed = true;
            ViewerRotation[Xaxis] -= 1.0;
            //aCounter++;
            //dCounter++;
        }
    }
    else if(key == 'S' | key == 's'){
        
        if(!keyWPressed){
            keySPressed = true;
            ViewerRotation[Xaxis] += 1.0;
            //aCounter++;
            //dCounter++;
        }
    }
    else if(key == 'R' | key == 'r'){
        
        Theta[Xaxis] += 1.0;
        keyRPressed = true;
        
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

//----------------------------------------------------------------------------
void timer( int p )
{
    /*Theta[Axis] += 2.0;
    if ( Theta[Axis] > 360.0 ) {
        Theta[Axis] -= 360.0;
    }*/
    
    if(keyAPressed){
        Theta[0] = Theta[1] = Theta[2] = 0.0;
        Theta[Axis] = 1.0;
    }
    
    glutPostRedisplay();
    
    glutTimerFunc(5,timer,0);
}


//----------------------------------------------------------------------------

void
arrowInput( int key,int x, int y )
{
    if (key == GLUT_KEY_UP) {
        
        keyAPressed = true;
        
        //Theta[0] = Theta[1] = Theta[2] = 0.0;
        //Theta[Axis] = 1.0;
        
        //std::cout << "Acc: " << acceleration << std::endl;
        
        glutPostRedisplay();
        
        
    } else if (key == GLUT_KEY_DOWN) {
        
        
       
        
        
        //std::cout << "Acc down: " << acceleration << std::endl;
        glutPostRedisplay();
    }
    
    
}


//----------------------------------------------------------------------------

int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode(  GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 512, 512 );
    glutCreateWindow( "Color Cube" );
    
    init();
    
    glutDisplayFunc( display ); // set display callback function
    glutReshapeFunc( reshape );
    glutIdleFunc( idle );
    glutMouseFunc( mouse );
    glutKeyboardFunc(keyboard);
    
    glutSpecialFunc(arrowInput);
    
    //glutTimerFunc(5,timer,0);
    
    
    glutMainLoop();
    return 0;
}



