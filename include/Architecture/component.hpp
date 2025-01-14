#pragma once

#include "SFML/Graphics.hpp"

namespace sharbat {

	class Component {
	public:
		virtual ~Component() = default;
	};

	class PositionComponent : public Component {
	public:
		float x, y;

		PositionComponent(float x = 0, float y = 0) : x(x), y(y) {}
	};

	class VelocityComponent : public Component {
	public:
		float vx, vy;

		VelocityComponent(float vx = 0, float vy = 0) : vx(vx), vy(vy) {}
	};

	class SpriteComponent : public Component {
	public:
		sf::Sprite sprite;

		SpriteComponent(const sf::Texture& texture) {
			sprite.setTexture(texture);
		}
	};

	class sizeComponent : public Component {
	public:
		float sx, sy;

		sizeComponent(float sx = 0, float sy = 0) : sx(sx), sy(sy) {}
	};
}