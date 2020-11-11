#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Alg_3_1/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Tests)
	{
	public:
		List* lst1;
		List* lst2;
		//before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			lst1 = new List();
			lst2 = new List();
		}
		//after each test
		TEST_METHOD_CLEANUP(cleanUP)
		{
			delete lst1;
			delete lst2;
		}

		TEST_METHOD(correct_push_back)
		{
			lst1->push_back(100);
			lst2->push_back(100);
			Assert::AreEqual(lst1->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_push_front)
		{
			lst1->push_front(24);
			lst2->push_front(45);
			Assert::AreEqual(lst1->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_pop_back)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			lst2->push_back(4);
			lst2->push_back(5);
			lst1->pop_back();
			Assert::AreEqual(lst1->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_pop_front)
		{
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			lst2->push_back(4);
			lst2->push_back(5);
			lst1->pop_front();
			Assert::AreEqual(lst1->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_insert)
		{
			size_t size = 3;
			lst1->push_front(1);
			lst1->push_front(3);
			lst1->insert(1, 2);
			Assert::AreEqual(lst1->get_size(), size);
		}

		TEST_METHOD(correct_at)
		{
			lst1->push_back(46);
			lst1->push_back(2);
			lst1->push_back(35);
			Assert::AreEqual(lst1->at(1), 2);
		}

		TEST_METHOD(correct_remove)
		{
			size_t size = 1;
			lst1->push_front(1);
			lst1->push_front(3);
			lst1->remove(1);
			Assert::AreEqual(lst1->get_size(), size);
		}

		TEST_METHOD(correct_get_size)
		{
			size_t size = 3;
			lst1->push_back(1);
			lst1->push_back(2);
			lst1->push_back(3);
			Assert::AreEqual(lst1->get_size(), size);
		}

		TEST_METHOD(correct_clear)
		{
			size_t size = 0;
			lst1->push_front(12);
			lst1->push_front(11);
			lst1->push_front(10);
			lst1->clear();
			Assert::AreEqual(lst1->get_size(),size);
		}

		TEST_METHOD(correct_set)
		{
			size_t size = 3;
			lst1->push_front(12);
			lst1->push_front(11);
			lst1->push_front(10);
			lst1->set(1, 3);
			Assert::AreEqual(lst1->get_size(), size);
		}

		TEST_METHOD(correct_is_Empty)
		{
			lst1->push_front(100);
			lst1->push_front(100);
			Assert::AreEqual(lst1->isEmpty(), true);
		}

		TEST_METHOD(correct_find_last)
		{
			lst1->push_front(12);
			lst1->push_front(11);
			lst1->push_front(10);
			lst2->push_front(12);
			Assert::AreEqual(lst1->find_last(*lst2), 2);
		}

		TEST_METHOD(incorrect_index_at)
		{
			try
			{
				lst1->at(-1);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}
	};
}
