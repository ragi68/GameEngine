#pragma once

#include "glm/glm.hpp"

namespace Proto {
	class Camera3D {
	public:
		Camera3D() = default;
		Camera3D(float fov, float aspect_ratio, float n, float f);


		glm::vec3 GetPos() { return init_pos; }
		void SetPosition(glm::vec3 position);

		glm::vec3 GetRot() { return init_rot; }
		void SetRotation(glm::vec3 rotation);

		void SetProjectionMatrix(float fov, float aspect_ratio, float n, float f);

		glm::mat4 GetProjectionMatrix() { return p_Matrix; }
		glm::mat4 GetViewMatrix() { return v_Matrix; }
		glm::mat4 GetVPMatrix() { return vp_Matrix; }


		void ReCalculateVPMatrix();

		void PanLeft();
		void PanRight();
		void PanDown();
		void PanUp();


	private:
		glm::mat4 p_Matrix;
		glm::mat4 v_Matrix;
		glm::mat4 vp_Matrix;

		glm::vec3 init_pos = { 0.0f, 0.0f, 0.0f }; //for both init and rotation
		glm::vec3 init_rot = { 0.0f, 0.0f, 0.0f };


	};

	class Camera2D {
	public:

		Camera2D() = default;
		Camera2D(float fov, float aspect_ratio, float n, float f);

		glm::vec3 GetPos() { return pos; }
		void SetPosition(glm::vec3 position);

		float GetRot() { return rotation; }
		void SetRotation(glm::vec3 rotation);

		void SetProjectionMatrix(float fov, float aspect_ratio, float n, float f);

		glm::mat4 GetProjectionMatrix() { return p_Matrix; }
		glm::mat4 GetViewMatrix() { return v_Matrix; }
		glm::mat4 GetVPMatrix() { return vp_Matrix; }


		void ReCalculateVPMatrix();



	private:
		glm::mat4 p_Matrix;
		glm::mat4 v_Matrix;
		glm::mat4 vp_Matrix;

		glm::vec3 pos = { 0.0f, 0.0f, 0.0f };
		float rotation = 0.0f;

	};

	class OrthoCamera {
		//maybe idk
	};
}