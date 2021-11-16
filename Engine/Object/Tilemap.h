#pragma once
#include "Object/Object.h"
#include "Core/Serializable.h"
#include <vector>

namespace nc {
	class Tilemap : public Object, public ISserializable {
	public:
		void Create() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public: 
		class Scene* scene = nullptr;

	private:
		int numTilesX = 0;
		int numTilesY = 0;
		glm::vec2 size;
		glm::vec2 start;
		std::vector<std::string> tileNames;
		std::vector<int> tiles;
	};
}
