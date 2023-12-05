/*
     Copyright © CloudBackend AB 2022.
*/

#ifndef INCLUDE_CBE_PUBLISH_MANAGER_H_
#define INCLUDE_CBE_PUBLISH_MANAGER_H_
#import <Foundation/Foundation.h>
#include "CBEIOS/Types.h"
// #include <vector>

// #include "CBE/Types.h"


// namespace CBI {
// class PublishManager;
// } // namespace CBI
// namespace cbe {

// /** 
//  * @brief list of web shares.
//  */ 
@interface CBEPublishManager : NSObject
// class PublishManager {
// public:
//   /**
//    * @brief Lists web shares that are shared with other @ref cbe::UserId
//    *        "userids".
//    * 
//    * Listing is done independently of where in the actual
//    * @ref cbe::Container "container/subcontainer" tree the
//    * @ref cbe::Item "items" are located.
//    *
//    * @return The web shares in terms of @ref cbe::Item "items".
//    */
//   cbe::Items getPublished() const;
// cbe::Items = std::vector<cbe::Item>
-(NSArray*) getPublished;

//   PublishManager(cbe::DefaultCtor);
//   ~PublishManager();

//   /**
//    * @return \c false, if current instance is unbound/undefined. I.e., if it is
//    *         only default constructed.
//    */
//   explicit operator bool() const;
// private:
//   struct Impl;
//   std::shared_ptr<Impl> pImpl{};
- (id) initWith:(void*) cbiPeerPtr;

//   friend class CloudBackend;
//   PublishManager(CBI::PublishManager& cbiPeer);
//   CBI::PublishManager& getCbiPeer() const;
// }; // class PublishManager

// } // namespace cbe
@end
#endif  // INCLUDE_CBE_PUBLISH_MANAGER_H_
