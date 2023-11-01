#include "pch.h"
#include "CppUnitTest.h"
#include"../Lab_6.2.rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab62rec
{
	TEST_CLASS(UnitTestLab62rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int  a[] = { 21,3,8,9,45,16,27,5 };
			int n = 8;
			double p = Average(a, n);
			Assert::AreEqual(p, 24.0);
		}
	};
}
