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

* Data containers is a *[std::map](http://en.cppreference.com/w/cpp/container/map "std::map")*
