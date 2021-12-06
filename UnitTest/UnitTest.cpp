#include "pch.h"
#include "CppUnitTest.h"
#include"../AISD_LAB2_sem1/AISD_LAB2_sem1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(CountSort)
		{
			char array[10];
			for (int i = 0; i < 10; i++) {
				array[i] = "0123456789ABCD"[rand() % 256];
			}
			countSort(array,10);
			Assert::IsTrue(isSortChar(array, 10));
		}

		TEST_METHOD(QuickSort) {
			int arr[100000];
			int length = 100000;
			for (int i = 0; i < length; i++) {
				arr[i] = rand() % 10;
			}
			quickSort(arr,length);
			Assert::IsTrue(isSort(arr, 100000));
		}

		TEST_METHOD(BogoSort) {
			int length = 10;
			int array[255];
			for (int i = 0; i < length; i++)
			{
				array[i] = rand() % 10;
			}
			bogosort(array, length);

			Assert::IsTrue(isSort(array, 10));
		}

		TEST_METHOD(SearchBinary) {
			int length = 10, index;
			int array[255];
			for (int i = 0; i < length; i++)
			{
				if (i == 2)
				{
					array[2] = 6;
					continue;
				}

				array[i] = rand() % 100;

			}
			quickSort(array, length);
			index = Search_Binary(array, 0, length, 6);

			Assert::IsTrue(index >= 0);
		}

		TEST_METHOD(BubbleSort) {
			int length = 10;
			int array[10U];

			for (int i = 0; i < length; i++)
			{
				array[i] = rand() % 100;
			}
			bubbleSort(array,length);

			Assert::IsTrue(isSort(array, 10));
		}
	};
}
