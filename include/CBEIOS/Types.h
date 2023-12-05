/*
  SDK type definitions.
  Copyright © CloudBackend AB 2020 - 2022.
*/
#ifndef INCLUDE_CBE_TYPES_H_
#define INCLUDE_CBE_TYPES_H_

// #include <stdint.h>
// #include <vector>
// #include <map>
// #include <memory>
// #include <string>
// #include <utility>
//wrapcbe todo fix vecors and maps and enums
/**
 * @brief Root namespace for the %CloudBackend SDK API.
 *
 */
//namespace cbe {

  // Type definitions for ids, enums, settings and failure codes

  /**
   * @brief Unique Id of a cbe::Container
   */
  typedef uint64_t CBEContainerId;
  /**
   * @brief time-stamp in the unix epoch format.
   *
   * A.k.a. POSIX time or time-stamp. \n
   * The equivalent in Linux shell can be found typedef e.g.,
   * \code {.sh}
   * date +%s --utc --date='now'
   * date +%s --utc --date='today 17:30:00'
   * \endcode
   * To convert a time-stamp to human readable format use e.g.,
   * \code {.sh}
   * date --utc --date=@1678902345
   * \endcode
   */
  typedef uint64_t CBEDate     ;
  /**
   * @brief The id of a drive.
   */
  typedef uint64_t CBEDriveId  ;
  /**
   * @brief Uniquely identifies the Group.
   */
  typedef uint64_t CBEGroupId  ;
  /**
   * @brief Id of a cbe::Container or cbe::Object
   */
  typedef uint64_t CBEItemId   ;
  /**
   * @brief Unique Id of a cbe::Object
   */
  typedef uint64_t CBEObjectId ;
  /**
   * @brief Uniquely identifies the CBE user.
   */
  typedef uint64_t CBEUserId       ;
  /**
   * @brief Represents the cbe::Group membership.
   */
  typedef uint64_t CBEMemberId ;
  /**
   * @brief Id of a cbe::Container or cbe::Object
   */
  typedef uint64_t CBESubscribeId  ;
  /**
   * @brief Id of a subscribed cbe::Container or cbe::Object.
   */
  typedef uint64_t CBEPublishId    ;
  /**
   * @brief Uniquely identifies a sharing of a cbe::Container or cbe::Object
   *
   */
  typedef uint64_t CBEShareId  ;
  /**
   * @brief Uniquely identifies a cbe::Stream.
   *
   */
  typedef uint64_t CBEStreamId ;

  typedef uint32_t cbeaccount_status_t       ;
  typedef uint32_t cbefailed_status_t        ;
  typedef uint32_t cbehttp_t                 ;
  typedef uint32_t cbesync_direction_t       ;
  typedef uint32_t cbesync_status_t          ;
  typedef uint32_t cbetransfer_t             ;
  typedef uint32_t cbepublish_access_t       ;
  typedef uint32_t cbepublish_visibility_t   ;

  typedef int cbepermission_status_t    ;
  typedef int cbeitem_t                 ;
  typedef int cbestream_t               ;
  typedef int cbevisibility             ;
  typedef int cbeapplication_t          ;
  typedef int cbeobject_t               ;

 //typedef uint32_t CBEFilterOrder;
  
   //typedef  cbeitem_t CBEItemType;


  /**
   * ApplicationType is not used in this version of groups but will be added
   * later.
   */
  // enum class ApplicationType : application_t {
  //   Open = 1,
  //   Invite = 2,
  //   Review = 3,
  //   Closed = 4
  // };

  /**
   * Type of invite.
   */
  typedef enum cbeObjectType : cbeobject_t {
    Other = 1,
    GroupInvites = 2,
    ShareInvite = 3
  }CBEObjectType;

  //! @cond Doxygen_Suppress
  /**
   * HttpType is used when you want to call rest requests directly.
   * \note This might in the future be taken out since we may parse
   * the URI string where the request type would be present instead.
  */
  // enum class HttpType : http_t {
  //   GET = 1,
  //   POST = 2,
  //   PUT = 3,
  //   DELETE = 4,
  //   HEAD = 5
  // };
  //! @endcond

  /**
   * Visibility is used for both groups and members, in this version
   * the member visibility will be Public for all members who join a group.
   *
   * Members will in the future also have the option of visibility friends.
  */
 typedef enum cbe_visibility:cbevisibility{
  //enum class Visibility : visibility {
    Public = 1,
    Private = 2
  }CBEVisibility; 

  /**
   * @brief Represents the access permission that can be set for any
   * cbe::Object or cbe::Container.
   * Forms the the possible different combinations of:
   * <ul>
   *   <li> 1: Read
   *   <li> 2: Write
   *   <li> 4: Delete
   *   <li> 8: ChangeACL
   * </ul>
   * combinations give access for users to use different API calls.
   *
   * E.g.:
   * 6 = ReadDelete gives the ability to call Move on a Container or an Object.
  */
//  typedef enum cbepermissions  : cbepermission_status_t{
     typedef NS_ENUM(cbepermission_status_t, CBEPermissions) {
    CBEPermissionsRead = 1,
    CBEPermissionsWrite = 2,
    CBEPermissionsReadWrite = 3,
    CBEPermissionsDelete = 4,
    CBEPermissionsReadDelete = 5,
    CBEPermissionsWriteDelete = 6,
    CBEPermissionsReadWriteDelete = 7,
    CBEPermissionsChangeACL = 8,
    CBEPermissionsReadChangeACL = 9,
    CBEPermissionsWriteChangeACL = 10,
    CBEPermissionsReadWriteChangeACL = 11,
    CBEPermissionsDeleteChangeACL = 12,
    CBEPermissionsReadDeleteChangeACL = 13,
    CBEPermissionsWriteDeleteChangeACL = 14,
    CBEPermissionsAllPermissions = 15,
    CBEPermissionsNoPermissions = 0
   };
//   } CBEPermissions;
  // enum class Permissions : permission_status_t
  // {
  //   Read = 1,
  //   Write = 2,
  //   ReadWrite = 3,
  //   Delete = 4,
  //   ReadDelete = 5,
  //   WriteDelete = 6,
  //   ReadWriteDelete = 7,
  //   ChangeACL = 8,
  //   ReadChangeACL = 9,
  //   WriteChangeACL = 10,
  //   ReadWriteChangeACL = 11,
  //   DeleteChangeACL = 12,
  //   ReadDeleteChangeACL = 13,
  //   WriteDeleteChangeACL = 14,
  //   AllPermissions = 15,
  //   NoPermissions = 0
  // };

  /**
   * Set the filter order in which the search or query will be sorted after.
  */
  typedef enum cbefilterorder:uint32_t{
    CBEFilterOrderTitle = 1,
    CBEFilterOrderRelevance = 2,    //Note* group Searches does not use Relevance as order.
    CBEFilterOrderPublished = 3,
    CBEFilterOrderUpdated = 4,
    CBEFilterOrderLength = 5,
    CBEFilterOrderS1 = 6,
    CBEFilterOrderS2 = 7,
    CBEFilterOrderS3 = 8,
    CBEFilterOrderS4 = 9
  }CBEFilterOrder;
  //typedef cbefilterorder CBEFilterOrder   ;

  /**
   * ItemType can be used to sort out cbe objects if the user would like to
   * create a container to put all different kinds of cbe objects in.
  */
 //enum class ItemType : cbe::item_t  {
   typedef enum cbeitemtype  : cbeitem_t{
     CBEItemTypeUnapplicable =  1,
     CBEItemTypeUnknown =       2,
     CBEItemTypeObject =        4,
     CBEItemTypeContainer =     8,
     CBEItemTypeTag =           16,
     CBEItemTypeGroup =         32
   } CBEItemType;
//typedef cbeitemtype CBEItemType;
  /**
   * Access permission for publish
   */
//  typedef NS_ENUM(cbepublish_access_t, CBEPublishAccess) {
  typedef enum  cbePublishAccess : cbepublish_access_t {
    CBEPublishAccessRead = 1,
    CBEPublishAccessUpdate = 2,
    CBEPublishAccessCreate = 3
//  };
  }CBEPublishAccess;

  /**
   * Visibility for publish
   */
  typedef enum  cbePublishVisibility : cbepublish_visibility_t {
    CBEPublishVisibilityPublic =  1,
    CBEPublishVisibilityFriends = 2,
    CBEPublishVisibilityPrivate = 3,
    CBEPublishVisibilityInvited = 4
  }CBEPublishVisibility;

  /**
   * Callback for login returns one of these three in callback.
   */
  // enum class AccountStatus : cbe::account_status_t {
  //   NotLoggedIn = 1,
  //   LoggedIn =    2,
  //   Failed =      3
  // };

  /**
   * @brief Default constructor marker.
   *
   * To default construct objects from most of the %CloudBackend classes, this
   * marker type is required.
   * \par Example use
   * \code {.cpp}
     ~~~
     // Conceptually, a default construction of an instance of cbe::Container
     cbe::Container myContainer{ cbe::DefaultCtor{} };
     // Ditto
     cbe::Object    myObject{ cbe::DefaultCtor{} };
     ~~~
   * \endcode
   *
   */
  // enum DefaultCtor {};

  /**
    * @brief Mimics the general error code encoding in the www.
    * \see [Wikipedia: List of HTTP status codes]
    *      (https://en.wikipedia.org/wiki/List_of_HTTP_status_codes)
    */
  typedef uint64_t CBEErrorCode;

  /**
   * @brief ACL map (<b>Access</b> <b>Control</b> <b>List</b>) of users and
   * groups.
   * Map of a specific user, in terms of cbe::UserId, and its cbe::Permission,
   * to reperesent permissions for specific users.
   */
  //typedef CBEAclMap = map<cbe::UserId, cbe::Permissions>;

  /**
   * @brief Map with key/value pairs, a.k.a. metadata.<br>
   * Can be applied on @ref cbe::Object but not on @ref cbe::Container.<br>
   * <ul>
   *   <li> <b>key</b> uniquely identifies the value
   *   <li> <b>value</b> and <b>index flag</b>
   *   <ul>
   *     <li> a string value
   *     <li> a boolean flag indicating whether this key/value entry is index
   *          (\c true) or not indexed (\c false).
   *   </ul>
   * </ul>
   */
  // @interface CBEMetaData : NSObject
  // @property (strong) NSString *value;
  // @property  bool index;
  // @end
  // struct CBEKeyValuePair{
  //   NSString* value;
  //   bool index;
  // };
//  typedef CBEKeyValues = NSDictionary<string, pair<string, bool>>;

  // class Account;
  // class CloudBackend;
  // class Connection;
  // class Container;
  // class Document;
  // class Folder;
  // class Group;
  // class Item;
  // class Object;
  // class Stream;
  // class Tag;
  // class Member;
  // class Transfer;
  // class GroupInvite;
  // class QueryResult;
  // class GroupQueryResult;
  // class QueryChain;
  // class Database;
  // class Publish;
  // class Subscribe;

  /**
   * @brief @ref cbe::Database "Databases" available for the
   * @ref cbe::Account "account".
   */
  //typedef CBEDataBases = map<string, cbe::Database>;


  /**
   * @brief Collection of @ref cbe::Item "items".
   */
  //typedef CBEItems = vector<cbe::Item>;

  struct ShareData;
  /**
   * @brief Map of cbe::ShareData for a specific cbe::ShareId.
   */
  //typedef CBEShareIds = map<cbe::ShareId, vector<cbe::ShareData>>;

  /**
   * @brief Map of a pair of @ref cbe::Member "members", associated with ban
   *        information, where:
   * <ul>
   *   <li> <b>Key</b> is formed by a [<b><c>pair</c></b>]
   *        (https://en.cppreference.com/w/cpp/utility/pair) of
   *        @ref cbe::MemberId "members",
   *        where:
   *     <ul>
   *       <li> <code>first</code> represents the banned member.
   *       <li> <code>second</code> represents the banning member with
   *            adminstration priviliges.
   *     </ul>
   *   <li> <b>Value</b> is formed by another pair:
   *     <ul>
   *       <li> @ref cbe::Date "date" of the ban
   *       <li> a free text reason message.
   */
  // typedef CBEMemberBanInfo  map<pair<cbe::MemberId, cbe::MemberId>,
  //                                pair<cbe::Date, string>>;

  /**
   * @brief collection of delegates for the main classes
   */
//  namespace delegate {}

  /**
   * @brief general utilities
   */
//  namespace util {}

//}// namespace cbe




#endif // INCLUDE_CBE_TYPES_H_
 
