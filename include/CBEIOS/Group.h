/*
 Copyright © CloudBackend AB 2020 - 2022.
 */
#ifndef INCLUDE_CBE_GROUP_H_
#define INCLUDE_CBE_GROUP_H_
#import <Foundation/Foundation.h>

//#include <string>
//#include "CBE/util/Context.h"
//#include "CBEIOS/Member.h"
#include "CBEIOS/Types.h"
#import "CBEIOS/Container.h"

//#include "CBE/delegate/Error.h"
 #include "CBEIOS/delegate/CreateGroupDelegate.h"
 #include "CBEIOS/delegate/LeaveDelegate.h"
 #include "CBEIOS/delegate/ListMembersDelegate.h"
 #include "CBEIOS/delegate/group/JoinDelegate.h"
 #include "CBEIOS/delegate/group/RenameDelegate.h"
 #include "CBEIOS/delegate/group/RemoveDelegate.h"

// #include "CBE/util/ErrorInfo.h"
// #include "CBE/util/Exception.h"

// namespace CBI {
// class Group;
// using GroupPtr = std::shared_ptr<CBI::Group>;
// class GroupEventProtocol;
// using GroupDelegatePtr = std::shared_ptr<GroupEventProtocol>;
// } // namespace CBI

// namespace cbe {

/**
 * @brief list of memberships to Group
 * 
 */
// class Group {
// public:
@protocol  ListBannedMembersDelegatePtr<ListMembersDelegatePtr>
@end

@interface CBEGroup : NSObject {
}
  /**
   * Returns the name of the group.
   */
   -(NSString*) name;

//   /**
//    * Returns the id number of the group.
//    */
-(CBEGroupId) id;

//   /**
//    * Group's Parent id number.
//    */
-(CBEGroupId) parentId;

//   /**
//    * Every group has a drive/container where resources can be shared with the 
//    * members of the group. Works like a shared container.
//    */
-(CBEContainer*) groupContainer;

//   /**
//    * Visibility of the Group, Public is searchable and Private is not. 
//    * In this early version you can create Private groups but the ability to 
//    * invite has been blocked. (work in progress)
//    * \see Types.h for cbe::PublishVisibility enum
//    */
-(CBEVisibility) getVisibility;

//   /**
//    * Searched groups are obtained through the GroupQuery response. This list of 
//    * groups have non-joined and joined groups. Already joined groups can be 
//    * found on the <code>groupManager.groups()</code> and they are also cached.
//    * The joined bool is used to easily sort out groups in the GroupQuery.
//    */
-(bool) joined;

//   //using Requests = std::vector<cbe::Request>;
//   /**
//    * Requests to join the group. To retrive the list call
//    *  listJoinRequests(cbe::GroupDelegatePtr delegate) on the group object.
//    */
// //  Requests requests() const;

//   using CreateGroupDelegatePtr = delegate::CreateGroupDelegatePtr;
//   /**
//    * @brief Create a new Group.
//    * 
//    * \note Can only be used by Tenant admin/owners to create new groups.
//    * @param name of the group
//    * @param memberAlias another popular name
//    * @param delegate Pointer to a delegate::CreateGroupDelegate instance 
//    *                 that is implemented by the user.   
//    * @param visibility default: public
//    * @return cbe::Group
//    * \see Types.h for cbe::visibility enum 
//    * cbe::Visibility::PublicGroup or cbe::Visibility::Private
//    */
-(CBEGroup*) createGroup:(NSString*)name
                          memberAlias:(NSString*) memberAlias
                         delegate:(id<CreateGroupDelegatePtr>) delegate
                         visibility:(CBEVisibility)visibility ;

// //  using JoinDelegatePtr = delegate::group::JoinDelegatePtr;
//   /**
//    * @brief Asking to join a group.
//    * 
//    * In this first version All members will be Public, 
//    * meaning visable for other member inside the group. All groups will also be
//    * open so all join requests should be accepted directly.
//    * 
//    * \note This is completetly different from the query chain join.

//    * @param alias    name
//    * @param delegate Pointer to a delegate::group::JoinDelegate instance 
//    *                 that is implemented by the user.   
//    * @param memberVisibility default: public
//    * @param applicationComment message to the owner regarding 
//    * the application to join
//    */
  -(void) join:(NSString*)alias
            delegate:(id<JoinGroupDelegatePtr>)delegate
            memberVisibility:(CBEVisibility)memberVisibility
            applicationComment:(NSString*)applicationComment;

// //  using LeaveDelegatePtr = delegate::LeaveDelegatePtr;  
//   /**
//    * @brief Leave group.
//    * 
//    * @param delegate Pointer to a delegate::LeaveDelegate instance 
//    *                 that is implemented by the user.   
//    */
  -(void) leave:(id<LeaveDelegatePtr>) delegate;

// //  using RemoveDelegatePtr = delegate::group::RemoveDelegatePtr;
//   /**
//    * @brief Remove group.
//    * 
//    * \note This is exlusive for Tenant group owners.
//    * 
//    * @param delegate Pointer to a delegate::group::RemoveDelegate instance 
//    *                 that is implemented by the user.   
//    */
   -(void) remove:(id<RemoveGroupDelegatePtr>) delegate;

// //  using RenameDelegatePtr = delegate::group::RenameDelegatePtr;
//   /**
//    * @brief Rename the Group; group id does not change.
//    * 
//    * @param newName  the new name for the group
//    * @param delegate Pointer to a delegate::group::RenameDelegate instance 
//    *                 that is implemented by the user.   
//    */
   -(void) rename:(NSString*) newName delegate:(id<RenameGroupDelegatePtr>) delegate;

// //  using ListMembersDelegatePtr = delegate::ListMembersDelegatePtr;
//   /**
//    * @brief List all members in the group.
//    * 
//    * The member list is then retrieved via the delegate callback function
//    * cbe::delegate::ListMembersDelegate::onListMembersSuccess()
//    * 
//    * @param delegate Pointer to a delegate::ListMembersDelegate instance
//    *                 that is implemented by the user.
//    */
   -(void) listMembers:(id<ListMembersDelegatePtr>) delegate;
  
// //  using ListBannedMembersDelegatePtr = delegate::ListMembersDelegatePtr;
  
//   /**
//    * @brief Lists all banned former members, or users.
//    * 
//    * @param delegate Pointer to a delegate::ListMembersDelegate instance 
//    *                 that is implemented by the user.
//    */
   - (void) listBannedMembers:(id<ListBannedMembersDelegatePtr>) delegate;

   - (id) initWith:(void*) cbiPeerPtr;

//   Group(cbe::DefaultCtor);
//   ~Group();

//   explicit operator bool() const;

// private:
//   struct Impl;
//   std::shared_ptr<Impl> pImpl{};
//   friend class GroupManager;
//   friend class GroupQueryResult;
//   Group(CBI::GroupPtr cbiPeerPtr);
//   CBI::Group& getCbiPeer() const;
// }; // class Group

// } // namespace cbe
@end
#endif  // INCLUDE_CBE_GROUP_H_
