# TKVS - Template Key Value Storage

## General information

[![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](http://www.gnu.org/licenses/lgpl-3.0 "LGPL-3.0")

-  **TKVS** is distributed under the terms of the **GNU LESSER GENERAL PUBLIC LICENSE**, version 3.0. The text of the license is included in the file [<code>LICENSE.TXT</code>](https://github.com/ThirtySomething/YAIP/blob/master/LICENSE.TXT "LGPL-3.0") in the project root.
- As testing framework [*Catch*](https://github.com/philsquared/Catch "Catch") is used.

## Requirements
To use **TKVS** you need to have an modern [C++11](https://en.wikipedia.org/wiki/C%2B%2B11 "C++11") compiler. See the used parts at the section **Implementation Details**. You can use

* [Visual Studio 2017](https://www.visualstudio.com/ "Visual Studio") and above

## Supported Platforms
Current supported/tested platforms are

- [*Windows 7*](https://en.wikipedia.org/wiki/Windows_7 "Windows 7"), [*Visual Studio 2017*](https://www.visualstudio.com/ "Visual Studio"), 32-/64-bit

## Motivation

I'm missing in the *[STL](https://en.wikipedia.org/wiki/Standard_Template_Library "STL")* an easy to use key-value storage. So I decided to write my own based on a *[std::map](http://en.cppreference.com/w/cpp/container/map "std::map")*.

## Implementation Details

* Data container is a *[std::map](http://en.cppreference.com/w/cpp/container/map "std::map")*
* Convenience typedefs are done for internal use based on the template definitions
#
	/**
	 * Template class for a key/value storage
	 */
	template<typename TypeKey, typename TypeValue> class TKVS;
#
	/**
	 * Convenience typedef for a map used as key/value storage
	 */
	typedef std::map<TypeKey, TypeValue> KeyValueStorage;

	/**
	 * Convenience typedef for a key/value pair
	 */
	typedef std::pair <TypeKey, TypeValue> KeyValuePair;

	/**
	 * Convenience typedef for a list of keys
	 */
	typedef std::vector<TypeKey> ListKeys;

	/**
	 * Convenience typedef for a list of values
	 */
	typedef std::vector<TypeValue> ListValues;

## Simple to use API

### Constructor

	/**
	 * Constructor
	 */
	template<typename TypeKey, typename TypeValue>
	TKVS(void);

### Clear internal memory

	/**
	 * Cleanup internal used map
	 * \attention In case pointers are stored, you have to take care about your objects.
	 * \attention May create some memory leaks.
	 */
	void clear(void);

### Check for empty storage

	/**
	 * Analogue to the map::empty method
	 * \return true if empty, otherwise false
	 */
	bool empty(void) const;

### Check number of entries

	/**
	 * Analogue to the map::size method
	 * \return Number of elements in the key/value storage
	 */
	typename KeyValueStorage::size_type size(void) const;

### Read a value

	/**
	 * Get value to corresponding key
	 * \param Key Read value from this key
	 * \param Value Variable to set value
	 * \return true on success, otherwise false
	 */
	bool KeyValueGet(TypeKey Key, TypeValue &Value);

### Write a value

	/**
	 * To add a value to specific key
	 * \param Key Key for saved value
	 * \param Value Value to save
	 * \return Pair of key and value
	 */
	typename KeyValuePair KeyValueSet(TypeKey Key, TypeValue Value);

### Delete a value

	/**
	 * To remove a key and the value
	 * \param Key Key of pair to remove to
	 * \return true on success otherwise false
	 */
	bool KeyValueDelete(TypeKey Key);

### Get a list of keys

	/**
	 * Get a vector with all keys
	 * \return A vector with all keys
	 */
	typename ListKeys GetListOfKeys(void);

## ToDo

* Optional a callback method for purging values to avoid memory leaks.
