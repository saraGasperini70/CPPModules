#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		virtual ~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() { return std::stack<T>::c.begin(); }
		const_iterator begin() const { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
		const_iterator end() const { return std::stack<T>::c.end(); }
		iterator rbegin() { return std::stack<T>::c.rbegin(); }
		const_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
		iterator rend() { return std::stack<T>::c.rend(); }
		const_iterator rend() const { return std::stack<T>::c.rend(); }
		iterator find(const T &value)
		{
			return std::find(begin(), end(), value);
		}
		const_iterator find(const T &value) const
		{
			return std::find(begin(), end(), value);
		}
		bool contains(const T &value) const
		{
			return find(value) != end();
		}
};
#endif
