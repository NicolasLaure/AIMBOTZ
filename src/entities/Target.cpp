#include "entities/Target.h"

#include "utils/Utilities.h"

namespace aimbotz
{
	namespace target
	{
		struct Target
		{
			float radius;
			Vector2f position;
			Vector2f center;
		};

		static Target target;

		static float radius = 50;

		void Init()
		{
			SetRadius(radius);
			target::SetPosition(utilities::GetRandomVector2(target::GetRadius() * 2));
		}

		void SetRadius(float radius)
		{
			target.radius = radius;
		}
		void SetPosition(Vector2f position)
		{
			target.position = position;
		}

		float GetRadius()
		{
			return target.radius;
		}

		Vector2f GetPosition()
		{
			return target.position;
		}

		Vector2f GetCenter()
		{
			return Vector2f(target.position.x + target.radius, target.position.y + target.radius);
		}
	}
}
