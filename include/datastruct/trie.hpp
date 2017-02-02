#ifndef DATASTRUCT_TRIE_HPP
#define DATASTRUCT_TRIE_HPP

#include <vector>
#include <unordered_map>

namespace datastruct
{
    template<typename String>
    class trie
    {
    private:
        struct node
        {
            std::unordered_map<char, node> children;
            bool end = false;
        };

        node root;

    private: // Private member functions
        void _insert(const String& s, node& root, int i)
        {
            if(root.children.find(s[i]) != root.children.end()) {
                return _insert(s, root.children[s[i]], i + 1);
            }

            root.children.emplace(std::pair<char, node>{ s[i], node() });

            if(i < s.size()) {
                return _insert(s, root.children[s[i]], i + 1);
            }

            root.end = true;
        }

        node * _find_prefix(const String& s, node& root, int i)
        {
            if(root.children.find(s[i]) == root.children.end()) {
                return nullptr;
            }
            
            if(i < s.size() - 1) {
                return _find_prefix(s, root.children[s[i]], i + 1);
            }

            return &root;
        }

        // Use _find_prefix to see if this word's chain exists,
        // then return the prefix node if the node returned is a leaf
        node * _find_word(const String& s, node& root, int i)
        {
            node *prefix = _find_prefix(s, root, i);
            if(prefix) {
                prefix = &prefix->children[s.back()];
            }
            return prefix && prefix->end ? prefix : nullptr;
        }

        // This is not done, it's not functional at all!
        void _remove(const String& s, node& root, int i)
        {
            if(i <= s.size()) {
                if(root.children.find(s[i]) == root.children.end()) {
                    return; // We have a problem, throw something!
                }

                _remove(s, root.children[s[i]], i + 1); // Recurse down

                // This step is executed after the recursion unwrap
                root.children.remove(s[i]);
            }
        }

    public:
        void insert(const String& s)
        {
            _insert(s, root, 0);
        }

        bool find_prefix(const String& prefix)
        {
            return _find_prefix(prefix, root, 0) != nullptr;
        }

        bool find_word(const String& word)
        {
            return _find_word(word, root, 0) != nullptr;
        }

        // Remove a word from the Trie
        void remove(const String& s)
        {
            // Implement removal of word from Trie
        }

        // Implement an in-order traversal of this trie for lex ordering

    };
};

#endif /* DATASTRUCT_TRIE_HPP */
