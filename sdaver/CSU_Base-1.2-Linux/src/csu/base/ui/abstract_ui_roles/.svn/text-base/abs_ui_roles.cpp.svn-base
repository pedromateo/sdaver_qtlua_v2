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
*   This file is part of the OHTu-Open Usability Evaluation Framework,
*   http://sourceforge.net/projects/ohtplus/
*
*/

#include "abs_ui_roles.h"

#include <boost/lexical_cast.hpp>

namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_roles {
namespace AUR {

namespace detail
{

// Default case to string
template<typename T>
struct to_string_converter
{
    static std::string convert (T const& t)
    {
        return boost::lexical_cast<std::string>(t);
    }
};

// Specialization to AUI::StringList
template<>
struct to_string_converter<AUI::StringList>
{
    static std::string convert (AUI::StringList const& t)
    {
        std::string retval;
        for (AUI::StringList::const_iterator it = t.begin(); it != t.end();++it)
            retval += *it + ";";
        return retval;
    }
};

// Specialization for string
template<>
struct to_string_converter<std::string>
{
    static std::string convert (std::string const& t)
    {
        return t;
    }
};

// Default case from string
template<typename T>
struct from_string_converter
{
    static T convert (std::string const& s)
    {
        return boost::lexical_cast<T>(s);
    }
};

// Specialization for string
template<>
struct from_string_converter<std::string>
{
    static std::string convert (std::string const& s)
    {
        return s;
    }
};

// Specialization for AUI::StringList
template<>
struct from_string_converter<AUI::StringList>
{
    static AUI::StringList convert (std::string const& s)
    {
        AUI::StringList retval;
        size_t pos = 0;
        do {
            size_t new_pos = s.find (';', pos);
            if (new_pos != std::string::npos)
            {
                retval.push_back (s.substr (pos, new_pos - pos));
                pos = new_pos + 1;
            }
            else
            {
                pos = new_pos;
            }
        } while (pos != std::string::npos);

        return retval;
    }
};

}  // namespace detail


#define ROLE(RN)                                \
    RN::RN (AUI::AbstractWidget*aw) \
        : AbstractUIRole (aw)                   \
    {                                           \
    }                                           \
    RN::~RN()                                   \
    {                                           \
    }                                           \
    bool RN::isValid() const                    \
    {                                           \
        return aw_->hasData ("__" #RN "__");     \
    }                                            \
                                                 \
    void RN::setRole (AUI::AbstractWidget* aw)   \
    {                                            \
        aw->addData ("__" #RN "__", "");         \
    }



#define ROLE_PROPERTY(RN, NAME, TYPE)                   \
    TYPE RN::NAME () const                              \
    {                                                   \
        return detail::from_string_converter<TYPE>::convert (   \
            aw_->getData (#RN "_" #NAME));                      \
    }                                                           \
                                                        \
    void RN::NAME (TYPE const& t)                       \
    {                                                   \
        aw_->addData (#RN "_" #NAME, \
                      detail::to_string_converter<TYPE>::convert (t));  \
    }


#define ROLE_END

#include "abs_ui_roles.def"

#undef ROLE
#undef ROLE_PROPERTY
#undef ROLE_END


/// /////////////////////////////////////////
/// abstract role
/// /////////////////////////////////////////

AbstractUIRole::AbstractUIRole(AUI::AbstractWidget* aw)
    : aw_(aw)
{}


} //
} //
} //
} //
} // csu

