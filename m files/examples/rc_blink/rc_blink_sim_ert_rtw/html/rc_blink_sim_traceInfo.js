function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Input */
	this.urlHashMap["rc_blink_sim:5"] = "rc_blink_sim.h:115";
	/* <Root>/MATLAB System */
	this.urlHashMap["rc_blink_sim:1"] = "rc_blink_sim.c:310,331,332,338&rc_blink_sim.h:125,128";
	/* <Root>/MATLAB System1 */
	this.urlHashMap["rc_blink_sim:2"] = "rc_blink_sim.h:105,130,170&rc_blink_sim_data.c:44,47,52";
	/* <Root>/MATLAB System2 */
	this.urlHashMap["rc_blink_sim:3"] = "rc_blink_sim.c:315,340,341,348&rc_blink_sim.h:126,129";
	/* <Root>/MATLAB System3 */
	this.urlHashMap["rc_blink_sim:8"] = "rc_blink_sim.c:109,128,129,145,146,158,159,165&rc_blink_sim.h:90,92,95,97,98,99,106,131,143,146,171&rc_blink_sim_types.h:64&rc_blink_sim_data.c:54,57,62";
	/* <Root>/MATLAB System4 */
	this.urlHashMap["rc_blink_sim:28"] = "rc_blink_sim.h:107,132,172&rc_blink_sim_data.c:64,67,72";
	/* <Root>/MATLAB System5 */
	this.urlHashMap["rc_blink_sim:30"] = "rc_blink_sim.c:42,61,62,78,79,91,92,98&rc_blink_sim.h:78,80,83,85,86,87,108,133,136,139,173&rc_blink_sim_types.h:61&rc_blink_sim_data.c:74,77,80";
	/* <Root>/Output */
	this.urlHashMap["rc_blink_sim:7"] = "rc_blink_sim.h:119";
	/* <Root>/Sine Wave */
	this.urlHashMap["rc_blink_sim:6"] = "rc_blink_sim.c:176,201,207,319&rc_blink_sim.h:127,153,156,159,162&rc_blink_sim_data.c:26,29,32,35";
	/* <Root>/get_led */
	this.urlHashMap["rc_blink_sim:29"] = "rc_blink_sim.h:123";
	/* <S1>/Compare */
	this.urlHashMap["rc_blink_sim:4:2"] = "rc_blink_sim.c:174&rc_blink_sim.h:104";
	/* <S1>/Constant */
	this.urlHashMap["rc_blink_sim:4:3"] = "rc_blink_sim.c:175&rc_blink_sim.h:165&rc_blink_sim_data.c:38";
	/* <S2>/Compare */
	this.urlHashMap["rc_blink_sim:10:2"] = "rc_blink_sim.c:186";
	/* <S2>/Constant */
	this.urlHashMap["rc_blink_sim:10:3"] = "rc_blink_sim.c:187&rc_blink_sim.h:168&rc_blink_sim_data.c:41";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "rc_blink_sim"};
	this.sidHashMap["rc_blink_sim"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "rc_blink_sim:4"};
	this.sidHashMap["rc_blink_sim:4"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "rc_blink_sim:10"};
	this.sidHashMap["rc_blink_sim:10"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/Compare To Zero"] = {sid: "rc_blink_sim:4"};
	this.sidHashMap["rc_blink_sim:4"] = {rtwname: "<Root>/Compare To Zero"};
	this.rtwnameHashMap["<Root>/Compare To Zero1"] = {sid: "rc_blink_sim:10"};
	this.sidHashMap["rc_blink_sim:10"] = {rtwname: "<Root>/Compare To Zero1"};
	this.rtwnameHashMap["<Root>/Input"] = {sid: "rc_blink_sim:5"};
	this.sidHashMap["rc_blink_sim:5"] = {rtwname: "<Root>/Input"};
	this.rtwnameHashMap["<Root>/MATLAB System"] = {sid: "rc_blink_sim:1"};
	this.sidHashMap["rc_blink_sim:1"] = {rtwname: "<Root>/MATLAB System"};
	this.rtwnameHashMap["<Root>/MATLAB System1"] = {sid: "rc_blink_sim:2"};
	this.sidHashMap["rc_blink_sim:2"] = {rtwname: "<Root>/MATLAB System1"};
	this.rtwnameHashMap["<Root>/MATLAB System2"] = {sid: "rc_blink_sim:3"};
	this.sidHashMap["rc_blink_sim:3"] = {rtwname: "<Root>/MATLAB System2"};
	this.rtwnameHashMap["<Root>/MATLAB System3"] = {sid: "rc_blink_sim:8"};
	this.sidHashMap["rc_blink_sim:8"] = {rtwname: "<Root>/MATLAB System3"};
	this.rtwnameHashMap["<Root>/MATLAB System4"] = {sid: "rc_blink_sim:28"};
	this.sidHashMap["rc_blink_sim:28"] = {rtwname: "<Root>/MATLAB System4"};
	this.rtwnameHashMap["<Root>/MATLAB System5"] = {sid: "rc_blink_sim:30"};
	this.sidHashMap["rc_blink_sim:30"] = {rtwname: "<Root>/MATLAB System5"};
	this.rtwnameHashMap["<Root>/Output"] = {sid: "rc_blink_sim:7"};
	this.sidHashMap["rc_blink_sim:7"] = {rtwname: "<Root>/Output"};
	this.rtwnameHashMap["<Root>/Sine Wave"] = {sid: "rc_blink_sim:6"};
	this.sidHashMap["rc_blink_sim:6"] = {rtwname: "<Root>/Sine Wave"};
	this.rtwnameHashMap["<Root>/get_led"] = {sid: "rc_blink_sim:29"};
	this.sidHashMap["rc_blink_sim:29"] = {rtwname: "<Root>/get_led"};
	this.rtwnameHashMap["<S1>/u"] = {sid: "rc_blink_sim:4:1"};
	this.sidHashMap["rc_blink_sim:4:1"] = {rtwname: "<S1>/u"};
	this.rtwnameHashMap["<S1>/Compare"] = {sid: "rc_blink_sim:4:2"};
	this.sidHashMap["rc_blink_sim:4:2"] = {rtwname: "<S1>/Compare"};
	this.rtwnameHashMap["<S1>/Constant"] = {sid: "rc_blink_sim:4:3"};
	this.sidHashMap["rc_blink_sim:4:3"] = {rtwname: "<S1>/Constant"};
	this.rtwnameHashMap["<S1>/y"] = {sid: "rc_blink_sim:4:5"};
	this.sidHashMap["rc_blink_sim:4:5"] = {rtwname: "<S1>/y"};
	this.rtwnameHashMap["<S2>/u"] = {sid: "rc_blink_sim:10:1"};
	this.sidHashMap["rc_blink_sim:10:1"] = {rtwname: "<S2>/u"};
	this.rtwnameHashMap["<S2>/Compare"] = {sid: "rc_blink_sim:10:2"};
	this.sidHashMap["rc_blink_sim:10:2"] = {rtwname: "<S2>/Compare"};
	this.rtwnameHashMap["<S2>/Constant"] = {sid: "rc_blink_sim:10:3"};
	this.sidHashMap["rc_blink_sim:10:3"] = {rtwname: "<S2>/Constant"};
	this.rtwnameHashMap["<S2>/y"] = {sid: "rc_blink_sim:10:5"};
	this.sidHashMap["rc_blink_sim:10:5"] = {rtwname: "<S2>/y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
