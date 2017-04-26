#include <string>

using namespace std;

class WordDictionary 
{
public:
	/** Initialize your data structure here. */
	WordDictionary() 
	{
		root = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) 
	{
		_addWord(root, word.c_str());
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) const
	{
		return _search(root, word.c_str());
	}

private:
	struct Node
	{
		bool isBack;
		Node *next[26];
		Node()
		{
			isBack = false;
			for (int i = 0; i < 26; i++)
			{
				next[i] = nullptr;
			}
		}
	};
	Node *root;
	//
	void _addWord(Node *curr, const char *str)
	{
		if (str[0] != '\0')
		{
			if (curr->next[str[0] - 'a'] == nullptr)
			{
				curr->next[str[0] - 'a'] = new Node();
			}
			if (str[1] == '\0')
			{
				curr->next[str[0] - 'a']->isBack = true;
			}
			_addWord(curr->next[str[0] - 'a'], str + 1);
		}
	}
	bool _search(Node *curr, const char *str) const
	{
		if (curr == nullptr)
		{
			return false;
		}
		if (str[0] == '\0')
		{
			return curr->isBack;
		}
		//
		if (str[0] == '.')
		{
			bool flag = false;
			for (int i = 0; i < 26; i++)
			{
				flag = flag || _search(curr->next[i], str + 1);
			}
			return flag;
		}
		else
		{
			return _search(curr->next[str[0] - 'a'], str + 1);
		}
	}
};