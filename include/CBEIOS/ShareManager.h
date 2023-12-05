/*
 Copyright © CloudBackend AB 2020 - 2022.
 */

#ifndef INCLUDE_CBE_SHARE_MANAGER_H_
#define INCLUDE_CBE_SHARE_MANAGER_H_

#import <Foundation/Foundation.h>
#include "CBEIOS/Types.h"
#include "CBEIOS/delegate/ListSharesDelegate.h"

@protocol ListAvailableSharesDelegatePtr <ListSharesDelegatePtr>
@end
@protocol ListMySharesDelegatePtr <ListSharesDelegatePtr>
@end

@interface CBEShareManager : NSObject
// public:
  // using ListSharesDelegatePtr = delegate::ListSharesDelegatePtr;
  /**
   * @brief Lists the shares exposed by other users to current user. 
   * This will give specific share information.
   * @param delegate Pointer to a delegate::ListSharesDelegate
   *                 instance that is implemented by the user.
   */
  // void listAvailableShares(ListSharesDelegatePtr delegate);
  -(void) listAvailableShares:(id<ListAvailableSharesDelegatePtr>) delegate;
  /**
   * @brief Lists the shares exposed by current user. 
   * This will give specific share information.
   * @param delegate Pointer to a delegate::ListSharesDelegate
   *                 instance that is implemented by the user.
   */
  // void listMyShares(ListSharesDelegatePtr delegate);
  -(void) listMyShares:(id<ListMySharesDelegatePtr>) delegate;

//   ShareManager(cbe::DefaultCtor);
//   ~ShareManager();  
  - (id) initWith:(void*) cbiPeerPtr;
  - (void*) getCbiPeerVoid;

//   explicit operator bool() const;
// private:
//   struct Impl;
//   std::shared_ptr<Impl> pImpl{};

//   friend class CloudBackend;
//   ShareManager(CBI::ShareManager& cbiPeer);
//   CBI::ShareManager& getCbiPeer() const;
// }; // class ShareManager
@end

#endif  // INCLUDE_CBE_SHARE_MANAGER_H_
