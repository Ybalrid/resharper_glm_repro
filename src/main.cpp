#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

int main()
{
	//This 3D vector is a point, as part of a 3D model (for example)
	glm::vec3 some_point_in_space{1.f, 2.f, 0.f};

	//Here's a series of matrices
	glm::mat4 model{1.f}, view{1.f}, projection{1.f};

	//The supposed 3D model is translated 1 unit towards negative X
	model = glm::translate(model, glm::vec3(-1.f, 0, 0));

	//A  camera is at point (5, 5, 5), is looking at point(0, 0, 0) and the Y axis is the general "up" direction
	view = glm::lookAt(glm::vec3(5.f, 5.f, 5.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
	//That camera has a 16:9 aspect ratio, as a 45° view angle, and see everything between 0.1 units and 100 units of depths
	projection = glm::perspective(glm::radians(45.f), float(1920) / float(1080), .1f, 100.f);

	//The point is projected form it's coodinates inside the object to the position of the model, to the space in front of the camera, to the screen
	glm::vec4 result = projection * view * model * glm::vec4(some_point_in_space, 1);

	//Display the resulting 2D vetor coordinates on the backplanes, these are nubmers between -1 and 1
	std::cout << result.x / result.w << ' ' << result.y / result.w << '\n';

	return 0;
}

