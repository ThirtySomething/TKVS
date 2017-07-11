#define CATCH_CONFIG_MAIN

#include "TKVS.h"
#include "catch.hpp"

TEST_CASE("Creation", "[Constructor]")
{
	net::derpaul::tools::TKVS<int, int> TKVSIntInt;
	REQUIRE(0 == TKVSIntInt.size());
	REQUIRE(true == TKVSIntInt.empty());
}

TEST_CASE("PairSet with new elements", "[PairSet - New]")
{
	net::derpaul::tools::TKVS<int, int> TKVSIntInt;
	int LoopMax = 10;

	for (int Loop = 0; Loop < LoopMax; Loop++)
	{
		net::derpaul::tools::TKVS<int, int>::KeyValuePair Result = TKVSIntInt.PairSet(Loop, Loop);
		REQUIRE(Loop == Result.first);
		REQUIRE(Loop == Result.second);
		int KeyValuePairCount = TKVSIntInt.size();
		REQUIRE(Loop == (KeyValuePairCount - 1));
	}
}

TEST_CASE("PairSet with existing elements", "[PairSet - Update]")
{
	net::derpaul::tools::TKVS<int, int> TKVSIntInt;
	int LoopMax = 10;

	for (int LoopKey = 0; LoopKey < LoopMax; LoopKey++)
	{
		for (int LoopValue = 0; LoopValue < LoopMax; LoopValue++)
		{
			net::derpaul::tools::TKVS<int, int>::KeyValuePair Result = TKVSIntInt.PairSet(LoopKey, LoopValue);
			REQUIRE(LoopKey == Result.first);
			REQUIRE(LoopValue == Result.second);
			int KeyValuePairCount = TKVSIntInt.size();
			REQUIRE(LoopKey == (KeyValuePairCount - 1));
		}
	}
}
