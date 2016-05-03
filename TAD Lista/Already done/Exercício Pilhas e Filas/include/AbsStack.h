template < class Object >
class AbsStack
{
	public:
		AbsStack() { /* Empty */ }
		virtual ~AbsStack() { /* Empty */ }

		//Basic Members
		virtual void push( const Object & x ) = 0;
		virtual Object pop() = 0;
		virtual Object top() = 0;

		virtual bool isEmpty() const = 0;
		virtual void makeEmpty() = 0;

	private:
	//Disable copy constructor
	AbsStack( const AbsStack & ) { /* Empty */}
};