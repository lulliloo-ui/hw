template< class T>
struct BiList {
  T val;
  BiList< T > * next;
  BiList< T > * prev;
};

template< class T >
BiList< T > * add(BiList< T > * h,  const T & v);

template< class T >
BiList< T > * insert_after(BiList< T > * h, const T & v);

template< class T >
BiList< T > * insert_before(BiList< T > * h, const T & v);

template< class T >
BiList< T > * erase_after(BiList< T > * h) noexcept;

template< class T >
BiList< T > * erase_before(BiList< T > * h) noexcept;

template< class T >
BiList< T > * clear(BiList< T > * h, BiList< T > * e) noexcept;

template< class T >
BiList< T > * clear_all(BiList< T > * h) noexcept;

template< class T >
BiList< T > * next(BiList< T > * h) noexcept;

template< class T >
BiList< T > * prev(BiList< T > * h) noexcept;


int main()
{}