///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2021 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef ETL_SUCCESSOR_INCLUDED
#define ETL_SUCCESSOR_INCLUDED

#include "platform.h"
#include "nullptr.h"

namespace etl
{
  //***************************************************************************
  /// Adds successor traits to a class.
  /// Also known as 'Chain Of Responsibility'.
  //***************************************************************************
  template <typename T>
  class successor
  {
  public:

    typedef T successor_type;

    //*************************************************************************
    /// Default constructor
    //*************************************************************************
    successor()
      : p_successor(ETL_NULLPTR)
    {
    }

    //*************************************************************************
    /// Construct from a successor type
    //*************************************************************************
    successor(successor_type& s)
      : p_successor(&s)
    {
    }

    //*************************************************************************
    /// Set the successor.
    //*************************************************************************
    void set_successor(successor_type& s)
    {
      p_successor = &s;
    }

    //*************************************************************************
    /// Get the successor.
    //*************************************************************************
    successor_type& get_successor() const
    {
      return *p_successor;
    }

    //*************************************************************************
    /// Do we have a successor?
    //*************************************************************************
    bool has_successor() const
    {
      return (p_successor != ETL_NULLPTR);
    }

  private:

    successor_type* p_successor;
  };
}

#endif
