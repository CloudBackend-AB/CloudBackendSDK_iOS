/*
     Copyright © CloudBackend AB 2020 - 2022.
*/

#ifndef INCLUDE_CBE__Filter_h__
#define INCLUDE_CBE__Filter_h__
#import <Foundation/Foundation.h>

//#include "CBEIOS/Types.h"
#import <CBEIOS/Types.h>

//#include "CBEIOS/Container.h"

// #include <iosfwd>
// #include <memory>

// namespace CBI {
// class Filter;
// class ItemEventProtocol;
// using ItemDelegatePtr = shared_ptr<ItemEventProtocol>;
// } // namespace CBI

// namespace cbe {
//   namespace util {
// struct Context;
//   } // namespace util
//   namespace delegate {
// class QueryDelegate;
// using QueryDelegatePtr = shared_ptr<QueryDelegate>;
// CBI::ItemDelegatePtr createCbiQueryDelegate(QueryDelegatePtr,
//                                             cbe::util::Context&&;
// class QueryJoinDelegate;
// using QueryJoinDelegatePtr = shared_ptr<QueryJoinDelegate>;
// CBI::ItemDelegatePtr createCbiQueryDelegate(QueryJoinDelegatePtr,
//                                             cbe::util::Context&&;
//   } // namespace delegate

/**
 * @brief to select Item that meets specific criterias when doing a query.
 * 
 * Filtering on Metadata Key values can be done to query for Object
 * with setQuery() .
 */
//    typedef enum  {
//      Unapplicable =  1,
//      Unknown =       2,
//      Object =        4,
//      Container =     8,
//      Tag =           16,
//      Group =         32
//    } CBEItemType;

//  typedef enum {
//     Title = 1,
//     Relevance = 2,    //Note* group Searches does not use Relevance as order.
//     Published = 3,
//     Updated = 4,
//     Length = 5,
//     S1 = 6,
//     S2 = 7,
//     S3 = 8,
//     S4 = 9
//   }CBEFilterOrder;
  
@class CBEContainer;

  @interface CBEFilter : NSObject {
  }
//class Filter {
// public:
//   Filter(;
//   Filter(const Filter& rh;
//   Filter(Filter&&      rh;
//   Filter& operator=(const Filter& rh;
//   Filter& operator=(Filter&&      rh;
//   ~Filter(;

  /**
   * Returns the requested data type.
   * E.g., cbe::ItemType::Container, Object, Tag, ...
   */
  /**  */
 -(CBEItemType) getDataType;

  /**
   * Returns the query NSString* that was set on the filter. \n 
   * E.g.: \n name:Abc* \n age:100 \n price<200 \n size>40
   */
  -(NSString*) getQuery;

  /**
   * Returns the settings on how the data was sorted and displayed.
   */
  -(bool) getAscending;

  /**
   * if deleted objects in the bin are included
   */
  -(bool) getDeleted;

  /**
   * if containers should be sorted before objects
   */
  -(bool) getContainerFirst;

  /**
   * if the resultset comes from a joined query
   */
  -(bool) isJoinedResult;

  /**
   * Returns the offset of items to be skiped that was used 
   * for the filter in the query.
   */
  -(uint32_t) getOffset;

  /**
   * Returns the size of the resultset of the query.
   */
  -(uint32_t) getCount;

  /**
   * Returns if skipping the cache was used or not.
   */
  -(bool) getByPassCache;

  /**
   * Returns the order the query was sorted. 
   * Check enum \c FilterOrder to see
   * options for sorting.
   */
  -(CBEFilterOrder) getItemOrder;

  /**
   * Returns the parent container that was queried, if it is in the cache. 
   * This is after a query was done, not before.
   */
  //todo cbewrap put this back
  -(CBEContainer*) container;

  /**
   * Set which \c datatypes to query for.
   * 
   * @param itemType as defined in Types.h
   */
  -(void) setDataType:(CBEItemType) itemType;

  /**
   * Set the query NSString. \n 
   * E.g.: Name:* (would search for all objects with the metadata key of Name). \n 
   * \note If used with rootContainer id as the dataId to search in, 
   * the whole account will be searched.
   * 
   * @param query is a NSString of key tags or key:value pairs. \n 
   * E.g. Name:*|Country:Sweden|Country:Norway, this would search for objects 
   * with key Name but any value and where key Country is either Sweden or 
   * Norway. \n
   * E.g.: \n name:Abc* \n age:100 \n price<200 \n size>40
   */
  -(void) setQuery:(NSString*) query;

  /**
   * Sets the order, \p ascending , in which data should be displayed:
   * 
   * @param ascending true = sorted in increasing order \n 
   * false = sorted in decreasing order
   */
  -(void) setAscending:(bool) ascending;

  /**
   * Show deleted items
   * 
   * @param deleted true = include items in the bin \n 
   * default is false
   */
  -(void) setDeleted:(bool) deleted;

  /**
   * If \c Container should be displayed before \c Object
   * 
   * @param containerFirst true = sort containers at the top of the resultset. \n 
   * default is to not sort for this.
   */
  -(void) setContainerFirst:(bool) containerFirst;

  /**
   * Set the offset for paging, offset is the item offset where to start your
   * resultset. \n 
   * E.g.:
   * There is already a query of the first 99 items and to get the rest you 
   * put setOffset() to 100 to get the next set.
   * 
   * @param offset first item start number of the complete resultset to return
   */
  -(void) setOffset:(uint32_t) offset;

  /**
   * Set the number of items you want to get from a container. \n 
   * E.g.: a container has 50 items but you only want the 10 first in ascending
   * order then set ascending to true and setCount to 10.
   * 
   * @param count maximum number of items to return 
   */
  -(void)  setCount:(uint32_t) count;

  /**
   * Set the order of how data will be shown by the enum of FilterOrder
   * E.g.: Title first, Relevance, published e.t.c.
   * 
   * @param order see the enum \c FilterOrder in Types.h
   */
  -(void)  setItemOrder:(CBEFilterOrder) order;

  /**
   * Set to skip the local SDK cache and fetch an update from the cloud.
   * 
   * @param byPassCache true = skip the SDK cache and ask the cloud. \n 
   * default is to use the cache when available.
   */
  -(void)  setByPassCache:(bool) byPassCache;


  - (id) initWith:(void*) cbiPeerPtr;
/*
  friend ostream& operator<<(ostream& os, const Filter& filter;
private:
  struct Impl;
  unique_ptr<Impl> pImpl;
  friend class CloudBackend;
  friend class Container;
  friend class QueryChain;
  friend class QueryResult;
  friend CBI::ItemDelegatePtr delegate::createCbiQueryDelegate(
                                                         delegate::QueryDelegatePtr,
                                                         cbe::util::Context&&;
  friend CBI::ItemDelegatePtr delegate::createCbiQueryDelegate(
                                                         delegate::QueryJoinDelegatePtr,
                                                         cbe::util::Context&&;
  Filter(CBI::Filter&& cbiPeer;
  CBI::Filter& getCbiPeer;
}; // class Filter

} // namespace cbe

*/
@end
#endif // #ifndef CBE__Filter_h__
