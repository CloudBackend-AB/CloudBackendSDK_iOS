/*
     Copyright © CloudBackend AB 2020 - 2022.
*/


#ifndef INCLUDE_CBE_QUERY_RESULT_H_
#define INCLUDE_CBE_QUERY_RESULT_H_

//#include "CBEIOS/Types.h"
#include "CBEIOS/Filter.h"


// namespace CBI {
// class QueryResult;
// using QueryResultPtr = std::shared_ptr<CBI::QueryResult>;
// class ItemEventProtocol;
// using ItemDelegatePtr = std::shared_ptr<ItemEventProtocol>;
// class PublishEventProtocol;
// using PublishDelegatePtr = std::shared_ptr<PublishEventProtocol>;
// class ShareEventProtocol;
// using ShareDelegatePtr = std::shared_ptr<ShareEventProtocol>;
// class SubscribeEventProtocol;
// using SubscribeDelegatePtr = std::shared_ptr<SubscribeEventProtocol>;
// } // namespace CBI

// namespace cbe {

// class Filter;
//   namespace util {
// struct Context;
//   } // namespace util
//   namespace delegate {
// class QueryDelegate;
// using QueryDelegatePtr = std::shared_ptr<QueryDelegate>;
// CBI::ItemDelegatePtr createCbiQueryDelegate(QueryDelegatePtr,
//                                             cbe::util::Context&&);
// class QueryJoinDelegate;
// using QueryJoinDelegatePtr = std::shared_ptr<QueryJoinDelegate>;
// CBI::ItemDelegatePtr createCbiQueryDelegate(QueryJoinDelegatePtr,
//                                             cbe::util::Context&&);
// class JoinDelegate;
// using JoinDelegatePtr = std::shared_ptr<JoinDelegate>;
// CBI::ItemDelegatePtr createCbiJoinDelegate(JoinDelegatePtr,
//                                            cbe::util::Context&&);
//   } // namespace delegate

/**
 * @brief resultset of data retrieved.
 * 
 */

//class QueryResult {

@interface CBEQueryResult : NSObject {
}
  /**
   * Returns a copy of the filter used for query.
   */
  -(CBEFilter*) filter ;

//  using ItemsSnapshot = vector<Item>;
  /**
   * Returns a copy of a vector containing the items for this QueryResult.
   * The QueryResult will be updated when new data comes in, but the returned
   * copy will not.
   * If iterating make sure to create a variable for a local copy.
   *
   * @return The items matching the query.
   */
  -(NSArray*) getItemsSnapshot ;

  /**
   * Number of \c items loaded in current QueryResult.
   */
  -(uint64_t) itemsLoaded ;

  /**
   * total number of items in the cloud matching the query result.
   * This may be more than loaded.
   */
  -(uint64_t) totalCount ;

  /**
   * Returns number of \c objects loaded in to the query result.
   */
  -(uint64_t) objectsLoaded ;

  /**
   * Returns number of \c containers loaded in to the query result.
   */
  -(uint64_t) containersLoaded ;

  /**
   * Checks if the Item with id is in the resultset.
   * 
   * @param itemId id number of the item asked for
   */
  -(bool) containsItem:(CBEItemId) itemId ;


  - (id) initWith:(void*) cbiPeerPtr;

  // friend std::ostream& operator<<(std::ostream&       os,
  //                                  QueryResult&  queryResult);

  // QueryResult(cbe::DefaultCtor);
  // ~QueryResult;

  /**
   * bool type conversion operator indicating that current QueryResult is valid.
   */
  // explicit operator bool ;
// private:
//   struct Impl;
//   std::shared_ptr<Impl> pImpl{};

//   friend class CloudBackend;
//   friend class Container;
//   friend class QueryChain;
//   friend class QueryChainSync;
//   friend class ShareManager;
//   friend class SubscribeManager;
//   friend CBI::ItemDelegatePtr delegate::createCbiQueryDelegate(
//                                                          delegate::QueryDelegatePtr,
//                                                          cbe::util::Context&&);
//   friend CBI::ItemDelegatePtr delegate::createCbiQueryDelegate(
//                                                          delegate::QueryJoinDelegatePtr,
//                                                          cbe::util::Context&&);
//   friend CBI::ItemDelegatePtr delegate::createCbiJoinDelegate(
//                                                          delegate::JoinDelegatePtr,
//                                                          cbe::util::Context&&);
//   QueryResult(CBI::QueryResultPtr cbiPeerPtr);
//   CBI::QueryResult& getCbiPeer ;
// }; // class QueryResult

// }
// namespace cbe
@end
#endif // INCLUDE_CBE_DIRECTORY_H_
