#include "pch.h"
#include "CppUnitTest.h"
#include "D:\121\Основи інженерії ПЗ\LW\3\src\LW-3\LW-3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		
		TEST_METHOD(calculate_get_24_and_5__187point06_returned)
		{
			double x = 24;
			int n = 5;
			double expected = 187.06;
			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(calculate_get_0_and_5__0_returned)
		{
			double x = 0.00;
			int n = 5;
			double expected = 0.00;
			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(calculate_get_minus3_and_5__0_returned)
		{
			double x = -3.00;
			int n = 5;
			double expected = 0.00;
			double actual = calculate(x, n);
			Assert::AreEqual(expected, actual);
		}

	};
	TEST_CLASS(checkValidParams_Tests)
	{
	public:

		TEST_METHOD(checkValidParams_get6_exceptionNotThrown)
		{
			int n = 6;
			try
			{
				checkValidParams(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(checkValidParams_get1_exceptionThrown)
		{
			int n = 1;
			try
			{
				checkValidParams(n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}

	};
}
