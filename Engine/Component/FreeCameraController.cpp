#include "FreeCameraController.h"
#include "Engine.h"

namespace nc {
	void FreeCameraController::Update()
	{
		glm::vec3 rotate{ 0 };
		if (owner->scene->engine->Get<InputSystem>()->GetButtonState((int)InputSystem::eMouseButton::Left) == InputSystem::eKeyState::HELD)
		{
			glm::vec2 axis = owner->scene->engine->Get<InputSystem>()->GetMouseRelative() * sensitivity;
			rotate.x -= glm::radians(axis.y);
			rotate.y -= glm::radians(axis.x);
		}

		owner->transform.rotation += rotate;

		glm::vec3 direction{ 0 };
		if (owner->scene->engine->Get<nc::InputSystem>()->GetKeyState(SDL_SCANCODE_A) == nc::InputSystem::eKeyState::HELD) direction.x = -1;
		if (owner->scene->engine->Get<nc::InputSystem>()->GetKeyState(SDL_SCANCODE_D) == nc::InputSystem::eKeyState::HELD) direction.x = 1;
		if (owner->scene->engine->Get<nc::InputSystem>()->GetKeyState(SDL_SCANCODE_W) == nc::InputSystem::eKeyState::HELD) direction.z = -1;
		if (owner->scene->engine->Get<nc::InputSystem>()->GetKeyState(SDL_SCANCODE_S) == nc::InputSystem::eKeyState::HELD) direction.z = 1;
		if (owner->scene->engine->Get<nc::InputSystem>()->GetKeyState(SDL_SCANCODE_E) == nc::InputSystem::eKeyState::HELD) direction.y = 1;
		if (owner->scene->engine->Get<nc::InputSystem>()->GetKeyState(SDL_SCANCODE_Q) == nc::InputSystem::eKeyState::HELD) direction.y = -1;

		glm::quat rotation{ owner->transform.rotation };

		owner->transform.position += (rotation * direction) * speed * owner->scene->engine->time.deltaTime;

	}
	bool FreeCameraController::Write(const rapidjson::Value& value) const
	{
		return false;
	}
	bool FreeCameraController::Read(const rapidjson::Value& value)
	{
		JSON_READ(value, speed);
		JSON_READ(value, sensitivity);

		return false;

	}
}