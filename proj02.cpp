#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"

glm::mat4
Multiply(glm::mat4 a, glm::mat4 b)
{
	return a * b;
}



glm::vec3
Multiply(glm::mat4 a, glm::vec3 b)
{
	return a * (b, 1.);
}



glm::vec3
ScalePointAroundAnotherPoint(glm::vec3 inputPoint, glm::vec3 centerPoint, glm::vec3 scale)
{
	glm::vec3 diff = inputPoint - centerPoint; //gets distance from center point.
	glm::mat4 scaledAtCenterpoint = scale(glm::mat4(1.), scale); // scale a default Matrix of size 1 by 
	glm::vec4 putScaledObjectAtCenter = scaledAtCenterpoint * glm::vec4(diff, 1); // Setting the scaled matrix at centerpoint.
	return glm::vec3(putScaledObjectAtCenter) + centerPoint; // reset postion.
}



glm::vec3
RotatePointAroundAnotherPoint(glm::vec3 inputPoint, glm::vec3 centerPoint, glm::mat4 first, glm::mat4 second, glm::mat4 third)
{
	glm::vec3 diff = inputPoint - centerPoint; //gets distance from center point.
	glm::vec4 rotate = first * second * third * glm::vec4(diff, 1); // Setting the rotated postion at centerpoint.
	return glm::vec3(rotate) + centerPoint; // reset postion.
}



void
PrintMatrix(glm::mat4 mat)
{
	for (int row = 0; row < 4; row++)
	{
		fprintf(stderr, "  %7.2f %7.2f %7.2f %7.2f\n", mat[row][0], mat[row][1], mat[row][2], mat[row][3]);
	}
}
void
WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Austin Friedrich";
	yourEmailAddress = "Friedrau@oregonstate.edu" ;
}
