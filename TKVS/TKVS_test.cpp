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

#include "TKVS_test.h"

// ******************************************************************
// ******************************************************************
TKVS_test::TKVS_test(void)
{
	clear_test();
}

// ******************************************************************
// ******************************************************************
TKVS_test::~TKVS_test(void)
{
}

// ******************************************************************
// ******************************************************************
void TKVS_test::clear_test(void)
{
	// Call clear method on SUT
	TKVSIntInt.clear();

	// Check size
	REQUIRE(0 == TKVSIntInt.size());

	// Check empty
	REQUIRE(true == TKVSIntInt.empty());
};

// ******************************************************************
// ******************************************************************
void TKVS_test::empty_test(void)
{
	// Ensure defined startup
	clear_test();

	// Check size
	REQUIRE(0 == TKVSIntInt.size());

	// Check empty
	REQUIRE(true == TKVSIntInt.empty());

	// Populate key value storage
	TKVSIntInt.KeyValueSet(1, 0);

	// Check size
	REQUIRE(1 == TKVSIntInt.size());

	// Check empty
	REQUIRE(false == TKVSIntInt.empty());
}

// ******************************************************************
// ******************************************************************
void TKVS_test::size_test(void)
{
	// Ensure defined startup
	clear_test();

	// Write to empty storage
	for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
	{
		// Populate key value storage
		TKVSIntInt.KeyValueSet(Loop, Loop);

		// Check size
		REQUIRE(Loop == TKVSIntInt.size());
	}

	// Write to already filled storage
	for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
	{
		// Populate key value storage
		TKVSIntInt.KeyValueSet(Loop, Loop);

		// Check size
		REQUIRE(MAX_LOOP == TKVSIntInt.size());
	}
}

// ******************************************************************
// ******************************************************************
void TKVS_test::KeyValueGet_test(void)
{
	// Ensure defined startup
	size_test();

	// Search existing entries
	for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
	{
		int Value = 0;
		bool Found = TKVSIntInt.KeyValueGet(Loop, Value);

		// Check found
		REQUIRE(true == Found);

		// Check value
		REQUIRE(Loop == Value);
	}

	// Search non existing entries
	for (int Loop = (MAX_LOOP + 1); Loop <= (2 * MAX_LOOP); Loop++)
	{
		int Value = 0;
		bool Found = TKVSIntInt.KeyValueGet(Loop, Value);

		// Check found
		REQUIRE(false == Found);

		// Check value
		REQUIRE(0 == Value);
	}
}

// ******************************************************************
// ******************************************************************
void TKVS_test::KeyValueSet_test(void)
{
	// KeyValueSet already tested in size
	size_test();
}

// ******************************************************************
// ******************************************************************
void TKVS_test::KeyValueDelete_test(void)
{
	// Ensure defined startup
	size_test();

	// Delete existing entries
	for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
	{
		int Value = 0;
		bool Found = TKVSIntInt.KeyValueGet(Loop, Value);

		// Check found
		REQUIRE(true == Found);

		// Check value
		REQUIRE(Loop == Value);

		bool Delete = TKVSIntInt.KeyValueDelete(Loop);

		// Check deletion
		REQUIRE(true == Delete);

		Value = 0;
		Found = TKVSIntInt.KeyValueGet(Loop, Value);

		// Check found
		REQUIRE(false == Found);

		// Check value
		REQUIRE(0 == Value);
	}

	// Delete non existing entries
	for (int Loop = (MAX_LOOP + 1); Loop <= (2 * MAX_LOOP); Loop++)
	{
		bool Delete = TKVSIntInt.KeyValueDelete(Loop);

		// Check deletion
		REQUIRE(false == Delete);
	}
}

// ******************************************************************
// ******************************************************************
void TKVS_test::GetListOfKeys_test(void)
{
	// Ensure defined startup
	size_test();

	std::vector<int> KeyList;

	// Fill list of keys
	for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
	{
		KeyList.push_back(Loop);
	}

	std::vector<int> KeyListData = TKVSIntInt.GetListOfKeys();

	// Compare list of keys
	REQUIRE(KeyList.size() == KeyListData.size());
	REQUIRE(KeyList == KeyListData);

	// Check changing sizes
	while (0 < KeyList.size())
	{
		// Remove element
		int LastElement = KeyList.back();
		KeyList.pop_back();
		bool Delete = TKVSIntInt.KeyValueDelete(LastElement);

		// Check deletion
		REQUIRE(true == Delete);

		// Compare list of keys
		KeyListData = TKVSIntInt.GetListOfKeys();
		REQUIRE(KeyList.size() == KeyListData.size());
		REQUIRE(KeyList == KeyListData);
	}
}
