using size_type = long int;

template < typename T >
class Vector
{
	public:
		/* COMMON METHODS */
		size_type size() const;
		void clear();
		bool empty();
		void push_back( const T & x );
		void pop_back();
		const T & back() const;
		const T & front() const;
		void assign( const T & x );
};

template < typename T >
class Forward_List
{
	public:
		/* COMMON METHODS */
		size_type size() const;
		void clear();
		bool empty();
		void push_back( const T & x );
		void pop_back();
		const T & back() const;
		const T & front() const;
		void assign( const T & x );
};

template < typename T >
class List
{
	public:
		/* COMMON METHODS */
		size_type size() const;
		void clear();
		bool empty();
		void push_back( const T & x );
		void pop_back();
		const T & back() const;
		const T & front() const;
		void assign( const T & x );
};