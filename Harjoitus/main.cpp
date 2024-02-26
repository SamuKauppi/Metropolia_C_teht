#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;


vector<int> frequencySort(vector<int>& nums) {
	unordered_map<int, int> values;

	for (int i = 0; i < nums.size(); i++)
	{
		values[nums[i]] += 1;
	}
	vector<int> sort_nums;
	sort_nums.reserve(values.size());
	while (values.size() > 0)
	{
		int key = INT_MAX;
		int count = INT_MAX;
		for (auto const& x : values)
		{
			if (x.second < count || (x.second == count && x.first > key))
			{
				key = x.first;
				count = x.second;
			}
		}

		values.erase(key);

		for (int j = 0; j < count; j++)
		{
			sort_nums.push_back(key);
		}
	}

	return sort_nums;
}

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
	unordered_map<int, int> m;

	vector<int> ans;
	ans.reserve(arr1.size() + arr2.size());

	vector<int> unique;

	for (int i = 0; i < arr1.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < arr2.size(); j++)
		{
			if (arr1[i] == arr2[j])
			{
				m[arr2[j]]++;
				found = true;
			}
		}

		if (!found)
		{
			unique.push_back(arr1[i]);
		}
	}

	int index = 0;
	while (index < arr2.size())
	{
		int key = 0;
		int count = 0;
		for (auto const& x : m)
		{
			if (x.first == arr2[index])
			{
				key = x.first;
				count = x.second;
				break;
			}
		}

		m.erase(key);

		for (int i = 0; i < count; i++)
		{
			ans.push_back(key);
		}

		index++;
	}

	sort(unique.begin(), unique.end());
	ans.insert(ans.end(), unique.begin(), unique.end());

	return ans;
}



struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void insertAfter(ListNode* prev_node, int new_data)
{
	// 1. Check if the given prev_node is NULL
	if (prev_node == NULL) {
		cout << "The given previous node cannot be NULL";
		return;
	}

	// 2. Allocate new node
	ListNode* new_node = new ListNode();

	// 3. Put in the data
	new_node->val = new_data;

	// 4. Make next of new node as
	// next of prev_node
	new_node->next = prev_node->next;

	// 5. move the next of prev_node
	// as new_node
	prev_node->next = new_node;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

	ListNode dummy(0);
	ListNode* current = &dummy;

	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			current->next = list1;
			list1 = list1->next;
		}
		else
		{
			current->next = list2;
			list2 = list2->next;
		}

		current = current->next;
	}

	if (list1)
	{
		current->next = list1;
	}
	else
	{
		current->next = list2;
	}

	return dummy.next;
}



int main()
{
	//vector<int> nums1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
	//vector<int> nums2 = { 2,1,4,3,9,6 };

	//vector<int> nums3 = relativeSortArray(nums1, nums2);

	ListNode* s4 = new ListNode(15, nullptr);
	ListNode* s3 = new ListNode(12, s4);
	ListNode* s2 = new ListNode(5, s3);
	ListNode* s1 = new ListNode(2, s2);


	ListNode* s24 = new ListNode(111, nullptr);
	ListNode* s23 = new ListNode(23, s24);
	ListNode* s22 = new ListNode(5, s23);
	ListNode* s21 = new ListNode(1, s22);

	mergeTwoLists(s1, s21);

	return 0;
}