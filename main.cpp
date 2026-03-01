#include<iostream>
//1. неявный интерфейс
//конструктор копирования
//присваивание
//диструктор

//2.
template< class T>
struct BiList {
  T val;
  BiList< T > * next;
  BiList< T > * prev;
};

template< class T >
BiList< T > * create(const T & v);

template< class T >
size_t size(BiList< T > * h);

template< class T >
BiList< T > * insert_after(BiList< T > * h, const T & v);

template< class T >
BiList< T > * insert_before(BiList< T > * h, const T & v);

template< class T >
BiList< T > * cut(BiList< T > * h) noexcept;

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

//3.

template< class T >
BiList< T > * create(const T & v)
{
  BiList< T > * ret = new BiList< T >{v, nullptr, nullptr};
  ret->next = ret;
  ret->prev = ret;
  return ret;
}

template< class T >
size_t size(BiList< T > * h)
{
  BiList< T > * a = h->next;
  size_t count = 1;
  while (a != h) {
    count++;
    a = a->next;
  }
  return count;
}

template< class T >
BiList< T > * insert_after(BiList< T > * h, const T & v) {
  BiList< T > * a = new BiList< T > {v, h->next, h};
  h->next = a;
  a->next->prev = a;
  return a;
}

template< class T >
BiList< T > * insert_before(BiList< T > * h, const T & v)
{
  BiList< T > * a = new BiList< T > {v, h, h->prev};
  h->prev = a;
  a->prev->next = a;
  return a;
}

template< class T >
BiList< T > * cut(BiList< T > * h) noexcept
{
  if (h->next == h) {
    delete h;
    return nullptr;
  }
  BiList< T > * ret = h->next;
  h->prev->next = ret;
  ret->prev = h->prev;
  delete h;
  return ret;
}

template< class T >
BiList< T > * erase_after(BiList< T > * h) noexcept
{
  BiList< T > * ret = h->next;
  ret = cut(ret);
  return ret;
}
template< class T >
BiList< T > * erase_before(BiList< T > * h) noexcept
{
  BiList< T > * ret = h->prev;
  ret = cut(ret);
  return ret;
}

template< class T >
BiList< T > * clear(BiList< T > * h, BiList< T > * e) noexcept
{
  while(h != e) {
    BiList< T > * n = h->next;
    cut(h);
    h = n;
  }
  return h;
}

template< class T >
BiList< T > * clear_all(BiList< T > * h) noexcept
{
  clear(h->next, h);
  delete h;
  return nullptr;
}

template< class T >
BiList< T > * next(BiList< T > * h) noexcept
{
  return h->next;
}

template< class T >
BiList< T > * prev(BiList< T > * h) noexcept
{
  return h->prev;
}


int main()
{}