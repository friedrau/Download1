//#include <stdio.h>
//#include <string>
//#define _USE_MATH_DEFINES
//#include <cmath>
//
//#define GLM_FORCE_RADIANS
//#include "glm/vec2.hpp"
//#include "glm/vec3.hpp"
//#include "glm/mat4x4.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/matrix_inverse.hpp"

glm::vec3
WhatPartOfALivesInBDir(glm::vec3 a, glm::vec3 b)
{
//Formula (A*B(unitVec))*B(unitVec)
//Get Unit Vector
//buv == B unit Vector or B hat or B^
	glm::vec3 buv = glm::normalize(b); //Get Bhat B^
	float dotProd = glm::dot(a, buv); // Get dot (A*B^)
	return buv * dotProd; //Final Equation (A*B^)*B^
	
}


glm::vec3
WhatPartOfALivesPerpToB( glm::vec3 a, glm::vec3 b )
{
	//A - (A*B^)*B^
	return a - WhatPartOfALivesInBDir(a, b);
}


glm::vec3
UnitSurfaceNormal( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
// n = (R-Q) * (S-Q)

	glm::vec3 cp = glm::cross((r-q),(s-q)); //get cross product

	return normalize(cp); //return direction of fave by creating unit vec

}


float
Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	glm::vec3 cp = glm::cross((r - q), (s - q)); //get cross product
	float area = .5 * glm::length(cp);
	return area;
}


bool
IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	// n = (R-Q) * (S-Q)
	// nq = (R-Q) * (P-Q)
	// nr = (S-R) * (P-R)
	// ns = (Q-S) * (P-S)
	glm::vec3 n = glm::cross((r - q), (s - q)); //get cross product
	glm::vec3 nq = glm::cross((r - q), (p - q)); //get cross product
	glm::vec3 nr = glm::cross((s - r), (p - r)); //get cross product
	glm::vec3 ns = glm::cross((q - s), (p - s)); //get cross product

	if (glm::dot(n, nq) >= 0 && glm::dot(n, nr) >= 0 && glm::dot(n, ns) >= 0) {
		return true;
	}
	else {
		return false;
	}


}



float
DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
	float dotProd = glm::dot((p - q), UnitSurfaceNormal(q,r,s)); 
	return dotProd;

}


void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Austin Friedrich";
	yourEmailAddress = "Friedrau@oregonstate.edu" ;
}
