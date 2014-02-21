// -*- mode: c++; c-basic-offset: 4; c-basic-style: bsd; -*-
/*
*   This program is free software; you can redistribute it and/or
*   modify
*   it under the terms of the GNU Lesser General Public License as
*   published by the Free Software Foundation; either version 3.0 of
*   the License, or (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public
*   License along with this library; if not, write to the Free Software
*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
*   02111-1307 USA
*
*/
#ifndef __NET_PACKET
#define __NET_PACKET

#include <exception>

namespace csu
{
namespace base
{
namespace comm
{

namespace detail
{
    struct empty_type
    {
        struct empty_type_serialization_exception :
                public std::exception
        {};
    };

    // Base serialization traits class
    template <typename T>
            struct serialization_traits
    {
        T& t_;

        serialization_traits (T& t)
            : t_ (t)
        {
        }

        template <class Ar>
                void serialize(Ar & ar, const unsigned int /*version*/)
        {
            ar & t_;
        }
    };

    // Specialization for the empty type (do nothing).
    template <>
            struct serialization_traits<empty_type>
    {
        serialization_traits (empty_type&)
        {
        }

        template <class Ar>
                void serialize(Ar & ar, const unsigned int /*version*/)
        {
            //throw an exception if empty_type is derialize
            //or deserialized
            throw empty_type::empty_type_serialization_exception();
        }
    };

}

template <typename T0,
typename T1 = detail::empty_type,
typename T2 = detail::empty_type,
typename T3 = detail::empty_type,
typename T4 = detail::empty_type,
typename T5 = detail::empty_type,
typename T6 = detail::empty_type,
typename T7 = detail::empty_type,
typename T8 = detail::empty_type,
typename T9 = detail::empty_type>
              class net_packet
              {
    int id_;

    T0* t0;
    T1* t1;
    T2* t2;
    T3* t3;
    T4* t4;
    T5* t5;
    T6* t6;
    T7* t7;
    T8* t8;
    T9* t9;

              public:
    // ctors
    net_packet()
    {
        id_=-1;
    }

    net_packet (int i, T0* v0, T1* v1=0, T2* v2=0, T3* v3=0, T4* v4=0,
                T5* v5=0, T6* v6=0, T7* v7=0, T8* v8=0, T9* v9=0)
    {
        id_ = i;
        t0 = v0; t1 = v1; t2 = v2; t3 = v3; t4 = v4;
        t5 = v5; t6 = v6; t7 = v7; t8 = v8; t9 = v9;
    }

    net_packet (T0* v0, T1* v1=0, T2* v2=0, T3* v3=0, T4* v4=0,
                T5* v5=0, T6* v6=0, T7* v7=0, T8* v8=0, T9* v9=0)
    {
        id_ = -1;
        t0 = v0; t1 = v1; t2 = v2; t3 = v3; t4 = v4;
        t5 = v5; t6 = v6; t7 = v7; t8 = v8; t9 = v9;
    }

    inline int
            id() const
    {
        return id_;
    }

    inline void
            id(int _id)
    {
        id_ = _id;
    }

    // serialize
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        // ID
        ar & id_;

        // TODO: how to implement this better? maybe boost
        // preprocessor macros?
        switch (id_)
        {
        case 0:
            {
                detail::serialization_traits<T0> s (*t0);
                ar & s;
            }
            break;
        case 1:
            {
                detail::serialization_traits<T1> s (*t1);
                ar & s;
            }
            break;
        case 2:
            {
                detail::serialization_traits<T2> s (*t2);
                ar & s;
            }
            break;
        case 3:
            {
                detail::serialization_traits<T3> s (*t3);
                ar & s;
            }
            break;
        case 4:
            {
                detail::serialization_traits<T4> s (*t4);
                ar & s;
            }
            break;
        case 5:
            {
                detail::serialization_traits<T5> s (*t5);
                ar & s;
            }
            break;
        case 6:
            {
                detail::serialization_traits<T6> s (*t6);
                ar & s;
            }
            break;
        case 7:
            {
                detail::serialization_traits<T7> s (*t7);
                ar & s;
            }
            break;
        case 8:
            {
                detail::serialization_traits<T8> s (*t8);
                ar & s;
            }
            break;
        case 9:
            {
                detail::serialization_traits<T9> s (*t9);
                ar & s;
            }
            break;
        }
    }
};

} // comm
} // base
} // csu


#endif // __NET_PACKET
