#ifndef DATASTRUCT_LIST_HPP
#define DATASTRUCT_LIST_HPP

#include <utility>
#include <stdexcept>

namespace datastruct
{
    template<typename T>
    class list
    {
    private:
        struct node
        {
            T data;
            node *next = nullptr;
        };

        node *head = nullptr;
        node *tail = nullptr;
        int n = 0; // List size

    private: /* Private utility functions */

        /* Check head, if it exists, call alternative function f;
        if it doesn't exist, set head and tail to the new node */
        template<typename F>
        void alloc_or(node *temp, F f)
        {
            if(head)
                return f();
            head = tail = temp;
        }

    public:

        void pop_front()
        {
            if(head) {
                auto *temp = head;
                head = head->next;
                delete temp;
                --n;
            }
        }

        /* We will not implement pop_back since it's a linear operation.
        Instead, we will implement erase(index) */
        void erase(int index)
        {
            if(index < 0 || index >= n) {
                throw std::out_of_range("erase(index) out of range");
            }

            node *current = head;
            auto target = [](node *c) { return c->next; };

            for(int i = 0; i < index; ++i) {
                current = current->next;
            }
            // Move the target's next to current's next
            current->next = target(current)->next;

            // Delete the target
            delete target(current);
            --n;
        }

        void push_front(const T& value)
        {
            node *temp = new node { value };
            alloc_or(temp, [&]() {
                temp->next = head;
                head = temp;
            });
            ++n;
        }

        void push_back(const T& value)
        {
            node *temp = new node { value };
            alloc_or(temp, [&]() {
                tail->next = temp;
                tail = temp;
            });
            ++n;
        }

        template<typename... Args>
        void emplace_front(Args&&... args)
        {
            node *temp = new node { T(std::forward<Args>(args)...) };
            alloc_or(temp, [&]() {
                temp->next = head;
                head = temp;
            });
            ++n;
        }

        template<typename... Args>
        void emplace_back(Args&&... args)
        {
            node *temp = new node { T(std::forward<Args>(args)...) };
            alloc_or(temp, [&]() {
                tail->next = temp;
                tail = temp;
            });
            ++n;
        }

        const int size() const
        {
            return n;
        }

    };
};

#endif /* DATASTRUCT_LIST_HPP */

