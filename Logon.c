Logon()
{

	web_add_cookie("birdsmp04.na.sas.com_Cluster=2C4A0D48B64F3269567B7E35E8BB1572.birdsmp04.na.sas.com_SASServer1_1; DOMAIN=birdsmp04.na.sas.com");

	lr_think_time(16);

	web_submit_data("login;birdsmp04.na.sas.com_Cluster=19B802BADCCDFA791C25D9E187633C13.birdsmp04.na.sas.com_SASServer1_1", 
		"Action=http://birdsmp04.na.sas.com/SASLogon/login;birdsmp04.na.sas.com_Cluster=19B802BADCCDFA791C25D9E187633C13.birdsmp04.na.sas.com_SASServer1_1?service=http%3A%2F%2Fbirdsmp04.na.sas.com%2FSASVisualAnalyticsExplorer%2Fj_spring_cas_security_check", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://birdsmp04.na.sas.com/SASLogon/login?service=http%3A%2F%2Fbirdsmp04.na.sas.com%2FSASVisualAnalyticsExplorer%2Fj_spring_cas_security_check", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=rdtest0001", ENDITEM, 
		"Name=password", "Value=good2go", ENDITEM, 
		"Name=lt", "Value=LT-23-Kc5fL36haBcikHMxcwsipEOZolJ0PY", ENDITEM, 
		"Name=execution", "Value=e1s1", ENDITEM, 
		"Name=_eventId", "Value=submit", ENDITEM, 
		LAST);

	web_concurrent_start(NULL);

	web_url("swfobject.js", 
		"URL=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/scripts/swfobject.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.jsp", 
		"Snapshot=t5.inf", 
		LAST);

	web_url("rightClick.js", 
		"URL=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/scripts/rightClick.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.jsp", 
		"Snapshot=t6.inf", 
		LAST);

	web_add_header("x-flash-version", 
		"11,7,700,202");

	web_url("VisualAnalyticsExplorerApp.swf", 
		"URL=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Resource=1", 
		"RecContentType=application/x-shockwave-flash", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.jsp", 
		"Snapshot=t7.inf", 
		LAST);

	web_add_header("x-flash-version", 
		"11,7,700,202");

	web_url("splash.swf", 
		"URL=http://birdsmp04.na.sas.com/SASFlexThemes/4.1/ApplicationThemes/Corporate/splash.swf", 
		"Resource=1", 
		"RecContentType=application/x-shockwave-flash", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t8.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_header("x-flash-version", 
		"11,7,700,202");

	lr_think_time(4);

	web_submit_data("config.xml", 
		"Action=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/config.xml", 
		"Method=POST", 
		"RecContentType=application/xml", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=dummy", "Value=dummy", ENDITEM, 
		LAST);

	web_url("historyFrame.html", 
		"URL=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/history/historyFrame.html?", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.jsp", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("x-flash-version", 
		"11,7,700,202");

	web_concurrent_start(NULL);

	web_url("FlexServicesConfigServlet", 
		"URL=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/FlexServicesConfigServlet", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t11.inf", 
		LAST);

	web_add_header("x-flash-version", 
		"11,7,700,202");

	web_url("ResourceModule_en_US.swf", 
		"URL=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/ResourceModules/ResourceModule_en_US.swf", 
		"Resource=1", 
		"RecContentType=application/x-shockwave-flash", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t12.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("x-flash-version", "11,7,700,202");

	web_submit_data("keepalive", 
		"Action=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/service/keepalive", 
		"Method=POST", 
		"RecContentType=text/plain", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=dummyTimeoutParam", "Value=true", ENDITEM, 
		LAST);

	flex_amf_call("AMF3_call", 
		"Gateway=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/"
		"messagebroker/sasamf", 
		"Snapshot=t14.inf", 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/1", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.CommandMessage><destination></destination>"
		"<messageId>04F70790-DA98-FB05-00F9-1A92DE070668</messageId><timestamp"
		">0</timestamp><timeToLive>0</timeToLive><headers><entry><string>DSId</"
		"string><string>nil</string></entry><entry><string>DSMessagingVersion</"
		"string><int>1</int></entry></headers><body class=\""
		"flex.messaging.io.amf.ASObject\" serialization=\"custom\">"
		"<unserializable-parents/><map><default><loadFactor>0.75</loadFactor>"
		"<threshold>12</threshold></default><int>16</int><int>0</int></map>"
		"<flex.messaging.io.amf.ASObject><default><inHashCode>false</inHashCode"
		"><inToString>false</inToString></default></"
		"flex.messaging.io.amf.ASObject></body><correlationId></correlationId>"
		"<operation>5</operation></flex.messaging.messages.CommandMessage></"
		"object-externalizable-custom></AMF3>", 
		END_ARGUMENTS, 
		LAST);

	flex_amf_call("AMF3_call_1", 
		"Gateway=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/"
		"messagebroker/sasamf", 
		"Snapshot=t15.inf", 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/2", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination"
		">preferenceService</destination><messageId"
		">1638A08F-4E75-2323-145E-1A92DDEC7226</messageId><timestamp>0</"
		"timestamp><timeToLive>0</timeToLive><headers><entry><string>DSEndpoint"
		"</string><string>amf</string></entry><entry><string>DSId</string>"
		"<string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></entry></headers"
		"><operation>getPreference</operation><parameters><string>Visual "
		"Analytics Explorer.recentWork</string></parameters></"
		"flex.messaging.messages.RemotingMessage></object-externalizable-custom"
		"></AMF3>", 
		END_ARGUMENTS, 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/3", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination"
		">preferenceService</destination><messageId"
		">F017E300-F0CB-258F-FCE7-1A92DDF4D372</messageId><timestamp>0</"
		"timestamp><timeToLive>0</timeToLive><headers><entry><string>DSEndpoint"
		"</string><string>amf</string></entry><entry><string>DSId</string>"
		"<string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></entry></headers"
		"><operation>getPreference</operation><parameters><string>Visual "
		"Analytics Explorer.workspaceShell.workspaceDisplay</string></"
		"parameters></flex.messaging.messages.RemotingMessage></"
		"object-externalizable-custom></AMF3>", 
		END_ARGUMENTS, 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/4", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination"
		">preferenceService</destination><messageId"
		">2B9D98ED-B73B-CB0D-29C1-1A92DDF5DDCC</messageId><timestamp>0</"
		"timestamp><timeToLive>0</timeToLive><headers><entry><string>DSEndpoint"
		"</string><string>amf</string></entry><entry><string>DSId</string>"
		"<string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></entry></headers"
		"><operation>getPreferences</operation><parameters><object-array>"
		"<string>Visual Analytics Explorer.workspaceShell.initialWorkspace</"
		"string><string>Visual Analytics Explorer.workspaceShell.maxRecentWork<"
		"/string></object-array></parameters></"
		"flex.messaging.messages.RemotingMessage></object-externalizable-custom"
		"></AMF3>", 
		END_ARGUMENTS, 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/5", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination"
		">preferenceService</destination><messageId"
		">E0F105F5-AEB6-24CB-A0C4-1A92DDF5F7FA</messageId><timestamp>0</"
		"timestamp><timeToLive>0</timeToLive><headers><entry><string>DSEndpoint"
		"</string><string>amf</string></entry><entry><string>DSId</string>"
		"<string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></entry></headers"
		"><operation>getPreference</operation><parameters><string>Visual "
		"Analytics Explorer.workspaceShell.userStateBlock</string></parameters>"
		"</flex.messaging.messages.RemotingMessage></"
		"object-externalizable-custom></AMF3>", 
		END_ARGUMENTS, 
		LAST);

	web_concurrent_start(NULL);

	web_url("ResourceModule_Formats.swf", 
		"URL=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/ResourceModules/ResourceModule_Formats.swf", 
		"Resource=1", 
		"RecContentType=application/x-shockwave-flash", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t16.inf", 
		LAST);

	web_url("Themes.xml", 
		"URL=http://birdsmp04.na.sas.com/SASFlexThemes/4.1/Themes.xml", 
		"Resource=1", 
		"RecContentType=application/xml", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t17.inf", 
		LAST);

	web_url("Corporate.swf", 
		"URL=http://birdsmp04.na.sas.com/SASFlexThemes/4.1/ApplicationThemes/Corporate/Corporate.swf", 
		"Resource=1", 
		"RecContentType=application/x-shockwave-flash", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t18.inf", 
		LAST);

	web_url("VisualAnalyticsExplorerApp_Corporate.swf", 
		"URL=http://birdsmp04.na.sas.com/SASFlexThemes/4.1/ApplicationThemes/Corporate/VisualAnalyticsExplorerApp_Corporate.swf", 
		"Resource=1", 
		"RecContentType=application/x-shockwave-flash", 
		"Referer=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/VisualAnalyticsExplorer/VisualAnalyticsExplorerApp.swf", 
		"Snapshot=t19.inf", 
		LAST);

	web_concurrent_end(NULL);

	flex_amf_call("AMF3_call_2", 
		"Gateway=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/"
		"messagebroker/sasamf", 
		"Snapshot=t20.inf", 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/6", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination>initService</"
		"destination><messageId>986B9711-B4F1-C2A6-5975-1A92EA5ED8FA</messageId"
		"><timestamp>0</timestamp><timeToLive>0</timeToLive><headers><entry>"
		"<string>DSEndpoint</string><string>amf</string></entry><entry><string"
		">DSId</string><string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></"
		"entry></headers><operation>getInitDto</operation><parameters/></"
		"flex.messaging.messages.RemotingMessage></object-externalizable-custom"
		"></AMF3>", 
		END_ARGUMENTS, 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/7", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination"
		">preferenceService</destination><messageId"
		">95BCAAC1-727F-3A6F-69FE-1A92EA60011A</messageId><timestamp>0</"
		"timestamp><timeToLive>0</timeToLive><headers><entry><string>DSEndpoint"
		"</string><string>amf</string></entry><entry><string>DSId</string>"
		"<string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></entry></headers"
		"><operation>getPreferences</operation><parameters><object-array>"
		"<string>prefs.vae.general.showDockPanel</string><string"
		">prefs.vae.general.dataLoadFactor</string><string"
		">prefs.vae.general.graphSkin</string><string"
		">VisualAnalytics.recentItemsListSize</string></object-array></"
		"parameters></flex.messaging.messages.RemotingMessage></"
		"object-externalizable-custom></AMF3>", 
		END_ARGUMENTS, 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/8", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination"
		">dataProviderService</destination><messageId"
		">0C4842E0-BD8E-B5E1-983F-1A92EA67F091</messageId><timestamp>0</"
		"timestamp><timeToLive>0</timeToLive><headers><entry><string>DSEndpoint"
		"</string><string>amf</string></entry><entry><string>DSId</string>"
		"<string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></entry></headers"
		"><operation>getAllGeoMapRoles</operation><parameters/></"
		"flex.messaging.messages.RemotingMessage></object-externalizable-custom"
		"></AMF3>", 
		END_ARGUMENTS, 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/9", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination>historyService</"
		"destination><messageId>6C6F5FA3-2BED-16D3-3594-1A92EA6E3921</messageId"
		"><timestamp>0</timestamp><timeToLive>0</timeToLive><headers><entry>"
		"<string>DSEndpoint</string><string>amf</string></entry><entry><string"
		">DSId</string><string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></"
		"entry></headers><operation>getHistoryFolderForApplication</operation>"
		"<parameters><string>VisualAnalytics</string></parameters></"
		"flex.messaging.messages.RemotingMessage></object-externalizable-custom"
		"></AMF3>", 
		END_ARGUMENTS, 
		LAST);

	flex_amf_call("AMF3_call_3", 
		"Gateway=http://birdsmp04.na.sas.com/SASVisualAnalyticsExplorer/"
		"messagebroker/sasamf", 
		"Snapshot=t21.inf", 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/10", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><destination>loggingService</"
		"destination><messageId>FC553D29-7130-F9C3-265F-1A92EC63EF5D</messageId"
		"><timestamp>0</timestamp><timeToLive>0</timeToLive><headers><entry>"
		"<string>DSEndpoint</string><string>amf</string></entry><entry><string"
		">DSId</string><string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></"
		"entry></headers><operation>log</operation><parameters>"
		"<flex.messaging.io.amf.ASObject serialization=\"custom\">"
		"<unserializable-parents/><map><default><loadFactor>0.75</loadFactor>"
		"<threshold>12</threshold></default><int>16</int><int>8</int><string"
		">userName</string><string></string><string>performanceLoggingType</"
		"string><int>2</int><string>operationData</string><string></string>"
		"<string>extraData</string><null/><string>startTimeMS</string><double"
		">1.370540403294E12</double><string>guid</string><string></string>"
		"<string>stopTimeMS</string><double>1.370540403808E12</double><string"
		">operation</string><string>INITIALIZE_APPLICATION</string></map>"
		"<flex.messaging.io.amf.ASObject><default><inHashCode>false</inHashCode"
		"><inToString>false</inToString><namedType"
		">com.sas.biv.common.dto.PerformanceLoggingDto</namedType></default></"
		"flex.messaging.io.amf.ASObject></flex.messaging.io.amf.ASObject></"
		"parameters></flex.messaging.messages.RemotingMessage></"
		"object-externalizable-custom></AMF3>", 
		END_ARGUMENTS, 
		MESSAGE, 
		"Method=null", 
		"TargetObjectId=/11", 
		BEGIN_ARGUMENTS, 
		"<AMF3><object-externalizable-custom>"
		"<flex.messaging.messages.RemotingMessage><clientId class=\"string\""
		">FE0B3D4C-E389-776C-36F8-87F73C4225EE</clientId><destination"
		">historyService</destination><messageId"
		">9CA41011-FC03-F92D-5C6E-1A92ED4BB746</messageId><timestamp>0</"
		"timestamp><timeToLive>0</timeToLive><headers><entry><string>DSEndpoint"
		"</string><string>amf</string></entry><entry><string>DSId</string>"
		"<string>FE0923BB-B0DE-2D11-D8E7-347C25FDD30D</string></entry></headers"
		"><operation>getHistoryFolderContents</operation><parameters>"
		"<flex.messaging.io.amf.ASObject serialization=\"custom\">"
		"<unserializable-parents/><map><default><loadFactor>0.75</loadFactor>"
		"<threshold>24</threshold></default><int>32</int><int>13</int><string"
		">modifiedBy</string><string>rdtest0001</string><string>maxSize</string"
		"><int>-1</int><string>creationDate</string><date>2013-05-16 15:59"
		":36.390 GMT</date><string>createdBy</string><string>rdtest0001</string"
		"><string>objectType</string><int>104</int><string>id</string><string"
		">A5SA6Q01.BP000003/FavoritesContainer</string><string>objectTypeName</"
		"string><string>HistoryFolder</string><string>descriptor</string>"
		"<boolean>false</boolean><string>modifiedDate</string><date>2013-05-20 "
		"19:31:43.650 GMT</date><string>contextName</string><string"
		">VisualAnalytics</string><string>description</string><string></string>"
		"<string>internalVersion</string><int>-1</int><string>name</string>"
		"<string>History</string></map><flex.messaging.io.amf.ASObject><default"
		"><inHashCode>false</inHashCode><inToString>false</inToString>"
		"<namedType"
		">com.sas.svcs.content.history.client.ApplicationHistoryFolder</"
		"namedType></default></flex.messaging.io.amf.ASObject></"
		"flex.messaging.io.amf.ASObject></parameters></"
		"flex.messaging.messages.RemotingMessage></object-externalizable-custom"
		"></AMF3>", 
		END_ARGUMENTS, 
		LAST);

	return 0;
}
