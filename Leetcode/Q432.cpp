#include <string>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class AllOne 
{
public:
	/** Initialize your data structure here. */
	AllOne() 
	{
		max = new Header();
		min = new Header();
		min->next = max;
		max->prev = min;
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) 
	{
		if (Map.find(key) == Map.end())
		{
			Node *temp = new Node(nullptr, key);
			Map[key] = temp;
			if (min->next != max && min->next->ptr->value == 1)
			{
				temp->parent = min->next;
				min->next->ptr = _insert<Node>(temp, nullptr, min->next->ptr);
			}
			else
			{
				Header *head = new Header();
				temp->parent = head;
				_insert<Header>(head, min, min->next);
				head->ptr = temp;
			}
		}
		else
		{
			Node *temp = Map[key];
			if (temp->parent->ptr == temp)
			{
				temp->parent->ptr = temp->next;
			}
			_delete<Node>(temp);
			Header *head = temp->parent;
			if (head->next != max && head->next->ptr->value == temp->value + 1)
			{
				_insert<Node>(temp, nullptr, head->next->ptr);
				head->next->ptr = temp;
				temp->value++;
				temp->parent = head->next;
			}
			else
			{
				_insert<Header>(new Header(), head, head->next);
				_insert<Node>(temp, head->next->ptr, nullptr);
				head->next->ptr = temp;
				temp->value++;
				temp->parent = head->next;
			}
			if (head->ptr == nullptr)
			{
				_delete<Header>(head);
				delete head;
			}
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) 
	{
		if (Map.find(key) != Map.end())
		{
			Node *temp = Map[key];
			Header *head = temp->parent;
			if (head->ptr == temp)
			{
				head->ptr = temp->next;
			}
			_delete<Node>(temp);
			//
			if (temp->value > 1)
			{
				if (head->prev != min && head->prev->ptr->value == temp->value - 1)
				{
					_insert<Node>(temp, nullptr, head->prev->ptr);
					head->prev->ptr = temp;
					temp->parent = head->prev;
					temp->value--;
				}
				else
				{
					_insert<Header>(new Header(), head->prev, head);
					temp->parent = head->prev;
					head->prev->ptr = temp;
					temp->value--;
				}
				if (head->ptr == nullptr)
				{
					_delete<Header>(head);
					delete head;
				}
			}
			else
			{
				Map.erase(temp->str);
				delete temp;
				if (head->ptr == nullptr)
				{
					_delete<Header>(head);
					delete head;
				}
			}
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() 
	{
		return (max->prev == min) ? string("") : (max->prev->ptr->str);
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() 
	{
		return (min->next == max) ? string("") : (min->next->ptr->str);
	}

private:
	struct Header;
	struct Node
	{
		Node(Header *_parent, string _str, int _value = 1)
		{
			next = nullptr;
			prev = nullptr;
			value = _value;
			str = _str;
			parent = _parent;
			
		}
		Node *next;
		Node *prev;
		int value;
		string str;
		Header *parent;
	};
	struct Header
	{
		Header()
		{
			prev = nullptr;
			next = nullptr;
			ptr = nullptr;
		}
		Header *prev;
		Header *next;
		Node * ptr;
	};
	//
	Header *max;
	Header *min;
	map<string, Node*> Map;
	//
	template <class T>
	static T *_insert(T *curr, T *prev, T *next)
	{
		if (curr)
		{
			curr->next = next;
			curr->prev = prev;
			if (prev)
			{
				prev->next = curr;
			}
			if (next)
			{
				next->prev = curr;
			}
		}
		return curr;
	}
	template <class T>
	static T *_delete(T *curr)
	{
		if (curr)
		{
			T *prev = curr->prev;
			T *next = curr->next;
			if (prev)
			{
				prev->next = next;
			}
			if (next)
			{
				next->prev = prev;
			}
			curr->prev = nullptr;
			curr->next = nullptr;
		}
		return curr;
	}
	//
	public:
	void _print() const
	{
		cout << endl;
		for (Header *curr = min->next; curr != max; curr = curr->next)
		{
			cout << " (" << curr->ptr->value << ") ";
			for (Node *temp = curr->ptr; temp != nullptr; temp = temp->next)
			{
				cout << temp->str << "   ";
			}
			cout << endl;
		}
		cout << endl;
	}
};
