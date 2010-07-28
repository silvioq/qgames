/****************************************************************************
 * Copyright (c) 2009-2010 Silvio Quadri                                    *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 ****************************************************************************/

#ifndef  QGAMES_CORE_H
#define  QGAMES_CORE_H 
#if HAVE_VISIBILITY
  #if defined _WIN32 || defined __CYGWIN__
    #ifdef BUILDING_DLL
      #ifdef __GNUC__
        #define DLL_PUBLIC __attribute__((dllexport))
      #else
        #define DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
      #endif
    #else
      #ifdef __GNUC__
        #define DLL_PUBLIC __attribute__((dllimport))
      #else
        #define DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
      #endif
    #endif
    #define DLL_LOCAL
  #else
    #if __GNUC__ >= 4
      #define DLL_PUBLIC __attribute__ ((visibility("default")))
      #define DLL_LOCAL  __attribute__ ((visibility("hidden")))
    #else
      #define DLL_PUBLIC
      #define DLL_LOCAL
    #endif
  #endif
#else
  #define DLL_PUBLIC
  #define DLL_LOCAL
#endif

#endif  // QGAMES_CORE_H
