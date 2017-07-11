#pragma once

#include <map>
#include <utility>
#include <vector>

namespace net
{
	namespace derpaul
	{
		namespace tools
		{
			template<typename TypeKey, typename TypeValue>
			class TKVS
			{
			public:
				typedef std::map<TypeKey, TypeValue> KeyValueStorage;
				typedef std::pair <TypeKey, TypeValue> KeyValuePair;
				typedef std::vector<TypeKey> ListKeys;
				typedef std::vector<TypeValue> ListValues;

				TKVS(void)
				{
				};

				virtual ~TKVS(void)
				{
				};

				void clear(void)
				{
					m_Data.clear();
				};

				bool empty(void) const
				{
					return m_Data.empty();
				};

				typename KeyValueStorage::size_type size(void) const
				{
					return m_Data.size();
				}

				typename KeyValuePair PairSet(TypeKey Key, TypeValue Value)
				{
					KeyValueStorage::iterator PositionKey = m_Data.find(Key);

					if (PositionKey != m_Data.end())
					{
						m_Data.erase(PositionKey);
					}

					std::pair<KeyValueStorage::iterator, bool> InsertResult = m_Data.insert(std::make_pair(Key, Value));
					KeyValuePair ReturnValue = std::make_pair(InsertResult.first->first, InsertResult.first->second);

					return ReturnValue;
				}

			protected:
				typename KeyValueStorage m_Data;

			private:
				// Disable copy constructor because of pointers as values
				TKVS(const TKVS &Source);
			};
		}
	}
}
