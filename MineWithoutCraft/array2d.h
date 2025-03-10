#ifndef ARRAY2D_H__
#define ARRAY2D_H__

#include "define.h"

template <class T>
class Array2d
{
public:
    Array2d(int x, int y);
    ~Array2d();
    Array2d(const Array2d& array);

    void Set(int x, int y, T type);
    BlockType Get(int x, int y) const;

    void Reset(T type);

private:
    int To1dIndex(int x, int y) const;
private:
    int m_x, m_y;
    BlockType* m_blocks;
};

template <class T>
Array2d<T>::Array2d(int x, int y) : m_x(x), m_y(y)
{
    m_blocks = new BlockType[m_x * m_y ];

      Reset(BTYPE_AIR);

}
template <class T>
Array2d<T>::~Array2d()
{
    delete[] m_blocks;
}

template <class T>
Array2d<T>::Array2d(const Array2d& array) : m_x(array.m_x), m_y(array.m_y)
{
	m_blocks = new BlockType[m_x * m_y];
	for (int i = 0; i < m_x * m_y; ++i)
		m_blocks[i] = array.m_blocks[i];
}

template <class T>
void Array2d<T>::Set(int x, int y, T type)
{
    m_blocks[To1dIndex(x, y)] = type;
}

template <class T>
BlockType Array2d<T>::Get(int x, int y) const
{
    return m_blocks[To1dIndex(x, y)];
}

template <class T>
void Array2d<T>::Reset(T type)
{
    for (int i = 0; i < m_x * m_y; ++i)
        m_blocks[i] = type;
}

template <class T>
int Array2d<T>::To1dIndex(int x, int y) const
{	
	return x + (y * m_x);
}


#endif // ARRAY2D_H__
