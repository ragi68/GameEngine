
#include "PrecompiledHeaders.h"
#include "Cameras.h"

#include "glm/gtc/matrix_transform.hpp"



Proto::Camera3D::Camera3D(float fov, float aspect_ratio, float n, float f) : p_Matrix(glm::perspective(fov, aspect_ratio, n, f))
{
	v_Matrix = glm::mat4(1);

	vp_Matrix = p_Matrix * v_Matrix;
}

void Proto::Camera3D::SetPosition(glm::vec3 position)
{
	init_pos = position;
	ReCalculateVPMatrix();
}

void Proto::Camera3D::SetRotation(glm::vec3 rotation)
{
	init_rot = rotation;
	ReCalculateVPMatrix();

}

void Proto::Camera3D::SetProjectionMatrix(float fov, float aspect_ratio, float n, float f)
{
	p_Matrix = glm::perspective(fov, aspect_ratio, n, f);
	vp_Matrix = p_Matrix * v_Matrix; 
}

void Proto::Camera3D::ReCalculateVPMatrix()
{
	glm::mat4 t_Matrix = glm::translate(glm::mat4(1), init_pos) * glm::rotate(glm::mat4(1), init_rot[0], glm::vec3(0, 0, 1));
	t_Matrix = t_Matrix * glm::rotate(glm::mat4(1), init_rot[1], glm::vec3(0, 1, 0));
	t_Matrix = t_Matrix * glm::rotate(glm::mat4(1), init_rot[2], glm::vec3(1, 0, 0));

	v_Matrix = glm::inverse(t_Matrix);
	vp_Matrix = p_Matrix * v_Matrix;
}

//next few functions are just copies of above, but the recalcvpmatrix function only has one t_matrix transform call line

Proto::Camera2D::Camera2D(float fov, float aspect_ratio, float n, float f)
{
}

void Proto::Camera2D::SetPosition(glm::vec3 position)
{
}

void Proto::Camera2D::SetRotation(glm::vec3 rotation)
{
}

void Proto::Camera2D::SetProjectionMatrix(float fov, float aspect_ratio, float n, float f)
{
}

void Proto::Camera2D::ReCalculateVPMatrix()
{
}
