#import <Foundation/Foundation.h>
#import "USAdditions.h"
#import <libxml/tree.h>
#import "USGlobals.h"
@class DuWebServiceSvc_acknowledgeExecution;
@class DuWebServiceSvc_acknowledgeExecutionResponse;
@class DuWebServiceSvc_addEvent;
@class DuWebServiceSvc_addEventResponse;
@class DuWebServiceSvc_addLaunch;
@class DuWebServiceSvc_addLaunchFromTask;
@class DuWebServiceSvc_addLaunchFromTask2;
@class DuWebServiceSvc_addLaunchFromTask2Response;
@class DuWebServiceSvc_addLaunchFromTaskResponse;
@class DuWebServiceSvc_addLaunchResponse;
@class DuWebServiceSvc_bypassLaunchConditionCheck;
@class DuWebServiceSvc_bypassLaunchConditionCheckResponse;
@class DuWebServiceSvc_contextHolder;
@class DuWebServiceSvc_createOutageWindow;
@class DuWebServiceSvc_createOutageWindowResponse;
@class DuWebServiceSvc_deleteEvent;
@class DuWebServiceSvc_deleteEventResponse;
@class DuWebServiceSvc_deleteLaunch;
@class DuWebServiceSvc_deleteLaunchResponse;
@class DuWebServiceSvc_deleteOutageWindow;
@class DuWebServiceSvc_deleteOutageWindowResponse;
@class DuWebServiceSvc_disableLaunch;
@class DuWebServiceSvc_disableLaunchResponse;
@class DuWebServiceSvc_enableLaunch;
@class DuWebServiceSvc_enableLaunchResponse;
@class DuWebServiceSvc_engine;
@class DuWebServiceSvc_event;
@class DuWebServiceSvc_eventFilter;
@class DuWebServiceSvc_eventItem;
@class DuWebServiceSvc_execution;
@class DuWebServiceSvc_executionFilter;
@class DuWebServiceSvc_executionItem;
@class DuWebServiceSvc_executionLog;
@class DuWebServiceSvc_forceCompleteLaunch;
@class DuWebServiceSvc_forceCompleteLaunchResponse;
@class DuWebServiceSvc_getDUEnvironmentList;
@class DuWebServiceSvc_getDUEnvironmentListResponse;
@class DuWebServiceSvc_getEvent;
@class DuWebServiceSvc_getEventResponse;
@class DuWebServiceSvc_getExecution;
@class DuWebServiceSvc_getExecutionLog;
@class DuWebServiceSvc_getExecutionLogAsAttachment;
@class DuWebServiceSvc_getExecutionLogAsAttachmentResponse;
@class DuWebServiceSvc_getExecutionLogResponse;
@class DuWebServiceSvc_getExecutionResponse;
@class DuWebServiceSvc_getHistoryTrace;
@class DuWebServiceSvc_getHistoryTraceResponse;
@class DuWebServiceSvc_getLaunch;
@class DuWebServiceSvc_getLaunchFromTask;
@class DuWebServiceSvc_getLaunchFromTaskResponse;
@class DuWebServiceSvc_getLaunchResponse;
@class DuWebServiceSvc_getListEvent;
@class DuWebServiceSvc_getListEventResponse;
@class DuWebServiceSvc_getListExecution;
@class DuWebServiceSvc_getListExecutionResponse;
@class DuWebServiceSvc_getListLaunch;
@class DuWebServiceSvc_getListLaunchResponse;
@class DuWebServiceSvc_getListMU;
@class DuWebServiceSvc_getListMUResponse;
@class DuWebServiceSvc_getListNode;
@class DuWebServiceSvc_getListNodeResponse;
@class DuWebServiceSvc_getListOutage;
@class DuWebServiceSvc_getListOutageResponse;
@class DuWebServiceSvc_getListSession;
@class DuWebServiceSvc_getListSessionResponse;
@class DuWebServiceSvc_getListTask;
@class DuWebServiceSvc_getListTaskResponse;
@class DuWebServiceSvc_getListUproc;
@class DuWebServiceSvc_getListUprocResponse;
@class DuWebServiceSvc_getPreviousLaunches;
@class DuWebServiceSvc_getPreviousLaunchesResponse;
@class DuWebServiceSvc_getRunBookExternalFile;
@class DuWebServiceSvc_getRunBookExternalFileResponse;
@class DuWebServiceSvc_getRunBooks;
@class DuWebServiceSvc_getRunBooksResponse;
@class DuWebServiceSvc_getRunNotes;
@class DuWebServiceSvc_getRunNotesResponse;
@class DuWebServiceSvc_getScriptResourceLog;
@class DuWebServiceSvc_getScriptResourceLogResponse;
@class DuWebServiceSvc_historyTrace;
@class DuWebServiceSvc_holdLaunch;
@class DuWebServiceSvc_holdLaunchResponse;
@class DuWebServiceSvc_launch;
@class DuWebServiceSvc_launchFilter;
@class DuWebServiceSvc_launchId;
@class DuWebServiceSvc_launchItem;
@class DuWebServiceSvc_login;
@class DuWebServiceSvc_loginResponse;
@class DuWebServiceSvc_logout;
@class DuWebServiceSvc_logoutResponse;
@class DuWebServiceSvc_muFilter;
@class DuWebServiceSvc_muItem;
@class DuWebServiceSvc_nodeFilter;
@class DuWebServiceSvc_nodeItem;
@class DuWebServiceSvc_outageFilter;
@class DuWebServiceSvc_outageWindow;
@class DuWebServiceSvc_previousLaunch;
@class DuWebServiceSvc_purgeExecution;
@class DuWebServiceSvc_purgeExecutionResponse;
@class DuWebServiceSvc_queue;
@class DuWebServiceSvc_releaseLaunch;
@class DuWebServiceSvc_releaseLaunchResponse;
@class DuWebServiceSvc_rerunExecution;
@class DuWebServiceSvc_rerunExecutionResponse;
@class DuWebServiceSvc_resetQueue;
@class DuWebServiceSvc_resetQueueResponse;
@class DuWebServiceSvc_resourceLog;
@class DuWebServiceSvc_restartEngine;
@class DuWebServiceSvc_restartEngineResponse;
@class DuWebServiceSvc_runBook;
@class DuWebServiceSvc_runBookFilter;
@class DuWebServiceSvc_runNote;
@class DuWebServiceSvc_runNoteFilter;
@class DuWebServiceSvc_sessionFilter;
@class DuWebServiceSvc_sessionItem;
@class DuWebServiceSvc_skipExecution;
@class DuWebServiceSvc_skipExecutionResponse;
@class DuWebServiceSvc_startEngine;
@class DuWebServiceSvc_startEngineResponse;
@class DuWebServiceSvc_startQueue;
@class DuWebServiceSvc_startQueueResponse;
@class DuWebServiceSvc_stopEngine;
@class DuWebServiceSvc_stopEngineResponse;
@class DuWebServiceSvc_stopExecution;
@class DuWebServiceSvc_stopExecutionResponse;
@class DuWebServiceSvc_stopQueue;
@class DuWebServiceSvc_stopQueueResponse;
@class DuWebServiceSvc_taskFilter;
@class DuWebServiceSvc_taskItem;
@class DuWebServiceSvc_unacknowledgeExecution;
@class DuWebServiceSvc_unacknowledgeExecutionResponse;
@class DuWebServiceSvc_updateEvent;
@class DuWebServiceSvc_updateEventResponse;
@class DuWebServiceSvc_updateLaunch;
@class DuWebServiceSvc_updateLaunchResponse;
@class DuWebServiceSvc_uprocFilter;
@class DuWebServiceSvc_uprocItem;
@class DuWebServiceSvc_uvmsContext;
@class DuWebServiceSvc_uvmsNodeFilter;
@class DuWebServiceSvc_variable;
@class DuWebServiceSvc_context;
@class DuWebServiceSvc_envir;
@class DuWebServiceSvc_uprocId;
@class DuWebServiceSvc_eventId;
@class DuWebServiceSvc_sessionId;
@class DuWebServiceSvc_variables;
@class DuWebServiceSvc_executionId;
@class DuWebServiceSvc_taskId;
@class DuWebServiceSvc_muId;
@class DuWebServiceSvc_nodeId;
@class DuWebServiceSvc_DuwsException;
@class DuWebServiceSvc_SessionTimedOutException;
typedef enum {
	DuWebServiceSvc_envirStatus_none = 0,
	DuWebServiceSvc_envirStatus_CONNECTING,
	DuWebServiceSvc_envirStatus_CONNECTED,
	DuWebServiceSvc_envirStatus_FAILED,
	DuWebServiceSvc_envirStatus_BROKEN,
	DuWebServiceSvc_envirStatus_STOPPED,
	DuWebServiceSvc_envirStatus_UNREACHABLE,
	DuWebServiceSvc_envirStatus_NODE_UNREACHABLE,
	DuWebServiceSvc_envirStatus_IO_UNREACHABLE,
	DuWebServiceSvc_envirStatus_CONNECTED_WARNING,
	DuWebServiceSvc_envirStatus_UNKNOWN,
	DuWebServiceSvc_envirStatus_NO_UPWARDS_MESSAGE,
	DuWebServiceSvc_envirStatus_BEING_COMPUTED,
} DuWebServiceSvc_envirStatus;
DuWebServiceSvc_envirStatus DuWebServiceSvc_envirStatus_enumFromString(NSString *string);
NSString * DuWebServiceSvc_envirStatus_stringFromEnum(DuWebServiceSvc_envirStatus enumValue);
@interface DuWebServiceSvc_envir : NSObject {
	
/* elements */
	NSString * company;
	NSString * node_;
	NSString * area;
	DuWebServiceSvc_envirStatus status;
	NSString * version;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_envir *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * company;
@property (retain) NSString * node_;
@property (retain) NSString * area;
@property (assign) DuWebServiceSvc_envirStatus status;
@property (retain) NSString * version;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_context : NSObject {
	
/* elements */
	DuWebServiceSvc_envir * envir;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_context *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_envir * envir;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_contextHolder : NSObject {
	
/* elements */
	NSString * token;
	DuWebServiceSvc_context * context;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_contextHolder *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * token;
@property (retain) DuWebServiceSvc_context * context;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_launchId : NSObject {
	
/* elements */
	NSString * task;
	NSString * session;
	NSString * sessionVersion;
	NSString * uproc;
	NSString * uprocVersion;
	NSString * mu;
	NSString * numLanc;
	NSString * numSess;
	NSString * numProc;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_launchId *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * task;
@property (retain) NSString * session;
@property (retain) NSString * sessionVersion;
@property (retain) NSString * uproc;
@property (retain) NSString * uprocVersion;
@property (retain) NSString * mu;
@property (retain) NSString * numLanc;
@property (retain) NSString * numSess;
@property (retain) NSString * numProc;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_acknowledgeExecution : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_acknowledgeExecution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_acknowledgeExecutionResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_acknowledgeExecutionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_eventId : NSObject {
	
/* elements */
	NSString * uproc;
	NSString * session;
	NSString * mu;
	NSString * processingDate;
	NSString * numProc;
	NSString * numSess;
	NSString * user;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_eventId *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * uproc;
@property (retain) NSString * session;
@property (retain) NSString * mu;
@property (retain) NSString * processingDate;
@property (retain) NSString * numProc;
@property (retain) NSString * numSess;
@property (retain) NSString * user;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_event : NSObject {
	
/* elements */
	DuWebServiceSvc_eventId * ident;
	NSString * status;
	NSString * step;
	NSString * creationDate;
	NSString * creationHour;
	NSString * updateDate;
	NSString * updateHour;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_event *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_eventId * ident;
@property (retain) NSString * status;
@property (retain) NSString * step;
@property (retain) NSString * creationDate;
@property (retain) NSString * creationHour;
@property (retain) NSString * updateDate;
@property (retain) NSString * updateHour;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_addEvent : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_event * event;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_addEvent *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_event * event;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_addEventResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_addEventResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_variable : NSObject {
	
/* elements */
	NSString * name;
	NSString * type;
	NSString * value;
	NSString * origin;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_variable *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * name;
@property (retain) NSString * type;
@property (retain) NSString * value;
@property (retain) NSString * origin;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_variables : NSObject {
	
/* elements */
	NSMutableArray *variables;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_variables *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addVariables:(DuWebServiceSvc_variable *)toAdd;
@property (readonly) NSMutableArray * variables;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_launch : NSObject {
	
/* elements */
	DuWebServiceSvc_launchId * ident;
	DuWebServiceSvc_variables * variables;
	USBoolean * autoRestart;
	USBoolean * centralControl;
	USBoolean * forcedExecution;
	USBoolean * bypassCondCheck;
	NSString * exclusionFrom;
	NSString * exclusionTo;
	NSString * status;
	NSString * beginDate;
	NSString * beginHour;
	NSString * endDate;
	NSString * endHour;
	NSString * processingDate;
	NSString * user;
	NSString * step;
	NSString * node_;
	NSString * queue;
	NSString * priority;
	NSString * information;
	NSNumber * severity;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_launch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_launchId * ident;
@property (retain) DuWebServiceSvc_variables * variables;
@property (retain) USBoolean * autoRestart;
@property (retain) USBoolean * centralControl;
@property (retain) USBoolean * forcedExecution;
@property (retain) USBoolean * bypassCondCheck;
@property (retain) NSString * exclusionFrom;
@property (retain) NSString * exclusionTo;
@property (retain) NSString * status;
@property (retain) NSString * beginDate;
@property (retain) NSString * beginHour;
@property (retain) NSString * endDate;
@property (retain) NSString * endHour;
@property (retain) NSString * processingDate;
@property (retain) NSString * user;
@property (retain) NSString * step;
@property (retain) NSString * node_;
@property (retain) NSString * queue;
@property (retain) NSString * priority;
@property (retain) NSString * information;
@property (retain) NSNumber * severity;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_addLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launch * launch;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_addLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launch * launch;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_taskId : NSObject {
	
/* elements */
	NSString * task;
	NSString * session;
	NSString * sessionVersion;
	NSString * uproc;
	NSString * uprocVersion;
	NSString * mu;
	USBoolean * template;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_taskId *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * task;
@property (retain) NSString * session;
@property (retain) NSString * sessionVersion;
@property (retain) NSString * uproc;
@property (retain) NSString * uprocVersion;
@property (retain) NSString * mu;
@property (retain) USBoolean * template;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_addLaunchFromTask : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_taskId * taskId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_addLaunchFromTask *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_taskId * taskId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_addLaunchFromTask2 : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_taskId * taskId;
	NSMutableArray *variables;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_addLaunchFromTask2 *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_taskId * taskId;
- (void)addVariables:(DuWebServiceSvc_variable *)toAdd;
@property (readonly) NSMutableArray * variables;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_addLaunchFromTask2Response : NSObject {
	
/* elements */
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_addLaunchFromTask2Response *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_addLaunchFromTaskResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_addLaunchFromTaskResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_addLaunchResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_addLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_bypassLaunchConditionCheck : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_bypassLaunchConditionCheck *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_bypassLaunchConditionCheckResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_bypassLaunchConditionCheckResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_outageWindow : NSObject {
	
/* elements */
	NSString * type;
	NSString * target;
	NSNumber * num;
	NSString * label;
	NSString * fromDate;
	NSString * untilDate;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_outageWindow *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * type;
@property (retain) NSString * target;
@property (retain) NSNumber * num;
@property (retain) NSString * label;
@property (retain) NSString * fromDate;
@property (retain) NSString * untilDate;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_createOutageWindow : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_outageWindow * outage;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_createOutageWindow *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_outageWindow * outage;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_createOutageWindowResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_outageWindow * outage;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_createOutageWindowResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_outageWindow * outage;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_deleteEvent : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_eventId * eventId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_deleteEvent *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_eventId * eventId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_deleteEventResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_deleteEventResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_deleteLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_deleteLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_deleteLaunchResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_deleteLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_deleteOutageWindow : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_outageWindow * outage;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_deleteOutageWindow *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_outageWindow * outage;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_deleteOutageWindowResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_deleteOutageWindowResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_disableLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_disableLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_disableLaunchResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_disableLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_enableLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_enableLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_enableLaunchResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_enableLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_engine : NSObject {
	
/* elements */
	NSString * engineCode;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_engine *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * engineCode;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_eventFilter : NSObject {
	
/* elements */
	NSString * uproc;
	NSString * session;
	NSString * mu;
	NSString * status;
	NSString * user;
	NSString * creationDateMin;
	NSString * creationDateMax;
	NSString * creationHourMin;
	NSString * creationHourMax;
	NSString * updateDateMin;
	NSString * updateDateMax;
	NSString * updateHourMin;
	NSString * updateHourMax;
	NSString * processingDate;
	NSString * numlancMin;
	NSString * numlancMax;
	NSString * numsessMin;
	NSString * numsessMax;
	NSString * numprocMin;
	NSString * numprocMax;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_eventFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * uproc;
@property (retain) NSString * session;
@property (retain) NSString * mu;
@property (retain) NSString * status;
@property (retain) NSString * user;
@property (retain) NSString * creationDateMin;
@property (retain) NSString * creationDateMax;
@property (retain) NSString * creationHourMin;
@property (retain) NSString * creationHourMax;
@property (retain) NSString * updateDateMin;
@property (retain) NSString * updateDateMax;
@property (retain) NSString * updateHourMin;
@property (retain) NSString * updateHourMax;
@property (retain) NSString * processingDate;
@property (retain) NSString * numlancMin;
@property (retain) NSString * numlancMax;
@property (retain) NSString * numsessMin;
@property (retain) NSString * numsessMax;
@property (retain) NSString * numprocMin;
@property (retain) NSString * numprocMax;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_eventItem : NSObject {
	
/* elements */
	DuWebServiceSvc_eventId * ident;
	NSString * status;
	NSString * step;
	NSString * authorCode;
	NSString * numLanc;
	NSString * creationDate;
	NSString * creationHour;
	NSString * updateDate;
	NSString * updateHour;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_eventItem *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_eventId * ident;
@property (retain) NSString * status;
@property (retain) NSString * step;
@property (retain) NSString * authorCode;
@property (retain) NSString * numLanc;
@property (retain) NSString * creationDate;
@property (retain) NSString * creationHour;
@property (retain) NSString * updateDate;
@property (retain) NSString * updateHour;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_executionId : NSObject {
	
/* elements */
	NSString * task;
	NSString * session;
	NSString * sessionVersion;
	NSString * uproc;
	NSString * uprocVersion;
	NSString * mu;
	NSString * numLanc;
	NSString * numProc;
	NSString * numSess;
	NSString * tempfilePath;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_executionId *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * task;
@property (retain) NSString * session;
@property (retain) NSString * sessionVersion;
@property (retain) NSString * uproc;
@property (retain) NSString * uprocVersion;
@property (retain) NSString * mu;
@property (retain) NSString * numLanc;
@property (retain) NSString * numProc;
@property (retain) NSString * numSess;
@property (retain) NSString * tempfilePath;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_executionItem : NSObject {
	
/* elements */
	DuWebServiceSvc_executionId * ident;
	NSString * status;
	NSString * beginDate;
	NSString * beginHour;
	NSString * endDate;
	NSString * endHour;
	NSString * processingDate;
	NSString * user;
	USBoolean * relaunched;
	NSString * node_;
	NSString * queue;
	NSString * priority;
	NSString * numEntry;
	NSString * info;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_executionItem *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_executionId * ident;
@property (retain) NSString * status;
@property (retain) NSString * beginDate;
@property (retain) NSString * beginHour;
@property (retain) NSString * endDate;
@property (retain) NSString * endHour;
@property (retain) NSString * processingDate;
@property (retain) NSString * user;
@property (retain) USBoolean * relaunched;
@property (retain) NSString * node_;
@property (retain) NSString * queue;
@property (retain) NSString * priority;
@property (retain) NSString * numEntry;
@property (retain) NSString * info;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_execution : NSObject {
	
/* elements */
	DuWebServiceSvc_executionItem * data;
	DuWebServiceSvc_variables * variables;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_execution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_executionItem * data;
@property (retain) DuWebServiceSvc_variables * variables;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_executionFilter : NSObject {
	
/* elements */
	NSString * task;
	NSString * session;
	NSString * uproc;
	NSString * mu;
	NSString * status;
	NSString * user;
	NSString * beginDateMin;
	NSString * beginDateMax;
	NSString * beginHourMin;
	NSString * beginHourMax;
	NSString * endDateMin;
	NSString * endDateMax;
	NSString * endHourMin;
	NSString * endHourMax;
	NSString * processingDate;
	NSString * numlancMin;
	NSString * numlancMax;
	NSString * numsessMin;
	NSString * numsessMax;
	NSString * numprocMin;
	NSString * numprocMax;
	USBoolean * relaunched;
	NSString * orderByFields;
	NSString * order;
	NSString * maximumResults;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_executionFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * task;
@property (retain) NSString * session;
@property (retain) NSString * uproc;
@property (retain) NSString * mu;
@property (retain) NSString * status;
@property (retain) NSString * user;
@property (retain) NSString * beginDateMin;
@property (retain) NSString * beginDateMax;
@property (retain) NSString * beginHourMin;
@property (retain) NSString * beginHourMax;
@property (retain) NSString * endDateMin;
@property (retain) NSString * endDateMax;
@property (retain) NSString * endHourMin;
@property (retain) NSString * endHourMax;
@property (retain) NSString * processingDate;
@property (retain) NSString * numlancMin;
@property (retain) NSString * numlancMax;
@property (retain) NSString * numsessMin;
@property (retain) NSString * numsessMax;
@property (retain) NSString * numprocMin;
@property (retain) NSString * numprocMax;
@property (retain) USBoolean * relaunched;
@property (retain) NSString * orderByFields;
@property (retain) NSString * order;
@property (retain) NSString * maximumResults;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_executionLog : NSObject {
	
/* elements */
	DuWebServiceSvc_executionId * ident;
	NSMutableArray *log;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_executionLog *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_executionId * ident;
- (void)addLog:(NSString *)toAdd;
@property (readonly) NSMutableArray * log;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_forceCompleteLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_forceCompleteLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_forceCompleteLaunchResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_forceCompleteLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_uvmsNodeFilter : NSObject {
	
/* elements */
	NSString * node_;
	NSString * company;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_uvmsNodeFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * node_;
@property (retain) NSString * company;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getDUEnvironmentList : NSObject {
	
/* elements */
	NSString * token;
	DuWebServiceSvc_uvmsNodeFilter * nodeFilter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getDUEnvironmentList *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * token;
@property (retain) DuWebServiceSvc_uvmsNodeFilter * nodeFilter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getDUEnvironmentListResponse : NSObject {
	
/* elements */
	NSMutableArray *envList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getDUEnvironmentListResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addEnvList:(DuWebServiceSvc_envir *)toAdd;
@property (readonly) NSMutableArray * envList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getEvent : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_eventId * eventId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getEvent *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_eventId * eventId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getEventResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_event * event;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getEventResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_event * event;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getExecution : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getExecution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getExecutionLog : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getExecutionLog *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getExecutionLogAsAttachment : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getExecutionLogAsAttachment *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getExecutionLogAsAttachmentResponse : NSObject {
	
/* elements */
	NSData * dataHandler;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getExecutionLogAsAttachmentResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSData * dataHandler;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getExecutionLogResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_executionLog * executionLog;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getExecutionLogResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_executionLog * executionLog;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getExecutionResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_execution * execution;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getExecutionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_execution * execution;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getHistoryTrace : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getHistoryTrace *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_historyTrace : NSObject {
	
/* elements */
	DuWebServiceSvc_executionId * ident;
	NSString * uprocLabel;
	NSString * sessionLabel;
	NSString * muLabel;
	NSMutableArray *trace;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_historyTrace *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_executionId * ident;
@property (retain) NSString * uprocLabel;
@property (retain) NSString * sessionLabel;
@property (retain) NSString * muLabel;
- (void)addTrace:(NSString *)toAdd;
@property (readonly) NSMutableArray * trace;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getHistoryTraceResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_historyTrace * historyTrace;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getHistoryTraceResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_historyTrace * historyTrace;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getLaunchFromTask : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_taskId * taskId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getLaunchFromTask *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_taskId * taskId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getLaunchFromTaskResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_launch * launch;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getLaunchFromTaskResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_launch * launch;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getLaunchResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_launch * launch;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_launch * launch;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListEvent : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_eventFilter * filter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListEvent *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_eventFilter * filter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListEventResponse : NSObject {
	
/* elements */
	NSMutableArray *eventList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListEventResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addEventList:(DuWebServiceSvc_eventItem *)toAdd;
@property (readonly) NSMutableArray * eventList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListExecution : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionFilter * filter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListExecution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionFilter * filter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListExecutionResponse : NSObject {
	
/* elements */
	NSMutableArray *executionList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListExecutionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addExecutionList:(DuWebServiceSvc_executionItem *)toAdd;
@property (readonly) NSMutableArray * executionList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_launchFilter : NSObject {
	
/* elements */
	NSString * task;
	NSString * session;
	NSString * uproc;
	NSString * mu;
	NSString * status;
	NSString * user;
	NSString * beginDateMin;
	NSString * beginDateMax;
	NSString * beginHourMin;
	NSString * beginHourMax;
	NSString * endDateMin;
	NSString * endDateMax;
	NSString * endHourMin;
	NSString * endHourMax;
	NSString * processingDate;
	NSString * numlancMin;
	NSString * numlancMax;
	NSString * numsessMin;
	NSString * numsessMax;
	NSString * numprocMin;
	NSString * numprocMax;
	NSString * orderByFields;
	NSString * order;
	NSString * maximumResults;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_launchFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * task;
@property (retain) NSString * session;
@property (retain) NSString * uproc;
@property (retain) NSString * mu;
@property (retain) NSString * status;
@property (retain) NSString * user;
@property (retain) NSString * beginDateMin;
@property (retain) NSString * beginDateMax;
@property (retain) NSString * beginHourMin;
@property (retain) NSString * beginHourMax;
@property (retain) NSString * endDateMin;
@property (retain) NSString * endDateMax;
@property (retain) NSString * endHourMin;
@property (retain) NSString * endHourMax;
@property (retain) NSString * processingDate;
@property (retain) NSString * numlancMin;
@property (retain) NSString * numlancMax;
@property (retain) NSString * numsessMin;
@property (retain) NSString * numsessMax;
@property (retain) NSString * numprocMin;
@property (retain) NSString * numprocMax;
@property (retain) NSString * orderByFields;
@property (retain) NSString * order;
@property (retain) NSString * maximumResults;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchFilter * filter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchFilter * filter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_launchItem : NSObject {
	
/* elements */
	DuWebServiceSvc_launchId * ident;
	NSString * status;
	NSString * beginDate;
	NSString * beginHour;
	NSString * endDate;
	NSString * endHour;
	NSString * processingDate;
	NSString * user;
	NSString * step;
	NSString * node_;
	NSString * queue;
	NSString * priority;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_launchItem *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_launchId * ident;
@property (retain) NSString * status;
@property (retain) NSString * beginDate;
@property (retain) NSString * beginHour;
@property (retain) NSString * endDate;
@property (retain) NSString * endHour;
@property (retain) NSString * processingDate;
@property (retain) NSString * user;
@property (retain) NSString * step;
@property (retain) NSString * node_;
@property (retain) NSString * queue;
@property (retain) NSString * priority;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListLaunchResponse : NSObject {
	
/* elements */
	NSMutableArray *launchList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addLaunchList:(DuWebServiceSvc_launchItem *)toAdd;
@property (readonly) NSMutableArray * launchList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_muFilter : NSObject {
	
/* elements */
	NSString * mu;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_muFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * mu;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListMU : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_muFilter * filter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListMU *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_muFilter * filter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_muId : NSObject {
	
/* elements */
	NSString * mu;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_muId *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * mu;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_muItem : NSObject {
	
/* elements */
	DuWebServiceSvc_muId * ident;
	NSString * label;
	NSString * node_;
	USBoolean * development;
	USBoolean * production;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_muItem *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_muId * ident;
@property (retain) NSString * label;
@property (retain) NSString * node_;
@property (retain) USBoolean * development;
@property (retain) USBoolean * production;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListMUResponse : NSObject {
	
/* elements */
	NSMutableArray *muList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListMUResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addMuList:(DuWebServiceSvc_muItem *)toAdd;
@property (readonly) NSMutableArray * muList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_nodeFilter : NSObject {
	
/* elements */
	NSString * node_;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_nodeFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * node_;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListNode : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_nodeFilter * filter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListNode *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_nodeFilter * filter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_nodeId : NSObject {
	
/* elements */
	NSString * node_;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_nodeId *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * node_;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_nodeItem : NSObject {
	
/* elements */
	DuWebServiceSvc_nodeId * ident;
	NSString * label;
	USBoolean * development;
	USBoolean * production;
	USBoolean * centralControl;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_nodeItem *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_nodeId * ident;
@property (retain) NSString * label;
@property (retain) USBoolean * development;
@property (retain) USBoolean * production;
@property (retain) USBoolean * centralControl;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListNodeResponse : NSObject {
	
/* elements */
	NSMutableArray *nodeList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListNodeResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addNodeList:(DuWebServiceSvc_nodeItem *)toAdd;
@property (readonly) NSMutableArray * nodeList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_outageFilter : NSObject {
	
/* elements */
	NSString * type;
	NSString * target;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_outageFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * type;
@property (retain) NSString * target;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListOutage : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_outageFilter * outage;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListOutage *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_outageFilter * outage;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListOutageResponse : NSObject {
	
/* elements */
	NSMutableArray *return_;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListOutageResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addReturn_:(DuWebServiceSvc_outageWindow *)toAdd;
@property (readonly) NSMutableArray * return_;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_sessionFilter : NSObject {
	
/* elements */
	NSString * session;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_sessionFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * session;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListSession : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_sessionFilter * filter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListSession *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_sessionFilter * filter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_sessionId : NSObject {
	
/* elements */
	NSString * session;
	NSString * sessionVersion;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_sessionId *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * session;
@property (retain) NSString * sessionVersion;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_sessionItem : NSObject {
	
/* elements */
	DuWebServiceSvc_sessionId * ident;
	NSString * label;
	NSString * head;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_sessionItem *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_sessionId * ident;
@property (retain) NSString * label;
@property (retain) NSString * head;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListSessionResponse : NSObject {
	
/* elements */
	NSMutableArray *sessionList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListSessionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addSessionList:(DuWebServiceSvc_sessionItem *)toAdd;
@property (readonly) NSMutableArray * sessionList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_taskFilter : NSObject {
	
/* elements */
	NSString * task;
	NSString * session;
	NSString * uproc;
	NSString * mu;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_taskFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * task;
@property (retain) NSString * session;
@property (retain) NSString * uproc;
@property (retain) NSString * mu;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListTask : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_taskFilter * filter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListTask *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_taskFilter * filter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_taskItem : NSObject {
	
/* elements */
	DuWebServiceSvc_taskId * ident;
	NSString * type;
	NSString * authorCode;
	NSString * queue;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_taskItem *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_taskId * ident;
@property (retain) NSString * type;
@property (retain) NSString * authorCode;
@property (retain) NSString * queue;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListTaskResponse : NSObject {
	
/* elements */
	NSMutableArray *taskList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListTaskResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addTaskList:(DuWebServiceSvc_taskItem *)toAdd;
@property (readonly) NSMutableArray * taskList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_uprocFilter : NSObject {
	
/* elements */
	NSString * uproc;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_uprocFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * uproc;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListUproc : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_uprocFilter * filter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListUproc *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_uprocFilter * filter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_uprocId : NSObject {
	
/* elements */
	NSString * uproc;
	NSString * uprocVersion;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_uprocId *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * uproc;
@property (retain) NSString * uprocVersion;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_uprocItem : NSObject {
	
/* elements */
	DuWebServiceSvc_uprocId * ident;
	NSString * label;
	NSString * domain;
	NSString * application;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_uprocItem *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_uprocId * ident;
@property (retain) NSString * label;
@property (retain) NSString * domain;
@property (retain) NSString * application;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getListUprocResponse : NSObject {
	
/* elements */
	NSMutableArray *uprocList;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getListUprocResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addUprocList:(DuWebServiceSvc_uprocItem *)toAdd;
@property (readonly) NSMutableArray * uprocList;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getPreviousLaunches : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getPreviousLaunches *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_previousLaunch : NSObject {
	
/* elements */
	NSString * uproc;
	NSString * numProc;
	NSString * launchDate;
	NSString * launchHour;
	NSString * type;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_previousLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * uproc;
@property (retain) NSString * numProc;
@property (retain) NSString * launchDate;
@property (retain) NSString * launchHour;
@property (retain) NSString * type;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getPreviousLaunchesResponse : NSObject {
	
/* elements */
	NSMutableArray *previousLaunches;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getPreviousLaunchesResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addPreviousLaunches:(DuWebServiceSvc_previousLaunch *)toAdd;
@property (readonly) NSMutableArray * previousLaunches;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_runBook : NSObject {
	
/* elements */
	NSString * name;
	NSNumber * nature;
	NSString * content;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_runBook *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * name;
@property (retain) NSNumber * nature;
@property (retain) NSString * content;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getRunBookExternalFile : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_runBook * runBook;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getRunBookExternalFile *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_runBook * runBook;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getRunBookExternalFileResponse : NSObject {
	
/* elements */
	NSData * fileDataHandler;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getRunBookExternalFileResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSData * fileDataHandler;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_runBookFilter : NSObject {
	
/* elements */
	NSString * uprocName;
	NSString * taskName;
	NSString * sessionName;
	NSString * application;
	NSString * muName;
	NSString * submissionAccount;
	NSString * queueName;
	NSString * severity;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_runBookFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * uprocName;
@property (retain) NSString * taskName;
@property (retain) NSString * sessionName;
@property (retain) NSString * application;
@property (retain) NSString * muName;
@property (retain) NSString * submissionAccount;
@property (retain) NSString * queueName;
@property (retain) NSString * severity;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getRunBooks : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_runBookFilter * runBookFilter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getRunBooks *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_runBookFilter * runBookFilter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getRunBooksResponse : NSObject {
	
/* elements */
	NSMutableArray *runbooks;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getRunBooksResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addRunbooks:(DuWebServiceSvc_runBook *)toAdd;
@property (readonly) NSMutableArray * runbooks;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_runNoteFilter : NSObject {
	
/* elements */
	NSString * session;
	NSString * sessionVersion;
	NSString * uproc;
	NSString * uprocVersion;
	NSString * task;
	NSString * taskVersion;
	NSString * mu;
	NSString * numnote;
	NSString * numlanc;
	NSString * numsess;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_runNoteFilter *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * session;
@property (retain) NSString * sessionVersion;
@property (retain) NSString * uproc;
@property (retain) NSString * uprocVersion;
@property (retain) NSString * task;
@property (retain) NSString * taskVersion;
@property (retain) NSString * mu;
@property (retain) NSString * numnote;
@property (retain) NSString * numlanc;
@property (retain) NSString * numsess;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getRunNotes : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_runNoteFilter * noteFilter;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getRunNotes *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_runNoteFilter * noteFilter;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_runNote : NSObject {
	
/* elements */
	NSString * creationDate;
	NSNumber * numproc;
	NSNumber * numlanc;
	NSString * noteText;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_runNote *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * creationDate;
@property (retain) NSNumber * numproc;
@property (retain) NSNumber * numlanc;
@property (retain) NSString * noteText;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getRunNotesResponse : NSObject {
	
/* elements */
	NSMutableArray *runNotes;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getRunNotesResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addRunNotes:(DuWebServiceSvc_runNote *)toAdd;
@property (readonly) NSMutableArray * runNotes;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getScriptResourceLog : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getScriptResourceLog *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_resourceLog : NSObject {
	
/* elements */
	DuWebServiceSvc_executionId * ident;
	NSMutableArray *log;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_resourceLog *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_executionId * ident;
- (void)addLog:(NSString *)toAdd;
@property (readonly) NSMutableArray * log;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_getScriptResourceLogResponse : NSObject {
	
/* elements */
	DuWebServiceSvc_resourceLog * resourceLog;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_getScriptResourceLogResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_resourceLog * resourceLog;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_holdLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launch;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_holdLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launch;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_holdLaunchResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_holdLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_uvmsContext : NSObject {
	
/* elements */
	NSString * uvmsHost;
	NSNumber * uvmsPort;
	NSString * uvmsUser;
	NSString * uvmsPassword;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_uvmsContext *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * uvmsHost;
@property (retain) NSNumber * uvmsPort;
@property (retain) NSString * uvmsUser;
@property (retain) NSString * uvmsPassword;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_login : NSObject {
	
/* elements */
	DuWebServiceSvc_uvmsContext * uvms;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_login *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_uvmsContext * uvms;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_loginResponse : NSObject {
	
/* elements */
	NSString * token;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_loginResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * token;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_logout : NSObject {
	
/* elements */
	NSString * token;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_logout *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * token;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_logoutResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_logoutResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_purgeExecution : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_purgeExecution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_purgeExecutionResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_purgeExecutionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_queue : NSObject {
	
/* elements */
	NSString * name;
	NSString * node_;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_queue *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * name;
@property (retain) NSString * node_;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_releaseLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_releaseLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_releaseLaunchResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_releaseLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_rerunExecution : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
	NSString * startDate;
	NSString * endDate;
	NSString * batchQueue;
	NSString * user;
	NSNumber * step;
	USBoolean * byPassCheck;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_rerunExecution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
@property (retain) NSString * startDate;
@property (retain) NSString * endDate;
@property (retain) NSString * batchQueue;
@property (retain) NSString * user;
@property (retain) NSNumber * step;
@property (retain) USBoolean * byPassCheck;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_rerunExecutionResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_rerunExecutionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_resetQueue : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_queue * queue;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_resetQueue *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_queue * queue;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_resetQueueResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_resetQueueResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_restartEngine : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_engine * engine;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_restartEngine *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_engine * engine;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_restartEngineResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_restartEngineResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_skipExecution : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_skipExecution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_skipExecutionResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_skipExecutionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_startEngine : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_engine * engine;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_startEngine *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_engine * engine;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_startEngineResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_startEngineResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_startQueue : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_queue * queue;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_startQueue *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_queue * queue;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_startQueueResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_startQueueResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_stopEngine : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_engine * engine;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_stopEngine *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_engine * engine;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_stopEngineResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_stopEngineResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_stopExecution : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_executionId * executionId;
	NSNumber * delay;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_stopExecution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_executionId * executionId;
@property (retain) NSNumber * delay;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_stopExecutionResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_stopExecutionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_stopQueue : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_queue * queue;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_stopQueue *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_queue * queue;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_stopQueueResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_stopQueueResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_unacknowledgeExecution : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launchId * launchId;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_unacknowledgeExecution *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launchId * launchId;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_unacknowledgeExecutionResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_unacknowledgeExecutionResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_updateEvent : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_eventId * eventId;
	NSString * status;
	NSString * step;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_updateEvent *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_eventId * eventId;
@property (retain) NSString * status;
@property (retain) NSString * step;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_updateEventResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_updateEventResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_updateLaunch : NSObject {
	
/* elements */
	DuWebServiceSvc_contextHolder * context;
	DuWebServiceSvc_launch * launch;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_updateLaunch *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) DuWebServiceSvc_contextHolder * context;
@property (retain) DuWebServiceSvc_launch * launch;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_updateLaunchResponse : NSObject {
	
/* elements */
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_updateLaunchResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_DuwsException : NSObject {
	
/* elements */
	NSNumber * errorCode;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_DuwsException *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * errorCode;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface DuWebServiceSvc_SessionTimedOutException : NSObject {
	
/* elements */
	NSNumber * timeout;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (DuWebServiceSvc_SessionTimedOutException *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * timeout;
/* attributes */
- (NSDictionary *)attributes;
@end
/* Cookies handling provided by http://en.wikibooks.org/wiki/Programming:WebObjects/Web_Services/Web_Service_Provider */
#import <libxml/parser.h>
#import "xs.h"
#import "DuWebServiceSvc.h"
@class DuWebServiceSoapBinding;
@interface DuWebServiceSvc : NSObject {
	
}
+ (DuWebServiceSoapBinding *)DuWebServiceSoapBinding;
@end
@class DuWebServiceSoapBindingResponse;
@class DuWebServiceSoapBindingOperation;
@protocol DuWebServiceSoapBindingResponseDelegate <NSObject>
- (void) operation:(DuWebServiceSoapBindingOperation *)operation completedWithResponse:(DuWebServiceSoapBindingResponse *)response;
@end
@interface DuWebServiceSoapBinding : NSObject <DuWebServiceSoapBindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(DuWebServiceSoapBindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (DuWebServiceSoapBindingResponse *)getListUprocUsingParameters:(DuWebServiceSvc_getListUproc *)aParameters ;
- (void)getListUprocAsyncUsingParameters:(DuWebServiceSvc_getListUproc *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)forceCompleteLaunchUsingParameters:(DuWebServiceSvc_forceCompleteLaunch *)aParameters ;
- (void)forceCompleteLaunchAsyncUsingParameters:(DuWebServiceSvc_forceCompleteLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)deleteEventUsingParameters:(DuWebServiceSvc_deleteEvent *)aParameters ;
- (void)deleteEventAsyncUsingParameters:(DuWebServiceSvc_deleteEvent *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getListSessionUsingParameters:(DuWebServiceSvc_getListSession *)aParameters ;
- (void)getListSessionAsyncUsingParameters:(DuWebServiceSvc_getListSession *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getLaunchUsingParameters:(DuWebServiceSvc_getLaunch *)aParameters ;
- (void)getLaunchAsyncUsingParameters:(DuWebServiceSvc_getLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)restartEngineUsingParameters:(DuWebServiceSvc_restartEngine *)aParameters ;
- (void)restartEngineAsyncUsingParameters:(DuWebServiceSvc_restartEngine *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)addLaunchUsingParameters:(DuWebServiceSvc_addLaunch *)aParameters ;
- (void)addLaunchAsyncUsingParameters:(DuWebServiceSvc_addLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getRunBooksUsingParameters:(DuWebServiceSvc_getRunBooks *)aParameters ;
- (void)getRunBooksAsyncUsingParameters:(DuWebServiceSvc_getRunBooks *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getListEventUsingParameters:(DuWebServiceSvc_getListEvent *)aParameters ;
- (void)getListEventAsyncUsingParameters:(DuWebServiceSvc_getListEvent *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getPreviousLaunchesUsingParameters:(DuWebServiceSvc_getPreviousLaunches *)aParameters ;
- (void)getPreviousLaunchesAsyncUsingParameters:(DuWebServiceSvc_getPreviousLaunches *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)addLaunchFromTaskUsingParameters:(DuWebServiceSvc_addLaunchFromTask *)aParameters ;
- (void)addLaunchFromTaskAsyncUsingParameters:(DuWebServiceSvc_addLaunchFromTask *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)stopQueueUsingParameters:(DuWebServiceSvc_stopQueue *)aParameters ;
- (void)stopQueueAsyncUsingParameters:(DuWebServiceSvc_stopQueue *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)logoutUsingParameters:(DuWebServiceSvc_logout *)aParameters ;
- (void)logoutAsyncUsingParameters:(DuWebServiceSvc_logout *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)enableLaunchUsingParameters:(DuWebServiceSvc_enableLaunch *)aParameters ;
- (void)enableLaunchAsyncUsingParameters:(DuWebServiceSvc_enableLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getListMUUsingParameters:(DuWebServiceSvc_getListMU *)aParameters ;
- (void)getListMUAsyncUsingParameters:(DuWebServiceSvc_getListMU *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)updateEventUsingParameters:(DuWebServiceSvc_updateEvent *)aParameters ;
- (void)updateEventAsyncUsingParameters:(DuWebServiceSvc_updateEvent *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)startEngineUsingParameters:(DuWebServiceSvc_startEngine *)aParameters ;
- (void)startEngineAsyncUsingParameters:(DuWebServiceSvc_startEngine *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getExecutionUsingParameters:(DuWebServiceSvc_getExecution *)aParameters ;
- (void)getExecutionAsyncUsingParameters:(DuWebServiceSvc_getExecution *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getExecutionLogUsingParameters:(DuWebServiceSvc_getExecutionLog *)aParameters ;
- (void)getExecutionLogAsyncUsingParameters:(DuWebServiceSvc_getExecutionLog *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)updateLaunchUsingParameters:(DuWebServiceSvc_updateLaunch *)aParameters ;
- (void)updateLaunchAsyncUsingParameters:(DuWebServiceSvc_updateLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)resetQueueUsingParameters:(DuWebServiceSvc_resetQueue *)aParameters ;
- (void)resetQueueAsyncUsingParameters:(DuWebServiceSvc_resetQueue *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getRunBookExternalFileUsingParameters:(DuWebServiceSvc_getRunBookExternalFile *)aParameters ;
- (void)getRunBookExternalFileAsyncUsingParameters:(DuWebServiceSvc_getRunBookExternalFile *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getRunNotesUsingParameters:(DuWebServiceSvc_getRunNotes *)aParameters ;
- (void)getRunNotesAsyncUsingParameters:(DuWebServiceSvc_getRunNotes *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)createOutageWindowUsingParameters:(DuWebServiceSvc_createOutageWindow *)aParameters ;
- (void)createOutageWindowAsyncUsingParameters:(DuWebServiceSvc_createOutageWindow *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getListLaunchUsingParameters:(DuWebServiceSvc_getListLaunch *)aParameters ;
- (void)getListLaunchAsyncUsingParameters:(DuWebServiceSvc_getListLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)holdLaunchUsingParameters:(DuWebServiceSvc_holdLaunch *)aParameters ;
- (void)holdLaunchAsyncUsingParameters:(DuWebServiceSvc_holdLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getListOutageUsingParameters:(DuWebServiceSvc_getListOutage *)aParameters ;
- (void)getListOutageAsyncUsingParameters:(DuWebServiceSvc_getListOutage *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getEventUsingParameters:(DuWebServiceSvc_getEvent *)aParameters ;
- (void)getEventAsyncUsingParameters:(DuWebServiceSvc_getEvent *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getExecutionLogAsAttachmentUsingParameters:(DuWebServiceSvc_getExecutionLogAsAttachment *)aParameters ;
- (void)getExecutionLogAsAttachmentAsyncUsingParameters:(DuWebServiceSvc_getExecutionLogAsAttachment *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)addEventUsingParameters:(DuWebServiceSvc_addEvent *)aParameters ;
- (void)addEventAsyncUsingParameters:(DuWebServiceSvc_addEvent *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)addLaunchFromTask2UsingParameters:(DuWebServiceSvc_addLaunchFromTask2 *)aParameters ;
- (void)addLaunchFromTask2AsyncUsingParameters:(DuWebServiceSvc_addLaunchFromTask2 *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getLaunchFromTaskUsingParameters:(DuWebServiceSvc_getLaunchFromTask *)aParameters ;
- (void)getLaunchFromTaskAsyncUsingParameters:(DuWebServiceSvc_getLaunchFromTask *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)purgeExecutionUsingParameters:(DuWebServiceSvc_purgeExecution *)aParameters ;
- (void)purgeExecutionAsyncUsingParameters:(DuWebServiceSvc_purgeExecution *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)deleteLaunchUsingParameters:(DuWebServiceSvc_deleteLaunch *)aParameters ;
- (void)deleteLaunchAsyncUsingParameters:(DuWebServiceSvc_deleteLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getListNodeUsingParameters:(DuWebServiceSvc_getListNode *)aParameters ;
- (void)getListNodeAsyncUsingParameters:(DuWebServiceSvc_getListNode *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getHistoryTraceUsingParameters:(DuWebServiceSvc_getHistoryTrace *)aParameters ;
- (void)getHistoryTraceAsyncUsingParameters:(DuWebServiceSvc_getHistoryTrace *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)skipExecutionUsingParameters:(DuWebServiceSvc_skipExecution *)aParameters ;
- (void)skipExecutionAsyncUsingParameters:(DuWebServiceSvc_skipExecution *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)rerunExecutionUsingParameters:(DuWebServiceSvc_rerunExecution *)aParameters ;
- (void)rerunExecutionAsyncUsingParameters:(DuWebServiceSvc_rerunExecution *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)releaseLaunchUsingParameters:(DuWebServiceSvc_releaseLaunch *)aParameters ;
- (void)releaseLaunchAsyncUsingParameters:(DuWebServiceSvc_releaseLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)stopExecutionUsingParameters:(DuWebServiceSvc_stopExecution *)aParameters ;
- (void)stopExecutionAsyncUsingParameters:(DuWebServiceSvc_stopExecution *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getScriptResourceLogUsingParameters:(DuWebServiceSvc_getScriptResourceLog *)aParameters ;
- (void)getScriptResourceLogAsyncUsingParameters:(DuWebServiceSvc_getScriptResourceLog *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)stopEngineUsingParameters:(DuWebServiceSvc_stopEngine *)aParameters ;
- (void)stopEngineAsyncUsingParameters:(DuWebServiceSvc_stopEngine *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getDUEnvironmentListUsingParameters:(DuWebServiceSvc_getDUEnvironmentList *)aParameters ;
- (void)getDUEnvironmentListAsyncUsingParameters:(DuWebServiceSvc_getDUEnvironmentList *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getListExecutionUsingParameters:(DuWebServiceSvc_getListExecution *)aParameters ;
- (void)getListExecutionAsyncUsingParameters:(DuWebServiceSvc_getListExecution *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)bypassLaunchConditionCheckUsingParameters:(DuWebServiceSvc_bypassLaunchConditionCheck *)aParameters ;
- (void)bypassLaunchConditionCheckAsyncUsingParameters:(DuWebServiceSvc_bypassLaunchConditionCheck *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)deleteOutageWindowUsingParameters:(DuWebServiceSvc_deleteOutageWindow *)aParameters ;
- (void)deleteOutageWindowAsyncUsingParameters:(DuWebServiceSvc_deleteOutageWindow *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)acknowledgeExecutionUsingParameters:(DuWebServiceSvc_acknowledgeExecution *)aParameters ;
- (void)acknowledgeExecutionAsyncUsingParameters:(DuWebServiceSvc_acknowledgeExecution *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)unacknowledgeExecutionUsingParameters:(DuWebServiceSvc_unacknowledgeExecution *)aParameters ;
- (void)unacknowledgeExecutionAsyncUsingParameters:(DuWebServiceSvc_unacknowledgeExecution *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)disableLaunchUsingParameters:(DuWebServiceSvc_disableLaunch *)aParameters ;
- (void)disableLaunchAsyncUsingParameters:(DuWebServiceSvc_disableLaunch *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)getListTaskUsingParameters:(DuWebServiceSvc_getListTask *)aParameters ;
- (void)getListTaskAsyncUsingParameters:(DuWebServiceSvc_getListTask *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)startQueueUsingParameters:(DuWebServiceSvc_startQueue *)aParameters ;
- (void)startQueueAsyncUsingParameters:(DuWebServiceSvc_startQueue *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
- (DuWebServiceSoapBindingResponse *)loginUsingParameters:(DuWebServiceSvc_login *)aParameters ;
- (void)loginAsyncUsingParameters:(DuWebServiceSvc_login *)aParameters  delegate:(id<DuWebServiceSoapBindingResponseDelegate>)responseDelegate;
@end
@interface DuWebServiceSoapBindingOperation : NSOperation {
	DuWebServiceSoapBinding *binding;
	DuWebServiceSoapBindingResponse *response;
	id<DuWebServiceSoapBindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) DuWebServiceSoapBinding *binding;
@property (readonly) DuWebServiceSoapBindingResponse *response;
@property (nonatomic, assign) id<DuWebServiceSoapBindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate;
@end
@interface DuWebServiceSoapBinding_getListUproc : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListUproc * parameters;
}
@property (retain) DuWebServiceSvc_getListUproc * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListUproc *)aParameters
;
@end
@interface DuWebServiceSoapBinding_forceCompleteLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_forceCompleteLaunch * parameters;
}
@property (retain) DuWebServiceSvc_forceCompleteLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_forceCompleteLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_deleteEvent : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_deleteEvent * parameters;
}
@property (retain) DuWebServiceSvc_deleteEvent * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_deleteEvent *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getListSession : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListSession * parameters;
}
@property (retain) DuWebServiceSvc_getListSession * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListSession *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getLaunch * parameters;
}
@property (retain) DuWebServiceSvc_getLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_restartEngine : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_restartEngine * parameters;
}
@property (retain) DuWebServiceSvc_restartEngine * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_restartEngine *)aParameters
;
@end
@interface DuWebServiceSoapBinding_addLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_addLaunch * parameters;
}
@property (retain) DuWebServiceSvc_addLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_addLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getRunBooks : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getRunBooks * parameters;
}
@property (retain) DuWebServiceSvc_getRunBooks * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getRunBooks *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getListEvent : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListEvent * parameters;
}
@property (retain) DuWebServiceSvc_getListEvent * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListEvent *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getPreviousLaunches : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getPreviousLaunches * parameters;
}
@property (retain) DuWebServiceSvc_getPreviousLaunches * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getPreviousLaunches *)aParameters
;
@end
@interface DuWebServiceSoapBinding_addLaunchFromTask : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_addLaunchFromTask * parameters;
}
@property (retain) DuWebServiceSvc_addLaunchFromTask * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_addLaunchFromTask *)aParameters
;
@end
@interface DuWebServiceSoapBinding_stopQueue : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_stopQueue * parameters;
}
@property (retain) DuWebServiceSvc_stopQueue * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_stopQueue *)aParameters
;
@end
@interface DuWebServiceSoapBinding_logout : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_logout * parameters;
}
@property (retain) DuWebServiceSvc_logout * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_logout *)aParameters
;
@end
@interface DuWebServiceSoapBinding_enableLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_enableLaunch * parameters;
}
@property (retain) DuWebServiceSvc_enableLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_enableLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getListMU : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListMU * parameters;
}
@property (retain) DuWebServiceSvc_getListMU * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListMU *)aParameters
;
@end
@interface DuWebServiceSoapBinding_updateEvent : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_updateEvent * parameters;
}
@property (retain) DuWebServiceSvc_updateEvent * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_updateEvent *)aParameters
;
@end
@interface DuWebServiceSoapBinding_startEngine : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_startEngine * parameters;
}
@property (retain) DuWebServiceSvc_startEngine * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_startEngine *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getExecution : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getExecution * parameters;
}
@property (retain) DuWebServiceSvc_getExecution * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getExecution *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getExecutionLog : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getExecutionLog * parameters;
}
@property (retain) DuWebServiceSvc_getExecutionLog * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getExecutionLog *)aParameters
;
@end
@interface DuWebServiceSoapBinding_updateLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_updateLaunch * parameters;
}
@property (retain) DuWebServiceSvc_updateLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_updateLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_resetQueue : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_resetQueue * parameters;
}
@property (retain) DuWebServiceSvc_resetQueue * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_resetQueue *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getRunBookExternalFile : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getRunBookExternalFile * parameters;
}
@property (retain) DuWebServiceSvc_getRunBookExternalFile * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getRunBookExternalFile *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getRunNotes : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getRunNotes * parameters;
}
@property (retain) DuWebServiceSvc_getRunNotes * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getRunNotes *)aParameters
;
@end
@interface DuWebServiceSoapBinding_createOutageWindow : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_createOutageWindow * parameters;
}
@property (retain) DuWebServiceSvc_createOutageWindow * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_createOutageWindow *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getListLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListLaunch * parameters;
}
@property (retain) DuWebServiceSvc_getListLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_holdLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_holdLaunch * parameters;
}
@property (retain) DuWebServiceSvc_holdLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_holdLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getListOutage : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListOutage * parameters;
}
@property (retain) DuWebServiceSvc_getListOutage * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListOutage *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getEvent : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getEvent * parameters;
}
@property (retain) DuWebServiceSvc_getEvent * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getEvent *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getExecutionLogAsAttachment : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getExecutionLogAsAttachment * parameters;
}
@property (retain) DuWebServiceSvc_getExecutionLogAsAttachment * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getExecutionLogAsAttachment *)aParameters
;
@end
@interface DuWebServiceSoapBinding_addEvent : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_addEvent * parameters;
}
@property (retain) DuWebServiceSvc_addEvent * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_addEvent *)aParameters
;
@end
@interface DuWebServiceSoapBinding_addLaunchFromTask2 : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_addLaunchFromTask2 * parameters;
}
@property (retain) DuWebServiceSvc_addLaunchFromTask2 * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_addLaunchFromTask2 *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getLaunchFromTask : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getLaunchFromTask * parameters;
}
@property (retain) DuWebServiceSvc_getLaunchFromTask * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getLaunchFromTask *)aParameters
;
@end
@interface DuWebServiceSoapBinding_purgeExecution : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_purgeExecution * parameters;
}
@property (retain) DuWebServiceSvc_purgeExecution * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_purgeExecution *)aParameters
;
@end
@interface DuWebServiceSoapBinding_deleteLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_deleteLaunch * parameters;
}
@property (retain) DuWebServiceSvc_deleteLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_deleteLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getListNode : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListNode * parameters;
}
@property (retain) DuWebServiceSvc_getListNode * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListNode *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getHistoryTrace : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getHistoryTrace * parameters;
}
@property (retain) DuWebServiceSvc_getHistoryTrace * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getHistoryTrace *)aParameters
;
@end
@interface DuWebServiceSoapBinding_skipExecution : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_skipExecution * parameters;
}
@property (retain) DuWebServiceSvc_skipExecution * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_skipExecution *)aParameters
;
@end
@interface DuWebServiceSoapBinding_rerunExecution : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_rerunExecution * parameters;
}
@property (retain) DuWebServiceSvc_rerunExecution * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_rerunExecution *)aParameters
;
@end
@interface DuWebServiceSoapBinding_releaseLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_releaseLaunch * parameters;
}
@property (retain) DuWebServiceSvc_releaseLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_releaseLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_stopExecution : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_stopExecution * parameters;
}
@property (retain) DuWebServiceSvc_stopExecution * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_stopExecution *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getScriptResourceLog : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getScriptResourceLog * parameters;
}
@property (retain) DuWebServiceSvc_getScriptResourceLog * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getScriptResourceLog *)aParameters
;
@end
@interface DuWebServiceSoapBinding_stopEngine : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_stopEngine * parameters;
}
@property (retain) DuWebServiceSvc_stopEngine * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_stopEngine *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getDUEnvironmentList : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getDUEnvironmentList * parameters;
}
@property (retain) DuWebServiceSvc_getDUEnvironmentList * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getDUEnvironmentList *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getListExecution : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListExecution * parameters;
}
@property (retain) DuWebServiceSvc_getListExecution * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListExecution *)aParameters
;
@end
@interface DuWebServiceSoapBinding_bypassLaunchConditionCheck : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_bypassLaunchConditionCheck * parameters;
}
@property (retain) DuWebServiceSvc_bypassLaunchConditionCheck * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_bypassLaunchConditionCheck *)aParameters
;
@end
@interface DuWebServiceSoapBinding_deleteOutageWindow : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_deleteOutageWindow * parameters;
}
@property (retain) DuWebServiceSvc_deleteOutageWindow * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_deleteOutageWindow *)aParameters
;
@end
@interface DuWebServiceSoapBinding_acknowledgeExecution : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_acknowledgeExecution * parameters;
}
@property (retain) DuWebServiceSvc_acknowledgeExecution * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_acknowledgeExecution *)aParameters
;
@end
@interface DuWebServiceSoapBinding_unacknowledgeExecution : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_unacknowledgeExecution * parameters;
}
@property (retain) DuWebServiceSvc_unacknowledgeExecution * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_unacknowledgeExecution *)aParameters
;
@end
@interface DuWebServiceSoapBinding_disableLaunch : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_disableLaunch * parameters;
}
@property (retain) DuWebServiceSvc_disableLaunch * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_disableLaunch *)aParameters
;
@end
@interface DuWebServiceSoapBinding_getListTask : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_getListTask * parameters;
}
@property (retain) DuWebServiceSvc_getListTask * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_getListTask *)aParameters
;
@end
@interface DuWebServiceSoapBinding_startQueue : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_startQueue * parameters;
}
@property (retain) DuWebServiceSvc_startQueue * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_startQueue *)aParameters
;
@end
@interface DuWebServiceSoapBinding_login : DuWebServiceSoapBindingOperation {
	DuWebServiceSvc_login * parameters;
}
@property (retain) DuWebServiceSvc_login * parameters;
- (id)initWithBinding:(DuWebServiceSoapBinding *)aBinding delegate:(id<DuWebServiceSoapBindingResponseDelegate>)aDelegate
	parameters:(DuWebServiceSvc_login *)aParameters
;
@end
@interface DuWebServiceSoapBinding_envelope : NSObject {
}
+ (DuWebServiceSoapBinding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface DuWebServiceSoapBindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
