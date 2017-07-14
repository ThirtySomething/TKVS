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

#include "TKVS.h"
#include "catch.hpp"

/**
 * Maximum number for loops
 */
static const int MAX_LOOP = 10;

/**
 * Test for creating a key/value storage
 */
TEST_CASE("Creation", "[Constructor]")
{
	// Instantiation
	net::derpaul::tools::TKVS<int, int> TKVSIntInt;

	// Check on size
	REQUIRE(0 == TKVSIntInt.size());

	// Check on empty
	REQUIRE(true == TKVSIntInt.empty());
}

/**
 * Test for
 * - Adding data to the storage
 * - Count of elements inside the storage
 * - Storage is not empty
 * - Remove data from storage
 * - Count of elements inside the storage
 * - Storage is empty
 */
TEST_CASE("PairSet with new elements", "[PairSet - New]")
{
	// Instantiation
	net::derpaul::tools::TKVS<int, int> TKVSIntInt;
	std::vector<int> KeyList;
	std::vector<int> KeyListStorage;

	// Save MAX_LOOP key/values, both integers
	for (int Loop = 0; Loop < MAX_LOOP; Loop++)
	{
		// Add pair
		net::derpaul::tools::TKVS<int, int>::KeyValuePair Result = TKVSIntInt.PairSet(Loop, Loop);

		// Check all keys
		KeyList.push_back(Loop);
		KeyListStorage = TKVSIntInt.GetListOfKeys();
		REQUIRE(KeyList == KeyListStorage);

		// Retrieve size
		int KeyValuePairCount = static_cast<int>(TKVSIntInt.size());

		// Check key
		REQUIRE(Loop == Result.first);

		// Check value
		REQUIRE(Loop == Result.second);

		// Check size
		REQUIRE((1 + Loop) == KeyValuePairCount);

		// Check emptiness
		REQUIRE(false == TKVSIntInt.empty());
	}

	// Remove MAX_LOOP key/values, both integers
	for (int Loop = (MAX_LOOP - 1); Loop >= 0; Loop--)
	{
		// Remove pair
		bool Removed = TKVSIntInt.PairRemove(Loop);

		// Check all keys
		KeyList.erase(std::remove(KeyList.begin(), KeyList.end(), Loop), KeyList.end());
		KeyListStorage = TKVSIntInt.GetListOfKeys();
		REQUIRE(KeyList == KeyListStorage);

		// Retrieve size
		int KeyValuePairCount = static_cast<int>(TKVSIntInt.size());

		// Data removed
		REQUIRE(true == Removed);

		// Check size
		REQUIRE(Loop == KeyValuePairCount);
	}

	// Check emptiness
	REQUIRE(true == TKVSIntInt.empty());
}

/**
 * Test for
 * - Updating data to the storage
 * - Count of elements inside the storage
 * - Storage is not empty
 */
TEST_CASE("PairSet with existing elements", "[PairSet - Update]")
{
	// Instantiation
	net::derpaul::tools::TKVS<int, int> TKVSIntInt;

	// Outer loop
	for (int LoopKey = 0; LoopKey < MAX_LOOP; LoopKey++)
	{
		// Inner loop
		for (int LoopValue = 0; LoopValue < MAX_LOOP; LoopValue++)
		{
			// Add pair
			net::derpaul::tools::TKVS<int, int>::KeyValuePair Result = TKVSIntInt.PairSet(LoopKey, LoopValue);

			// Retrieve size
			int KeyValuePairCount = static_cast<int>(TKVSIntInt.size());

			// Check key
			REQUIRE(LoopKey == Result.first);

			// Check value
			REQUIRE(LoopValue == Result.second);

			// Check size
			REQUIRE((LoopKey + 1) == KeyValuePairCount);

			// Check emptiness
			REQUIRE(false == TKVSIntInt.empty());
		}
	}
}
