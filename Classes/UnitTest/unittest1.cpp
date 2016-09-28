#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Classes\Circle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSetGetRadius)
		{
			Circle firstCircle;
			firstCircle.setRadius(10);
			Assert::AreEqual(10.0, firstCircle.getRadius());
		}

		TEST_METHOD(TestArea)
		{
			Circle firstCircle;
			firstCircle.setRadius(10);
			Assert::AreEqual((10.0*10.0*3.14159), firstCircle.area());
		}

		TEST_METHOD(TestVolume)
		{
			Circle firstCircle;
			firstCircle.setRadius(10);
			Assert::AreEqual((4.0/3.0*1000.0*3.14159), firstCircle.getVolume());
		}
	};
}