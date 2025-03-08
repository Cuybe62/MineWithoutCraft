#ifndef ARRAY3D_H__
#define ARRAY3D_H__

#include "define.h"

template <class T>
class Array3d
{
    public:
        Array3d(int x, int y, int z);
        ~Array3d();
        Array3d(const Array3d& array);

        void Set(int x, int y, int z, const  T& type);
        BlockType Get(int x, int y, int z) const;

        void Reset(const T& type);

    private:
        int To1dIndex(int x, int y, int z) const;
    private:
        int m_x, m_y, m_z;
        BlockType* m_blocks;
};

template <class T>
Array3d<T>::Array3d(int x, int y, int z) : m_x(x), m_y(y), m_z(z)
{
    m_blocks = new BlockType[m_x * m_y * m_z];

    Reset(BTYPE_AIR);
}
template <class T>
Array3d<T>::~Array3d()
{
    delete[] m_blocks;
}

template <class T>
Array3d<T>::Array3d(const Array3d& array) : m_x(array.m_x), m_y(array.m_y), m_z(array.m_z)
{
    m_blocks = new BlockType[m_x * m_y * m_z];
    for (int i = 0; i < m_x * m_y * m_z; ++i)
        m_blocks[i] = array.m_blocks[i];
}

template <class T>
void Array3d<T>::Set(int x, int y, int z,const T& type)
{
    m_blocks[To1dIndex(x, y, z)] = type;
}

template <class T>
BlockType Array3d<T>::Get(int x, int y, int z) const
{
    return m_blocks[To1dIndex(x, y, z)];
}

template <class T>
void Array3d<T>::Reset(const T& type)
{
    for (int i = 0; i < m_x * m_y * m_z; ++i)
        m_blocks[i] = type;
}

template <class T>
int Array3d<T>::To1dIndex(int x, int y, int z) const
{
    return x + (z * m_x) + (y * m_z * m_x);
}


#endif // ARRAY3d_H__
