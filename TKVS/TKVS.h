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

#include <map>
#include <utility>
#include <vector>

/**
 * TLD namespace
 */
namespace net
{
	/**
	 * Domain namespace
	 */
	namespace derpaul
	{
		/**
		 * Tools namespace
		 */
		namespace tools
		{
			/**
			 * Template class for a key/value storage
			 */
			template<typename TypeKey, typename TypeValue>
			class TKVS
			{
			public:
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

				/**
				 * Constructor
				 */
				TKVS(void)
					: m_Data()
				{
				};

				/**
				 * Destructor
				 * \attention The map will be cleared and all keys/values stored also.
				 * \attention In case pointers are stored, you have to take care about your objects.
				 * \attention May create some memory leaks.
				 */
				virtual ~TKVS(void)
				{
					clear();
				};

				/**
				 * Cleanup internal used map
				 * \attention In case pointers are stored, you have to take care about your objects.
				 * \attention May create some memory leaks.
				 */
				void clear(void)
				{
					m_Data.clear();
				};

				/**
				 * Analogue to the map::empty method
				 * \return true if empty, otherwise false
				 */
				bool empty(void) const
				{
					return m_Data.empty();
				};

				/**
				 * Analogue to the map::size method
				 * \return Number of elements in the key/value storage
				 */
				typename KeyValueStorage::size_type size(void) const
				{
					return m_Data.size();
				}

				/**
				 * Get value to corresponding key
				 * \param Key Read value from this key
				 * \param Value Variable to set value
				 * \return true on success, otherwise false
				 */
				bool KeyValueGet(TypeKey Key, TypeValue &Value)
				{
					bool Found = false;
					KeyValueStorage::iterator PositionKey = m_Data.find(Key);

					if (PositionKey != m_Data.end())
					{
						Value = PositionKey->second;
						Found = true;
					}
					return Found;
				}

				/**
				 * To add a value to specific key
				 * \param Key Key for saved value
				 * \param Value Value to save
				 * \return Pair of key and value
				 */
				typename KeyValuePair KeyValueSet(TypeKey Key, TypeValue Value)
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

				/**
				 * To remove a key and the value
				 * \param Key Key of pair to remove to
				 * \return true on success otherwise false
				 */
				bool KeyValueDelete(TypeKey Key)
				{
					bool Removed = false;
					KeyValueStorage::iterator PositionKey = m_Data.find(Key);

					if (PositionKey != m_Data.end())
					{
						m_Data.erase(PositionKey);
						Removed = true;
					}

					return Removed;
				}

				/**
				 * Get a vector with all keys
				 * \return A vector with all keys
				 */
				typename ListKeys GetListOfKeys(void)
				{
					ListKeys ListOfKeys;

					for (KeyValueStorage::iterator Loop = m_Data.begin(); Loop != m_Data.end(); ++Loop)
					{
						ListOfKeys.push_back(Loop->first);
					}

					return ListOfKeys;
				}

			protected:
				/**
				 * The storage itself as std::map
				 */
				typename KeyValueStorage m_Data;

			private:
				/**
				 * Disable copy constructor because of potential pointers as values
				 * \param Source Second key/value storage for copy
				 */
				TKVS(const TKVS &Source);
			};
		}
	}
}
