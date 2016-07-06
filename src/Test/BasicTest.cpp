#include "BasicTest.h"

namespace MINI_STL
{
	namespace BasicTest{
		
		void heapTest()
		{
			int ia[9] = {0,1,2,3,4,8,9,3,5};
			MINI_STL::vector<int> vec(ia,ia+9);
			std::vector<int> vecTest(ia,ia+9);
			MINI_STL::make_heap(vec.begin(),vec.end());
			std::make_heap(vecTest.begin(),vecTest.end());
			assert(MINI_STL::Test::container_equal(vec, vecTest));

			vec.push_back(7);
			vecTest.push_back(7);
			MINI_STL::push_heap(vec.begin(),vec.end());
			std::push_heap(vecTest.begin(),vecTest.end());
			assert(MINI_STL::Test::container_equal(vec, vecTest));

			MINI_STL::pop_heap(vec.begin(),vec.end());
			std::pop_heap(vecTest.begin(),vecTest.end());
			vec.pop_back();
			vecTest.pop_back();
			assert(MINI_STL::Test::container_equal(vec, vecTest));

			MINI_STL::sort_heap(vec.begin(),vec.end());
			std::sort_heap(vecTest.begin(),vecTest.end());
			assert(MINI_STL::Test::container_equal(vec, vecTest));
		}


		void slist_test()
		{
			MINI_STL::slist<int> sl;
			std::forward_list<int> fl;
			assert(sl.size()==0);

			sl.push_front(9);
			sl.push_front(1);
			sl.push_front(2);
			sl.push_front(3);
			sl.push_front(4);

			fl.push_front(9);
			fl.push_front(1);
			fl.push_front(2);
			fl.push_front(3);
			fl.push_front(4);
			assert(sl.size()==5);
			assert(MINI_STL::Test::container_equal(sl,fl));



			auto it = find(sl.begin(),sl.end(),1);
			auto fit = MINI_STL::find(fl.begin(),fl.end(),2);
			if (it!=nullptr)
			{
				sl.insert(it,99);
				fl.insert_after(fit,99);
			}
			assert(sl.size()==6);
			assert(*it==1);
			assert(MINI_STL::Test::container_equal(sl,fl));

			it = find(sl.begin(),sl.end(),3);
			fit =  MINI_STL::find(fl.begin(),fl.end(),4);
			if (it!=nullptr)
			{
				assert(*(sl.erase(it))==2);
				fl.erase_after(fit);
			}
			assert(MINI_STL::Test::container_equal(sl,fl));

		}

		void rbtree_test()
		{
			RBTree<int,int,MINI_STL::identity<int>,MINI_STL::less<int>> tree;
			assert(tree.size()==0);
			tree.insert_unique(10);
			tree.insert_unique(7);
			tree.insert_unique(8);

			tree.insert_unique(15);
			tree.insert_unique(5);
			tree.insert_unique(6);

			tree.insert_unique(11);

			tree.insert_unique(13);
			tree.insert_unique(12);

			assert(tree.size()==9);
			int a[9] = {5,6,7,8,10,11,12,13,15};
			assert(MINI_STL::Test::container_equal(a,tree));
			/*auto it1 = tree.begin();
			auto it2 = tree.end();
			while (it1!=it2)
			{
				std::cout<<*it1<<" ";
				++it1;
			}
			std::cout<<std::endl;*/

			bool b[9] = {false,true,false,true,true,false,false,true,false};
			bool result[9] ;

			int index = 0;
			auto it1 = tree.begin();
			auto it2 = tree.end();
			while (it1!=it2)
			{
				//std::cout<<*it1<<"("<<RBTree_iterator_base(it1).node->color<<")"<<" ";
				result[index++] = RBTree_iterator_base(it1).node->color;
				++it1;
			}
			assert(MINI_STL::Test::container_equal(b,result));
		}
		void testAllCases()
		{
			rbtree_test();
			heapTest();
			slist_test();	
		}
	}
}