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
				 * To add a value to specific key
				 * \return Pair of key and value
				 */
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

				/**
				 * To remove a key and the value
				 * \return true on success otherwise false
				 */
				bool PairRemove(TypeKey Key)
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
