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

#include "catch.hpp"
#include "TKVS_defines.h"

TEST_CASE("TKVS - Template Key Value Storage", "[net][derpaul][tools][TKVS]")
{
	TKVSIntInt_Type *TKVSIntInt = new TKVSIntInt_Type();

	SECTION("test contstructor")
	{
		CHECK(nullptr != TKVSIntInt);
		REQUIRE(0 == TKVSIntInt->size());
		REQUIRE(true == TKVSIntInt->empty());
	}

	SECTION("test clear method")
	{
		TKVSIntInt->KeyValueSet(1, 0);
		REQUIRE(0 < TKVSIntInt->size());
		REQUIRE(false == TKVSIntInt->empty());
		TKVSIntInt->clear();
		REQUIRE(0 == TKVSIntInt->size());
		REQUIRE(true == TKVSIntInt->empty());
	}

	SECTION("test empty method")
	{
		REQUIRE(0 == TKVSIntInt->size());
		REQUIRE(true == TKVSIntInt->empty());
		TKVSIntInt->KeyValueSet(1, 0);
		REQUIRE(1 == TKVSIntInt->size());
		REQUIRE(false == TKVSIntInt->empty());
	}

	SECTION("test size method")
	{
		TKVSIntInt->clear();
		REQUIRE(0 == TKVSIntInt->size());
		REQUIRE(true == TKVSIntInt->empty());
		for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
		{
			TKVSIntInt->KeyValueSet(Loop, Loop);
			REQUIRE(Loop == TKVSIntInt->size());
			REQUIRE(false == TKVSIntInt->empty());
		}
		for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
		{
			TKVSIntInt->KeyValueSet(Loop, Loop);
			REQUIRE(MAX_LOOP == TKVSIntInt->size());
			REQUIRE(false == TKVSIntInt->empty());
		}
	}

	SECTION("test keyvalueget method")
	{
		TKVSIntInt->clear();
		REQUIRE(0 == TKVSIntInt->size());
		REQUIRE(true == TKVSIntInt->empty());
		for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
		{
			TKVSIntInt->KeyValueSet(Loop, Loop);
			REQUIRE(Loop == TKVSIntInt->size());
			REQUIRE(false == TKVSIntInt->empty());
		}
		for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
		{
			int Value = 0;
			bool Found = TKVSIntInt->KeyValueGet(Loop, Value);
			REQUIRE(true == Found);
			REQUIRE(Loop == Value);
		}
		for (int Loop = (MAX_LOOP + 1); Loop <= (2 * MAX_LOOP); Loop++)
		{
			int Value = 0;
			bool Found = TKVSIntInt->KeyValueGet(Loop, Value);
			REQUIRE(false == Found);
			REQUIRE(0 == Value);
		}
	}

	SECTION("test keyvaluedelete method")
	{
		TKVSIntInt->clear();
		REQUIRE(0 == TKVSIntInt->size());
		REQUIRE(true == TKVSIntInt->empty());
		for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
		{
			TKVSIntInt->KeyValueSet(Loop, Loop);
			REQUIRE(Loop == TKVSIntInt->size());
			REQUIRE(false == TKVSIntInt->empty());
		}
		for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
		{
			int Value = 0;
			bool Found = TKVSIntInt->KeyValueGet(Loop, Value);
			REQUIRE(true == Found);
			REQUIRE(Loop == Value);
			bool Delete = TKVSIntInt->KeyValueDelete(Loop);
			REQUIRE(true == Delete);
			Value = 0;
			Found = TKVSIntInt->KeyValueGet(Loop, Value);
			REQUIRE(false == Found);
			REQUIRE(0 == Value);
		}
		for (int Loop = (MAX_LOOP + 1); Loop <= (2 * MAX_LOOP); Loop++)
		{
			bool Delete = TKVSIntInt->KeyValueDelete(Loop);
			REQUIRE(false == Delete);
		}
	}

	SECTION("test getlistofkeys method")
	{
		TKVSIntInt->clear();
		REQUIRE(0 == TKVSIntInt->size());
		REQUIRE(true == TKVSIntInt->empty());
		for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
		{
			TKVSIntInt->KeyValueSet(Loop, Loop);
			REQUIRE(Loop == TKVSIntInt->size());
			REQUIRE(false == TKVSIntInt->empty());
		}
		std::vector<int> KeyList;
		for (int Loop = 1; Loop <= MAX_LOOP; Loop++)
		{
			KeyList.push_back(Loop);
		}
		std::vector<int> KeyListData = TKVSIntInt->GetListOfKeys();
		REQUIRE(KeyList.size() == KeyListData.size());
		REQUIRE(KeyList == KeyListData);
		while (0 < KeyList.size())
		{
			int LastElement = KeyList.back();
			KeyList.pop_back();
			bool Delete = TKVSIntInt->KeyValueDelete(LastElement);
			REQUIRE(true == Delete);
			KeyListData = TKVSIntInt->GetListOfKeys();
			REQUIRE(KeyList.size() == KeyListData.size());
			REQUIRE(KeyList == KeyListData);
		}
	}
}
