#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/GameObject.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(slowingObject)
		{
			GameObject* s = new SlowingObject({ { Vect2(2, 2), 'c' } });
			Assert::IsTrue(s->IsSlowing());
			Assert::IsFalse(s->IsIndestructible());
			Assert::IsFalse(s->IsFalling());
		}
		TEST_METHOD(standardObject)
		{
			GameObject* s = new StandardObject({ { Vect2(2, 2), 'c' } });
			Assert::IsFalse(s->IsSlowing());
			Assert::IsFalse(s->IsIndestructible());
			Assert::IsFalse(s->IsFalling());
		}
		TEST_METHOD(fallingObject)
		{
			GameObject* s = new FallingObject({ { Vect2(2, 2), 'c' } });
			Assert::IsFalse(s->IsSlowing());
			Assert::IsFalse(s->IsIndestructible());
			Assert::IsTrue(s->IsFalling());
		}
		TEST_METHOD(indestructibleObject)
		{
			GameObject* s = new IndestructibleObject({ { Vect2(2, 2), 'c' } });
			Assert::IsFalse(s->IsSlowing());
			Assert::IsTrue(s->IsIndestructible());
			Assert::IsFalse(s->IsFalling());
		}
	};
}
