/*
 Copyright © CloudBackend AB 2020 - 2022.
 */

#ifndef INCLUDE_CBE_GROUP_MANAGER_H_
#define INCLUDE_CBE_GROUP_MANAGER_H_

#import <Foundation/Foundation.h>

#include "CBEIOS/Types.h"

//include "CBEIOS/GroupFilter.h"

//#include "CBE/delegate/Error.h"
#include "CBEIOS/delegate/ListGroupsDelegate.h"
#include "CBEIOS/delegate/SearchGroupsDelegate.h"

// #include "CBE/util/Context.h"
// #include "CBE/util/ErrorInfo.h"
// #include "CBE/util/Exception.h"

// namespace CBI {
// class GroupManager;
// } // namespace CBI
@class CBEGroupFilter;

@interface CBEGroupManager : NSObject {
}

// namespace cbe {

/**
 * @brief to manage the users own Group.
 * 
 */
// class GroupManager {
// public:  
  // using ListGroupsDelegatePtr = delegate::ListGroupsDelegatePtr;
  /**
   * List all current joined groups.
   */
  -(void) listGroups:(id<ListGroupsDelegatePtr>)delegate;
  // void listGroups(cbe::GroupDelegatePtr delegate);

  // using SearchGroupsDelegatePtr = delegate::SearchGroupsDelegatePtr;
  /**
   * Search for open public groups.
   * @param filter        is a group filter to set search criteria for open 
   *                      public groups. Look att class GroupFilter for more 
   *                      information.
   * @param delegate      is the callback protocol template for group actions.
   * @param parentGroupId is the id of the group to be searched within. 
   *                      If this is not set the tenent id will be used.
   */
  -(void) searchGroups:(CBEGroupFilter*)filter
                    delegate:(id<SearchGroupsDelegatePtr>) delegate
                    parentGroupId:(CBEGroupId)            parentGroupId;

  /**
   * Returns the tenant id of the Tenant user group that the user is in.
   */
  -(CBEGroupId) getTenantId;

  - (id) initWith:(void*)cbiPeerPtr;



//   GroupManager(cbe::DefaultCtor);
//   ~GroupManager();

//   explicit operator bool() const;
// private:
//   struct Impl;
//   std::shared_ptr<Impl> pImpl{};

//   friend class CloudBackend;
//   GroupManager(CBI::GroupManager& cbiPeer);
//   CBI::GroupManager& getCbiPeer() const;
// }; // class GroupManager

// } // namespace cbe
@end
#endif  // INCLUDE_CBE_GROUP_MANAGER_H_
