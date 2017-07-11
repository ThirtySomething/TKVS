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

The handling of a std::map

## Implementation Details

* Convenience typedefs for datatypes in <code>YAIP++.h</code>
* Data containers are STL elements like [*vector*](http://en.cppreference.com/w/cpp/container/vector "Vector") or [*map*](http://en.cppreference.com/w/cpp/container/map "Map")
* Detection of section and key/value pair is done using [*regular expressions*](http://en.cppreference.com/w/cpp/regex "Regular Expression"), see also [*regular expression*](https://en.wikipedia.org/wiki/Regular_expression "Regular Expression")
* The major methods are based on [*std::string*](http://en.cppreference.com/w/cpp/string/basic_string "String")
* The templated methods using converters from and to [*std::string*](http://en.cppreference.com/w/cpp/string/basic_string "String")

## Extension

If any datatype is currently not supported, the extension is very simple. Just extend the class <code>YAIP::Convert</code> with conversion methods from/to your data type.

## Doxygen Documentation

A doxygen documentation can be generated, the config file is located in the doxygen subfolder.

## API Overview

### File related actions:

* Load INI file

		/**
		 * Load and parse INI file into internal structures
		 * \param Filename Full qualified filename of the INI file
		 * \return true on success otherwise false
		 */
		bool INIFileLoad(std::string Filename);

* Save INI file

		/**
		 * Save internal structures to INI file
		 * \param Filename Full qualified filename of the INI file
		 * \return true on success otherwise false
		 */
		bool INIFileSave(std::string Filename);

### Section related actions:

* Get a list of all sections

		/**
		 * Get all sections of the INI file
		 * \return Vector with a std::strings for each section
		 */
		tVectorString SectionListGet(void);

* Delete a section

		/**
		 * Remove section completely from internal data structure
		 * \param Section Specified section
		 */
		void SectionKill(const std::string &Section);

### Key related actions:

* Get a list of keys of a section

		/**
		 * Get all keys of a section of the INI file
		 * \param Section Specified section
		 * \return Vector with a std::strings for each key
		 */
		tVectorString SectionKeyListGet(const std::string &Section);

* Get a value of a section/key combination - *Note: This is a templated method and requires in any case a default value.*

		/**
		 * Templated method to retrieve a value of the specified section/key combination
		 * \param Section Specified section
		 * \param Key Specified key
		 * \param Default Specified default value in case key does not exist
		 * \return Returns either the default value or the value of the existing section/key combination
		 */
		template<typename VariableType>
		VariableType SectionKeyValueGet(const std::string &Section, const std::string &Key, const VariableType &Default);


* Set a value of a section/key combination - *Note: This is a templated method and may require a cast.*

		/**
		 * Templated method to set a value of the specified section/key combination
		 * \param Section Specified section
		 * \param Key Specified key
		 * \param Value Specified value to set
		 * \return true on success otherwise false
		 */
		template<typename VariableType>
		bool SectionKeyValueSet(const std::string &Section, const std::string &Key, const VariableType &Value);

* Delete a key

		/**
		 * Remove key completely from section of internal data structure
		 * \param Section Specified section
		 * \param Key Specified key
		 */
		void SectionKeyKill(const std::string &Section, const std::string &Key);

## ToDo's

* The implementation has to be checked against the inofficial specification at [Wikipedia](https://en.wikipedia.org/wiki/INI_file#Comments) and the tests have to satisfiy the specification.
* Comments are currently not supported - add this feature as desscribed in the specification.
