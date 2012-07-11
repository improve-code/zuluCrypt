/*
 * 
 *  Copyright (c) 2011
 *  name : mhogo mchungu 
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef STRINGLISTTYPE
#define STRINGLISTTYPE

#ifdef __cplusplus
extern "C" {
#endif	

#include "String.h"

typedef struct StringListType * stringList_t ;

/*
 * stringList_t is a type to be used as a handle with these functions
 * 
 * this library implements a an array of strings_t type dynamically and add other functionality
 * 
 */

/*
 *  create stringlist handle with a C string. All stringlist operations should happen through this handle 
 */
stringList_t StringList( const char * cstring ) ;

/*
 *  create stringlist handle with a string_t. All stringlist operations should happen through this handle 
 *  this function will take ownership of st,invalidating the handle after auto deleting its contents
 */
stringList_t StringListString( string_t * ) ;


/*
 * Return the number of elements in the list * 
 */
size_t StringListSize( stringList_t stl ) ;

/*
 * create a  stringlist from splitted cstring using splitter as a splitting trigger. * 
 */
stringList_t StringListSplit( const char * cstring,char splitter ) ;

/*
 * create a stringlist from string_t using splitter as a splitting trigger. 
 * If the operation succeeds( return value is not NULL), st will be deleted.
 * If the operation fail( return value is NULL), st will not be deleted and you have to delete it yourself.
 * If you want to split and not delete st then use StringListSplit()
 */
stringList_t StringListStringSplit( string_t * st,char splitter ) ;

/*
 * return a string_t element at position index.
 * First element is at position 0.
 */
string_t StringListStringAt( stringList_t stl, size_t index ) ;

/*
 *  return a pointer to a string at position index.
 * First element is at position 0. * 
 */
const char * StringListContentAt( stringList_t stl,size_t index ) ;

/*
 * strcmp() a strinf at index with cstring
 */
int StringListContentAtEqual( stringList_t stl,size_t index,const char * cstring );

/*
 * printf() string content at a given index
 */
void StringListPrintAt( stringList_t stl,size_t index ) ;

/*
 * printf() with a new line string content at a given index
 */
void StringListPrintLineAt( stringList_t stl,size_t index ) ;

/*
 *  return a pointer to a string at the last elenent in the list.
 */
const char * StringListContentAtLast( stringList_t stl ) ;

/*
 *  return a string_t at the last elenent in the list.
 */
string_t StringListStringAtLast( stringList_t stl ) ;

/*
 *  return an index position of an element with cstring.
 *  return -1 if there is no element in the list with the string.
 */
ssize_t StringListContains( stringList_t stl,const char * cstring );

/*
 * append an entry into the list.
 * if stl == NULL, then the function call is the same as "StringList( cstring )" 
 */
stringList_t StringListAppend( stringList_t stl,const char * cstring ) ;

/*
 * append an entry into the list.
 * if stl == NULL, then the function call is the same as "StringList( cstring )" 
 * 
 * this function will take ownership of st,invalidating the handle after auto deleting its contents
 * 
 */
stringList_t StringListAppendString( stringList_t stl,string_t * ) ;

/*
 * append an entry into the list by taking only len characters from the string.
 * if stl == NULL, then the function call is the same as "StringList( cstring )" 
 */
stringList_t StringListAppendSize( stringList_t stl,const char * cstring,size_t len ) ;


/*
 * prepend an entry into the list
 * if stl == NULL then the function is the same as "StringList( cstring )" 
 */
stringList_t StringListPrepend( stringList_t stl,const char * cstring ) ;

/*
 * prepend an entry into the list
 * if stl == NULL then the function is the same as "StringList( cstring )" 
 * 
 * this function will take ownership of st,invalidating the handle after auto deleting its contents
 * 
 */
stringList_t StringListPrependString( stringList_t stl,string_t * st ) ;

/*
 * prepend an entry into the list by taking len characters from the string.
 * if stl == NULL then the function is the same as "StringList( cstring )" 
 */
stringList_t StringListPrependSize( stringList_t stl,const char * cstring,size_t len ) ;

/*
 * insert an element as position index.
 * the first position is at position 0
 * the program will most likely crash is stl == NULL
 */
stringList_t StringListInsertAt( stringList_t stl,const char * cstring,size_t index ) ;

/*
 * insert string_t as position index.
 * the first position is at position 0
 * the program will most likely crash is stl == NULL
 * 
 * this function will take ownership of st,invalidating the handle after auto deleting its contents * 
 */
stringList_t StringListStringInsertAt( stringList_t stl,string_t *,size_t index ) ;

/*
 * insert an element as position index by taking only len characters from the string
 * the first position is at position 0
 * the program will most likely crash is stl == NULL
 */
stringList_t StringListInsertAtSize( stringList_t stl,const char * cstring,size_t len, size_t index ) ;

/*
 * remove an entry from the list bt deleting it
 * the first position is at position 0
 */
stringList_t StringListRemoveAt( stringList_t stl, size_t index ) ;

/*
 * remove an entry from the list at position index and "let it free",the detached entry is now a fully fledged string_t object.
 * the first position is at position 0
 */
string_t StringListDetachAt( stringList_t stl, size_t index ) ;

/*
 *  remember to clean after yourself
 *  when function return, stl will point to NULL
 */
void StringListDelete( stringList_t * stl ) ;

/*
 * delete multiple stringList_t * objects.
 * NOTE; The last element on the argument list must be '\0' 
 */
void StringListMultipleDelete( stringList_t * stl,... ) ;

/*
 * find the first element with cstring and remove it and return the position of where the element was.
 * return -1 when there is no element in the list with cstring.
 * call the function repeatedly until you get -1 if elements can repeat.
 */
ssize_t StringListRemoveString( stringList_t stl,const char * cstring ) ;

/*
 * add a cstring to the list and take it over( own it )
 * cstring will be NULL on function return.
 * cstring must be created will malloc.
 */
stringList_t StringListAppendWithSize( stringList_t stl,char ** cstring,size_t s ) ;

/*
 *  create a stringlist with cstring and take it over( own it )
 * cstring will point to NULL on function return.
 * cstring must be created with malloc.
 */
stringList_t StringListWithSize( char ** cstring,size_t s ) ;

/*
 * returns a copy of a string list
 */
stringList_t StringListCopy( stringList_t stl ) ;

/*
 * move entry at position x to position y and entry at position y to position x * 
 * first entry is at position 0.
 */
stringList_t StringListSwap( stringList_t stl, size_t x,size_t y ) ;

#ifdef __cplusplus
}
#endif

#endif