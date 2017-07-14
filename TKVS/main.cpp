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

#define CATCH_CONFIG_MAIN

#include "TKVS_test.h"

/**
 * Test for creating a key/value storage
 */
TEST_CASE_METHOD(TKVS_test)
{
	TKVS_test SUT;
	SUT.clear_test();
	SUT.empty_test();
	SUT.size_test();
	SUT.KeyValueGet_test();
	SUT.KeyValueSet_test();
	SUT.KeyValueDelete_test();
	SUT.GetListOfKeys_test();
}
