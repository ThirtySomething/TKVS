//******************************************************************************
// Copyright 2017 ThirtySomething
//******************************************************************************
// This file is part of TKVS.
//
// TKVS is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// TKVS is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
// more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with TKVS. If not, see <http://www.gnu.org/licenses/>.
//******************************************************************************

#pragma once

#include "TKVS_defines.h"
#include "catch.hpp"

/**
 * Test for TKVS
 */
class TKVS_test
{
public:
	/**
	 * Default constructor
	 */
	explicit TKVS_test(void);

	/**
	 * Default destructor
	 */
	virtual ~TKVS_test(void);

	/**
	 * Test of clear method
	 */
	void clear_test(void);

	/**
	 * Test of empty method
	 */
	void empty_test(void);

	/**
	 * Test of size method
	 */
	void size_test(void);

	/**
	 * Test of KeyValueGet method
	 */
	void KeyValueGet_test(void);

	/**
	 * Test of KeyValueSet method
	 */
	void KeyValueSet_test(void);

	/**
	 * Test of KeyValueDelete method
	 */
	void KeyValueDelete_test(void);

	/**
	 * Test of GetListOfKeys method
	 */
	void GetListOfKeys_test(void);

protected:
	/**
	 * Data storage used in all tests
	 */
	TKVSIntInt_Type TKVSIntInt;
};
