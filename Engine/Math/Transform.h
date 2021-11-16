#pragma once
#include "Math/MathTypes.h"
#include "Core/Serializable.h"

namespace nc{
	struct Transform : public ISserializable {
		glm::vec3 position;
		float rotation;
		glm::vec3 scale;

		glm::vec3 localPosition;
		float localRotation;
		glm::vec3 localScale;

		glm::mat4 matrix;

		Transform() {}
		Transform(const glm::vec3& position, float rotation = 0, float scale = 1) : position{ position }, rotation{ rotation }, scale{ scale }{}

		void Update();
		void Update(const glm::mat4& mx);

		// Inherited via ISserializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};

}