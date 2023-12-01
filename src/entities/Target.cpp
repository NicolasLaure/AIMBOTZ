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
		const int UPPER_LIMIT = 58;


		void Init()
		{
			SetRadius(radius);
			ResetPosition();
		}

		void ResetPosition()
		{
			target::SetPosition(utilities::GetRandomVector2(target::GetRadius() * 2, 0, UPPER_LIMIT));
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
