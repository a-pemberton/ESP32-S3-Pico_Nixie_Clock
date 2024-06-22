//_____________________________________________________________________________________________
//
// Module:              IANA TCP/IP port number definitions
// Filename:            IANAports.h
// Version:             2.0
// Date:                01/SEP/2005
// Author:              A.Pemberton
// Function:            A 'C/C++' compatible list of IANA assigned TCP/IP port numbers and their names
// Change History:      20/JUL/2023 Revision of port assignments as per IANA (2023_06_29) which can be
//                      found at https://www.iana.org/assignments/service_names_port_numbers/service_names_port_numbers.xhtml
//
//_____________________________________________________________________________________________
/*
    Copyright (C) 2017 A.Pemberton

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
************************************************************************
* IANA /PORT NUMBERS
*
* IANA port numbers are divided into three ranges: the Well Known Ports,
* the Registered Ports, and the Dynamic and/or Private Ports.
*
* The Well Known Ports are those from 0 through 1023.
*
* The Registered Ports are those from 1024 through 49151
*
* The Dynamic and/or Private Ports are those from 49152 through 65535
*
************************************************************************
* PLEASE NOTE THE FOLLOWING:                                           *
*                                                                      *
* 1. UNASSIGNED PORT NUMBERS SHOULD NOT BE USED.  THE IANA WILL ASSIGN *
* THE NUMBER FOR THE PORT AFTER YOUR APPLICATION HAS BEEN APPROVED.    *
*                                                                      *
* 2. ASSIGNMENT OF A PORT NUMBER DOES NOT IN ANY WAY IMPLY AN          *
* ENDORSEMENT OF AN APPLICATION OR PRODUCT, AND THE FACT THAT NETWORK  *
* TRAFFIC IS FLOWING TO OR FROM A REGISTERED PORT DOES NOT MEAN THAT   *
* IT IS "GOOD" TRAFFIC. FIREWALL AND SYSTEM ADMINISTRATORS SHOULD      *
* CHOOSE HOW TO CONFIGURE THEIR SYSTEMS BASED ON THEIR KNOWLEDGE OF    *
* THE TRAFFIC IN QUESTION, NOT WHETHER THERE IS A PORT NUMBER          *
* REGISTERED OR NOT.                                                   *
************************************************************************
*
* Also note that:_
*
* 1, 'C/C++' port numbers here are protocol agnostic. Ports may be
*    TCP, UDP,SCTP, DCCP or possibly other.
*
* 2, Original comments have been left as far as possible but it has
*    to be said that these comments are cryptic, possibly due to
*    commercial needs of the requestor.
*
* 3, Where a common name has been assigned to multiple protocols, only
*    name has been retained to avoid compiler conflicts.
*
* 4, Where a different name for more than one protocol using the same
*    port, all the names have been retained.
*
* 5, Where IANA have reserved ports, the port numbers have been kept
*    but listed as comments.
*
* 6, Unassigned ports have been removed from this list.
*
* 7, IANA port names containing a '-' (minus) sign would cause
*    a compiler problem and have been replaced by an
*    underscore '_' sign.
*
* 8, Where IANA have assigned multiple ports with a common name, it
*    has been necessary to provide names with a numeric suffix for
*    each individual port number. The original name has been left
*    assigned to the first port and it is up to the user of this file
*    to decide how to handle the range.
*
* 9, Due to the size and complexity of the list, it is quite likely
*    that some errors have been made. Corrections welcome.
*
*/


#ifndef _IANAports_h_
#define _IANAports_h_

/*

WELL KNOWN PORT NUMBERS

The Well Known Ports are assigned by the IANA and on most systems can
only be used by system (or root) processes or by programs executed by
privileged users.

Ports are used in the TCP [RFC793] to name the ends of logical
connections which carry long term conversations.  For the purpose of
providing services to unknown callers, a service contact port is
defined.  This list specifies the port used by the server process as
its contact port.  The contact port is sometimes called the
"well_known port".

To the extent possible, these same port assignments are used with the
UDP [RFC768].
*/

//The range for assigned ports managed by the IANA is 0_1023.
//Port Assignments:
//Keyword							              Value		Description     References
//_______						          	    _____		___________     __________
//#define IANAport_				          0 			// tcp/udp,Reserved   
#define IANAport_tcpmux				      1			  // tcp/udp,TCP Port Service Multiplexer   
#define IANAport_compressnet2	      2			  // tcp/udp,Management Utility   
#define IANAport_compressnet3 	    3			  // tcp/udp,Compression Process   
#define IANAport_rje				        5			  // tcp/udp,Remote Job Entry   
#define IANAport_echo				        7			  // tcp/udp,Echo   
#define IANAport_discard			      9			  // tcp/udp/sctp/dccp,Discard ,[RFC4340],[RFC9260]
#define IANAport_systat 				    11			// tcp/udp,Active Users   
#define IANAport_daytime  			    13			// tcp/udp,Daytime,[RFC867]  ,
//#define IANAport_				  	      15			// tcp,Unassigned [was netstat]   
#define IANAport_qotd				        17			// tcp/udp,Quote of the Day   
#define IANAport_msp				        18			// tcp/udp,Message Send Protocol (historic)   
#define IANAport_chargen			      19			// tcp/udp,Character Generator   
#define IANAport_ftp_data			      20			// tcp/udp,File Transfer [Default Data]   
#define IANAport_ftp_data_sctp	    20			// sctp,FTP,[RFC9260]  ,
#define IANAport_ftp  				      21			// tcp/udp,File Transfer Protocol [Control],[RFC959]  ,
#define IANAport_ftp_sctp	  		    21			// sctp,FTP,[RFC9260]  ,
#define IANAport_ssh				        22			// tcp/udp,The Secure Shell (SSH) Protocol,[RFC4251]  ,
#define IANAport_ssh_sctp			      22			// sctp,SSH,[RFC9260]  ,
#define IANAport_telnet				      23			// tcp/udp,Telnet,[RFC854]  ,
//#define IANAport_					        24			// tcp/udp,any private mail system   
#define IANAport_smtp	  			      25			// tcp/udp,Simple Mail Transfer,[RFC5321]  ,
#define IANAport_nsw_fe	  			    27			// tcp/udp,NSW User System FE   
#define IANAport_msg_icp	  		    29 			// tcp/udp,MSG ICP   
#define IANAport_msg_auth		  	    31 			// tcp/udp,MSG Authentication   
#define IANAport_dsp				        33 			// tcp/udp,Display Support Protocol   
//#define IANAport_					        35 			// tcp/udp,any private printer server   
#define IANAport_time				        37 			// tcp/udp,Time   
#define IANAport_rap  				      38 			// tcp/udp,Route Access Protocol   
#define IANAport_rlp	  			      39 			// tcp/udp,Resource Location Protocol   
#define IANAport_graphics 			    41 			// tcp/udp,Graphics   
#define IANAport_name			  	      42 			// tcp/udp,Host Name Server   
#define IANAport_nameserver	  		  42 			// tcp/udp,Host Name Server   
#define IANAport_nicname			      43 			// tcp/udp,Who Is   
#define IANAport_mpm_flags			    44 			// tcp/udp,MPM FLAGS Protocol   
#define IANAport_mpm	  		        45   		// tcp/udp,Message Processing Module [recv]   
#define IANAport_mpm_snd  			    46   		// tcp/udp,MPM [default send]   
//#define IANAport_				  	      47 	  	// tcp/udp,Reserved   
#define IANAport_auditd			  	    48 		  // tcp/udp,Digital Audit Daemon   
#define IANAport_tacacs				      49 			// tcp/udp,Login Host Protocol (TACACS)   
#define IANAport_re_mail_ck			    50   		// tcp/udp,Remote Mail Checking Protocol   
//#define IANAport_				          51 	  	// ,Reserved   
#define IANAport_xns_time    			  52 		  // tcp/udp,XNS Time Protocol   
#define IANAport_domain 		  	    53 			// tcp/udp,Domain Name Server   
#define IANAport_xns_ch 		    	  54   		// tcp/udp,XNS Clearinghouse   
#define IANAport_isi_gl 			      55 	  	// tcp/udp,ISI Graphics Language   
#define IANAport_xns_auth 			    56 		  // tcp/udp,XNS Authentication   
//#define IANAport_			  	        57 			// tcp/udp,any private terminal access   
#define IANAport_xns_mail   			  58  		// tcp/udp,XNS Mail   
//#define IANAport_				          59	  	// tcp/udp,any private file service   
//#define IANAport_				          61		  // tcp/udp,Reserved   
#define IANAport_acas 				      62 			// tcp/udp,ACA Services   
#define IANAport_whoispp 			      63   		// tcp/udp,"whois++ IANA assigned this well_formed service name as a replacement for ""whois++""."   
//#define IANAport_whois++   			  63 	  	// tcp/udp,whois++ Not Allowed - use IANAport_whoispp instead
#define IANAport_covia 			  	    64 		  // tcp/udp,Communications Integrator (CI)   
#define IANAport_tacacs_ds 		  	  65 			// tcp/udp,TACACS_Database Service   
#define IANAport_sql_net 			      66   		// tcp/udp,"Oracle SQL*NET IANA assigned this well_formed service name as a replacement for ""sql*net""."   
//#define IANAport_sql*net   			  66 	  	// tcp/udp,Oracle SQL*NET Not Allowed - use IANAport_sql_net instead  
#define IANAport_bootps 		  	    67 		  // tcp/udp,Bootstrap Protocol Server,[RFC951]  ,
#define IANAport_bootpc 			      68 			// tcp/udp,Bootstrap Protocol Client   
#define IANAport_tftp 				      69   		// tcp/udp,Trivial File Transfer   
#define IANAport_gopher 			      70 	  	// tcp/udp,Gopher   
#define IANAport_netrjs_1   			  71 		  // tcp/udp,Remote Job Service   
#define IANAport_netrjs_2 	  		  72 			// tcp/udp,Remote Job Service   
#define IANAport_netrjs_3 		  	  73   		// tcp/udp,Remote Job Service   
#define IANAport_netrjs_4 			    74 	  	// tcp/udp,Remote Job Service   
//#define IANAport_				          75   		// tcp/udp,any private dial out service   
#define IANAport_deos   				    76 	  	// tcp/udp,Distributed External Object Store   
//#define IANAport_			  		      77 		  // tcp/udp,any private RJE service   
#define IANAport_vettcp 	  		    78 			// tcp/udp,vettcp   
#define IANAport_finger 		  	    79   		// tcp/udp,Finger   
#define IANAport_http 				      80 	  	// tcp/udp,World Wide Web HTTP,[RFC9110]  ,
#define IANAport_www 				        80 		  // tcp/udp,World Wide Web HTTP,[RFC9110]  ,
#define IANAport_www_http 			    80 			// tcp/udp,World Wide Web HTTP   
#define IANAport_http_sctp   			  80   		// sctp,HTTP,[RFC9260]  ,
#define IANAport_xfer 			  	    82 	  	// tcp/udp,XFER Utility   
#define IANAport_mit_ml_dev1 	  	  83 		  // tcp/udp,MIT ML Device   
#define IANAport_ctf 				        84 			// tcp/udp,Common Trace Facility   
#define IANAport_mit_ml_dev2 		    85   		// tcp/udp,MIT ML Device   
#define IANAport_mfcobol   			    86 	  	// tcp/udp,Micro Focus Cobol   
//#define IANAport_				          87 		  // tcp/udp,any private terminal link   
#define IANAport_kerberos 	  		  88 			// tcp/udp,Kerberos,[RFC4120]  ,
#define IANAport_su_mit_tg 		  	  89   		// tcp/udp,SU/MIT Telnet Gateway   
#define IANAport_dnsix 				      90 	  	// tcp/udp,DNSIX Securit Attribute Token Map   
#define IANAport_mit_dov 			      91 		  // tcp/udp,MIT Dover Spooler   
#define IANAport_npp   				      92 			// tcp/udp,Network Printing Protocol   
#define IANAport_dcp 	  			      93   		// tcp/udp,Device Control Protocol   
#define IANAport_objcall   			    94 	  	// tcp/udp,Tivoli Object Dispatcher   
#define IANAport_supdup 	  		    95 		  // tcp/udp,SUPDUP   
#define IANAport_dixie 			  	    96 			// tcp/udp,DIXIE Protocol Specification   
#define IANAport_swift_rvf 		  	  97   		// tcp/udp,Swift Remote Virtural File Protocol   
#define IANAport_tacnews 			      98 	  	// tcp/udp,TAC News   
#define IANAport_metagram 			    99 		  // tcp/udp,Metagram Relay   
#define IANAport_hostname   			  101			// tcp/udp,NIC Host Name Server   
#define IANAport_iso_tsap 	  		  102 		// tcp/udp,ISO_TSAP Class 0   
#define IANAport_gppitnp 			      103	  	// tcp/udp,Genesis Point_to_Point Trans Net   
#define IANAport_acr_nema 			    104		  // tcp/udp,ACR_NEMA Digital Imag. & Comm. 300   
#define IANAport_cso 				        105			// tcp/udp,CCSO name server protocol   
#define IANAport_csnet_ns    			  105 		// tcp/udp,Mailbox Name Nameserver   
#define IANAport_3com_tsmux   		  106	  	// tcp/udp,3COM_TSMUX   
#define IANAport_rtelnet 			      107		  // tcp/udp,Remote Telnet Service   
#define IANAport_snagas 			      108			// tcp/udp,SNA Gateway Access Server   
#define IANAport_pop2 				      109 		// tcp/udp,Post Office Protocol _ Version 2   
#define IANAport_pop3   				    110	  	// tcp/udp,Post Office Protocol _ Version 3   
#define IANAport_sunrpc   			    111		  // tcp/udp,SUN Remote Procedure Call   
#define IANAport_mcidas 	  		    112			// tcp/udp,McIDAS Data Transmission Protocol   
#define IANAport_ident 			  	    113 		// tcp   ,
#define IANAport_auth				        113   	// tcp/udp,Authentication Service   
#define IANAport_sftp 				      115 	  // tcp/udp,Simple File Transfer Protocol   
#define IANAport_ansanotify 		    116 		// tcp/udp,ANSA REX Notify   
#define IANAport_uucp_path   			  117  	  // tcp/udp,UUCP Path Service   
#define IANAport_sqlserv 		  	    118   	// tcp/udp,SQL Services   
#define IANAport_nntp 				      119 		// tcp/udp,Network News Transfer Protocol,[RFC3977]  ,
#define IANAport_cfdptkt 			      120    	// tcp/udp,CFDPTKT   
#define IANAport_erpc 				      121 	  // tcp/udp,Encore Expedited Remote Pro.Call   
#define IANAport_smakynet    			  122 		// tcp/udp,SMAKYNET   
#define IANAport_ntp 				        123    	// tcp/udp,Network Time Protocol,[RFC5905]  ,
#define IANAport_ansatrader 	  	  124 	  // tcp/udp,ANSA REX Trader   
#define IANAport_locus_map 			    125 		// tcp/udp,Locus PC_Interface Net Map Ser   
#define IANAport_nxedit 			      126    	// tcp/udp,NXEdit   
#define IANAport_locus_con   			  127 	  // tcp/udp,Locus PC_Interface Conn Server   
#define IANAport_gss_xlicen   		  128 		// tcp/udp,GSS X License Verification   
#define IANAport_pwdgen 			      129    	// tcp/udp,Password Generator Protocol   
#define IANAport_cisco_fna 			    130 	  // tcp/udp,cisco FNATIVE   
#define IANAport_cisco_tna 			    131 		// tcp/udp,cisco TNATIVE   
#define IANAport_cisco_sys   			  132    	// tcp/udp,cisco SYSMAINT   
#define IANAport_statsrv 		  	    133 	  // tcp/udp,Statistics Service   
#define IANAport_ingres_net 	  	  134 		// tcp/udp,INGRES_NET Service   
#define IANAport_epmap 				      135    	// tcp/udp,DCE endpoint resolution   
#define IANAport_profile 			      136 	  // tcp/udp,PROFILE Naming System   
#define IANAport_netbios_ns    		  137 		// tcp/udp,NETBIOS Name Service   
#define IANAport_netbios_dgm 	  	  138    	// tcp/udp,NETBIOS Datagram Service   
#define IANAport_netbios_ssn 		    139 	  // tcp/udp,NETBIOS Session Service   
#define IANAport_emfis_data 		    140 		// tcp/udp,EMFIS Data Service   
#define IANAport_emfis_cntl    		  141 		// tcp/udp,EMFIS Control Service   
#define IANAport_bl_idm 			      142 		// tcp/udp,Britton_Lee IDM   
#define IANAport_imap 				      143 		// tcp/udp,Internet Message Access Protocol,[RFC3501][RFC9051]  ,
//#define IANAport_				          143 		// udp,Reserved,[RFC9051]  ,
#define IANAport_uma  				      144 		// tcp/udp,Universal Management Architecture   
#define IANAport_uaac   				    145 		// tcp/udp,UAAC Protocol   
#define IANAport_iso_tp0   		  	  146 		// tcp/udp,ISO_IP0   
#define IANAport_iso_ip 	  		    147 		// tcp/udp,ISO_IP   
#define IANAport_jargon 		  	    148 		// tcp/udp,Jargon   
#define IANAport_aed_512 			      149 		// tcp/udp,AED 512 Emulation Service   
#define IANAport_sql_net_1 			    150 		// tcp/udp,SQL_NET - Modified to avoid conflict with line 176 
#define IANAport_hems 				      151 		// tcp/udp,HEMS   
#define IANAport_bftp    				    152 		// tcp/udp,Background File Transfer Program   
#define IANAport_sgmp 	  			    153 		// tcp/udp,SGMP   
#define IANAport_netsc_prod    		  154 		// tcp/udp,NETSC   
#define IANAport_netsc_dev 		  	  155 		// tcp/udp,NETSC   
#define IANAport_sqlsrv 			      156 		// tcp/udp,SQL Service   
#define IANAport_knet_cmp 			    157 		// tcp/udp,KNET/VM Command/Message Protocol   
#define IANAport_pcmail_srv   		  158 		// tcp/udp,PCMail Server   
#define IANAport_nss_routing 	  	  159 		// tcp/udp,NSS_Routing   
#define IANAport_sgmp_traps 		    160 		// tcp/udp,SGMP_TRAPS   
#define IANAport_snmp 				      161 		// tcp/udp,SNMP   
#define IANAport_snmptrap   			  162 		// tcp/udp,SNMPTRAP   
#define IANAport_cmip_man 	  		  163 		// tcp/udp,CMIP/TCP Manager   
#define IANAport_cmip_agent 	  	  164 		// tcp/udp,CMIP/TCP Agent   
#define IANAport_xns_courier 		    165 		// tcp/udp,Xerox   
#define IANAport_s_net 				      166 		// tcp/udp,Sirius Systems   
#define IANAport_namp   				    167 		// tcp/udp,NAMP   
#define IANAport_rsvd 	  			    168 		// tcp/udp,RSVD   
#define IANAport_send 		  		    169 		// tcp/udp,SEND   
#define IANAport_print_srv 	  		  170 		// tcp/udp,Network PostScript   
#define IANAport_multiplex 		  	  171 		// tcp/udp,Network Innovations Multiplex   
#define IANAport_cl_1 				      172 		// tcp/udp,"Network Innovations CL/1 IANA assigned this well_formed service name as a replacement for ""cl/1""."   
#define IANAport_cl_1 				      172 		// udp,"Network Innovations CL/1 IANA assigned this well_formed service name as a replacement for ""cl/1""."   
#define IANAport_xyplex_mux    		  173 		// tcp/udp,Xyplex   
#define IANAport_mailq 				      174 		// tcp/udp,MAILQ   
#define IANAport_vmnet 				      175 		// tcp/udp,VMNET   
#define IANAport_genrad_mux 		    176 		// tcp/udp,GENRAD_MUX   
#define IANAport_xdmcp  				    177 		// tcp/udp,X Display Manager Control Protocol   
#define IANAport_nextstep    			  178 		// tcp/udp,NextStep Window Server   
#define IANAport_bgp 				        179 		// tcp/udp,Border Gateway Protocol   
#define IANAport_bgp_sctp 		  	  179 		// sctp,BGP,[RFC9260]  ,
#define IANAport_ris 				        180 		// tcp/udp,Intergraph   
#define IANAport_unify 				      181 		// tcp/udp,Unify   
#define IANAport_audit  			  	  182 		// tcp/udp,Unisys Audit SITP   
#define IANAport_ocbinder    			  183 		// tcp/udp,OCBinder   
#define IANAport_ocserver   			  184 		// tcp/udp,OCServer   
#define IANAport_remote_kis   		  185 		// tcp/udp,Remote_KIS   
#define IANAport_kis 				        186 		// tcp/udp,KIS Protocol   
#define IANAport_aci 				        187 		// tcp/udp,Application Communication Interface   
#define IANAport_mumps 				      188 		// tcp/udp,Plus Five's MUMPS   
#define IANAport_qft 	  			      189 		// tcp/udp,Queued File Transport   
#define IANAport_gacp 	  			    190 		// tcp/udp,Gateway Access Control Protocol   
#define IANAport_prospero   			  191 		// tcp/udp,Prospero Directory Service   
#define IANAport_osu_nms 		  	    192 		// tcp/udp,OSU Network Monitoring System   
#define IANAport_srmp 				      193 		// tcp/udp,Spider Remote Monitoring Protocol   
#define IANAport_irc 				        194 		// tcp/udp,Internet Relay Chat Protocol   
#define IANAport_dn6_nlm_aud 		    195 		// tcp/udp,DNSIX Network Level Module Audit   
#define IANAport_dn6_smm_red  		  196 		// tcp/udp,DNSIX Session Mgt Module Audit Redir   
#define IANAport_dls 				        197 		// tcp/udp,Directory Location Service   
#define IANAport_dls_mon 			      198 		// tcp/udp,Directory Location Service Monitor   
#define IANAport_smux 				      199 		// tcp/udp,SMUX   
#define IANAport_src  				      200 		// tcp/udp,IBM System Resource Controller   
#define IANAport_at_rtmp   			    201 		// tcp/udp,AppleTalk Routing Maintenance   
#define IANAport_at_nbp 	  		    202 		// tcp/udp,AppleTalk Name Binding   
#define IANAport_at_3 			  	    203 		// tcp/udp,AppleTalk Unused   
#define IANAport_at_echo 			      204 		// tcp/udp,AppleTalk Echo   
#define IANAport_at_5 				      205 		// tcp/udp,AppleTalk Unused   
#define IANAport_at_zis 			      206 		// tcp/udp,AppleTalk Zone Information   
#define IANAport_at_7	  			      207 		// tcp/udp,AppleTalk Unused   
#define IANAport_at_8 	  			    208 		// tcp/udp,AppleTalk Unused   
#define IANAport_qmtp 		  	  	  209 		// tcp/udp,The Quick Mail Transfer Protocol   
#define IANAport_z39_50 		  	    210 		// tcp/udp,"ANSI Z39.50 IANA assigned this well_formed service name as a replacement for ""z39.50""."   
#define IANAport_Texas_914c_g   	  211 		// tcp/udp,"Texas Instruments 914C/G Terminal IANA assigned this well_formed service name as a replacement for ""914c/g""."   
#define IANAport_anet 				      212 		// tcp/udp,ATEXSSTR   
#define IANAport_ipx 			    	    213 		// tcp/udp,IPX   
#define IANAport_vmpwscs 	  		    214 		// tcp/udp,VM PWSCS   
#define IANAport_softpc 		  	    215 		// tcp/udp,Insignia Solutions   
#define IANAport_CAIlic 			      216 		// tcp/udp,Computer Associates Int'l License Server   
#define IANAport_dbase 				      217 		// tcp/udp,dBASE Unix   
#define IANAport_mpp 				        218 		// tcp/udp,Netix Message Posting Protocol   
#define IANAport_uarps  			  	  219 		// tcp/udp,Unisys ARPs   
#define IANAport_imap3 	  			    220 		// tcp/udp,Interactive Mail Access Protocol v3   
#define IANAport_fln_spx     			  221 		// tcp/udp,Berkeley rlogind with SPX auth   
#define IANAport_rsh_spx 	    		  222 		// tcp/udp,Berkeley rshd with SPX auth   
#define IANAport_cdc 				        223 		// tcp/udp,Certificate Distribution Center   
#define IANAport_masqdialer 		    224 		// tcp/udp,masqdialer   
//#define IANAport_			  	        225_241 	// ,Reserved   
#define IANAport_direct   	  		  242 		// tcp/udp,Direct   
#define IANAport_sur_meas   			  243 		// tcp/udp,Survey Measurement   
#define IANAport_inbusiness   		  244 		// tcp/udp,inbusiness   
#define IANAport_link 			    	  245 		// tcp/udp,LINK   
#define IANAport_dsp3270 			      246 		// tcp/udp,Display Systems Protocol   
#define IANAport_subntbcst_tftp	    247 		// tcp/udp,"SUBNTBCST_TFTP IANA assigned this well_formed service name as a replacement for ""subntbcst_tftp""."   
#define IANAport_bhfhs  	  			  248 		// tcp/udp,bhfhs   
//#define IANAport_			  	        249_255 	// ,Reserved   
#define IANAport_rap_rap	  	  	  256 		// tcp/udp,RAP - modified to avoid redefinition conflict with line 148
#define IANAport_set 				        257 		// tcp/udp,Secure Electronic Transaction   
#define IANAport_esro_gen 		  	  259 		// tcp/udp,Efficient Short Remote Operations   
#define IANAport_openport 			    260 		// tcp/udp,Openport   
#define IANAport_nsiiops 	  		    261 		// tcp/udp,IIOP Name Service over TLS/SSL   
#define IANAport_arcisdms   			  262 		// tcp/udp,Arcisdms   
#define IANAport_hdap 			    	  263 		// tcp/udp,HDAP   
#define IANAport_bgmp 				      264 		// tcp/udp,BGMP   
#define IANAport_x_bone_ctl 		    265 		// tcp/udp,X_Bone CTL   
#define IANAport_sst 			    	    266 		// tcp/udp,SCSI on ST   
#define IANAport_td_service   		  267 		// tcp/udp,Tobit David Service Layer   
#define IANAport_td_replica 	  	  268 		// tcp/udp,Tobit David Replica   
#define IANAport_manet 				      269 		// tcp/udp,MANET Protocols,[RFC5498]  ,
//#define IANAport_			  	        270 		// tcp/udp,Reserved   
#define IANAport_gist   		  		  270 		// udp,Q_mode encapsulation for GIST messages,[RFC5971]  ,
#define IANAport_pt_tls   		  	  271 		// tcp/udp,IETF Network Endpoint Assessment (NEA) Posture Transport Protocol over TLS (PT_TLS),[RFC6876]  ,
//#define IANAport_				          271 		// udp,Reserved   
#define IANAport_http_mgmt 	  		  280 		// tcp/udp,http_mgmt   
#define IANAport_personal_link   	  281 		// tcp/udp,Personal Link   
#define IANAport_cableport_ax 	    282 		// tcp/udp,Cable Port A/X   
#define IANAport_rescap    			    283 		// tcp/udp,rescap   
#define IANAport_corerjd  	  		  284 		// tcp/udp,corerjd   
#define IANAport_fxp_1 		      	  286 		// tcp/udp,FXP Communication   
#define IANAport_k_block 			      287 		// tcp/udp,K_BLOCK   
#define IANAport_novastorbakcup	    308 		// tcp/udp,Novastor Backup   
#define IANAport_entrusttime 		    309 		// tcp/udp,EntrustTime   
#define IANAport_bhmds 				      310 		// tcp/udp,bhmds   
#define IANAport_asip_webadmin 	    311 		// tcp/udp,AppleShare IP WebAdmin   
#define IANAport_vslmp 				      312 		// tcp/udp,VSLMP   
#define IANAport_magenta_logic 	    313 		// tcp/udp,Magenta Logic   
#define IANAport_opalis_robot 	    314 		// tcp/udp,Opalis Robot   
#define IANAport_dpsi   	  			  315 		// tcp/udp,DPSI   
#define IANAport_decauth   	  		  316 		// tcp/udp,decAuth   
#define IANAport_zannet 	  	  	  317 		// tcp/udp,Zannet   
#define IANAport_pkix_timestamp 	  318 		// tcp/udp,PKIX TimeStamp   
#define IANAport_ptp_event 			    319 		// tcp/udp,PTP Event   
#define IANAport_ptp_general 		    320 		// tcp/udp,PTP General   
#define IANAport_pip 	  			      321 		// tcp/udp,PIP   
#define IANAport_rtsps 	  			    322 		// tcp/udp,RTSPS   
#define IANAport_rpki_rtr   			  323 		// tcp,Resource PKI to Router Protocol,[RFC6810]  ,
//#define IANAport_				          323			// udp,Reserved   
#define IANAport_rpki_rtr_tls   	  324 		// tcp,Resource PKI to Router Protocol over TLS,[RFC6810]  ,
//#define IANAport_		  		        324 		// udp,Reserved   
#define IANAport_texar 	  			    333 		// tcp/udp,Texar Security Port   
#define IANAport_pdap   		  		  344			// tcp/udp,Prospero Data Access Protocol   
#define IANAport_pawserv   		  	  345 		// tcp/udp,Perf Analysis Workbench   
#define IANAport_zserv 		  		    346 		// tcp/udp,Zebra server   
#define IANAport_fatserv   	  		  347 		// tcp/udp,Fatmen Server   
#define IANAport_csi_sgwp 		  	  348			// tcp/udp,Cabletron Management Protocol   
#define IANAport_mftp 		  		    349 		// tcp/udp,mftp   
#define IANAport_matip_type_a 	    350 		// tcp/udp,MATIP Type A,[RFC2351]  ,
#define IANAport_matip_type_b    	  351 		// tcp/udp,MATIP Type B,[RFC2351]  ,
#define IANAport_bhoetty 			      351			// tcp/udp,bhoetty   
#define IANAport_dtag_ste_sb 		    352 		// tcp/udp,DTAG   
#define IANAport_bhoedap4   			  352 		// tcp/udp,bhoedap4   
#define IANAport_ndsauth 		  	    353 		// tcp/udp,NDSAUTH   
#define IANAport_bh611 				      354 		// tcp/udp,bh611   
#define IANAport_datex_asn 			    355 		// tcp/udp,DATEX_ASN   
#define IANAport_cloanto_net_1 	    356 		// tcp/udp,Cloanto Net 1   
#define IANAport_bhevent 	  		    357 		// tcp/udp,bhevent   
#define IANAport_shrinkwrap   		  358 		// tcp/udp,Shrinkwrap   
#define IANAport_nsrmp 				      359 		// tcp/udp,Network Security Risk Management Protocol   
#define IANAport_scoi2odialog 	    360 		// tcp/udp,scoi2odialog   
#define IANAport_semantix 			    361 		// tcp/udp,Semantix   
#define IANAport_srssend 	  		    362 		// tcp/udp,SRS Send   
#define IANAport_rsvp_tunnel   		  363 		// tcp/udp,"RSVP Tunnel IANA assigned this well_formed service name as a replacement for ""rsvp_tunnel""."   
#define IANAport_aurora_cmgr 	  	  364 		// tcp/udp,Aurora CMGR   
#define IANAport_dtk 				        365 		// tcp/udp,DTK   
#define IANAport_odmr 				      366 		// tcp/udp,ODMR   
#define IANAport_mortgageware    	  367 		// tcp/udp,MortgageWare   
#define IANAport_qbikgdp 			      368 		// tcp/udp,QbikGDP   
#define IANAport_rpc2portmap 		    369 		// tcp/udp,rpc2portmap   
#define IANAport_codaauth2  			  370 		// tcp/udp,codaauth2   
#define IANAport_clearcase 	  		  371 		// tcp/udp,Clearcase   
#define IANAport_ulistproc 		  	  372 		// tcp/udp,ListProcessor   
#define IANAport_legent_1			      373 		// tcp/udp,Legent Corporation   
#define IANAport_legent_2 			    374 		// tcp/udp,Legent Corporation   
#define IANAport_hassle   	  		  375 		// tcp/udp,Hassle   
#define IANAport_nip 			  	      376 		// tcp/udp,Amiga Envoy Network Inquiry Protocol   
#define IANAport_tnETOS 		  	    377 		// tcp/udp,NEC Corporation   
#define IANAport_dsETOS 			      378 		// tcp/udp,NEC Corporation   
#define IANAport_is99c 				      379 		// tcp/udp,TIA/EIA/IS_99 modem client   
#define IANAport_is99s 				      380 		// tcp/udp,TIA/EIA/IS_99 modem server   
#define IANAport_hp_collector 	    381 		// tcp/udp,hp performance data collector   
#define IANAport_hp_managed_node    382 		// tcp/udp,hp performance data managed node   
#define IANAport_hp_alarm_mgr    		383 		// tcp/udp,hp performance data alarm manager   
#define IANAport_arns 				      384 		// tcp/udp,A Remote Network Server System   
#define IANAport_ibm_app 			      385 		// tcp/udp,IBM Application   
#define IANAport_asa 	  			      386 		// tcp/udp,ASA Message Router Object Def.   
#define IANAport_aurp 	  			    387 		// tcp/udp,Appletalk Update_Based Routing Pro.   
#define IANAport_unidata_ldm   		  388 		// tcp/udp,Unidata LDM   
#define IANAport_ldap 				      389 		// tcp/udp,Lightweight Directory Access Protocol   
#define IANAport_uis 				        390 		// tcp/udp,UIS   
#define IANAport_synotics_relay 	  391 		// tcp/udp,SynOptics SNMP Relay Port   
#define IANAport_synotics_broker   	392 		// tcp/udp,SynOptics Port Broker Port   
#define IANAport_meta5 	  			    393 		// tcp/udp,Meta5   
#define IANAport_embl_ndt   			  394 		// tcp/udp,EMBL Nucleic Data Transfer   
#define IANAport_netcp 			  	    395 		// tcp/udp,NetScout Control Protocol   
#define IANAport_netware_ip 	  	  396 		// tcp/udp,Novell Netware over IP   
#define IANAport_mptn 				      397 		// tcp/udp,Multi Protocol Trans. Net.   
#define IANAport_kryptolan 			    398 		// tcp/udp,Kryptolan   
#define IANAport_iso_tsap_c2  		  399 		// tcp/udp,ISO Transport Class 2 Non_Control over TCP   
#define IANAport_osb_sd 			      400 		// tcp/udp,Oracle Secure Backup   
#define IANAport_ups 				        401 		// tcp/udp,Uninterruptible Power Supply   
#define IANAport_genie 				      402 		// tcp/udp,Genie Protocol   
#define IANAport_decap  				    403 		// tcp/udp,decap   
#define IANAport_nced 	  			    404 		// tcp/udp,nced   
#define IANAport_ncld 		  		    405 		// tcp/udp,ncld   
#define IANAport_imsp 			  	    406 		// tcp/udp,Interactive Mail Support Protocol   
#define IANAport_timbuktu 		  	  407 		// tcp/udp,Timbuktu   
#define IANAport_prm_sm 			      408 		// tcp/udp,Prospero Resource Manager Sys. Man.   
#define IANAport_prm_nm 			      409 		// tcp/udp,Prospero Resource Manager Node Man.   
#define IANAport_decladebug   		  410 		// tcp/udp,DECLadebug Remote Debug Protocol   
#define IANAport_rmt 				        411 		// tcp/udp,Remote MT Protocol   
#define IANAport_synoptics_trap 	  412 		// tcp/udp,Trap Convention Port   
#define IANAport_smsp   				    413 		// tcp/udp,Storage Management Services Protocol   
#define IANAport_infoseek    			  414 		// tcp/udp,InfoSeek   
#define IANAport_bnet 			  	    415 		// tcp/udp,BNet   
#define IANAport_silverplatter   		416 		// tcp/udp,Silverplatter   
#define IANAport_onmux 				      417 		// tcp/udp,Onmux   
#define IANAport_hyper_g 			      418 		// tcp/udp,Hyper_G   
#define IANAport_ariel1   			    419 		// tcp/udp,Ariel 1   
#define IANAport_smpte 		  		    420 		// tcp/udp,SMPTE   
#define IANAport_ariel2 		  	    421 		// tcp/udp,Ariel 2   
#define IANAport_ariel3 			      422 		// tcp/udp,Ariel 3   
#define IANAport_opc_job_start 	  	423 		// tcp/udp,IBM Operations Planning and Control Start   
#define IANAport_opc_job_track 		  424 		// tcp/udp,IBM Operations Planning and Control Track   
#define IANAport_icad_el  			    425 		// tcp/udp,ICAD   
#define IANAport_smartsdp   			  426 		// tcp/udp,smartsdp   
#define IANAport_svrloc 		  	    427 		// tcp/udp,Server Location   
#define IANAport_ocs_cmu 			      428 		// tcp/udp,"OCS_CMU IANA assigned this well_formed service name as a replacement for ""ocs_cmu""."   
#define IANAport_ocs_amu 			      429 		// tcp/udp,"OCS_AMU IANA assigned this well_formed service name as a replacement for ""ocs_amu""."   
#define IANAport_utmpsd 			      430 		// tcp/udp,UTMPSD   
#define IANAport_utmpcd   			    431 		// tcp/udp,UTMPCD   
#define IANAport_iasd 		  		    432 		// tcp/udp,IASD   
#define IANAport_nnsp 			  	    433 		// tcp/udp,NNTP for transit servers (NNSP),[RFC3977]  ,
#define IANAport_mobileip_agent    	434 		// tcp/udp,MobileIP_Agent   
#define IANAport_mobilip_mn 		    435 		// tcp/udp,MobilIP_MN   
#define IANAport_dna_cml 	  		    436 		// tcp/udp,DNA_CML   
#define IANAport_comscm 		  	    437 		// tcp/udp,comscm   
#define IANAport_dsfgw 				      438 		// tcp/udp,dsfgw   
#define IANAport_dasp 				      439 		// tcp/udp,dasp   
#define IANAport_sgcp 				      440 		// tcp/udp,sgcp   
#define IANAport_decvms_sysmgt 		  441 		// tcp/udp,decvms_sysmgt   
#define IANAport_cvc_hostd 	  		  442 		// tcp/udp,"cvc_hostd IANA assigned this well_formed service name as a replacement for ""cvc_hostd""."   
#define IANAport_https 		  		    443 		// tcp/udp,http protocol over TLS/SSL,[RFC9110],sctp,HTTPS,[RFC9260]
#define IANAport_snpp 			  	    444 		// tcp/udp,Simple Network Paging Protocol,[RFC1568]  ,
#define IANAport_microsoft_ds   		445 		// tcp/udp,Microsoft_DS   
#define IANAport_ddm_rdb  			    446 		// tcp/udp,DDM_Remote Relational Database Access   
#define IANAport_ddm_dfm 	  		    447 		// tcp/udp,DDM_Distributed File Management   
#define IANAport_ddm_ssl 		  	    448 		// tcp/udp,DDM_Remote DB Access Using Secure Sockets   
#define IANAport_as_servermap   		449 		// tcp/udp,AS Server Mapper   
#define IANAport_tserver 			      450 		// tcp/udp,Computer Supported Telecomunication Applications   
#define IANAport_sfs_smp_net 		    451 		// tcp/udp,Cray Network Semaphore server   
#define IANAport_sfs_config 		    452 		// tcp/udp,Cray SFS config server   
#define IANAport_creativeserver_1   453 		// tcp/udp,CreativeServer - Note amended 
#define IANAport_contentserver_1	  454 		// tcp/udp,ContentServer  - Note amended
#define IANAport_creativepartnr_1   455 		// tcp/udp,CreativePartnr - Note amended
#define IANAport_macon_tcp 			    456 		// tcp/udp,macon_tcp   
#define IANAport_scohelp  			    457 		// tcp/udp,scohelp   
#define IANAport_appleqtc   			  458 		// tcp/udp,apple quick time   
#define IANAport_ampr_rcmd 	  		  459 		// tcp/udp,ampr_rcmd   
#define IANAport_skronk 			      460 		// tcp/udp,skronk   
#define IANAport_datasurfsrv 		    461 		// tcp/udp,DataRampSrv   
#define IANAport_datasurfsrvsec 	  462 		// tcp/udp,DataRampSrvSec   
#define IANAport_alpes  				    463 		// tcp/udp,alpes   
#define IANAport_kpasswd   			    464 		// tcp/udp,kpasswd   
#define IANAport_urd 			  	      465 		// tcp/udp,URL Rendezvous Directory for SSM   
#define IANAport_submissions   	  	465 		// tcp/udp,Message Submission over TLS protocol,[RFC8314]  ,
#define IANAport_igmpv3lite 	  	  465 		// udp,IGMP over UDP for SSM   
#define IANAport_digital_vrc 		    466 		// tcp/udp,digital_vrc   
#define IANAport_mylex_mapd 		    467 		// tcp/udp,mylex_mapd   
#define IANAport_photuris   			  468 		// tcp/udp,proturis   
#define IANAport_rcp 				        469 		// tcp/udp,Radio Control Protocol   
#define IANAport_scx_proxy 		  	  470 		// tcp/udp,scx_proxy   
#define IANAport_mondex 			      471 		// tcp/udp,Mondex   
#define IANAport_ljk_login 			    472 		// tcp/udp,ljk_login   
#define IANAport_hybrid_pop   		  473 		// tcp/udp,hybrid_pop   
#define IANAport_tn_tl_w1 		  	  474 		// tcp/udp,tn_tl_w1   
#define IANAport_tcpnethaspsrv 	  	475 		// tcp/udp,tcpnethaspsrv   
#define IANAport_tn_tl_fd1 			    476 		// tcp/udp,tn_tl_fd1   
#define IANAport_ss7ns  				    477 		// tcp/udp,ss7ns   
#define IANAport_spsc 	  			    478 		// tcp/udp,spsc   
#define IANAport_iafserver   			  479 		// tcp/udp,iafserver   
#define IANAport_iafdbase 	  		  480 		// tcp/udp,iafdbase   
#define IANAport_ph 			        	481 		// tcp/udp,Ph service   
#define IANAport_bgs_nsi 			      482 		// tcp/udp,bgs_nsi   
#define IANAport_ulpnet 			      483 		// tcp/udp,ulpnet   
#define IANAport_integra_sme  		  484 		// tcp/udp,Integra Software Management Environment   
#define IANAport_powerburst 	  	  485 		// tcp/udp,Air Soft Power Burst   
#define IANAport_avian 			      	486 		// tcp/udp,avian   
#define IANAport_saft 				      487 		// tcp/udp,saft Simple Asynchronous File Transfer   
#define IANAport_gss_http 			    488 		// tcp/udp,gss_http   
#define IANAport_nest_protocol 		  489 		// tcp/udp,nest_protocol   
#define IANAport_micom_pfs  			  490 		// tcp/udp,micom_pfs   
#define IANAport_go_login 	  		  491 		// tcp/udp,go_login   
#define IANAport_ticf_1 			      492 		// tcp/udp,Transport Independent Convergence for FNA   
#define IANAport_ticf_2 			      493 		// tcp/udp,Transport Independent Convergence for FNA   
#define IANAport_pov_ray 			      494 		// tcp/udp,POV_Ray   
#define IANAport_intecourier  		  495 		// tcp/udp,intecourier   
#define IANAport_pim_rp_disc 	  	  496 		// tcp/udp,PIM_RP_DISC   
#define IANAport_retrospect 		    497 		// tcp/udp,Retrospect backup and restore service   
#define IANAport_siam 				      498 		// tcp/udp,siam   
#define IANAport_iso_ill  			    499 		// tcp/udp,ISO ILL Protocol   
#define IANAport_isakmp 	  		    500 		// tcp/udp,isakmp   
#define IANAport_stmf 			  	    501 		// tcp/udp,STMF   
#define IANAport_mbap 				      502 		// tcp/udp,Modbus Application Protocol   
#define IANAport_intrinsa 			    503 		// tcp/udp,Intrinsa   
#define IANAport_citadel 			      504 		// tcp/udp,citadel   
#define IANAport_mailbox_lm   		  505 		// tcp/udp,mailbox_lm   
#define IANAport_ohimsrv 			      506 		// tcp/udp,ohimsrv   
#define IANAport_crs 				        507 		// tcp/udp,crs   
#define IANAport_xvttp 				      508 		// tcp/udp,xvttp   
#define IANAport_snare 	  			    509 		// tcp/udp,snare   
#define IANAport_fcp 			  	      510 		// tcp/udp,FirstClass Protocol   
#define IANAport_passgo 		  	    511 		// tcp/udp,PassGo   
#define IANAport_exec 				      512 		// tcp,remote process execution   
#define IANAport_comsat             512 		// udp   ,
#define IANAport_biff               512 		// udp,used by mail system to notify users of new mail received   
#define IANAport_login              513 		// tcp,"remote login a la telnet; automatic authentication performed based on priviledged port numbers and distributed data bases which identify ""authentication domains"""   
#define IANAport_who                513 		// udp,maintains data bases showing who's logged in to machines on a local net and the load average of the machine   
#define IANAport_shell              514 		// tcp,"cmd like exec, but automatic authentication is performed as for login server"   
#define IANAport_syslog             514 		// udp [RFC5426]  ,
#define IANAport_printer            515 		// tcp,spooler   
#define IANAport_videotex           516 		// tcp,videotex   
#define IANAport_talk               517 		// tcp,"like tenex link, but across machine _ unfortunately, doesn't use link protocol (this is actually just a rendezvous port from which a tcp connection is established)"   
#define IANAport_ntalk              518 		// tcp   ,
#define IANAport_utime              519 		// tcp,unixtime   
#define IANAport_efs                520 		// tcp,extended file name server   
#define IANAport_router             520 		// udp,local routing process (on site)   
#define IANAport_ripng              521 		// tcp,ripng   
#define IANAport_ulp                522 		// tcp,ULP   
#define IANAport_ibm_db2            523 		// tcp,IBM_DB2   
#define IANAport_ncp                524 		// tcp,NCP   
#define IANAport_timed              525 		// tcp,timeserver   
#define IANAport_tempo              526 		// tcp,newdate   
#define IANAport_stx                527 		// tcp,Stock IXChange   
#define IANAport_custix             528 		// tcp,Customer IXChange   
#define IANAport_irc_serv           529 		// tcp,IRC_SERV   
#define IANAport_courier            530 		// tcp,rpc   
#define IANAport_conference         531 		// tcp,chat   
#define IANAport_netnews            532 		// tcp,readnews   
#define IANAport_netwall            533 		// tcp,for emergency broadcasts   
#define IANAport_windream           534 		// tcp,windream Admin   
#define IANAport_iiop               535 		// tcp,iiop   
#define IANAport_opalis_rdv         536 		// tcp,opalis_rdv   
#define IANAport_nmsp               537 		// tcp,Networked Media Streaming Protocol   
#define IANAport_gdomap             538 		// tcp,gdomap   
#define IANAport_apertus_ldp        539 		// tcp,Apertus Technologies Load Determination   
#define IANAport_uucp               540 		// tcp,uucpd   
#define IANAport_uucp_rlogin        541 		// tcp,uucp_rlogin   
#define IANAport_commerce           542 		// tcp,commerce   
#define IANAport_klogin             543 		// tcp   ,
#define IANAport_kshell             544 		// tcp,krcmd   
#define IANAport_appleqtcsrvr       545 		// tcp,appleqtcsrvr   
#define IANAport_dhcpv6_client      546 		// tcp,DHCPv6 Client   
#define IANAport_dhcpv6_server      547 		// tcp,DHCPv6 Server,[RFC5460]  ,
#define IANAport_afpovertcp         548 		// tcp,AFP over TCP   
#define IANAport_idfp               549 		// tcp,IDFP   
#define IANAport_new_rwho           550 		// tcp,new_who,[n/a]  ,
#define IANAport_cybercash          551 		// tcp,cybercash,[RFC1898]  ,
#define IANAport_devshr_nts         552 		// tcp,DeviceShare   
#define IANAport_pirp               553 		// tcp,pirp   
#define IANAport_rtsp               554 		// tcp,Real Time Streaming Protocol (RTSP)   
#define IANAport_dsf                555 		// tcp   ,
#define IANAport_remotefs           556 		// tcp,rfs server   
#define IANAport_openvms_sysipc     557 		// tcp,openvms_sysipc   
#define IANAport_sdnskmp            558 		// tcp,SDNSKMP   
#define IANAport_teedtap            559 		// tcp,TEEDTAP   
#define IANAport_rmonitor           560 		// tcp,rmonitord   
#define IANAport_monitor            561 		// tcp   ,
#define IANAport_chshell            562 		// tcp,chcmd   
#define IANAport_nntps              563 		// tcp,nntp protocol over TLS/SSL (was snntp),[RFC4642]  ,
#define IANAport_9pfs               564 		// tcp,plan 9 file service   
#define IANAport_whoami             565 		// tcp,whoami   
#define IANAport_streettalk         566 		// tcp,streettalk   
#define IANAport_banyan_rpc         567 		// tcp,banyan_rpc   
#define IANAport_ms_shuttle         568 		// tcp,microsoft shuttle   
#define IANAport_ms_rome            569 		// tcp,microsoft rome   
#define IANAport_meter              570 		// tcp,demon   
#define IANAport_meter_udemon       571 		// tcp,udemon   
#define IANAport_sonar              572 		// tcp,sonar   
#define IANAport_banyan_vip         573 		// tcp,banyan_vip   
#define IANAport_ftp_agent          574 		// tcp,FTP Software Agent System   
#define IANAport_vemmi              575 		// tcp,VEMMI   
#define IANAport_ipcd               576 		// tcp,ipcd   
#define IANAport_vnas               577 		// tcp,vnas   
#define IANAport_ipdd               578 		// tcp,ipdd   
#define IANAport_decbsrv            579 		// tcp,decbsrv   
#define IANAport_sntp_heartbeat     580 		// tcp,SNTP HEARTBEAT   
#define IANAport_bdp                581 		// tcp,Bundle Discovery Protocol   
#define IANAport_scc_security       582 		// tcp,SCC Security   
#define IANAport_philips_vc         583 		// tcp,Philips Video_Conferencing   
#define IANAport_keyserver          584 		// tcp,Key Server   
//#define IANAport_                 585 		// ,De_registered   
#define IANAport_password_chg       586 		// tcp,Password Change   
#define IANAport_submission         587 		// tcp,Message Submission,[RFC6409]  ,
#define IANAport_cal                588 		// tcp,CAL   
#define IANAport_eyelink            589 		// tcp,EyeLink   
#define IANAport_tns_cml            590 		// tcp,TNS CML   
#define IANAport_http_alt_1         591 		// tcp,"FileMaker, Inc. _ HTTP Alternate (see Port 80)" - Note amended
#define IANAport_eudora_set         592 		// tcp,Eudora Set   
#define IANAport_http_rpc_epmap     593 		// tcp,HTTP RPC Ep Map   
#define IANAport_tpip               594 		// tcp,TPIP   
#define IANAport_cab_protocol       595 		// tcp,CAB Protocol   
#define IANAport_smsd               596 		// tcp,SMSD   
#define IANAport_ptcnameservice     597 		// tcp,PTC Name Service   
#define IANAport_sco_websrvrmg3     598 		// tcp,SCO Web Server Manager 3   
#define IANAport_acp                599 		// tcp,Aeolon Core Protocol   
#define IANAport_ipcserver          600 		// tcp,Sun IPC server   
#define IANAport_syslog_conn        601 		// tcp,Reliable Syslog Service,[RFC3195]  ,
#define IANAport_xmlrpc_beep        602 		// tcp,XML_RPC over BEEP,[RFC3529]  ,
#define IANAport_idxp               603 		// tcp,IDXP,[RFC4767]  ,
#define IANAport_tunnel             604 		// tcp,TUNNEL,[RFC3620]  ,
#define IANAport_soap_beep          605 		// tcp,SOAP over BEEP,[RFC4227]  ,
#define IANAport_urm                606 		// tcp,Cray Unified Resource Manager   
#define IANAport_nqs                607 		// tcp,nqs   
#define IANAport_sift_uft           608 		// tcp,Sender_Initiated/Unsolicited File Transfer   
#define IANAport_npmp_trap          609 		// tcp,npmp_trap   
#define IANAport_npmp_local         610 		// tcp,npmp_local   
#define IANAport_npmp_gui           611 		// tcp,npmp_gui   
#define IANAport_hmmp_ind           612 		// tcp,HMMP Indication   
#define IANAport_hmmp_op            613 		// tcp,HMMP Operation   
#define IANAport_sshell             614 		// tcp,SSLshell   
#define IANAport_sco_inetmgr        615 		// tcp,Internet Configuration Manager   
#define IANAport_sco_sysmgr         616 		// tcp,SCO System Administration Server   
#define IANAport_sco_dtmgr          617 		// tcp,SCO Desktop Administration Server   
#define IANAport_dei_icda           618 		// tcp,DEI_ICDA   
#define IANAport_compaq_evm         619 		// tcp,Compaq EVM   
#define IANAport_sco_websrvrmgr     620 		// tcp,SCO WebServer Manager   
#define IANAport_escp_ip            621 		// tcp,ESCP   
#define IANAport_collaborator       622 		// tcp,Collaborator   
#define IANAport_oob_ws_http        623 		// tcp,DMTF out_of_band web services management protocol   
#define IANAport_asf_rmcp           623 		// udp,ASF Remote Management and Control Protocol   
#define IANAport_cryptoadmin        624 		// tcp,Crypto Admin   
#define IANAport_dec_dlm            625 		// tcp,"DEC DLM IANA assigned this well_formed service name as a replacement for ""dec_dlm""."   
#define IANAport_asia               626 		// tcp,ASIA   
#define IANAport_passgo_tivoli      627 		// tcp,PassGo Tivoli   
#define IANAport_qmqp               628 		// tcp,QMQP   
#define IANAport_3com_amp3          629 		// tcp,3Com AMP3   
#define IANAport_rda                630 		// tcp,RDA   
#define IANAport_ipp                631 		// tcp,IPP (Internet Printing Protocol),[RFC8011]  ,
#define IANAport_ipps               631 		// tcp,Internet Printing Protocol over HTTPS,[RFC8011]  ,
#define IANAport_bmpp               632 		// udp,bmpp   
#define IANAport_servstat           633 		// tcp,Service Status update (Sterling Software)   
#define IANAport_ginad              634 		// tcp,ginad   
#define IANAport_rlzdbase           635 		// tcp,RLZ DBase   
#define IANAport_ldaps              636 		// tcp,ldap protocol over TLS/SSL (was sldap)   
#define IANAport_lanserver          637 		// tcp,lanserver   
#define IANAport_mcns_sec           638 		// tcp,mcns_sec   
#define IANAport_msdp               639 		// tcp,MSDP   
#define IANAport_entrust_sps        640 		// tcp,entrust_sps   
#define IANAport_repcmd             641 		// tcp,repcmd   
#define IANAport_esro_emsdp         642 		// tcp,ESRO_EMSDP V1.3   
#define IANAport_sanity             643 		// tcp,SANity   
#define IANAport_dwr                644 		// tcp,dwr   
#define IANAport_pssc               645 		// tcp,PSSC   
#define IANAport_ldp                646 		// tcp,LDP   
#define IANAport_dhcp_failover      647 		// tcp,DHCP Failover,[RFC8156]  ,
#define IANAport_rrp                648 		// tcp,Registry Registrar Protocol (RRP)   
#define IANAport_cadview_3d         649 		// tcp,Cadview_3d _ streaming 3d models over the internet   
#define IANAport_obex               650 		// tcp,OBEX   
#define IANAport_ieee_mms           651 		// tcp,IEEE MMS   
#define IANAport_hello_port         652 		// tcp,HELLO_PORT   
#define IANAport_repscmd            653 		// tcp,RepCmd   
#define IANAport_aodv               654 		// tcp,AODV   
#define IANAport_tinc               655 		// tcp,TINC   
#define IANAport_spmp               656 		// tcp,SPMP   
#define IANAport_rmc                657 		// tcp,RMC   
#define IANAport_tenfold            658 		// tcp,TenFold   
//#define IANAport_                 659 		// ,Removed   
#define IANAport_mac_srvr_admin     660 		// tcp,MacOS Server Admin   
#define IANAport_hap                661 		// tcp,HAP   
#define IANAport_pftp               662 		// tcp,PFTP   
#define IANAport_purenoise          663 		// tcp,PureNoise   
#define IANAport_oob_ws_https       664 		// tcp,DMTF out_of_band secure web services management protocol   
#define IANAport_asf_secure_rmcp    664 		// udp,ASF Secure Remote Management and Control Protocol   
#define IANAport_sun_dr             665 		// tcp,Sun DR   
#define IANAport_doom               666 		// tcp,doom Id Software   
#define IANAport_disclose           667 		// tcp,campaign contribution disclosures _ SDR Technologies   
#define IANAport_mecomm             668 		// tcp,MeComm   
#define IANAport_meregister         669 		// tcp,MeRegister   
#define IANAport_vacdsm_sws         670 		// tcp,VACDSM_SWS   
#define IANAport_vacdsm_app         671 		// tcp,VACDSM_APP   
#define IANAport_vpps_qua           672 		// tcp,VPPS_QUA   
#define IANAport_cimplex            673 		// tcp,CIMPLEX   
#define IANAport_acap               674 		// tcp,ACAP   
#define IANAport_dctp               675 		// tcp,DCTP   
#define IANAport_vpps_via           676 		// tcp,VPPS Via   
#define IANAport_vpp                677 		// tcp,Virtual Presence Protocol   
#define IANAport_ggf_ncp            678 		// tcp,GNU Generation Foundation NCP   
#define IANAport_mrm                679 		// tcp,MRM   
#define IANAport_entrust_aaas       680 		// tcp,entrust_aaas   
#define IANAport_entrust_aams       681 		// tcp,entrust_aams   
#define IANAport_xfr                682 		// tcp,XFR   
#define IANAport_corba_iiop         683 		// tcp,CORBA IIOP   
#define IANAport_corba_iiop_ssl     684 		// tcp,CORBA IIOP SSL   
#define IANAport_mdc_portmapper     685 		// tcp,MDC Port Mapper   
#define IANAport_hcp_wismar         686 		// tcp,Hardware Control Protocol Wismar   
#define IANAport_asipregistry       687 		// tcp,asipregistry   
#define IANAport_realm_rusd         688 		// tcp,ApplianceWare managment protocol   
#define IANAport_nmap               689 		// tcp,NMAP   
#define IANAport_vatp               690 		// tcp,Velneo Application Transfer Protocol   
#define IANAport_msexch_routing     691 		// tcp,MS Exchange Routing   
#define IANAport_hyperwave_isp      692 		// tcp,Hyperwave_ISP   
#define IANAport_connendp           693 		// tcp,almanid Connection Endpoint   
#define IANAport_ha_cluster         694 		// tcp,ha_cluster   
#define IANAport_ieee_mms_ssl       695 		// tcp,IEEE_MMS_SSL   
#define IANAport_rushd              696 		// tcp,RUSHD   
#define IANAport_uuidgen            697 		// udp,UUIDGEN   
#define IANAport_olsr               698 		// tcp,OLSR   
#define IANAport_accessnetwork      699 		// tcp,Access Network   
#define IANAport_epp                700 		// tcp,Extensible Provisioning Protocol,[RFC5734]  ,
#define IANAport_lmp                701 		// tcp,Link Management Protocol (LMP),[RFC4204]  ,
#define IANAport_iris_beep          702 		// tcp,IRIS over BEEP,[RFC3983]  ,
#define IANAport_elcsd              704 		// tcp,errlog copy/server daemon   
#define IANAport_agentx             705 		// tcp,AgentX   
#define IANAport_silc               706 		// tcp,SILC   
#define IANAport_borland_dsj        707 		// tcp,Borland DSJ   
#define IANAport_entrust_kmsh       709 		// tcp,Entrust Key Management Service Handler   
#define IANAport_entrust_ash        710 		// tcp,Entrust Administration Service Handler   
#define IANAport_cisco_tdp          711 		// tcp,Cisco TDP   
#define IANAport_tbrpf              712 		// tcp,TBRPF,[RFC3684]  ,
#define IANAport_iris_xpc           713 		// tcp,IRIS over XPC   
#define IANAport_iris_xpcs          714 		// tcp,IRIS over XPCS,[RFC4992]  ,
#define IANAport_iris_lwz           715 		// tcp,IRIS_LWZ,[RFC4993]  ,
#define IANAport_pana               716 		// udp,PANA Messages,[RFC5191]  ,
#define IANAport_netviewdm1         729 		// tcp,IBM NetView DM/6000 Server/Client   
#define IANAport_netviewdm2         730 		// tcp,IBM NetView DM/6000 send/tcp   
#define IANAport_netviewdm3         731 		// tcp,IBM NetView DM/6000 receive/tcp   
#define IANAport_netgw              741 		// tcp,netGW   
#define IANAport_netrcs             742 		// tcp,Network based Rev. Cont. Sys.   
#define IANAport_flexlm             744 		// tcp,Flexible License Manager   
#define IANAport_fujitsu_dev        747 		// tcp,Fujitsu Device Control   
#define IANAport_ris_cm             748 		// tcp,Russell Info Sci Calendar Manager   
#define IANAport_kerberos_adm       749 		// tcp,kerberos administration   
#define IANAport_rfile              750 		// tcp   ,
#define IANAport_loadav             750 		// udp   ,
#define IANAport_kerberos_iv        750 		// udp,kerberos version iv   
#define IANAport_pump               751 		// tcp   ,
#define IANAport_qrh                752 		// tcp   ,
#define IANAport_rrh                753 		// tcp   ,
#define IANAport_tell               754 		// tcp,send   
#define IANAport_nlogin             758 		// tcp   ,
#define IANAport_con                759 		// tcp   ,
#define IANAport_ns                 760 		// tcp   ,
#define IANAport_rxe                761 		// tcp   ,
#define IANAport_quotad             762 		// tcp   ,
#define IANAport_cycleserv          763 		// tcp   ,
#define IANAport_omserv             764 		// tcp   ,
#define IANAport_webster            765 		// tcp   ,
#define IANAport_phonebook          767 		// tcp,phone   
#define IANAport_vid                769 		// tcp   ,
#define IANAport_cadlock            770 		// tcp   ,
#define IANAport_rtip               771 		// tcp   ,
#define IANAport_cycleserv2         772 		// tcp   ,
#define IANAport_submit             773 		// tcp   ,
#define IANAport_rpasswd            774 		// tcp   ,
#define IANAport_acmaint_dbd        774 		// udp,"IANA assigned this well_formed service name as a replacement for ""acmaint_dbd""."   
#define IANAport_entomb             775 		// tcp   ,
#define IANAport_acmaint_transd     775 		// udp,"IANA assigned this well_formed service name as a replacement for ""acmaint_transd""."   
#define IANAport_wpages             776 		// tcp   ,
#define IANAport_multiling_http     777 		// tcp,Multiling HTTP   
#define IANAport_wpgs               780 		// tcp   ,
#define IANAport_mdbs_daemon        800 		// tcp,"IANA assigned this well_formed service name as a replacement for ""mdbs_daemon""."   
#define IANAport_device             801 		// tcp   ,
#define IANAport_mbap_s             802 		// tcp,Modbus Application Protocol Secure   
#define IANAport_fcp_udp            810 		// tcp,FCP   
#define IANAport_itm_mcell_s        828 		// tcp,itm_mcell_s   
#define IANAport_pkix_3_ca_ra       829 		// tcp,PKIX_3 CA/RA   
#define IANAport_netconf_ssh        830 		// tcp,NETCONF over SSH,[RFC6242]  ,
#define IANAport_netconf_beep       831 		// tcp,NETCONF over BEEP,[RFC4744]  ,
#define IANAport_netconfsoaphttp    832 		// tcp,NETCONF for SOAP over HTTPS,[RFC4743]  ,
#define IANAport_netconfsoapbeep    833 		// tcp,NETCONF for SOAP over BEEP,[RFC4743]  ,
#define IANAport_dhcp_failover2     847 		// tcp,dhcp_failover 2   
#define IANAport_gdoi               848 		// tcp,GDOI,[RFC3547]  ,
#define IANAport_domain_s           853 		// tcp,DNS query_response protocol run over TLS,[RFC7858]  ,
#define IANAport_dlep               854 		// tcp,Dynamic Link Exchange Protocol (DLEP),[RFC8175]  ,
#define IANAport_iscsi              860 		// tcp,iSCSI,[RFC7143]  ,
#define IANAport_owamp_control      861 		// tcp,OWAMP_Control,[RFC4656]  ,
#define IANAport_owamp_test         861 		// udp,OWAMP_Test,[RFC8545]  ,
#define IANAport_twamp_control      862 		// tcp,TWAMP_Control,[RFC5357]  ,
#define IANAport_twamp_test         862 		// udp,TWAMP_Test Receiver Port,[RFC8545]  ,
#define IANAport_rsync              873 		// tcp,rsync   
#define IANAport_iclcnet_locate     886 		// tcp,ICL coNETion locate server   
#define IANAport_iclcnet_svinfo     887 		// tcp,"ICL coNETion server info IANA assigned this well_formed service name as a replacement for ""iclcnet_svinfo""."   
#define IANAport_accessbuilder      888 		// tcp,AccessBuilder   
#define IANAport_cddbp              888 		// tcp,CD Database Protocol   
#define IANAport_omginitialrefs     900 		// tcp,OMG Initial Refs   
#define IANAport_smpnameres         901 		// tcp,SMPNAMERES   
#define IANAport_ideafarm_door      902 		// tcp,self documenting Telnet Door   
#define IANAport_ideafarm_panic     903 		// tcp,self documenting Telnet Panic Door   
#define IANAport_kink               910 		// tcp,Kerberized Internet Negotiation of Keys (KINK),[RFC4430]  ,
#define IANAport_xact_backup        911 		// tcp,xact_backup   
#define IANAport_apex_mesh          912 		// tcp,APEX relay_relay service   
#define IANAport_apex_edge          913 		// tcp,APEX endpoint_relay service,[RFC3340]  ,
//#define IANAport_                 914 		// tcp,Reserved   
#define IANAport_rift_lies          914 		// udp,"Routing in Fat Trees Link Information Elements (TEMPORARY _ registered 2023_02_17, expires 2024_02_17)",[draft_ietf_rift_rift_16]  ,
//#define IANAport_                 915 		// tcp,Reserved   
#define IANAport_rndc               953 		// tcp,BIND9 remote name daemon controller   
//#define IANAport_                 953 		// udp,Reserved   
#define IANAport_ftps_data          989 		// tcp,"ftp protocol, data, over TLS/SSL"   
#define IANAport_ftps               990 		// tcp,"ftp protocol, control, over TLS/SSL"   
#define IANAport_nas                991 		// tcp,Netnews Administration System,[RFC4707]  ,
#define IANAport_telnets            992 		// tcp,telnet protocol over TLS/SSL   
#define IANAport_imaps              993 		// tcp,IMAP over TLS protocol,[RFC3501][RFC8314][RFC9051]  ,
//#define IANAport_                 993 		// udp,Reserved,[RFC9051]  ,
//#define IANAport_                 994 		// tcp,Reserved   
//#define IANAport_                 994 		// udp,Reserved   
#define IANAport_pop3s              995 		// tcp,POP3 over TLS protocol,[RFC8314]  ,
#define IANAport_vsinet             996 		// tcp,vsinet   
#define IANAport_maitrd             997 		// tcp   ,
#define IANAport_busboy             998 		// tcp   ,
#define IANAport_puparp             998 		// udp   ,
#define IANAport_garcon             999 		// tcp   ,
#define IANAport_applix             999 		// udp,Applix ac   
#define IANAport_puprouter          999 		// tcp   ,
#define IANAport_cadlock2           1000 		// tcp   ,
#define IANAport_webpush            1001 		// tcp,HTTP Web Push,[RFC8030]  ,
//#define IANAport_                 1001 		// udp,Reserved   
//#define IANAport_                 1008 		// udp,Possibly used by Sun Solaris????   
#define IANAport_surf               1010 		// tcp,surf   
//#define IANAport_                 1011_1020	// ,Reserved   
#define IANAport_exp1               1021 		// tcp,RFC3692_style Experiment 1,[1][RFC4727][RFC6335]  ,
#define IANAport_exp2               1022 		// tcp,RFC3692_style Experiment 2,[1][RFC4727][RFC6335]  ,
#define IANAport_exp2               1022 		// udp,RFC3692_style Experiment 2,[1][RFC4727][RFC6335]  ,
//#define IANAport_                 1023 		// tcp,Reserved   
//#define IANAport_                 1024 		// tcp,Reserved   

/*
REGISTERED PORT NUMBERS

The Registered Ports are listed by the IANA and on most systems can be
used by ordinary user processes or programs executed by ordinary
users.

Ports are used in the TCP [RFC793] to name the ends of logical
connections which carry long term conversations.  For the purpose of
providing services to unknown callers, a service contact port is
defined.  This list specifies the port used by the server process as
its contact port.

The IANA registers uses of these ports as a convenience to the
community.

To the extent possible, these same port assignments are used with the
UDP [RFC768].

The Registered Ports are in the range 1024_49151.

*/
//The range for assigned ports managed by the IANA is 0_1023.
//Port Assignments:
//Keyword							Value		Description                     References
//_______							_____		___________						__________
#define IANAport_blackjack          1025			// tcp,network blackjack   
#define IANAport_cap                1026			// udp,Calendar Access Protocol   
#define IANAport_6a44               1027			// udp,IPv6 Behind NAT44 CPEs,[RFC6751]  ,
//#define IANAport_                 1027			// tcp,Reserved   
//#define IANAport_                 1028			// ,Deprecated   
#define IANAport_solid_mux          1029			// tcp,Solid Mux Server   
//#define IANAport_                 1030			// ,Reserved   
//#define IANAport_                 1031			// ,Reserved   
//#define IANAport_                 1032			// ,Reserved   
#define IANAport_netinfo_local      1033			// tcp,local netinfo port   
#define IANAport_activesync         1034			// tcp,ActiveSync Notifications   
#define IANAport_mxxrlogin          1035			// tcp,MX_XR RPC   
#define IANAport_nsstp              1036			// tcp,Nebula Secure Segment Transfer Protocol   
#define IANAport_ams                1037			// tcp,AMS   
#define IANAport_mtqp               1038			// tcp,Message Tracking Query Protocol,[RFC3887]  ,
#define IANAport_sbl                1039			// tcp,Streamlined Blackhole   
#define IANAport_netarx             1040			// tcp,Netarx Netcare   
#define IANAport_danf_ak2           1041			// tcp,AK2 Product   
#define IANAport_afrog              1042			// tcp,Subnet Roaming   
#define IANAport_boinc_client       1043			// tcp,BOINC Client Control   
#define IANAport_dcutility          1044			// tcp,Dev Consortium Utility   
#define IANAport_fpitp              1045			// tcp,Fingerprint Image Transfer Protocol   
#define IANAport_wfremotertm        1046			// tcp,WebFilter Remote Monitor   
#define IANAport_neod1              1047			// tcp,Sun's NEO Object Request Broker   
#define IANAport_neod2              1048			// tcp,Sun's NEO Object Request Broker   
#define IANAport_td_postman         1049			// tcp,Tobit David Postman VPMN   
#define IANAport_cma                1050			// tcp,CORBA Management Agent   
#define IANAport_optima_vnet        1051			// tcp,Optima VNET   
#define IANAport_ddt                1052			// tcp,Dynamic DNS Tools   
#define IANAport_remote_as          1053			// tcp,Remote Assistant (RA)   
#define IANAport_brvread            1054			// tcp,BRVREAD   
#define IANAport_ansyslmd           1055			// tcp,ANSYS _ License Manager   
#define IANAport_vfo                1056			// tcp,VFO   
#define IANAport_startron           1057			// tcp,STARTRON   
#define IANAport_nim                1058			// tcp,nim   
#define IANAport_nimreg             1059			// tcp,nimreg   
#define IANAport_polestar           1060			// tcp,POLESTAR   
#define IANAport_kiosk              1061			// tcp,KIOSK   
#define IANAport_veracity           1062			// tcp,Veracity   
#define IANAport_kyoceranetdev      1063			// tcp,KyoceraNetDev   
#define IANAport_jstel              1064			// tcp,JSTEL   
#define IANAport_syscomlan          1065			// tcp,SYSCOMLAN   
#define IANAport_fpo_fns            1066			// tcp,FPO_FNS   
#define IANAport_instl_boots        1067			// tcp,"Installation Bootstrap Proto. Serv. IANA assigned this well_formed service name as a replacement for ""instl_boots""."   
#define IANAport_instl_bootc        1068			// tcp,"Installation Bootstrap Proto. Cli. IANA assigned this well_formed service name as a replacement for ""instl_bootc""."   
#define IANAport_cognex_insight     1069			// tcp,COGNEX_INSIGHT   
#define IANAport_gmrupdateserv      1070			// tcp,GMRUpdateSERV   
#define IANAport_bsquare_voip       1071			// tcp,BSQUARE_VOIP   
#define IANAport_cardax             1072			// tcp,CARDAX   
#define IANAport_bridgecontrol      1073			// tcp,Bridge Control   
#define IANAport_warmspotMgmt       1074			// tcp,Warmspot Management Protocol   
#define IANAport_rdrmshc            1075			// tcp,RDRMSHC   
#define IANAport_dab_sti_c          1076			// tcp,DAB STI_C   
#define IANAport_imgames            1077			// tcp,IMGames   
#define IANAport_avocent_proxy      1078			// tcp,Avocent Proxy Protocol   
#define IANAport_asprovatalk        1079			// tcp,ASPROVATalk   
#define IANAport_socks              1080			// tcp,Socks   
#define IANAport_pvuniwien          1081			// tcp,PVUNIWIEN   
#define IANAport_amt_esd_prot       1082			// tcp,AMT_ESD_PROT   
#define IANAport_ansoft_lm_1        1083			// tcp,Anasoft License Manager   
#define IANAport_ansoft_lm_2        1084			// tcp,Anasoft License Manager   
#define IANAport_webobjects         1085			// tcp,Web Objects   
#define IANAport_cplscrambler_lg    1086			// tcp,CPL Scrambler Logging   
#define IANAport_cplscrambler_in    1087			// tcp,CPL Scrambler Internal   
#define IANAport_cplscrambler_al    1088			// tcp,CPL Scrambler Alarm Log   
#define IANAport_ff_annunc          1089			// tcp,FF Annunciation   
#define IANAport_ff_fms             1090			// tcp,FF Fieldbus Message Specification   
#define IANAport_ff_sm              1091			// tcp,FF System Management   
#define IANAport_obrpd              1092			// tcp,Open Business Reporting Protocol   
#define IANAport_proofd             1093			// tcp,PROOFD   
#define IANAport_rootd              1094			// tcp,ROOTD   
#define IANAport_nicelink           1095			// tcp,NICELink   
#define IANAport_cnrprotocol        1096			// tcp,Common Name Resolution Protocol   
#define IANAport_sunclustermgr      1097			// tcp,Sun Cluster Manager   
#define IANAport_rmiactivation      1098			// tcp,RMI Activation   
#define IANAport_rmiregistry        1099			// tcp,RMI Registry   
#define IANAport_mctp               1100			// tcp,MCTP   
#define IANAport_pt2_discover       1101			// tcp,PT2_DISCOVER   
#define IANAport_adobeserver_1      1102			// tcp,ADOBE SERVER 1   
#define IANAport_adobeserver_2      1103			// tcp,ADOBE SERVER 2   
#define IANAport_xrl                1104			// tcp,XRL   
#define IANAport_ftranhc            1105			// tcp,FTRANHC   
#define IANAport_isoipsigport_1     1106			// tcp,ISOIPSIGPORT_1   
#define IANAport_isoipsigport_2     1107			// tcp,ISOIPSIGPORT_2   
#define IANAport_ratio_adp          1108			// tcp,ratio_adp   
//#define IANAport_                 1109			// ,Reserved _ IANA   
#define IANAport_webadmstart        1110			// tcp,Start web admin server   
#define IANAport_nfsd_keepalive     1110			// udp,Client status info   
#define IANAport_lmsocialserver     1111			// tcp,LM Social Server   
#define IANAport_icp                1112			// tcp,Intelligent Communication Protocol   
#define IANAport_ltp_deepspace      1113			// tcp,Licklider Transmission Protocol,[RFC5326]  ,
#define IANAport_mini_sql           1114			// tcp,Mini SQL   
#define IANAport_ardus_trns         1115			// tcp,ARDUS Transfer   
#define IANAport_ardus_cntl         1116			// tcp,ARDUS Control   
#define IANAport_ardus_mtrns        1117			// tcp,ARDUS Multicast Transfer   
#define IANAport_sacred             1118			// tcp,SACRED,[RFC3767]  ,
#define IANAport_bnetgame           1119			// tcp,Battle.net Chat/Game Protocol   
#define IANAport_bnetfile           1120			// tcp,Battle.net File Transfer Protocol   
#define IANAport_rmpp               1121			// tcp,Datalode RMPP   
#define IANAport_availant_mgr       1122			// tcp,availant_mgr   
#define IANAport_murray             1123			// tcp,Murray   
#define IANAport_hpvmmcontrol       1124			// tcp,HP VMM Control   
#define IANAport_hpvmmagent         1125			// tcp,HP VMM Agent   
#define IANAport_hpvmmdata          1126			// tcp,HP VMM Agent   
#define IANAport_kwdb_commn         1127			// tcp,KWDB Remote Communication   
#define IANAport_saphostctrl        1128			// tcp,SAPHostControl over SOAP/HTTP   
#define IANAport_saphostctrls       1129			// tcp,SAPHostControl over SOAP/HTTPS   
#define IANAport_casp               1130			// tcp,CAC App Service Protocol   
#define IANAport_caspssl            1131			// tcp,CAC App Service Protocol Encripted   
#define IANAport_kvm_via_ip         1132			// tcp,KVM_via_IP Management Service   
#define IANAport_dfn                1133			// tcp,Data Flow Network   
#define IANAport_aplx               1134			// tcp,MicroAPL APLX   
#define IANAport_omnivision         1135			// tcp,OmniVision Communication Service   
#define IANAport_hhb_gateway        1136			// tcp,HHB Gateway Control   
#define IANAport_trim               1137			// tcp,TRIM Workgroup Service   
#define IANAport_encrypted_admin    1138			// tcp,"encrypted admin requests IANA assigned this well_formed service name as a replacement for ""encrypted_admin""."   
#define IANAport_encrypted_admin    1138			// udp,"encrypted admin requests IANA assigned this well_formed service name as a replacement for ""encrypted_admin""."   
#define IANAport_evm                1139			// tcp,Enterprise Virtual Manager   
#define IANAport_autonoc            1140			// tcp,AutoNOC Network Operations Protocol   
#define IANAport_mxomss             1141			// tcp,User Message Service   
#define IANAport_edtools            1142			// tcp,User Discovery Service   
#define IANAport_imyx               1143			// tcp,Infomatryx Exchange   
#define IANAport_fuscript           1144			// tcp,Fusion Script   
#define IANAport_x9_icue            1145			// tcp,X9 iCue Show Control   
#define IANAport_audit_transfer     1146			// tcp,audit transfer   
#define IANAport_capioverlan        1147			// tcp,CAPIoverLAN   
#define IANAport_elfiq_repl         1148			// tcp,Elfiq Replication Service   
#define IANAport_bvtsonar           1149			// tcp,BlueView Sonar Service   
#define IANAport_blaze              1150			// tcp,Blaze File Server   
#define IANAport_unizensus          1151			// tcp,Unizensus Login Server   
#define IANAport_winpoplanmess      1152			// tcp,Winpopup LAN Messenger   
#define IANAport_c1222_acse         1153			// tcp,ANSI C12.22 Port,[RFC6142]  ,
#define IANAport_resacommunity      1154			// tcp,Community Service   
#define IANAport_nfa                1155			// tcp,Network File Access   
#define IANAport_iascontrol_oms     1156			// tcp,iasControl OMS   
#define IANAport_iascontrol         1157			// tcp,Oracle iASControl   
#define IANAport_dbcontrol_oms      1158			// tcp,dbControl OMS   
#define IANAport_oracle_oms         1159			// tcp,Oracle OMS   
#define IANAport_olsv               1160			// tcp,DB Lite Mult_User Server   
#define IANAport_health_polling     1161			// tcp,Health Polling   
#define IANAport_health_trap        1162			// tcp,Health Trap   
#define IANAport_sddp               1163			// tcp,SmartDialer Data Protocol   
#define IANAport_qsm_proxy          1164			// tcp,QSM Proxy Service   
#define IANAport_qsm_gui            1165			// tcp,QSM GUI Service   
#define IANAport_qsm_remote         1166			// tcp,QSM RemoteExec   
#define IANAport_cisco_ipsla        1167			// tcp,Cisco IP SLAs Control Protocol   
#define IANAport_vchat              1168			// tcp,VChat Conference Service   
#define IANAport_tripwire           1169			// tcp,TRIPWIRE   
#define IANAport_atc_lm             1170			// tcp,AT+C License Manager   
#define IANAport_atc_appserver      1171			// tcp,AT+C FmiApplicationServer   
#define IANAport_dnap               1172			// tcp,DNA Protocol   
#define IANAport_d_cinema_rrp       1173			// tcp,D_Cinema Request_Response   
#define IANAport_fnet_remote_ui     1174			// tcp,FlashNet Remote Admin   
#define IANAport_dossier            1175			// tcp,Dossier Server   
#define IANAport_indigo_server      1176			// tcp,Indigo Home Server   
#define IANAport_dkmessenger        1177			// tcp,DKMessenger Protocol   
#define IANAport_sgi_storman        1178			// tcp,SGI Storage Manager   
#define IANAport_b2n                1179			// tcp,Backup To Neighbor   
#define IANAport_mc_client          1180			// tcp,Millicent Client Proxy   
#define IANAport_3comnetman         1181			// tcp,3Com Net Management   
#define IANAport_accelenet          1182			// tcp,AcceleNet Control   
#define IANAport_accelenet_data     1182			// udp,AcceleNet Data   
#define IANAport_llsurfup_http      1183			// tcp,LL Surfup HTTP   
#define IANAport_llsurfup_https     1184			// tcp,LL Surfup HTTPS   
#define IANAport_catchpole          1185			// tcp,Catchpole port   
#define IANAport_mysql_cluster      1186			// tcp,MySQL Cluster Manager   
#define IANAport_alias              1187			// tcp,Alias Service   
#define IANAport_hp_webadmin        1188			// tcp,HP Web Admin   
#define IANAport_unet               1189			// tcp,Unet Connection   
#define IANAport_commlinx_avl       1190			// tcp,CommLinx GPS / AVL System   
#define IANAport_gpfs               1191			// tcp,General Parallel File System   
#define IANAport_caids_sensor       1192			// tcp,caids sensors channel   
#define IANAport_fiveacross         1193			// tcp,Five Across Server   
#define IANAport_openvpn            1194			// tcp,OpenVPN   
#define IANAport_rsf_1              1195			// tcp,RSF_1 clustering   
#define IANAport_netmagic           1196			// tcp,Network Magic   
#define IANAport_carrius_rshell     1197			// tcp,Carrius Remote Access   
#define IANAport_cajo_discovery     1198			// tcp,cajo reference discovery   
#define IANAport_dmidi              1199			// tcp,DMIDI   
#define IANAport_scol               1200			// tcp,SCOL   
#define IANAport_nucleus_sand       1201			// tcp,Nucleus Sand Database Server   
#define IANAport_caiccipc           1202			// tcp,caiccipc   
#define IANAport_ssslic_mgr         1203			// tcp,License Validation   
#define IANAport_ssslog_mgr         1204			// tcp,Log Request Listener   
#define IANAport_accord_mgc         1205			// tcp,Accord_MGC   
#define IANAport_anthony_data       1206			// tcp,Anthony Data   
#define IANAport_metasage           1207			// tcp,MetaSage   
#define IANAport_seagull_ais        1208			// tcp,SEAGULL AIS   
#define IANAport_ipcd3              1209			// tcp,IPCD3   
#define IANAport_eoss               1210			// tcp,EOSS   
#define IANAport_groove_dpp         1211			// tcp,Groove DPP   
#define IANAport_lupa               1212			// tcp,lupa   
#define IANAport_mpc_lifenet        1213			// tcp,Medtronic/Physio_Control LIFENET   
#define IANAport_kazaa              1214			// tcp,KAZAA   
#define IANAport_scanstat_1         1215			// tcp,scanSTAT 1.0   
#define IANAport_etebac5            1216			// tcp,ETEBAC 5   
#define IANAport_hpss_ndapi         1217			// tcp,HPSS NonDCE Gateway   
#define IANAport_aeroflight_ads     1218			// tcp,AeroFlight_ADs   
#define IANAport_aeroflight_ret     1219			// tcp,AeroFlight_Ret   
#define IANAport_qt_serveradmin     1220			// tcp,QT SERVER ADMIN   
#define IANAport_sweetware_apps     1221			// tcp,SweetWARE Apps   
#define IANAport_nerv               1222			// tcp,SNI R&D network   
#define IANAport_tgp                1223			// tcp,TrulyGlobal Protocol   
#define IANAport_vpnz               1224			// tcp,VPNz   
#define IANAport_slinkysearch       1225			// tcp,SLINKYSEARCH   
#define IANAport_stgxfws            1226			// tcp,STGXFWS   
#define IANAport_dns2go             1227			// tcp,DNS2Go   
#define IANAport_florence           1228			// tcp,FLORENCE   
#define IANAport_zented             1229			// tcp,ZENworks Tiered Electronic Distribution   
#define IANAport_periscope          1230			// tcp,Periscope   
#define IANAport_menandmice_lpm     1231			// tcp,menandmice_lpm   
#define IANAport_first_defense      1232			// tcp,Remote systems monitoring   
#define IANAport_univ_appserver     1233			// tcp,Universal App Server   
#define IANAport_search_agent       1234			// tcp,Infoseek Search Agent   
#define IANAport_mosaicsyssvc1      1235			// tcp,mosaicsyssvc1   
#define IANAport_bvcontrol          1236			// tcp,bvcontrol   
#define IANAport_tsdos390           1237			// tcp,tsdos390   
#define IANAport_hacl_qs            1238			// tcp,hacl_qs   
#define IANAport_nmsd               1239			// tcp,NMSD   
#define IANAport_instantia          1240			// tcp,Instantia   
#define IANAport_nessus             1241			// tcp,nessus   
#define IANAport_nmasoverip         1242			// tcp,NMAS over IP   
#define IANAport_serialgateway      1243			// tcp,SerialGateway   
#define IANAport_isbconference1     1244			// tcp,isbconference1   
#define IANAport_isbconference2     1245			// tcp,isbconference2   
#define IANAport_payrouter          1246			// tcp,payrouter   
#define IANAport_visionpyramid      1247			// tcp,VisionPyramid   
#define IANAport_hermes             1248			// tcp,hermes   
#define IANAport_mesavistaco        1249			// tcp,Mesa Vista Co   
#define IANAport_swldy_sias         1250			// tcp,swldy_sias   
#define IANAport_servergraph        1251			// tcp,servergraph   
#define IANAport_bspne_pcc          1252			// tcp,bspne_pcc   
#define IANAport_q55_pcc            1253			// tcp,q55_pcc   
#define IANAport_de_noc             1254			// tcp,de_noc   
#define IANAport_de_cache_query     1255			// tcp,de_cache_query   
#define IANAport_de_server          1256			// tcp,de_server   
#define IANAport_shockwave2         1257			// tcp,Shockwave 2   
#define IANAport_opennl             1258			// tcp,Open Network Library   
#define IANAport_opennl_voice       1259			// tcp,Open Network Library Voice   
#define IANAport_ibm_ssd            1260			// tcp,ibm_ssd   
#define IANAport_mpshrsv            1261			// tcp,mpshrsv   
#define IANAport_qnts_orb           1262			// tcp,QNTS_ORB   
#define IANAport_dka                1263			// tcp,dka   
#define IANAport_prat               1264			// tcp,PRAT   
#define IANAport_dssiapi            1265			// tcp,DSSIAPI   
#define IANAport_dellpwrappks       1266			// tcp,DELLPWRAPPKS   
#define IANAport_epc                1267			// tcp,eTrust Policy Compliance   
#define IANAport_propel_msgsys      1268			// tcp,PROPEL_MSGSYS   
#define IANAport_watilapp           1269			// tcp,WATiLaPP   
#define IANAport_opsmgr             1270			// tcp,Microsoft Operations Manager   
#define IANAport_excw               1271			// tcp,eXcW   
#define IANAport_cspmlockmgr        1272			// tcp,CSPMLockMgr   
#define IANAport_emc_gateway        1273			// tcp,EMC_Gateway   
#define IANAport_t1distproc         1274			// tcp,t1distproc   
#define IANAport_ivcollector        1275			// tcp,ivcollector   
//#define IANAport_                 1276			// tcp,Reserved   
#define IANAport_miva_mqs           1277			// tcp,mqs   
#define IANAport_dellwebadmin_1     1278			// tcp,Dell Web Admin 1   
#define IANAport_dellwebadmin_2     1279			// tcp,Dell Web Admin 2   
#define IANAport_pictrography       1280			// tcp,Pictrography   
#define IANAport_healthd            1281			// tcp,healthd   
#define IANAport_emperion           1282			// tcp,Emperion   
#define IANAport_productinfo        1283			// tcp,Product Information   
#define IANAport_iee_qfx            1284			// tcp,IEE_QFX   
#define IANAport_neoiface           1285			// tcp,neoiface   
#define IANAport_netuitive          1286			// tcp,netuitive   
#define IANAport_routematch         1287			// tcp,RouteMatch Com   
#define IANAport_navbuddy           1288			// tcp,NavBuddy   
#define IANAport_jwalkserver        1289			// tcp,JWalkServer   
#define IANAport_winjaserver        1290			// tcp,WinJaServer   
#define IANAport_seagulllms         1291			// tcp,SEAGULLLMS   
#define IANAport_dsdn               1292			// tcp,dsdn   
#define IANAport_pkt_krb_ipsec      1293			// tcp,PKT_KRB_IPSec   
#define IANAport_cmmdriver          1294			// tcp,CMMdriver   
#define IANAport_ehtp               1295			// tcp,End_by_Hop Transmission Protocol   
#define IANAport_dproxy             1296			// tcp,dproxy   
#define IANAport_sdproxy            1297			// tcp,sdproxy   
#define IANAport_lpcp               1298			// tcp,lpcp   
#define IANAport_hp_sci             1299			// tcp,hp_sci   
#define IANAport_h323hostcallsc     1300			// tcp,H.323 Secure Call Control Signalling   
//#define IANAport_                 1301			// tcp,Reserved   
//#define IANAport_                 1302			// tcp,Reserved   
#define IANAport_sftsrv             1303			// tcp,sftsrv   
#define IANAport_boomerang          1304			// tcp,Boomerang   
#define IANAport_pe_mike            1305			// tcp,pe_mike   
#define IANAport_re_conn_proto      1306			// tcp,RE_Conn_Proto   
#define IANAport_pacmand            1307			// tcp,Pacmand   
#define IANAport_odsi               1308			// tcp,Optical Domain Service Interconnect (ODSI)   
#define IANAport_jtag_server        1309			// tcp,JTAG server   
#define IANAport_husky              1310			// tcp,Husky   
#define IANAport_rxmon              1311			// tcp,RxMon   
#define IANAport_sti_envision       1312			// tcp,STI Envision   
#define IANAport_bmc_patroldb       1313			// tcp,"BMC_PATROLDB IANA assigned this well_formed service name as a replacement for ""bmc_patroldb""."   
#define IANAport_pdps               1314			// tcp,Photoscript Distributed Printing System   
#define IANAport_els                1315			// tcp,"E.L.S., Event Listener Service"   
#define IANAport_exbit_escp         1316			// tcp,Exbit_ESCP   
#define IANAport_vrts_ipcserver     1317			// tcp,vrts_ipcserver   
#define IANAport_krb5gatekeeper     1318			// tcp,krb5gatekeeper   
#define IANAport_amx_icsp           1319			// tcp,AMX_ICSP   
#define IANAport_amx_axbnet         1320			// tcp,AMX_AXBNET   
#define IANAport_pip_pip            1321			// tcp,PIP - Modified to avoid conflict with line 387
#define IANAport_novation           1322			// tcp,Novation   
#define IANAport_brcd               1323			// tcp,brcd   
#define IANAport_delta_mcp          1324			// tcp,delta_mcp   
#define IANAport_dx_instrument      1325			// tcp,DX_Instrument   
#define IANAport_wimsic             1326			// tcp,WIMSIC   
#define IANAport_ultrex             1327			// tcp,Ultrex   
#define IANAport_ewall              1328			// tcp,EWALL   
#define IANAport_netdb_export       1329			// tcp,netdb_export   
#define IANAport_streetperfect      1330			// tcp,StreetPerfect   
#define IANAport_intersan           1331			// tcp,intersan   
#define IANAport_pcia_rxp_b         1332			// tcp,PCIA RXP_B   
#define IANAport_passwrd_policy     1333			// tcp,Password Policy   
#define IANAport_writesrv           1334			// tcp,writesrv   
#define IANAport_digital_notary     1335			// tcp,Digital Notary Protocol   
#define IANAport_ischat             1336			// tcp,Instant Service Chat   
#define IANAport_menandmice_dns     1337			// tcp,menandmice DNS   
#define IANAport_wmc_log_svc        1338			// tcp,WMC_log_svr   
#define IANAport_kjtsiteserver      1339			// tcp,kjtsiteserver   
#define IANAport_naap               1340			// tcp,NAAP   
#define IANAport_qubes              1341			// tcp,QuBES   
#define IANAport_esbroker           1342			// tcp,ESBroker   
#define IANAport_re101              1343			// tcp,re101   
#define IANAport_icap               1344			// tcp,ICAP   
#define IANAport_vpjp               1345			// tcp,VPJP   
#define IANAport_alta_ana_lm        1346			// tcp,Alta Analytics License Manager   
#define IANAport_bbn_mmc            1347			// tcp,multi media conferencing   
#define IANAport_bbn_mmx            1348			// tcp,multi media conferencing   
#define IANAport_sbook              1349			// tcp,Registration Network Protocol   
#define IANAport_editbench          1350			// tcp,Registration Network Protocol   
#define IANAport_equationbuilder    1351			// tcp,Digital Tool Works (MIT)   
#define IANAport_lotusnote          1352			// tcp,Lotus Note   
#define IANAport_relief             1353			// tcp,Relief Consulting   
#define IANAport_XSIP_network       1354			// tcp,Five Across XSIP Network   
#define IANAport_intuitive_edge     1355			// tcp,Intuitive Edge   
#define IANAport_cuillamartin       1356			// tcp,CuillaMartin Company   
#define IANAport_pegboard           1357			// tcp,Electronic PegBoard   
#define IANAport_connlcli           1358			// tcp,CONNLCLI   
#define IANAport_ftsrv              1359			// tcp,FTSRV   
#define IANAport_mimer              1360			// tcp,MIMER   
#define IANAport_linx               1361			// tcp,LinX   
#define IANAport_timeflies          1362			// tcp,TimeFlies   
#define IANAport_ndm_requester      1363			// tcp,Network DataMover Requester   
#define IANAport_ndm_server         1364			// tcp,Network DataMover Server   
#define IANAport_adapt_sna          1365			// tcp,Network Software Associates   
#define IANAport_netware_csp        1366			// tcp,Novell NetWare Comm Service Platform   
#define IANAport_dcs                1367			// tcp,DCS   
#define IANAport_screencast         1368			// tcp,ScreenCast   
#define IANAport_gv_us              1369			// tcp,GlobalView to Unix Shell   
#define IANAport_us_gv              1370			// tcp,Unix Shell to GlobalView   
#define IANAport_fc_cli             1371			// tcp,Fujitsu Config Protocol   
#define IANAport_fc_ser             1372			// tcp,Fujitsu Config Protocol   
#define IANAport_chromagrafx        1373			// tcp,Chromagrafx   
#define IANAport_molly              1374			// tcp,EPI Software Systems   
#define IANAport_bytex              1375			// tcp,Bytex   
#define IANAport_ibm_pps            1376			// tcp,IBM Person to Person Software   
#define IANAport_cichlid            1377			// tcp,Cichlid License Manager   
#define IANAport_elan               1378			// tcp,Elan License Manager   
#define IANAport_dbreporter         1379			// tcp,Integrity Solutions   
#define IANAport_telesis_licman     1380			// tcp,Telesis Network License Manager   
#define IANAport_apple_licman       1381			// tcp,Apple Network License Manager   
#define IANAport_udt_os_1           1382			// tcp,"udt_os IANA assigned this well_formed service name as a replacement for ""udt_os"" - Note amended
#define IANAport_gwha               1383			// tcp,GW Hannaway Network License Manager   
#define IANAport_os_licman          1384			// tcp,Objective Solutions License Manager   
#define IANAport_atex_elmd          1385			// tcp,"Atex Publishing License Manager IANA assigned this well_formed service name as a replacement for ""atex_elmd""."   
#define IANAport_checksum           1386			// tcp,CheckSum License Manager   
#define IANAport_cadsi_lm           1387			// tcp,Computer Aided Design Software Inc LM   
#define IANAport_objective_dbc      1388			// tcp,Objective Solutions DataBase Cache   
#define IANAport_iclpv_dm           1389			// tcp,Document Manager   
#define IANAport_iclpv_sc           1390			// udp,Storage Controller   
#define IANAport_iclpv_sas          1391			// tcp,Storage Access Server   
#define IANAport_iclpv_pm           1392			// tcp,Print Manager   
#define IANAport_iclpv_nls          1393			// tcp,Network Log Server   
#define IANAport_iclpv_nlc          1394			// tcp,Network Log Client   
#define IANAport_iclpv_wsm          1395			// tcp,PC Workstation Manager software   
#define IANAport_dvl_activemail     1396			// tcp,DVL Active Mail   
#define IANAport_audio_activmail    1397			// tcp,Audio Active Mail   
#define IANAport_video_activmail    1398			// tcp,Video Active Mail   
#define IANAport_cadkey_licman      1399			// tcp,Cadkey License Manager   
#define IANAport_cadkey_tablet      1400			// tcp,Cadkey Tablet Daemon   
#define IANAport_goldleaf_licman    1401			// tcp,Goldleaf License Manager   
#define IANAport_prm_sm_np          1402			// tcp,Prospero Resource Manager   
#define IANAport_prm_nm_np          1403			// tcp,Prospero Resource Manager   
#define IANAport_igi_lm             1404			// tcp,Infinite Graphics License Manager   
#define IANAport_ibm_res            1405			// tcp,IBM Remote Execution Starter   
#define IANAport_netlabs_lm         1406			// tcp,NetLabs License Manager   
#define IANAport_tibet_server       1407			// tcp,TIBET Data Server   
//#define IANAport_                 1407			// udp,Reserved   
#define IANAport_sophia_lm          1408			// tcp,Sophia License Manager   
#define IANAport_here_lm            1409			// tcp,Here License Manager   
#define IANAport_hiq                1410			// tcp,HiQ License Manager   
#define IANAport_af                 1411			// tcp,AudioFile   
#define IANAport_innosys            1412			// tcp,InnoSys   
#define IANAport_innosys_acl        1413			// tcp,Innosys_ACL   
#define IANAport_ibm_mqseries       1414			// tcp,IBM MQSeries   
#define IANAport_dbstar             1415			// tcp,DBStar   
#define IANAport_novell_lu6_2       1416			// tcp,"Novell LU6.2 IANA assigned this well_formed service name as a replacement for ""novell_lu6.2""."   
#define IANAport_timbuktu_srv1      1417			// tcp,Timbuktu Service 1 Port   
#define IANAport_timbuktu_srv2      1418			// tcp,Timbuktu Service 2 Port   
#define IANAport_timbuktu_srv3      1419			// tcp,Timbuktu Service 3 Port   
#define IANAport_timbuktu_srv4      1420			// tcp,Timbuktu Service 4 Port   
#define IANAport_gandalf_lm         1421			// tcp,Gandalf License Manager   
#define IANAport_autodesk_lm        1422			// tcp,Autodesk License Manager   
#define IANAport_essbase            1423			// tcp,Essbase Arbor Software   
#define IANAport_hybrid             1424			// tcp,Hybrid Encryption Protocol   
#define IANAport_zion_lm            1425			// tcp,Zion Software License Manager   
#define IANAport_sais               1426			// tcp,Satellite_data Acquisition System 1   
#define IANAport_mloadd             1427			// tcp,mloadd monitoring tool   
#define IANAport_informatik_lm      1428			// tcp,Informatik License Manager   
#define IANAport_nms                1429			// tcp,Hypercom NMS   
#define IANAport_tpdu               1430			// tcp,Hypercom TPDU   
#define IANAport_rgtp               1431			// tcp,Reverse Gossip Transport   
#define IANAport_blueberry_lm       1432			// tcp,Blueberry Software License Manager   
#define IANAport_ms_sql_s           1433			// tcp,Microsoft_SQL_Server   
#define IANAport_ms_sql_m           1434			// tcp,Microsoft_SQL_Monitor   
#define IANAport_ibm_cics           1435			// tcp,IBM CICS   
#define IANAport_saism              1436			// tcp,Satellite_data Acquisition System 2   
#define IANAport_tabula             1437			// tcp,Tabula   
#define IANAport_eicon_server       1438			// tcp,Eicon Security Agent/Server   
#define IANAport_eicon_x25          1439			// tcp,Eicon X25/SNA Gateway   
#define IANAport_eicon_slp          1440			// tcp,Eicon Service Location Protocol   
#define IANAport_cadis_1            1441			// tcp,Cadis License Management   
#define IANAport_cadis_2            1442			// tcp,Cadis License Management   
#define IANAport_ies_lm             1443			// tcp,Integrated Engineering Software   
#define IANAport_marcam_lm          1444			// tcp,Marcam  License Management   
#define IANAport_proxima_lm         1445			// tcp,Proxima License Manager   
#define IANAport_ora_lm             1446			// tcp,Optical Research Associates License Manager   
#define IANAport_apri_lm            1447			// tcp,Applied Parallel Research LM   
#define IANAport_oc_lm              1448			// tcp,OpenConnect License Manager   
#define IANAport_peport             1449			// tcp,PEport   
#define IANAport_dwf                1450			// tcp,Tandem Distributed Workbench Facility   
#define IANAport_infoman            1451			// tcp,IBM Information Management   
#define IANAport_gtegsc_lm          1452			// tcp,GTE Government Systems License Man   
#define IANAport_genie_lm           1453			// tcp,Genie License Manager   
#define IANAport_interhdl_elmd      1454			// tcp,"interHDL License Manager IANA assigned this well_formed service name as a replacement for ""interhdl_elmd""."   
#define IANAport_esl_lm             1455			// tcp,ESL License Manager   
#define IANAport_dca                1456			// tcp,DCA   
#define IANAport_valisys_lm         1457			// tcp,Valisys License Manager   
#define IANAport_nrcabq_lm          1458			// tcp,Nichols Research Corp.   
#define IANAport_proshare1          1459			// tcp,Proshare Notebook Application   
#define IANAport_proshare2          1460			// tcp,Proshare Notebook Application   
#define IANAport_ibm_wrless_lan     1461			// tcp,"IBM Wireless LAN IANA assigned this well_formed service name as a replacement for ""ibm_wrless_lan""."   
#define IANAport_world_lm           1462			// tcp,World License Manager   
#define IANAport_nucleus            1463			// tcp,Nucleus   
#define IANAport_msl_lmd            1464			// tcp,"MSL License Manager IANA assigned this well_formed service name as a replacement for ""msl_lmd""."   
#define IANAport_pipes              1465			// tcp,Pipes Platform   
#define IANAport_oceansoft_lm       1466			// tcp,Ocean Software License Manager   
#define IANAport_CSDMBASE           1467			// tcp,CSDMBASE - Modified to avoid conflict with line 1356
#define IANAport_CSDM               1468			// tcp,CSDM - Modified to avoid conflict with line 1357
#define IANAport_aal_lm             1469			// tcp,Active Analysis Limited License Manager   
#define IANAport_uaiact             1470			// tcp,Universal Analytics   
#define IANAport_csdmbase           1471			// tcp,csdmbase   
#define IANAport_csdm               1472			// tcp,csdm   
#define IANAport_openmath           1473			// tcp,OpenMath   
#define IANAport_telefinder         1474			// tcp,Telefinder   
#define IANAport_taligent_lm        1475			// tcp,Taligent License Manager   
#define IANAport_clvm_cfg           1476			// tcp,clvm_cfg   
#define IANAport_ms_sna_server      1477			// tcp,ms_sna_server   
#define IANAport_ms_sna_base        1478			// tcp,ms_sna_base   
#define IANAport_dberegister        1479			// tcp,dberegister   
#define IANAport_pacerforum         1480			// tcp,PacerForum   
#define IANAport_airs               1481			// tcp,AIRS   
#define IANAport_miteksys_lm        1482			// tcp,Miteksys License Manager   
#define IANAport_afs                1483			// tcp,AFS License Manager   
#define IANAport_confluent          1484			// tcp,Confluent License Manager   
#define IANAport_lansource          1485			// tcp,LANSource   
#define IANAport_nms_topo_serv      1486			// tcp,"nms_topo_serv IANA assigned this well_formed service name as a replacement for ""nms_topo_serv""."   
#define IANAport_localinfosrvr      1487			// tcp,LocalInfoSrvr   
#define IANAport_docstor            1488			// tcp,DocStor   
#define IANAport_dmdocbroker        1489			// tcp,dmdocbroker   
#define IANAport_insitu_conf        1490			// tcp,insitu_conf   
#define IANAport_stone_design_1     1492			// tcp,stone_design_1   
#define IANAport_netmap_lm          1493			// tcp,"netmap_lm IANA assigned this well_formed service name as a replacement for ""netmap_lm""."   
#define IANAport_ica                1494			// tcp,ica   
#define IANAport_cvc                1495			// tcp,cvc   
#define IANAport_liberty_lm         1496			// tcp,liberty_lm   
#define IANAport_rfx_lm             1497			// tcp,rfx_lm   
#define IANAport_sybase_sqlany      1498			// tcp,Sybase SQL Any   
#define IANAport_fhc                1499			// tcp,Federico Heinz Consultora   
#define IANAport_vlsi_lm            1500			// tcp,VLSI License Manager   
#define IANAport_saiscm             1501			// tcp,Satellite_data Acquisition System 3   
#define IANAport_shivadiscovery     1502			// tcp,Shiva   
#define IANAport_imtc_mcs           1503			// tcp,Databeam   
#define IANAport_evb_elm            1504			// tcp,EVB Software Engineering License Manager   
#define IANAport_funkproxy          1505			// tcp,"Funk Software, Inc."   
#define IANAport_utcd               1506			// tcp,Universal Time daemon (utcd)   
#define IANAport_symplex            1507			// tcp,symplex   
#define IANAport_diagmond           1508			// tcp,diagmond   
#define IANAport_robcad_lm          1509			// tcp,"Robcad, Ltd. License Manager"   
#define IANAport_mvx_lm             1510			// tcp,Midland Valley Exploration Ltd. Lic. Man.   
#define IANAport_3l_l1              1511			// tcp,3l_l1   
#define IANAport_wins               1512			// tcp,Microsoft's Windows Internet Name Service   
#define IANAport_fujitsu_dtc        1513			// tcp,"Fujitsu Systems Business of America, Inc"   
#define IANAport_fujitsu_dtcns      1514			// tcp,"Fujitsu Systems Business of America, Inc"   
#define IANAport_ifor_protocol      1515			// tcp,ifor_protocol   
#define IANAport_vpad               1516			// tcp,Virtual Places Audio data   
#define IANAport_vpac               1517			// tcp,Virtual Places Audio control   
#define IANAport_vpvd               1518			// tcp,Virtual Places Video data   
#define IANAport_vpvc               1519			// tcp,Virtual Places Video control   
#define IANAport_atm_zip_office     1520			// tcp,atm zip office   
#define IANAport_ncube_lm           1521			// tcp,nCube License Manager   
#define IANAport_ricardo_lm_1       1522			// tcp,Ricardo North America License Manager - Note amended 
#define IANAport_cichild_lm         1523			// tcp,cichild   
#define IANAport_ingreslock         1524			// tcp,ingres   
#define IANAport_orasrv             1525			// tcp,oracle   
#define IANAport_prospero_np        1525			// tcp,Prospero Directory Service non_priv   
#define IANAport_pdap_np            1526			// tcp,Prospero Data Access Prot non_priv   
#define IANAport_tlisrv             1527			// tcp,oracle   
#define IANAport_norp               1528			// tcp,Not Only a Routeing Protocol   
#define IANAport_coauthor           1529			// tcp,oracle   
#define IANAport_rap_service        1530			// tcp,rap_service   
#define IANAport_rap_listen         1531			// tcp,rap_listen   
#define IANAport_miroconnect        1532			// tcp,miroconnect   
#define IANAport_virtual_places     1533			// tcp,Virtual Places Software   
#define IANAport_micromuse_lm       1534			// tcp,micromuse_lm   
#define IANAport_ampr_info          1535			// tcp,ampr_info   
#define IANAport_ampr_inter         1536			// tcp,ampr_inter   
#define IANAport_sdsc_lm            1537			// tcp,isi_lm   
#define IANAport_3ds_lm             1538			// tcp,3ds_lm   
#define IANAport_intellistor_lm     1539			// tcp,Intellistor License Manager   
#define IANAport_rds                1540			// tcp,rds   
#define IANAport_rds2               1541			// tcp,rds2   
#define IANAport_gridgen_elmd       1542			// tcp,gridgen_elmd   
#define IANAport_simba_cs           1543			// tcp,simba_cs   
#define IANAport_aspeclmd           1544			// tcp,aspeclmd   
#define IANAport_vistium_share      1545			// tcp,vistium_share   
#define IANAport_abbaccuray         1546			// tcp,abbaccuray   
#define IANAport_laplink            1547			// tcp,laplink   
#define IANAport_axon_lm            1548			// tcp,Axon License Manager   
#define IANAport_shivahose          1549			// tcp,Shiva Hose   
#define IANAport_shivasound         1549			// udp,Shiva Sound   
#define IANAport_3m_image_lm        1550			// tcp,Image Storage license manager 3M Company   
#define IANAport_hecmtl_db          1551			// tcp,HECMTL_DB   
#define IANAport_pciarray           1552			// tcp,pciarray   
#define IANAport_sna_cs             1553			// tcp,sna_cs   
#define IANAport_caci_lm            1554			// tcp,CACI Products Company License Manager   
#define IANAport_livelan            1555			// tcp,livelan   
#define IANAport_veritas_pbx        1556			// tcp,"VERITAS Private Branch Exchange IANA assigned this well_formed service name as a replacement for ""veritas_pbx""."   
#define IANAport_arbortext_lm       1557			// tcp,ArborText License Manager   
#define IANAport_xingmpeg           1558			// tcp,xingmpeg   
#define IANAport_web2host           1559			// tcp,web2host   
#define IANAport_asci_val           1560			// tcp,ASCI_RemoteSHADOW   
#define IANAport_facilityview       1561			// tcp,facilityview   
#define IANAport_pconnectmgr        1562			// tcp,pconnectmgr   
#define IANAport_cadabra_lm         1563			// tcp,Cadabra License Manager   
#define IANAport_pay_per_view       1564			// tcp,Pay_Per_View   
#define IANAport_winddlb            1565			// tcp,WinDD   
#define IANAport_corelvideo         1566			// tcp,CORELVIDEO   
#define IANAport_jlicelmd           1567			// tcp,jlicelmd   
#define IANAport_tsspmap            1568			// tcp,tsspmap   
#define IANAport_ets                1569			// tcp,ets   
#define IANAport_orbixd             1570			// tcp,orbixd   
#define IANAport_rdb_dbs_disp       1571			// tcp,Oracle Remote Data Base   
#define IANAport_chip_lm            1572			// tcp,Chipcom License Manager   
#define IANAport_itscomm_ns         1573			// tcp,itscomm_ns   
#define IANAport_mvel_lm            1574			// tcp,mvel_lm   
#define IANAport_oraclenames        1575			// tcp,oraclenames   
#define IANAport_moldflow_lm        1576			// tcp,Moldflow License Manager   
#define IANAport_hypercube_lm       1577			// tcp,hypercube_lm   
#define IANAport_jacobus_lm         1578			// tcp,Jacobus License Manager   
#define IANAport_ioc_sea_lm         1579			// tcp,ioc_sea_lm   
#define IANAport_tn_tl_r1           1580			// tcp,tn_tl_r1   
#define IANAport_mil_2045_47001     1581			// tcp,MIL_2045_47001   
#define IANAport_msims              1582			// tcp,MSIMS   
#define IANAport_simbaexpress       1583			// tcp,simbaexpress   
#define IANAport_tn_tl_fd2          1584			// tcp,tn_tl_fd2   
#define IANAport_intv               1585			// tcp,intv   
#define IANAport_ibm_abtact         1586			// tcp,ibm_abtact   
#define IANAport_pra_elmd           1587			// tcp,"pra_elmd IANA assigned this well_formed service name as a replacement for ""pra_elmd""."   
#define IANAport_triquest_lm        1588			// tcp,triquest_lm   
#define IANAport_vqp                1589			// tcp,VQP   
#define IANAport_gemini_lm          1590			// tcp,gemini_lm   
#define IANAport_ncpm_pm            1591			// tcp,ncpm_pm   
#define IANAport_commonspace        1592			// tcp,commonspace   
#define IANAport_mainsoft_lm        1593			// tcp,mainsoft_lm   
#define IANAport_sixtrak            1594			// tcp,sixtrak   
#define IANAport_radio              1595			// tcp,radio   
#define IANAport_radio_sm           1596			// tcp,radio_sm   
#define IANAport_radio_bc           1596			// udp,radio_bc   
#define IANAport_orbplus_iiop       1597			// tcp,orbplus_iiop   
#define IANAport_picknfs            1598			// tcp,picknfs   
#define IANAport_simbaservices      1599			// tcp,simbaservices   
#define IANAport_issd               1600			// tcp,issd   
#define IANAport_aas                1601			// tcp,aas   
#define IANAport_inspect            1602			// tcp,inspect   
#define IANAport_picodbc            1603			// tcp,pickodbc   
#define IANAport_icabrowser         1604			// tcp,icabrowser   
#define IANAport_slp                1605			// tcp,Salutation Manager (Salutation Protocol)   
#define IANAport_slm_api            1606			// tcp,Salutation Manager (SLM_API)   
#define IANAport_stt                1607			// tcp,stt   
#define IANAport_smart_lm           1608			// tcp,Smart Corp. License Manager   
#define IANAport_isysg_lm           1609			// tcp,isysg_lm   
#define IANAport_taurus_wh          1610			// tcp,taurus_wh   
#define IANAport_ill                1611			// tcp,Inter Library Loan   
#define IANAport_netbill_trans      1612			// tcp,NetBill Transaction Server   
#define IANAport_netbill_keyrep     1613			// tcp,NetBill Key Repository   
#define IANAport_netbill_cred       1614			// tcp,NetBill Credential Server   
#define IANAport_netbill_auth       1615			// tcp,NetBill Authorization Server   
#define IANAport_netbill_prod       1616			// tcp,NetBill Product Server   
#define IANAport_nimrod_agent       1617			// tcp,Nimrod Inter_Agent Communication   
#define IANAport_skytelnet          1618			// tcp,skytelnet   
#define IANAport_xs_openstorage     1619			// tcp,xs_openstorage   
#define IANAport_faxportwinport     1620			// tcp,faxportwinport   
#define IANAport_softdataphone      1621			// tcp,softdataphone   
#define IANAport_ontime             1622			// tcp,ontime   
#define IANAport_jaleosnd           1623			// tcp,jaleosnd   
#define IANAport_udp_sr_port        1624			// tcp,udp_sr_port   
#define IANAport_svs_omagent        1625			// tcp,svs_omagent   
#define IANAport_shockwave          1626			// tcp,Shockwave   
#define IANAport_t128_gateway       1627			// tcp,T.128 Gateway   
#define IANAport_lontalk_norm       1628			// tcp,LonTalk normal   
#define IANAport_lontalk_urgnt      1629			// tcp,LonTalk urgent   
#define IANAport_oraclenet8cman     1630			// tcp,Oracle Net8 Cman   
#define IANAport_visitview          1631			// tcp,Visit view   
#define IANAport_pammratc           1632			// tcp,PAMMRATC   
#define IANAport_pammrpc            1633			// tcp,PAMMRPC   
#define IANAport_loaprobe           1634			// tcp,Log On America Probe   
#define IANAport_edb_server1        1635			// tcp,EDB Server 1   
#define IANAport_isdc               1636			// tcp,ISP shared public data control   
#define IANAport_islc               1637			// tcp,ISP shared local data control   
#define IANAport_ismc               1638			// tcp,ISP shared management control   
#define IANAport_cert_initiator     1639			// tcp,cert_initiator   
#define IANAport_cert_responder     1640			// tcp,cert_responder   
#define IANAport_invision           1641			// tcp,InVision   
#define IANAport_isis_am            1642			// tcp,isis_am   
#define IANAport_isis_ambc          1643			// tcp,isis_ambc   
#define IANAport_saiseh             1644			// tcp,Satellite_data Acquisition System 4   
#define IANAport_sightline          1645			// tcp,SightLine   
#define IANAport_sa_msg_port        1646			// tcp,sa_msg_port   
#define IANAport_rsap               1647			// tcp,rsap   
#define IANAport_concurrent_lm      1648			// tcp,concurrent_lm   
#define IANAport_kermit             1649			// tcp,kermit   
#define IANAport_nkd                1650			// tcp,nkdn   
#define IANAport_shiva_confsrvr     1651			// tcp,"shiva_confsrvr IANA assigned this well_formed service name as a replacement for ""shiva_confsrvr""."   
#define IANAport_xnmp               1652			// tcp,xnmp   
#define IANAport_alphatech_lm       1653			// tcp,alphatech_lm   
#define IANAport_stargatealerts     1654			// tcp,stargatealerts   
#define IANAport_dec_mbadmin        1655			// tcp,dec_mbadmin   
#define IANAport_dec_mbadmin_h      1656			// tcp,dec_mbadmin_h   
#define IANAport_fujitsu_mmpdc      1657			// tcp,fujitsu_mmpdc   
#define IANAport_sixnetudr          1658			// tcp,sixnetudr   
#define IANAport_sg_lm              1659			// tcp,Silicon Grail License Manager   
#define IANAport_skip_mc_gikreq     1660			// tcp,skip_mc_gikreq   
#define IANAport_netview_aix_1      1661			// tcp,netview_aix_1   
#define IANAport_netview_aix_2      1662			// tcp,netview_aix_2   
#define IANAport_netview_aix_3      1663			// tcp,netview_aix_3   
#define IANAport_netview_aix_4      1664			// tcp,netview_aix_4   
#define IANAport_netview_aix_5      1665			// tcp,netview_aix_5   
#define IANAport_netview_aix_6      1666			// tcp,netview_aix_6   
#define IANAport_netview_aix_7      1667			// tcp,netview_aix_7   
#define IANAport_netview_aix_8      1668			// tcp,netview_aix_8   
#define IANAport_netview_aix_9      1669			// tcp,netview_aix_9   
#define IANAport_netview_aix_10     1670			// tcp,netview_aix_10   
#define IANAport_netview_aix_11     1671			// tcp,netview_aix_11   
#define IANAport_netview_aix_12     1672			// tcp,netview_aix_12   
#define IANAport_proshare_mc_1      1673			// tcp,Intel Proshare Multicast   
#define IANAport_proshare_mc_2      1674			// tcp,Intel Proshare Multicast   
#define IANAport_pdp                1675			// tcp,Pacific Data Products   
#define IANAport_netcomm1           1676			// tcp,netcomm1   
#define IANAport_netcomm2           1676			// udp,netcomm2   
#define IANAport_groupwise          1677			// tcp,groupwise   
#define IANAport_prolink            1678			// tcp,prolink   
#define IANAport_darcorp_lm         1679			// tcp,darcorp_lm   
#define IANAport_microcom_sbp       1680			// tcp,microcom_sbp   
#define IANAport_sd_elmd            1681			// tcp,sd_elmd   
#define IANAport_lanyon_lantern     1682			// tcp,lanyon_lantern   
#define IANAport_ncpm_hip           1683			// tcp,ncpm_hip   
#define IANAport_snaresecure        1684			// tcp,SnareSecure   
#define IANAport_n2nremote          1685			// tcp,n2nremote   
#define IANAport_cvmon              1686			// tcp,cvmon   
#define IANAport_nsjtp_ctrl         1687			// tcp,nsjtp_ctrl   
#define IANAport_nsjtp_data         1688			// tcp,nsjtp_data   
#define IANAport_firefox            1689			// tcp,firefox   
#define IANAport_ng_umds            1690			// tcp,ng_umds   
#define IANAport_empire_empuma      1691			// tcp,empire_empuma   
#define IANAport_sstsys_lm          1692			// tcp,sstsys_lm   
#define IANAport_rrirtr             1693			// tcp,rrirtr   
#define IANAport_rrimwm             1694			// tcp,rrimwm   
#define IANAport_rrilwm             1695			// tcp,rrilwm   
#define IANAport_rrifmm             1696			// tcp,rrifmm   
#define IANAport_rrisat             1697			// tcp,rrisat   
#define IANAport_rsvp_encap_1       1698			// tcp,RSVP_ENCAPSULATION_1   
#define IANAport_rsvp_encap_2       1699			// tcp,RSVP_ENCAPSULATION_2   
#define IANAport_mps_raft           1700			// tcp,mps_raft   
#define IANAport_l2f                1701			// tcp,l2f   
#define IANAport_l2tp               1701			// tcp,l2tp   
#define IANAport_deskshare          1702			// tcp,deskshare   
#define IANAport_hb_engine          1703			// tcp,hb_engine   
#define IANAport_bcs_broker         1704			// tcp,bcs_broker   
#define IANAport_slingshot          1705			// tcp,slingshot   
#define IANAport_jetform            1706			// tcp,jetform   
#define IANAport_vdmplay            1707			// tcp,vdmplay   
#define IANAport_gat_lmd            1708			// tcp,gat_lmd   
#define IANAport_centra             1709			// tcp,centra   
#define IANAport_impera             1710			// tcp,impera   
#define IANAport_pptconference      1711			// tcp,pptconference   
#define IANAport_registrar          1712			// tcp,resource monitoring service   
#define IANAport_conferencetalk     1713			// tcp,ConferenceTalk   
#define IANAport_sesi_lm            1714			// tcp,sesi_lm   
#define IANAport_houdini_lm         1715			// tcp,houdini_lm   
#define IANAport_xmsg               1716			// tcp,xmsg   
#define IANAport_fj_hdnet           1717			// tcp,fj_hdnet   
#define IANAport_h323gatedisc       1718			// tcp,H.323 Multicast Gatekeeper Discover   
#define IANAport_h323gatestat       1719			// tcp,H.323 Unicast Gatekeeper Signaling   
#define IANAport_h323hostcall       1720			// tcp,H.323 Call Control Signalling   
#define IANAport_caicci             1721			// tcp,caicci   
#define IANAport_hks_lm             1722			// tcp,HKS License Manager   
#define IANAport_pptp               1723			// tcp,pptp,[RFC2637]  ,
#define IANAport_csbphonemaster     1724			// tcp,csbphonemaster   
#define IANAport_iden_ralp          1725			// tcp,iden_ralp   
#define IANAport_iberiagames        1726			// tcp,IBERIAGAMES   
#define IANAport_winddx             1727			// tcp,winddx   
#define IANAport_telindus           1728			// tcp,TELINDUS   
#define IANAport_citynl             1729			// tcp,CityNL License Management   
#define IANAport_roketz             1730			// tcp,roketz   
#define IANAport_msiccp             1731			// tcp,MSICCP   
#define IANAport_proxim             1732			// tcp,proxim   
#define IANAport_siipat             1733			// tcp,SIMS _ SIIPAT Protocol for Alarm Transmission   
#define IANAport_cambertx_lm        1734			// tcp,Camber Corporation License Management   
#define IANAport_privatechat        1735			// tcp,PrivateChat   
#define IANAport_street_stream      1736			// tcp,street_stream   
#define IANAport_ultimad            1737			// tcp,ultimad   
#define IANAport_gamegen1           1738			// tcp,GameGen1   
#define IANAport_webaccess          1739			// tcp,webaccess   
#define IANAport_encore             1740			// tcp,encore   
#define IANAport_cisco_net_mgmt     1741			// tcp,cisco_net_mgmt   
#define IANAport_3Com_nsd           1742			// tcp,3Com_nsd   
#define IANAport_cinegrfx_lm        1743			// tcp,Cinema Graphics License Manager   
#define IANAport_ncpm_ft            1744			// tcp,ncpm_ft   
#define IANAport_remote_winsock     1745			// tcp,remote_winsock   
#define IANAport_ftrapid_1          1746			// tcp,ftrapid_1   
#define IANAport_ftrapid_2          1747			// tcp,ftrapid_2   
#define IANAport_oracle_em1         1748			// tcp,oracle_em1   
#define IANAport_aspen_services     1749			// tcp,aspen_services   
#define IANAport_sslp               1750			// tcp,Simple Socket Library's PortMaster   
#define IANAport_swiftnet           1751			// tcp,SwiftNet   
#define IANAport_lofr_lm            1752			// tcp,Leap of Faith Research License Manager   
#define IANAport_predatar_comms     1753			// tcp,Predatar Comms Service   
//#define IANAport_                 1753			// udp,Reserved   
#define IANAport_oracle_em2         1754			// tcp,oracle_em2   
#define IANAport_ms_streaming       1755			// tcp,ms_streaming   
#define IANAport_capfast_lmd        1756			// tcp,capfast_lmd   
#define IANAport_cnhrp              1757			// tcp,cnhrp   
#define IANAport_tftp_mcast         1758			// tcp,tftp_mcast   
#define IANAport_spss_lm            1759			// tcp,SPSS License Manager   
#define IANAport_www_ldap_gw        1760			// tcp,www_ldap_gw   
#define IANAport_cft_0              1761			// tcp,cft_0   
#define IANAport_cft_1              1762			// tcp,cft_1   
#define IANAport_cft_2              1763			// tcp,cft_2   
#define IANAport_cft_3              1764			// tcp,cft_3   
#define IANAport_cft_4              1765			// tcp,cft_4   
#define IANAport_cft_5              1766			// tcp,cft_5   
#define IANAport_cft_6              1767			// tcp,cft_6   
#define IANAport_cft_7              1768			// tcp,cft_7   
#define IANAport_bmc_net_adm        1769			// tcp,bmc_net_adm   
#define IANAport_bmc_net_svc        1770			// tcp,bmc_net_svc   
#define IANAport_vaultbase          1771			// tcp,vaultbase   
#define IANAport_essweb_gw          1772			// tcp,EssWeb Gateway   
#define IANAport_kmscontrol         1773			// tcp,KMSControl   
#define IANAport_global_dtserv      1774			// tcp,global_dtserv   
#define IANAport_vdab               1775			// tcp,data interchange between visual processing containers   
//#define IANAport_                 1775			// udp,Reserved   
#define IANAport_femis              1776			// tcp,Federal Emergency Management Information System   
#define IANAport_powerguardian      1777			// tcp,powerguardian   
#define IANAport_prodigy_intrnet    1778			// tcp,prodigy_internet   
#define IANAport_pharmasoft         1779			// tcp,pharmasoft   
#define IANAport_dpkeyserv          1780			// tcp,dpkeyserv   
#define IANAport_answersoft_lm      1781			// tcp,answersoft_lm   
#define IANAport_hp_hcip            1782			// tcp,hp_hcip   
//#define IANAport_                 1783			// ,"Decomissioned Port 04/14/00, ms"   
#define IANAport_finle_lm           1784			// tcp,Finle License Manager   
#define IANAport_windlm             1785			// tcp,Wind River Systems License Manager   
#define IANAport_funk_logger        1786			// tcp,funk_logger   
#define IANAport_funk_license       1787			// tcp,funk_license   
#define IANAport_psmond             1788			// tcp,psmond   
#define IANAport_hello              1789			// tcp,hello   
#define IANAport_nmsp_nmsp          1790			// tcp,Narrative Media Streaming Protocol - Modified to avoid conflict with line 587 Networked Media Streaming Protocol
#define IANAport_ea1                1791			// tcp,EA1   
#define IANAport_ibm_dt_2           1792			// tcp,ibm_dt_2   
#define IANAport_rsc_robot          1793			// tcp,rsc_robot   
#define IANAport_cera_bcm           1794			// tcp,cera_bcm   
#define IANAport_dpi_proxy          1795			// tcp,dpi_proxy   
#define IANAport_vocaltec_admin     1796			// tcp,Vocaltec Server Administration   
#define IANAport_uma_uma            1797			// tcp,UMA - Modified to avoid conflict with line 258 Universal Management Architecture
#define IANAport_etp                1798			// tcp,Event Transfer Protocol   
#define IANAport_netrisk            1799			// tcp,NETRISK   
#define IANAport_ansys_lm           1800			// tcp,ANSYS_License manager   
#define IANAport_msmq               1801			// tcp,Microsoft Message Que   
#define IANAport_concomp1           1802			// tcp,ConComp1   
#define IANAport_hp_hcip_gwy        1803			// tcp,HP_HCIP_GWY   
#define IANAport_enl                1804			// tcp,ENL   
#define IANAport_enl_name           1805			// tcp,ENL_Name   
#define IANAport_musiconline        1806			// tcp,Musiconline   
#define IANAport_fhsp               1807			// tcp,Fujitsu Hot Standby Protocol   
#define IANAport_oracle_vp2         1808			// tcp,Oracle_VP2   
#define IANAport_oracle_vp1         1809			// tcp,Oracle_VP1   
#define IANAport_jerand_lm          1810			// tcp,Jerand License Manager   
#define IANAport_scientia_sdb       1811			// tcp,Scientia_SDB   
#define IANAport_radius             1812			// tcp,RADIUS,[RFC2865]  ,
#define IANAport_radius_acct        1813			// tcp,RADIUS Accounting,[RFC2866]  ,
#define IANAport_tdp_suite          1814			// tcp,TDP Suite   
#define IANAport_mmpft              1815			// tcp,MMPFT   
#define IANAport_harp               1816			// tcp,HARP   
#define IANAport_rkb_oscs           1817			// tcp,RKB_OSCS   
#define IANAport_etftp              1818			// tcp,Enhanced Trivial File Transfer Protocol   
#define IANAport_plato_lm           1819			// tcp,Plato License Manager   
#define IANAport_mcagent            1820			// tcp,mcagent   
#define IANAport_donnyworld         1821			// tcp,donnyworld   
#define IANAport_es_elmd            1822			// tcp,es_elmd   
#define IANAport_unisys_lm          1823			// tcp,Unisys Natural Language License Manager   
#define IANAport_metrics_pas        1824			// tcp,metrics_pas   
#define IANAport_direcpc_video      1825			// tcp,DirecPC Video   
#define IANAport_ardt               1826			// tcp,ARDT   
#define IANAport_asi                1827			// tcp,ASI   
#define IANAport_itm_mcell_u        1828			// tcp,itm_mcell_u   
#define IANAport_optika_emedia      1829			// tcp,Optika eMedia   
#define IANAport_net8_cman          1830			// tcp,Oracle Net8 CMan Admin   
#define IANAport_myrtle             1831			// tcp,Myrtle   
#define IANAport_tht_treasure       1832			// tcp,ThoughtTreasure   
#define IANAport_udpradio           1833			// tcp,udpradio   
#define IANAport_ardusuni           1834			// tcp,ARDUS Unicast   
#define IANAport_ardusmul           1835			// tcp,ARDUS Multicast   
#define IANAport_ste_smsc           1836			// tcp,ste_smsc   
#define IANAport_csoft1             1837			// tcp,csoft1   
#define IANAport_talnet             1838			// tcp,TALNET   
#define IANAport_netopia_vo1        1839			// tcp,netopia_vo1   
#define IANAport_netopia_vo2        1840			// tcp,netopia_vo2   
#define IANAport_netopia_vo3        1841			// tcp,netopia_vo3   
#define IANAport_netopia_vo4        1842			// tcp,netopia_vo4   
#define IANAport_netopia_vo5        1843			// tcp,netopia_vo5   
#define IANAport_direcpc_dll        1844			// tcp,DirecPC_DLL   
#define IANAport_altalink           1845			// tcp,altalink   
#define IANAport_tunstall_pnc       1846			// tcp,Tunstall PNC   
#define IANAport_slp_notify         1847			// tcp,SLP Notification,[RFC3082]  ,
#define IANAport_fjdocdist          1848			// tcp,fjdocdist   
#define IANAport_alpha_sms          1849			// tcp,ALPHA_SMS   
#define IANAport_gsi                1850			// tcp,GSI   
#define IANAport_ctcd               1851			// tcp,ctcd   
#define IANAport_virtual_time       1852			// tcp,Virtual Time   
#define IANAport_vids_avtp          1853			// tcp,VIDS_AVTP   
#define IANAport_buddy_draw         1854			// tcp,Buddy Draw   
#define IANAport_fiorano_rtrsvc     1855			// tcp,Fiorano RtrSvc   
#define IANAport_fiorano_msgsvc     1856			// tcp,Fiorano MsgSvc   
#define IANAport_datacaptor         1857			// tcp,DataCaptor   
#define IANAport_privateark         1858			// tcp,PrivateArk   
#define IANAport_gammafetchsvr      1859			// tcp,Gamma Fetcher Server   
#define IANAport_sunscalar_svc      1860			// tcp,SunSCALAR Services   
#define IANAport_lecroy_vicp        1861			// tcp,LeCroy VICP   
#define IANAport_mysql_cm_agent     1862			// tcp,MySQL Cluster Manager Agent   
#define IANAport_msnp               1863			// tcp,MSNP   
#define IANAport_paradym_31port     1864			// tcp,Paradym 31 Port   
#define IANAport_entp               1865			// tcp,ENTP   
#define IANAport_swrmi              1866			// tcp,swrmi   
#define IANAport_udrive             1867			// tcp,UDRIVE   
#define IANAport_viziblebrowser     1868			// tcp,VizibleBrowser   
#define IANAport_transact           1869			// tcp,TransAct   
#define IANAport_sunscalar_dns      1870			// tcp,SunSCALAR DNS Service   
#define IANAport_canocentral0       1871			// tcp,Cano Central 0   
#define IANAport_canocentral1       1872			// tcp,Cano Central 1   
#define IANAport_fjmpjps            1873			// tcp,Fjmpjps   
#define IANAport_fjswapsnp          1874			// tcp,Fjswapsnp   
#define IANAport_westell_stats      1875			// tcp,westell stats   
#define IANAport_ewcappsrv          1876			// tcp,ewcappsrv   
#define IANAport_hp_webqosdb        1877			// tcp,hp_webqosdb   
#define IANAport_drmsmc             1878			// tcp,drmsmc   
#define IANAport_nettgain_nms       1879			// tcp,NettGain NMS   
#define IANAport_vsat_control       1880			// tcp,Gilat VSAT Control   
#define IANAport_ibm_mqseries2      1881			// tcp,IBM WebSphere MQ Everyplace   
#define IANAport_ecsqdmn            1882			// tcp,CA eTrust Common Services   
#define IANAport_mqtt               1883			// tcp,Message Queuing Telemetry Transport Protocol   
#define IANAport_idmaps             1884			// tcp,Internet Distance Map Svc   
#define IANAport_vrtstrapserver     1885			// tcp,Veritas Trap Server   
#define IANAport_leoip              1886			// tcp,Leonardo over IP   
#define IANAport_filex_lport        1887			// tcp,FileX Listening Port   
#define IANAport_ncconfig           1888			// tcp,NC Config Port   
#define IANAport_unify_adapter      1889			// tcp,Unify Web Adapter Service   
#define IANAport_wilkenlistener     1890			// tcp,wilkenListener   
#define IANAport_childkey_notif     1891			// tcp,ChildKey Notification   
#define IANAport_childkey_ctrl      1892			// tcp,ChildKey Control   
#define IANAport_elad               1893			// tcp,ELAD Protocol   
#define IANAport_o2server_port      1894			// tcp,O2Server Port   
#define IANAport_b_novative_ls      1896			// tcp,b_novative license server   
#define IANAport_metaagent          1897			// tcp,MetaAgent   
#define IANAport_cymtec_port        1898			// tcp,Cymtec secure management   
#define IANAport_mc2studios         1899			// tcp,MC2Studios   
#define IANAport_ssdp               1900			// tcp,SSDP   
#define IANAport_fjicl_tep_a        1901			// tcp,Fujitsu ICL Terminal Emulator Program A   
#define IANAport_fjicl_tep_b        1902			// tcp,Fujitsu ICL Terminal Emulator Program B   
#define IANAport_linkname           1903			// tcp,Local Link Name Resolution   
#define IANAport_fjicl_tep_c        1904			// tcp,Fujitsu ICL Terminal Emulator Program C   
#define IANAport_sugp               1905			// tcp,Secure UP.Link Gateway Protocol   
#define IANAport_tpmd               1906			// tcp,TPortMapperReq   
#define IANAport_intrastar          1907			// tcp,IntraSTAR   
#define IANAport_dawn               1908			// tcp,Dawn   
#define IANAport_global_wlink       1909			// tcp,Global World Link   
#define IANAport_ultrabac           1910			// tcp,UltraBac Software communications port   
#define IANAport_mtp                1911			// tcp,Starlight Networks Multimedia Transport Protocol   
#define IANAport_rhp_iibp           1912			// tcp,rhp_iibp   
#define IANAport_armadp             1913			// tcp,armadp   
#define IANAport_elm_momentum       1914			// tcp,Elm_Momentum   
#define IANAport_facelink           1915			// tcp,FACELINK   
#define IANAport_persona            1916			// tcp,Persoft Persona   
#define IANAport_noagent            1917			// tcp,nOAgent   
#define IANAport_can_nds            1918			// tcp,IBM Tivole Directory Service _ NDS   
#define IANAport_can_dch            1919			// tcp,IBM Tivoli Directory Service _ DCH   
#define IANAport_can_ferret         1920			// tcp,IBM Tivoli Directory Service _ FERRET   
#define IANAport_noadmin            1921			// tcp,NoAdmin   
#define IANAport_tapestry           1922			// tcp,Tapestry   
#define IANAport_spice              1923			// tcp,SPICE   
#define IANAport_xiip               1924			// tcp,XIIP   
#define IANAport_discovery_port     1925			// tcp,Surrogate Discovery Port   
#define IANAport_egs                1926			// tcp,Evolution Game Server   
#define IANAport_videte_cipc        1927			// tcp,Videte CIPC Port   
#define IANAport_emsd_port          1928			// tcp,Expnd Maui Srvr Dscovr   
#define IANAport_bandwiz_system     1929			// tcp,Bandwiz System _ Server   
#define IANAport_driveappserver     1930			// tcp,Drive AppServer   
#define IANAport_amdsched           1931			// tcp,AMD SCHED   
#define IANAport_ctt_broker         1932			// tcp,CTT Broker   
#define IANAport_xmapi              1933			// tcp,IBM LM MT Agent   
#define IANAport_xaapi              1934			// tcp,IBM LM Appl Agent   
#define IANAport_macromedia_fcs     1935			// tcp,Macromedia Flash Communications Server MX   
#define IANAport_jetcmeserver       1936			// tcp,JetCmeServer Server Port   
#define IANAport_jwserver           1937			// tcp,JetVWay Server Port   
#define IANAport_jwclient           1938			// tcp,JetVWay Client Port   
#define IANAport_jvserver           1939			// tcp,JetVision Server Port   
#define IANAport_jvclient           1940			// tcp,JetVision Client Port   
#define IANAport_dic_aida           1941			// tcp,DIC_Aida   
#define IANAport_res                1942			// tcp,Real Enterprise Service   
#define IANAport_beeyond_media      1943			// tcp,Beeyond Media   
#define IANAport_close_combat       1944			// tcp,close_combat   
#define IANAport_dialogic_elmd      1945			// tcp,dialogic_elmd   
#define IANAport_tekpls             1946			// tcp,tekpls   
#define IANAport_sentinelsrm        1947			// tcp,SentinelSRM   
#define IANAport_eye2eye            1948			// tcp,eye2eye   
#define IANAport_ismaeasdaqlive     1949			// tcp,ISMA Easdaq Live   
#define IANAport_ismaeasdaqtest     1950			// tcp,ISMA Easdaq Test   
#define IANAport_bcs_lmserver       1951			// tcp,bcs_lmserver   
#define IANAport_mpnjsc             1952			// tcp,mpnjsc   
#define IANAport_rapidbase          1953			// tcp,Rapid Base   
#define IANAport_abr_api            1954			// tcp,ABR_API (diskbridge)   
#define IANAport_abr_secure         1955			// tcp,ABR_Secure Data (diskbridge)   
#define IANAport_vrtl_vmf_ds        1956			// tcp,Vertel VMF DS   
#define IANAport_unix_status        1957			// tcp,unix_status   
#define IANAport_dxadmind           1958			// tcp,CA Administration Daemon   
#define IANAport_simp_all           1959			// tcp,SIMP Channel   
#define IANAport_nasmanager         1960			// tcp,Merit DAC NASmanager   
#define IANAport_bts_appserver      1961			// tcp,BTS APPSERVER   
#define IANAport_biap_mp            1962			// tcp,BIAP_MP   
#define IANAport_webmachine         1963			// tcp,WebMachine   
#define IANAport_solid_e_engine     1964			// tcp,SOLID E ENGINE   
#define IANAport_tivoli_npm         1965			// tcp,Tivoli NPM   
#define IANAport_slush              1966			// tcp,Slush   
#define IANAport_sns_quote          1967			// tcp,SNS Quote   
#define IANAport_lipsinc            1968			// tcp,LIPSinc   
#define IANAport_lipsinc1           1969			// tcp,LIPSinc 1   
#define IANAport_netop_rc           1970			// tcp,NetOp Remote Control   
#define IANAport_netop_school       1971			// tcp,NetOp School   
#define IANAport_intersys_cache     1972			// tcp,Cache   
#define IANAport_dlsrap             1973			// tcp,Data Link Switching Remote Access Protocol   
#define IANAport_drp                1974			// tcp,DRP   
#define IANAport_tcoflashagent      1975			// tcp,TCO Flash Agent   
#define IANAport_tcoregagent        1976			// tcp,TCO Reg Agent   
#define IANAport_tcoaddressbook     1977			// tcp,TCO Address Book   
#define IANAport_unisql             1978			// tcp,UniSQL   
#define IANAport_unisql_java        1979			// tcp,UniSQL Java   
#define IANAport_pearldoc_xact      1980			// tcp,PearlDoc XACT   
#define IANAport_p2pq               1981			// tcp,p2pQ   
#define IANAport_estamp             1982			// tcp,Evidentiary Timestamp   
#define IANAport_lhtp               1983			// tcp,Loophole Test Protocol   
#define IANAport_bb                 1984			// tcp,BB   
#define IANAport_hsrp               1985			// tcp,Hot Standby Router Protocol,[RFC2281]  ,
#define IANAport_licensedaemon      1986			// tcp,cisco license management   
#define IANAport_tr_rsrb_p1         1987			// tcp,cisco RSRB Priority 1 port   
#define IANAport_tr_rsrb_p2         1988			// tcp,cisco RSRB Priority 2 port   
#define IANAport_tr_rsrb_p3         1989			// tcp,cisco RSRB Priority 3 port   
#define IANAport_mshnet             1989			// tcp,MHSnet system   
#define IANAport_stun_p1            1990			// tcp,cisco STUN Priority 1 port   
#define IANAport_stun_p2            1991			// tcp,cisco STUN Priority 2 port   
#define IANAport_stun_p3            1992			// tcp,cisco STUN Priority 3 port   
#define IANAport_ipsendmsg          1992			// tcp,IPsendmsg   
#define IANAport_snmp_tcp_port      1993			// tcp,cisco SNMP TCP port   
#define IANAport_stun_port          1994			// tcp,cisco serial tunnel port   
#define IANAport_perf_port          1995			// tcp,cisco perf port   
#define IANAport_tr_rsrb_port       1996			// tcp,cisco Remote SRB port   
#define IANAport_gdp_port           1997			// tcp,cisco Gateway Discovery Protocol   
#define IANAport_x25_svc_port       1998			// tcp,cisco X.25 service (XOT)   
#define IANAport_tcp_id_port        1999			// tcp,cisco identification port   
#define IANAport_cisco_sccp         2000			// tcp,Cisco SCCP   
#define IANAport_dc                 2001			// tcp   ,
#define IANAport_wizard             2001			// udp,curry   
#define IANAport_globe              2002			// tcp   ,
#define IANAport_brutus             2003			// tcp,Brutus Server   
#define IANAport_mailbox            2004			// tcp   ,
#define IANAport_emce               2004			// udp,CCWS mm conf   
#define IANAport_berknet            2005			// tcp   ,
#define IANAport_oracle             2005			// udp   ,
#define IANAport_invokator          2006			// tcp   ,
#define IANAport_raid_cd_1          2006			// udp,raid - Modified to avoid conflict with Line 1916
#define IANAport_dectalk            2007			// tcp   ,
#define IANAport_raid_am_udp        2007			// udp - Modified to avoid conflict with Line 1915 
#define IANAport_conf               2008			// tcp   ,
#define IANAport_terminaldb_udp     2008			// udp - Modified to avoid conflict with Line 1924
#define IANAport_news               2009			// tcp   ,
#define IANAport_whosockami_udp     2009			// udp - Modified to avoid conflict with Line 1926
#define IANAport_search             2010			// tcp   ,
#define IANAport_pipe_server        2010			// udp,"IANA assigned this well_formed service name as a replacement for ""pipe_server""."   
#define IANAport_raid_cc            2011			// tcp,raid   
#define IANAport_servserv           2011			// udp   ,
#define IANAport_ttyinfo            2012			// tcp   ,
#define IANAport_raid_ac            2012			// udp   ,
#define IANAport_raid_am_tcp        2013			// tcp - Modified to avoid conflict with Line 1904
#define IANAport_raid_cd_2          2013			// udp - Modified to avoid conflict with Line 1902
#define IANAport_troff              2014			// tcp   ,
#define IANAport_raid_sf            2014			// udp   ,
#define IANAport_cypress            2015			// tcp   ,
#define IANAport_raid_cs            2015			// udp   ,
#define IANAport_bootserver         2016			// tcp   ,
#define IANAport_cypress_stat       2017			// tcp   ,
#define IANAport_bootclient         2017			// udp   ,
#define IANAport_terminaldb_tcp     2018			// tcp - Modified to avoid conflict with Line 1906
#define IANAport_rellpack           2018			// udp   ,
#define IANAport_whosockami_tcp     2019			// tcp - Modified to avoid conflict with Line 1908
#define IANAport_about              2019			// udp   ,
#define IANAport_xinupageserver     2020			// tcp   ,
#define IANAport_servexec           2021			// tcp   ,
#define IANAport_xinuexpansion1     2021			// udp   ,
#define IANAport_down               2022			// tcp   ,
#define IANAport_xinuexpansion2     2022			// udp   ,
#define IANAport_xinuexpansion3     2023			// tcp   ,
#define IANAport_xinuexpansion4     2024			// tcp   ,
#define IANAport_ellpack            2025			// tcp   ,
#define IANAport_xribs              2025			// udp   ,
#define IANAport_scrabble           2026			// tcp   ,
#define IANAport_shadowserver       2027			// tcp   ,
#define IANAport_submitserver       2028			// tcp   ,
#define IANAport_hsrpv6             2029			// tcp,Hot Standby Router Protocol IPv6   
#define IANAport_device2            2030			// tcp   ,
#define IANAport_mobrien_chat       2031			// tcp,mobrien_chat   
#define IANAport_blackboard         2032			// tcp   ,
#define IANAport_glogger            2033			// tcp   ,
#define IANAport_scoremgr           2034			// tcp   ,
#define IANAport_imsldoc            2035			// tcp   ,
#define IANAport_e_dpnet            2036			// tcp,Ethernet WS DP network   
#define IANAport_applus             2037			// tcp,APplus Application Server   
#define IANAport_objectmanager      2038			// tcp   ,
#define IANAport_prizma             2039			// tcp,Prizma Monitoring Service   
#define IANAport_lam                2040			// tcp   ,
#define IANAport_interbase          2041			// tcp   ,
#define IANAport_isis               2042			// tcp,isis   
#define IANAport_isis_bcast         2043			// tcp,isis_bcast   
#define IANAport_rimsl              2044			// tcp   ,
#define IANAport_cdfunc             2045			// tcp   ,
#define IANAport_sdfunc             2046			// tcp   ,
#define IANAport_dls_1              2047			//  - Modified to avoid conflict with Line 313
#define IANAport_dls_monitor        2048			// tcp   ,
#define IANAport_shilp              2049			// tcp   ,
#define IANAport_nfs                2049			// sctp,Network File System,[RFC5665]  ,
#define IANAport_av_emb_config      2050			// tcp,Avaya EMB Config Port   
#define IANAport_epnsdp             2051			// tcp,EPNSDP   
#define IANAport_clearvisn          2052			// tcp,clearVisn Services Port   
#define IANAport_lot105_ds_upd      2053			// tcp,Lot105 DSuper Updates   
#define IANAport_weblogin           2054			// tcp,Weblogin Port   
#define IANAport_iop                2055			// tcp,Iliad_Odyssey Protocol   
#define IANAport_omnisky            2056			// tcp,OmniSky Port   
#define IANAport_rich_cp            2057			// tcp,Rich Content Protocol   
#define IANAport_newwavesearch      2058			// tcp,NewWaveSearchables RMI   
#define IANAport_bmc_messaging      2059			// tcp,BMC Messaging Service   
#define IANAport_teleniumdaemon     2060			// tcp,Telenium Daemon IF   
#define IANAport_netmount           2061			// tcp,NetMount   
#define IANAport_icg_swp            2062			// tcp,ICG SWP Port   
#define IANAport_icg_bridge         2063			// tcp,ICG Bridge Port   
#define IANAport_icg_iprelay        2064			// tcp,ICG IP Relay Port   
#define IANAport_dlsrpn             2065			// tcp,Data Link Switch Read Port Number   
#define IANAport_aura               2066			// tcp,AVM USB Remote Architecture   
#define IANAport_dlswpn             2067			// tcp,Data Link Switch Write Port Number   
#define IANAport_avauthsrvprtcl     2068			// tcp,Avocent AuthSrv Protocol   
#define IANAport_event_port         2069			// tcp,HTTP Event Port   
#define IANAport_ah_esp_encap       2070			// tcp,AH and ESP Encapsulated in UDP packet   
#define IANAport_acp_port           2071			// tcp,Axon Control Protocol   
#define IANAport_msync              2072			// tcp,GlobeCast mSync   
#define IANAport_gxs_data_port      2073			// tcp,DataReel Database Socket   
#define IANAport_vrtl_vmf_sa        2074			// tcp,Vertel VMF SA   
#define IANAport_newlixengine       2075			// tcp,Newlix ServerWare Engine   
#define IANAport_newlixconfig       2076			// tcp,Newlix JSPConfig   
#define IANAport_tsrmagt            2077			// tcp,Old Tivoli Storage Manager   
#define IANAport_tpcsrvr            2078			// tcp,IBM Total Productivity Center Server   
#define IANAport_idware_router      2079			// tcp,IDWARE Router Port   
#define IANAport_autodesk_nlm       2080			// tcp,Autodesk NLM (FLEXlm)   
#define IANAport_kme_trap_port      2081			// tcp,KME PRINTER TRAP PORT   
#define IANAport_infowave           2082			// tcp,Infowave Mobility Server   
#define IANAport_radsec             2083			// tcp,Secure Radius Service,[RFC6614]  ,
#define IANAport_sunclustergeo      2084			// tcp,SunCluster Geographic   
#define IANAport_ada_cip            2085			// tcp,ADA Control   
#define IANAport_gnunet             2086			// tcp,GNUnet   
#define IANAport_eli                2087			// tcp,ELI _ Event Logging Integration   
#define IANAport_ip_blf             2088			// tcp,IP Busy Lamp Field   
#define IANAport_sep                2089			// tcp,Security Encapsulation Protocol _ SEP   
#define IANAport_lrp                2090			// tcp,Load Report Protocol   
#define IANAport_prp                2091			// tcp,PRP   
#define IANAport_descent3           2092			// tcp,Descent 3   
#define IANAport_nbx_cc             2093			// tcp,NBX CC   
#define IANAport_nbx_au             2094			// tcp,NBX AU   
#define IANAport_nbx_ser            2095			// tcp,NBX SER   
#define IANAport_nbx_dir            2096			// tcp,NBX DIR   
#define IANAport_jetformpreview     2097			// tcp,Jet Form Preview   
#define IANAport_dialog_port        2098			// tcp,Dialog Port   
#define IANAport_h2250_annex_g      2099			// tcp,H.225.0 Annex G Signalling   
#define IANAport_amiganetfs         2100			// tcp,Amiga Network Filesystem   
#define IANAport_rtcm_sc104         2101			// tcp,rtcm_sc104   
#define IANAport_zephyr_srv         2102			// tcp,Zephyr server   
#define IANAport_zephyr_clt         2103			// tcp,Zephyr serv_hm connection   
#define IANAport_zephyr_hm          2104			// tcp,Zephyr hostmanager   
#define IANAport_minipay            2105			// tcp,MiniPay   
#define IANAport_mzap               2106			// tcp,MZAP   
#define IANAport_bintec_admin       2107			// tcp,BinTec Admin   
#define IANAport_comcam             2108			// tcp,Comcam   
#define IANAport_ergolight          2109			// tcp,Ergolight   
#define IANAport_umsp               2110			// tcp,UMSP   
#define IANAport_dsatp              2111			// tcp,OPNET Dynamic Sampling Agent Transaction Protocol   
#define IANAport_idonix_metanet     2112			// tcp,Idonix MetaNet   
#define IANAport_hsl_storm          2113			// tcp,HSL StoRM   
#define IANAport_ariascribe         2114			// tcp,Classical Music Meta_Data Access and Enhancement   
#define IANAport_kdm                2115			// tcp,Key Distribution Manager   
#define IANAport_ccowcmr            2116			// tcp,CCOWCMR   
#define IANAport_mentaclient        2117			// tcp,MENTACLIENT   
#define IANAport_mentaserver        2118			// tcp,MENTASERVER   
#define IANAport_gsigatekeeper      2119			// tcp,GSIGATEKEEPER   
#define IANAport_qencp              2120			// tcp,Quick Eagle Networks CP   
#define IANAport_scientia_ssdb      2121			// tcp,SCIENTIA_SSDB   
#define IANAport_caupc_remote       2122			// tcp,CauPC Remote Control   
#define IANAport_gtp_control        2123			// tcp,GTP_Control Plane (3GPP)   
#define IANAport_elatelink          2124			// tcp,ELATELINK   
#define IANAport_lockstep           2125			// tcp,LOCKSTEP   
#define IANAport_pktcable_cops      2126			// tcp,PktCable_COPS   
#define IANAport_index_pc_wb        2127			// tcp,INDEX_PC_WB   
#define IANAport_net_steward        2128			// tcp,Net Steward Control   
#define IANAport_cs_live            2129			// tcp,cs_live.com   
#define IANAport_xds                2130			// tcp,XDS   
#define IANAport_avantageb2b        2131			// tcp,Avantageb2b   
#define IANAport_solera_epmap       2132			// tcp,SoleraTec End Point Map   
#define IANAport_zymed_zpp          2133			// tcp,ZYMED_ZPP   
#define IANAport_avenue             2134			// tcp,AVENUE   
#define IANAport_gris               2135			// tcp,Grid Resource Information Server   
#define IANAport_appworxsrv         2136			// tcp,APPWORXSRV   
#define IANAport_connect            2137			// tcp,CONNECT   
#define IANAport_unbind_cluster     2138			// tcp,UNBIND_CLUSTER   
#define IANAport_ias_auth           2139			// tcp,IAS_AUTH   
#define IANAport_ias_reg            2140			// tcp,IAS_REG   
#define IANAport_ias_admind         2141			// tcp,IAS_ADMIND   
#define IANAport_tdmoip             2142			// tcp,TDM OVER IP,[RFC5087]  ,
#define IANAport_lv_jc              2143			// tcp,Live Vault Job Control   
#define IANAport_lv_ffx             2144			// tcp,Live Vault Fast Object Transfer   
#define IANAport_lv_pici            2145			// tcp,Live Vault Remote Diagnostic Console Support   
#define IANAport_lv_not             2146			// tcp,Live Vault Admin Event Notification   
#define IANAport_lv_auth            2147			// tcp,Live Vault Authentication   
#define IANAport_veritas_ucl        2148			// tcp,VERITAS UNIVERSAL COMMUNICATION LAYER   
#define IANAport_acptsys            2149			// tcp,ACPTSYS   
#define IANAport_dynamic3d          2150			// tcp,DYNAMIC3D   
#define IANAport_docent             2151			// tcp,DOCENT   
#define IANAport_gtp_user           2152			// tcp,GTP_User Plane (3GPP)   
#define IANAport_ctlptc             2153			// tcp,Control Protocol   
#define IANAport_stdptc             2154			// tcp,Standard Protocol   
#define IANAport_brdptc             2155			// tcp,Bridge Protocol   
#define IANAport_trp                2156			// tcp,Talari Reliable Protocol   
#define IANAport_xnds               2157			// tcp,Xerox Network Document Scan Protocol   
#define IANAport_touchnetplus       2158			// tcp,TouchNetPlus Service   
#define IANAport_gdbremote          2159			// tcp,GDB Remote Debug Port   
#define IANAport_apc_2160           2160			// tcp,APC 2160   
#define IANAport_apc_2161           2161			// tcp,APC 2161   
#define IANAport_navisphere         2162			// tcp,Navisphere   
#define IANAport_navisphere_sec     2163			// tcp,Navisphere Secure   
#define IANAport_ddns_v3            2164			// tcp,Dynamic DNS Version 3   
#define IANAport_x_bone_api         2165			// tcp,X_Bone API   
#define IANAport_iwserver           2166			// tcp,iwserver   
#define IANAport_raw_serial         2167			// tcp,Raw Async Serial Link   
#define IANAport_easy_soft_mux      2168			// tcp,easy_soft Multiplexer   
#define IANAport_brain              2169			// tcp,Backbone for Academic Information Notification (BRAIN)   
#define IANAport_eyetv              2170			// tcp,EyeTV Server Port   
#define IANAport_msfw_storage       2171			// tcp,MS Firewall Storage   
#define IANAport_msfw_s_storage     2172			// tcp,MS Firewall SecureStorage   
#define IANAport_msfw_replica       2173			// tcp,MS Firewall Replication   
#define IANAport_msfw_array         2174			// tcp,MS Firewall Intra Array   
#define IANAport_airsync            2175			// tcp,Microsoft Desktop AirSync Protocol   
#define IANAport_rapi               2176			// tcp,Microsoft ActiveSync Remote API   
#define IANAport_qwave              2177			// tcp,qWAVE Bandwidth Estimate   
#define IANAport_bitspeer           2178			// tcp,Peer Services for BITS   
#define IANAport_vmrdp              2179			// tcp,Microsoft RDP for virtual machines   
#define IANAport_mc_gt_srv          2180			// tcp,Millicent Vendor Gateway Server   
#define IANAport_eforward           2181			// tcp,eforward   
#define IANAport_cgn_stat           2182			// tcp,CGN status   
#define IANAport_cgn_config         2183			// tcp,Code Green configuration   
#define IANAport_nvd_user           2184			// tcp,NVD User  - Modified to avoid conflict with Line 2284
#define IANAport_onbase_dds         2185			// tcp,OnBase Distributed Disk Services   
#define IANAport_gtaua              2186			// tcp,Guy_Tek Automated Update Applications   
#define IANAport_ssmc               2187			// tcp,Sepehr System Management Control   
#define IANAport_ssmd               2187			// udp,Sepehr System Management Data   
#define IANAport_radware_rpm        2188			// tcp,Radware Resource Pool Manager   
//#define IANAport_                 2188			// udp,Reserved   
#define IANAport_radware_rpm_s      2189			// tcp,Secure Radware Resource Pool Manager   
//#define IANAport_                 2189			// udp,Reserved   
#define IANAport_tivoconnect        2190			// tcp,TiVoConnect Beacon   
#define IANAport_tvbus              2191			// tcp,TvBus Messaging   
#define IANAport_asdis              2192			// tcp,ASDIS software management   
#define IANAport_drwcs              2193			// tcp,Dr.Web Enterprise Management Service   
#define IANAport_mnp_exchange       2197			// tcp,MNP data exchange   
#define IANAport_onehome_remote     2198			// tcp,OneHome Remote Access   
#define IANAport_onehome_help       2199			// tcp,OneHome Service Port   
//#define IANAport_                 2200			// tcp,Reserved   
#define IANAport_ats                2201			// tcp,Advanced Training System Program   
#define IANAport_imtc_map           2202			// tcp,Int. Multimedia Teleconferencing Cosortium   
#define IANAport_b2_runtime         2203			// tcp,b2 Runtime Protocol   
#define IANAport_b2_license         2204			// tcp,b2 License Server   
#define IANAport_jps                2205			// tcp,Java Presentation Server   
#define IANAport_hpocbus            2206			// tcp,HP OpenCall bus   
#define IANAport_hpssd              2207			// tcp,HP Status and Services   
#define IANAport_hpiod              2208			// tcp,HP I/O Backend   
#define IANAport_rimf_ps            2209			// tcp,HP RIM for Files Portal Service   
#define IANAport_noaaport           2210			// tcp,NOAAPORT Broadcast Network   
#define IANAport_emwin              2211			// tcp,EMWIN   
#define IANAport_leecoposserver     2212			// tcp,LeeCO POS Server Service   
#define IANAport_kali               2213			// tcp,Kali   
#define IANAport_rpi                2214			// tcp,RDQ Protocol Interface   
#define IANAport_ipcore             2215			// tcp,IPCore.co.za GPRS   
#define IANAport_vtu_comms          2216			// tcp,VTU data service   
#define IANAport_gotodevice         2217			// tcp,GoToDevice Device Management   
#define IANAport_bounzza            2218			// tcp,Bounzza IRC Proxy   
#define IANAport_netiq_ncap         2219			// tcp,NetIQ NCAP Protocol   
#define IANAport_netiq              2220			// tcp,NetIQ End2End   
#define IANAport_ethernet_ip_s      2221			// tcp,EtherNet/IP over TLS   
#define IANAport_EtherNet_IP_1      2222			// tcp,"EtherNet/IP I/O IANA assigned this well_formed service name as a replacement for ""EtherNet/IP_1""."   
#define IANAport_rockwell_csp2      2223			// tcp,Rockwell CSP2   
#define IANAport_efi_mg             2224			// tcp,Easy Flexible Internet/Multiplayer Games   
#define IANAport_rcip_itu           2225			// tcp,Resource Connection Initiation Protocol   
#define IANAport_di_drm             2226			// tcp,Digital Instinct DRM   
#define IANAport_di_msg             2227			// tcp,DI Messaging Service   
#define IANAport_ehome_ms           2228			// tcp,eHome Message Server   
#define IANAport_datalens           2229			// tcp,DataLens Service   
#define IANAport_queueadm           2230			// tcp,MetaSoft Job Queue Administration Service   
#define IANAport_wimaxasncp         2231			// tcp,WiMAX ASN Control Plane Protocol   
#define IANAport_ivs_video          2232			// tcp,IVS Video default   
#define IANAport_infocrypt          2233			// tcp,INFOCRYPT   
#define IANAport_directplay         2234			// tcp,DirectPlay   
#define IANAport_sercomm_wlink      2235			// tcp,Sercomm_WLink   
#define IANAport_nani               2236			// tcp,Nani   
#define IANAport_nani               2236			// udp,Nani   
#define IANAport_optech_port1_lm    2237			// tcp,Optech Port1 License Manager   
#define IANAport_aviva_sna          2238			// tcp,AVIVA SNA SERVER   
#define IANAport_imagequery         2239			// tcp,Image Query   
#define IANAport_recipe             2240			// tcp,RECIPe   
#define IANAport_ivsd               2241			// tcp,IVS Daemon   
#define IANAport_foliocorp          2242			// tcp,Folio Remote Server   
#define IANAport_magicom            2243			// tcp,Magicom Protocol   
#define IANAport_nmsserver          2244			// tcp,NMS Server   
#define IANAport_hao                2245			// tcp,HaO   
#define IANAport_pc_mta_addrmap     2246			// tcp,PacketCable MTA Addr Map   
#define IANAport_antidotemgrsvr     2247			// tcp,Antidote Deployment Manager Service   
#define IANAport_ums                2248			// tcp,User Management Service   
#define IANAport_rfmp               2249			// tcp,RISO File Manager Protocol   
#define IANAport_remote_collab      2250			// tcp,remote_collab   
#define IANAport_dif_port           2251			// tcp,Distributed Framework Port   
#define IANAport_njenet_ssl         2252			// tcp,NJENET using SSL   
#define IANAport_dtv_chan_req       2253			// tcp,DTV Channel Request   
#define IANAport_seispoc            2254			// tcp,Seismic P.O.C. Port   
#define IANAport_vrtp               2255			// tcp,VRTP _ ViRtue Transfer Protocol   
#define IANAport_pcc_mfp            2256			// tcp,PCC MFP   
#define IANAport_simple_tx_rx       2257			// tcp,simple text/file transfer   
#define IANAport_rcts               2258			// tcp,Rotorcraft Communications Test System   
#define IANAport_bid_serv           2259			// tcp,BIF identifiers resolution service   
#define IANAport_apc_2260           2260			// tcp,APC 2260   
#define IANAport_comotionmaster     2261			// tcp,CoMotion Master Server   
#define IANAport_comotionback       2262			// tcp,CoMotion Backup Server   
#define IANAport_ecwcfg             2263			// tcp,ECweb Configuration Service   
#define IANAport_apx500api_1        2264			// tcp,Audio Precision Apx500 API Port 1   
#define IANAport_apx500api_2        2265			// tcp,Audio Precision Apx500 API Port 2   
#define IANAport_mfserver           2266			// tcp,M_Files Server   
#define IANAport_ontobroker         2267			// tcp,OntoBroker   
#define IANAport_amt                2268			// tcp,AMT,[RFC7450]  ,
#define IANAport_mikey              2269			// tcp,MIKEY   
#define IANAport_starschool         2270			// tcp,starSchool   
#define IANAport_mmcals             2271			// tcp,Secure Meeting Maker Scheduling   
#define IANAport_mmcal              2272			// tcp,Meeting Maker Scheduling   
#define IANAport_mysql_im           2273			// tcp,MySQL Instance Manager   
#define IANAport_pcttunnell         2274			// tcp,PCTTunneller   
#define IANAport_ibridge_data       2275			// tcp,iBridge Conferencing   
#define IANAport_ibridge_mgmt       2276			// tcp,iBridge Management   
#define IANAport_bluectrlproxy      2277			// tcp,Bt device control proxy   
#define IANAport_s3db               2278			// tcp,Simple Stacked Sequences Database   
#define IANAport_xmquery            2279			// tcp,xmquery   
#define IANAport_lnvpoller          2280			// tcp,LNVPOLLER   
#define IANAport_lnvconsole         2281			// tcp,LNVCONSOLE   
#define IANAport_lnvalarm           2282			// tcp,LNVALARM   
#define IANAport_lnvstatus          2283			// tcp,LNVSTATUS   
#define IANAport_lnvmaps            2284			// tcp,LNVMAPS   
#define IANAport_lnvmailmon         2285			// tcp,LNVMAILMON   
#define IANAport_nas_metering       2286			// tcp,NAS_Metering   
#define IANAport_dna                2287			// tcp,DNA   
#define IANAport_netml              2288			// tcp,NETML   
#define IANAport_dict_lookup        2289			// tcp,Lookup dict server   
#define IANAport_sonus_logging      2290			// tcp,Sonus Logging Services   
#define IANAport_eapsp              2291			// tcp,EPSON Advanced Printer Share Protocol   
#define IANAport_mib_streaming      2292			// tcp,Sonus Element Management Services   
#define IANAport_npdbgmngr          2293			// tcp,Network Platform Debug Manager   
#define IANAport_konshus_lm         2294			// tcp,Konshus License Manager (FLEX)   
#define IANAport_advant_lm          2295			// tcp,Advant License Manager   
#define IANAport_theta_lm           2296			// tcp,Theta License Manager (Rainbow)   
#define IANAport_d2k_datamover1     2297			// tcp,D2K DataMover 1   
#define IANAport_d2k_datamover2     2298			// tcp,D2K DataMover 2   
#define IANAport_pc_telecommute     2299			// tcp,PC Telecommute   
#define IANAport_cvmmon             2300			// tcp,CVMMON   
#define IANAport_cpq_wbem           2301			// tcp,Compaq HTTP   
#define IANAport_binderysupport     2302			// tcp,Bindery Support   
#define IANAport_proxy_gateway      2303			// tcp,Proxy Gateway   
#define IANAport_attachmate_uts     2304			// tcp,Attachmate UTS   
#define IANAport_mt_scaleserver     2305			// tcp,MT ScaleServer   
#define IANAport_tappi_boxnet       2306			// tcp,TAPPI BoxNet   
#define IANAport_pehelp             2307			// tcp,pehelp   
#define IANAport_sdhelp             2308			// tcp,sdhelp   
#define IANAport_sdserver           2309			// tcp,SD Server   
#define IANAport_sdclient           2310			// tcp,SD Client   
#define IANAport_messageservice     2311			// tcp,Message Service   
#define IANAport_wanscaler          2312			// tcp,WANScaler Communication Service   
#define IANAport_iapp               2313			// tcp,IAPP (Inter Access Point Protocol)   
#define IANAport_cr_websystems      2314			// tcp,CR WebSystems   
#define IANAport_precise_sft        2315			// tcp,Precise Sft.   
#define IANAport_sent_lm            2316			// tcp,SENT License Manager   
#define IANAport_attachmate_g32     2317			// tcp,Attachmate G32   
#define IANAport_cadencecontrol     2318			// tcp,Cadence Control   
#define IANAport_infolibria         2319			// tcp,InfoLibria   
#define IANAport_siebel_ns          2320			// tcp,Siebel NS   
#define IANAport_rdlap              2321			// tcp,RDLAP   
#define IANAport_ofsd               2322			// tcp,ofsd   
#define IANAport_3d_nfsd            2323			// tcp,3d_nfsd   
#define IANAport_cosmocall          2324			// tcp,Cosmocall   
#define IANAport_ansysli            2325			// tcp,ANSYS Licensing Interconnect   
#define IANAport_idcp               2326			// tcp,IDCP   
#define IANAport_xingcsm            2327			// tcp,xingcsm   
#define IANAport_netrix_sftm        2328			// tcp,Netrix SFTM   
#define IANAport_nvd                2329			// tcp,NVD 
#define IANAport_tscchat            2330			// tcp,TSCCHAT   
#define IANAport_agentview          2331			// tcp,AGENTVIEW   
#define IANAport_rcc_host           2332			// tcp,RCC Host   
#define IANAport_snapp              2333			// tcp,SNAPP   
#define IANAport_ace_client         2334			// tcp,ACE Client Auth   
#define IANAport_ace_proxy          2335			// tcp,ACE Proxy   
#define IANAport_appleugcontrol     2336			// tcp,Apple UG Control   
#define IANAport_ideesrv            2337			// tcp,ideesrv   
#define IANAport_norton_lambert     2338			// tcp,Norton Lambert   
#define IANAport_3com_webview       2339			// tcp,3Com WebView   
#define IANAport_wrs_registry       2340			// tcp,"WRS Registry IANA assigned this well_formed service name as a replacement for ""wrs_registry""."   
#define IANAport_xiostatus          2341			// tcp,XIO Status   
#define IANAport_manage_exec        2342			// tcp,Seagate Manage Exec   
#define IANAport_nati_logos         2343			// tcp,nati logos   
#define IANAport_fcmsys             2344			// tcp,fcmsys   
#define IANAport_dbm                2345			// tcp,dbm   
#define IANAport_redstorm_join      2346			// tcp,"Game Connection Port IANA assigned this well_formed service name as a replacement for ""redstorm_join""."   
#define IANAport_redstorm_find      2347			// tcp,"Game Announcement and Location IANA assigned this well_formed service name as a replacement for ""redstorm_find""."   
#define IANAport_redstorm_info      2348			// tcp,"Information to query for game status IANA assigned this well_formed service name as a replacement for ""redstorm_info""."   
#define IANAport_redstorm_diag      2349			// tcp,"Diagnostics Port IANA assigned this well_formed service name as a replacement for ""redstorm_diag""."   
#define IANAport_psbserver          2350			// tcp,Pharos Booking Server   
#define IANAport_psrserver          2351			// tcp,psrserver   
#define IANAport_pslserver          2352			// tcp,pslserver   
#define IANAport_pspserver          2353			// tcp,pspserver   
#define IANAport_psprserver         2354			// tcp,psprserver   
#define IANAport_psdbserver         2355			// tcp,psdbserver   
#define IANAport_gxtelmd            2356			// tcp,GXT License Managemant   
#define IANAport_unihub_server      2357			// tcp,UniHub Server   
#define IANAport_futrix             2358			// tcp,Futrix   
#define IANAport_flukeserver        2359			// tcp,FlukeServer   
#define IANAport_nexstorindltd      2360			// tcp,NexstorIndLtd   
#define IANAport_tl1                2361			// tcp,TL1   
#define IANAport_digiman            2362			// tcp,digiman   
#define IANAport_mediacntrlnfsd     2363			// tcp,Media Central NFSD   
#define IANAport_oi_2000            2364			// tcp,OI_2000   
#define IANAport_dbref              2365			// tcp,dbref   
#define IANAport_qip_login          2366			// tcp,qip_login   
#define IANAport_service_ctrl       2367			// tcp,Service Control   
#define IANAport_opentable          2368			// tcp,OpenTable   
#define IANAport_bif_p2p            2369			// tcp,Blockchain Identifier InFrastructure P2P   
#define IANAport_l3_hbmon           2370			// tcp,L3_HBMon   
#define IANAport_rda_rda            2371			// tcp,Remote Device Access - Modified to avoid conflict with Line 690
//#define IANAport_                 2371			// udp,Reserved   
#define IANAport_lanmessenger       2372			// tcp,LanMessenger   
#define IANAport_remographlm        2373			// tcp,Remograph License Manager   
//#define IANAport_                 2373			// udp,Reserved   
#define IANAport_hydra              2374			// tcp,Hydra RPC   
//#define IANAport_                 2374			// udp,Reserved   
#define IANAport_docker             2375			// tcp,Docker REST API (plain text)   
//#define IANAport_                 2375			// udp,Reserved   
#define IANAport_docker_s           2376			// tcp,Docker REST API (ssl)   
#define IANAport_swarm              2377			// tcp,RPC interface for Docker Swarm   
//#define IANAport_                 2377			// udp,Reserved   
//#define IANAport_                 2378			// tcp,Reserved   
#define IANAport_dali               2378			// udp,DALI lighting control   
#define IANAport_etcd_client        2379			// tcp,etcd client communication   
//#define IANAport_                 2379			// udp,Reserved   
#define IANAport_etcd_server        2380			// tcp,etcd server to server communication   
//#define IANAport_                 2380			// udp,Reserved   
#define IANAport_compaq_https       2381			// tcp,Compaq HTTPS   
#define IANAport_ms_olap3           2382			// tcp,Microsoft OLAP   
#define IANAport_ms_olap4           2383			// tcp,Microsoft OLAP   
#define IANAport_sd_request         2384			// tcp,SD_REQUEST   
#define IANAport_sd_capacity        2384			// udp,SD_CAPACITY   
#define IANAport_sd_data            2385			// tcp,SD_DATA   
#define IANAport_virtualtape        2386			// tcp,Virtual Tape   
#define IANAport_vsamredirector     2387			// tcp,VSAM Redirector   
#define IANAport_mynahautostart     2388			// tcp,MYNAH AutoStart   
#define IANAport_ovsessionmgr       2389			// tcp,OpenView Session Mgr   
#define IANAport_rsmtp              2390			// tcp,RSMTP   
#define IANAport_3com_net_mgmt      2391			// tcp,3COM Net Management   
#define IANAport_tacticalauth       2392			// tcp,Tactical Auth   
#define IANAport_ms_olap1           2393			// tcp,MS OLAP 1   
#define IANAport_ms_olap2           2394			// tcp,MS OLAP 2   
#define IANAport_lan900_remote      2395			// tcp,"LAN900 Remote IANA assigned this well_formed service name as a replacement for ""lan900_remote""."   
#define IANAport_wusage             2396			// tcp,Wusage   
#define IANAport_ncl                2397			// tcp,NCL   
#define IANAport_orbiter            2398			// tcp,Orbiter   
#define IANAport_fmpro_fdal         2399			// tcp,"FileMaker, Inc. _ Data Access Layer"   
#define IANAport_opequus_server     2400			// tcp,OpEquus Server   
#define IANAport_cvspserver         2401			// tcp,cvspserver   
#define IANAport_taskmaster2000svr  2402			// tcp,TaskMaster 2000 Server   
#define IANAport_taskmaster2000web  2403			// tcp,TaskMaster 2000 Web   
#define IANAport_iec_104            2404			// tcp,IEC 60870_5_104 process control over IP   
#define IANAport_trc_netpoll        2405			// tcp,TRC Netpoll   
#define IANAport_jediserver         2406			// tcp,JediServer   
#define IANAport_orion              2407			// tcp,Orion   
#define IANAport_railgun_webaccl    2408			// tcp,CloudFlare Railgun Web Acceleration Protocol   
//#define IANAport_                 2408			// udp,Reserved   
#define IANAport_sns_protocol       2409			// tcp,SNS Protocol   
#define IANAport_vrts_registry      2410			// tcp,VRTS Registry   
#define IANAport_netwave_ap_mgmt    2411			// tcp,Netwave AP Management   
#define IANAport_cdn                2412			// tcp,CDN   
#define IANAport_orion_rmi_reg      2413			// tcp,orion_rmi_reg   
#define IANAport_beeyond            2414			// tcp,Beeyond   
#define IANAport_codima_rtp         2415			// tcp,Codima Remote Transaction Protocol   
#define IANAport_rmtserver          2416			// tcp,RMT Server   
#define IANAport_composit_server    2417			// tcp,Composit Server   
#define IANAport_cas                2418			// tcp,cas   
#define IANAport_attachmate_s2s     2419			// tcp,Attachmate S2S   
#define IANAport_dslremote_mgmt     2420			// tcp,DSL Remote Management   
#define IANAport_g_talk             2421			// tcp,G_Talk   
#define IANAport_crmsbits           2422			// tcp,CRMSBITS   
#define IANAport_rnrp               2423			// tcp,RNRP   
#define IANAport_kofax_svr          2424			// tcp,KOFAX_SVR   
#define IANAport_fjitsuappmgr       2425			// tcp,Fujitsu App Manager   
#define IANAport_vcmp               2426			// tcp,VeloCloud MultiPath Protocol   
#define IANAport_mgcp_gateway       2427			// tcp,Media Gateway Control Protocol Gateway   
#define IANAport_ott                2428			// tcp,One Way Trip Time   
#define IANAport_ft_role            2429			// tcp,FT_ROLE   
#define IANAport_venus              2430			// tcp,venus   
#define IANAport_venus_se           2431			// tcp,venus_se   
#define IANAport_codasrv            2432			// tcp,codasrv   
#define IANAport_codasrv_se         2433			// tcp,codasrv_se   
#define IANAport_pxc_epmap          2434			// tcp,pxc_epmap   
#define IANAport_optilogic          2435			// tcp,OptiLogic   
#define IANAport_topx               2436			// tcp,TOP/X   
#define IANAport_unicontrol_1       2437			// tcp,UniControl   
#define IANAport_msp_new            2438			// tcp,MSP - Modified to avoid conflict with Line 131, replaces historic port
#define IANAport_sybasedbsynch      2439			// tcp,SybaseDBSynch   
#define IANAport_spearway           2440			// tcp,Spearway Lockers   
#define IANAport_pvsw_inet          2441			// tcp,Pervasive I*net Data Server   
#define IANAport_netangel           2442			// tcp,Netangel   
#define IANAport_powerclientcsf     2443			// tcp,PowerClient Central Storage Facility   
#define IANAport_btpp2sectrans      2444			// tcp,BT PP2 Sectrans   
#define IANAport_dtn1               2445			// tcp,DTN1   
#define IANAport_bues_service       2446			// tcp,"bues_service IANA assigned this well_formed service name as a replacement for ""bues_service""."   
#define IANAport_ovwdb              2447			// tcp,OpenView NNM daemon   
#define IANAport_hpppssvr           2448			// tcp,hpppsvr   
#define IANAport_ratl               2449			// tcp,RATL   
#define IANAport_netadmin           2450			// tcp,netadmin   
#define IANAport_netchat            2451			// tcp,netchat   
#define IANAport_snifferclient      2452			// tcp,SnifferClient   
#define IANAport_madge_ltd          2453			// tcp,madge ltd   
#define IANAport_indx_dds           2454			// tcp,IndX_DDS   
#define IANAport_wago_io_system     2455			// tcp,WAGO_IO_SYSTEM   
#define IANAport_altav_remmgt       2456			// tcp,altav_remmgt   
#define IANAport_rapido_ip          2457			// tcp,Rapido_IP   
#define IANAport_griffin            2458			// tcp,griffin   
#define IANAport_xrpl               2459			// tcp,Community   
#define IANAport_ms_theater         2460			// tcp,ms_theater   
#define IANAport_qadmifoper         2461			// tcp,qadmifoper   
#define IANAport_qadmifevent        2462			// tcp,qadmifevent   
#define IANAport_lsi_raid_mgmt      2463			// tcp,LSI RAID Management   
#define IANAport_direcpc_si         2464			// tcp,DirecPC SI   
#define IANAport_lbm                2465			// tcp,Load Balance Management   
#define IANAport_lbf                2466			// tcp,Load Balance Forwarding   
#define IANAport_high_criteria      2467			// tcp,High Criteria   
#define IANAport_qip_msgd           2468			// tcp,qip_msgd   
#define IANAport_mti_tcs_comm       2469			// tcp,MTI_TCS_COMM   
#define IANAport_taskman_port       2470			// tcp,taskman port   
#define IANAport_seaodbc            2471			// tcp,SeaODBC   
#define IANAport_c3                 2472			// tcp,C3   
#define IANAport_aker_cdp           2473			// tcp,Aker_cdp   
#define IANAport_vitalanalysis      2474			// tcp,Vital Analysis   
#define IANAport_ace_server         2475			// tcp,ACE Server   
#define IANAport_ace_svr_prop       2476			// tcp,ACE Server Propagation   
#define IANAport_ssm_cvs            2477			// tcp,SecurSight Certificate Valifation Service   
#define IANAport_ssm_cssps          2478			// tcp,SecurSight Authentication Server (SSL)   
#define IANAport_ssm_els            2479			// tcp,SecurSight Event Logging Server (SSL)   
#define IANAport_powerexchange      2480			// tcp,Informatica PowerExchange Listener   
#define IANAport_giop               2481			// tcp,Oracle GIOP   
#define IANAport_giop_ssl           2482			// tcp,Oracle GIOP SSL   
#define IANAport_ttc                2483			// tcp,Oracle TTC   
#define IANAport_ttc_ssl            2484			// tcp,Oracle TTC SSL   
#define IANAport_netobjects1        2485			// tcp,Net Objects1   
#define IANAport_netobjects2        2486			// tcp,Net Objects2   
#define IANAport_pns                2487			// tcp,Policy Notice Service   
#define IANAport_moy_corp           2488			// tcp,Moy Corporation   
#define IANAport_tsilb              2489			// tcp,TSILB   
#define IANAport_qip_qdhcp          2490			// tcp,qip_qdhcp   
#define IANAport_conclave_cpp       2491			// tcp,Conclave CPP   
#define IANAport_groove             2492			// tcp,GROOVE   
#define IANAport_talarian_mqs       2493			// tcp,Talarian MQS   
#define IANAport_bmc_ar             2494			// tcp,BMC AR   
#define IANAport_fast_rem_serv      2495			// tcp,Fast Remote Services   
#define IANAport_dirgis             2496			// tcp,DIRGIS   
#define IANAport_quaddb             2497			// tcp,Quad DB   
#define IANAport_odn_castraq        2498			// tcp,ODN_CasTraq   
#define IANAport_unicontrol_2       2499			// tcp,UniControl   
#define IANAport_rtsserv            2500			// tcp,Resource Tracking system server   
#define IANAport_rtsclient          2501			// tcp,Resource Tracking system client   
#define IANAport_kentrox_prot       2502			// tcp,Kentrox Protocol   
#define IANAport_nms_dpnss          2503			// tcp,NMS_DPNSS   
#define IANAport_wlbs               2504			// tcp,WLBS   
#define IANAport_ppcontrol          2505			// tcp,PowerPlay Control   
#define IANAport_jbroker            2506			// tcp,jbroker   
#define IANAport_spock              2507			// tcp,spock   
#define IANAport_jdatastore         2508			// tcp,JDataStore   
#define IANAport_fjmpss             2509			// tcp,fjmpss   
#define IANAport_fjappmgrbulk       2510			// tcp,fjappmgrbulk   
#define IANAport_metastorm          2511			// tcp,Metastorm   
#define IANAport_citrixima          2512			// tcp,Citrix IMA   
#define IANAport_citrixadmin        2513			// tcp,Citrix ADMIN   
#define IANAport_facsys_ntp         2514			// tcp,Facsys NTP   
#define IANAport_facsys_router      2515			// tcp,Facsys Router   
#define IANAport_maincontrol        2516			// tcp,Main Control   
#define IANAport_call_sig_trans     2517			// tcp,H.323 Annex E Call Control Signalling Transport   
#define IANAport_willy              2518			// tcp,Willy   
#define IANAport_globmsgsvc         2519			// tcp,globmsgsvc   
#define IANAport_pvsw               2520			// tcp,Pervasive Listener   
#define IANAport_adaptecmgr         2521			// tcp,Adaptec Manager   
#define IANAport_windb              2522			// tcp,WinDb   
#define IANAport_qke_llc_v3         2523			// tcp,Qke LLC V.3   
#define IANAport_optiwave_lm        2524			// tcp,Optiwave License Management   
#define IANAport_ms_v_worlds        2525			// tcp,MS V_Worlds   
#define IANAport_ema_sent_lm        2526			// tcp,EMA License Manager   
#define IANAport_iqserver           2527			// tcp,IQ Server   
#define IANAport_ncr_ccl            2528			// tcp,"NCR CCL IANA assigned this well_formed service name as a replacement for ""ncr_ccl""."   
#define IANAport_ncr_ccl            2528			// udp,"NCR CCL IANA assigned this well_formed service name as a replacement for ""ncr_ccl""."   
#define IANAport_utsftp             2529			// tcp,UTS FTP   
#define IANAport_vrcommerce         2530			// tcp,VR Commerce   
#define IANAport_ito_e_gui          2531			// tcp,ITO_E GUI   
#define IANAport_ovtopmd            2532			// tcp,OVTOPMD   
#define IANAport_snifferserver      2533			// tcp,SnifferServer   
#define IANAport_combox_web_acc     2534			// tcp,Combox Web Access   
#define IANAport_madcap             2535			// tcp,MADCAP   
#define IANAport_btpp2audctr1       2536			// tcp,btpp2audctr1   
#define IANAport_upgrade            2537			// tcp,Upgrade Protocol   
#define IANAport_vnwk_prapi         2538			// tcp,vnwk_prapi   
#define IANAport_vsiadmin           2539			// udp,VSI Admin   
#define IANAport_lonworks           2540			// tcp,LonWorks   
#define IANAport_lonworks2          2541			// tcp,LonWorks2   
#define IANAport_udrawgraph         2542			// tcp,uDraw(Graph)   
#define IANAport_reftek             2543			// tcp,REFTEK   
#define IANAport_novell_zen         2544			// tcp,Management Daemon Refresh   
#define IANAport_sis_emt            2545			// tcp,sis_emt   
#define IANAport_vytalvaultbrtp     2546			// tcp,vytalvaultbrtp   
#define IANAport_vytalvaultvsmp     2547			// tcp,vytalvaultvsmp   
#define IANAport_vytalvaultpipe     2548			// tcp,vytalvaultpipe   
#define IANAport_ipass              2549			// tcp,IPASS   
#define IANAport_ads                2550			// tcp,ADS   
#define IANAport_isg_uda_server     2551			// tcp,ISG UDA Server   
#define IANAport_call_logging       2552			// tcp,Call Logging   
#define IANAport_efidiningport      2553			// tcp,efidiningport   
#define IANAport_vcnet_link_v10     2554			// tcp,VCnet_Link v10   
#define IANAport_compaq_wcp         2555			// tcp,Compaq WCP   
#define IANAport_nicetec_nmsvc      2556			// tcp,nicetec_nmsvc   
#define IANAport_nicetec_mgmt       2557			// tcp,nicetec_mgmt   
#define IANAport_pclemultimedia     2558			// tcp,PCLE Multi Media   
#define IANAport_lstp               2559			// tcp,LSTP   
#define IANAport_labrat             2560			// tcp,labrat   
#define IANAport_mosaixcc           2561			// tcp,MosaixCC   
#define IANAport_delibo             2562			// tcp,Delibo   
#define IANAport_cti_redwood        2563			// tcp,CTI Redwood   
#define IANAport_hp_3000_telnet     2564			// tcp,HP 3000 NS/VT block mode telnet   
#define IANAport_coord_svr          2565			// tcp,Coordinator Server   
#define IANAport_pcs_pcw            2566			// tcp,pcs_pcw   
#define IANAport_clp                2567			// tcp,Cisco Line Protocol   
#define IANAport_spamtrap           2568			// tcp,SPAM TRAP   
#define IANAport_sonuscallsig       2569			// tcp,Sonus Call Signal   
#define IANAport_hs_port            2570			// tcp,HS Port   
#define IANAport_cecsvc             2571			// tcp,CECSVC   
#define IANAport_ibp                2572			// tcp,IBP   
#define IANAport_trustestablish     2573			// tcp,Trust Establish   
#define IANAport_blockade_bpsp      2574			// tcp,Blockade BPSP   
#define IANAport_hl7                2575			// tcp,HL7   
#define IANAport_tclprodebugger     2576			// tcp,TCL Pro Debugger   
#define IANAport_scipticslsrvr      2577			// tcp,Scriptics Lsrvr   
#define IANAport_rvs_isdn_dcp       2578			// tcp,RVS ISDN DCP   
#define IANAport_mpfoncl            2579			// tcp,mpfoncl   
#define IANAport_tributary          2580			// tcp,Tributary   
#define IANAport_argis_te           2581			// tcp,ARGIS TE   
#define IANAport_argis_ds           2582			// tcp,ARGIS DS   
#define IANAport_mon_1              2583			// tcp,MON - Note amended
#define IANAport_cyaserv            2584			// tcp,cyaserv   
#define IANAport_netx_server        2585			// tcp,NETX Server   
#define IANAport_netx_agent         2586			// tcp,NETX Agent   
#define IANAport_masc               2587			// tcp,MASC   
#define IANAport_privilege          2588			// tcp,Privilege   
#define IANAport_quartus_tcl        2589			// tcp,quartus tcl   
#define IANAport_idotdist           2590			// tcp,idotdist   
#define IANAport_maytagshuffle      2591			// tcp,Maytag Shuffle   
#define IANAport_netrek             2592			// tcp,netrek   
#define IANAport_mns_mail           2593			// tcp,MNS Mail Notice Service   
#define IANAport_dts                2594			// tcp,Data Base Server   
#define IANAport_worldfusion1       2595			// tcp,World Fusion 1   
#define IANAport_worldfusion2       2596			// tcp,World Fusion 2   
#define IANAport_homesteadglory     2597			// tcp,Homestead Glory   
#define IANAport_citriximaclient    2598			// tcp,Citrix MA Client   
#define IANAport_snapd              2599			// tcp,Snap Discovery   
#define IANAport_hpstgmgr           2600			// tcp,HPSTGMGR   
#define IANAport_discp_client       2601			// tcp,discp client   
#define IANAport_discp_server       2602			// tcp,discp server   
#define IANAport_servicemeter       2603			// tcp,Service Meter   
#define IANAport_nsc_ccs            2604			// tcp,NSC CCS   
#define IANAport_nsc_posa           2605			// tcp,NSC POSA   
#define IANAport_netmon             2606			// tcp,Dell Netmon   
#define IANAport_connection         2607			// tcp,Dell Connection   
#define IANAport_wag_service        2608			// tcp,Wag Service   
#define IANAport_system_monitor     2609			// tcp,System Monitor   
#define IANAport_versa_tek          2610			// tcp,VersaTek   
#define IANAport_lionhead           2611			// tcp,LIONHEAD   
#define IANAport_qpasa_agent        2612			// tcp,Qpasa Agent   
#define IANAport_smntubootstrap     2613			// tcp,SMNTUBootstrap   
#define IANAport_neveroffline       2614			// tcp,Never Offline   
#define IANAport_firepower          2615			// tcp,firepower   
#define IANAport_appswitch_emp      2616			// tcp,appswitch_emp   
#define IANAport_cmadmin            2617			// tcp,Clinical Context Managers   
#define IANAport_priority_e_com     2618			// tcp,Priority E_Com   
#define IANAport_bruce              2619			// tcp,bruce   
#define IANAport_lpsrecommender     2620			// tcp,LPSRecommender   
#define IANAport_miles_apart        2621			// tcp,Miles Apart Jukebox Server   
#define IANAport_metricadbc         2622			// tcp,MetricaDBC   
#define IANAport_lmdp               2623			// tcp,LMDP   
#define IANAport_aria               2624			// tcp,Aria   
#define IANAport_blwnkl_port        2625			// tcp,Blwnkl Port   
#define IANAport_gbjd816            2626			// tcp,gbjd816   
#define IANAport_moshebeeri         2627			// tcp,Moshe Beeri   
#define IANAport_dict               2628			// tcp,DICT   
#define IANAport_sitaraserver       2629			// tcp,Sitara Server   
#define IANAport_sitaramgmt         2630			// tcp,Sitara Management   
#define IANAport_sitaradir          2631			// tcp,Sitara Dir   
#define IANAport_irdg_post          2632			// tcp,IRdg Post   
#define IANAport_interintelli       2633			// tcp,InterIntelli   
#define IANAport_pk_electronics     2634			// tcp,PK Electronics   
#define IANAport_backburner         2635			// tcp,Back Burner   
#define IANAport_solve              2636			// tcp,Solve   
#define IANAport_imdocsvc           2637			// tcp,Import Document Service   
#define IANAport_sybaseanywhere     2638			// tcp,Sybase Anywhere   
#define IANAport_aminet             2639			// tcp,AMInet   
#define IANAport_ami_control        2640			// tcp,Alcorn McBride Inc protocol used for device control   
#define IANAport_hdl_srv            2641			// tcp,HDL Server   
#define IANAport_tragic             2642			// tcp,Tragic   
#define IANAport_gte_samp           2643			// tcp,GTE_SAMP   
#define IANAport_travsoft_ipx_t     2644			// tcp,Travsoft IPX Tunnel   
#define IANAport_novell_ipx_cmd     2645			// tcp,Novell IPX CMD   
#define IANAport_and_lm             2646			// tcp,AND License Manager   
#define IANAport_syncserver         2647			// tcp,SyncServer   
#define IANAport_upsnotifyprot      2648			// tcp,Upsnotifyprot   
#define IANAport_vpsipport          2649			// tcp,VPSIPPORT   
#define IANAport_eristwoguns        2650			// tcp,eristwoguns   
#define IANAport_ebinsite           2651			// tcp,EBInSite   
#define IANAport_interpathpanel     2652			// tcp,InterPathPanel   
#define IANAport_sonus              2653			// tcp,Sonus   
#define IANAport_corel_vncadmin     2654			// tcp,"Corel VNC Admin IANA assigned this well_formed service name as a replacement for ""corel_vncadmin""."   
#define IANAport_unglue             2655			// tcp,UNIX Nt Glue   
#define IANAport_kana               2656			// tcp,Kana   
#define IANAport_sns_dispatcher     2657			// tcp,SNS Dispatcher   
#define IANAport_sns_admin          2658			// tcp,SNS Admin   
#define IANAport_sns_query          2659			// tcp,SNS Query   
#define IANAport_gcmonitor          2660			// tcp,GC Monitor   
#define IANAport_olhost             2661			// tcp,OLHOST   
#define IANAport_bintec_capi        2662			// tcp,BinTec_CAPI   
#define IANAport_bintec_tapi        2663			// tcp,BinTec_TAPI   
#define IANAport_patrol_mq_gm       2664			// tcp,Patrol for MQ GM   
#define IANAport_patrol_mq_nm       2665			// tcp,Patrol for MQ NM   
#define IANAport_extensis           2666			// tcp,extensis   
#define IANAport_alarm_clock_s      2667			// tcp,Alarm Clock Server   
#define IANAport_alarm_clock_c      2668			// tcp,Alarm Clock Client   
#define IANAport_toad               2669			// tcp,TOAD   
#define IANAport_tve_announce       2670			// tcp,TVE Announce   
#define IANAport_newlixreg          2671			// tcp,newlixreg   
#define IANAport_nhserver           2672			// tcp,nhserver   
#define IANAport_firstcall42        2673			// tcp,First Call 42   
#define IANAport_ewnn               2674			// tcp,ewnn   
#define IANAport_ttc_etap           2675			// tcp,TTC ETAP   
#define IANAport_simslink           2676			// tcp,SIMSLink   
#define IANAport_gadgetgate1way     2677			// tcp,Gadget Gate 1 Way   
#define IANAport_gadgetgate2way     2678			// tcp,Gadget Gate 2 Way   
#define IANAport_syncserverssl      2679			// tcp,Sync Server SSL   
#define IANAport_pxc_sapxom         2680			// tcp,pxc_sapxom   
#define IANAport_mpnjsomb           2681			// tcp,mpnjsomb   
//#define IANAport_                 2682			// ,Removed   
#define IANAport_ncdloadbalance     2683			// tcp,NCDLoadBalance   
#define IANAport_mpnjsosv           2684			// tcp,mpnjsosv   
#define IANAport_mpnjsocl           2685			// tcp,mpnjsocl   
#define IANAport_mpnjsomg           2686			// tcp,mpnjsomg   
#define IANAport_pq_lic_mgmt        2687			// tcp,pq_lic_mgmt   
#define IANAport_md_cg_http         2688			// tcp,md_cf_http   
#define IANAport_fastlynx           2689			// tcp,FastLynx   
#define IANAport_hp_nnm_data        2690			// tcp,HP NNM Embedded Database   
#define IANAport_itinternet         2691			// tcp,ITInternet ISM Server   
#define IANAport_admins_lms         2692			// tcp,Admins LMS   
#define IANAport_pwrsevent          2694			// tcp,pwrsevent   
#define IANAport_vspread            2695			// tcp,VSPREAD   
#define IANAport_unifyadmin         2696			// tcp,Unify Admin   
#define IANAport_oce_snmp_trap      2697			// tcp,Oce SNMP Trap Port   
#define IANAport_mck_ivpip          2698			// tcp,MCK_IVPIP   
#define IANAport_csoft_plusclnt     2699			// tcp,Csoft Plus Client   
#define IANAport_tqdata             2700			// tcp,tqdata   
#define IANAport_sms_rcinfo         2701			// tcp,SMS RCINFO   
#define IANAport_sms_xfer           2702			// tcp,SMS XFER   
#define IANAport_sms_chat           2703			// tcp,SMS CHAT   
#define IANAport_sms_remctrl        2704			// tcp,SMS REMCTRL   
#define IANAport_sds_admin          2705			// tcp,SDS Admin   
#define IANAport_ncdmirroring       2706			// tcp,NCD Mirroring   
#define IANAport_emcsymapiport      2707			// tcp,EMCSYMAPIPORT   
#define IANAport_banyan_net         2708			// tcp,Banyan_Net   
#define IANAport_supermon           2709			// tcp,Supermon   
#define IANAport_sso_service        2710			// tcp,SSO Service   
#define IANAport_sso_control        2711			// tcp,SSO Control   
#define IANAport_aocp               2712			// tcp,Axapta Object Communication Protocol   
#define IANAport_raventbs           2713			// tcp,Raven Trinity Broker Service   
#define IANAport_raventdm           2714			// tcp,Raven Trinity Data Mover   
#define IANAport_hpstgmgr2          2715			// tcp,HPSTGMGR2   
#define IANAport_inova_ip_disco     2716			// tcp,Inova IP Disco   
#define IANAport_pn_requester       2717			// tcp,PN REQUESTER   
#define IANAport_pn_requester2      2718			// tcp,PN REQUESTER 2   
#define IANAport_scan_change        2719			// tcp,Scan & Change   
#define IANAport_wkars              2720			// tcp,wkars   
#define IANAport_smart_diagnose     2721			// tcp,Smart Diagnose   
#define IANAport_proactivesrvr      2722			// tcp,Proactive Server   
#define IANAport_watchdog_nt        2723			// tcp,WatchDog NT Protocol   
#define IANAport_qotps              2724			// tcp,qotps   
#define IANAport_msolap_ptp2        2725			// tcp,MSOLAP PTP2   
#define IANAport_tams               2726			// tcp,TAMS   
#define IANAport_mgcp_callagent     2727			// tcp,Media Gateway Control Protocol Call Agent   
#define IANAport_sqdr               2728			// tcp,SQDR   
#define IANAport_tcim_control       2729			// tcp,TCIM Control   
#define IANAport_nec_raidplus       2730			// tcp,NEC RaidPlus   
#define IANAport_fyre_messanger     2731			// tcp,Fyre Messanger   
#define IANAport_g5m                2732			// tcp,G5M   
#define IANAport_signet_ctf         2733			// tcp,Signet CTF   
#define IANAport_ccs_software       2734			// tcp,CCS Software   
#define IANAport_netiq_mc           2735			// tcp,NetIQ Monitor Console   
#define IANAport_radwiz_nms_srv     2736			// tcp,RADWIZ NMS SRV   
#define IANAport_srp_feedback       2737			// tcp,SRP Feedback   
#define IANAport_ndl_tcp_ois_gw     2738			// tcp,NDL TCP_OSI Gateway   
#define IANAport_tn_timing          2739			// tcp,TN Timing   
#define IANAport_alarm              2740			// tcp,Alarm   
#define IANAport_tsb                2741			// tcp,TSB   
#define IANAport_tsb2               2742			// tcp,TSB2   
#define IANAport_murx               2743			// tcp,murx   
#define IANAport_honyaku            2744			// tcp,honyaku   
#define IANAport_urbisnet           2745			// tcp,URBISNET   
#define IANAport_cpudpencap         2746			// tcp,CPUDPENCAP   
#define IANAport_fjippol_swrly      2747			// tcp   ,
#define IANAport_fjippol_polsvr     2748			// tcp   ,
#define IANAport_fjippol_cnsl       2749			// tcp   ,
#define IANAport_fjippol_port1      2750			// tcp   ,
#define IANAport_fjippol_port2      2751			// tcp   ,
#define IANAport_rsisysaccess       2752			// tcp,RSISYS ACCESS   
#define IANAport_de_spot            2753			// tcp,de_spot   
#define IANAport_apollo_cc          2754			// tcp,APOLLO CC   
#define IANAport_expresspay         2755			// tcp,Express Pay   
#define IANAport_simplement_tie     2756			// tcp,simplement_tie   
#define IANAport_cnrp               2757			// tcp,CNRP   
#define IANAport_apollo_status      2758			// tcp,APOLLO Status   
#define IANAport_apollo_gms         2759			// tcp,APOLLO GMS   
#define IANAport_sabams             2760			// tcp,Saba MS   
#define IANAport_dicom_iscl         2761			// tcp,DICOM ISCL   
#define IANAport_dicom_tls          2762			// tcp,DICOM TLS   
#define IANAport_desktop_dna        2763			// tcp,Desktop DNA   
#define IANAport_data_insurance     2764			// tcp,Data Insurance   
#define IANAport_qip_audup          2765			// tcp,qip_audup   
#define IANAport_compaq_scp         2766			// tcp,Compaq SCP   
#define IANAport_uadtc              2767			// tcp,UADTC   
#define IANAport_uacs               2768			// tcp,UACS   
#define IANAport_exce               2769			// tcp,eXcE   
#define IANAport_veronica           2770			// tcp,Veronica   
#define IANAport_vergencecm         2771			// tcp,Vergence CM   
#define IANAport_auris              2772			// tcp,auris   
#define IANAport_rbakcup1           2773			// tcp,RBackup Remote Backup   
#define IANAport_rbakcup2           2774			// tcp,RBackup Remote Backup   
#define IANAport_smpp               2775			// tcp,SMPP   
#define IANAport_ridgeway1          2776			// tcp,Ridgeway Systems & Software   
#define IANAport_ridgeway2          2777			// tcp,Ridgeway Systems & Software   
#define IANAport_gwen_sonya         2778			// tcp,Gwen_Sonya   
#define IANAport_lbc_sync           2779			// tcp,LBC Sync   
#define IANAport_lbc_control        2780			// tcp,LBC Control   
#define IANAport_whosells           2781			// tcp,whosells   
#define IANAport_everydayrc         2782			// tcp,everydayrc   
#define IANAport_aises              2783			// tcp,AISES   
#define IANAport_www_dev            2784			// tcp,world wide web _ development   
#define IANAport_aic_np             2785			// tcp,aic_np   
#define IANAport_aic_oncrpc         2786			// tcp,aic_oncrpc _ Destiny MCD database   
#define IANAport_piccolo            2787			// tcp,piccolo _ Cornerstone Software   
#define IANAport_fryeserv           2788			// tcp,NetWare Loadable Module _ Seagate Software   
#define IANAport_media_agent        2789			// tcp,Media Agent   
#define IANAport_plgproxy           2790			// tcp,PLG Proxy   
#define IANAport_mtport_regist      2791			// tcp,MT Port Registrator   
#define IANAport_f5_globalsite      2792			// tcp,f5_globalsite   
#define IANAport_initlsmsad         2793			// udp,initlsmsad   
#define IANAport_livestats          2795			// tcp,LiveStats   
#define IANAport_ac_tech            2796			// tcp,ac_tech   
#define IANAport_esp_encap          2797			// tcp,esp_encap   
#define IANAport_tmesis_upshot      2798			// tcp,TMESIS_UPShot   
#define IANAport_icon_discover      2799			// tcp,ICON Discover   
#define IANAport_acc_raid           2800			// tcp,ACC RAID   
#define IANAport_igcp               2801			// tcp,IGCP   
#define IANAport_veritas_tcp1       2802			// tcp,Veritas TCP1   
#define IANAport_btprjctrl          2803			// tcp,btprjctrl   
#define IANAport_dvr_esm            2804			// tcp,March Networks Digital Video Recorders and Enterprise Service Manager products   
#define IANAport_wta_wsp_s          2805			// tcp,WTA WSP_S   
#define IANAport_cspuni             2806			// tcp,cspuni   
#define IANAport_cspmulti           2807			// tcp,cspmulti   
#define IANAport_j_lan_p            2808			// tcp,J_LAN_P   
#define IANAport_corbaloc           2809			// tcp,CORBA LOC   
#define IANAport_netsteward         2810			// tcp,Active Net Steward   
#define IANAport_gsiftp             2811			// tcp,GSI FTP   
#define IANAport_atmtcp             2812			// tcp,atmtcp   
#define IANAport_llm_pass           2813			// tcp,llm_pass   
#define IANAport_llm_csv            2814			// tcp,llm_csv   
#define IANAport_lbc_measure        2815			// tcp,LBC Measurement   
#define IANAport_lbc_watchdog       2816			// tcp,LBC Watchdog   
#define IANAport_nmsigport_1        2817			// tcp,NMSig Port   
#define IANAport_rmlnk              2818			// tcp,rmlnk   
#define IANAport_fc_faultnotify     2819			// tcp,FC Fault Notification   
#define IANAport_univision          2820			// tcp,UniVision   
#define IANAport_vrts_at_port       2821			// tcp,VERITAS Authentication Service   
#define IANAport_ka0wuc             2822			// tcp,ka0wuc   
#define IANAport_cqg_netlan         2823			// tcp,CQG Net/LAN   
#define IANAport_cqg_netlan_1       2824			// tcp,CQG Net/LAN 1   
#define IANAport_slc_systemlog      2826			// tcp,slc systemlog   
#define IANAport_slc_ctrlrloops     2827			// tcp,slc ctrlrloops   
#define IANAport_itm_lm             2828			// tcp,ITM License Manager   
#define IANAport_silkp1             2829			// tcp,silkp1   
#define IANAport_silkp2             2830			// tcp,silkp2   
#define IANAport_silkp3             2831			// tcp,silkp3   
#define IANAport_silkp4             2832			// tcp,silkp4   
#define IANAport_glishd             2833			// tcp,glishd   
#define IANAport_evtp               2834			// tcp,EVTP   
#define IANAport_evtp_data          2835			// tcp,EVTP_DATA   
#define IANAport_catalyst           2836			// tcp,catalyst   
#define IANAport_repliweb           2837			// tcp,Repliweb   
#define IANAport_starbot            2838			// tcp,Starbot   
#define IANAport_nmsigport_2        2839			// tcp,NMSigPort   
#define IANAport_l3_exprt           2840			// tcp,l3_exprt   
#define IANAport_l3_ranger          2841			// tcp,l3_ranger   
#define IANAport_l3_hawk            2842			// tcp,l3_hawk   
#define IANAport_pdnet              2843			// tcp,PDnet   
#define IANAport_bpcp_poll          2844			// tcp,BPCP POLL   
#define IANAport_bpcp_trap          2845			// tcp,BPCP TRAP   
#define IANAport_aimpp_hello        2846			// tcp,AIMPP Hello   
#define IANAport_aimpp_port_req     2847			// tcp,AIMPP Port Req   
#define IANAport_amt_blc_port       2848			// tcp,AMT_BLC_PORT   
#define IANAport_fxp_2              2849			// tcp,FXP   
#define IANAport_metaconsole        2850			// tcp,MetaConsole   
#define IANAport_webemshttp         2851			// tcp,webemshttp   
#define IANAport_bears_01           2852			// tcp,bears_01   
#define IANAport_ispipes            2853			// tcp,ISPipes   
#define IANAport_infomover          2854			// tcp,InfoMover   
#define IANAport_msrp               2855			// tcp,MSRP over TCP,[RFC4976]  ,
//#define IANAport_                 2855			// udp,Reserved   
#define IANAport_cesdinv            2856			// tcp,cesdinv   
#define IANAport_simctlp            2857			// tcp,SimCtIP   
#define IANAport_ecnp               2858			// tcp,ECNP   
#define IANAport_activememory       2859			// tcp,Active Memory   
#define IANAport_dialpad_voice1     2860			// tcp,Dialpad Voice 1   
#define IANAport_dialpad_voice2     2861			// tcp,Dialpad Voice 2   
#define IANAport_ttg_protocol       2862			// tcp,TTG Protocol   
#define IANAport_sonardata          2863			// tcp,Sonar Data   
#define IANAport_astronova_main     2864			// tcp,main 5001 cmd   
#define IANAport_pit_vpn            2865			// tcp,pit_vpn   
#define IANAport_iwlistener         2866			// tcp,iwlistener   
#define IANAport_esps_portal        2867			// tcp,esps_portal   
#define IANAport_npep_messaging     2868			// tcp,Norman Proprietaqry Events Protocol   
#define IANAport_icslap             2869			// tcp,ICSLAP   
#define IANAport_daishi             2870			// tcp,daishi   
#define IANAport_msi_selectplay     2871			// tcp,MSI Select Play   
#define IANAport_radix              2872			// tcp,RADIX   
#define IANAport_psrt               2873			// tcp,PubSub Realtime Telemetry Protocol   
#define IANAport_dxmessagebase1     2874			// tcp,DX Message Base Transport Protocol   
#define IANAport_dxmessagebase2     2875			// tcp,DX Message Base Transport Protocol   
#define IANAport_sps_tunnel         2876			// tcp,SPS Tunnel   
#define IANAport_bluelance          2877			// tcp,BLUELANCE   
#define IANAport_aap                2878			// tcp,AAP   
#define IANAport_ucentric_ds        2879			// tcp,ucentric_ds   
#define IANAport_synapse            2880			// tcp,Synapse Transport   
#define IANAport_ndsp               2881			// tcp,NDSP   
#define IANAport_ndtp               2882			// tcp,NDTP   
#define IANAport_ndnp               2883			// tcp,NDNP   
#define IANAport_flashmsg           2884			// tcp,Flash Msg   
#define IANAport_topflow            2885			// tcp,TopFlow   
#define IANAport_responselogic      2886			// tcp,RESPONSELOGIC   
#define IANAport_aironetddp         2887			// tcp,aironet   
#define IANAport_spcsdlobby         2888			// tcp,SPCSDLOBBY   
#define IANAport_rsom               2889			// tcp,RSOM   
#define IANAport_cspclmulti         2890			// tcp,CSPCLMULTI   
#define IANAport_cinegrfx_elmd      2891			// tcp,CINEGRFX_ELMD License Manager   
#define IANAport_snifferdata        2892			// tcp,SNIFFERDATA   
#define IANAport_vseconnector       2893			// tcp,VSECONNECTOR   
#define IANAport_abacus_remote      2894			// tcp,ABACUS_REMOTE   
#define IANAport_natuslink          2895			// tcp,NATUS LINK   
#define IANAport_ecovisiong6_1      2896			// tcp,ECOVISIONG6_1   
#define IANAport_citrix_rtmp        2897			// tcp,Citrix RTMP   
#define IANAport_appliance_cfg      2898			// tcp,APPLIANCE_CFG   
#define IANAport_powergemplus       2899			// tcp,POWERGEMPLUS   
#define IANAport_quicksuite         2900			// tcp,QUICKSUITE   
#define IANAport_allstorcns         2901			// tcp,ALLSTORCNS   
#define IANAport_netaspi            2902			// tcp,NET ASPI   
#define IANAport_suitcase           2903			// tcp,SUITCASE   
#define IANAport_m2ua               2904			// tcp,M2UA   
#define IANAport_m3ua               2905			// tcp,M3UA,[RFC4666]  ,
//#define IANAport_                 2905			// udp,De_registered   
#define IANAport_caller9            2906			// tcp,CALLER9   
#define IANAport_webmethods_b2b     2907			// tcp,WEBMETHODS B2B   
#define IANAport_mao                2908			// tcp,mao   
#define IANAport_funk_dialout       2909			// tcp,Funk Dialout   
#define IANAport_tdaccess           2910			// tcp,TDAccess   
#define IANAport_blockade           2911			// tcp,Blockade   
#define IANAport_epicon             2912			// tcp,Epicon   
#define IANAport_boosterware        2913			// tcp,Booster Ware   
#define IANAport_gamelobby          2914			// tcp,Game Lobby   
#define IANAport_tksocket           2915			// tcp,TK Socket   
#define IANAport_elvin_server       2916			// tcp,"Elvin Server IANA assigned this well_formed service name as a replacement for ""elvin_server""."   
#define IANAport_elvin_client       2917			// tcp,"Elvin Client IANA assigned this well_formed service name as a replacement for ""elvin_client""."   
#define IANAport_kastenchasepad     2918			// tcp,Kasten Chase Pad   
#define IANAport_roboer             2919			// tcp,roboER   
#define IANAport_roboeda            2920			// tcp,roboEDA   
#define IANAport_cesdcdman          2921			// tcp,CESD Contents Delivery Management   
#define IANAport_cesdcdtrn          2922			// tcp,CESD Contents Delivery Data Transfer   
#define IANAport_wta_wsp_wtp_s      2923			// tcp,WTA_WSP_WTP_S   
#define IANAport_precise_vip        2924			// tcp,PRECISE_VIP   
#define IANAport_mobile_file_dl     2926			// tcp,MOBILE_FILE_DL   
#define IANAport_unimobilectrl      2927			// tcp,UNIMOBILECTRL   
#define IANAport_redstone_cpss      2928			// tcp,REDSTONE_CPSS   
#define IANAport_amx_webadmin       2929			// tcp,AMX_WEBADMIN   
#define IANAport_amx_weblinx        2930			// tcp,AMX_WEBLINX   
#define IANAport_circle_x           2931			// tcp,Circle_X   
#define IANAport_incp               2932			// tcp,INCP   
#define IANAport_4_tieropmgw        2933			// tcp,4_TIER OPM GW   
#define IANAport_4_tieropmcli       2934			// tcp,4_TIER OPM CLI   
#define IANAport_qtp                2935			// tcp,QTP   
#define IANAport_otpatch            2936			// tcp,OTPatch   
#define IANAport_pnaconsult_lm      2937			// tcp,PNACONSULT_LM   
#define IANAport_sm_pas_1           2938			// tcp,SM_PAS_1   
#define IANAport_sm_pas_2           2939			// tcp,SM_PAS_2   
#define IANAport_sm_pas_3           2940			// tcp,SM_PAS_3   
#define IANAport_sm_pas_4           2941			// tcp,SM_PAS_4   
#define IANAport_sm_pas_5           2942			// tcp,SM_PAS_5   
#define IANAport_ttnrepository      2943			// tcp,TTNRepository   
#define IANAport_megaco_h248        2944			// tcp,Megaco H_248   
#define IANAport_h248_binary        2945			// tcp,H248 Binary   
#define IANAport_fjsvmpor           2946			// tcp,FJSVmpor   
#define IANAport_gpsd               2947			// tcp,GPS Daemon request/response protocol   
#define IANAport_wap_push           2948			// tcp,WAP PUSH   
#define IANAport_wap_pushsecure     2949			// tcp,WAP PUSH SECURE   
#define IANAport_esip               2950			// tcp,ESIP   
#define IANAport_ottp               2951			// tcp,OTTP   
#define IANAport_mpfwsas            2952			// tcp,MPFWSAS   
#define IANAport_ovalarmsrv         2953			// tcp,OVALARMSRV   
#define IANAport_ovalarmsrv_cmd     2954			// tcp,OVALARMSRV_CMD   
#define IANAport_csnotify           2955			// tcp,CSNOTIFY   
#define IANAport_ovrimosdbman       2956			// tcp,OVRIMOSDBMAN   
#define IANAport_jmact5             2957			// tcp,JAMCT5   
#define IANAport_jmact6             2958			// tcp,JAMCT6   
#define IANAport_rmopagt            2959			// tcp,RMOPAGT   
#define IANAport_dfoxserver         2960			// tcp,DFOXSERVER   
#define IANAport_boldsoft_lm        2961			// tcp,BOLDSOFT_LM   
#define IANAport_iph_policy_cli     2962			// tcp,IPH_POLICY_CLI   
#define IANAport_iph_policy_adm     2963			// tcp,IPH_POLICY_ADM   
#define IANAport_bullant_srap       2964			// tcp,BULLANT SRAP   
#define IANAport_bullant_rap        2965			// tcp,BULLANT RAP   
#define IANAport_idp_infotrieve     2966			// tcp,IDP_INFOTRIEVE   
#define IANAport_ssc_agent          2967			// tcp,SSC_AGENT   
#define IANAport_enpp               2968			// tcp,ENPP   
#define IANAport_essp               2969			// tcp,ESSP   
#define IANAport_index_net          2970			// tcp,INDEX_NET   
#define IANAport_netclip            2971			// tcp,NetClip clipboard daemon   
#define IANAport_pmsm_webrctl       2972			// tcp,PMSM Webrctl   
#define IANAport_svnetworks         2973			// tcp,SV Networks   
#define IANAport_signal             2974			// tcp,Signal   
#define IANAport_fjmpcm             2975			// tcp,Fujitsu Configuration Management Service   
#define IANAport_cns_srv_port       2976			// tcp,CNS Server Port   
#define IANAport_ttc_etap_ns        2977			// tcp,TTCs Enterprise Test Access Protocol _ NS   
#define IANAport_ttc_etap_ds        2978			// tcp,TTCs Enterprise Test Access Protocol _ DS   
#define IANAport_h263_video         2979			// tcp,H.263 Video Streaming   
#define IANAport_wimd               2980			// tcp,Instant Messaging Service   
#define IANAport_mylxamport         2981			// tcp,MYLXAMPORT   
#define IANAport_iwb_whiteboard     2982			// tcp,IWB_WHITEBOARD   
#define IANAport_netplan            2983			// tcp,NETPLAN   
#define IANAport_hpidsadmin         2984			// tcp,HPIDSADMIN   
#define IANAport_hpidsagent         2985			// tcp,HPIDSAGENT   
#define IANAport_stonefalls         2986			// tcp,STONEFALLS   
#define IANAport_identify           2987			// tcp,identify   
#define IANAport_hippad             2988			// tcp,HIPPA Reporting Protocol   
#define IANAport_zarkov             2989			// tcp,ZARKOV Intelligent Agent Communication   
#define IANAport_boscap             2990			// tcp,BOSCAP   
#define IANAport_wkstn_mon          2991			// tcp,WKSTN_MON   
#define IANAport_avenyo             2992			// tcp,Avenyo Server   
#define IANAport_veritas_vis1       2993			// tcp,VERITAS VIS1   
#define IANAport_veritas_vis2       2994			// tcp,VERITAS VIS2   
#define IANAport_idrs               2995			// tcp,IDRS   
#define IANAport_vsixml             2996			// tcp,vsixml   
#define IANAport_rebol              2997			// tcp,REBOL   
#define IANAport_realsecure         2998			// tcp,Real Secure   
#define IANAport_remoteware_un      2999			// tcp,RemoteWare Unassigned   
#define IANAport_hbci               3000			// tcp,HBCI   
#define IANAport_remoteware_cl      3000			// tcp,RemoteWare Client   
#define IANAport_origo_native       3001			// tcp,OrigoDB Server Native Interface   
//#define IANAport_                 3001			// udp,Reserved   
#define IANAport_exlm_agent         3002			// tcp,EXLM Agent   
#define IANAport_remoteware_srv     3002			// tcp,RemoteWare Server   
#define IANAport_cgms               3003			// tcp,CGMS   
#define IANAport_csoftragent        3004			// tcp,Csoft Agent   
#define IANAport_geniuslm           3005			// tcp,Genius License Manager   
#define IANAport_ii_admin           3006			// tcp,Instant Internet Admin   
#define IANAport_lotusmtap          3007			// tcp,Lotus Mail Tracking Agent Protocol   
#define IANAport_midnight_tech      3008			// tcp,Midnight Technologies   
#define IANAport_pxc_ntfy           3009			// tcp,PXC_NTFY   
#define IANAport_gw                 3010			// tcp,Telerate Workstation   
#define IANAport_ping_pong          3010			// udp,Telerate Workstation   
#define IANAport_trusted_web        3011			// tcp,Trusted Web   
#define IANAport_twsdss             3012			// tcp,Trusted Web Client   
#define IANAport_gilatskysurfer     3013			// tcp,Gilat Sky Surfer   
#define IANAport_broker_service     3014			// tcp,"Broker Service IANA assigned this well_formed service name as a replacement for ""broker_service""."   
#define IANAport_nati_dstp          3015			// tcp,NATI DSTP   
#define IANAport_notify_srvr        3016			// tcp,"Notify Server IANA assigned this well_formed service name as a replacement for ""notify_srvr""."   
#define IANAport_event_listener     3017			// tcp,"Event Listener IANA assigned this well_formed service name as a replacement for ""event_listener""."   
#define IANAport_srvc_registry      3018			// tcp,"Service Registry IANA assigned this well_formed service name as a replacement for ""srvc_registry""."   
#define IANAport_resource_mgr       3019			// tcp,"Resource Manager IANA assigned this well_formed service name as a replacement for ""resource_mgr""."   
#define IANAport_cifs               3020			// tcp,CIFS   
#define IANAport_agriserver         3021			// tcp,AGRI Server   
#define IANAport_csregagent         3022			// tcp,CSREGAGENT   
#define IANAport_magicnotes         3023			// tcp,magicnotes   
#define IANAport_nds_sso            3024			// tcp,"NDS_SSO IANA assigned this well_formed service name as a replacement for ""nds_sso""."   
#define IANAport_arepa_raft         3025			// tcp,Arepa Raft   
#define IANAport_agri_gateway       3026			// tcp,AGRI Gateway   
#define IANAport_LiebDevMgmt_C      3027			// tcp,"LiebDevMgmt_C IANA assigned this well_formed service name as a replacement for ""LiebDevMgmt_C""."   
#define IANAport_LiebDevMgmt_DM     3028			// tcp,"LiebDevMgmt_DM IANA assigned this well_formed service name as a replacement for ""LiebDevMgmt_DM""."   
#define IANAport_LiebDevMgmt_A      3029			// tcp,"LiebDevMgmt_A IANA assigned this well_formed service name as a replacement for ""LiebDevMgmt_A""."   
#define IANAport_arepa_cas          3030			// tcp,Arepa Cas   
#define IANAport_eppc               3031			// tcp,Remote AppleEvents/PPC Toolbox   
#define IANAport_redwood_chat       3032			// tcp,Redwood Chat   
#define IANAport_pdb                3033			// tcp,PDB   
#define IANAport_osmosis_aeea       3034			// tcp,Osmosis / Helix (R) AEEA Port   
#define IANAport_fjsv_gssagt        3035			// tcp,FJSV gssagt   
#define IANAport_hagel_dump         3036			// tcp,Hagel DUMP   
#define IANAport_hp_san_mgmt        3037			// tcp,HP SAN Mgmt   
#define IANAport_santak_ups         3038			// tcp,Santak UPS   
#define IANAport_cogitate           3039			// tcp,"Cogitate, Inc."   
#define IANAport_tomato_springs     3040			// tcp,Tomato Springs   
#define IANAport_di_traceware       3041			// tcp,di_traceware   
#define IANAport_journee            3042			// tcp,journee   
#define IANAport_brp                3043			// tcp,Broadcast Routing Protocol   
#define IANAport_epp_epp            3044			// tcp,EndPoint Protocol - Note renamed
#define IANAport_responsenet        3045			// tcp,ResponseNet   
#define IANAport_di_ase             3046			// tcp,di_ase   
#define IANAport_hlserver           3047			// tcp,Fast Security HL Server   
#define IANAport_pctrader           3048			// tcp,Sierra Net PC Trader   
#define IANAport_nsws               3049			// tcp,NSWS   
#define IANAport_gds_db             3050			// tcp,"gds_db IANA assigned this well_formed service name as a replacement for ""gds_db""."   
#define IANAport_galaxy_server      3051			// tcp,Galaxy Server   
#define IANAport_apc_3052           3052			// tcp,APC 3052   
#define IANAport_dsom_server        3053			// tcp,dsom_server   
#define IANAport_amt_cnf_prot       3054			// tcp,AMT CNF PROT   
#define IANAport_policyserver       3055			// tcp,Policy Server   
#define IANAport_cdl_server         3056			// tcp,CDL Server   
#define IANAport_goahead_fldup      3057			// tcp,GoAhead FldUp   
#define IANAport_videobeans         3058			// tcp,videobeans   
#define IANAport_qsoft              3059			// tcp,qsoft   
#define IANAport_interserver        3060			// tcp,interserver   
#define IANAport_cautcpd            3061			// tcp,cautcpd   
#define IANAport_ncacn_ip_tcp       3062			// tcp,ncacn_ip_tcp   
#define IANAport_ncadg_ip_udp       3063			// tcp,ncadg_ip_udp   
#define IANAport_rprt               3064			// tcp,Remote Port Redirector   
#define IANAport_slinterbase        3065			// tcp,slinterbase   
#define IANAport_netattachsdmp      3066			// tcp,NETATTACHSDMP   
#define IANAport_fjhpjp             3067			// tcp,FJHPJP   
#define IANAport_ls3bcast           3068			// tcp,ls3 Broadcast   
#define IANAport_ls3                3069			// tcp,ls3   
#define IANAport_mgxswitch          3070			// tcp,MGXSWITCH   
#define IANAport_xplat_replicate    3071			// tcp,Crossplatform replication protocol   
//#define IANAport_                 3071			// udp,Reserved   
#define IANAport_csd_monitor        3072			// tcp,ContinuStor Monitor Port   
#define IANAport_vcrp               3073			// tcp,Very simple chatroom prot   
#define IANAport_xbox               3074			// tcp,Xbox game port   
#define IANAport_orbix_locator      3075			// tcp,Orbix 2000 Locator   
#define IANAport_orbix_config       3076			// tcp,Orbix 2000 Config   
#define IANAport_orbix_loc_ssl      3077			// tcp,Orbix 2000 Locator SSL   
#define IANAport_orbix_cfg_ssl      3078			// tcp,Orbix 2000 Locator SSL   
#define IANAport_lv_frontpanel      3079			// tcp,LV Front Panel   
#define IANAport_stm_pproc          3080			// tcp,"stm_pproc IANA assigned this well_formed service name as a replacement for ""stm_pproc""."   
#define IANAport_tl1_lv             3081			// tcp,TL1_LV   
#define IANAport_tl1_raw            3082			// tcp,TL1_RAW   
#define IANAport_tl1_telnet         3083			// tcp,TL1_TELNET   
#define IANAport_itm_mccs           3084			// tcp,ITM_MCCS   
#define IANAport_pcihreq            3085			// tcp,PCIHReq   
#define IANAport_jdl_dbkitchen      3086			// tcp,JDL_DBKitchen   
#define IANAport_asoki_sma          3087			// tcp,Asoki SMA   
#define IANAport_xdtp               3088			// tcp,eXtensible Data Transfer Protocol   
#define IANAport_ptk_alink          3089			// tcp,ParaTek Agent Linking   
#define IANAport_stss               3090			// tcp,Senforce Session Services   
#define IANAport_1ci_smcs           3091			// tcp,1Ci Server Management   
#define IANAport_rapidmq_center     3093			// tcp,Jiiva RapidMQ Center   
#define IANAport_rapidmq_reg        3094			// tcp,Jiiva RapidMQ Registry   
#define IANAport_panasas            3095			// tcp,Panasas rendezvous port   
#define IANAport_ndl_aps            3096			// tcp,Active Print Server Port   
//#define IANAport_                 3097			// tcp,Reserved   
//#define IANAport_                 3097			// udp,Reserved   
#define IANAport_itu_bicc_stc       3097			// sctp,ITU_T Q.1902.1/Q.2150.3   
#define IANAport_umm_port           3098			// tcp,Universal Message Manager   
#define IANAport_chmd               3099			// tcp,CHIPSY Machine Daemon   
#define IANAport_opcon_xps          3100			// tcp,OpCon/xps   
#define IANAport_hp_pxpib           3101			// tcp,HP PolicyXpert PIB Server   
#define IANAport_slslavemon         3102			// tcp,SoftlinK Slave Mon Port   
#define IANAport_autocuesmi         3103			// tcp,Autocue SMI Protocol   
#define IANAport_autocuelog         3104			// tcp,Autocue Logger Protocol   
#define IANAport_autocuetime        3104			// udp,Autocue Time Service   
#define IANAport_cardbox            3105			// udp,Cardbox   
#define IANAport_cardbox_http       3106			// tcp,Cardbox HTTP   
#define IANAport_business           3107			// tcp,Business protocol   
#define IANAport_geolocate          3108			// tcp,Geolocate protocol   
#define IANAport_personnel          3109			// tcp,Personnel protocol   
#define IANAport_sim_control        3110			// tcp,simulator control port   
#define IANAport_wsynch             3111			// tcp,Web Synchronous Services   
#define IANAport_ksysguard          3112			// tcp,KDE System Guard   
#define IANAport_cs_auth_svr        3113			// tcp,CS_Authenticate Svr Port   
#define IANAport_ccmad              3114			// tcp,CCM AutoDiscover   
#define IANAport_mctet_master       3115			// tcp,MCTET Master   
#define IANAport_mctet_gateway      3116			// tcp,MCTET Gateway   
#define IANAport_mctet_jserv        3117			// tcp,MCTET Jserv   
#define IANAport_pkagent            3118			// tcp,PKAgent   
#define IANAport_d2000kernel        3119			// tcp,D2000 Kernel Port   
#define IANAport_d2000webserver     3120			// tcp,D2000 Webserver Port   
#define IANAport_pcmk_remote        3121			// tcp,The pacemaker remote (pcmk_remote) service extends high availability functionality outside of the Linux cluster into remote nodes.   
//#define IANAport_                 3121			// udp,Reserved   
#define IANAport_vtr_emulator       3122			// tcp,MTI VTR Emulator port   
#define IANAport_edix               3123			// tcp,EDI Translation Protocol   
#define IANAport_beacon_port        3124			// tcp,Beacon Port   
#define IANAport_a13_an             3125			// tcp,A13_AN Interface   
#define IANAport_ctx_bridge         3127			// tcp,CTX Bridge Port   
#define IANAport_ndl_aas            3128			// tcp,Active API Server Port   
#define IANAport_netport_id         3129			// tcp,NetPort Discovery Port   
#define IANAport_icpv2              3130			// tcp,ICPv2   
#define IANAport_netbookmark        3131			// tcp,Net Book Mark   
#define IANAport_ms_rule_engine     3132			// tcp,Microsoft Business Rule Engine Update Service   
#define IANAport_prism_deploy       3133			// tcp,Prism Deploy User Port   
#define IANAport_ecp                3134			// tcp,Extensible Code Protocol   
#define IANAport_peerbook_port      3135			// tcp,PeerBook Port   
#define IANAport_grubd              3136			// tcp,Grub Server Port   
#define IANAport_rtnt_1             3137			// tcp,rtnt_1 data packets   
#define IANAport_rtnt_2             3138			// tcp,rtnt_2 data packets   
#define IANAport_incognitorv        3139			// tcp,Incognito Rendez_Vous   
#define IANAport_ariliamulti        3140			// tcp,Arilia Multiplexor   
#define IANAport_vmodem             3141			// tcp,VMODEM   
#define IANAport_rdc_wh_eos         3142			// tcp,RDC WH EOS   
#define IANAport_seaview            3143			// tcp,Sea View   
#define IANAport_tarantella         3144			// tcp,Tarantella   
#define IANAport_csi_lfap           3145			// tcp,CSI_LFAP   
#define IANAport_bears_02           3146			// tcp,bears_02   
#define IANAport_rfio               3147			// tcp,RFIO   
#define IANAport_nm_game_admin      3148			// tcp,NetMike Game Administrator   
#define IANAport_nm_game_server     3149			// tcp,NetMike Game Server   
#define IANAport_nm_asses_admin     3150			// tcp,NetMike Assessor Administrator   
#define IANAport_nm_assessor        3151			// tcp,NetMike Assessor   
#define IANAport_feitianrockey      3152			// tcp,FeiTian Port   
#define IANAport_s8_client_port     3153			// tcp,S8Cargo Client Port   
#define IANAport_ccmrmi             3154			// tcp,ON RMI Registry   
#define IANAport_jpegmpeg           3155			// tcp,JpegMpeg Port   
#define IANAport_indura             3156			// tcp,Indura Collector   
#define IANAport_e3consultants      3157			// tcp,CCC Listener Port   
#define IANAport_stvp               3158			// tcp,SmashTV Protocol   
#define IANAport_navegaweb_port     3159			// tcp,NavegaWeb Tarification   
#define IANAport_tip_app_server     3160			// tcp,TIP Application Server   
#define IANAport_doc1lm             3161			// tcp,DOC1 License Manager   
#define IANAport_sflm               3162			// tcp,SFLM   
#define IANAport_res_sap            3163			// tcp,RES_SAP   
#define IANAport_imprs              3164			// tcp,IMPRS   
#define IANAport_newgenpay          3165			// tcp,Newgenpay Engine Service   
#define IANAport_sossecollector     3166			// tcp,Quest Spotlight Out_Of_Process Collector   
#define IANAport_nowcontact         3167			// tcp,Now Contact Public Server   
#define IANAport_poweronnud         3168			// tcp,Now Up_to_Date Public Server   
#define IANAport_serverview_as      3169			// tcp,SERVERVIEW_AS   
#define IANAport_serverview_asn     3170			// tcp,SERVERVIEW_ASN   
#define IANAport_serverview_gf      3171			// tcp,SERVERVIEW_GF   
#define IANAport_serverview_rm      3172			// tcp,SERVERVIEW_RM   
#define IANAport_serverview_icc     3173			// tcp,SERVERVIEW_ICC   
#define IANAport_armi_server        3174			// tcp,ARMI Server   
#define IANAport_t1_e1_over_ip      3175			// tcp,T1_E1_Over_IP   
#define IANAport_ars_master         3176			// tcp,ARS Master   
#define IANAport_phonex_port        3177			// tcp,Phonex Protocol   
#define IANAport_radclientport      3178			// tcp,Radiance UltraEdge Port   
#define IANAport_h2gf_w_2m          3179			// tcp,H2GF W.2m Handover prot.   
#define IANAport_mc_brk_srv         3180			// tcp,Millicent Broker Server   
#define IANAport_bmcpatrolagent     3181			// tcp,BMC Patrol Agent   
#define IANAport_bmcpatrolrnvu      3182			// tcp,BMC Patrol Rendezvous   
#define IANAport_cops_tls           3183			// tcp,COPS/TLS   
#define IANAport_apogeex_port       3184			// tcp,ApogeeX Port   
#define IANAport_smpppd             3185			// tcp,SuSE Meta PPPD   
#define IANAport_iiw_port           3186			// tcp,IIW Monitor User Port   
#define IANAport_odi_port           3187			// tcp,Open Design Listen Port   
#define IANAport_brcm_comm_port     3188			// tcp,Broadcom Port   
#define IANAport_pcle_infex         3189			// tcp,Pinnacle Sys InfEx Port   
#define IANAport_csvr_proxy         3190			// tcp,ConServR Proxy   
#define IANAport_csvr_sslproxy      3191			// tcp,ConServR SSL Proxy   
#define IANAport_firemonrcc         3192			// tcp,FireMon Revision Control   
#define IANAport_spandataport       3193			// tcp,SpanDataPort   
#define IANAport_magbind            3194			// tcp,Rockstorm MAG protocol   
#define IANAport_ncu_1              3195			// tcp,Network Control Unit   
#define IANAport_ncu_2              3196			// tcp,Network Control Unit   
#define IANAport_embrace_dp_s       3197			// tcp,Embrace Device Protocol Server   
#define IANAport_embrace_dp_c       3198			// tcp,Embrace Device Protocol Client   
#define IANAport_dmod_workspace     3199			// tcp,DMOD WorkSpace   
#define IANAport_tick_port          3200			// tcp,Press_sense Tick Port   
#define IANAport_cpq_tasksmart      3201			// tcp,CPQ_TaskSmart   
#define IANAport_intraintra         3202			// tcp,IntraIntra   
#define IANAport_netwatcher_mon     3203			// tcp,Network Watcher Monitor   
#define IANAport_netwatcher_db      3204			// tcp,Network Watcher DB Access   
#define IANAport_isns               3205			// tcp,iSNS Server Port,[RFC4171]  ,
#define IANAport_ironmail           3206			// tcp,IronMail POP Proxy   
#define IANAport_vx_auth_port       3207			// tcp,Veritas Authentication Port   
#define IANAport_pfu_prcallback     3208			// tcp,PFU PR Callback   
#define IANAport_netwkpathengine    3209			// tcp,HP OpenView Network Path Engine Server   
#define IANAport_flamenco_proxy     3210			// tcp,Flamenco Networks Proxy   
#define IANAport_avsecuremgmt       3211			// tcp,Avocent Secure Management   
#define IANAport_surveyinst         3212			// tcp,Survey Instrument   
#define IANAport_neon24x7           3213			// tcp,NEON 24X7 Mission Control   
#define IANAport_jmq_daemon_1       3214			// tcp,JMQ Daemon Port 1   
#define IANAport_jmq_daemon_2       3215			// tcp,JMQ Daemon Port 2   
#define IANAport_ferrari_foam       3216			// tcp,Ferrari electronic FOAM   
#define IANAport_unite              3217			// tcp,Unified IP & Telecom Environment   
#define IANAport_smartpackets       3218			// tcp,EMC SmartPackets   
#define IANAport_wms_messenger      3219			// tcp,WMS Messenger   
#define IANAport_xnm_ssl            3220			// tcp,XML NM over SSL   
#define IANAport_xnm_clear_text     3221			// tcp,XML NM over TCP   
#define IANAport_glbp               3222			// tcp,Gateway Load Balancing Pr   
#define IANAport_digivote           3223			// tcp,DIGIVOTE (R) Vote_Server   
#define IANAport_aes_discovery      3224			// tcp,AES Discovery Port   
#define IANAport_fcip_port          3225			// tcp,FCIP,[RFC3821]  ,
#define IANAport_isi_irp            3226			// tcp,ISI Industry Software IRP   
#define IANAport_dwnmshttp          3227			// tcp,DiamondWave NMS Server   
#define IANAport_dwmsgserver        3228			// tcp,DiamondWave MSG Server   
#define IANAport_global_cd_port     3229			// tcp,Global CD Port   
#define IANAport_sftdst_port        3230			// tcp,Software Distributor Port   
#define IANAport_vidigo             3231			// tcp,VidiGo communication (previous was: Delta Solutions Direct)   
#define IANAport_mdtp               3232			// tcp,MDT port,[RFC6513]  ,
#define IANAport_whisker            3233			// tcp,WhiskerControl main port   
#define IANAport_alchemy            3234			// tcp,Alchemy Server   
#define IANAport_mdap_port          3235			// tcp,MDAP port   
#define IANAport_apparenet_ts       3236			// tcp,appareNet Test Server   
#define IANAport_apparenet_tps      3237			// tcp,appareNet Test Packet Sequencer   
#define IANAport_apparenet_as       3238			// tcp,appareNet Analysis Server   
#define IANAport_apparenet_ui       3239			// tcp,appareNet User Interface   
#define IANAport_triomotion         3240			// tcp,Trio Motion Control Port   
#define IANAport_sysorb             3241			// tcp,SysOrb Monitoring Server   
#define IANAport_sdp_id_port        3242			// tcp,Session Description ID   
#define IANAport_timelot            3243			// tcp,Timelot Port   
#define IANAport_onesaf             3244			// tcp,OneSAF   
#define IANAport_vieo_fe            3245			// tcp,VIEO Fabric Executive   
#define IANAport_dvt_system         3246			// tcp,DVT SYSTEM PORT   
#define IANAport_dvt_data           3247			// tcp,DVT DATA LINK   
#define IANAport_procos_lm          3248			// tcp,PROCOS LM   
#define IANAport_ssp                3249			// tcp,State Sync Protocol   
#define IANAport_hicp               3250			// tcp,HMS hicp port   
#define IANAport_sysscanner         3251			// tcp,Sys Scanner   
#define IANAport_dhe                3252			// tcp,DHE port   
#define IANAport_pda_data           3253			// tcp,PDA Data   
#define IANAport_pda_sys            3254			// tcp,PDA System   
#define IANAport_semaphore          3255			// tcp,Semaphore Connection Port   
#define IANAport_cpqrpm_agent       3256			// tcp,Compaq RPM Agent Port   
#define IANAport_cpqrpm_server      3257			// tcp,Compaq RPM Server Port   
#define IANAport_ivecon_port        3258			// tcp,Ivecon Server Port   
#define IANAport_epncdp2            3259			// tcp,Epson Network Common Devi   
#define IANAport_iscsi_target       3260			// tcp,iSCSI port,[RFC7143]  ,
#define IANAport_winshadow          3261			// tcp,winShadow   
#define IANAport_necp               3262			// tcp,NECP   
#define IANAport_ecolor_imager      3263			// tcp,E_Color Enterprise Imager   
#define IANAport_ccmail             3264			// tcp,cc:mail/lotus   
#define IANAport_altav_tunnel       3265			// tcp,Altav Tunnel   
#define IANAport_ns_cfg_server      3266			// tcp,NS CFG Server   
#define IANAport_ibm_dial_out       3267			// tcp,IBM Dial Out   
#define IANAport_msft_gc            3268			// tcp,Microsoft Global Catalog   
#define IANAport_msft_gc_ssl        3269			// tcp,Microsoft Global Catalog with LDAP/SSL   
#define IANAport_verismart          3270			// tcp,Verismart   
#define IANAport_csoft_prev         3271			// tcp,CSoft Prev Port   
#define IANAport_user_manager       3272			// tcp,Fujitsu User Manager   
#define IANAport_sxmp               3273			// tcp,Simple Extensible Multiplexed Protocol   
#define IANAport_ordinox_server     3274			// tcp,Ordinox Server   
#define IANAport_samd               3275			// tcp,SAMD   
#define IANAport_maxim_asics        3276			// tcp,Maxim ASICs   
#define IANAport_awg_proxy          3277			// tcp,AWG Proxy   
#define IANAport_lkcmserver         3278			// tcp,LKCM Server   
#define IANAport_admind_1           3279			// tcp,admind - Note amended
#define IANAport_vs_server          3280			// tcp,VS Server   
#define IANAport_sysopt             3281			// tcp,SYSOPT   
#define IANAport_datusorb           3282			// tcp,Datusorb   
#define IANAport_Apple_Remote_Desktop_Net_Assistant 3283			// tcp,Net Assistant   
#define IANAport_4talk              3284			// tcp,4Talk   
#define IANAport_plato              3285			// tcp,Plato   
#define IANAport_e_net              3286			// tcp,E_Net   
#define IANAport_directvdata        3287			// tcp,DIRECTVDATA   
#define IANAport_cops               3288			// tcp,COPS   
#define IANAport_enpc               3289			// tcp,ENPC   
#define IANAport_caps_lm            3290			// tcp,CAPS LOGISTICS TOOLKIT _ LM   
#define IANAport_sah_lm             3291			// tcp,S A Holditch & Associates _ LM   
#define IANAport_cart_o_rama        3292			// tcp,Cart O Rama   
#define IANAport_fg_fps             3293			// tcp,fg_fps   
#define IANAport_fg_gip             3294			// tcp,fg_gip   
#define IANAport_dyniplookup        3295			// tcp,Dynamic IP Lookup   
#define IANAport_rib_slm            3296			// tcp,Rib License Manager   
#define IANAport_cytel_lm           3297			// tcp,Cytel License Manager   
#define IANAport_deskview           3298			// tcp,DeskView   
#define IANAport_pdrncs             3299			// tcp,pdrncs   
#define IANAport_ceph               3300			// tcp,Ceph monitor   
//#define IANAport_                 3300			// udp,Reserved   
#define IANAport_tarantool          3301			// tcp,Tarantool in_memory computing platform   
#define IANAport_mcs_fastmail       3302			// tcp,MCS Fastmail   
#define IANAport_opsession_clnt     3303			// tcp,OP Session Client   
#define IANAport_opsession_srvr     3304			// tcp,OP Session Server   
#define IANAport_odette_ftp         3305			// tcp,ODETTE_FTP,[RFC5024]  ,
#define IANAport_mysql              3306			// tcp,MySQL   
#define IANAport_opsession_prxy     3307			// tcp,OP Session Proxy   
#define IANAport_tns_server         3308			// tcp,TNS Server   
#define IANAport_tns_adv            3309			// tcp,TNS ADV   
#define IANAport_dyna_access        3310			// tcp,Dyna Access   
#define IANAport_mcns_tel_ret       3311			// tcp,MCNS Tel Ret   
#define IANAport_appman_server      3312			// tcp,Application Management Server   
#define IANAport_uorb               3313			// tcp,Unify Object Broker   
#define IANAport_uohost             3314			// tcp,Unify Object Host   
#define IANAport_cdid               3315			// tcp,CDID   
#define IANAport_aicc_cmi           3316			// tcp,AICC/CMI   
#define IANAport_vsaiport           3317			// tcp,VSAI PORT   
#define IANAport_ssrip              3318			// tcp,Swith to Swith Routing Information Protocol   
#define IANAport_sdt_lmd            3319			// tcp,SDT License Manager   
#define IANAport_officelink2000     3320			// tcp,Office Link 2000   
#define IANAport_vnsstr             3321			// tcp,VNSSTR   
#define IANAport_active_net1        3322			// ,Active Networks   
#define IANAport_active_net2        3323			// ,Active Networks   
#define IANAport_active_net3        3324			// ,Active Networks   
#define IANAport_active_net4        3325			// ,Active Networks   
#define IANAport_sftu               3326			// tcp,SFTU   
#define IANAport_bbars              3327			// tcp,BBARS   
#define IANAport_egptlm             3328			// tcp,Eaglepoint License Manager   
#define IANAport_hp_device_disc     3329			// tcp,HP Device Disc   
#define IANAport_mcs_calypsoicf     3330			// tcp,MCS Calypso ICF   
#define IANAport_mcs_messaging      3331			// tcp,MCS Messaging   
#define IANAport_mcs_mailsvr        3332			// tcp,MCS Mail Server   
#define IANAport_dec_notes          3333			// tcp,DEC Notes   
#define IANAport_directv_web        3334			// tcp,Direct TV Webcasting   
#define IANAport_directv_soft       3335			// tcp,Direct TV Software Updates   
#define IANAport_directv_tick       3336			// tcp,Direct TV Tickers   
#define IANAport_directv_catlg      3337			// tcp,Direct TV Data Catalog   
#define IANAport_anet_b             3338			// tcp,OMF data b   
#define IANAport_anet_l             3339			// tcp,OMF data l   
#define IANAport_anet_m             3340			// tcp,OMF data m   
#define IANAport_anet_h             3341			// tcp,OMF data h   
#define IANAport_webtie             3342			// tcp,WebTIE   
#define IANAport_ms_cluster_net     3343			// tcp,MS Cluster Net   
#define IANAport_bnt_manager        3344			// tcp,BNT Manager   
#define IANAport_influence          3345			// tcp,Influence   
#define IANAport_trnsprntproxy      3346			// tcp,Trnsprnt Proxy   
#define IANAport_phoenix_rpc        3347			// tcp,Phoenix RPC   
#define IANAport_pangolin_laser     3348			// tcp,Pangolin Laser   
#define IANAport_chevinservices     3349			// tcp,Chevin Services   
#define IANAport_findviatv          3350			// tcp,FINDVIATV   
#define IANAport_btrieve            3351			// tcp,Btrieve port   
#define IANAport_ssql               3352			// tcp,Scalable SQL   
#define IANAport_fatpipe            3353			// tcp,FATPIPE   
#define IANAport_suitjd             3354			// tcp,SUITJD   
#define IANAport_ordinox_dbase      3355			// tcp,Ordinox Dbase   
#define IANAport_upnotifyps         3356			// tcp,UPNOTIFYPS   
#define IANAport_adtech_test        3357			// tcp,Adtech Test IP   
#define IANAport_mpsysrmsvr         3358			// tcp,Mp Sys Rmsvr   
#define IANAport_wg_netforce        3359			// tcp,WG NetForce   
#define IANAport_kv_server          3360			// tcp,KV Server   
#define IANAport_kv_agent           3361			// tcp,KV Agent   
#define IANAport_dj_ilm             3362			// tcp,DJ ILM   
#define IANAport_nati_vi_server     3363			// tcp,NATI Vi Server   
#define IANAport_creativeserver_2   3364			// tcp,Creative Server - Note amended
#define IANAport_contentserver_2    3365			// tcp,Content Server  - Note amended
#define IANAport_creativepartnr_2   3366			// tcp,Creative Partner - Note amended
#define IANAport_satvid_datalnk1    3367			// ,Satellite Video Data Link   
#define IANAport_satvid_datalnk2    3368			// ,Satellite Video Data Link   
#define IANAport_satvid_datalnk3    3369			// ,Satellite Video Data Link   
#define IANAport_satvid_datalnk4    3370			// ,Satellite Video Data Link   
#define IANAport_satvid_datalnk5    3371			// ,Satellite Video Data Link   
#define IANAport_tip2               3372			// tcp,TIP 2   
#define IANAport_lavenir_lm         3373			// tcp,Lavenir License Manager   
#define IANAport_cluster_disc       3374			// tcp,Cluster Disc   
#define IANAport_vsnm_agent         3375			// tcp,VSNM Agent   
#define IANAport_cdbroker           3376			// tcp,CD Broker   
#define IANAport_cogsys_lm          3377			// tcp,Cogsys Network License Manager   
#define IANAport_wsicopy            3378			// tcp,WSICOPY   
#define IANAport_socorfs            3379			// tcp,SOCORFS   
#define IANAport_sns_channels       3380			// tcp,SNS Channels   
#define IANAport_geneous            3381			// tcp,Geneous   
#define IANAport_fujitsu_neat       3382			// tcp,Fujitsu Network Enhanced Antitheft function   
#define IANAport_esp_lm             3383			// tcp,Enterprise Software Products License Manager   
#define IANAport_hp_clic            3384			// tcp,Cluster Management Services   
#define IANAport_qnxnetman          3385			// tcp,qnxnetman   
#define IANAport_gprs_data          3386			// tcp,GPRS Data   
#define IANAport_gprs_sig           3386			// udp,GPRS SIG   
#define IANAport_backroomnet        3387			// tcp,Back Room Net   
#define IANAport_cbserver           3388			// tcp,CB Server   
#define IANAport_ms_wbt_server      3389			// tcp,MS WBT Server   
#define IANAport_dsc                3390			// tcp,Distributed Service Coordinator   
#define IANAport_savant             3391			// tcp,SAVANT   
#define IANAport_efi_lm             3392			// tcp,EFI License Management   
#define IANAport_d2k_tapestry1      3393			// tcp,D2K Tapestry Client to Server   
#define IANAport_d2k_tapestry2      3394			// tcp,D2K Tapestry Server to Server   
#define IANAport_dyna_lm            3395			// tcp,Dyna License Manager (Elam)   
#define IANAport_printer_agent      3396			// tcp,"Printer Agent IANA assigned this well_formed service name as a replacement for ""printer_agent""."   
#define IANAport_cloanto_lm         3397			// tcp,Cloanto License Manager   
#define IANAport_mercantile         3398			// tcp,Mercantile   
#define IANAport_csms               3399			// tcp,CSMS   
#define IANAport_csms2              3400			// tcp,CSMS2   
#define IANAport_filecast           3401			// tcp,filecast   
#define IANAport_fxaengine_net      3402			// tcp,FXa Engine Network Port   
//#define IANAport_                 3403			// ,De_registered   
//#define IANAport_                 3404			// ,Removed   
#define IANAport_nokia_ann_ch1      3405			// tcp,Nokia Announcement ch 1   
#define IANAport_nokia_ann_ch2      3406			// tcp,Nokia Announcement ch 2   
#define IANAport_ldap_admin         3407			// tcp,LDAP admin server port   
#define IANAport_BESApi             3408			// tcp,BES Api Port   
#define IANAport_networklens        3409			// tcp,NetworkLens Event Port   
#define IANAport_networklenss       3410			// tcp,NetworkLens SSL Event   
#define IANAport_biolink_auth       3411			// tcp,BioLink Authenteon server   
#define IANAport_xmlblaster         3412			// tcp,xmlBlaster   
#define IANAport_svnet              3413			// tcp,SpecView Networking   
#define IANAport_wip_port           3414			// tcp,BroadCloud WIP Port   
#define IANAport_bcinameservice     3415			// tcp,BCI Name Service   
#define IANAport_commandport        3416			// tcp,AirMobile IS Command Port   
#define IANAport_csvr               3417			// tcp,ConServR file translation   
#define IANAport_rnmap              3418			// tcp,Remote nmap   
#define IANAport_softaudit          3419			// tcp,Isogon SoftAudit   
#define IANAport_ifcp_port          3420			// tcp,iFCP User Port,[RFC4172]  ,
#define IANAport_bmap               3421			// tcp,Bull Apprise portmapper   
#define IANAport_rusb_sys_port      3422			// tcp,Remote USB System Port   
#define IANAport_xtrm               3423			// tcp,xTrade Reliable Messaging   
#define IANAport_xtrms              3424			// tcp,xTrade over TLS/SSL   
#define IANAport_agps_port          3425			// tcp,AGPS Access Port   
#define IANAport_arkivio            3426			// tcp,Arkivio Storage Protocol   
#define IANAport_websphere_snmp     3427			// tcp,WebSphere SNMP   
#define IANAport_twcss              3428			// tcp,2Wire CSS   
#define IANAport_gcsp               3429			// tcp,GCSP user port   
#define IANAport_ssdispatch         3430			// tcp,Scott Studios Dispatch   
#define IANAport_ndl_als            3431			// tcp,Active License Server Port   
#define IANAport_osdcp              3432			// tcp,Secure Device Protocol   
#define IANAport_opnet_smp          3433			// tcp,OPNET Service Management Platform   
#define IANAport_opencm             3434			// tcp,OpenCM Server   
#define IANAport_pacom              3435			// tcp,Pacom Security User Port   
#define IANAport_gc_config          3436			// tcp,GuardControl Exchange Protocol   
#define IANAport_autocueds          3437			// tcp,Autocue Directory Service   
#define IANAport_spiral_admin       3438			// tcp,Spiralcraft Admin   
#define IANAport_hri_port           3439			// tcp,HRI Interface Port   
#define IANAport_ans_console        3440			// tcp,Net Steward Mgmt Console   
#define IANAport_connect_client     3441			// tcp,OC Connect Client   
#define IANAport_connect_server     3442			// tcp,OC Connect Server   
#define IANAport_ov_nnm_websrv      3443			// tcp,OpenView Network Node Manager WEB Server   
#define IANAport_denali_server      3444			// tcp,Denali Server   
#define IANAport_monp               3445			// tcp,Media Object Network Protocol   
#define IANAport_3comfaxrpc         3446			// tcp,3Com FAX RPC port   
#define IANAport_directnet          3447			// tcp,DirectNet IM System   
#define IANAport_dnc_port           3448			// tcp,Discovery and Net Config   
#define IANAport_hotu_chat          3449			// tcp,HotU Chat   
#define IANAport_castorproxy        3450			// tcp,CAStorProxy   
#define IANAport_asam               3451			// tcp,ASAM Services   
#define IANAport_sabp_signal        3452			// tcp,SABP_Signalling Protocol   
#define IANAport_pscupd             3453			// tcp,PSC Update   
#define IANAport_mira               3454			// tcp,Apple Remote Access Protocol   
#define IANAport_prsvp              3455			// tcp,RSVP Port   
#define IANAport_vat                3456			// tcp,VAT default data   
#define IANAport_vat_control        3457			// tcp,VAT default control   
#define IANAport_d3winosfi          3458			// tcp,D3WinOSFI   
#define IANAport_integral           3459			// tcp,TIP Integral   
#define IANAport_edm_manager        3460			// tcp,EDM Manger   
#define IANAport_edm_stager         3461			// tcp,EDM Stager   
#define IANAport_edm_std_notify     3462			// tcp,EDM STD Notify   
#define IANAport_edm_adm_notify     3463			// tcp,EDM ADM Notify   
#define IANAport_edm_mgr_sync       3464			// tcp,EDM MGR Sync   
#define IANAport_edm_mgr_cntrl      3465			// tcp,EDM MGR Cntrl   
#define IANAport_workflow           3466			// tcp,WORKFLOW   
#define IANAport_rcst               3467			// tcp,RCST   
#define IANAport_ttcmremotectrl     3468			// tcp,TTCM Remote Controll   
#define IANAport_pluribus           3469			// tcp,Pluribus   
#define IANAport_jt400              3470			// tcp,jt400   
#define IANAport_jt400_ssl          3471			// tcp,jt400_ssl   
#define IANAport_jaugsremotec_1     3472			// tcp,JAUGS N_G Remotec 1   
#define IANAport_jaugsremotec_2     3473			// tcp,JAUGS N_G Remotec 2   
#define IANAport_ttntspauto         3474			// tcp,TSP Automation   
#define IANAport_genisar_port       3475			// tcp,Genisar Comm Port   
#define IANAport_nppmp              3476			// tcp,NVIDIA Mgmt Protocol   
#define IANAport_ecomm              3477			// tcp,eComm link port   
#define IANAport_stun               3478			// tcp,Session Traversal Utilities for NAT (STUN) port,[RFC8489]  ,
#define IANAport_turn               3478			// tcp,TURN over TCP,[RFC8656]  ,
#define IANAport_stun_behavior      3478			// tcp,STUN Behavior Discovery over TCP,[RFC5780]  ,
#define IANAport_twrpc              3479			// tcp,2Wire RPC   
#define IANAport_plethora           3480			// tcp,Secure Virtual Workspace   
#define IANAport_cleanerliverc      3481			// tcp,CleanerLive remote ctrl   
#define IANAport_vulture            3482			// tcp,Vulture Monitoring System   
#define IANAport_slim_devices       3483			// tcp,Slim Devices Protocol   
#define IANAport_gbs_stp            3484			// tcp,GBS SnapTalk Protocol   
#define IANAport_celatalk           3485			// tcp,CelaTalk   
#define IANAport_ifsf_hb_port       3486			// tcp,IFSF Heartbeat Port   
#define IANAport_ltctcp             3487			// tcp,LISA TCP Transfer Channel   
#define IANAport_fs_rh_srv          3488			// tcp,FS Remote Host Server   
#define IANAport_dtp_dia            3489			// tcp,DTP/DIA   
#define IANAport_colubris           3490			// tcp,Colubris Management Port   
#define IANAport_swr_port           3491			// tcp,SWR Port   
#define IANAport_tvdumtray_port     3492			// tcp,TVDUM Tray Port   
#define IANAport_nut                3493			// tcp,Network UPS Tools,[RFC9271]  ,
#define IANAport_ibm3494            3494			// tcp,IBM 3494   
#define IANAport_seclayer_tcp       3495			// tcp,securitylayer over tcp   
#define IANAport_seclayer_tls       3496			// tcp,securitylayer over tls   
#define IANAport_ipether232port     3497			// tcp,ipEther232Port   
#define IANAport_dashpas_port       3498			// tcp,DASHPAS user port   
#define IANAport_sccip_media        3499			// tcp,SccIP Media   
#define IANAport_rtmp_port          3500			// tcp,RTMP Port   
#define IANAport_isoft_p2p 			    3501			// tcp,iSoft_P2P   
#define IANAport_avinstalldisc 		  3502			// tcp,Avocent Install Discovery   
#define IANAport_lsp_ping 			    3503			// tcp,MPLS LSP_echo Port,[RFC8029]  ,
#define IANAport_ironstorm 			    3504			// tcp,IronStorm game server   
#define IANAport_ccmcomm      			3505			// tcp,CCM communications port   
#define IANAport_apc_3506 		    	3506			// tcp,APC 3506   
#define IANAport_nesh_broker 		    3507			// tcp,Nesh Broker Port   
#define IANAport_interactionweb 	  3508			// tcp,Interaction Web   
#define IANAport_vt_ssl       			3509			// tcp,Virtual Token SSL Port   
#define IANAport_xss_port 		    	3510			// tcp,XSS Port   
#define IANAport_webmail_2    			3511			// tcp,WebMail/2   
#define IANAport_aztec 				      3512			// tcp,Aztec Distribution Port   
#define IANAport_arcpd      				3513			// tcp,Adaptec Remote Protocol   
#define IANAport_must_p2p 	    		3514			// tcp,MUST Peer to Peer   
#define IANAport_must_backplane   	3515			// tcp,MUST Backplane   
#define IANAport_smartcard_port 	  3516			// tcp,Smartcard Port   
#define IANAport_802_11_iapp    		3517			// tcp,IEEE 802.11 WLANs WG IAPP   
#define IANAport_artifact_msg 	  	3518			// tcp,Artifact Message Server   
#define IANAport_nvmsgd       			3519			// tcp,Netvion Messenger Port   
#define IANAport_galileolog 	    	3520			// tcp,Netvion Galileo Log Port   
#define IANAport_mc3ss 	      			3521			// tcp,Telequip Labs MC3SS   
#define IANAport_nssocketport    		3522			// tcp,DO over NSSocketPort   
#define IANAport_odeumservlink 	  	3523			// tcp,Odeum Serverlink   
#define IANAport_ecmport      			3524			// tcp,ECM Server port   
#define IANAport_eisport 			      3525			// tcp,EIS Server port   
#define IANAport_starquiz_port 		  3526			// tcp,starQuiz Port   
#define IANAport_beserver_msg_q 	  3527			// tcp,VERITAS Backup Exec Server   
#define IANAport_jboss_iiop 		    3528			// tcp,JBoss IIOP   
#define IANAport_jboss_iiop_ssl 	  3529			// tcp,JBoss IIOP/SSL   
#define IANAport_gf         				3530			// tcp,Grid Friendly   
#define IANAport_joltid 		      	3531			// tcp,Joltid   
#define IANAport_raven_rmp     			3532			// tcp,Raven Remote Management Control   
#define IANAport_raven_rdp 		    	3533			// tcp,Raven Remote Management Data   
#define IANAport_urld_port 			    3534			// tcp,URL Daemon Port   
#define IANAport_ms_la       				3535			// tcp,MS_LA   
#define IANAport_snac 			      	3536			// tcp,SNAC   
#define IANAport_ni_visa_remote 	  3537			// tcp,Remote NI_VISA port   
#define IANAport_ibm_diradm     		3538			// tcp,IBM Directory Server   
#define IANAport_ibm_diradm_ssl   	3539			// tcp,IBM Directory Server SSL   
#define IANAport_pnrp_port 			    3540			// tcp,PNRP User Port   
#define IANAport_voispeed_port   		3541			// tcp,VoiSpeed Port   
#define IANAport_hacl_monitor 	  	3542			// tcp,HA cluster monitor   
#define IANAport_qftest_lookup 		  3543			// tcp,qftest Lookup Port   
#define IANAport_teredo       			3544			// tcp,Teredo Port,[RFC4380]  ,
#define IANAport_camac 				      3545			// tcp,CAMAC equipment   
#define IANAport_symantec_sim   		3547			// tcp,Symantec SIM   
#define IANAport_interworld 		    3548			// tcp,Interworld   
#define IANAport_tellumat_nms 		  3549			// tcp,Tellumat MDR NMS   
#define IANAport_ssmpp       				3550			// tcp,Secure SMPP   
#define IANAport_apcupsd 		      	3551			// tcp,Apcupsd Information Port   
#define IANAport_taserver     			3552			// tcp,TeamAgenda Server Port   
#define IANAport_rbr_discovery   		3553			// tcp,Red Box Recorder ADP   
#define IANAport_questnotify 		    3554			// tcp,Quest Notification Server   
#define IANAport_razor       				3555			// tcp,Vipul's Razor   
#define IANAport_sky_transport  		3556			// tcp,Sky Transport Protocol   
#define IANAport_personalos_001   	3557			// tcp,PersonalOS Comm Port   
#define IANAport_mcp_port     			3558			// tcp,MCP user port   
#define IANAport_cctv_port 		    	3559			// tcp,CCTV control port   
#define IANAport_iniserve_port 		  3560			// tcp,INIServe port   
#define IANAport_bmc_onekey      		3561			// tcp,BMC_OneKey   
#define IANAport_sdbproxy 			    3562			// tcp,SDBProxy   
#define IANAport_watcomdebug     		3563			// tcp,Watcom Debug   
#define IANAport_esimport 			    3564			// tcp,Electromed SIM port   
#define IANAport_m2pa       				3565			// tcp,M2PA,[RFC4165]  ,
#define IANAport_quest_data_hub    	3566			// tcp,Quest Data Hub   
//#define IANAport_     				    3566			// udp,Reserved   
#define IANAport_dof_eps       			3567			// tcp,DOF Protocol Stack   
#define IANAport_dof_tunnel_sec    	3568			// tcp,DOF Secure Tunnel   
#define IANAport_mbg_ctrl 			    3569			// tcp,Meinberg Control Service   
#define IANAport_mccwebsvr_port 	  3570			// tcp,MCC Web Server Port   
#define IANAport_megardsvr_port 	  3571			// tcp,MegaRAID Server Port   
#define IANAport_megaregsvrport 	  3572			// tcp,Registration Server Port   
#define IANAport_tag_ups_1    			3573			// tcp,Advantage Group UPS Suite   
#define IANAport_dmaf_server 	    	3574			// tcp,DMAF Server   
#define IANAport_ccm_port  			    3575			// tcp,Coalsere CCM Port   
#define IANAport_cmc_port     			3576			// udp,Coalsere CMC Port   
#define IANAport_config_port 	    	3577			// tcp,Configuration Port   
#define IANAport_data_port 			    3578			// tcp,Data Port   
#define IANAport_ttat3lb      			3579			// tcp,Tarantella Load Balancing   
#define IANAport_nati_svrloc 	    	3580			// tcp,NATI_ServiceLocator   
#define IANAport_kfxaclicensing 	  3581			// tcp,Ascent Capture Licensing   
#define IANAport_press      				3582			// tcp,PEG PRESS Server   
#define IANAport_canex_watch     		3583			// tcp,CANEX Watch System   
#define IANAport_u_dbap       			3584			// tcp,U_DBase Access Protocol   
#define IANAport_emprise_lls 	    	3585			// tcp,Emprise License Server   
#define IANAport_emprise_lsc 		    3586			// tcp,License Server Console   
#define IANAport_p2pgroup     			3587			// tcp,Peer to Peer Grouping   
#define IANAport_sentinel 		    	3588			// tcp,Sentinel Server   
#define IANAport_isomair      			3589			// tcp,isomair   
#define IANAport_wv_csp_sms 	    	3590			// tcp,WV CSP SMS Binding   
#define IANAport_gtrack_server 		  3591			// tcp,LOCANIS G_TRACK Server   
#define IANAport_gtrack_ne    			3592			// tcp,LOCANIS G_TRACK NE Port   
#define IANAport_bpmd 				      3593			// tcp,BP Model Debugger   
#define IANAport_mediaspace     		3594			// tcp,MediaSpace   
#define IANAport_shareapp 			    3595			// tcp,ShareApp   
#define IANAport_iw_mmogame 		    3596			// tcp,Illusion Wireless MMOG   
#define IANAport_a14        				3597			// tcp,A14 (AN_to_SC/MM)   
#define IANAport_a15 				        3598			// tcp,A15 (AN_to_AN)   
#define IANAport_quasar_server   		3599			// tcp,Quasar Accounting Server   
#define IANAport_trap_daemon 		    3600			// tcp,text relay_answer   
#define IANAport_visinet_gui    		3601			// tcp,Visinet Gui   
#define IANAport_infiniswitchcl	  	3602			// tcp,InfiniSwitch Mgr Client   
#define IANAport_int_rcv_cntrl 		  3603			// tcp,Integrated Rcvr Control   
#define IANAport_bmc_jmx_port    		3604			// tcp,BMC JMX Port   
#define IANAport_comcam_io 			    3605			// tcp,ComCam IO Port   
#define IANAport_splitlock    			3606			// tcp,Splitlock Server   
#define IANAport_precise_i3 	    	3607			// tcp,Precise I3   
#define IANAport_trendchip_dcp 		  3608			// tcp,Trendchip control protocol   
#define IANAport_cpdi_pidas_cm 		  3609			// tcp,CPDI PIDAS Connection Mon   
#define IANAport_echonet      			3610			// tcp,ECHONET   
#define IANAport_six_degrees 	    	3611			// tcp,Six Degrees Port   
#define IANAport_dataprotector 		  3612			// tcp,Micro Focus Data Protector   
#define IANAport_alaris_disc    		3613			// tcp,Alaris Device Discovery   
#define IANAport_sigma_port 		    3614			// tcp,Satchwell Sigma   
#define IANAport_start_network 		  3615			// tcp,Start Messaging Network   
#define IANAport_cd3o_protocol 		  3616			// tcp,cd3o Control Protocol   
#define IANAport_sharp_server 		  3617			// tcp,ATI SHARP Logic Engine   
#define IANAport_aairnet_1     			3618			// tcp,AAIR_Network 1   
#define IANAport_aairnet_2 		    	3619			// tcp,AAIR_Network 2   
#define IANAport_ep_pcp       			3620			// tcp,EPSON Projector Control Port   
#define IANAport_ep_nsp 			      3621			// tcp,EPSON Network Screen Port   
#define IANAport_ff_lr_port     		3622			// tcp,FF LAN Redundancy Port   
#define IANAport_haipe_discover    	3623			// tcp,HAIPIS Dynamic Discovery   
#define IANAport_dist_upgrade   		3624			// tcp,Distributed Upgrade Port   
#define IANAport_volley 		      	3625			// tcp,Volley   
#define IANAport_bvcdaemon_port   	3626			// tcp,bvControl Daemon   
#define IANAport_jamserverport  		3627			// tcp,Jam Server Port   
#define IANAport_ept_machine    		3628			// tcp,EPT Machine Interface   
#define IANAport_escvpnet 	    		3629			// tcp,ESC/VP.net   
#define IANAport_cs_remote_db 	  	3630			// tcp,C&S Remote Database Port   
#define IANAport_cs_services     		3631			// tcp,C&S Web Services Port   
#define IANAport_distcc       			3632			// tcp,distributed compiler   
#define IANAport_wacp 				      3633			// tcp,Wyrnix AIS port   
#define IANAport_hlibmgr      			3634			// tcp,hNTSP Library Manager   
#define IANAport_sdo        				3635			// tcp,Simple Distributed Objects   
#define IANAport_servistaitsm   		3636			// tcp,SerVistaITSM   
#define IANAport_scservp      			3637			// tcp,Customer Service Port   
#define IANAport_ehp_backup 	    	3638			// tcp,EHP Backup Protocol   
#define IANAport_xap_ha     	  		3639			// tcp,Extensible Automation   
#define IANAport_netplay_port1  		3640			// tcp,Netplay Port 1   
#define IANAport_netplay_port2  		3641			// tcp,Netplay Port 2   
#define IANAport_juxml_port 	    	3642			// tcp,Juxml Replication port   
#define IANAport_audiojuggler    		3643			// tcp,AudioJuggler   
#define IANAport_ssowatch     			3644			// tcp,ssowatch   
#define IANAport_cyc 	        			3645			// tcp,Cyc   
#define IANAport_xss_srv_port   		3646			// tcp,XSS Server Port   
#define IANAport_splitlock_gw   		3647			// tcp,Splitlock Gateway   
#define IANAport_fjcp       				3648			// tcp,Fujitsu Cooperation Port   
#define IANAport_nmmp       				3649			// tcp,Nishioka Miyuki Msg Protocol   
#define IANAport_prismiq_plugin   	3650			// tcp,PRISMIQ VOD plug_in   
#define IANAport_xrpc_registry  		3651			// tcp,XRPC Registry   
#define IANAport_vxcrnbuport    		3652			// tcp,VxCR NBU Default Port   
#define IANAport_tsp 	        			3653			// tcp,Tunnel Setup Protocol,[RFC5572]  ,
#define IANAport_vaprtm       			3654			// tcp,VAP RealTime Messenger   
#define IANAport_abatemgr     			3655			// tcp,ActiveBatch Exec Agent   
#define IANAport_abatjss 	      		3656			// tcp,ActiveBatch Job Scheduler   
#define IANAport_immedianet_bcn   	3657			// tcp,ImmediaNet Beacon   
#define IANAport_ps_ams 	      		3658			// tcp,PlayStation AMS (Secure)   
#define IANAport_apple_sasl 		    3659			// tcp,Apple SASL   
#define IANAport_can_nds_ssl     		3660			// tcp,IBM Tivoli Directory Service using SSL   
#define IANAport_can_ferret_ssl   	3661			// tcp,IBM Tivoli Directory Service using SSL   
#define IANAport_pserver      			3662			// tcp,pserver   
#define IANAport_dtp 	        			3663			// tcp,DIRECWAY Tunnel Protocol   
#define IANAport_ups_engine 	    	3664			// tcp,UPS Engine Port   
#define IANAport_ent_engine 		    3665			// tcp,Enterprise Engine Port   
#define IANAport_eserver_pap 		    3666			// tcp,IBM eServer PAP   
#define IANAport_infoexch 			    3667			// tcp,IBM Information Exchange   
#define IANAport_dell_rm_port 		  3668			// tcp,Dell Remote Management   
#define IANAport_casanswmgmt     		3669			// tcp,CA SAN Switch Management   
#define IANAport_smile      				3670			// tcp,SMILE TCP/UDP Interface   
#define IANAport_efcp       				3671			// tcp,e Field Control (EIBnet)   
#define IANAport_lispworks_orb  		3672			// tcp,LispWorks ORB   
#define IANAport_mediavault_gui   	3673			// tcp,Openview Media Vault GUI   
#define IANAport_wininstall_ipc   	3674			// tcp,WinINSTALL IPC Port   
#define IANAport_calltrax     			3675			// tcp,CallTrax Data Port   
#define IANAport_va_pacbase     		3676			// tcp,VisualAge Pacbase server   
#define IANAport_roverlog     			3677			// tcp,RoverLog IPC   
#define IANAport_ipr_dglt     			3678			// tcp,DataGuardianLT   
#define IANAport_Escale_Newton_Dock	3679			// tcp,Newton Dock   
#define IANAport_npds_tracker   		3680			// tcp,NPDS Tracker   
#define IANAport_bts_x73      			3681			// tcp,BTS X73 Port   
#define IANAport_cas_mapi     			3682			// tcp,EMC SmartPackets_MAPI   
#define IANAport_bmc_ea 	      		3683			// tcp,BMC EDV/EA   
#define IANAport_faxstfx_port   		3684			// tcp,FAXstfX   
#define IANAport_dsx_agent    			3685			// tcp,DS Expert Agent   
#define IANAport_tnmpv2 	      		3686			// tcp,Trivial Network Management   
#define IANAport_simple_push    		3687			// tcp,simple_push   
#define IANAport_simple_push_s  		3688			// tcp,simple_push Secure   
#define IANAport_daap       				3689			// tcp,Digital Audio Access Protocol (iTunes)   
#define IANAport_svn 	        			3690			// tcp,Subversion   
#define IANAport_magaya_network   	3691			// tcp,Magaya Network Port   
#define IANAport_intelsync    			3692			// tcp,Brimstone IntelSync   
#define IANAport_easl 	      			3693			// tcp,Emergency Automatic Structure Lockdown System   
//#define IANAport_				          3693			// udp,Reserved   
#define IANAport_bmc_data_coll   		3695			// tcp,BMC Data Collection   
#define IANAport_telnetcpcd     		3696			// tcp,Telnet Com Port Control   
#define IANAport_nw_license     		3697			// tcp,NavisWorks License System   
#define IANAport_sagectlpanel   		3698			// tcp,SAGECTLPANEL   
#define IANAport_kpn_icw      			3699			// tcp,Internet Call Waiting   
#define IANAport_lrs_paging 	    	3700			// tcp,LRS NetPage   
#define IANAport_netcelera 			    3701			// tcp,NetCelera   
#define IANAport_ws_discovery    		3702			// tcp,Web Service Discovery   
#define IANAport_adobeserver_3 	  	3703			// tcp,Adobe Server 3   
#define IANAport_adobeserver_4 		  3704			// tcp,Adobe Server 4   
#define IANAport_adobeserver_5 		  3705			// tcp,Adobe Server 5   
#define IANAport_rt_event     			3706			// tcp,Real_Time Event Port   
#define IANAport_rt_event_s 	    	3707			// tcp,Real_Time Event Secure Port   
#define IANAport_sun_as_iiops 		  3708			// tcp,Sun App Svr _ Naming   
#define IANAport_ca_idms      			3709			// tcp,CA_IDMS Server   
#define IANAport_portgate_auth   		3710			// tcp,PortGate Authentication   
#define IANAport_edb_server2 		    3711			// tcp,EBD Server 2   
#define IANAport_sentinel_ent   		3712			// tcp,Sentinel Enterprise   
#define IANAport_tftps      				3713			// tcp,TFTP over TLS   
#define IANAport_delos_dms 	    		3714			// tcp,DELOS Direct Messaging   
#define IANAport_anoto_rendezv 	  	3715			// tcp,Anoto Rendezvous Port   
#define IANAport_wv_csp_sms_cir 	  3716			// tcp,WV CSP SMS CIR Channel   
#define IANAport_wv_csp_udp_cir 	  3717			// udp,WV CSP UDP/IP CIR Channel   
#define IANAport_opus_services 		  3718			// tcp,OPUS Server Port   
#define IANAport_itelserverport 	  3719			// tcp,iTel Server Port   
#define IANAport_ufastro_instr 		  3720			// tcp,UF Astro. Instr. Services   
#define IANAport_xsync 	      			3721			// tcp,Xsync   
#define IANAport_xserveraid 	    	3722			// tcp,Xserve RAID   
#define IANAport_sychrond 			    3723			// tcp,Sychron Service Daemon   
#define IANAport_blizwow      			3724			// tcp,World of Warcraft   
#define IANAport_na_er_tip 		    	3725			// tcp,Netia NA_ER Port   
#define IANAport_array_manager 		  3726			// tcp,Xyratex Array Manager   
#define IANAport_e_mdu      				3727			// tcp,Ericsson Mobile Data Unit   
#define IANAport_e_woa 			      	3728			// tcp,Ericsson Web on Air   
#define IANAport_fksp_audit 		    3729			// tcp,Fireking Audit Port   
#define IANAport_client_ctrl    		3730			// tcp,Client Control   
#define IANAport_smap       				3731			// tcp,Service Manager   
#define IANAport_m_wnn 			      	3732			// tcp,Mobile Wnn   
#define IANAport_multip_msg     		3733			// tcp,Multipuesto Msg Port   
#define IANAport_synel_data 		    3734			// tcp,Synel Data Collection Port   
#define IANAport_pwdis      				3735			// tcp,Password Distribution   
#define IANAport_rs_rmi 		      	3736			// tcp,RealSpace RMI   
#define IANAport_xpanel        			3737			// tcp,XPanel Daemon   
//#define IANAport_				          3737			// udp,Reserved   
#define IANAport_versatalk 	    		3738			// tcp,versaTalk Server Port   
#define IANAport_launchbird_lm 	  	3739			// tcp,Launchbird LicenseManager   
#define IANAport_heartbeat    			3740			// tcp,Heartbeat Protocol   
#define IANAport_wysdma 			      3741			// tcp,WysDM Agent   
#define IANAport_cst_port     			3742			// tcp,CST _ Configuration & Service Tracker   
#define IANAport_ipcs_command   		3743			// tcp,IP Control Systems Ltd.   
#define IANAport_sasg 	      			3744			// tcp,SASG   
#define IANAport_gw_call_port   		3745			// tcp,GWRTC Call Port   
#define IANAport_linktest 			    3746			// tcp,LXPRO.COM LinkTest   
#define IANAport_linktest_s     		3747			// tcp,LXPRO.COM LinkTest SSL   
#define IANAport_webdata 			      3748			// tcp,webData   
#define IANAport_cimtrak      			3749			// tcp,CimTrak   
#define IANAport_cbos_ip_port   		3750			// tcp,CBOS/IP ncapsalation port   
#define IANAport_gprs_cube 			    3751			// tcp,CommLinx GPRS Cube   
#define IANAport_vipremoteagent   	3752			// tcp,Vigil_IP RemoteAgent   
#define IANAport_nattyserver 	    	3753			// tcp,NattyServer Port   
#define IANAport_timestenbroker    	3754			// tcp,TimesTen Broker Port   
#define IANAport_sas_remote_hlp 	  3755			// tcp,SAS Remote Help Server   
#define IANAport_canon_capt      		3756			// tcp,Canon CAPT Port   
#define IANAport_grf_port 			    3757			// tcp,GRF Server Port   
#define IANAport_apw_registry   		3758			// tcp,apw RMI registry   
#define IANAport_exapt_lmgr 		    3759			// tcp,Exapt License Manager   
#define IANAport_adtempusclient   	3760			// tcp,adTempus Client   
#define IANAport_gsakmp       			3761			// tcp,gsakmp port,[RFC4535]  ,
#define IANAport_gbs_smp 			      3762			// tcp,GBS SnapMail Protocol   
#define IANAport_xo_wave      			3763			// tcp,XO Wave Control Port   
#define IANAport_mni_prot_rout   		3764			// tcp,MNI Protected Routing   
#define IANAport_rtraceroute 		    3765			// tcp,Remote Traceroute   
#define IANAport_sitewatch_s     		3766			// tcp,SSL e_watch sitewatch server   
//#define IANAport_		      		    3766			// udp,Reserved   
#define IANAport_listmgr_port   		3767			// tcp,ListMGR Port   
#define IANAport_rblcheckd 			    3768			// tcp,rblcheckd server daemon   
#define IANAport_haipe_otnk      		3769			// tcp,HAIPE Network Keying   
#define IANAport_cindycollab 		    3770			// tcp,Cinderella Collaboration   
#define IANAport_paging_port 		    3771			// tcp,RTP Paging Port   
#define IANAport_ctp        				3772			// tcp,Chantry Tunnel Protocol   
#define IANAport_ctdhercules     		3773			// tcp,ctdhercules   
#define IANAport_zicom      				3774			// tcp,ZICOM   
#define IANAport_ispmmgr 		      	3775			// tcp,ISPM Manager Port   
#define IANAport_dvcprov_port 		  3776			// tcp,Device Provisioning Port   
#define IANAport_jibe_eb      			3777			// tcp,Jibe EdgeBurst   
#define IANAport_c_h_it_port 	    	3778			// tcp,Cutler_Hammer IT Port   
#define IANAport_cognima      			3779			// tcp,Cognima Replication   
#define IANAport_nnp 		        		3780			// tcp,Nuzzler Network Protocol   
#define IANAport_abcvoice_port 	  	3781			// tcp,ABCvoice server port   
#define IANAport_iso_tp0s     			3782			// tcp,Secure ISO TP0 port   
#define IANAport_bim_pem 			      3783			// tcp,Impact Mgr./PEM Gateway   
#define IANAport_bfd_control    		3784			// tcp,BFD Control Protocol,[RFC5881]  ,
#define IANAport_bfd_echo 			    3785			// tcp,BFD Echo Protocol,[RFC5881]  ,
#define IANAport_upstriggervsw  		3786			// tcp,VSW Upstrigger port   
#define IANAport_fintrx       			3787			// tcp,Fintrx   
#define IANAport_isrp_port 		    	3788			// tcp,SPACEWAY Routing port   
#define IANAport_remotedeploy 		  3789			// tcp,RemoteDeploy Administration Port [July 2003]   
#define IANAport_quickbooksrds  		3790			// tcp,QuickBooks RDS   
#define IANAport_tvnetworkvideo   	3791			// tcp,TV NetworkVideo Data port   
#define IANAport_sitewatch    			3792			// tcp,e_Watch Corporation SiteWatch   
#define IANAport_dcsoftware 	    	3793			// tcp,DataCore Software   
#define IANAport_jaus       				3794			// tcp,JAUS Robots   
#define IANAport_myblast 		      	3795			// tcp,myBLAST Mekentosj port   
#define IANAport_spw_dialer     		3796			// tcp,Spaceway Dialer   
#define IANAport_idps       				3797			// tcp,idps   
#define IANAport_minilock 	    		3798			// tcp,Minilock   
#define IANAport_radius_dynauth   	3799			// tcp,RADIUS Dynamic Authorization,[RFC3576]  ,
#define IANAport_pwgpsi       			3800			// tcp,Print Services Interface   
#define IANAport_ibm_mgr 			      3801			// tcp,ibm manager service   
#define IANAport_vhd        				3802			// tcp,VHD   
#define IANAport_soniqsync 	    		3803			// tcp,SoniqSync   
#define IANAport_iqnet_port 		    3804			// tcp,Harman IQNet Port   
#define IANAport_tcpdataserver 		  3805			// tcp,ThorGuard Server Port   
#define IANAport_wsmlb      				3806			// tcp,Remote System Manager   
#define IANAport_spugna 		      	3807			// tcp,SpuGNA Communication Port   
#define IANAport_sun_as_iiops_ca 	  3808			// tcp,Sun App Svr_IIOPClntAuth   
#define IANAport_apocd      				3809			// tcp,Java Desktop System Configuration Agent   
#define IANAport_wlanauth 	    		3810			// tcp,WLAN AS server   
#define IANAport_amp        				3811			// tcp,AMP   
#define IANAport_neto_wol_server  	3812			// tcp,netO WOL Server   
#define IANAport_rap_ip       			3813			// tcp,Rhapsody Interface Protocol   
#define IANAport_neto_dcs 		    	3814			// tcp,netO DCS   
#define IANAport_lansurveyorxml 	  3815			// tcp,LANsurveyor XML   
#define IANAport_sunlps_http    		3816			// tcp,Sun Local Patch Server   
#define IANAport_tapeware 			    3817			// tcp,Yosemite Tech Tapeware   
#define IANAport_crinis_hb    			3818			// tcp,Crinis Heartbeat   
#define IANAport_epl_slp 			      3819			// tcp,EPL Sequ Layer Protocol   
#define IANAport_scp        				3820			// tcp,Siemens AuD SCP   
#define IANAport_pmcp 			      	3821			// tcp,ATSC PMCP Standard   
#define IANAport_acp_discovery 		  3822			// tcp,Compute Pool Discovery   
#define IANAport_acp_conduit    		3823			// tcp,Compute Pool Conduit   
#define IANAport_acp_policy 		    3824			// tcp,Compute Pool Policy   
#define IANAport_ffserver      			3825			// tcp,Antera FlowFusion Process Simulation   
#define IANAport_warmux 			      3826			// tcp,WarMUX game server   
#define IANAport_netmpi       			3827			// tcp,Netadmin Systems MPI service   
#define IANAport_neteh 				      3828			// tcp,Netadmin Systems Event Handler   
#define IANAport_neteh_ext     			3829			// tcp,Netadmin Systems Event Handler External   
#define IANAport_cernsysmgmtagt    	3830			// tcp,Cerner System Management Agent   
#define IANAport_dvapps       			3831			// tcp,Docsvault Application Service   
#define IANAport_xxnetserver 	    	3832			// tcp,xxNETserver   
#define IANAport_aipn_auth    			3833			// tcp,AIPN LS Authentication   
#define IANAport_spectardata 	    	3834			// tcp,Spectar Data Stream Service   
#define IANAport_spectardb 			    3835			// tcp,Spectar Database Rights Service   
#define IANAport_markem_dcp     		3836			// tcp,MARKEM NEXTGEN DCP   
#define IANAport_mkm_discovery 	    3837			// tcp,MARKEM Auto_Discovery   
#define IANAport_sos        				3838			// tcp,Scito Object Server   
#define IANAport_amx_rms 		      	3839			// tcp,AMX Resource Management Suite   
#define IANAport_flirtmitmir    		3840			// tcp,www.FlirtMitMir.de   
#define IANAport_shiprush_db_svr   	3841			// tcp,ShipRush Database Server   
//#define IANAport_	      			    3841			// udp,Reserved   
#define IANAport_nhci 		      		3842			// tcp,NHCI status port   
#define IANAport_quest_agent 		    3843			// tcp,Quest Common Agent   
#define IANAport_rnm        				3844			// tcp,RNM   
#define IANAport_v_one_spp 	    		3845			// tcp,V_ONE Single Port Proxy   
#define IANAport_an_pcp        			3846			// tcp,Astare Network PCP   
#define IANAport_msfw_control   		3847			// tcp,MS Firewall Control   
#define IANAport_item       				3848			// tcp,IT Environmental Monitor   
#define IANAport_spw_dnspreload   	3849			// tcp,SPACEWAY DNS Preload   
#define IANAport_qtms_bootstrap   	3850			// tcp,QTMS Bootstrap Protocol   
#define IANAport_spectraport    		3851			// tcp,SpectraTalk Port   
#define IANAport_sse_app_config   	3852			// tcp,SSE App Configuration   
#define IANAport_sscan      				3853			// tcp,SONY scanning protocol   
#define IANAport_stryker_com     		3854			// tcp,Stryker Comm Port   
#define IANAport_opentrac 			    3855			// tcp,OpenTRAC   
#define IANAport_informer     			3856			// tcp,INFORMER   
#define IANAport_trap_port 		    	3857			// tcp,Trap Port   
#define IANAport_trap_port_mom 		  3858			// tcp,Trap Port MOM   
#define IANAport_nav_port     			3859			// tcp,Navini Port   
#define IANAport_sasp 				      3860			// tcp,Server/Application State Protocol (SASP)   
#define IANAport_winshadow_hd   		3861			// tcp,winShadow Host Discovery   
#define IANAport_giga_pocket     		3862			// tcp,GIGA_POCKET   
#define IANAport_asap_tcp 			    3863			// tcp,asap tcp port   
#define IANAport_asap_sctp    			3863			// sctp,asap sctp,[RFC5352]  ,
//#define IANAport_		      		    3864			// udp,Reserved   
#define IANAport_asap_sctp_tls  		3864			// sctp,asap_sctp/tls,[RFC5352]  ,
#define IANAport_xpl        				3865			// tcp,xpl automation protocol   
#define IANAport_dzdaemon     			3866			// tcp,Sun SDViz DZDAEMON Port   
#define IANAport_dzoglserver    		3867			// tcp,Sun SDViz DZOGLSERVER Port   
#define IANAport_diameter     			3868			// tcp,DIAMETER   ,[RFC3588]
#define IANAport_ovsam_mgmt     		3869			// tcp,hp OVSAM MgmtServer Disco   
#define IANAport_ovsam_d_agent  		3870			// tcp,hp OVSAM HostAgent Disco   
#define IANAport_avocent_adsap  		3871			// tcp,Avocent DS Authorization   
#define IANAport_oem_agent    			3872			// tcp,OEM Agent   
#define IANAport_fagordnc     			3873			// tcp,fagordnc   
#define IANAport_sixxsconfig    		3874			// tcp,SixXS Configuration   
#define IANAport_pnbscada 			    3875			// tcp,PNBSCADA   
#define IANAport_dl_agent 	    		3876			// tcp,"DirectoryLockdown Agent IANA assigned this well_formed service name as a replacement for ""dl_agent""."   
#define IANAport_xmpcr_interface   	3877			// tcp,XMPCR Interface Port   
#define IANAport_fotogcad     			3878			// tcp,FotoG CAD interface   
#define IANAport_appss_lm 		    	3879			// tcp,appss license manager   
#define IANAport_igrs        				3880			// tcp,IGRS   
#define IANAport_idac 			      	3881			// tcp,Data Acquisition and Control   
#define IANAport_msdts1       			3882			// tcp,DTS Service Port   
#define IANAport_vrpn 				      3883			// tcp,VR Peripheral Network   
#define IANAport_softrack_meter   	3884			// tcp,SofTrack Metering   
#define IANAport_topflow_ssl    		3885			// tcp,TopFlow SSL   
#define IANAport_nei_management   	3886			// tcp,NEI management port   
#define IANAport_ciphire_data   		3887			// tcp,Ciphire Data Transport   
#define IANAport_ciphire_serv   		3888			// tcp,Ciphire Services   
#define IANAport_dandv_tester   		3889			// tcp,D and V Tester Control Port   
#define IANAport_ndsconnect     		3890			// tcp,Niche Data Server Connect   
#define IANAport_rtc_pm_port    		3891			// tcp,Oracle RTC_PM port   
#define IANAport_pcc_image_port   	3892			// tcp,PCC_image_port   
#define IANAport_cgi_starapi     		3893			// tcp,CGI StarAPI Server   
#define IANAport_syam_agent     		3894			// tcp,SyAM Agent Port   
#define IANAport_syam_smc     			3895			// tcp,SyAm SMC Service Port   
#define IANAport_sdo_tls 	      		3896			// tcp,Simple Distributed Objects over TLS   
#define IANAport_sdo_ssh      			3897			// tcp,Simple Distributed Objects over SSH   
#define IANAport_senip 	      			3898			// tcp,"IAS, Inc. SmartEye NET Internet Protocol"   
#define IANAport_itv_control    		3899			// tcp,ITV Port   
#define IANAport_udt_os_2 			    3900			// tcp,"Unidata UDT OS IANA assigned this well_formed service name as a replacement for ""udt_os""." - Note amended 
#define IANAport_nimsh      				3901			// tcp,NIM Service Handler   
#define IANAport_nimaux 		      	3902			// tcp,NIMsh Auxiliary Port   
#define IANAport_charsetmgr     		3903			// tcp,CharsetMGR   
#define IANAport_omnilink_port  		3904			// tcp,Arnet Omnilink Port   
#define IANAport_mupdate      			3905			// tcp,Mailbox Update (MUPDATE) protocol,[RFC3656]  ,
#define IANAport_topovista_data   	3906			// tcp,TopoVista elevation data   
#define IANAport_imoguia_port   		3907			// tcp,Imoguia Port   
#define IANAport_hppronetman 	    	3908			// tcp,HP Procurve NetManagement   
#define IANAport_surfcontrolcpa   	3909			// tcp,SurfControl CPA   
#define IANAport_prnrequest     		3910			// tcp,Printer Request Port   
#define IANAport_prnstatus 	    		3911			// tcp,Printer Status Port   
#define IANAport_gbmt_stars     		3912			// tcp,Global Maintech Stars   
#define IANAport_listcrt_port   		3913			// tcp,ListCREATOR Port   
#define IANAport_listcrt_port_2   	3914			// tcp,ListCREATOR Port 2   
#define IANAport_agcat 	      			3915			// tcp,Auto_Graphics Cataloging   
#define IANAport_wysdmc       			3916			// tcp,WysDM Controller   
#define IANAport_aftmux 	      		3917			// tcp,AFT multiplex port   
#define IANAport_pktcablemmcops   	3918			// tcp,PacketCableMultimediaCOPS   
#define IANAport_hyperip 	      		3919			// tcp,HyperIP   
#define IANAport_exasoftport1   		3920			// tcp,Exasoft IP Port   
#define IANAport_herodotus_net  		3921			// tcp,Herodotus Net   
#define IANAport_sor_update     		3922			// tcp,Soronti Update Port   
#define IANAport_symb_sb_port   		3923			// tcp,Symbian Service Broker   
#define IANAport_mpl_gprs_port  		3924			// tcp,MPL_GPRS_PORT   
#define IANAport_zmp 		        		3925			// tcp,Zoran Media Port   
#define IANAport_winport 	      		3926			// tcp,WINPort   
#define IANAport_natdataservice   	3927			// tcp,ScsTsr   
#define IANAport_netboot_pxe    		3928			// tcp,PXE NetBoot Manager   
#define IANAport_smauth_port 	    	3929			// tcp,AMS Port   
#define IANAport_syam_webserver   	3930			// tcp,Syam Web Server Port   
#define IANAport_msr_plugin_port   	3931			// tcp,MSR Plugin Port   
#define IANAport_dyn_site 	    		3932			// tcp,Dynamic Site System   
#define IANAport_plbserve_port  		3933			// tcp,PL/B App Server User Port   
#define IANAport_sunfm_port     		3934			// tcp,PL/B File Manager Port   
#define IANAport_sdp_portmapper   	3935			// tcp,SDP Port Mapper Protocol   
#define IANAport_mailprox     			3936			// tcp,Mailprox   
#define IANAport_dvbservdsc     		3937			// tcp,DVB Service Discovery   
#define IANAport_dbcontrol_agent   	3938			// tcp,"Oracle dbControl Agent po IANA assigned this well_formed service name as a replacement for ""dbcontrol_agent""."   
#define IANAport_aamp       				3939			// tcp,Anti_virus Application Management Port   
#define IANAport_xecp_node    			3940			// tcp,XeCP Node Service   
#define IANAport_homeportal_web   	3941			// tcp,Home Portal Web Server   
#define IANAport_srdp       				3942			// tcp,satellite distribution   
#define IANAport_tig 		        		3943			// tcp,TetraNode Ip Gateway   
#define IANAport_sops 	      			3944			// tcp,S_Ops Management   
#define IANAport_emcads 	      		3945			// tcp,EMCADS Server Port   
#define IANAport_backupedge     		3946			// tcp,BackupEDGE Server   
#define IANAport_ccp 		        		3947			// tcp,"Connect and Control Protocol for Consumer, Commercial, and Industrial Electronic Devices"   
#define IANAport_apdap 	      			3948			// tcp,Anton Paar Device Administration Protocol   
#define IANAport_drip 	      			3949			// tcp,Dynamic Routing Information Protocol   
#define IANAport_namemunge    			3950			// tcp,Name Munging   
#define IANAport_pwgippfax 	    		3951			// tcp,PWG IPP Facsimile   
#define IANAport_i3_sessionmgr 	  	3952			// tcp,I3 Session Manager   
#define IANAport_xmlink_connect   	3953			// tcp,Eydeas XMLink Connect   
#define IANAport_adrep 	      			3954			// tcp,AD Replication RPC   
#define IANAport_p2pcommunity   		3955			// tcp,p2pCommunity   
#define IANAport_gvcp       				3956			// tcp,GigE Vision Control   
#define IANAport_mqe_broker     		3957			// tcp,MQEnterprise Broker   
#define IANAport_mqe_agent 	    		3958			// tcp,MQEnterprise Agent   
#define IANAport_treehopper     		3959			// tcp,Tree Hopper Networking   
#define IANAport_bess 	      			3960			// tcp,Bess Peer Assessment   
#define IANAport_proaxess     			3961			// tcp,ProAxess Server   
#define IANAport_sbi_agent    			3962			// tcp,SBI Agent Protocol   
#define IANAport_thrp 	      			3963			// tcp,Teran Hybrid Routing Protocol   
#define IANAport_sasggprs     			3964			// tcp,SASG GPRS   
#define IANAport_ati_ip_to_ncpe   	3965			// tcp,Avanti IP to NCPE API   
#define IANAport_bflckmgr     			3966			// tcp,BuildForge Lock Manager   
#define IANAport_ppsms 		      		3967			// tcp,PPS Message Service   
#define IANAport_ianywhere_dbns   	3968			// tcp,iAnywhere DBNS   
#define IANAport_landmarks 	    		3969			// tcp,Landmark Messages   
#define IANAport_lanrevagent    		3970			// tcp,LANrev Agent   
#define IANAport_lanrevserver   		3971			// tcp,LANrev Server   
#define IANAport_iconp 	      			3972			// tcp,ict_control Protocol   
#define IANAport_progistics     		3973			// tcp,ConnectShip Progistics   
#define IANAport_xk22 		      		3974			// tcp,Remote Applicant Tracking Service   
#define IANAport_airshot 	      		3975			// tcp,Air Shot   
#define IANAport_opswagent 	    		3976			// tcp,Server Automation Agent   
#define IANAport_opswmanager    		3977			// tcp,Opsware Manager   
#define IANAport_secure_cfg_svr   	3978			// tcp,Secured Configuration Server   
#define IANAport_smwan 	      			3979			// tcp,Smith Micro Wide Area Network Service   
//#define IANAport_			      	    3980			// tcp,Reserved   
//#define IANAport_			      	    3980			// udp,Reserved   
#define IANAport_starfish     			3981			// tcp,Starfish System Admin   
#define IANAport_eis 		        		3982			// tcp,ESRI Image Server   
#define IANAport_eisp 		      		3983			// tcp,ESRI Image Service   
#define IANAport_mapper_nodemgr   	3984			// tcp,MAPPER network node manager   
#define IANAport_mapper_mapethd   	3985			// tcp,MAPPER TCP/IP server   
#define IANAport_mapper_ws_ethd   	3986			// tcp,"MAPPER workstation server IANA assigned this well_formed service name as a replacement for ""mapper_ws_ethd""."   
#define IANAport_centerline     		3987			// tcp,Centerline   
#define IANAport_dcs_config     		3988			// tcp,DCS Configuration Port   
#define IANAport_bv_queryengine   	3989			// tcp,BindView_Query Engine   
#define IANAport_bv_is 		      		3990			// tcp,BindView_IS   
#define IANAport_bv_smcsrv 	    		3991			// tcp,BindView_SMCServer   
#define IANAport_bv_ds 			      	3992			// tcp,BindView_DirectoryServer   
#define IANAport_bv_agent 	    		3993			// tcp,BindView_Agent   
#define IANAport_iss_mgmt_ssl   		3995			// tcp,ISS Management Svcs SSL   
#define IANAport_abcsoftware 	    	3996			// tcp,abcsoftware_01   
#define IANAport_agentsease_db 	  	3997			// tcp,aes_db   
#define IANAport_dnx 	        			3998			// tcp,Distributed Nagios Executor Service   
#define IANAport_nvcnet       			3999			// tcp,Norman distributes scanning service   
#define IANAport_terabase     			4000			// tcp,Terabase   
#define IANAport_newoak 	      		4001			// tcp,NewOak   
#define IANAport_pxc_spvr_ft    		4002			// tcp,pxc_spvr_ft   
#define IANAport_pxc_splr_ft    		4003			// tcp,pxc_splr_ft   
#define IANAport_pxc_roid 	    		4004			// tcp,pxc_roid   
#define IANAport_pxc_pin 	      		4005			// tcp,pxc_pin   
#define IANAport_pxc_spvr     			4006			// tcp,pxc_spvr   
#define IANAport_pxc_splr     			4007			// tcp,pxc_splr   
#define IANAport_netcheque 	    		4008			// tcp,NetCheque accounting   
#define IANAport_chimera_hwm 	    	4009			// tcp,Chimera HWM   
#define IANAport_samsung_unidex   	4010			// tcp,Samsung Unidex   
#define IANAport_altserviceboot   	4011			// tcp,Alternate Service Boot   
#define IANAport_pda_gate     			4012			// tcp,PDA Gate   
#define IANAport_acl_manager    		4013			// tcp,ACL Manager   
#define IANAport_taiclock 	    		4014			// tcp,TAICLOCK   
#define IANAport_talarian_mcast1  	4015			// tcp,Talarian Mcast   
#define IANAport_talarian_mcast2   	4016			// tcp,Talarian Mcast   
#define IANAport_talarian_mcast3  	4017			// tcp,Talarian Mcast   
#define IANAport_talarian_mcast4  	4018			// tcp,Talarian Mcast   
#define IANAport_talarian_mcast5  	4019			// tcp,Talarian Mcast   
#define IANAport_trap 			      	4020			// tcp,TRAP Port   
#define IANAport_nexus_portal 	  	4021			// tcp,Nexus Portal   
#define IANAport_dnox 			      	4022			// tcp,DNOX   
#define IANAport_esnm_zoning    		4023			// tcp,ESNM Zoning Port   
#define IANAport_tnp1_port 	    		4024			// tcp,TNP1 User Port   
#define IANAport_partimage 	    		4025			// tcp,Partition Image Port   
#define IANAport_as_debug     			4026			// tcp,Graphical Debug Server   
#define IANAport_bxp 			        	4027			// tcp,bitxpress   
#define IANAport_dtserver_port  		4028			// tcp,DTServer Port   
#define IANAport_ip_qsig 	      		4029			// tcp,IP Q signaling protocol   
#define IANAport_jdmn_port    			4030			// tcp,Accell/JSP Daemon Port   
#define IANAport_suucp 		      		4031			// tcp,UUCP over SSL   
#define IANAport_vrts_auth_port   	4032			// tcp,VERITAS Authorization Service   
#define IANAport_sanavigator    		4033			// tcp,SANavigator Peer Port   
#define IANAport_ubxd       				4034			// tcp,Ubiquinox Daemon   
#define IANAport_wap_push_http  		4035			// tcp,WAP Push OTA_HTTP port   
#define IANAport_wap_push_https   	4036			// tcp,WAP Push OTA_HTTP secure   
#define IANAport_ravehd       			4037			// tcp,RaveHD network control   
#define IANAport_fazzt_ptp 	    		4038			// tcp,Fazzt Point_To_Point   
#define IANAport_fazzt_admin    		4039			// tcp,Fazzt Administration   
#define IANAport_yo_main      			4040			// tcp,Yo.net main service   
#define IANAport_houston      			4041			// tcp,Rocketeer_Houston   
#define IANAport_ldxp 	      			4042			// tcp,LDXP   
#define IANAport_nirp       				4043			// tcp,Neighbour Identity Resolution   
#define IANAport_ltp 		        		4044			// tcp,Location Tracking Protocol   
#define IANAport_npp_npp	      		4045			// tcp,Network Paging Protocol - Note amended
#define IANAport_acp_proto 	    		4046			// tcp,Accounting Protocol   
#define IANAport_ctp_state 	    		4047			// tcp,Context Transfer Protocol   
#define IANAport_wafs 	      			4049			// tcp,Wide Area File Services   
#define IANAport_cisco_wafs     		4050			// tcp,Wide Area File Services   
#define IANAport_cppdp 	      			4051			// tcp,Cisco Peer to Peer Distribution Protocol   
#define IANAport_interact 	    		4052			// tcp,VoiceConnect Interact   
#define IANAport_ccu_comm_1     		4053			// tcp,CosmoCall Universe Communications Port 1   
#define IANAport_ccu_comm_2     		4054			// tcp,CosmoCall Universe Communications Port 2   
#define IANAport_ccu_comm_3     		4055			// tcp,CosmoCall Universe Communications Port 3   
#define IANAport_lms 	        			4056			// tcp,Location Message Service   
#define IANAport_wfm 	        			4057			// tcp,Servigistics WFM server   
#define IANAport_kingfisher     		4058			// tcp,Kingfisher protocol   
#define IANAport_dlms_cosem 	    	4059			// tcp,DLMS/COSEM   
#define IANAport_dsmeter_iatc   		4060			// tcp,"DSMETER Inter_Agent Transfer Channel IANA assigned this well_formed service name as a replacement for ""dsmeter_iatc""."   
#define IANAport_ice_location   		4061			// tcp,Ice Location Service (TCP)   
#define IANAport_ice_slocation  		4062			// tcp,Ice Location Service (SSL)   
#define IANAport_ice_router     		4063			// tcp,Ice Firewall Traversal Service (TCP)   
#define IANAport_ice_srouter    		4064			// tcp,Ice Firewall Traversal Service (SSL)   
#define IANAport_avanti_cdp     		4065			// tcp,"Avanti Common Data IANA assigned this well_formed service name as a replacement for ""avanti_cdp""."   
#define IANAport_pmas 	      			4066			// tcp,Performance Measurement and Analysis   
#define IANAport_idp 		        		4067			// tcp,Information Distribution Protocol   
#define IANAport_ipfltbcst    			4068			// tcp,IP Fleet Broadcast   
#define IANAport_minger 	      		4069			// tcp,Minger Email Address Validation Service   
#define IANAport_tripe 	      			4070			// tcp,Trivial IP Encryption (TrIPE)   
#define IANAport_aibkup       			4071			// tcp,Automatically Incremental Backup   
#define IANAport_zieto_sock     		4072			// tcp,Zieto Socket Communications   
#define IANAport_iRAPP 		      		4073			// tcp,Interactive Remote Application Pairing Protocol   
#define IANAport_cequint_cityid   	4074			// tcp,Cequint City ID UI trigger   
#define IANAport_perimlan     			4075			// tcp,ISC Alarm Message Service   
#define IANAport_seraph 	      		4076			// tcp,Seraph DCS   
//#define IANAport_			      	    4077			// tcp,Reserved   
#define IANAport_ascomalarm     		4077			// udp,Ascom IP Alarming   
#define IANAport_cssp 	      			4078			// tcp,Coordinated Security Service Protocol   
//#define IANAport_		      		    4078			// udp,Reserved   
#define IANAport_santools     			4079			// tcp,SANtools Diagnostic Server   
#define IANAport_lorica_in 	    		4080			// tcp,Lorica inside facing   
#define IANAport_lorica_in_sec  		4081			// tcp,Lorica inside facing (SSL)   
#define IANAport_lorica_out     		4082			// tcp,Lorica outside facing   
#define IANAport_lorica_out_sec   	4083			// tcp,Lorica outside facing (SSL)   
//#define IANAport_			      	    4084			// tcp,Reserved   
#define IANAport_fortisphere_vm   	4084			// udp,Fortisphere VM Service   
#define IANAport_ezmessagesrv   		4085			// tcp,EZNews Newsroom Message Service   
//#define IANAport_		       		    4085			// udp,Reserved   
//#define IANAport_		      		    4086			// tcp,Reserved   
#define IANAport_ftsync 	      		4086			// udp,Firewall/NAT state table synchronization   
#define IANAport_applusservice  		4087			// tcp,APplus Service   
//#define IANAport_			      	    4087			// udp,Reserved   
#define IANAport_npsp 	      			4088			// tcp,Noah Printing Service Protocol   
//#define IANAport_			      	    4088			// udp,Reserved   
#define IANAport_opencore     			4089			// tcp,OpenCORE Remote Control Service   
#define IANAport_omasgport    			4090			// tcp,OMA BCAST Service Guide   
#define IANAport_ewinstaller    		4091			// tcp,EminentWare Installer   
#define IANAport_ewdgs 		      		4092			// tcp,EminentWare DGS   
#define IANAport_pvxpluscs 	    		4093			// tcp,Pvx Plus CS Host   
#define IANAport_sysrqd 	      		4094			// tcp,sysrq daemon   
#define IANAport_xtgui 	      			4095			// tcp,xtgui information service   
#define IANAport_bre 		        		4096			// tcp,BRE (Bridge Relay Element)   
#define IANAport_patrolview     		4097			// tcp,Patrol View   
#define IANAport_drmsfsd      			4098			// tcp,drmsfsd   
#define IANAport_dpcp 	      			4099			// tcp,DPCP   
#define IANAport_igo_incognito 	  	4100			// tcp,IGo Incognito Data Port   
#define IANAport_brlp_0       			4101			// tcp,Braille protocol   
#define IANAport_brlp_1 	      		4102			// tcp,Braille protocol   
#define IANAport_brlp_2 	      		4103			// tcp,Braille protocol   
#define IANAport_brlp_3 	      		4104			// tcp,Braille protocol   
#define IANAport_shofar 	      		4105			// tcp,Shofar   
#define IANAport_shofar 	      		4105			// udp,Shofar   
#define IANAport_synchronite    		4106			// tcp,Synchronite   
#define IANAport_j_ac 	      			4107			// tcp,JDL Accounting LAN Service   
#define IANAport_accel 	      			4108			// tcp,ACCEL   
#define IANAport_izm 		        		4109			// tcp,Instantiated Zero_control Messaging   
#define IANAport_g2tag 	      			4110			// tcp,G2 RFID Tag Telemetry Data   
#define IANAport_xgrid 	      			4111			// tcp,Xgrid   
#define IANAport_apple_vpns_rp 	  	4112			// tcp,Apple VPN Server Reporting Protocol   
#define IANAport_aipn_reg     			4113			// tcp,AIPN LS Registration   
#define IANAport_jomamqmonitor 	  	4114			// tcp,JomaMQMonitor   
#define IANAport_cds 		        		4115			// tcp,CDS Transfer Agent   
#define IANAport_smartcard_tls  		4116			// tcp,smartcard_TLS   
#define IANAport_hillrserv 	    		4117			// tcp,Hillr Connection Manager   
#define IANAport_netscript 	    		4118			// tcp,Netadmin Systems NETscript service   
#define IANAport_assuria_slm    		4119			// tcp,Assuria Log Manager   
#define IANAport_minirem 	      		4120			// tcp,MiniRem Remote Telemetry and Control   
//#define IANAport_			      	    4120			// udp,Reserved   
#define IANAport_e_builder 	    		4121			// tcp,e_Builder Application Communication   
#define IANAport_fprams 	      		4122			// tcp,Fiber Patrol Alarm Service   
#define IANAport_z_wave       			4123			// tcp,Z_Wave Protocol   
#define IANAport_tigv2 	      			4124			// tcp,Rohill TetraNode Ip Gateway v2   
#define IANAport_opsview_envoy  		4125			// tcp,Opsview Envoy   
#define IANAport_ddrepl       			4126			// tcp,Data Domain Replication Service   
#define IANAport_unikeypro    			4127			// tcp,NetUniKeyServer   
#define IANAport_nufw 	      			4128			// tcp,NuFW decision delegation protocol   
#define IANAport_nuauth       			4129			// tcp,NuFW authentication protocol   
#define IANAport_fronet       			4130			// tcp,FRONET message protocol   
#define IANAport_stars 		      		4131			// tcp,Global Maintech Stars   
#define IANAport_nuts_dem 	    		4132			// tcp,"NUTS Daemon IANA assigned this well_formed service name as a replacement for ""nuts_dem""."   
#define IANAport_nuts_bootp     		4133			// tcp,"NUTS Bootp Server IANA assigned this well_formed service name as a replacement for ""nuts_bootp""."   
#define IANAport_nifty_hmi 	    		4134			// tcp,NIFTY_Serve HMI protocol   
#define IANAport_cl_db_attach   		4135			// tcp,Classic Line Database Server Attach   
#define IANAport_cl_db_request  		4136			// tcp,Classic Line Database Server Request   
#define IANAport_cl_db_remote   		4137			// tcp,Classic Line Database Server Remote   
#define IANAport_nettest      			4138			// tcp,nettest   
#define IANAport_thrtx 		      		4139			// tcp,Imperfect Networks Server   
#define IANAport_cedros_fds     		4140			// tcp,"Cedros Fraud Detection System IANA assigned this well_formed service name as a replacement for ""cedros_fds""."   
#define IANAport_oirtgsvc     			4141			// tcp,Workflow Server   
#define IANAport_oidocsvc 	    		4142			// tcp,Document Server   
#define IANAport_oidsr 		      		4143			// tcp,Document Replication   
#define IANAport_vvr_control    		4145			// tcp,VVR Control   
#define IANAport_tgcconnect     		4146			// tcp,TGCConnect Beacon   
#define IANAport_vrxpservman 	    	4147			// tcp,Multum Service Manager   
#define IANAport_hhb_handheld       4148			// tcp,HHB Handheld Client   
#define IANAport_agslb 		      		4149			// tcp,A10 GSLB Service   
#define IANAport_PowerAlert_nsa   	4150			// tcp,PowerAlert Network Shutdown Agent   
#define IANAport_menandmice_noh   	4151			// tcp,"Men & Mice Remote Control IANA assigned this well_formed service name as a replacement for ""menandmice_noh""."   
#define IANAport_idig_mux 	    		4152			// tcp,"iDigTech Multiplex IANA assigned this well_formed service name as a replacement for ""idig_mux""."   
#define IANAport_mbl_battd 	    		4153			// tcp,MBL Remote Battery Monitoring   
#define IANAport_atlinks 	      		4154			// tcp,atlinks device discovery   
#define IANAport_bzr 			        	4155			// tcp,Bazaar version control system   
#define IANAport_stat_results     	4156			// tcp,STAT Results   
#define IANAport_stat_scanner   		4157			// tcp,STAT Scanner Control   
#define IANAport_stat_cc 	      		4158			// tcp,STAT Command Center   
#define IANAport_nss 	        			4159			// tcp,Network Security Service   
#define IANAport_jini_discovery   	4160			// tcp,Jini Discovery   
#define IANAport_omscontact     		4161			// tcp,OMS Contact   
#define IANAport_omstopology 	    	4162			// tcp,OMS Topology   
#define IANAport_silverpeakpeer   	4163			// tcp,Silver Peak Peer Protocol   
#define IANAport_silverpeakcomm   	4164			// tcp,Silver Peak Communication Protocol   
#define IANAport_altcp 	       			4165			// tcp,ArcLink over Ethernet   
#define IANAport_joost 		      		4166			// tcp,Joost Peer to Peer Protocol   
#define IANAport_ddgn 		      		4167			// tcp,DeskDirect Global Network   
#define IANAport_pslicser     			4168			// tcp,PrintSoft License Server   
#define IANAport_iadt 		      		4169			// tcp,Automation Drive Interface Transport   
#define IANAport_iadt_disc 	    		4169			// udp,Internet ADT Discovery Protocol   
#define IANAport_d_cinema_csp   		4170			// tcp,SMPTE Content Synchonization Protocol   
//#define IANAport_				          4170			// udp,Reserved   
#define IANAport_ml_svnet 	    		4171			// tcp,Maxlogic Supervisor Communication   
//#define IANAport_				          4171			// udp,Reserved   
#define IANAport_pcoip 		      		4172			// tcp,PC over IP   
//#define IANAport_				          4173			// tcp,Reserved   
#define IANAport_mma_discovery  		4173			// udp,MMA Device Discovery   
#define IANAport_smcluster    			4174			// tcp,StorMagic Cluster Services   
#define IANAport_sm_disc 	      		4174			// udp,StorMagic Discovery   
#define IANAport_bccp 		      		4175			// tcp,Brocade Cluster Communication Protocol   
//#define IANAport_				          4175			// udp,Reserved   
#define IANAport_tl_ipcproxy    		4176			// tcp,Translattice Cluster IPC Proxy   
//#define IANAport_			      	    4176			// udp,Reserved   
#define IANAport_wello 	      			4177			// tcp,Wello P2P pubsub service   
#define IANAport_storman      			4178			// tcp,StorMan   
#define IANAport_MaxumSP      			4179			// tcp,Maxum Services   
#define IANAport_httpx 	      			4180			// tcp,HTTPX   
#define IANAport_macbak       			4181			// tcp,MacBak   
#define IANAport_pcptcpservice    	4182			// tcp,Production Company Pro TCP Service   
#define IANAport_cyborgnet    			4183			// tcp,CyborgNet communications protocol   
#define IANAport_universe_suite   	4184			// tcp,"UNIVERSE SUITE MESSAGE SERVICE IANA assigned this well_formed service name as a replacement for ""universe_suite""."   
#define IANAport_wcpp 	      			4185			// tcp,Woven Control Plane Protocol   
#define IANAport_boxbackupstore   	4186			// tcp,Box Backup Store Service   
//#define IANAport_		      		    4186			// udp,Reserved   
#define IANAport_csc_proxy 	    		4187			// tcp,"Cascade Proxy IANA assigned this well_formed service name as a replacement for ""csc_proxy""."   
//#define IANAport_			      	    4187			// udp,Reserved   
#define IANAport_vatata       			4188			// tcp,Vatata Peer to Peer Protocol   
#define IANAport_pcep 	      			4189			// tcp,Path Computation Element Communication Protocol   
//#define IANAport_			      	    4189			// udp,Reserved,[RFC5440]  ,
#define IANAport_sieve 	      			4190			// tcp,ManageSieve Protocol   
//#define IANAport_				          4190			// udp,Reserved,[RFC5804]  ,
//#define IANAport_			      	    4191			// tcp,Reserved   
#define IANAport_dsmipv6 	      		4191			// udp,Dual Stack MIPv6 NAT Traversal,[RFC5555]  ,
#define IANAport_azeti 		      		4192			// tcp,Azeti Agent Service   
#define IANAport_azeti_bd     			4192			// udp,azeti blinddate   
#define IANAport_pvxplusio 	    		4193			// tcp,PxPlus remote file srvr   
//#define IANAport_			      	    4193			// udp,Reserved   
#define IANAport_spdm 	      			4194			// tcp,Security Protocol and Data Model   
//#define IANAport_			      	    4194			// udp,Reserved   
#define IANAport_aws_wsp      			4195			// tcp,AWS protocol for cloud remoting solution   
#define IANAport_hctl 		      		4197			// tcp,Harman HControl Protocol   
#define IANAport_eims_admin     		4199			// tcp,EIMS ADMIN   
//#define IANAport_vrml_multi_use 	4200_4299		// ,VRML Multi User Systems   
#define IANAport_corelccam    			4300			// tcp,Corel CCam   
#define IANAport_d_data 	      		4301			// tcp,Diagnostic Data   
#define IANAport_d_data_control   	4302			// tcp,Diagnostic Data Control   
#define IANAport_srcp 	      			4303			// tcp,Simple Railroad Command Protocol   
#define IANAport_owserver     			4304			// tcp,One_Wire Filesystem Server   
#define IANAport_batman 	      		4305			// tcp,better approach to mobile ad_hoc networking   
#define IANAport_pinghgl 	      		4306			// tcp,Hellgate London   
#define IANAport_trueconf     			4307			// tcp,TrueConf Videoconference Service   
#define IANAport_compx_lockview   	4308			// tcp,CompX_LockView   
#define IANAport_dserver      			4309			// tcp,Exsequi Appliance Discovery   
#define IANAport_mirrtex 	      		4310			// tcp,Mir_RT exchange service   
#define IANAport_p6ssmc       			4311			// tcp,P6R Secure Server Management Console   
//#define IANAport_			      	    4311			// udp,Reserved   
#define IANAport_pscl_mgt     			4312			// tcp,Parascale Membership Manager   
//#define IANAport_				          4312			// udp,Reserved   
#define IANAport_perrla       			4313			// tcp,PERRLA User Services   
//#define IANAport_			      	    4313			// udp,Reserved   
#define IANAport_choiceview_agt   	4314			// tcp,ChoiceView Agent   
//#define IANAport_			      	    4314			// udp,Reserved   
#define IANAport_choiceview_clt   	4316			// tcp,ChoiceView Client   
//#define IANAport_			      	    4316			// udp,Reserved   
#define IANAport_opentelemetry 	  	4317			// tcp,OpenTelemetry Protocol   
//#define IANAport_		      		    4317			// udp,Reserved   
#define IANAport_fox_skytale    		4319			// tcp,Fox SkyTale encrypted communication   
#define IANAport_fdt_rcatp 	    		4320			// tcp,FDT Remote Categorization Protocol   
#define IANAport_rwhois 	      		4321			// tcp,Remote Who Is,[RFC2167]  ,
#define IANAport_trim_event     		4322			// tcp,TRIM Event Service   
#define IANAport_trim_ice 	    		4323			// tcp,TRIM ICE Service   
//#define IANAport_				          4324			// ,Reserved   
#define IANAport_geognosisadmin   	4325			// tcp,Cadcorp GeognoSIS Administrator   
#define IANAport_geognosisman   		4325			// udp,Cadcorp GeognoSIS Administrator   
#define IANAport_geognosis 	    		4326			// tcp,Cadcorp GeognoSIS   
#define IANAport_jaxer_web    			4327			// tcp,Jaxer Web Protocol   
#define IANAport_jaxer_manager  		4328			// tcp,Jaxer Manager Command Protocol   
#define IANAport_publiqare_sync   	4329			// tcp,PubliQare Distributed Environment Synchronisation Engine   
//#define IANAport_			      	    4329			// udp,Reserved   
#define IANAport_dey_sapi 	    		4330			// tcp,DEY Storage Administration REST API   
//#define IANAport_				          4330			// udp,Reserved   
#define IANAport_ktickets_rest  		4331			// tcp,ktickets REST API for event management and ticketing systems (embedded POS devices)   
//#define IANAport_				          4331			// udp,Reserved   
#define IANAport_getty_focus    		4332			// tcp,Getty Images FOCUS service   
//#define IANAport_				          4332			// udp,Reserved   
#define IANAport_ahsp 		      		4333			// tcp,ArrowHead Service Protocol (AHSP)   
#define IANAport_netconf_ch_ssh   	4334			// tcp,NETCONF Call Home (SSH),[RFC8071]  ,
//#define IANAport_			      	    4334			// udp,Reserved   
#define IANAport_netconf_ch_tls   	4335			// tcp,NETCONF Call Home (TLS),[RFC8071]  ,
//#define IANAport_				          4335			// udp,Reserved   
#define IANAport_restconf_ch_tls  	4336			// tcp,RESTCONF Call Home (TLS),[RFC8071]  ,
//#define IANAport_			      	    4336			// udp,Reserved   
#define IANAport_gaia 	      			4340			// tcp,Gaia Connector Protocol   
//#define IANAport_				          4341			// tcp,Reserved   
#define IANAport_lisp_data 	    		4341			// udp,LISP Data Packets,[RFC9300]  ,
//#define IANAport_				          4342			// tcp,Reserved   
#define IANAport_lisp_control   		4342			// udp,LISP Control Packets,[RFC9301]  ,
#define IANAport_unicall 	      		4343			// tcp,UNICALL   
#define IANAport_vinainstall 	    	4344			// tcp,VinaInstall   
#define IANAport_m4_network_as  		4345			// tcp,Macro 4 Network AS   
#define IANAport_elanlm 	      		4346			// tcp,ELAN LM   
#define IANAport_lansurveyor 	    	4347			// tcp,LAN Surveyor   
#define IANAport_itose 		      		4348			// tcp,ITOSE   
#define IANAport_fsportmap 	    		4349			// tcp,File System Port Map   
#define IANAport_net_device     		4350			// tcp,Net Device   
#define IANAport_plcy_net_svcs   		4351			// tcp,PLCY Net Services   
#define IANAport_pjlink 	      		4352			// tcp,Projector Link   
#define IANAport_f5_iquery 	    		4353			// tcp,F5 iQuery   
#define IANAport_qsnet_trans 	    	4354			// tcp,QSNet Transmitter   
#define IANAport_qsnet_workst   		4355			// tcp,QSNet Workstation   
#define IANAport_qsnet_assist   		4356			// tcp,QSNet Assistant   
#define IANAport_qsnet_cond     		4357			// tcp,QSNet Conductor   
#define IANAport_qsnet_nucl     		4358			// tcp,QSNet Nucleus   
#define IANAport_omabcastltkm   		4359			// tcp,OMA BCAST Long_Term Key Messages   
#define IANAport_matrix_vnet    		4360			// tcp,"Matrix VNet Communication Protocol IANA assigned this well_formed service name as a replacement for ""matrix_vnet""."   
//#define IANAport_				          4360			// udp,Reserved   
//#define IANAport_				          4361			// tcp,Reserved   
#define IANAport_nacnl 		      		4361			// udp,NavCom Discovery and Control Port   
//#define IANAport_			      	    4362			// tcp,Reserved   
#define IANAport_afore_vdp_disc   	4362			// udp,AFORE vNode Discovery protocol   
#define IANAport_shadowstream   		4366			// udp,ShadowStream System   
//#define IANAport_		      		    4366			// tcp,Reserved   
#define IANAport_wxbrief      			4368			// tcp,WeatherBrief Direct   
#define IANAport_epmd 	      			4369			// tcp,Erlang Port Mapper Daemon   
#define IANAport_elpro_tunnel   		4370			// tcp,"ELPRO V2 Protocol Tunnel IANA assigned this well_formed service name as a replacement for ""elpro_tunnel""."   
#define IANAport_l2c_control    		4371			// tcp,LAN2CAN Control   
#define IANAport_l2c_disc 	    		4371			// udp,LAN2CAN Discovery   
#define IANAport_l2c_data     			4372			// tcp,LAN2CAN Data   
#define IANAport_remctl 	      		4373			// tcp,Remote Authenticated Command Service   
#define IANAport_psi_ptt 	      		4374			// tcp,PSI Push_to_Talk Protocol   
//#define IANAport_				          4374			// udp,Reserved   
#define IANAport_tolteces 		    	4375			// tcp,Toltec EasyShare   
#define IANAport_bip 		        		4376			// tcp,BioAPI Interworking   
#define IANAport_cp_spxsvr 	    		4377			// tcp,Cambridge Pixel SPx Server   
#define IANAport_cp_spxdpy 	    		4378			// tcp,Cambridge Pixel SPx Display   
#define IANAport_ctdb 			      	4379			// tcp,CTDB   
#define IANAport_xandros_cms 	    	4389			// tcp,Xandros Community Management Service   
#define IANAport_wiegand 		      	4390			// tcp,Physical Access Control   
#define IANAport_apwi_imserver  		4391			// tcp,American Printware IMServer Protocol   
//#define IANAport_				          4391			// udp,Reserved   
#define IANAport_apwi_rxserver 	  	4392			// tcp,American Printware RXServer Protocol   
//#define IANAport_			      	    4392			// udp,Reserved   
#define IANAport_apwi_rxspooler   	4393			// tcp,American Printware RXSpooler Protocol   
//#define IANAport_		      		    4393			// udp,Reserved   
//#define IANAport_			      	    4394			// tcp,Reserved   
#define IANAport_apwi_disc 	    		4394			// udp,American Printware Discovery   
#define IANAport_omnivisionesx 	  	4395			// tcp,OmniVision communication for Virtual environments   
#define IANAport_fly 	        			4396			// tcp,Fly Object Space   
//#define IANAport_				          4396			// udp,Reserved   
#define IANAport_ds_srv       			4400			// tcp,ASIGRA Services   
#define IANAport_ds_srvr      			4401			// tcp,ASIGRA Televaulting DS_System Service   
#define IANAport_ds_clnt      			4402			// tcp,ASIGRA Televaulting DS_Client Service   
#define IANAport_ds_user 	      		4403			// tcp,ASIGRA Televaulting DS_Client Monitoring/Management   
#define IANAport_ds_admin     			4404			// tcp,ASIGRA Televaulting DS_System Monitoring/Management   
#define IANAport_ds_mail 	      		4405			// tcp,ASIGRA Televaulting Message Level Restore service   
#define IANAport_ds_slp 	      		4406			// tcp,ASIGRA Televaulting DS_Sleeper Service   
#define IANAport_nacagent     			4407			// tcp,Network Access Control Agent   
//#define IANAport_				          4407			// udp,Reserved   
#define IANAport_slscc 		      		4408			// tcp,SLS Technology Control Centre   
//#define IANAport_			      	    4408			// udp,Reserved   
#define IANAport_netcabinet_com   	4409			// tcp,Net_Cabinet comunication   
//#define IANAport_			      	    4409			// udp,Reserved   
#define IANAport_itwo_server    		4410			// tcp,RIB iTWO Application Server   
//#define IANAport_			      	    4410			// udp,Reserved   
#define IANAport_found 	      			4411			// tcp,Found Messaging Protocol   
//#define IANAport_			      	    4411			// udp,Reserved   
//#define IANAport_			      	    4412			// tcp,Reserved   
#define IANAport_smallchat 	    		4412			// udp,SmallChat   
#define IANAport_avi_nms 	      		4413			// tcp,AVI Systems NMS   
#define IANAport_avi_nms_disc   		4413			// udp,AVI Systems NMS   
#define IANAport_updog 	      			4414			// tcp,Updog Monitoring and Status Framework   
//#define IANAport_			      	    4414			// udp,Reserved   
#define IANAport_brcd_vr_req 	    	4415			// tcp,Brocade Virtual Router Request   
//#define IANAport_			      	    4415			// udp,Reserved   
#define IANAport_pjj_player     		4416			// tcp,PJJ Media Player   
#define IANAport_pjj_player_disc  	4416			// udp,PJJ Media Player discovery   
#define IANAport_workflowdir    		4417			// tcp,Workflow Director Communication   
//#define IANAport_		      		    4417			// udp,Reserved   
//#define IANAport_			      	    4418			// tcp,Reserved   
#define IANAport_axysbridge     		4418			// udp,AXYS communication protocol   
#define IANAport_cbp 	        			4419			// tcp,Colnod Binary Protocol   
//#define IANAport_	      			    4419			// udp,Reserved   
#define IANAport_nvme       				4420			// tcp,NVM Express over Fabrics storage access   
#define IANAport_scaleft      			4421			// tcp,Multi_Platform Remote Management for Cloud Infrastructure   
//#define IANAport_			      	    4421			// udp,Reserved   
#define IANAport_tsepisp      			4422			// tcp,TSEP Installation Service Protocol   
//#define IANAport_			      	    4422			// udp,Reserved   
#define IANAport_thingkit     			4423			// tcp,thingkit secure mesh   
//#define IANAport_			      	    4423			// udp,Reserved   
#define IANAport_netrockey6     		4425			// tcp,NetROCKEY6 SMART Plus Service   
#define IANAport_beacon_port_2  		4426			// tcp,SMARTS Beacon Port   
#define IANAport_drizzle 	      		4427			// tcp,Drizzle database server   
//#define IANAport_				          4427			// udp,Reserved   
#define IANAport_omviserver     		4428			// tcp,OMV_Investigation Server_Client   
//#define IANAport_				          4428			// udp,Reserved   
#define IANAport_omviagent    			4429			// tcp,OMV Investigation Agent_Server   
//#define IANAport_				          4429			// udp,Reserved   
#define IANAport_rsqlserver     		4430			// tcp,REAL SQL Server   
#define IANAport_wspipe 		      	4431			// tcp,adWISE Pipe   
//#define IANAport_			      	    4431			// udp,Reserved   
#define IANAport_l_acoustics    		4432			// tcp,L_ACOUSTICS management   
#define IANAport_vop 	        			4433			// tcp,Versile Object Protocol   
//#define IANAport_	      			    4433			// udp,Reserved   
//#define IANAport_	      			    4441			// tcp,Reserved   
#define IANAport_netblox      			4441			// udp,Netblox Protocol   
#define IANAport_saris 	      			4442			// tcp,Saris   
#define IANAport_pharos       			4443			// tcp,Pharos   
#define IANAport_krb524       			4444			// tcp,KRB524   
#define IANAport_nv_video     			4444			// tcp,NV Video default   
#define IANAport_upnotifyp    			4445			// tcp,UPNOTIFYP   
#define IANAport_n1_fwp 	      		4446			// tcp,N1_FWP   
#define IANAport_n1_rmgmt     			4447			// tcp,N1_RMGMT   
#define IANAport_asc_slmd     			4448			// tcp,ASC Licence Manager   
#define IANAport_privatewire    		4449			// tcp,PrivateWire   
#define IANAport_camp 		      		4450			// tcp,Common ASCII Messaging Protocol   
#define IANAport_ctisystemmsg   		4451			// tcp,CTI System Msg   
#define IANAport_ctiprogramload   	4452			// tcp,CTI Program Load   
#define IANAport_nssalertmgr 	    	4453			// tcp,NSS Alert Manager   
#define IANAport_nssagentmgr 	    	4454			// tcp,NSS Agent Manager   
#define IANAport_prchat_user    		4455			// tcp,PR Chat User   
#define IANAport_prchat_server  		4456			// tcp,PR Chat Server   
#define IANAport_prRegister     		4457			// tcp,PR Register   
#define IANAport_mcp 		        		4458			// tcp,Matrix Configuration Protocol   
#define IANAport_ntske 	      			4460			// tcp,Network Time Security Key Establishment,[RFC8915]  ,
//#define IANAport_			      	    4460			// udp,Reserved   
#define IANAport_hpssmgmt     			4484			// tcp,hpssmgmt service   
#define IANAport_assyst_dr    			4485			// tcp,Assyst Data Repository Service   
//#define IANAport_			      	    4485			// udp,Reserved   
#define IANAport_icms 	      			4486			// tcp,Integrated Client Message Service   
#define IANAport_prex_tcp     			4487			// tcp,Protocol for Remote Execution over TCP   
//#define IANAport_				          4487			// udp,Reserved   
#define IANAport_awacs_ice    			4488			// tcp,Apple Wide Area Connectivity Service ICE Bootstrap   
#define IANAport_ipsec_nat_t    		4500			// tcp,IPsec NAT_Traversal,[RFC9329]  ,
#define IANAport_a25_fap_fgw    		4502			// sctp,A25 (FAP_FGW)   
//#define IANAport_			      	    4534			// tcp,Reserved   
#define IANAport_armagetronad   		4534			// udp,Armagetron Advanced Game Server   
#define IANAport_ehs 		        		4535			// tcp,Event Heap Server   
#define IANAport_ehs_ssl 	      		4536			// tcp,Event Heap Server SSL   
#define IANAport_wssauthsvc     		4537			// tcp,WSS Security Service   
#define IANAport_swx_gate 	    		4538			// tcp,Software Data Exchange Gateway   
#define IANAport_worldscores    		4545			// tcp,WorldScores   
#define IANAport_sf_lm 		      		4546			// tcp,SF License Manager (Sentinel)   
#define IANAport_lanner_lm    			4547			// tcp,Lanner License Manager   
#define IANAport_synchromesh    		4548			// tcp,Synchromesh   
#define IANAport_aegate       			4549			// tcp,Aegate PMR Service   
#define IANAport_gds_adppiw_db  		4550			// tcp,Perman I Interbase Server   
#define IANAport_ieee_mih     			4551			// tcp,MIH Services,[RFC5677]  ,
#define IANAport_menandmice_mon   	4552			// tcp,Men and Mice Monitoring   
#define IANAport_icshostsvc      		4553			// tcp,ICS host services   
//#define IANAport_		      		    4553			// udp,Reserved   
#define IANAport_msfrs 	      			4554			// tcp,MS FRS Replication   
#define IANAport_rsip 	      			4555			// tcp,RSIP Port,[RFC3103]  ,
#define IANAport_dtn_bundle     		4556			// tcp,DTN Bundle TCP CL Protocol,[RFC9174],[RFC7122]
//#define IANAport_		      		    4557			// tcp,Reserved   
#define IANAport_mtcevrunqss    		4557			// udp,Marathon everRun Quorum Service Server   
//#define IANAport_				          4558			// tcp,Reserved   
#define IANAport_mtcevrunqman   		4558			// udp,Marathon everRun Quorum Service Manager   
#define IANAport_hylafax 		      	4559			// tcp,HylaFAX   
#define IANAport_amahi_anywhere   	4563			// tcp,Amahi Anywhere   
//#define IANAport_	      			    4563			// udp,Reserved   
#define IANAport_kwtc       				4566			// tcp,Kids Watch Time Control Service   
#define IANAport_tram       				4567			// tcp,TRAM   
#define IANAport_bmc_reporting  		4568			// tcp,BMC Reporting   
#define IANAport_iax 	        			4569			// tcp,Inter_Asterisk eXchange,[RFC5456]  ,
#define IANAport_deploymentmap 	  	4570			// tcp,Service to distribute and update within a site deployment information for Oracle Communications Suite   
//#define IANAport_		      		    4570			// udp,Reserved   
#define IANAport_cardifftec_back  	4573			// tcp,A port for communication between a server and client for a custom backup system   
//#define IANAport_				          4573			// udp,Reserved   
#define IANAport_rid 		        		4590			// tcp,RID over HTTP/TLS,[RFC6546]  ,
//#define IANAport_				          4590			// udp,Reserved   
#define IANAport_l3t_at_an 	    		4591			// tcp,HRPD L3T (AT_AN)   
//#define IANAport_				          4592			// tcp,Reserved   
#define IANAport_hrpd_ith_at_an   	4592			// udp,HRPD_ITH (AT_AN)   
#define IANAport_ipt_anri_anri   		4593			// tcp,IPT (ANRI_ANRI)   
#define IANAport_ias_session 	     	4594			// tcp,IAS_Session (ANRI_ANRI)   
#define IANAport_ias_paging     		4595			// tcp,IAS_Paging (ANRI_ANRI)   
#define IANAport_ias_neighbor   		4596			// tcp,IAS_Neighbor (ANRI_ANRI)   
#define IANAport_a21_an_1xbs    		4597			// tcp,A21 (AN_1xBS)   
#define IANAport_a16_an_an 	    		4598			// tcp,A16 (AN_AN)   
#define IANAport_a17_an_an 	    		4599			// tcp,A17 (AN_AN)   
#define IANAport_piranha1 	    		4600			// tcp,Piranha1   
#define IANAport_piranha2     			4601			// tcp,Piranha2   
#define IANAport_mtsserver    			4602			// tcp,EAX MTS Server   
//#define IANAport_				          4602			// udp,Reserved   
#define IANAport_menandmice_upg    	4603			// tcp,Men & Mice Upgrade Agent   
//#define IANAport_			      	    4603			// udp,Reserved   
#define IANAport_irp 	        			4604			// tcp,Identity Registration Protocol   
//#define IANAport_			      	    4604			// udp,Reserved   
#define IANAport_sixchat      			4605			// tcp,Direct End to End Secure Chat Protocol   
//#define IANAport_			      	    4605			// udp,Reserved   
#define IANAport_sixid 	      			4606			// tcp,Secure ID to IP registration and lookup   
//#define IANAport_		      		    4606			// udp,Reserved   
//#define IANAport_		      		    4621			// tcp,Reserved   
#define IANAport_ventoso      			4621			// udp,Bidirectional single port remote radio VOIP and Control stream   
#define IANAport_dots_signal    		4646			// tcp,"Distributed Denial_of_Service Open Threat Signaling (DOTS) Signal Channel Protocol. The service name is used to construct the SRV service names ""_dots_signal._udp"" and ""_dots_signal._tcp"" for discovering DOTS servers used to establish DOTS signal channel.",[RFC8973][RFC9132]  ,
#define IANAport_playsta2_app   		4658			// tcp,PlayStation2 App Port   
#define IANAport_playsta2_lob   		4659			// tcp,PlayStation2 Lobby Port   
#define IANAport_smaclmgr 	    		4660			// tcp,smaclmgr   
#define IANAport_kar2ouche    			4661			// tcp,Kar2ouche Peer location service   
#define IANAport_oms 	        			4662			// tcp,OrbitNet Message Service   
#define IANAport_noteit       			4663			// tcp,Note It! Message Service   
#define IANAport_ems 		        		4664			// tcp,Rimage Messaging Server   
#define IANAport_contclientms   		4665			// tcp,Container Client Message Service   
#define IANAport_eportcomm 	    		4666			// tcp,E_Port Message Service   
#define IANAport_mmacomm      			4667			// tcp,MMA Comm Services   
#define IANAport_mmaeds 	      		4668			// tcp,MMA EDS Service   
#define IANAport_eportcommdata  		4669			// tcp,E_Port Data Service   
#define IANAport_light      				4670			// tcp,Light packets transfer protocol   
#define IANAport_acter      				4671			// tcp,Bull RSF action server   
#define IANAport_rfa 	        			4672			// tcp,remote file access server   
#define IANAport_cxws       				4673			// tcp,CXWS Operations   
#define IANAport_appiq_mgmt     		4674			// tcp,AppIQ Agent Management   
#define IANAport_dhct_status    		4675			// tcp,BIAP Device Status   
#define IANAport_dhct_alerts    		4676			// tcp,BIAP Generic Alert   
#define IANAport_bcs 	        			4677			// tcp,Business Continuity Servi   
#define IANAport_traversal 	    		4678			// tcp,boundary traversal   
#define IANAport_mgesupervision   	4679			// tcp,MGE UPS Supervision   
#define IANAport_mgemanagement   		4680			// tcp,MGE UPS Management   
#define IANAport_parliant     			4681			// tcp,Parliant Telephony System   
#define IANAport_finisar 	      		4682			// tcp,finisar   
#define IANAport_spike 	      			4683			// tcp,Spike Clipboard Service   
#define IANAport_rfid_rp1     			4684			// tcp,RFID Reader Protocol 1.0   
#define IANAport_autopac      			4685			// tcp,Autopac Protocol   
#define IANAport_msp_os       			4686			// tcp,Manina Service Protocol   
#define IANAport_nst 	        			4687			// tcp,Network Scanner Tool FTP   
#define IANAport_mobile_p2p     		4688			// tcp,Mobile P2P Service   
#define IANAport_altovacentral  		4689			// tcp,Altova DatabaseCentral   
#define IANAport_prelude 	      		4690			// tcp,Prelude IDS message proto   
#define IANAport_mtn 		        		4691			// tcp,monotone Netsync Protocol   
#define IANAport_conspiracy     		4692			// tcp,Conspiracy messaging   
#define IANAport_netxms_agent   		4700			// tcp,NetXMS Agent   
#define IANAport_netxms_mgmt    		4701			// tcp,NetXMS Management   
#define IANAport_netxms_sync    		4702			// tcp,NetXMS Server Synchronization   
#define IANAport_npqes_test     		4703			// tcp,Network Performance Quality Evaluation System Test Service   
//#define IANAport_				          4703			// udp,Reserved   
#define IANAport_assuria_ins 	    	4704			// tcp,Assuria Insider   
//#define IANAport_				          4704			// udp,Reserved   
#define IANAport_trinity_dist   		4711			// tcp,Trinity Trust Network Node Communication   
#define IANAport_truckstar    			4725			// tcp,TruckStar Service   
//#define IANAport_		      		    4726			// tcp,Reserved   
#define IANAport_a26_fap_fgw    		4726			// udp,A26 (FAP_FGW)   
#define IANAport_fcis 		      		4727			// tcp,F_Link Client Information Service   
#define IANAport_fcis_disc    			4727			// udp,F_Link Client Information Service Discovery   
#define IANAport_capmux       			4728			// tcp,CA Port Multiplexer   
//#define IANAport_			      	    4729			// tcp,Reserved   
#define IANAport_gsmtap       			4729			// udp,GSM Interface Tap   
#define IANAport_gearman 	      		4730			// tcp,Gearman Job Queue System   
#define IANAport_remcap       			4731			// tcp,Remote Capture Protocol   
//#define IANAport_		      		    4731			// udp,Reserved   
//#define IANAport_	      			    4732			// tcp,Reserved   
#define IANAport_ohmtrigger      		4732			// udp,OHM server trigger   
#define IANAport_resorcs      			4733			// tcp,RES Orchestration Catalog Services   
//#define IANAport_			      	    4733			// udp,Reserved   
#define IANAport_ipdr_sp 	      		4737			// tcp,IPDR/SP   
#define IANAport_solera_lpn     		4738			// tcp,SoleraTec Locator   
#define IANAport_ipfix 	      			4739			// tcp,IP Flow Info Export   
#define IANAport_ipfixs       			4740			// tcp,ipfix protocol over TLS   
#define IANAport_lumimgrd     			4741			// tcp,Luminizer Manager   
#define IANAport_sicct 	      			4742			// tcp,SICCT   
#define IANAport_sicct_sdp    			4742			// udp,SICCT Service Discovery Protocol   
#define IANAport_openhpid     			4743			// tcp,openhpi HPI service   
#define IANAport_ifsp       				4744			// tcp,Internet File Synchronization Protocol   
#define IANAport_fmp 	        			4745			// tcp,Funambol Mobile Push   
//#define IANAport_		      		    4746			// tcp,Reserved   
#define IANAport_intelliadm_disc   	4746			// udp,IntelliAdmin Discovery   
#define IANAport_buschtrommel    		4747			// udp,peer_to_peer file exchange protocol   
//#define IANAport_		      		    4747			// tcp,Reserved   
#define IANAport_profilemac     		4749			// tcp,Profile for Mac   
#define IANAport_ssad 	      			4750			// tcp,Simple Service Auto Discovery   
#define IANAport_spocp 	      			4751			// tcp,Simple Policy Control Protocol   
#define IANAport_snap 	      			4752			// tcp,Simple Network Audio Protocol   
#define IANAport_simon 	      			4753			// tcp,Simple Invocation of Methods Over Network (SIMON)   
#define IANAport_simon_disc     		4753			// udp,Simple Invocation of Methods Over Network (SIMON) Discovery   
//#define IANAport_				          4754			// tcp,Reserved   
#define IANAport_gre_in_udp     		4754			// udp,GRE_in_UDP Encapsulation,[RFC8086]  ,
//#define IANAport_				          4755			// tcp,Reserved   
#define IANAport_gre_udp_dtls   		4755			// udp,GRE_in_UDP Encapsulation with DTLS,[RFC8086]  ,
#define IANAport_RDCenter     			4756			// tcp,Reticle Decision Center   
//#define IANAport_				          4756			// udp,Reserved   
#define IANAport_converge     			4774			// tcp,Converge RPC   
//#define IANAport_				          4774			// udp,Reserved   
#define IANAport_bfd_multi_ctl  		4784			// tcp,BFD Multihop Control   
//#define IANAport_			      	    4785			// tcp,Reserved   
#define IANAport_cncp 	      			4785			// udp,Cisco Nexus Control Protocol   
#define IANAport_smart_install  		4786			// tcp,Smart Install Service   
//#define IANAport_			      	    4786			// udp,Reserved   
#define IANAport_sia_ctrl_plane   	4787			// tcp,Service Insertion Architecture (SIA) Control_Plane   
//#define IANAport_		      		    4787			// udp,Reserved   
#define IANAport_xmcp 	      			4788			// tcp,eXtensible Messaging Client Protocol   
//#define IANAport_			      	    4788			// udp,Reserved   
#define IANAport_vxlan 	      			4789			// udp,Virtual eXtensible Local Area Network (VXLAN),[RFC7348]  ,
//#define IANAport_			      	    4789			// tcp,Reserved   
#define IANAport_vxlan_gpe    			4790			// udp,Generic Protocol Extension for Virtual eXtensible Local Area Network (VXLAN)   
//#define IANAport_			      	    4790			// tcp,Reserved   
#define IANAport_roce 	      			4791			// udp,IP Routable RocE   
//#define IANAport_			      	    4791			// tcp,Reserved   
#define IANAport_unified_bus 	    	4792			// tcp,IP Routable Unified Bus   
#define IANAport_iims 	      			4800			// tcp,Icona Instant Messenging System   
#define IANAport_iwec 	      			4801			// tcp,Icona Web Embedded Chat   
#define IANAport_ilss 	      			4802			// tcp,Icona License System Server   
#define IANAport_notateit 	    		4803			// tcp,Notateit Messaging   
#define IANAport_notateit_disc  		4803			// udp,Notateit Messaging Discovery   
//#define IANAport_			      	    4804			// tcp,Reserved   
#define IANAport_aja_ntv4_disc 	  	4804			// udp,AJA ntv4 Video System Discovery   
#define IANAport_htcp 	      			4827			// tcp,HTCP   
#define IANAport_varadero_0     		4837			// tcp,Varadero_0   
#define IANAport_varadero_1     		4838			// tcp,Varadero_1   
#define IANAport_varadero_2     		4839			// tcp,Varadero_2   
#define IANAport_opcua_tcp 	    		4840			// tcp,OPC UA Connection Protocol   
#define IANAport_opcua_udp    			4840			// udp,OPC UA Multicast Datagram Protocol   
#define IANAport_quosa 		      		4841			// tcp,QUOSA Virtual Library Service   
#define IANAport_gw_asv 	      		4842			// tcp,nCode ICE_flow Library AppServer   
#define IANAport_opcua_tls    			4843			// tcp,OPC UA TCP Protocol over TLS/SSL   
#define IANAport_gw_log 	      		4844			// tcp,nCode ICE_flow Library LogServer   
#define IANAport_wcr_remlib     		4845			// tcp,WordCruncher Remote Library Service   
#define IANAport_contamac_icm   		4846			// tcp,"Contamac ICM Service IANA assigned this well_formed service name as a replacement for ""contamac_icm""."   
#define IANAport_wfc 	        			4847			// tcp,Web Fresh Communication   
#define IANAport_appserv_http   		4848			// tcp,App Server _ Admin HTTP   
#define IANAport_appserv_https  		4849			// tcp,App Server _ Admin HTTPS   
#define IANAport_sun_as_nodeagt   	4850			// tcp,Sun App Server _ NA   
#define IANAport_derby_repli    		4851			// tcp,Apache Derby Replication   
#define IANAport_unify_debug    		4867			// tcp,Unify Debugger   
#define IANAport_phrelay 	      		4868			// tcp,Photon Relay   
#define IANAport_phrelaydbg     		4869			// tcp,Photon Relay Debug   
#define IANAport_cc_tracking    		4870			// tcp,Citcom Tracking Service   
#define IANAport_wired 		      		4871			// tcp,Wired   
#define IANAport_tritium_can    		4876			// tcp,Tritium CAN Bus Bridge Service   
#define IANAport_lmcs 		      		4877			// tcp,Lighting Management Control System   
//#define IANAport_				          4878			// tcp,Reserved   
#define IANAport_inst_discovery   	4878			// udp,Agilent Instrument Discovery   
#define IANAport_wsdl_event     		4879			// tcp,WSDL Event Receiver   
//#define IANAport_				          4879			// udp,Reserved   
#define IANAport_hislip 	      		4880			// tcp,IVI High_Speed LAN Instrument Protocol   
//#define IANAport_		      		    4880			// udp,Reserved   
//#define IANAport_		      		    4881			// tcp,Reserved   
#define IANAport_socp_t        			4881			// udp,SOCP Time Synchronization Protocol   
//#define IANAport_			      	    4882			// tcp,Reserved   
#define IANAport_socp_c       			4882			// udp,SOCP Control Protocol   
#define IANAport_wmlserver 	    		4883			// tcp,Meier_Phelps License Server   
//#define IANAport_			      	    4883			// udp,Reserved   
#define IANAport_hivestor 		    	4884			// tcp,HiveStor Distributed File System   
#define IANAport_abbs 	      			4885			// tcp,ABBS   
#define IANAport_xcap_portal    		4888			// tcp,xcap code analysis portal public user access   
//#define IANAport_			      	    4888			// udp,Reserved   
#define IANAport_xcap_control   		4889			// tcp,xcap code analysis portal cluster control and administration   
//#define IANAport_			      	    4889			// udp,Reserved   
#define IANAport_lyskom 	      		4894			// tcp,LysKOM Protocol A   
#define IANAport_radmin_port    		4899			// tcp,RAdmin Port   
#define IANAport_hfcs 	      			4900			// tcp,HFSQL Client/Server Database Engine   
#define IANAport_flr_agent    			4901			// tcp,"FileLocator Remote Search Agent IANA assigned this well_formed service name as a replacement for ""flr_agent""."   
//#define IANAport_			      	    4901			// udp,Reserved   
#define IANAport_magiccontrol   		4902			// tcp,magicCONROL RF and Data Interface   
//#define IANAport_			      	    4902			// udp,Reserved   
#define IANAport_lutap 	      			4912			// tcp,Technicolor LUT Access Protocol   
//#define IANAport_			      	    4912			// udp,Reserved   
#define IANAport_lutcp      				4913			// tcp,LUTher Control Protocol   
#define IANAport_bones 	      			4914			// tcp,Bones Remote Control   
#define IANAport_frcs 	      			4915			// tcp,Fibics Remote Control Service   
//#define IANAport_		      		    4915			// udp,Reserved   
#define IANAport_an_signaling   		4936			// udp,Signal protocol port for autonomic networking   
//#define IANAport_		      		    4936			// tcp,Reserved   
//#define IANAport_	      			    4937			// tcp,Reserved   
#define IANAport_atsc_mh_ssc    		4937			// udp,ATSC_M/H Service Signaling Channel   
#define IANAport_eq_office_4940   	4940			// tcp,Equitrac Office   
#define IANAport_eq_office_4941   	4941			// udp,Equitrac Office   
#define IANAport_eq_office_4942   	4942			// udp,Equitrac Office   
#define IANAport_munin 		      		4949			// tcp,Munin Graphing Framework   
#define IANAport_sybasesrvmon   		4950			// tcp,Sybase Server Monitor   
#define IANAport_pwgwims 	      		4951			// tcp,PWG WIMS   
#define IANAport_sagxtsds     			4952			// tcp,SAG Directory Server   
#define IANAport_dbsyncarbiter 	  	4953			// tcp,Synchronization Arbiter   
//#define IANAport_			      	    4953			// udp,Reserved   
#define IANAport_ccss_qmm     			4969			// tcp,CCSS QMessageMonitor   
#define IANAport_ccss_qsm     			4970			// tcp,CCSS QSystemMonitor   
#define IANAport_burp 		      		4971			// tcp,BackUp and Restore Program   
//#define IANAport_				          4971			// udp,Reserved   
#define IANAport_ctxs_vpp     			4980			// udp,Citrix Virtual Path   
//#define IANAport_			      	    4980			// tcp,Reserved   
#define IANAport_webyast 	      		4984			// tcp,WebYast   
//#define IANAport_			            4984			// udp,Reserved   
#define IANAport_gerhcs 	      		4985			// tcp,GER HC Standard   
//#define IANAport_			      	    4985			// udp,Reserved   
#define IANAport_mrip 	      			4986			// tcp,Model Railway Interface Program   
#define IANAport_smar_se_port1  		4987			// tcp,SMAR Ethernet Port 1   
#define IANAport_smar_se_port2  		4988			// tcp,SMAR Ethernet Port 2   
#define IANAport_parallel     			4989			// tcp,Parallel for GAUSS (tm)   
#define IANAport_busycal 	      		4990			// tcp,BusySync Calendar Synch. Protocol   
#define IANAport_vrt 		        		4991			// tcp,VITA Radio Transport   
#define IANAport_hfcs_manager   		4999			// tcp,HFSQL Client/Server Database Engine Manager   
#define IANAport_commplex_main  		5000			// 
#define IANAport_commplex_link  		5001			// 
#define IANAport_rfe 		        		5002			// tcp,radio free ethernet   
#define IANAport_fmpro_internal   	5003			// tcp,"FileMaker, Inc. _ Proprietary transport"   
#define IANAport_avt_profile_1  		5004			// tcp,RTP media data,[RFC3551][RFC4571]  ,
#define IANAport_avt_profile_2  		5005			// tcp,RTP control protocol,[RFC3551][RFC4571]  ,
#define IANAport_wsm_server     		5006			// tcp,wsm server   
#define IANAport_wsm_server_ssl   	5007			// tcp,wsm server ssl   
#define IANAport_synapsis_edge 	  	5008			// tcp,Synapsis EDGE   
#define IANAport_winfs 	      			5009			// tcp,Microsoft Windows Filesystem   
#define IANAport_telelpathstart   	5010			// tcp,TelepathStart   
#define IANAport_telelpathattack  	5011			// tcp,TelepathAttack   
#define IANAport_nsp 	        			5012			// tcp,NetOnTap Service   
#define IANAport_fmpro_v6     			5013			// tcp,"FileMaker, Inc. _ Proprietary transport"   
//#define IANAport_			      	    5014			// tcp,Reserved   
#define IANAport_onpsocket    			5014			// udp,Overlay Network Protocol   
#define IANAport_fmwp 	      			5015			// tcp,"FileMaker, Inc. _ Web publishing"   
//#define IANAport_				          5015			// udp,Reserved   
#define IANAport_zenginkyo_1    		5020			// tcp,zenginkyo_1   
#define IANAport_zenginkyo_2    		5021			// tcp,zenginkyo_2   
#define IANAport_mice       				5022			// tcp,mice server   
#define IANAport_htuilsrv     			5023			// tcp,Htuil Server for PLD2   
#define IANAport_scpi_telnet     		5024			// tcp,SCPI_TELNET   
#define IANAport_scpi_raw     			5025			// tcp,SCPI_RAW   
#define IANAport_strexec_d    			5026			// tcp,Storix I/O daemon (data)   
#define IANAport_strexec_s    			5027			// tcp,Storix I/O daemon (stat)   
#define IANAport_qvr 	        			5028			// tcp,Quiqum Virtual Relais   
//#define IANAport_			      	    5028			// udp,Reserved   
#define IANAport_infobright     		5029			// tcp,Infobright Database Server   
//#define IANAport_		      		    5030			// tcp,Reserved   
//#define IANAport_		      		    5030			// udp,Reserved   
//#define IANAport_		      		    5031			// tcp,Reserved   
#define IANAport_dmp 		        		5031			// udp,Direct Message Protocol   
#define IANAport_signacert_agent 	  5032			// tcp,SignaCert Enterprise Trust Server Agent   
//#define IANAport_			      	    5032			// udp,Reserved   
#define IANAport_jtnetd_server  		5033			// tcp,Janstor Secure Data   
//#define IANAport_			      	    5033			// udp,Reserved   
#define IANAport_jtnetd_status 	  	5034			// tcp,Janstor Status   
//#define IANAport_				          5034			// udp,Reserved   
#define IANAport_asnaacceler8db   	5042			// tcp,asnaacceler8db   
#define IANAport_swxadmin 	    		5043			// tcp,ShopWorX Administration   
#define IANAport_lxi_evntsvc    		5044			// tcp,LXI Event Service   
#define IANAport_osp 		        		5045			// tcp,Open Settlement Protocol   
//#define IANAport_			      	    5045			// udp,Reserved   
//#define IANAport_			      	    5046			// tcp,Reserved   
#define IANAport_vpm_udp 	      		5046			// udp,Vishay PM UDP Service   
//#define IANAport_			      	    5047			// tcp,Reserved   
#define IANAport_iscape       			5047			// udp,iSCAPE Data Broadcasting   
#define IANAport_texai 	      			5048			// tcp,Texai Message Service   
//#define IANAport_		      		    5048			// udp,Reserved   
#define IANAport_ivocalize 	    		5049			// tcp,iVocalize Web Conference   
#define IANAport_mmcc 		      		5050			// tcp,multimedia conference control tool   
#define IANAport_ita_agent 	    		5051			// tcp,ITA Agent   
#define IANAport_ita_manager    		5052			// tcp,ITA Manager   
#define IANAport_rlm 	        			5053			// tcp,RLM License Server   
#define IANAport_rlm_disc     			5053			// udp,RLM Discovery Server   
#define IANAport_rlm_admin 	    		5054			// tcp,RLM administrative interface   
//#define IANAport_			      	    5054			// udp,Reserved   
#define IANAport_unot 	      			5055			// tcp,UNOT   
#define IANAport_intecom_ps1    		5056			// tcp,Intecom Pointspan 1   
#define IANAport_intecom_ps2    		5057			// tcp,Intecom Pointspan 2   
//#define IANAport_			      	    5058			// tcp,Reserved   
#define IANAport_locus_disc     		5058			// udp,Locus Discovery   
#define IANAport_sds 	        			5059			// tcp,SIP Directory Services   
#define IANAport_sip 	        			5060			// tcp,SIP,[RFC3263]  ,
#define IANAport_sip 		        		5060			// sctp,SIP,[RFC4168]  ,
#define IANAport_sips 	      			5061			// tcp,SIP_TLS,[RFC3263]  ,
#define IANAport_na_localise     		5062			// tcp,Localisation access   
#define IANAport_csrpc 	      			5063			// tcp,centrify secure RPC   
//#define IANAport_		      		    5063			// udp,Reserved   
#define IANAport_ca_1       				5064			// tcp,Channel Access 1   
#define IANAport_ca_2       				5065			// tcp,Channel Access 2   
#define IANAport_stanag_5066    		5066			// tcp,STANAG_5066_SUBNET_INTF   
#define IANAport_authentx 	    		5067			// tcp,Authentx Service   
#define IANAport_bitforestsrv   		5068			// tcp,Bitforest Data Service   
//#define IANAport_			      	    5068			// udp,Reserved   
#define IANAport_i_net_2000_npr   	5069			// tcp,I/Net 2000_NPR   
#define IANAport_vtsas 	      			5070			// tcp,VersaTrans Server Agent Service   
#define IANAport_powerschool    		5071			// tcp,PowerSchool   
#define IANAport_ayiya 	      			5072			// tcp,Anything In Anything   
#define IANAport_tag_pm       			5073			// tcp,Advantage Group Port Mgr   
#define IANAport_alesquery    			5074			// tcp,ALES Query   
#define IANAport_pvaccess     			5075			// tcp,Experimental Physics and Industrial Control System   
//#define IANAport_				          5075			// udp,Reserved   
#define IANAport_pixelpusher    		5078			// udp,PixelPusher pixel data   
//#define IANAport_			      	    5078			// tcp,Reserved   
//#define IANAport_				          5079			// tcp,Reserved   
#define IANAport_cp_spxrpts     		5079			// udp,Cambridge Pixel SPx Reports   
#define IANAport_onscreen     			5080			// tcp,OnScreen Data Collection Service   
#define IANAport_sdl_ets 	      		5081			// tcp,SDL _ Ent Trans Server   
#define IANAport_qcp 		        		5082			// tcp,Qpur Communication Protocol   
#define IANAport_qfp 	        			5083			// tcp,Qpur File Protocol   
#define IANAport_llrp       				5084			// tcp,EPCglobal Low_Level Reader Protocol   
#define IANAport_encrypted_llrp   	5085			// tcp,EPCglobal Encrypted LLRP   
#define IANAport_aprigo_cs 	    		5086			// tcp,Aprigo Collection Service   
//#define IANAport_			      	    5086			// udp,Reserved   
#define IANAport_biotic       			5087			// tcp,BIOTIC _ Binary Internet of Things Interoperable Communication   
//#define IANAport_		      		    5087			// udp,Reserved   
#define IANAport_car 	         			5090			// sctp,Candidate AR   
#define IANAport_cxtp 	      			5091			// sctp,Context Transfer Protocol,[RFC4065]  ,
//#define IANAport_		      		    5092			// tcp,Reserved   
#define IANAport_magpie       			5092			// udp,Magpie Binary   
#define IANAport_sentinel_lm    		5093			// tcp,Sentinel LM   
#define IANAport_hart_ip 	      		5094			// tcp,HART_IP   
#define IANAport_sentlm_srv2srv   	5099			// tcp,SentLM Srv2Srv   
#define IANAport_socalia 	      		5100			// tcp,Socalia service mux   
#define IANAport_talarian_tcp   		5101			// tcp,Talarian_TCP   
#define IANAport_talarian_udp   		5101			// udp,Talarian_UDP   
#define IANAport_oms_nonsecure  		5102			// tcp,Oracle OMS non_secure   
#define IANAport_actifio_c2c    		5103			// tcp,Actifio C2C   
//#define IANAport_		      		    5103			// udp,Reserved   
//#define IANAport_			      	    5104			// tcp,Reserved   
#define IANAport_tinymessage    		5104			// udp,TinyMessage   
//#define IANAport_				          5105			// tcp,Reserved   
#define IANAport_hughes_ap 	    		5105			// udp,Hughes Association Protocol   
#define IANAport_actifioudsagent  	5106			// tcp,Actifio UDS Agent   
//#define IANAport_			      	    5106			// udp,Reserved   
#define IANAport_actifioreplic 	  	5107			// tcp,Disk to Disk replication between Actifio Clusters   
//#define IANAport_		      		    5107			// udp,Reserved   
#define IANAport_taep_as_svc 	    	5111			// tcp,TAEP AS service   
#define IANAport_pm_cmdsvr 	    		5112			// tcp,PeerMe Msg Cmd Service   
#define IANAport_ev_services    		5114			// tcp,Enterprise Vault Services   
//#define IANAport_				          5114			// udp,Reserved   
#define IANAport_autobuild    			5115			// tcp,Symantec Autobuild Service   
//#define IANAport_			      	    5115			// udp,Reserved   
////#define IANAport_		    		    5116			// tcp,Reserved   
#define IANAport_emb_proj_cmd   		5116			// udp,EPSON Projecter Image Transfer   
#define IANAport_gradecam     			5117			// tcp,GradeCam Image Processing   
//#define IANAport_				          5117			// udp,Reserved   
#define IANAport_barracuda_bbs 	  	5120			// tcp,Barracuda Backup Protocol   
#define IANAport_nbt_pc       			5133			// tcp,Policy Commander   
#define IANAport_ppactivation 	  	5134			// tcp,PP ActivationServer   
//#define IANAport_			      	    5134			// udp,Reserved   
#define IANAport_erp_scale 	    		5135			// tcp,ERP_Scale   
//#define IANAport_			      	    5135			// udp,Reserved   
//#define IANAport_			      	    5136			// tcp,Reserved   
#define IANAport_minotaur_sa    		5136			// udp,Minotaur SA   
#define IANAport_ctsd 		      		5137			// tcp,MyCTS server port   
#define IANAport_rmonitor_secure  	5145			// tcp,"RMONITOR SECURE IANA assigned this well_formed service name as a replacement for ""rmonitor_secure""."   
#define IANAport_social_alarm     	5146			// tcp,Social Alarm Service   
//#define IANAport_			      	    5146			// udp,Reserved   
#define IANAport_atmp 	      			5150			// tcp,Ascend Tunnel Management Protocol   
#define IANAport_esri_sde     			5151			// tcp,"ESRI SDE Instance IANA assigned this well_formed service name as a replacement for ""esri_sde""."   
#define IANAport_sde_discovery  		5152			// tcp,ESRI SDE Instance Discovery   
//#define IANAport_				          5153			// tcp,Reserved   
//#define IANAport_				          5153			// udp,Reserved   
#define IANAport_bzflag 	      		5154			// tcp,BZFlag game server   
#define IANAport_asctrl_agent   		5155			// tcp,Oracle asControl Agent   
#define IANAport_rugameonline   		5156			// tcp,Russian Online Game   
//#define IANAport_				          5156			// udp,Reserved   
#define IANAport_mediat       			5157			// tcp,Mediat Remote Object Exchange   
//#define IANAport_				          5157			// udp,Reserved   
#define IANAport_snmpssh 	      		5161			// tcp,SNMP over SSH Transport Model,[RFC5592]  ,
//#define IANAport_				          5161			// udp,Reserved   
#define IANAport_snmpssh_trap   		5162			// tcp,SNMP Notification over SSH Transport Model,[RFC5592]  ,
//#define IANAport_				          5162			// udp,Reserved   
#define IANAport_sbackup 	      		5163			// tcp,Shadow Backup   
//#define IANAport_			      	    5163			// udp,Reserved   
#define IANAport_vpa 		        		5164			// tcp,Virtual Protocol Adapter   
#define IANAport_vpa_disc     			5164			// udp,Virtual Protocol Adapter Discovery   
#define IANAport_ife_icorp    			5165			// tcp,"ife_1corp IANA assigned this well_formed service name as a replacement for ""ife_icorp""."   
#define IANAport_winpcs 	      		5166			// tcp,WinPCS Service Connection   
#define IANAport_scte104 	      		5167			// tcp,SCTE104 Connection   
#define IANAport_scte30 	      		5168			// tcp,SCTE30 Connection   
#define IANAport_pcoip_mgmt     		5172			// tcp,PC over IP Endpoint Management   
//#define IANAport_			      	    5172			// udp,Reserved   
#define IANAport_aol 	        			5190			// tcp,America_Online   
#define IANAport_aol_1 	      			5191			// tcp,AmericaOnline1   
#define IANAport_aol_2 	      			5192			// tcp,AmericaOnline2   
#define IANAport_aol_3 	      			5193			// tcp,AmericaOnline3   
#define IANAport_cpscomm 	      		5194			// tcp,CipherPoint Config Service   
//#define IANAport_				          5194			// udp,Reserved   
#define IANAport_ampl_lic     			5195			// tcp,The protocol is used by a license server and client programs to control use of program licenses that float to networked machines   
//#define IANAport_				          5195			// udp,Reserved   
#define IANAport_ampl_tableproxy  	5196			// tcp,"The protocol is used by two programs that exchange ""table"" data used in the AMPL modeling language"   
//#define IANAport_				          5196			// udp,Reserved   
#define IANAport_tunstall_lwp   		5197			// tcp,Tunstall Lone worker device interface   
//#define IANAport_				          5197			// udp,Reserved   
#define IANAport_targus_getdata   	5200			// tcp,TARGUS GetData   
#define IANAport_targus_getdata1   	5201			// tcp,TARGUS GetData 1   
#define IANAport_targus_getdata2  	5202			// tcp,TARGUS GetData 2   
#define IANAport_targus_getdata3   	5203			// tcp,TARGUS GetData 3   
#define IANAport_nomad 		      		5209			// tcp,Nomad Device Video Transfer   
//#define IANAport_				          5209			// udp,Reserved   
#define IANAport_noteza       			5215			// tcp,NOTEZA Data Safety Service   
//#define IANAport_				          5215			// udp,Reserved   
#define IANAport_3exmp 		      		5221			// tcp,3eTI Extensible Management Protocol for OAMP   
//#define IANAport_				          5221			// udp,Reserved   
#define IANAport_xmpp_client    		5222			// tcp,XMPP Client Connection,[RFC6120]  ,
//#define IANAport_				          5222			// udp,Reserved   
#define IANAport_hpvirtgrp    			5223			// tcp,HP Virtual Machine Group Management   
#define IANAport_hpvirtctrl     		5224			// tcp,HP Virtual Machine Console Operations   
#define IANAport_hp_server 	    		5225			// tcp,HP Server   
#define IANAport_hp_status    			5226			// tcp,HP Status   
#define IANAport_perfd 		      		5227			// tcp,HP System Performance Metric Service   
#define IANAport_hpvroom 	      		5228			// tcp,HP Virtual Room Service   
//#define IANAport_				          5228			// udp,Reserved   
#define IANAport_jaxflow 	      		5229			// tcp,Netflow/IPFIX/sFlow Collector and Forwarder Management   
//#define IANAport_				          5229			// udp,Reserved   
#define IANAport_jaxflow_data   		5230			// tcp,JaxMP RealFlow application and protocol data   
//#define IANAport_			      	    5230			// udp,Reserved   
#define IANAport_crusecontrol   		5231			// tcp,Remote Control of Scan Software for Cruse Scanners   
//#define IANAport_			      	    5231			// udp,Reserved   
#define IANAport_csedaemon    			5232			// tcp,Cruse Scanning System Service   
//#define IANAport_			      	    5232			// udp,Reserved   
#define IANAport_enfs 	      			5233			// tcp,Etinnae Network File Service   
//#define IANAport_			      	    5233			// udp,Reserved   
#define IANAport_eenet 	      			5234			// tcp,EEnet communications   
#define IANAport_galaxy_network   	5235			// tcp,Galaxy Network Service   
#define IANAport_padl2sim 	    		5236			// tcp   ,
#define IANAport_mnet_discovery   	5237			// tcp,m_net discovery   
#define IANAport_attune 	      		5242			// tcp,ATTUne API   
//#define IANAport_			      	    5242			// udp,Reserved   
#define IANAport_xycstatus 	    		5243			// tcp,xyClient Status API and rendevous point   
//#define IANAport_				          5243			// udp,Reserved   
#define IANAport_downtools 	    		5245			// tcp,DownTools Control Protocol   
#define IANAport_downtools_disc   	5245			// udp,DownTools Discovery Protocol   
//#define IANAport_			      	    5246			// tcp,Reserved   
#define IANAport_capwap_control   	5246			// udp,CAPWAP Control Protocol,[RFC5415]  ,
//#define IANAport_				          5247			// tcp,Reserved   
#define IANAport_capwap_data 	    	5247			// udp,CAPWAP Data Protocol,[RFC5415]  ,
#define IANAport_caacws 	      		5248			// tcp,CA Access Control Web Service   
#define IANAport_caaclang2 	    		5249			// tcp,CA AC Lang Service   
#define IANAport_soagateway     		5250			// tcp,soaGateway   
#define IANAport_caevms 	      		5251			// tcp,CA eTrust VM Service   
#define IANAport_movaz_ssc    			5252			// tcp,Movaz SSC   
#define IANAport_kpdp 		      		5253			// tcp,Kohler Power Device Protocol   
//#define IANAport_			      	    5253			// udp,Reserved   
#define IANAport_logcabin 	    		5254			// tcp,LogCabin storage service   
//#define IANAport_				          5254			// udp,Reserved   
#define IANAport_3com_njack_1   		5264			// tcp,3Com Network Jack Port 1   
#define IANAport_3com_njack_2   		5265			// tcp,3Com Network Jack Port 2   
#define IANAport_xmpp_server    		5269			// tcp,XMPP Server Connection,[RFC6120]  ,
//#define IANAport_			      	    5269			// udp,Reserved   
#define IANAport_cartographerxmp  	5270			// tcp,Cartographer XMP   
#define IANAport_cuelink 	      		5271			// tcp,StageSoft CueLink messaging   
#define IANAport_cuelink_disc   		5271			// udp,StageSoft CueLink discovery   
#define IANAport_pk 			        	5272			// tcp,PK   
#define IANAport_xmpp_bosh 	    		5280			// tcp,Bidirectional_streams Over Synchronous HTTP (BOSH)   
//#define IANAport_				          5280			// udp,Reserved   
#define IANAport_undo_lm 	      		5281			// tcp,Undo License Manager   
//#define IANAport_			      	    5281			// udp,Reserved   
#define IANAport_transmit_port  		5282			// tcp,Marimba Transmitter Port   
#define IANAport_presence 	    		5298			// tcp,XMPP Link_Local Messaging   
#define IANAport_nlg_data     			5299			// tcp,NLG Data Service   
#define IANAport_hacl_hb 	      		5300			// tcp,HA cluster heartbeat   
#define IANAport_hacl_gs 	      		5301			// tcp,HA cluster general services   
#define IANAport_hacl_cfg 	    		5302			// tcp,HA cluster configuration   
#define IANAport_hacl_probe     		5303			// tcp,HA cluster probing   
#define IANAport_hacl_local     		5304			// tcp,HA Cluster Commands   
#define IANAport_hacl_test 	    		5305			// tcp,HA Cluster Test   
#define IANAport_sun_mc_grp     		5306			// tcp,Sun MC Group   
#define IANAport_sco_aip 	      		5307			// tcp,SCO AIP   
#define IANAport_cfengine     			5308			// tcp,CFengine   
#define IANAport_jprinter 	    		5309			// tcp,J Printer   
#define IANAport_outlaws 	      		5310			// tcp,Outlaws   
#define IANAport_permabit_cs 	    	5312			// tcp,Permabit Client_Server   
#define IANAport_rrdp 			      	5313			// tcp,Real_time & Reliable Data   
#define IANAport_opalis_rbt_ipc   	5314			// tcp,opalis_rbt_ipc   
#define IANAport_hacl_poll 	    		5315			// tcp,HA Cluster UDP Polling   
#define IANAport_hpbladems 	    		5316			// tcp,HPBladeSystem Monitor Service   
#define IANAport_hpdevms 	      		5317			// tcp,HP Device Monitor Service   
//#define IANAport_				          5317			// udp,Reserved   
#define IANAport_pkix_cmc     			5318			// tcp,PKIX Certificate Management using CMS (CMC),[RFC6402]  ,
//#define IANAport_				          5318			// udp,Reserved   
#define IANAport_bsfserver_zn   		5320			// tcp,Webservices_based Zn interface of BSF   
//#define IANAport_			      	    5320			// udp,Reserved   
#define IANAport_bsfsvr_zn_ssl  		5321			// tcp,Webservices_based Zn interface of BSF over SSL   
//#define IANAport_				          5321			// udp,Reserved   
#define IANAport_kfserver     			5343			// tcp,Sculptor Database Server   
#define IANAport_xkotodrcp 	    		5344			// tcp,xkoto DRCP   
#define IANAport_stuns 		      		5349			// tcp,Session Traversal Utilities for NAT (STUN) port,[RFC8489],[RFC7350],[RFC8656]  ,
#define IANAport_stun_behaviors   	5349			// tcp,STUN Behavior Discovery over TLS,[RFC5780]  ,
//#define IANAport_				          5350			// tcp,Reserved   
#define IANAport_pcp_multicast  		5350			// udp,Port Control Protocol Multicast,[RFC6887]  ,
//#define IANAport_		      		    5351			// tcp,Reserved   
#define IANAport_pcp 		        		5351			// udp,Port Control Protocol,[RFC6887]  ,
#define IANAport_dns_llq 	      		5352			// tcp,DNS Long_Lived Queries,[RFC8764]  ,
#define IANAport_mdns 		      		5353			// tcp,Multicast DNS,[RFC6762]  ,
#define IANAport_mdnsresponder  		5354			// tcp,Multicast DNS Responder IPC   
#define IANAport_llmnr 		      		5355			// tcp,LLMNR   
#define IANAport_ms_smlbiz    			5356			// tcp,Microsoft Small Business   
#define IANAport_wsdapi 	      		5357			// tcp,Web Services for Devices   
#define IANAport_wsdapi_s 	    		5358			// tcp,WS for Devices Secured   
#define IANAport_ms_alerter     		5359			// tcp,Microsoft Alerter   
#define IANAport_ms_sideshow    		5360			// tcp,Protocol for Windows SideShow   
#define IANAport_ms_s_sideshow 	  	5361			// tcp,Secure Protocol for Windows SideShow   
#define IANAport_serverwsd2     		5362			// tcp,Microsoft Windows Server WSD2 Service   
#define IANAport_net_projection   	5363			// tcp,Windows Network Projection   
#define IANAport_kdnet 		      		5364			// udp,Microsoft Kernel Debugger   
//#define IANAport_				          5364			// tcp,Reserved   
#define IANAport_stresstester   		5397			// tcp,StressTester(tm) Injector   
#define IANAport_elektron_admin   	5398			// tcp,Elektron Administration   
#define IANAport_securitychase  		5399			// tcp,SecurityChase   
#define IANAport_excerpt 	      		5400			// tcp,Excerpt Search   
#define IANAport_excerpts 	    		5401			// tcp,Excerpt Search Secure   
#define IANAport_mftp_mftp	    		5402			// tcp,OmniCast MFTP - Note amended
#define IANAport_hpoms_ci_lstn  		5403			// tcp,HPOMS_CI_LSTN   
#define IANAport_hpoms_dps_lstn   	5404			// tcp,HPOMS_DPS_LSTN   
#define IANAport_netsupport 	    	5405			// tcp,NetSupport   
#define IANAport_systemics_sox  		5406			// tcp,Systemics Sox   
#define IANAport_foresyte_clear   	5407			// tcp,Foresyte_Clear   
#define IANAport_foresyte_sec 	  	5408			// tcp,Foresyte_Sec   
#define IANAport_salient_dtasrv   	5409			// tcp,Salient Data Server   
#define IANAport_salient_usrmgr   	5410			// tcp,Salient User Manager   
#define IANAport_actnet 	      		5411			// tcp,ActNet   
#define IANAport_continuus 	    		5412			// tcp,Continuus   
#define IANAport_wwiotalk     			5413			// tcp,WWIOTALK   
#define IANAport_statusd 	      		5414			// tcp,StatusD   
#define IANAport_ns_server    			5415			// tcp,NS Server   
#define IANAport_sns_gateway    		5416			// tcp,SNS Gateway   
#define IANAport_sns_agent    			5417			// tcp,SNS Agent   
#define IANAport_mcntp 		      		5418			// tcp,MCNTP   
#define IANAport_dj_ice       			5419			// tcp,DJ_ICE   
#define IANAport_cylink_c 	    		5420			// tcp,Cylink_C   
#define IANAport_netsupport2    		5421			// tcp,Net Support 2   
#define IANAport_salient_mux    		5422			// tcp,Salient MUX   
#define IANAport_virtualuser 	    	5423			// tcp,VIRTUALUSER   
#define IANAport_beyond_remote  		5424			// tcp,Beyond Remote   
#define IANAport_br_channel     		5425			// tcp,Beyond Remote Command Channel   
#define IANAport_devbasic 	    		5426			// tcp,DEVBASIC   
#define IANAport_sco_peer_tta   		5427			// tcp,SCO_PEER_TTA   
#define IANAport_telaconsole    		5428			// tcp,TELACONSOLE   
#define IANAport_base 			      	5429			// tcp,Billing and Accounting System Exchange   
#define IANAport_radec_corp     		5430			// tcp,RADEC CORP   
#define IANAport_park_agent     		5431			// tcp,PARK AGENT   
#define IANAport_postgresql     		5432			// tcp,PostgreSQL Database   
#define IANAport_pyrrho 	      		5433			// tcp,Pyrrho DBMS   
#define IANAport_sgi_arrayd     		5434			// tcp,SGI Array Services Daemon   
#define IANAport_sceanics 	    		5435			// tcp,SCEANICS situation and action notification   
//#define IANAport_				          5436			// tcp,Reserved   
#define IANAport_pmip6_cntl     		5436			// udp,pmip6_cntl,[RFC5844]  ,
//#define IANAport_			      	    5437			// tcp,Reserved   
#define IANAport_pmip6_data     		5437			// udp,pmip6_data,[RFC5844]  ,
#define IANAport_spss 		      		5443			// tcp,Pearson HTTPS   
#define IANAport_smbdirect 	    		5445			// tcp,Server Message Block over Remote Direct Memory Access   
//#define IANAport_			      	    5445			// udp,Reserved   
#define IANAport_smbdirect 	    		5445			// sctp,Server Message Block over Remote Direct Memory Access   
#define IANAport_tiepie 	      		5450			// tcp,TiePie engineering data acquisition   
#define IANAport_tiepie_disc    		5450			// udp,TiePie engineering data acquisition (discovery)   
#define IANAport_surebox 	      		5453			// tcp,SureBox   
#define IANAport_apc_5454     			5454			// tcp,APC 5454   
#define IANAport_apc_5455     			5455			// tcp,APC 5455   
#define IANAport_apc_5456 	    		5456			// tcp,APC 5456   
#define IANAport_silkmeter 	    		5461			// tcp,SILKMETER   
#define IANAport_ttl_publisher  		5462			// tcp,TTL Publisher   
#define IANAport_ttlpriceproxy  		5463			// tcp,TTL Price Proxy   
#define IANAport_quailnet 	    		5464			// tcp,Quail Networks Object Broker   
#define IANAport_netops_broker  		5465			// tcp,NETOPS_BROKER   
#define IANAport_apsolab_col    		5470			// tcp,The Apsolab company's data collection protocol (native api)   
//#define IANAport_				          5470			// udp,Reserved   
#define IANAport_apsolab_cols   		5471			// tcp,The Apsolab company's secure data collection protocol (native api)   
//#define IANAport_				          5471			// udp,Reserved   
#define IANAport_apsolab_tag    		5472			// tcp,The Apsolab company's dynamic tag protocol   
//#define IANAport_				          5472			// udp,Reserved   
#define IANAport_apsolab_tags   		5473			// tcp,The Apsolab company's secure dynamic tag protocol   
//#define IANAport_			      	    5473			// udp,Reserved   
#define IANAport_apsolab_rpc    		5474			// udp,The Apsolab company's status query protocol   
//#define IANAport_			      	    5474			// tcp,Reserved   
#define IANAport_apsolab_data   		5475			// tcp,The Apsolab company's data retrieval protocol   
//#define IANAport_			      	    5475			// udp,Reserved   
#define IANAport_fcp_addr_srvr1   	5500			// tcp,fcp_addr_srvr1   
#define IANAport_fcp_addr_srvr2    	5501			// tcp,fcp_addr_srvr2   
#define IANAport_fcp_srvr_inst1   	5502			// tcp,fcp_srvr_inst1   
#define IANAport_fcp_srvr_inst2   	5503			// tcp,fcp_srvr_inst2   
#define IANAport_fcp_cics_gw1   		5504			// tcp,fcp_cics_gw1   
#define IANAport_checkoutdb 	    	5505			// tcp,Checkout Database   
#define IANAport_amc 			        	5506			// tcp,Amcom Mobile Connect   
#define IANAport_psl_management   	5507			// tcp,PowerSysLab Electrical Management   
//#define IANAport_			      	    5507			// udp,Reserved   
#define IANAport_matter       			5540			// tcp,Matter Operational Discovery and Communi   
#define IANAport_cbus 	      			5550			// tcp,Model Railway control using the CBUS message protocol   
//#define IANAport_		      		    5550			// udp,Reserved   
#define IANAport_sgi_eventmond  		5553			// tcp,SGI Eventmond Port   
#define IANAport_sgi_esphttp    		5554			// tcp,SGI ESP HTTP   
#define IANAport_personal_agent    	5555			// tcp,Personal Agent   
#define IANAport_freeciv 	      		5556			// tcp,Freeciv gameplay   
#define IANAport_farenet      			5557			// tcp,Sandlab FARENET   
//#define IANAport_			      	    5557			// udp,Reserved   
#define IANAport_dp_bura 	      		5565			// tcp,Data Protector BURA   
//#define IANAport_				          5565			// udp,Reserved   
#define IANAport_westec_connect   	5566			// tcp,Westec Connect   
//#define IANAport_		      		    5566			// udp,Reserved   
#define IANAport_dof_dps_mc_sec   	5567			// tcp,DOF Protocol Stack Multicast/Secure Transport   
#define IANAport_sdt        				5568			// tcp,Session Data Transport Multicast   
#define IANAport_rdmnet_ctrl    		5569			// tcp,"PLASA E1.33, Remote Device Management (RDM) controller status notifications"   
#define IANAport_rdmnet_device  		5569			// udp,"PLASA E1.33, Remote Device Management (RDM) messages"   
#define IANAport_sdmmp 		      		5573			// tcp,SAS Domain Management Messaging Protocol   
#define IANAport_lsi_bobcat     		5574			// tcp,SAS IO Forwarding   
//#define IANAport_				          5574			// udp,Reserved   
#define IANAport_ora_oap 	      		5575			// tcp,Oracle Access Protocol   
//#define IANAport_				          5575			// udp,Reserved   
#define IANAport_fdtracks     			5579			// tcp,FleetDisplay Tracking Service   
//#define IANAport_				          5579			// udp,Reserved   
#define IANAport_tmosms0 	      		5580			// tcp,T_Mobile SMS Protocol Message 0   
#define IANAport_tmosms1 	      		5581			// tcp,T_Mobile SMS Protocol Message 1   
#define IANAport_fac_restore 	    	5582			// tcp,T_Mobile SMS Protocol Message 3   
#define IANAport_tmo_icon_sync  		5583			// tcp,T_Mobile SMS Protocol Message 2   
#define IANAport_bis_web 	      		5584			// tcp,BeInSync_Web   
#define IANAport_bis_sync     			5585			// tcp,BeInSync_sync   
#define IANAport_att_mt_sms     		5586			// tcp,Planning to send mobile terminated SMS to the specific port so that the SMS is not visible to the client   
//#define IANAport_				          5586			// udp,Reserved   
#define IANAport_ininmessaging 	  	5597			// tcp,inin secure messaging   
#define IANAport_mctfeed 	      		5598			// tcp,MCT Market Data Feed   
#define IANAport_esinstall 	    		5599			// tcp,Enterprise Security Remote Install   
#define IANAport_esmmanager     		5600			// tcp,Enterprise Security Manager   
#define IANAport_esmagent 	    		5601			// tcp,Enterprise Security Agent   
#define IANAport_a1_msc 	      		5602			// tcp,A1_MSC   
#define IANAport_a1_bs 			      	5603			// tcp,A1_BS   
#define IANAport_a3_sdunode     		5604			// tcp,A3_SDUNode   
#define IANAport_a4_sdunode     		5605			// tcp,A4_SDUNode   
#define IANAport_efr 		        		5618			// tcp,Fiscal Registering Protocol   
//#define IANAport_				          5618			// udp,Reserved   
#define IANAport_ninaf 		      		5627			// tcp,Node Initiated Network Association Forma   
#define IANAport_htrust 	      		5628			// tcp,HTrust API   
#define IANAport_symantec_sfdb  		5629			// tcp,Symantec Storage Foundation for Database   
#define IANAport_precise_comm   		5630			// tcp,PreciseCommunication   
#define IANAport_pcanywheredata   	5631			// tcp,pcANYWHEREdata   
#define IANAport_pcanywherestat   	5632			// tcp,pcANYWHEREstat   
#define IANAport_beorl 		      		5633			// tcp,BE Operations Request Listener   
#define IANAport_xprtld 	      		5634			// tcp,SF Message Service   
#define IANAport_sfmsso 	      		5635			// tcp,SFM Authentication Subsystem   
//#define IANAport_				          5635			// udp,Reserved   
#define IANAport_sfm_db_server 	  	5636			// tcp,SFMdb _ SFM DB server   
//#define IANAport_			      	    5636			// udp,Reserved   
#define IANAport_cssc 	      			5637			// tcp,Symantec CSSC   
//#define IANAport_				          5637			// udp,Reserved   
#define IANAport_flcrs 		      		5638			// tcp,Symantec Fingerprint Lookup and Container Reference Service   
//#define IANAport_			      	    5638			// udp,Reserved   
#define IANAport_ics 		        		5639			// tcp,Symantec Integrity Checking Service   
//#define IANAport_			      	    5639			// udp,Reserved   
#define IANAport_vfmobile     			5646			// tcp,Ventureforth Mobile   
//#define IANAport_				          5646			// udp,Reserved   
#define IANAport_nrpe 	      			5666			// tcp,Nagios Remote Plugin Executor   
//#define IANAport_		      		    5666			// udp,Reserved   
#define IANAport_filemq       			5670			// tcp,ZeroMQ file publish_subscribe protocol   
#define IANAport_zre_disc     			5670			// udp,Local area discovery and messaging over ZeroMQ   
#define IANAport_amqps 	      			5671			// tcp,amqp protocol over TLS/SSL   
#define IANAport_amqp 	      			5672			// tcp,AMQP   
#define IANAport_jms 		        		5673			// tcp,JACL Message Server   
#define IANAport_hyperscsi_port   	5674			// tcp,HyperSCSI Port   
#define IANAport_v5ua 		      		5675			// tcp,V5UA application port,[RFC3807]  ,
#define IANAport_raadmin      			5676			// tcp,RA Administration   
#define IANAport_questdb2_lnchr   	5677			// tcp,Quest Central DB2 Launchr   
#define IANAport_rrac 		      		5678			// tcp,Remote Replication Agent Connection   
#define IANAport_dccm 		      		5679			// tcp,Direct Cable Connect Manager   
#define IANAport_auriga_router    	5680			// tcp,Auriga Router Service   
#define IANAport_ncxcp 	      			5681			// tcp,Net_coneX Control Protocol   
//#define IANAport_			      	    5682			// tcp,Reserved   
#define IANAport_brightcore     		5682			// udp,BrightCore control & data transfer exchange   
#define IANAport_coap 	      			5683			// tcp,Constrained Application Protocol (CoAP),[RFC8323]  ,
#define IANAport_coaps 		      		5684			// tcp,Constrained Application Protocol (CoAP),[RFC7301][RFC8323]  ,
#define IANAport_gog_multiplayer  	5687			// udp,GOG multiplayer game protocol   
//#define IANAport_				          5687			// tcp,Reserved   
#define IANAport_ggz 		        		5688			// tcp,GGZ Gaming Zone   
#define IANAport_qmvideo 	      		5689			// tcp,QM video network management protocol   
#define IANAport_rbsystem 	    		5693			// tcp,Robert Bosch Data Transfer   
//#define IANAport_				          5693			// udp,Reserved   
#define IANAport_kmip 	      			5696			// tcp,Key Management Interoperability Protocol   
//#define IANAport_			      	    5696			// udp,Reserved   
#define IANAport_supportassist  		5700			// tcp,Dell SupportAssist data center management   
//#define IANAport_				          5700			// udp,Reserved   
#define IANAport_storageos 	    		5705			// tcp,StorageOS REST API   
//#define IANAport_				          5705			// udp,Reserved   
#define IANAport_proshareaudio 	  	5713			// tcp,proshare conf audio   
#define IANAport_prosharevideo 	  	5714			// tcp,proshare conf video   
#define IANAport_prosharedata   		5715			// tcp,proshare conf data   
#define IANAport_prosharerequest  	5716			// tcp,proshare conf request   
#define IANAport_prosharenotify   	5717			// tcp,proshare conf notify   
#define IANAport_dpm 		        		5718			// tcp,DPM Communication Server   
#define IANAport_dpm_agent 	    		5719			// tcp,DPM Agent Coordinator   
#define IANAport_ms_licensing   		5720			// tcp,MS_Licensing   
#define IANAport_dtpt 	      			5721			// tcp,Desktop Passthru Service   
#define IANAport_msdfsr       			5722			// tcp,Microsoft DFS Replication Service   
#define IANAport_omhs 	      			5723			// tcp,Operations Manager _ Health Service   
#define IANAport_omsdk 	      			5724			// tcp,Operations Manager _ SDK Service   
#define IANAport_ms_ilm       			5725			// tcp,Microsoft Identity Lifecycle Manager   
//#define IANAport_			      	    5725			// udp,Reserved   
#define IANAport_ms_ilm_sts     		5726			// tcp,Microsoft Lifecycle Manager Secure Token Service   
//#define IANAport_				          5726			// udp,Reserved   
#define IANAport_asgenf 	      		5727			// tcp,ASG Event Notification Framework   
//#define IANAport_			      	    5727			// udp,Reserved   
#define IANAport_io_dist_data   		5728			// tcp,Dist. I/O Comm. Service Data and Control   
#define IANAport_openmail 	    		5729			// tcp,Openmail User Agent Layer   
#define IANAport_unieng 	      		5730			// tcp,Steltor's calendar access   
#define IANAport_ida_discover1 	  	5741			// tcp,IDA Discover Port 1   
#define IANAport_ida_discover2  		5742			// tcp,IDA Discover Port 2   
#define IANAport_watchdoc_pod   		5743			// tcp,Watchdoc NetPOD Protocol   
#define IANAport_watchdoc 	    		5744			// tcp,Watchdoc Server   
#define IANAport_fcopy_server   		5745			// tcp,fcopy_server   
#define IANAport_fcopys_server  		5746			// tcp,fcopys_server   
#define IANAport_tunatic 	      		5747			// tcp,Wildbits Tunatic   
#define IANAport_tunalyzer 	    		5748			// tcp,Wildbits Tunalyzer   
#define IANAport_rscd 		      		5750			// tcp,Bladelogic Agent Service   
#define IANAport_openmailg 	    		5755			// tcp,OpenMail Desk Gateway server   
#define IANAport_x500ms 	      		5757			// tcp,OpenMail X.500 Directory Server   
#define IANAport_openmailns     		5766			// tcp,OpenMail NewMail Server   
#define IANAport_s_openmail     		5767			// tcp,OpenMail Suer Agent Layer (Secure)   
#define IANAport_openmailpxy    		5768			// tcp,OpenMail CMTS Server   
#define IANAport_spramsca 	    		5769			// tcp,x509solutions Internal CA   
#define IANAport_spramsd 	      		5770			// tcp,x509solutions Secure Data   
#define IANAport_netagent     			5771			// tcp,NetAgent   
#define IANAport_starfield_io   		5777			// tcp,Control commands and responses   
#define IANAport_vts_rpc 	      		5780			// tcp,Visual Tag System RPC   
//#define IANAport_				          5780			// udp,Reserved   
#define IANAport_3par_evts 	    		5781			// tcp,3PAR Event Reporting Service   
#define IANAport_3par_mgmt 	    		5782			// tcp,3PAR Management Service   
#define IANAport_3par_mgmt_ssl  		5783			// tcp,3PAR Management Service with SSL   
//#define IANAport_				          5784			// tcp,Reserved   
#define IANAport_ibar 	      			5784			// udp,Cisco Interbox Application Redundancy   
#define IANAport_3par_rcopy     		5785			// tcp,3PAR Inform Remote Copy   
//#define IANAport_				          5786			// tcp,Reserved   
#define IANAport_cisco_redu     		5786			// udp,redundancy notification   
//#define IANAport_			      	    5787			// tcp,Reserved   
#define IANAport_waascluster    		5787			// udp,Cisco WAAS Cluster Protocol   
#define IANAport_xtreamx 	      		5793			// tcp,XtreamX Supervised Peer message   
//#define IANAport_				          5794			// tcp,Reserved   
#define IANAport_spdp 		      		5794			// udp,Simple Peered Discovery Protocol   
#define IANAport_enlabel_dpl    		5798			// tcp,Proprietary Website deployment service   
//#define IANAport_			      	    5798			// udp,Reserved   
#define IANAport_icmpd 		      		5813			// tcp,ICMPD   
#define IANAport_spt_automation   	5814			// tcp,Support Automation   
#define IANAport_autopassdaemon   	5820			// tcp,AutoPass licensing   
//#define IANAport_			      	    5820			// udp,Reserved   
#define IANAport_shiprush_d_ch  		5841			// tcp,Z_firm ShipRush interface for web access and bidirectional data   
//#define IANAport_				          5841			// udp,Reserved   
#define IANAport_reversion 	    		5842			// tcp,Reversion Backup/Restore   
//#define IANAport_				          5842			// udp,Reserved   
#define IANAport_wherehoo     			5859			// tcp,WHEREHOO   
#define IANAport_ppsuitemsg     		5863			// tcp,PlanetPress Suite Messeng   
#define IANAport_diameters 	    		5868			// tcp,Diameter over TLS/TCP,[RFC6733]  ,
//#define IANAport_				          5868			// udp,Reserved   
#define IANAport_jute 	      			5883			// tcp,Javascript Unit Test Environment   
#define IANAport_rfb 		        		5900			// tcp,Remote Framebuffer,[RFC6143]  ,
#define IANAport_ff_ice 	      		5903			// tcp,Flight & Flow Info for Collaborative Env   
#define IANAport_ag_swim 	      		5904			// tcp,Air_Ground SWIM   
#define IANAport_asmgcs 	      		5905			// tcp,Adv Surface Mvmnt and Guidance Cont Sys   
#define IANAport_rpas_c2 	      		5906			// tcp,Remotely Piloted Vehicle C&C   
#define IANAport_dsd 			        	5907			// tcp,Distress and Safety Data App   
#define IANAport_ipsma 		      		5908			// tcp,IPS Management Application   
#define IANAport_agma 		      		5909			// tcp,Air_ground media advisory   
#define IANAport_ats_atn 	      		5910			// tcp,Air Traffic Services applications using ATN   
#define IANAport_cm 			        	5910			// sctp,Context Management   
#define IANAport_ats_acars 	    		5911			// tcp,Air Traffic Services applications using ACARS   
#define IANAport_cpdlc 		      		5911			// sctp,Controller Pilot Data Link Communication   
#define IANAport_ais_met 	      		5912			// tcp,Aeronautical Information Service/Meteorological applications using ACARS   
#define IANAport_fis 			        	5912			// sctp,Flight Information Services   
#define IANAport_aoc_acars 	    		5913			// tcp,Airline operational communications applications using ACARS   
#define IANAport_ads_c 		      		5913			// sctp,Automatic Dependent Surveillance   
#define IANAport_indy 		      		5963			// tcp,Indy Application Server   
#define IANAport_mppolicy_v5 	    	5968			// tcp,mppolicy_v5   
#define IANAport_mppolicy_mgr   		5969			// tcp,mppolicy_mgr   
#define IANAport_couchdb 	      		5984			// tcp,CouchDB   
#define IANAport_wsman 		      		5985			// tcp,WBEM WS_Management HTTP   
#define IANAport_wsmans 	      		5986			// tcp,WBEM WS_Management HTTP over TLS/SSL   
#define IANAport_wbem_rmi     			5987			// tcp,WBEM RMI   
#define IANAport_wbem_http 	    		5988			// tcp,WBEM CIM_XML (HTTP)   
#define IANAport_wbem_https     		5989			// tcp,WBEM CIM_XML (HTTPS)   
#define IANAport_wbem_exp_https   	5990			// tcp,WBEM Export HTTPS   
#define IANAport_nuxsl 			      	5991			// tcp,NUXSL   
#define IANAport_consul_insight   	5992			// tcp,Consul InSight Security   
#define IANAport_cim_rs 	      		5993			// tcp,DMTF WBEM CIM REST   
//#define IANAport_				          5993			// udp,Reserved   
#define IANAport_rms_agent 	    		5994			// tcp,RMS Agent Listening Service   
//#define IANAport_				          5994			// udp,Reserved   
#define IANAport_cvsup 		      		5999			// tcp,CVSup   
#define IANAport_x11 		        		6000			// tcp,X Window System, common value for port range 6000_6063  
#define IANAport_x11_00	      			6000			// tcp,X Window System   
#define IANAport_x11_01	      			6001			// tcp,X Window System   
#define IANAport_x11_02	      			6002			// tcp,X Window System   
#define IANAport_x11_03	      			6003			// tcp,X Window System   
#define IANAport_x11_04	      			6004			// tcp,X Window System   
#define IANAport_x11_05	      			6005			// tcp,X Window System   
#define IANAport_x11_06	      			6006			// tcp,X Window System   
#define IANAport_x11_07     				6007			// tcp,X Window System   
#define IANAport_x11_08			      	6008			// tcp,X Window System   
#define IANAport_x11_09	      			6009			// tcp,X Window System   
#define IANAport_x11_10				      6010			// tcp,X Window System   
#define IANAport_x11_11	      			6011			// tcp,X Window System   
#define IANAport_x11_12				      6012			// tcp,X Window System   
#define IANAport_x11_13       			6013			// tcp,X Window System   
#define IANAport_x11_14				      6014			// tcp,X Window System   
#define IANAport_x11_15       			6015			// tcp,X Window System   
#define IANAport_x11_16				      6016			// tcp,X Window System   
#define IANAport_x11_17	      			6017			// tcp,X Window System   
#define IANAport_x11_18		      		6018			// tcp,X Window System   
#define IANAport_x11_19		      		6019			// tcp,X Window System   
#define IANAport_x11_20	      			6020			// tcp,X Window System   
#define IANAport_x11_21	      			6021			// tcp,X Window System   
#define IANAport_x11_22	      			6022			// tcp,X Window System   
#define IANAport_x11_23	      			6023			// tcp,X Window System   
#define IANAport_x11_24		      		6024			// tcp,X Window System   
#define IANAport_x11_25		      		6025			// tcp,X Window System   
#define IANAport_x11_26		      		6026			// tcp,X Window System   
#define IANAport_x11_27		      		6027			// tcp,X Window System   
#define IANAport_x11_28		      		6028			// tcp,X Window System   
#define IANAport_x11_29		      		6029			// tcp,X Window System   
#define IANAport_x11_30		      		6030			// tcp,X Window System   
#define IANAport_x11_31		      		6031			// tcp,X Window System   
#define IANAport_x11_32		      		6032			// tcp,X Window System   
#define IANAport_x11_33		      		6033			// tcp,X Window System   
#define IANAport_x11_34	      			6034			// tcp,X Window System   
#define IANAport_x11_35	      			6035			// tcp,X Window System   
#define IANAport_x11_36	      			6036			// tcp,X Window System   
#define IANAport_x11_37	      			6037			// tcp,X Window System   
#define IANAport_x11_38		      		6038			// tcp,X Window System   
#define IANAport_x11_39		      		6039			// tcp,X Window System   
#define IANAport_x11_40	      			6040			// tcp,X Window System   
#define IANAport_x11_41	      			6041			// tcp,X Window System   
#define IANAport_x11_42	      			6042			// tcp,X Window System   
#define IANAport_x11_43	      			6043			// tcp,X Window System   
#define IANAport_x11_44	      			6044			// tcp,X Window System   
#define IANAport_x11_45	      			6045			// tcp,X Window System   
#define IANAport_x11_46	      			6046			// tcp,X Window System   
#define IANAport_x11_47	      			6047			// tcp,X Window System   
#define IANAport_x11_48	      			6048			// tcp,X Window System   
#define IANAport_x11_49	      			6049			// tcp,X Window System   
#define IANAport_x11_50	      			6050			// tcp,X Window System   
#define IANAport_x11_51	      			6051			// tcp,X Window System   
#define IANAport_x11_52	      			6052			// tcp,X Window System   
#define IANAport_x11_53	      			6053			// tcp,X Window System   
#define IANAport_x11_54	      			6054			// tcp,X Window System   
#define IANAport_x11_55	      			6055			// tcp,X Window System   
#define IANAport_x11_56	      			6056			// tcp,X Window System   
#define IANAport_x11_57	      			6057			// tcp,X Window System   
#define IANAport_x11_58	      			6058			// tcp,X Window System   
#define IANAport_x11_59	      			6059			// tcp,X Window System   
#define IANAport_x11_60	      			6060			// tcp,X Window System   
#define IANAport_x11_61	      			6061			// tcp,X Window System   
#define IANAport_x11_62		      		6062			// tcp,X Window System   
#define IANAport_x11_63	      			6063			// tcp,X Window System   
#define IANAport_ndl_ahp_svc    		6064			// tcp,NDL_AHP_SVC   
#define IANAport_winpharaoh     		6065			// tcp,WinPharaoh   
#define IANAport_ewctsp 	      		6066			// tcp,EWCTSP   
#define IANAport_gsmp_ancp 	    		6068			// tcp,GSMP/ANCP,[RFC6320]  ,
//#define IANAport_				          6068			// udp,Reserved   
#define IANAport_trip 		      		6069			// tcp,TRIP   
#define IANAport_messageasap    		6070			// tcp,Messageasap   
#define IANAport_ssdtp 	      			6071			// tcp,SSDTP   
#define IANAport_diagnose_proc    	6072			// tcp,DIAGNOSE_PROC   
#define IANAport_directplay8    		6073			// tcp,DirectPlay8   
#define IANAport_max 	        			6074			// tcp,Microsoft Max   
#define IANAport_dpm_acm 	      		6075			// tcp,Microsoft DPM Access Control Manager   
//#define IANAport_				          6075			// udp,Reserved   
#define IANAport_msft_dpm_cert 	  	6076			// tcp,Microsoft DPM WCF Certificates   
//#define IANAport_			      	    6076			// udp,Reserved   
#define IANAport_iconstructsrv 	  	6077			// tcp,iConstruct Server   
//#define IANAport_			      	    6077			// udp,Reserved   
#define IANAport_gue 		        		6080			// udp,Generic UDP Encapsulation,[draft_herbert_gue]  ,
//#define IANAport_			      	    6080			// tcp,Reserved   
#define IANAport_geneve 	      		6081			// udp,Generic Network Virtualization Encapsulation (Geneve),[RFC8926]  ,
//#define IANAport_				          6081			// tcp,Reserved   
//#define IANAport_			      	    6082			// tcp,Reserved   
#define IANAport_p25cai       			6082			// udp,APCO Project 25 Common Air Interface _ UDP encapsulation   
//#define IANAport_			      	    6083			// tcp,Reserved   
#define IANAport_miami_bcast 	    	6083			// udp,telecomsoftware miami broadcast   
#define IANAport_reload_config  		6084			// tcp,Peer to Peer Infrastructure Configuration,[RFC6940]  ,
//#define IANAport_				          6084			// udp,Reserved   
#define IANAport_konspire2b     		6085			// tcp,konspire2b p2p network   
#define IANAport_pdtp 		      		6086			// tcp,PDTP P2P   
#define IANAport_ldss 		      		6087			// tcp,Local Download Sharing Service   
#define IANAport_doglms 		      	6088			// tcp,SuperDog License Manager   
#define IANAport_doglms_notify  		6088			// udp,SuperDog License Manager Notifier   
#define IANAport_raxa_mgmt 	    		6099			// tcp,RAXA Management   
//#define IANAport_				          6099			// udp,Reserved   
#define IANAport_synchronet_db  		6100			// tcp,SynchroNet_db   
#define IANAport_synchronet_rtc   	6101			// tcp,SynchroNet_rtc   
#define IANAport_synchronet_upd   	6102			// tcp,SynchroNet_upd   
#define IANAport_rets 	      			6103			// tcp,RETS   
#define IANAport_dbdb 		      		6104			// tcp,DBDB   
#define IANAport_primaserver    		6105			// tcp,Prima Server   
#define IANAport_mpsserver 	    		6106			// tcp,MPS Server   
#define IANAport_etc_control 	    	6107			// tcp,ETC Control   
#define IANAport_sercomm_scadmin  	6108			// tcp,Sercomm_SCAdmin   
#define IANAport_globecast_id   		6109			// tcp,GLOBECAST_ID   
#define IANAport_softcm 	      		6110			// tcp,HP SoftBench CM   
#define IANAport_spc 			        	6111			// tcp,HP SoftBench Sub_Process Control   
#define IANAport_dtspcd 	      		6112			// tcp,Desk_Top Sub_Process Control Daemon   
#define IANAport_dayliteserver 	  	6113			// tcp,Daylite Server   
//#define IANAport_				          6113			// udp,Reserved   
#define IANAport_wrspice 	      		6114			// tcp,WRspice IPC Service   
//#define IANAport_				          6114			// udp,Reserved   
#define IANAport_xic 			        	6115			// tcp,Xic IPC Service   
//#define IANAport_			      	    6115			// udp,Reserved   
#define IANAport_xtlserv 	      		6116			// tcp,XicTools License Manager Service   
//#define IANAport_				          6116			// udp,Reserved   
#define IANAport_daylitetouch   		6117			// tcp,Daylite Touch Sync   
//#define IANAport_			      	    6117			// udp,Reserved   
#define IANAport_tipc 	      			6118			// udp,Transparent Inter Process Communication   
//#define IANAport_			      	    6118			// tcp,Reserved   
#define IANAport_spdy 		      		6121			// tcp,SPDY for a faster web   
//#define IANAport_			      	    6121			// udp,Reserved   
#define IANAport_bex_webadmin   		6122			// tcp,Backup Express Web Server   
#define IANAport_backup_express   	6123			// tcp,Backup Express   
#define IANAport_pnbs 		      		6124			// tcp,Phlexible Network Backup Service   
#define IANAport_damewaremobgtwy  	6130			// tcp,The DameWare Mobile Gateway Service   
#//define IANAport_			      	    6130			// udp,Reserved   
#define IANAport_nbt_wol 	      		6133			// tcp,New Boundary Tech WOL   
#define IANAport_pulsonixnls    		6140			// tcp,Pulsonix Network License Service   
#define IANAport_meta_corp 	    		6141			// tcp,Meta Corporation License Manager   
#define IANAport_aspentec_lm 	    	6142			// tcp,Aspen Technology License Manager   
#define IANAport_watershed_lm   		6143			// tcp,Watershed License Manager   
#define IANAport_statsci1_lm    		6144			// tcp,StatSci License Manager _ 1   
#define IANAport_statsci2_lm      	6145			// tcp,StatSci License Manager _ 2   
#define IANAport_lonewolf_lm      	6146			// tcp,Lone Wolf Systems License Manager   
#define IANAport_montage_lm 	    	6147			// tcp,Montage License Manager   
#define IANAport_ricardo_lm_2   		6148			// tcp,Ricardo North America License Manager - Note amended
#define IANAport_tal_pod 	      		6149			// tcp,tal_pod   
#define IANAport_efb_aci 	      		6159			// tcp,EFB Application Control Interface   
//#define IANAport_				          6159			// udp,Reserved   
#define IANAport_ecmp 	      			6160			// tcp,Emerson Extensible Control and Management Protocol   
#define IANAport_ecmp_data 	    		6160			// udp,Emerson Extensible Control and Management Protocol Data   
#define IANAport_patrol_ism     		6161			// tcp,PATROL Internet Srv Mgr   
#define IANAport_patrol_coll    		6162			// tcp,PATROL Collector   
#define IANAport_pscribe 	      		6163			// tcp,Precision Scribe Cnx Port   
#define IANAport_lm_x 	      			6200			// tcp,LM_X License Manager by X_Formation   
//#define IANAport_			      	    6201			// tcp,Reserved   
#define IANAport_thermo_calc    		6201			// udp,Management of service nodes in a processing grid for thermodynamic calculations   
#define IANAport_qmtps 	      			6209			// tcp,QMTP over TLS   
#define IANAport_radmind 	      		6222			// tcp,Radmind Access Protocol   
#define IANAport_jeol_nsdtp_1   		6241			// tcp,JEOL Network Services Data Transport Protocol 1   
#define IANAport_jeol_nsdtp_2   		6242			// tcp,JEOL Network Services Data Transport Protocol 2   
#define IANAport_jeol_nsdtp_3   		6243			// tcp,JEOL Network Services Data Transport Protocol 3   
#define IANAport_jeol_nsdtp_4   		6244			// tcp,JEOL Network Services Data Transport Protocol 4   
#define IANAport_tl1_raw_ssl    		6251			// tcp,TL1 Raw Over SSL/TLS   
#define IANAport_tl1_ssh 		      	6252			// tcp,TL1 over SSH   
#define IANAport_crip 			      	6253			// tcp,CRIP   
#define IANAport_gld 			        	6267			// tcp,GridLAB_D User Interface   
//#define IANAport_			      	    6267			// udp,Reserved   
#define IANAport_grid 		      		6268			// tcp,Grid Authentication   
#define IANAport_grid_alt     			6269			// tcp,Grid Authentication Alt   
#define IANAport_bmc_grx 		      	6300			// tcp,BMC GRX   
#define IANAport_bmc_ctd_ldap   		6301			// tcp,"BMC CONTROL_D LDAP SERVER IANA assigned this well_formed service name as a replacement for ""bmc_ctd_ldap""."   
#define IANAport_ufmp 	      			6306			// tcp,Unified Fabric Management Protocol   
#define IANAport_scup 	      			6315			// tcp,Sensor Control Unit Protocol   
#define IANAport_scup_disc 	    		6315			// udp,Sensor Control Unit Protocol Discovery Protocol   
#define IANAport_abb_escp 	    		6316			// tcp,Ethernet Sensor Communications Protocol   
#define IANAport_nav_data_cmd   		6317			// tcp,Navtech Radar Sensor Data Command   
#define IANAport_nav_data     			6317			// udp,Navtech Radar Sensor Data   
#define IANAport_repsvc 	      		6320			// tcp,Double_Take Replication Service   
#define IANAport_emp_server1    		6321			// tcp,Empress Software Connectivity Server 1   
#define IANAport_emp_server2 	    	6322			// tcp,Empress Software Connectivity Server 2   
#define IANAport_hrd_ncs 	      		6324			// tcp,HR Device Network Configuration Service   
#define IANAport_hrd_ns_disc    		6324			// udp,HR Device Network service   
#define IANAport_dt_mgmtsvc     		6325			// tcp,Double_Take Management Service   
//#define IANAport_				          6325			// udp,Reserved   
#define IANAport_dt_vra       			6326			// tcp,Double_Take Virtual Recovery Assistant   
//#define IANAport_			      	    6326			// udp,Reserved   
#define IANAport_sflow 		      		6343			// tcp,sFlow traffic monitoring   
#define IANAport_streletz     			6344			// tcp,Argus_Spectr security and fire_prevention systems service   
//#define IANAport_				          6344			// udp,Reserved   
#define IANAport_gnutella_svc   		6346			// tcp,gnutella_svc   
#define IANAport_gnutella_rtr   		6347			// tcp,gnutella_rtr   
#define IANAport_adap 	      			6350			// tcp,App Discovery and Access Protocol   
#define IANAport_pmcs 	      			6355			// tcp,PMCS applications   
#define IANAport_metaedit_mu 	    	6360			// tcp,MetaEdit+ Multi_User   
#define IANAport_ndn 	        			6363			// udp,Named Data Networking   
//#define IANAport_			      	    6363			// tcp,Reserved   
#define IANAport_metaedit_se    		6370			// tcp,MetaEdit+ Server Administration   
#define IANAport_redis 	      			6379			// tcp,An advanced key_value cache and store   
//#define IANAport_			      	    6379			// udp,Reserved   
#define IANAport_metatude_mds   		6382			// tcp,Metatude Dialogue Server   
#define IANAport_clariion_evr01   	6389			// tcp,clariion_evr01   
#define IANAport_metaedit_ws    		6390			// tcp,MetaEdit+ WebService API   
#define IANAport_boe_cms 	      		6400			// ,Business Objects CMS contact port   
#define IANAport_boe_was 		      	6401			// ,boe_was   
#define IANAport_boe_eventsrv     	6402			// ,boe_eventsrv   
#define IANAport_boe_cachesvr   		6403			// ,boe_cachesvr   
#define IANAport_boe_filesvr    		6404			// ,Business Objects Enterprise internal server   
#define IANAport_boe_pagesvr 	    	6405			// ,Business Objects Enterprise internal server   
#define IANAport_boe_processsvr   	6406			// ,Business Objects Enterprise internal server   
#define IANAport_boe_resssvr1   		6407			// ,Business Objects Enterprise internal server   
#define IANAport_boe_resssvr2   		6408			// ,Business Objects Enterprise internal server   
#define IANAport_boe_resssvr3 	  	6409			// ,Business Objects Enterprise internal server   
#define IANAport_boe_resssvr4 	  	6410			// ,Business Objects Enterprise internal server   
#define IANAport_faxcomservice 	  	6417			// tcp,Faxcom Message Service   
#define IANAport_syserverremote   	6418			// tcp,SYserver remote commands   
//#define IANAport_				          6418			// udp,Reserved   
#define IANAport_svdrp 		      		6419			// tcp,Simple VDR Protocol   
#define IANAport_svdrp_disc     		6419			// udp,Simple VDR Protocol Discovery   
#define IANAport_nim_vdrshell   		6420			// tcp,NIM_VDRShell   
#define IANAport_nim_wan 	      		6421			// tcp,NIM_WAN   
#define IANAport_pgbouncer 	    		6432			// tcp,PgBouncer   
//#define IANAport_				          6432			// udp,Reserved   
#define IANAport_heliosd 	      		6440			// tcp,heliosd daemon   
//#define IANAport_				          6440			// udp,Reserved   
#define IANAport_tarp 	      			6442			// tcp,Transitory Application Request Protocol   
//#define IANAport_			      	    6442			// udp,Reserved   
#define IANAport_sun_sr_https   		6443			// tcp,Service Registry Default HTTPS Domain   
#define IANAport_sge_qmaster    		6444			// tcp,"Grid Engine Qmaster Service IANA assigned this well_formed service name as a replacement for ""sge_qmaster""."   
#define IANAport_sge_execd 	    		6445			// tcp,"Grid Engine Execution Service IANA assigned this well_formed service name as a replacement for ""sge_execd""."   
#define IANAport_mysql_proxy 	    	6446			// tcp,MySQL Proxy   
#define IANAport_skip_cert_recv   	6455			// tcp,SKIP Certificate Receive   
#define IANAport_skip_cert_send   	6456			// tcp,SKIP Certificate Send   
#define IANAport_ieee11073_20701   	6464			// tcp,Port assignment for medical device communication in accordance to IEEE 11073_20701   
#define IANAport_lvision_lm     		6471			// tcp,LVision License Manager   
#define IANAport_sun_sr_http    		6480			// tcp,Service Registry Default HTTP Domain   
#define IANAport_servicetags    		6481			// tcp,Service Tags   
#define IANAport_ldoms_mgmt     		6482			// tcp,Logical Domains Management Interface   
#define IANAport_SunVTS_RMI     		6483			// tcp,SunVTS RMI   
#define IANAport_sun_sr_jms     		6484			// tcp,Service Registry Default JMS Domain   
#define IANAport_sun_sr_iiop 	    	6485			// tcp,Service Registry Default IIOP Domain   
#define IANAport_sun_sr_iiops   		6486			// tcp,Service Registry Default IIOPS Domain   
#define IANAport_sun_sr_iiop_aut  	6487			// tcp,Service Registry Default IIOPAuth Domain   
#define IANAport_sun_sr_jmx     		6488			// tcp,Service Registry Default JMX Domain   
#define IANAport_sun_sr_admin   		6489			// tcp,Service Registry Default Admin Domain   
#define IANAport_boks 		      		6500			// tcp,BoKS Master   
#define IANAport_boks_servc     		6501			// tcp,"BoKS Servc IANA assigned this well_formed service name as a replacement for ""boks_servc""."   
#define IANAport_boks_servm     		6502			// tcp,"BoKS Servm IANA assigned this well_formed service name as a replacement for ""boks_servm""."   
#define IANAport_boks_clntd     		6503			// tcp,"BoKS Clntd IANA assigned this well_formed service name as a replacement for ""boks_clntd""."   
#define IANAport_badm_priv 	    		6505			// tcp,"BoKS Admin Private Port IANA assigned this well_formed service name as a replacement for ""badm_priv""."   
#define IANAport_badm_pub 	    		6506			// tcp,"BoKS Admin Public Port IANA assigned this well_formed service name as a replacement for ""badm_pub""."   
#define IANAport_bdir_priv 	    		6507			// tcp,"BoKS Dir Server, Private Port IANA assigned this well_formed service name as a replacement for ""bdir_priv""."   
#define IANAport_bdir_pub 	    		6508			// tcp,"BoKS Dir Server, Public Port IANA assigned this well_formed service name as a replacement for ""bdir_pub""."   
#define IANAport_mgcs_mfp_port  		6509			// tcp,MGCS_MFP Port   
#define IANAport_mgcs_mfp_port  		6509			// udp,MGCS_MFP Port   
#define IANAport_mcer_port 	    		6510			// tcp,MCER Port   
//#define IANAport_				          6511			// tcp,Reserved   
#define IANAport_dccp_udp     			6511			// udp,Datagram Congestion Control Protocol Encapsulation for NAT Traversal,[RFC6773]  ,
#define IANAport_netconf_tls 	    	6513			// tcp,NETCONF over TLS,[RFC7589]  ,
//#define IANAport_				          6513			// udp,Reserved   
#define IANAport_syslog_tls     		6514			// tcp,Syslog over TLS,[RFC5425]  ,
#define IANAport_elipse_rec     		6515			// tcp,Elipse RPC Protocol   
#define IANAport_lds_distrib 	    	6543			// tcp,lds_distrib   
#define IANAport_lds_dump 	    		6544			// tcp,LDS Dump Service   
#define IANAport_apc_6547 	    		6547			// tcp,APC 6547   
#define IANAport_apc_6548 	    		6548			// tcp,APC 6548   
#define IANAport_apc_6549 	    		6549			// tcp,APC 6549   
#define IANAport_fg_sysupdate   		6550			// tcp,fg_sysupdate   
#define IANAport_sum 		        		6551			// tcp,Software Update Manager   
#define IANAport_checkmk_agent  		6556			// tcp,Checkmk Monitoring Agent   
//#define IANAport_			      	    6556			// udp,Reserved   
#define IANAport_xdsxdm 	      		6558			// tcp   ,
#define IANAport_sane_port    			6566			// tcp,SANE Control Port   
//#define IANAport_				          6567			// ,Reserved   
#define IANAport_canit_store 	    	6568			// tcp,"CanIt Storage Manager IANA assigned this well_formed service name as a replacement for ""canit_store""."   
#define IANAport_rp_reputation  		6568			// udp,Roaring Penguin IP Address Reputation Collection   
#define IANAport_affiliate 	    		6579			// tcp,Affiliate   
#define IANAport_parsec_master  		6580			// tcp,Parsec Masterserver   
#define IANAport_parsec_peer    		6581			// tcp,Parsec Peer_to_Peer   
#define IANAport_parsec_game    		6582			// tcp,Parsec Gameserver   
#define IANAport_joaJewelSuite 	  	6583			// tcp,JOA Jewel Suite   
#define IANAport_mshvlm       			6600			// tcp,Microsoft Hyper_V Live Migration   
//#define IANAport_				          6600			// udp,Reserved   
#define IANAport_mstmg_sstp     		6601			// tcp,Microsoft Threat Management Gateway SSTP   
//#define IANAport_				          6601			// udp,Reserved   
#define IANAport_wsscomfrmwk 	    	6602			// tcp,Windows WSS Communication Framework   
//#define IANAport_				          6602			// udp,Reserved   
#define IANAport_odette_ftps 	    	6619			// tcp,ODETTE_FTP over TLS/SSL,[RFC5024]  ,
#define IANAport_kftp_data 	    		6620			// tcp,Kerberos V5 FTP Data   
#define IANAport_kftp 		      		6621			// tcp,Kerberos V5 FTP Control   
#define IANAport_mcftp 		      		6622			// tcp,Multicast FTP   
#define IANAport_ktelnet 	      		6623			// tcp,Kerberos V5 Telnet   
#define IANAport_datascaler_db  		6624			// tcp,DataScaler database   
//#define IANAport_				          6624			// udp,Reserved   
#define IANAport_datascaler_ctl   	6625			// tcp,DataScaler control   
//#define IANAport_			      	    6625			// udp,Reserved   
#define IANAport_wago_service   		6626			// tcp,WAGO Service and Update   
#define IANAport_nexgen 	      		6627			// tcp,Allied Electronics NeXGen   
#define IANAport_afesc_mc 	    		6628			// tcp,AFE Stock Channel M/C   
#define IANAport_nexgen_aux 	    	6629			// tcp,"Secondary, (non ANDI) multi_protocol multi_function interface to the Allied ANDI_based family of forecourt controllers"   
#define IANAport_mxodbc_connect   	6632			// tcp,eGenix mxODBC Connect   
//#define IANAport_			      	    6632			// udp,Reserved   
//#define IANAport_				          6633			// tcp,Reserved   
#define IANAport_cisco_vpath_tun  	6633			// udp,Cisco vPath Services Overlay   
#define IANAport_mpls_pm 	      		6634			// udp,MPLS Performance Measurement out_of_band response   
//#define IANAport_			      	    6634			// tcp,Reserved   
//#define IANAport_				          6635			// tcp,Reserved   
#define IANAport_mpls_udp 	    		6635			// udp,Encapsulate MPLS packets in UDP tunnels.,[RFC7510]  ,
//#define IANAport_				          6636			// tcp,Reserved   
#define IANAport_mpls_udp_dtls  		6636			// udp,Encapsulate MPLS packets in UDP tunnels with DTLS.,[RFC7510]  ,
#define IANAport_ovsdb 	      			6640			// tcp,Open vSwitch Database protocol,[RFC7047]  ,
//#define IANAport_			      	    6640			// udp,Reserved   
#define IANAport_openflow     			6653			// tcp,OpenFlow   
#define IANAport_pcs_sf_ui_man 	  	6655			// tcp,PC SOFT _ Software factory UI/manager   
//#define IANAport_			      	    6655			// udp,Reserved   
#define IANAport_emgmsg       			6656			// tcp,Emergency Message Control Service   
//#define IANAport_			      	    6656			// udp,Reserved   
//#define IANAport_			      	    6657			// tcp,Reserved   
#define IANAport_palcom_disc    		6657			// udp,PalCom Discovery   
#define IANAport_ircu 	      			6665			// tcp,IRCU   
#define IANAport_ircu_5       			6665			// tcp,IRCU   
#define IANAport_ircu_6	      			6666			// tcp,IRCU   
#define IANAport_ircu_7	      			6667			// tcp,IRCU   
#define IANAport_ircu_8	      			6668			// tcp,IRCU   
#define IANAport_ircu_9	      			6669			// tcp,IRCU   
//#define IANAport_			      	    6665_6669		// udp,Reserved   
#define IANAport_vocaltec_gold  		6670			// tcp,Vocaltec Global Online Directory   
#define IANAport_p4p_portal     		6671			// tcp,P4P Portal Service   
#define IANAport_vision_server 	  	6672			// tcp,"vision_server IANA assigned this well_formed service name as a replacement for ""vision_server""."   
#define IANAport_vision_elmd    		6673			// tcp,"vision_elmd IANA assigned this well_formed service name as a replacement for ""vision_elmd""."   
#define IANAport_vfbp 		      		6678			// tcp,Viscount Freedom Bridge Protocol   
#define IANAport_vfbp_disc 	    		6678			// udp,Viscount Freedom Bridge Discovery   
#define IANAport_osaut 		      		6679			// tcp,Osorno Automation   
#define IANAport_clever_ctrace  		6687			// tcp,CleverView for cTrace Message Service   
//#define IANAport_			      	    6687			// udp,Reserved   
#define IANAport_clever_tcpip   		6688			// tcp,CleverView for TCP/IP Message Service   
//#define IANAport_			      	    6688			// udp,Reserved   
#define IANAport_tsa 		        		6689			// tcp,Tofino Security Appliance   
#define IANAport_cleverdetect   		6690			// tcp,CLEVERDetect Message Service   
//#define IANAport_			      	    6690			// udp,Reserved   
//#define IANAport_			      	    6696			// tcp,Reserved   
#define IANAport_babel 	      			6696			// udp,Babel Routing Protocol,[RFC8966]  ,
#define IANAport_ircs_u 	      		6697			// tcp,Internet Relay Chat via TLS/SSL,[RFC7194]  ,
//#define IANAport_				          6697			// udp,Reserved   
//#define IANAport_				          6699			// tcp,Reserved   
#define IANAport_babel_dtls 	    	6699			// udp,Babel Routing Protocol over DTLS,[RFC8968]  ,
#define IANAport_kti_icad_srvr  		6701			// tcp,KTI/ICAD Nameserver   
#define IANAport_e_design_net   		6702			// tcp,e_Design network   
#define IANAport_e_design_web   		6703			// tcp,e_Design web   
//#define IANAport_				          6704			// udp,Reserved   
//#define IANAport_				          6704			// tcp,Reserved   
#define IANAport_frc_hp 	      		6704			// sctp,ForCES HP (High Priority) channel,[RFC5811]  ,
//#define IANAport_				          6705			// udp,Reserved   
//#define IANAport_				          6705			// tcp,Reserved   
#define IANAport_frc_mp 	      		6705			// sctp,ForCES MP (Medium Priority) channel,[RFC5811]  ,
//#define IANAport_			      	    6706			// udp,Reserved   
//#define IANAport_			      	    6706			// tcp,Reserved   
#define IANAport_frc_lp 	      		6706			// sctp,ForCES LP (Low priority) channel,[RFC5811]  ,
#define IANAport_ibprotocol     		6714			// tcp,Internet Backplane Protocol   
#define IANAport_fibotrader_com   	6715			// tcp,Fibotrader Communications   
#define IANAport_princity_agent   	6716			// tcp,Princity Agent   
//#define IANAport_				          6716			// udp,Reserved   
#define IANAport_bmc_perf_agent   	6767			// tcp,BMC PERFORM AGENT   
#define IANAport_bmc_perf_mgrd  		6768			// tcp,BMC PERFORM MGRD   
#define IANAport_adi_gxp_srvprt    	6769			// tcp,ADInstruments GxP Server   
#define IANAport_plysrv_http 	    	6770			// tcp,PolyServe http   
#define IANAport_plysrv_https   		6771			// tcp,PolyServe https   
#define IANAport_ntz_tracker    		6777			// tcp,netTsunami Tracker   
//#define IANAport_				          6777			// udp,Reserved   
#define IANAport_ntz_p2p_storage  	6778			// tcp,netTsunami p2p storage system   
//#define IANAport_				          6778			// udp,Reserved   
//#define IANAport_				          6784			// tcp,Reserved   
#define IANAport_bfd_lag 	      		6784			// udp,Bidirectional Forwarding Detection (BFD) on Link Aggregation Group (LAG) Interfaces,[RFC7130]  ,
#define IANAport_dgpf_exchg 	    	6785			// tcp,DGPF Individual Exchange   
#define IANAport_smc_jmx 	      		6786			// tcp,Sun Java Web Console JMX   
#define IANAport_smc_admin 	    		6787			// tcp,Sun Web Console Admin   
#define IANAport_smc_http 	    		6788			// tcp,SMC_HTTP   
#define IANAport_radg 		      		6789			// tcp,GSS_API for the Oracle Remote Administration Daemon   
//#define IANAport_				          6789			// udp,Reserved   
#define IANAport_hnmp 	      			6790			// tcp,HNMP   
#define IANAport_hnm 	        			6791			// tcp,Halcyon Network Manager   
#define IANAport_acnet 	      			6801			// tcp,ACNET Control System Protocol   
#define IANAport_pentbox_sim 	    	6817			// tcp,PenTBox Secure IM Protocol   
//#define IANAport_				          6817			// udp,Reserved   
#define IANAport_ambit_lm 	    		6831			// tcp,ambit_lm   
#define IANAport_netmo_default  		6841			// tcp,Netmo Default   
#define IANAport_netmo_http     		6842			// tcp,Netmo HTTP   
#define IANAport_iccrushmore    		6850			// tcp,ICCRUSHMORE   
#define IANAport_acctopus_cc    		6868			// tcp,Acctopus Command Channel   
#define IANAport_acctopus_st    		6868			// udp,Acctopus Status   
#define IANAport_muse 			      	6888			// tcp,MUSE   
#define IANAport_rtimeviewer    		6900			// tcp,R*TIME Viewer Data Interface   
//#define IANAport_				          6900			// udp,Reserved   
#define IANAport_jetstream 	    		6901			// tcp,Novell Jetstream messaging protocol   
//#define IANAport_				          6901			// udp,Reserved   
#define IANAport_split_ping     		6924			// tcp,Ping with RX/TX latency/loss split   
#define IANAport_ethoscan 	    		6935			// tcp,EthoScan Service   
#define IANAport_xsmsvc 	      		6936			// tcp,XenSource Management Service   
#define IANAport_bioserver    			6946			// tcp,Biometrics Server   
#define IANAport_otlp 	      			6951			// tcp,OTLP   
#define IANAport_jmact3 	      		6961			// tcp,JMACT3   
#define IANAport_jmevt2 	      		6962			// tcp,jmevt2   
#define IANAport_swismgr1     			6963			// tcp,swismgr1   
#define IANAport_swismgr2     			6964			// tcp,swismgr2   
#define IANAport_swistrap 	    		6965			// tcp,swistrap   
#define IANAport_swispol 		      	6966			// tcp,swispol   
#define IANAport_acmsoda 	      		6969			// tcp,acmsoda   
#define IANAport_conductor 	    		6970			// tcp,Conductor test coordination protocol   
//#define IANAport_				          6970			// udp,Reserved   
#define IANAport_conductor_mpx  		6970			// sctp,conductor for multiplex   
//#define IANAport_			      	    6980			// tcp,Reserved   
#define IANAport_qolyester 	    		6980			// udp,QoS_extended OLSR protocol   
#define IANAport_MobilitySrv    		6997			// tcp,Mobility XE Protocol   
#define IANAport_iatp_highpri   		6998			// tcp,IATP_highPri   
#define IANAport_iatp_normalpri   	6999			// tcp,IATP_normalPri   
#define IANAport_afs3_fileserver  	7000			// tcp,file server itself   
#define IANAport_afs3_callback 	  	7001			// tcp,callbacks to cache managers   
#define IANAport_afs3_prserver  		7002			// tcp,users & groups database   
#define IANAport_afs3_vlserver 	  	7003			// tcp,volume location database   
#define IANAport_afs3_kaserver  		7004			// tcp,AFS/Kerberos authentication service   
#define IANAport_afs3_volser 	    	7005			// tcp,volume managment server   
#define IANAport_afs3_errors    		7006			// tcp,error interpretation service   
#define IANAport_afs3_bos 	    		7007			// tcp,basic overseer process   
#define IANAport_afs3_update    		7008			// tcp,server_to_server updater   
#define IANAport_afs3_rmtsys 	    	7009			// tcp,remote cache manager service   
#define IANAport_ups_onlinet 	    	7010			// tcp,onlinet uninterruptable power supplies   
#define IANAport_talon_disc 	    	7011			// tcp,Talon Discovery Port   
#define IANAport_talon_engine   		7012			// tcp,Talon Engine   
#define IANAport_microtalon_dis   	7013			// tcp,Microtalon Discovery   
#define IANAport_microtalon_com   	7014			// tcp,Microtalon Communications   
#define IANAport_talon_webserver  	7015			// tcp,Talon Webserver   
#define IANAport_spg 			        	7016			// tcp,SPG Controls Carrier   
#define IANAport_grasp 		      		7017			// tcp,GeneRic Autonomic Signaling Protocol,[RFC8990]  ,
#define IANAport_fisa_svc     			7018			// tcp,FISA Service   
//#define IANAport_				          7018			// udp,Reserved   
#define IANAport_doceri_ctl     		7019			// tcp,doceri drawing service control   
#define IANAport_doceri_view 	    	7019			// udp,doceri drawing service screen view   
#define IANAport_dpserve 	      		7020			// tcp,DP Serve   
#define IANAport_dpserveadmin   		7021			// tcp,DP Serve Admin   
#define IANAport_ctdp 	      			7022			// tcp,CT Discovery Protocol   
#define IANAport_ct2nmcs 	      		7023			// tcp,Comtech T2 NMCS   
#define IANAport_vmsvc 	      			7024			// tcp,Vormetric service   
#define IANAport_vmsvc_2 	      		7025			// tcp,Vormetric Service II   
#define IANAport_loreji_panel   		7026			// tcp,Loreji Webhosting Panel   
//#define IANAport_			      	    7026			// udp,Reserved   
#define IANAport_op_probe     			7030			// tcp,ObjectPlanet probe   
#define IANAport_iposplanet     		7031			// tcp,IPOSPLANET retailing multi devices protocol   
//#define IANAport_				          7031			// udp,Reserved   
//#define IANAport_			      	    7040			// tcp,Reserved   
#define IANAport_quest_disc     		7040			// udp,Quest application level network service discovery   
#define IANAport_arcp 		      		7070			// tcp,ARCP   
#define IANAport_iwg1 		      		7071			// tcp,IWGADTS Aircraft Housekeeping Message   
#define IANAport_iba_cfg 	      		7072			// tcp,iba Device Configuration Protocol   
#define IANAport_iba_cfg_disc   		7072			// udp,iba Device Configuration Protocol   
#define IANAport_martalk 	      		7073			// tcp,MarTalk protocol   
//#define IANAport_				          7073			// udp,Reserved   
#define IANAport_empowerid 	    		7080			// tcp,EmpowerID Communication   
//#define IANAport_				          7088			// tcp,Reserved   
#define IANAport_zixi_transport   	7088			// udp,Zixi live video transport protocol   
#define IANAport_jdp_disc 	    		7095			// udp,Java Discovery Protocol   
//#define IANAport_				          7095			// tcp,Reserved   
#define IANAport_lazy_ptop 	    		7099			// tcp,lazy_ptop   
#define IANAport_font_service   		7100			// tcp,X Font Service   
#define IANAport_elcn 		      		7101			// tcp,Embedded Light Control Network   
//#define IANAport_				          7107			// tcp,Reserved   
#define IANAport_aes_x170     			7107			// udp,AES_X170   
#define IANAport_rothaga 	      		7117			// tcp,Encrypted chat and file transfer service   
//#define IANAport_			      	    7117			// udp,Reserved   
#define IANAport_virprot_lm     		7121			// tcp,Virtual Prototypes License Manager   
#define IANAport_snif 		      		7123			// tcp,End_to_end TLS Relay Control Connection   
//#define IANAport_				          7123			// udp,Reserved   
#define IANAport_scenidm 	      		7128			// tcp,intelligent data manager   
#define IANAport_scenccs 	      		7129			// tcp,Catalog Content Search   
#define IANAport_cabsm_comm     		7161			// tcp,CA BSM Comm   
#define IANAport_caistoragemgr 	  	7162			// tcp,CA Storage Manager   
#define IANAport_cacsambroker   		7163			// tcp,CA Connection Broker   
#define IANAport_fsr 		        		7164			// tcp,File System Repository Agent   
#define IANAport_doc_server     		7165			// tcp,Document WCF Server   
#define IANAport_aruba_server     	7166			// tcp,Aruba eDiscovery Server   
#define IANAport_casrmagent     		7167			// tcp,CA SRM Agent   
//#define IANAport_				          7167			// udp,Reserved   
#define IANAport_cnckadserver   		7168			// tcp,cncKadServer DB & Inventory Services   
//#define IANAport_				          7168			// udp,Reserved   
#define IANAport_ccag_pib 	    		7169			// tcp,Consequor Consulting Process Integration Bridge   
#define IANAport_nsrp 		      		7170			// tcp,Adaptive Name/Service Resolution   
#define IANAport_drm_production   	7171			// tcp,Discovery and Retention Mgt Production   
#define IANAport_metalbend 	    		7172			// tcp,Port used for MetalBend programmable interface   
//#define IANAport_				          7172			// udp,Reserved   
#define IANAport_zsecure 		      	7173			// tcp,zSecure Server   
//#define IANAport_				          7173			// udp,Reserved   
#define IANAport_clutild 		      	7174			// tcp,Clutild   
#define IANAport_janus_disc     		7181			// udp,Janus Guidewire Enterprise Discovery Service Bus   
//#define IANAport_				          7181			// tcp,Reserved   
#define IANAport_fodms 	      			7200			// tcp,FODMS FLIP   
#define IANAport_dlip 	      			7201			// tcp,DLIP   
#define IANAport_pon_ictp     			7202			// tcp,"Inter_Channel Termination Protocol (ICTP) for multi_wavelength PON
    												                  // (Passive Optical Network) systems","[TR_352][Inter_Channel_Termination protocol (ICTP) is a peer_to_peer protocol with
												                    	// a binary message format that is used by a set of optical line terminal (OLT) channel terminations (CT) comprising a 40_Gigabit_capable next_generation passive optical network (NG_PON2) system to
													                    // exchange channel profile configuration and status information and to coordinate the operation of tunable optical network units (ONUs) in a multi_wavelength channel environment.]"  ,
//#define IANAport_				          7202			// udp,Reserved   
#define IANAport_PS_Server 			    7215			// tcp,Communication ports for PaperStream Server services   
//#define IANAport_				          7215			// udp,Reserved   
#define IANAport_PS_Capture_Pro 	  7216			// tcp,PaperStream Capture Professional   
//#define IANAport_				          7216			// udp,Reserved   
#define IANAport_ramp 				      7227			// tcp,Registry A & M Protocol   
#define IANAport_citrixupp 		    	7228			// tcp,Citrix Universal Printing Port   
//#define IANAport_				          7228			// udp,Reserved   
#define IANAport_citrixuppg 	    	7229			// tcp,Citrix UPP Gateway   
//#define IANAport_				          7229			// udp,Reserved   
#define IANAport_asa_gateways   		7234			// tcp,Traffic forwarding for Okta cloud infra   
//#define IANAport_				          7234			// udp,Reserved   
#define IANAport_aspcoordination  	7235			// udp,ASP Coordination Protocol   
//#define IANAport_				          7235			// tcp,Reserved   
#define IANAport_display 			      7236			// tcp,Wi_Fi Alliance Wi_Fi Display Protocol   
//#define IANAport_				          7236			// udp,Reserved   
#define IANAport_pads 				      7237			// tcp,PADS (Public Area Display System) Server   
//#define IANAport_				          7237			// udp,Reserved   
#define IANAport_frc_hicp 			    7244			// tcp,FrontRow Calypso Human Interface Control Protocol   
#define IANAport_frc_hicp_disc 		  7244			// udp,FrontRow Calypso Human Interface Control Protocol   
#define IANAport_cnap 				      7262			// tcp,Calypso Network Access Protocol   
#define IANAport_watchme_7272 		  7272			// tcp,WatchMe Monitoring 7272   
#define IANAport_oma_rlp 		      	7273			// tcp,OMA Roaming Location   
#define IANAport_oma_rlp_s 	    		7274			// tcp,OMA Roaming Location SEC   
#define IANAport_oma_ulp 		      	7275			// tcp,OMA UserPlane Location   
#define IANAport_oma_ilp 		      	7276			// tcp,OMA Internal Location Protocol   
#define IANAport_oma_ilp_s 	    		7277			// tcp,OMA Internal Location Secure Protocol   
#define IANAport_oma_dcdocbs    		7278			// tcp,OMA Dynamic Content Delivery over CBS   
#define IANAport_ctxlic 		      	7279			// tcp,Citrix Licensing   
#define IANAport_itactionserver1  	7280			// tcp,ITACTIONSERVER 1   
#define IANAport_itactionserver2   	7281			// tcp,ITACTIONSERVER 2   
#define IANAport_mzca_action    		7282			// tcp,eventACTION/ussACTION (MZCA) server   
#define IANAport_mzca_alert     		7282			// udp,eventACTION/ussACTION (MZCA) alert   
#define IANAport_genstat 	      		7283			// tcp,General Statistics Rendezvous Protocol   
//#define IANAport_				          7283			// udp,Reserved   
#define IANAport_swx 		        		7300			// ,The Swiss Exchange for port range 7300_7359
#define IANAport_swx_00       			7300			// ,The Swiss Exchange   
#define IANAport_swx_01 	      		7301			// ,The Swiss Exchange   
#define IANAport_swx_02       			7302			// ,The Swiss Exchange   
#define IANAport_swx_03       			7303			// ,The Swiss Exchange   
#define IANAport_swx_04 	      		7304			// ,The Swiss Exchange   
#define IANAport_swx_05 	      		7305			// ,The Swiss Exchange   
#define IANAport_swx_06 	      		7306			// ,The Swiss Exchange   
#define IANAport_swx_07 	      		7307			// ,The Swiss Exchange   
#define IANAport_swx_08 	      		7308			// ,The Swiss Exchange   
#define IANAport_swx_09 	      		7309			// ,The Swiss Exchange   
#define IANAport_swx_10 	      		7310			// ,The Swiss Exchange   
#define IANAport_swx_11 	      		7311			// ,The Swiss Exchange   
#define IANAport_swx_12 	      		7312			// ,The Swiss Exchange   
#define IANAport_swx_13 	      		7313			// ,The Swiss Exchange   
#define IANAport_swx_14       			7314			// ,The Swiss Exchange   
#define IANAport_swx_15 	      		7315			// ,The Swiss Exchange   
#define IANAport_swx_16 	      		7316			// ,The Swiss Exchange   
#define IANAport_swx_17 	      		7317			// ,The Swiss Exchange   
#define IANAport_swx_18 	      		7318			// ,The Swiss Exchange   
#define IANAport_swx_19 	      		7319			// ,The Swiss Exchange   
#define IANAport_swx_20 	      		7320			// ,The Swiss Exchange   
#define IANAport_swx_21 	      		7321			// ,The Swiss Exchange   
#define IANAport_swx_22 	      		7322			// ,The Swiss Exchange   
#define IANAport_swx_23 	      		7323			// ,The Swiss Exchange   
#define IANAport_swx_24 	      		7324			// ,The Swiss Exchange   
#define IANAport_swx_25       			7325			// ,The Swiss Exchange   
#define IANAport_swx_26       			7326			// ,The Swiss Exchange   
#define IANAport_swx_27       			7327			// ,The Swiss Exchange   
#define IANAport_swx_28       			7328			// ,The Swiss Exchange   
#define IANAport_swx_29       			7329			// ,The Swiss Exchange   
#define IANAport_swx_30       			7330			// ,The Swiss Exchange   
#define IANAport_swx_31       			7331			// ,The Swiss Exchange   
#define IANAport_swx_32       			7332			// ,The Swiss Exchange   
#define IANAport_swx_33       			7333			// ,The Swiss Exchange   
#define IANAport_swx_34       			7334			// ,The Swiss Exchange   
#define IANAport_swx_35       			7335			// ,The Swiss Exchange   
#define IANAport_swx_36       			7336			// ,The Swiss Exchange   
#define IANAport_swx_37 	      		7337			// ,The Swiss Exchange   
#define IANAport_swx_38       			7338			// ,The Swiss Exchange   
#define IANAport_swx_39 	      		7339			// ,The Swiss Exchange   
#define IANAport_swx_40 	      		7340			// ,The Swiss Exchange   
#define IANAport_swx_41       			7341			// ,The Swiss Exchange   
#define IANAport_swx_42 	      		7342			// ,The Swiss Exchange   
#define IANAport_swx_43 	      		7343			// ,The Swiss Exchange   
#define IANAport_swx_44       			7344			// ,The Swiss Exchange   
#define IANAport_swx_45 	      		7345			// ,The Swiss Exchange   
#define IANAport_swx_46 	      		7346			// ,The Swiss Exchange   
#define IANAport_swx_47 	      		7347			// ,The Swiss Exchange   
#define IANAport_swx_48 	      		7348			// ,The Swiss Exchange   
#define IANAport_swx_49       			7349			// ,The Swiss Exchange   
#define IANAport_swx_50       			7350			// ,The Swiss Exchange   
#define IANAport_swx_51       			7351			// ,The Swiss Exchange   
#define IANAport_swx_52       			7352			// ,The Swiss Exchange   
#define IANAport_swx_53       			7353			// ,The Swiss Exchange   
#define IANAport_swx_54       			7354			// ,The Swiss Exchange   
#define IANAport_swx_55       			7355			// ,The Swiss Exchange   
#define IANAport_swx_56 	      		7356			// ,The Swiss Exchange   
#define IANAport_swx_57 	      		7357			// ,The Swiss Exchange   
#define IANAport_swx_58 	      		7358			// ,The Swiss Exchange   
#define IANAport_swx_59 		      	7359			// ,The Swiss Exchange   
#define IANAport_lcm_server 	    	7365			// tcp,LifeKeeper Communications   
#define IANAport_mindfilesys 	    	7391			// tcp,mind_file system server   
#define IANAport_mrssrendezvous   	7392			// tcp,mrss_rendezvous server   
#define IANAport_nfoldman     			7393			// tcp,nFoldMan Remote Publish   
#define IANAport_fse 		        		7394			// tcp,File system export of backup images   
#define IANAport_winqedit     			7395			// tcp,winqedit   
#define IANAport_hexarc 	      		7397			// tcp,Hexarc Command Language   
#define IANAport_rtps_discovery   	7400			// tcp,RTPS Discovery   
#define IANAport_rtps_dd_ut       	7401			// tcp,RTPS Data_Distribution User_Traffic   
#define IANAport_rtps_dd_mt     		7402			// tcp,RTPS Data_Distribution Meta_Traffic   
#define IANAport_ionixnetmon 	    	7410			// tcp,Ionix Network Monitor   
#define IANAport_daqstream 		    	7411			// tcp,Streaming of measurement data   
//#define IANAport_				          7420			// tcp,Reserved   
#define IANAport_ipluminary     		7420			// udp,Multichannel real_time lighting control   
#define IANAport_mtportmon 	    		7421			// tcp,Matisse Port Monitor   
#define IANAport_pmdmgr 	      		7426			// tcp,OpenView DM Postmaster Manager   
#define IANAport_oveadmgr 	    		7427			// tcp,OpenView DM Event Agent Manager   
#define IANAport_ovladmgr     			7428			// tcp,OpenView DM Log Agent Manager   
#define IANAport_opi_sock 	    		7429			// tcp,OpenView DM rqt communication   
#define IANAport_xmpv7 			      	7430			// tcp,OpenView DM xmpv7 api pipe   
#define IANAport_pmd 			        	7431			// tcp,OpenView DM ovc/xmpv3 api pipe   
#define IANAport_faximum 	      		7437			// tcp,Faximum   
#define IANAport_oracleas_https   	7443			// tcp,Oracle Application Server HTTPS   
#define IANAport_sttunnel     			7471			// tcp,Stateless Transport Tunneling Protocol   
//#define IANAport_				          7471			// udp,Reserved   
#define IANAport_rise 	      			7473			// tcp,Rise: The Vieneo Province   
#define IANAport_neo4j 		      		7474			// tcp,Neo4j Graph Database   
//#define IANAport_			      	    7474			// udp,Reserved   
#define IANAport_openit 	      		7478			// tcp,IT Asset Management   
//#define IANAport_				          7478			// udp,Reserved   
#define IANAport_telops_lmd     		7491			// tcp,telops_lmd   
#define IANAport_silhouette     		7500			// tcp,Silhouette User   
#define IANAport_ovbus 		      		7501			// tcp,HP OpenView Bus Daemon   
#define IANAport_adcp 	      			7508			// tcp,Automation Device Configuration Protocol   
//#define IANAport_			      	    7508			// udp,Reserved   
#define IANAport_acplt 	      			7509			// tcp,ACPLT _ process automation service   
//#define IANAport_			      	    7509			// udp,Reserved   
#define IANAport_ovhpas       			7510			// tcp,HP OpenView Application Server   
#define IANAport_pafec_lm     			7511			// tcp,pafec_lm   
#define IANAport_saratoga 	    		7542			// tcp,Saratoga Transfer Protocol   
#define IANAport_atul 		      		7543			// tcp,atul server   
#define IANAport_nta_ds 	      		7544			// tcp,FlowAnalyzer DisplayServer   
#define IANAport_nta_us 	      		7545			// tcp,FlowAnalyzer UtilityServer   
#define IANAport_cfs 	        			7546			// tcp,Cisco Fabric service   
#define IANAport_cwmp 		      		7547			// tcp,Broadband Forum CWMP   
#define IANAport_tidp 		      		7548			// tcp,Threat Information Distribution Protocol   
#define IANAport_nls_tl 	      		7549			// tcp,Network Layer Signaling Transport Layer   
//#define IANAport_				          7550			// tcp,Reserved   
#define IANAport_cloudsignaling   	7550			// udp,Cloud Signaling Service   
#define IANAport_controlone_con   	7551			// tcp,ControlONE Console signaling   
//#define IANAport_			      	    7551			// udp,Reserved   
#define IANAport_sncp 	      			7560			// tcp,Sniffer Command Protocol   
#define IANAport_cfw 			        	7563			// tcp,Control Framework,[RFC6230]  ,
//#define IANAport_				          7563			// udp,Reserved   
#define IANAport_vsi_omega 	    		7566			// tcp,VSI Omega   
#define IANAport_dell_eql_asm   		7569			// tcp,Dell EqualLogic Host Group Management   
//#define IANAport_				          7569			// udp,Reserved   
#define IANAport_aries_kfinder  		7570			// tcp,Aries Kfinder   
#define IANAport_coherence 		    	7574			// tcp,Oracle Coherence Cluster Service   
#define IANAport_coherence_disc    	7574			// udp,Oracle Coherence Cluster discovery service   
#define IANAport_sun_lm 	      		7588			// tcp,Sun License Manager   
#define IANAport_mipi_debug     		7606			// tcp,MIPI Alliance Debug   
#define IANAport_indi 			      	7624			// tcp,Instrument Neutral Distributed Interface   
#define IANAport_simco 			      	7626			// tcp,SImple Middlebox COnfiguration (SIMCO) Server,[RFC4540]  ,
//#define IANAport_				          7626			// udp,De_registered   
#define IANAport_simco 		      		7626			// sctp,SImple Middlebox COnfiguration (SIMCO)   
#define IANAport_soap_http    			7627			// tcp,SOAP Service Port   
#define IANAport_zen_pawn 	    		7628			// tcp,Primary Agent Work Notification   
#define IANAport_xdas 		      		7629			// tcp,OpenXDAS Wire Protocol   
#define IANAport_hawk 		      		7630			// tcp,HA Web Konsole   
//#define IANAport_				          7630			// udp,Reserved   
#define IANAport_tesla_sys_msg  		7631			// tcp,TESLA System Messaging   
//#define IANAport_				          7631			// udp,Reserved   
#define IANAport_pmdfmgt      			7633			// tcp,PMDF Management   
#define IANAport_cuseeme 	      		7648			// tcp,bonjour_cuseeme   
#define IANAport_rome 		      		7663			// tcp,Proprietary immutable distributed data storage   
#define IANAport_imqstomp     			7672			// tcp,iMQ STOMP Server   
//#define IANAport_				          7672			// udp,Reserved   
#define IANAport_imqstomps 	    		7673			// tcp,iMQ STOMP Server over SSL   
//#define IANAport_				          7673			// udp,Reserved   
#define IANAport_imqtunnels       	7674			// tcp,iMQ SSL tunnel   
#define IANAport_imqtunnel 		    	7675			// tcp,iMQ Tunnel   
#define IANAport_imqbrokerd 	    	7676			// tcp,iMQ Broker Rendezvous   
#define IANAport_sun_user_https   	7677			// tcp,Sun App Server _ HTTPS   
#define IANAport_ms_do 		      		7680			// tcp,Microsoft Delivery Optimization Peer_to_Peer   
#define IANAport_dmt 			        	7683			// tcp,Cleondris DMT   
//#define IANAport_			      	    7683			// udp,Reserved   
#define IANAport_bolt 		      		7687			// tcp,Bolt database connection   
//#define IANAport_				          7687			// udp,Reserved   
#define IANAport_collaber     			7689			// tcp,Collaber Network Service   
#define IANAport_sovd 		      		7690			// tcp,Service_Oriented Vehicle Diagnostics   
//#define IANAport_			      	    7690			// udp,Reserved   
#define IANAport_klio 	      			7697			// tcp,KLIO communications   
#define IANAport_em7_secom 	    		7700			// tcp,EM7 Secure Communications   
//#define IANAport_				          7700			// udp,Reserved   
//#define IANAport_				          7701			// tcp,Reserved   
//#define IANAport_				          7701			// udp,Reserved   
#define IANAport_nfapi 		      		7701			// sctp,SCF nFAPI defining MAC/PHY split   
#define IANAport_sync_em7     			7707			// tcp,EM7 Dynamic Updates   
#define IANAport_scinet 	      		7708			// tcp,scientia.net   
#define IANAport_medimageportal   	7720			// tcp,MedImage Portal   
#define IANAport_nsdeepfreezectl  	7724			// tcp,Novell Snap_in Deep Freeze Control   
#define IANAport_nitrogen 	    		7725			// tcp,Nitrogen Service   
#define IANAport_freezexservice   	7726			// tcp,FreezeX Console Service   
#define IANAport_trident_data   		7727			// tcp,Trident Systems Data   
#define IANAport_osvr 		      		7728			// tcp,Open_Source Virtual Reality   
#define IANAport_smip 		      		7734			// tcp,Smith Protocol over IP   
#define IANAport_aiagent 	      		7738			// tcp,HP Enterprise Discovery Agent   
#define IANAport_scriptview     		7741			// tcp,ScriptView Network   
#define IANAport_msss 		      		7742			// tcp,Mugginsoft Script Server Service   
//#define IANAport_		      		    7742			// udp,Reserved   
#define IANAport_sstp_1       			7743			// tcp,Sakura Script Transfer Protocol   
#define IANAport_raqmon_pdu     		7744			// tcp,RAQMON PDU,[RFC4712]  ,
#define IANAport_prgp 		      		7747			// tcp,Put/Run/Get Protocol   
#define IANAport_inetfs 	      		7775			// tcp,A File System using TLS over a wide area network   
//#define IANAport_				          7775			// udp,Reserved   
#define IANAport_cbt 		        		7777			// tcp,cbt   
#define IANAport_interwise 	    		7778			// tcp,Interwise   
#define IANAport_vstat 		        	7779			// tcp,VSTAT   
#define IANAport_accu_lmgr    			7781			// tcp,accu_lmgr   
#define IANAport_s_bfd 		      		7784			// udp,Seamless Bidirectional Forwarding Detection (S_BFD),[RFC7881]  ,
//#define IANAport_				          7784			// tcp,Reserved   
#define IANAport_minivend 	    		7786			// tcp,MINIVEND   
#define IANAport_popup_reminders  	7787			// tcp,Popup Reminders Receive   
#define IANAport_office_tools   		7789			// tcp,Office Tools Pro Receive   
#define IANAport_q3ade 		      		7794			// tcp,Q3ADE Cluster Service   
#define IANAport_pnet_conn 	    		7797			// tcp,Propel Connector port   
#define IANAport_pnet_enc     			7798			// tcp,Propel Encoder port   
#define IANAport_altbsdp 	      		7799			// tcp,Alternate BSDP Service   
#define IANAport_asr 		        		7800			// tcp,Apple Software Restore   
#define IANAport_ssp_client     		7801			// tcp,Secure Server Protocol _ client   
#define IANAport_vns_tp 	      		7802			// udp,Virtualized Network Services Tunnel Protocol   
//#define IANAport_			      	    7802			// tcp,Reserved   
#define IANAport_rbt_wanopt     		7810			// tcp,Riverbed WAN Optimization Protocol   
#define IANAport_apc_7845 	    		7845			// tcp,APC 7845   
#define IANAport_apc_7846     			7846			// tcp,APC 7846   
#define IANAport_csoauth 	      		7847			// tcp,A product key authentication protocol made by CSO   
//#define IANAport_				          7847			// udp,Reserved   
#define IANAport_mobileanalyzer   	7869			// tcp,MobileAnalyzer& MobileMonitor   
//#define IANAport_		      		    7869			// udp,Reserved   
#define IANAport_rbt_smc      			7870			// tcp,Riverbed Steelhead Mobile Service   
//#define IANAport_			      	    7870			// udp,Reserved   
#define IANAport_mdm 		        		7871			// tcp,Mobile Device Management   
//#define IANAport_			      	    7871			// udp,Reserved   
//#define IANAport_			      	    7872			// tcp,Reserved   
#define IANAport_mipv6tls     			7872			// udp,TLS_based Mobile IPv6 Security,[RFC6618]  ,
#define IANAport_owms 	  	    		7878			// tcp,Opswise Message Service   
//#define IANAport_			      	    7878			// udp,Reserved   
#define IANAport_pss 		        		7880			// tcp,Pearson   
#define IANAport_ubroker 	      		7887			// tcp,Universal Broker   
#define IANAport_mevent 	      		7900			// tcp,Multicast Event   
#define IANAport_tnos_sp 	      		7901			// tcp,TNOS Service Protocol   
#define IANAport_tnos_dp 	      		7902			// tcp,TNOS shell Protocol   
#define IANAport_tnos_dps       		7903			// tcp,TNOS Secure DiaguardProtocol   
#define IANAport_qo_secure 	    		7913			// tcp,QuickObjects secure port   
#define IANAport_t2_drm 	      		7932			// tcp,Tier 2 Data Resource Manager   
#define IANAport_t2_brm 	      		7933			// tcp,Tier 2 Business Rules Manager   
#define IANAport_generalsync    		7962			// tcp,"Encrypted, extendable, general_purpose synchronization protocol"   
#define IANAport_supercell 	    		7967			// tcp,Supercell   
#define IANAport_micromuse_ncps   	7979			// tcp,Micromuse_ncps   
#define IANAport_quest_vista 	    	7980			// tcp,Quest Vista   
#define IANAport_sossd_collect  		7981			// tcp,Spotlight on SQL Server Desktop Collect   
//#define IANAport_				          7981			// udp,Reserved   
#define IANAport_sossd_agent    		7982			// tcp,Spotlight on SQL Server Desktop Agent   
#define IANAport_sossd_disc     		7982			// udp,Spotlight on SQL Server Desktop Agent Discovery   
#define IANAport_pushns 	      		7997			// tcp,PUSH Notification Service   
//#define IANAport_			      	    7997			// udp,Reserved   
//#define IANAport_			      	    7998			// tcp,Reserved   
#define IANAport_usicontentpush   	7998			// udp,USI Content Push Service   
#define IANAport_irdmi2       			7999			// tcp,iRDMI2   
#define IANAport_irdmi 	      			8000			// tcp,iRDMI   
#define IANAport_vcom_tunnel    		8001			// tcp,VCOM Tunnel   
#define IANAport_teradataordbms   	8002			// tcp,Teradata ORDBMS   
#define IANAport_mcreport 	    		8003			// tcp,Mulberry Connect Reporting Service   
#define IANAport_p2pevolvenet   		8004			// tcp,Opensource Evolv Enterprise Platform P2P Network Node Connection Protocol   
//#define IANAport_			      	    8004			// udp,Reserved   
#define IANAport_mxi 			        	8005			// tcp,MXI Generation II for z/OS   
#define IANAport_wpl_analytics  		8006			// tcp,World Programming analytics   
#define IANAport_wpl_disc     			8006			// udp,World Programming analytics discovery   
#define IANAport_warppipe 	    		8007			// tcp,I/O oriented cluster computing software   
#define IANAport_http_alt_2	    		8008			// tcp,HTTP Alternate - Note amended
#define IANAport_nvme_disc 	    		8009			// tcp,NVMe over Fabrics Discovery Service   
//#define IANAport_				          8009			// udp,Reserved   
//#define IANAport_			      	    8010			// ,Reserved   
#define IANAport_cfg_cloud    			8015			// tcp,Configuration Cloud Service   
//#define IANAport_			      	    8015			// udp,Reserved   
#define IANAport_ads_s 	      			8016			// tcp,Beckhoff Automation Device Specification   
//#define IANAport_			      	    8016			// udp,Reserved   
//#define IANAport_			      	    8017			// tcp,Reserved   
#define IANAport_cisco_cloudsec   	8017			// udp,Cisco Cloudsec Dataplane Port Number   
//#define IANAport_qbdb       			8019			// tcp,QB DB Dynamic Port   
//#define IANAport_qbdb 	      		8019			// udp,QB DB Dynamic Port   
#define IANAport_intu_ec_svcdisc  	8020			// tcp,Intuit Entitlement Service and Discovery   
#define IANAport_intu_ec_client   	8021			// tcp,Intuit Entitlement Client   
#define IANAport_oa_system 	    		8022			// tcp,oa_system   
#define IANAport_arca_api     			8023			// tcp,ARCATrust vault API   
#define IANAport_ca_audit_da    		8025			// tcp,CA Audit Distribution Agent   
#define IANAport_ca_audit_ds 	    	8026			// tcp,CA Audit Distribution Server   
#define IANAport_papachi_p2p_srv  	8027			// tcp,peer tracker and data relay service   
#define IANAport_pro_ed 	      		8032			// tcp,ProEd   
#define IANAport_mindprint 	    		8033			// tcp,MindPrint   
#define IANAport_vantronix_mgmt   	8034			// tcp,.vantronix Management   
#define IANAport_ampify 	      		8040			// tcp,Ampify Messaging Protocol   
#define IANAport_enguity_xccetp    	8041			// tcp,Xcorpeon ASIC Carrier Ethernet Transport   
#define IANAport_fs_agent     			8042			// tcp,FireScope Agent   
//#define IANAport_			      	    8042			// udp,Reserved   
#define IANAport_fs_server    			8043			// tcp,FireScope Server   
//#define IANAport_			      	    8043			// udp,Reserved   
#define IANAport_fs_mgmt      			8044			// tcp,FireScope Management Interface   
//#define IANAport_			      	    8044			// udp,Reserved   
#define IANAport_rocrail      			8051			// tcp,Rocrail Client Service   
//#define IANAport_			      	    8051			// udp,Reserved   
#define IANAport_senomix01    			8052			// tcp,Senomix Timesheets Server   
#define IANAport_senomix02 	    		8053			// tcp,Senomix Timesheets Client [1 year assignment]   
#define IANAport_senomix03 	    		8054			// tcp,Senomix Timesheets Server [1 year assignment]   
#define IANAport_senomix04    			8055			// tcp,Senomix Timesheets Server [1 year assignment]   
#define IANAport_senomix05 	    		8056			// tcp,Senomix Timesheets Server [1 year assignment]   
#define IANAport_senomix06 	    		8057			// tcp,Senomix Timesheets Client [1 year assignment]   
#define IANAport_senomix07 	    		8058			// tcp,Senomix Timesheets Client [1 year assignment]   
#define IANAport_senomix08 	    		8059			// tcp,Senomix Timesheets Client [1 year assignment]   
//#define IANAport_				          8060			// tcp,Reserved   
#define IANAport_aero 		      		8060			// udp,Asymmetric Extended Route Optimization (AERO),[RFC6706]  ,
#define IANAport_toad_bi_appsrvr  	8066			// tcp,Toad BI Application Server   
//#define IANAport_				          8066			// udp,Reserved   
#define IANAport_infi_async     		8067			// tcp,Infinidat async replication   
//#define IANAport_				          8067			// udp,Reserved   
#define IANAport_ucs_isc 	      		8070			// tcp,Oracle Unified Communication Suite's Indexed Search Converter   
//#define IANAport_				          8070			// udp,Reserved   
#define IANAport_gadugadu     			8074			// tcp,Gadu_Gadu   
#define IANAport_mles 	      			8077			// tcp,Mles is a client_server data distribution protocol targeted to serve as a lightweight and reliable distributed publish/subscribe database service.   
//#define IANAport_				          8077			// udp,Reserved   
#define IANAport_http_alt 	    		8080			// tcp,HTTP Alternate (see port 80)   
#define IANAport_sunproxyadmin 	  	8081			// tcp,Sun Proxy Admin Service   
#define IANAport_us_cli 	      		8082			// tcp,Utilistor (Client)   
#define IANAport_us_srv 	      		8083			// tcp,Utilistor (Server)   
#define IANAport_websnp 	      		8084			// tcp,Snarl Network Protocol over HTTP   
//#define IANAport_			            8084			// udp,Reserved   
#define IANAport_d_s_n 		      		8086			// tcp,Distributed SCADA Networking Rendezvous Port   
#define IANAport_simplifymedia 	  	8087			// tcp,Simplify Media SPP Protocol   
#define IANAport_radan_http     		8088			// tcp,Radan HTTP   
#define IANAport_opsmessaging   		8090			// tcp,Vehicle to station messaging   
//#define IANAport_				          8090			// udp,Reserved   
#define IANAport_jamlink      			8091			// tcp,Jam Link Framework   
//#define IANAport_				          8091			// udp,Reserved   
#define IANAport_sac 			        	8097			// tcp,SAC Port Id   
#define IANAport_xprint_server  		8100			// tcp,Xprint Server   
#define IANAport_ldoms_migr     		8101			// tcp,Logical Domains Migration   
//#define IANAport_				          8101			// udp,Reserved   
#define IANAport_kz_migr 	      		8102			// tcp,Oracle Kernel zones migration server   
//#define IANAport_				          8102			// udp,Reserved   
//#define IANAport_				          8111			// tcp,Reserved   
#define IANAport_skynetflow     		8111			// udp,Skynetflow network services   
#define IANAport_mtl8000_matrix   	8115			// tcp,MTL8000 Matrix   
#define IANAport_cp_cluster     		8116			// tcp,Check Point Clustering   
#define IANAport_purityrpc    			8117			// tcp,Purity replication clustering and remote management   
//#define IANAport_				          8117			// udp,Reserved   
#define IANAport_privoxy 	      		8118			// tcp,Privoxy HTTP proxy   
#define IANAport_apollo_data 	    	8121			// tcp,Apollo Data Port   
#define IANAport_apollo_admin   		8122			// tcp,Apollo Admin Port   
#define IANAport_paycash_online   	8128			// tcp,PayCash Online Protocol   
#define IANAport_paycash_wbp    		8129			// tcp,PayCash Wallet_Browser   
#define IANAport_indigo_vrmi 	    	8130			// tcp,INDIGO_VRMI   
#define IANAport_indigo_vbcp    		8131			// tcp,INDIGO_VBCP   
#define IANAport_dbabble 	      		8132			// tcp,dbabble   
#define IANAport_puppet       			8140			// tcp,The Puppet master service   
//define IANAport_			        		8140			// udp,Reserved   
#define IANAport_isdd 	      			8148			// tcp,i_SDD file transfer   
//#define IANAport_			      	    8149			// tcp,Reserved   
#define IANAport_eor_game 	    		8149			// udp,Edge of Reality game data   
#define IANAport_quantastor     		8153			// tcp,QuantaStor Management Interface   
//#define IANAport_				          8153			// udp,Reserved   
#define IANAport_patrol 	      		8160			// tcp,Patrol   
#define IANAport_patrol_snmp    		8161			// tcp,Patrol SNMP   
#define IANAport_lpar2rrd 	    		8162			// tcp,LPAR2RRD client server communication   
//#define IANAport_				          8162			// udp,Reserved   
#define IANAport_intermapper    		8181			// tcp,Intermapper network management system   
//#define IANAport_				          8181			// udp,Reserved   
#define IANAport_vmware_fdm     		8182			// tcp,VMware Fault Domain Manager   
#define IANAport_proremote 	    		8183			// tcp,ProRemote   
//#define IANAport_			      	    8183			// udp,Reserved   
#define IANAport_itach 		      		8184			// tcp,Remote iTach Connection   
#define IANAport_gcp_rphy     			8190			// tcp,Generic control plane for RPHY   
//#define IANAport_				          8190			// udp,Reserved   
#define IANAport_limnerpressure   	8191			// tcp,Limner Pressure   
//#define IANAport_				          8191			// udp,Reserved   
#define IANAport_spytechphone   		8192			// tcp,SpyTech Phone Service   
#define IANAport_blp1 		      		8194			// tcp,Bloomberg data API   
#define IANAport_blp2 		      		8195			// tcp,Bloomberg feed   
#define IANAport_vvr_data 	    		8199			// tcp,VVR DATA   
#define IANAport_trivnet1 	    		8200			// tcp,TRIVNET   
#define IANAport_trivnet2 	    		8201			// tcp,TRIVNET   
//#define IANAport_				          8202			// tcp,Reserved   
#define IANAport_aesop 		      		8202			// udp,Audio+Ethernet Standard Open Protocol   
#define IANAport_lm_perfworks     	8204			// tcp,LM Perfworks   
#define IANAport_lm_instmgr     		8205			// tcp,LM Instmgr   
#define IANAport_lm_dta 	      		8206			// tcp,LM Dta   
#define IANAport_lm_sserver 	    	8207			// tcp,LM SServer   
#define IANAport_lm_webwatcher  		8208			// tcp,LM Webwatcher   
//#define IANAport_			      	    8211			// tcp,Reserved   
#define IANAport_aruba_papi     		8211			// udp,Aruba Networks AP management   
#define IANAport_rexecj       			8230			// tcp,RexecJ Server   
//#define IANAport_				          8231			// tcp,Reserved   
#define IANAport_hncp_udp_port 	  	8231			// udp,HNCP,[RFC7788]  ,
//#define IANAport_				          8232			// tcp,Reserved   
#define IANAport_hncp_dtls_port   	8232			// udp,HNCP over DTLS,[RFC7788]  ,
#define IANAport_synapse_nhttps   	8243			// tcp,Synapse Non Blocking HTTPS   
//#define IANAport_			      	    8266			// tcp,Reserved   
#define IANAport_espeasy_p2p    		8266			// udp,ESPeasy peer_2_peer communication   
#define IANAport_robot_remote   		8270			// tcp,Robot Framework Remote Library Interface   
//#define IANAport_				          8270			// udp,Reserved   
#define IANAport_ms_mcc       			8276			// tcp,Microsoft Connected Cache   
#define IANAport_synapse_nhttp  		8280			// tcp,Synapse Non Blocking HTTP   
#define IANAport_libelle 	      		8282			// tcp,Libelle EnterpriseBus   
#define IANAport_libelle_disc   		8282			// udp,Libelle EnterpriseBus discovery   
//#define IANAport_		      		    8282			// sctp,Reserved   
//#define IANAport_		      		    8282			// dccp,Reserved   
#define IANAport_blp3 	      			8292			// tcp,Bloomberg professional   
#define IANAport_hiperscan_id   		8293			// tcp,Hiperscan Identification Service   
//#define IANAport_			      	    8293			// udp,Reserved   
#define IANAport_blp4 	      			8294			// tcp,Bloomberg intelligent client   
#define IANAport_tmi 		        		8300			// tcp,Transport Management Interface   
#define IANAport_amberon 	      		8301			// tcp,Amberon PPC/PPS   
#define IANAport_hub_open_net   		8313			// tcp,Hub Open Network   
//#define IANAport_				          8313			// udp,Reserved   
#define IANAport_tnp_discover   		8320			// tcp,Thin(ium) Network Protocol   
#define IANAport_tnp 		        		8321			// tcp,Thin(ium) Network Protocol   
#define IANAport_garmin_marine 	  	8322			// tcp,Garmin Marine   
#define IANAport_server_find 	    	8351			// tcp,Server Find   
#define IANAport_cruise_enum 	    	8376			// tcp,Cruise ENUM   
#define IANAport_cruise_swroute   	8377			// tcp,Cruise SWROUTE   
#define IANAport_cruise_config  		8378			// tcp,Cruise CONFIG   
#define IANAport_cruise_diags 	  	8379			// tcp,Cruise DIAGS   
#define IANAport_cruise_update  		8380			// tcp,Cruise UPDATE   
#define IANAport_m2mservices 	    	8383			// tcp,M2m Services   
#define IANAport_marathontp 	    	8384			// udp,Marathon Transport Protocol   
//#define IANAport_				          8384			// tcp,Reserved   
#define IANAport_cvd 			        	8400			// tcp,cvd   
#define IANAport_sabarsd 	      		8401			// tcp,sabarsd   
#define IANAport_abarsd 	      		8402			// tcp,abarsd   
#define IANAport_admind_2     			8403			// tcp,admind - Note amended
#define IANAport_svcloud 	      		8404			// tcp,SuperVault Cloud   
//#define IANAport_				          8404			// udp,Reserved   
#define IANAport_svbackup     			8405			// tcp,SuperVault Backup   
//#define IANAport_				          8405			// udp,Reserved   
#define IANAport_dlpx_sp 	      		8415			// tcp,Delphix Session Protocol   
//#define IANAport_				          8415			// udp,Reserved   
#define IANAport_espeech 	      		8416			// tcp,eSpeech Session Protocol   
#define IANAport_espeech_rtp    		8417			// tcp,eSpeech RTP Protocol   
#define IANAport_aritts 	      		8423			// tcp,Aristech text_to_speech server   
//#define IANAport_				          8423			// udp,Reserved   
#define IANAport_pgbackrest     		8432			// tcp,PostgreSQL Backup   
//#define IANAport_			      	    8432			// udp,Reserved   
//#define IANAport_			      	    8433			// tcp,Reserved   
#define IANAport_aws_as2 	      		8433			// udp,Non Persistent Desktop and Application Streaming   
#define IANAport_cybro_a_bus    		8442			// tcp,CyBro A_bus Protocol   
#define IANAport_pcsync_https     	8443			// tcp,PCsync HTTPS   
#define IANAport_pcsync_http    		8444			// tcp,PCsync HTTP   
#define IANAport_copy 		      		8445			// tcp,Port for copy peer sync feature   
#define IANAport_copy_disc 	    		8445			// udp,Port for copy discovery   
#define IANAport_npmp 			      	8450			// tcp,npmp   
#define IANAport_nexentamv 	    		8457			// tcp,Nexenta Management GUI   
//#define IANAport_				          8457			// udp,Reserved   
#define IANAport_cisco_avp    			8470			// tcp,Cisco Address Validation Protocol   
//#define IANAport_				          8470			// udp,Reserved   
#define IANAport_pim_port 	    		8471			// tcp,PIM over Reliable Transport,[RFC6559]  ,
//#define IANAport_				          8471			// udp,Reserved   
#define IANAport_otv 			        	8472			// tcp,Overlay Transport Virtualization (OTV)   
#define IANAport_vp2p 		      		8473			// tcp,Virtual Point to Point   
#define IANAport_noteshare 	    		8474			// tcp,AquaMinds NoteShare   
#define IANAport_fmtp 			      	8500			// tcp,Flight Message Transfer Protocol   
#define IANAport_cmtp_mgt 	    		8501			// tcp,CYTEL Message Transfer Management   
#define IANAport_cmtp_av 		      	8501			// udp,CYTEL Message Transfer Audio and Video   
#define IANAport_ftnmtp 		      	8502			// tcp,FTN Message Transfer Protocol   
//#define IANAport_				          8502			// udp,Reserved   
#define IANAport_lsp_self_ping 	  	8503			// udp,MPLS LSP Self_Ping,[RFC7746]  ,
//#define IANAport_			      	    8503			// tcp,Reserved   
#define IANAport_rtsp_alt 	    		8554			// tcp,RTSP Alternate (see port 554)   
#define IANAport_d_fence 	      		8555			// tcp,SYMAX D_FENCE   
#define IANAport_dof_tunnel     		8567			// tcp,DOF Tunneling Protocol   
#define IANAport_asterix 		      	8600			// tcp,Surveillance Data   
//#define IANAport_				          8609			// tcp,Reserved   
#define IANAport_canon_cpp_disc   	8609			// udp,Canon Compact Printer Protocol Discovery   
#define IANAport_canon_mfnp     		8610			// tcp,Canon MFNP Service   
#define IANAport_canon_bjnp1    		8611			// tcp,Canon BJNP Port 1   
#define IANAport_canon_bjnp2    		8612			// tcp,Canon BJNP Port 2   
#define IANAport_canon_bjnp3    		8613			// tcp,Canon BJNP Port 3   
#define IANAport_canon_bjnp4    		8614			// tcp,Canon BJNP Port 4   
#define IANAport_imink 		      		8615			// tcp,Imink Service Control   
//#define IANAport_				          8615			// udp,Reserved   
#define IANAport_monetra 	      		8665			// tcp,Monetra   
//#define IANAport_				          8665			// udp,Reserved   
#define IANAport_monetra_admin  		8666			// tcp,Monetra Administrative Access   
//#define IANAport_				          8666			// udp,Reserved   
#define IANAport_msi_cps_rm 	    	8675			// tcp,Motorola Solutions Customer Programming Software for Radio Management   
#define IANAport_msi_cps_rm_disc   	8675			// udp,Motorola Solutions Customer Programming Software for Radio Management Discovery   
#define IANAport_sun_as_jmxrmi 	  	8686			// tcp,Sun App Server _ JMX/RMI   
#define IANAport_openremote_ctrl  	8688			// tcp,OpenRemote Controller HTTP/REST   
//#define IANAport_				          8688			// udp,Reserved   
#define IANAport_vnyx 		      		8699			// tcp,VNYX Primary Port   
//#define IANAport_				          8699			// udp,Reserved   
#define IANAport_semi_grpc 	    		8710			// tcp,gRPC for SEMI Standards implementations   
//#define IANAport_				          8710			// udp,Reserved   
#define IANAport_nvc 		        		8711			// tcp,Nuance Voice Control   
//#define IANAport_		      		    8711			// udp,Reserved   
//#define IANAport_			      	    8732			// tcp,Reserved   
#define IANAport_dtp_net 	      		8732			// udp,DASGIP Net Services   
#define IANAport_ibus 		      		8733			// tcp,iBus   
#define IANAport_dey_keyneg     		8750			// tcp,DEY Storage Key Negotiation   
//#define IANAport_				          8750			// udp,Reserved   
#define IANAport_mc_appserver   		8763			// tcp,MC_APPSERVER   
#define IANAport_openqueue 		    	8764			// tcp,OPENQUEUE   
#define IANAport_ultraseek_http   	8765			// tcp,Ultraseek HTTP   
#define IANAport_amcs 		      		8766			// tcp,Agilent Connectivity Service   
#define IANAport_core_of_source   	8767			// tcp,Online mobile multiplayer game   
//#define IANAport_				          8767			// udp,Reserved   
#define IANAport_sandpolis 	    		8768			// tcp,Sandpolis Server   
//#define IANAport_				          8768			// udp,Reserved   
#define IANAport_oktaauthenticat  	8769			// tcp,Okta MultiPlatform Access Mgmt for Cloud Svcs   
//#define IANAport_				          8769			// udp,Reserved   
#define IANAport_dpap 		      		8770			// tcp,Digital Photo Access Protocol (iPhoto)   
#define IANAport_uec 		        		8778			// tcp,Stonebranch Universal Enterprise Controller   
//#define IANAport_			      	    8778			// udp,Reserved   
#define IANAport_msgclnt 		      	8786			// tcp,Message Client   
#define IANAport_msgsrvr 		      	8787			// tcp,Message Server   
#define IANAport_acd_pm 		      	8793			// tcp,Accedian Performance Measurement   
#define IANAport_sunwebadmin 	    	8800			// tcp,Sun Web Server Admin Service   
#define IANAport_truecm 		      	8804			// tcp,truecm   
//#define IANAport_				          8805			// tcp,Reserved   
#define IANAport_pfcp 			      	8805			// udp,Destination Port number for PFCP   
//#define IANAport_				          8807			// tcp,Reserved   
#define IANAport_hes_clip 	    		8807			// udp,HES_CLIP Interoperability protocol   
//#define IANAport_				          8808			// tcp,Reserved   
#define IANAport_ssports_bcast 	  	8808			// udp,STATSports Broadcast Service   
//#define IANAport_			      	    8809			// tcp,Reserved   
#define IANAport_3gpp_monp    			8809			// udp,MCPTT Off_Network Protocol (MONP)   
#define IANAport_dxspider     			8873			// tcp,dxspider linking protocol   
#define IANAport_cddbp_alt    			8880			// tcp,CDDBP   
#define IANAport_galaxy4d     			8881			// tcp,Galaxy4D Online Game Engine   
//#define IANAport_				          8881			// udp,Reserved   
#define IANAport_secure_mqtt     		8883			// tcp,Secure MQTT   
#define IANAport_ddi_tcp_1 	    		8888			// tcp,NewsEDGE server TCP (TCP 1)   
#define IANAport_ddi_tcp_2 	    		8889			// tcp,Desktop Data TCP 1   
#define IANAport_ddi_tcp_3    			8890			// tcp,Desktop Data TCP 2   
#define IANAport_ddi_tcp_4 	    		8891			// tcp,Desktop Data TCP 3: NESS application   
#define IANAport_ddi_tcp_5 	    		8892			// tcp,Desktop Data TCP 4: FARM product   
#define IANAport_ddi_tcp_6 	    		8893			// tcp,Desktop Data TCP 5: NewsEDGE/Web application   
#define IANAport_ddi_tcp_7    			8894			// tcp,Desktop Data TCP 6: COAL application   
#define IANAport_ospf_lite 	    		8899			// tcp,ospf_lite   
#define IANAport_jmb_cds1 	    		8900			// tcp,JMB_CDS 1   
#define IANAport_jmb_cds2     			8901			// tcp,JMB_CDS 2   
#define IANAport_dpp 			        	8908			// tcp,WFA Device Provisioning Protocol   
//#define IANAport_				          8908			// udp,Reserved   
#define IANAport_manyone_http   		8910			// tcp,manyone_http   
#define IANAport_manyone_xml    		8911			// tcp,manyone_xml   
#define IANAport_wcbackup 	    		8912			// tcp,Windows Client Backup   
#define IANAport_dragonfly 	    		8913			// tcp,Dragonfly System Service   
#define IANAport_twds 			      	8937			// tcp,Transaction Warehouse Data Service   
//#define IANAport_				          8937			// udp,Reserved   
#define IANAport_ub_dns_control   	8953			// tcp,unbound dns nameserver control   
//#define IANAport_				          8953			// udp,Reserved   
#define IANAport_cumulus_admin  		8954			// tcp,Cumulus Admin Port   
#define IANAport_nod_provider   		8980			// tcp,Network of Devices Provider   
#define IANAport_nod_client     		8981			// udp,Network of Devices Client   
//#define IANAport_				          8981			// tcp,Reserved   
#define IANAport_sunwebadmins   		8989			// tcp,Sun Web Server SSL Admin Service   
#define IANAport_http_wmap    			8990			// tcp,webmail HTTP service   
#define IANAport_https_wmap     		8991			// tcp,webmail HTTPS service   
#define IANAport_oracle_ms_ens  		8997			// tcp,Oracle Messaging Server Event Notification Service   
//#define IANAport_			      	    8997			// udp,Reserved   
#define IANAport_canto_roboflow   	8998			// tcp,Canto RoboFlow Control   
//#define IANAport_			      	    8998			// udp,Reserved   
#define IANAport_bctp 		      		8999			// tcp,Brodos Crypto Trade Protocol   
#define IANAport_cslistener     		9000			// tcp,CSlistener   
#define IANAport_etlservicemgr  		9001			// tcp,ETL Service Manager   
#define IANAport_dynamid 		      	9002			// tcp,DynamID authentication   
#define IANAport_golem 		      		9005			// tcp,Golem Inter_System RPC   
//#define IANAport_			      	    9005			// udp,Reserved   
//#define IANAport_			      	    9006			// ,De_Commissioned Port   
//#define IANAport_				          9007			// tcp,Reserved   
#define IANAport_ogs_client     		9007			// udp,Open Grid Services Client   
#define IANAport_ogs_server     		9008			// tcp,Open Grid Services Server   
//#define IANAport_			      	    9008			// udp,Reserved   
#define IANAport_pichat       			9009			// tcp,Pichat Server   
#define IANAport_sdr 		        		9010			// tcp,Secure Data Replicator Protocol   
//#define IANAport_			      	    9010			// udp,Reserved   
//#define IANAport_				          9011			// tcp,Reserved   
#define IANAport_d_star 	      		9011			// udp,D_Star Routing digital voice+data for amateur radio   
#define IANAport_tambora 	      		9020			// tcp,TAMBORA   
#define IANAport_panagolin_ident  	9021			// tcp,Pangolin Identification   
#define IANAport_paragent     			9022			// tcp,PrivateArk Remote Agent   
#define IANAport_swa_1 		      		9023			// tcp,Secure Web Access _ 1   
#define IANAport_swa_2 		      		9024			// tcp,Secure Web Access _ 2   
#define IANAport_swa_3 		      		9025			// tcp,Secure Web Access _ 3   
#define IANAport_swa_4 		      		9026			// tcp,Secure Web Access _ 4   
#define IANAport_versiera     			9050			// tcp,Versiera Agent Listener   
//#define IANAport_				          9050			// udp,Reserved   
#define IANAport_fio_cmgmt    			9051			// tcp,Fusion_io Central Manager Service   
//#define IANAport_				          9051			// udp,Reserved   
#define IANAport_CardWeb_IO     		9060			// tcp,CardWeb request_response I/O exchange   
#define IANAport_CardWeb_RT     		9060			// udp,CardWeb realtime device data   
#define IANAport_glrpc 		      		9080			// tcp,Groove GLRPC   
//#define IANAport_			      	    9081			// tcp,Reserved   
#define IANAport_cisco_aqos     		9081			// udp,Required for Adaptive Quality of Service   
#define IANAport_lcs_ap       			9082			// sctp,LCS Application Protocol   
#define IANAport_emc_pp_mgmtsvc   	9083			// tcp,EMC PowerPath Mgmt Service   
//#define IANAport_				          9083			// udp,Reserved   
#define IANAport_aurora 	      		9084			// tcp,IBM AURORA Performance Visualizer   
#define IANAport_ibm_rsyscon    		9085			// tcp,IBM Remote System Console   
#define IANAport_net2display 	    	9086			// tcp,Vesa Net2Display   
#define IANAport_classic 	      		9087			// tcp,Classic Data Server   
#define IANAport_sqlexec 	      		9088			// tcp,IBM Informix SQL Interface   
#define IANAport_sqlexec_ssl 	    	9089			// tcp,IBM Informix SQL Interface _ Encrypted   
#define IANAport_websm 			      	9090			// tcp,WebSM   
#define IANAport_xmltec_xmlmail   	9091			// tcp,xmltec_xmlmail   
#define IANAport_XmlIpcRegSvc   		9092			// tcp,Xml_Ipc Server Reg   
#define IANAport_copycat 	      		9093			// tcp,Copycat database replication service   
//#define IANAport_				          9093			// udp,Reserved   
#define IANAport_hp_pdl_datastr   	9100			// tcp,PDL Data Streaming Port   
#define IANAport_pdl_datastream   	9100			// tcp,Printer PDL Data Stream   
#define IANAport_bacula_dir     		9101			// tcp,Bacula Director   
#define IANAport_bacula_fd 	    		9102			// tcp,Bacula File Daemon   
#define IANAport_bacula_sd 	    		9103			// tcp,Bacula Storage Daemon   
#define IANAport_peerwire 	    		9104			// tcp,PeerWire   
#define IANAport_xadmin 	      		9105			// tcp,Xadmin Control Service,[Ari√´n Huisken <xadmin&huisken_systems.nl> 15 June 2009]  ,
#define IANAport_astergate 	    		9106			// tcp,Astergate Control Service   
#define IANAport_astergate_disc   	9106			// udp,Astergate Discovery Service   
#define IANAport_astergatefax   		9107			// tcp,AstergateFax Control Service   
//#define IANAport_				          9107			// udp,Reserved   
#define IANAport_hexxorecore 	    	9111			// tcp,"Multiple Purpose, Distributed Message Bus"   
#define IANAport_mxit 		      		9119			// tcp,MXit Instant Messaging   
#define IANAport_grcmp 		      		9122			// tcp,Global Relay compliant mobile instant messaging protocol   
//#define IANAport_				          9122			// udp,Reserved   
#define IANAport_grcp 		      		9123			// tcp,Global Relay compliant instant messaging protocol   
//#define IANAport_				          9123			// udp,Reserved   
#define IANAport_dddp 		      		9131			// tcp,Dynamic Device Discovery   
#define IANAport_apani1 	      		9160			// tcp,apani1   
#define IANAport_apani2 		      	9161			// tcp,apani2   
#define IANAport_apani3 	      		9162			// tcp,apani3   
#define IANAport_apani4 		      	9163			// tcp,apani4   
#define IANAport_apani5 		      	9164			// tcp,apani5   
#define IANAport_sun_as_jpda 	    	9191			// tcp,Sun AppSvr JPDA   
#define IANAport_wap_wsp 		      	9200			// tcp,WAP connectionless session service   
#define IANAport_wap_wsp_wtp    		9201			// tcp,WAP session service   
#define IANAport_wap_wsp_s 		    	9202			// tcp,WAP secure connectionless session service   
#define IANAport_wap_wsp_wtp_s    	9203			// tcp,WAP secure session service   
#define IANAport_wap_vcard 	    		9204			// tcp,WAP vCard   
#define IANAport_wap_vcal 	    		9205			// tcp,WAP vCal   
#define IANAport_wap_vcard_s    		9206			// tcp,WAP vCard Secure   
#define IANAport_wap_vcal_s     		9207			// tcp,WAP vCal Secure   
#define IANAport_rjcdb_vcards   		9208			// tcp,rjcdb vCard   
#define IANAport_almobile_system  	9209			// tcp,ALMobile System Service   
#define IANAport_oma_mlp 	      		9210			// tcp,OMA Mobile Location Protocol   
#define IANAport_oma_mlp_s 		    	9211			// tcp,OMA Mobile Location Protocol Secure   
#define IANAport_serverviewdbms   	9212			// tcp,Server View dbms access   
#define IANAport_serverstart 	    	9213			// tcp,ServerStart RemoteControl   
#define IANAport_ipdcesgbs 		    	9214			// tcp,IPDC ESG BootstrapService   
#define IANAport_insis 			      	9215			// tcp,Integrated Setup and Install Service   
#define IANAport_acme 		      		9216			// tcp,Aionex Communication Management Engine   
#define IANAport_fsc_port 		    	9217			// tcp,FSC Communication Port   
#define IANAport_teamcoherence  		9222			// tcp,QSC Team Coherence   
#define IANAport_mon_2 		      		9255			// tcp,Manager On Network - Note amended
#define IANAport_traingpsdata 	  	9277			// udp,GPS Data transmitted from train to ground network   
//#define IANAport_				          9277			// tcp,Reserved   
#define IANAport_pegasus 	      		9278			// tcp,Pegasus GPS Platform   
#define IANAport_pegasus_ctl    		9279			// tcp,Pegaus GPS System Control Interface   
#define IANAport_pgps 		      		9280			// tcp,Predicted GPS   
#define IANAport_swtp_port1 	    	9281			// tcp,SofaWare transport port 1   
#define IANAport_swtp_port2     		9282			// tcp,SofaWare transport port 2   
#define IANAport_callwaveiam    		9283			// tcp,CallWaveIAM   
#define IANAport_visd 		      		9284			// tcp,VERITAS Information Serve   
#define IANAport_n2h2server     		9285			// tcp,N2H2 Filter Service Port   
//#define IANAport_				          9286			// tcp,Reserved   
#define IANAport_n2receive 	    		9286			// udp,n2 monitoring receiver   
#define IANAport_cumulus 		      	9287			// tcp,Cumulus   
#define IANAport_armtechdaemon  		9292			// tcp,ArmTech Daemon   
#define IANAport_storview 	    		9293			// tcp,StorView Client   
#define IANAport_armcenterhttp 	  	9294			// tcp,ARMCenter http Service   
#define IANAport_armcenterhttps   	9295			// tcp,ARMCenter https Service   
#define IANAport_vrace 	      			9300			// tcp,Virtual Racing Service   
#define IANAport_sphinxql     			9306			// tcp,Sphinx search server (MySQL listener)   
//#define IANAport_				          9306			// udp,Reserved   
#define IANAport_sapms 		      		9310			// tcp,SAP Message Server   
//#define IANAport_				          9310			// udp,Reserved   
#define IANAport_sphinxapi 	    		9312			// tcp,Sphinx search server   
//#define IANAport_				          9312			// udp,Reserved   
#define IANAport_secure_ts 	    		9318			// tcp,PKIX TimeStamp over TLS   
#define IANAport_guibase 	      		9321			// tcp,guibase   
#define IANAport_gnmi_gnoi 	    		9339			// tcp,gRPC Network Mgmt/Operations Interface   
//#define IANAport_				          9339			// udp,Reserved   
#define IANAport_gribi 			      	9340			// tcp,gRPC Routing Information Base Interface   
//#define IANAport_				          9340			// udp,Reserved   
#define IANAport_mpidcmgr 	    		9343			// tcp,MpIdcMgr   
#define IANAport_mphlpdmc 	    		9344			// tcp,Mphlpdmc   
#define IANAport_rancher 		      	9345			// tcp,Rancher Agent   
//#define IANAport_				          9345			// udp,Reserved   
#define IANAport_ctechlicensing   	9346			// tcp,C Tech Licensing   
#define IANAport_fjdmimgr 	    		9374			// tcp,fjdmimgr   
#define IANAport_boxp 			      	9380			// tcp,Brivs! Open Extensible Protocol   
#define IANAport_d2dconfig 	    		9387			// tcp,D2D Configuration Service   
//#define IANAport_				          9387			// udp,Reserved   
#define IANAport_d2ddatatrans   		9388			// tcp,D2D Data Transfer Service   
//#define IANAport_			      	    9388			// udp,Reserved   
#define IANAport_adws 	      			9389			// tcp,Active Directory Web Services   
//#define IANAport_			      	    9389			// udp,Reserved   
#define IANAport_otp 		        		9390			// tcp,OpenVAS Transfer Protocol   
//#define IANAport_			      	    9390			// udp,Reserved   
#define IANAport_fjinvmgr     			9396			// tcp,fjinvmgr   
#define IANAport_mpidcagt 	    		9397			// tcp,MpIdcAgt   
#define IANAport_sec_t4net_srv  		9400			// tcp,Samsung Twain for Network Server   
#define IANAport_sec_t4net_clt  		9401			// tcp,Samsung Twain for Network Client   
#define IANAport_sec_pc2fax_srv   	9402			// tcp,Samsung PC2FAX for Network Server   
#define IANAport_git 			        	9418			// tcp,git pack transfer service   
#define IANAport_tungsten_https   	9443			// tcp,WSO2 Tungsten HTTPS   
#define IANAport_wso2esb_console   	9444			// tcp,WSO2 ESB Administration Console HTTPS   
#define IANAport_mindarray_ca 	  	9445			// tcp,MindArray Systems Console Agent   
//#define IANAport_				          9445			// udp,Reserved   
#define IANAport_sntlkeyssrvr   		9450			// tcp,Sentinel Keys Server   
#define IANAport_ismserver 	    		9500			// tcp,ismserver   
//#define IANAport_				          9522			// tcp,Reserved   
#define IANAport_sma_spw 		      	9522			// udp,SMA Speedwire   
#define IANAport_mngsuite 	    		9535			// tcp,Management Suite Remote Control   
#define IANAport_laes_bf 	      		9536			// tcp,Surveillance buffering function   
#define IANAport_trispen_sra    		9555			// tcp,Trispen Secure Remote Access   
#define IANAport_p4runtime 	    		9559			// tcp,P4Runtime gRPC Service   
//#define IANAport_				          9559			// udp,Reserved   
#define IANAport_ldgateway 	    		9592			// tcp,LANDesk Gateway   
#define IANAport_cba8 		      		9593			// tcp,LANDesk Management Agent (cba8)   
#define IANAport_msgsys 	      		9594			// tcp,Message System   
#define IANAport_pds 			        	9595			// tcp,Ping Discovery Service   
#define IANAport_mercury_disc 	  	9596			// tcp,Mercury Discovery   
#define IANAport_pd_admin 	    		9597			// tcp,PD Administration   
#define IANAport_vscp 			      	9598			// tcp,Very Simple Ctrl Protocol   
#define IANAport_robix 			      	9599			// tcp,Robix   
#define IANAport_micromuse_ncpw   	9600			// tcp,MICROMUSE_NCPW   
#define IANAport_streamcomm_ds    	9612			// tcp,StreamComm User Directory   
#define IANAport_iadt_tls     			9614			// tcp,iADT Protocol over TLS   
//#define IANAport_				          9614			// udp,Reserved   
#define IANAport_erunbook_agent   	9616			// tcp,"eRunbook Agent IANA assigned this well_formed service name as a replacement for ""erunbook_agent""."   
//#define IANAport_				          9616			// udp,Reserved   
#define IANAport_erunbook_server   	9617			// tcp,"eRunbook Server IANA assigned this well_formed service name as a replacement for ""erunbook_server""."   
//#define IANAport_				          9617			// udp,Reserved   
#define IANAport_condor 		      	9618			// tcp,Condor Collector Service   
#define IANAport_odbcpathway 	    	9628			// tcp,ODBC Pathway Service   
#define IANAport_uniport 	      		9629			// tcp,UniPort SSO Controller   
#define IANAport_peoctlr 	      		9630			// tcp,Peovica Controller   
//#define IANAport_				          9630			// udp,Reserved   
#define IANAport_peocoll 	      		9631			// tcp,Peovica Collector   
//#define IANAport_				          9631			// udp,Reserved   
//#define IANAport_				          9632			// tcp,Reserved   
#define IANAport_mc_comm 	      		9632			// udp,Mobile_C Communications   
#define IANAport_pqsflows     			9640			// tcp,ProQueSys Flows Service   
//#define IANAport_				          9640			// udp,Reserved   
#define IANAport_zoomcp 	      		9666			// tcp,Zoom Control Panel Game Server Management   
//#define IANAport_				          9666			// udp,Reserved   
#define IANAport_xmms2 		      		9667			// tcp,Cross_platform Music Multiplexing System   
#define IANAport_tec5_sdctp     		9668			// tcp,tec5 Spectral Device Control Protocol   
#define IANAport_client_wakeup  		9694			// tcp,T_Mobile Client Wakeup Message   
#define IANAport_ccnx 		      		9695			// tcp,Content Centric Networking   
#define IANAport_board_roar 	    	9700			// tcp,Board M.I.T. Service   
#define IANAport_l5nas_parchan  		9747			// tcp,L5NAS Parallel Channel   
#define IANAport_board_voip 	    	9750			// tcp,Board M.I.T. Synchronous Collaboration   
#define IANAport_rasadv 	      		9753			// tcp,rasadv   
#define IANAport_tungsten_http  		9762			// tcp,WSO2 Tungsten HTTP   
#define IANAport_davsrc       			9800			// tcp,WebDav Source Port   
#define IANAport_sstp_2       			9801			// tcp,Sakura Script Transfer Protocol_2   
#define IANAport_davsrcs      			9802			// tcp,WebDAV Source TLS/SSL   
#define IANAport_sapv1 	      			9875			// tcp,Session Announcement v1,[RFC2974]  ,
#define IANAport_sd 		        		9876			// tcp,Session Director   
#define IANAport_x510 	      			9877			// tcp,The X.510 wrapper protocol,[ITU_T X.510 / ISO/IEC 9584_11]  ,
//#define IANAport_			      	    9877			// udp,Reserved   
#define IANAport_kca_service    		9878			// udp,The KX509 Kerberized Certificate Issuance Protocol in Use in 2012,[RFC6717]  ,
//#define IANAport_				          9878			// tcp,Reserved   
#define IANAport_cyborg_systems   	9888			// tcp,CYBORG Systems   
#define IANAport_gt_proxy     			9889			// tcp,Port for Cable network related data proxy or repeater   
#define IANAport_monkeycom    			9898			// tcp,MonkeyCom   
//#define IANAport_				          9899			// tcp,Reserved   
#define IANAport_sctp_tunneling   	9899			// udp,SCTP TUNNELING,[RFC6951]  ,
#define IANAport_iua 		        		9900			// tcp,IUA   
#define IANAport_enrp 		      		9901			// udp,enrp server channel   
#define IANAport_enrp_sctp 	    		9901			// sctp,enrp server channel,[RFC5353]  ,
#define IANAport_enrp_sctp_tls  		9902			// sctp,enrp/tls server channel,[RFC5353]  ,
//#define IANAport_				          9903			// tcp,Reserved   
#define IANAport_multicast_ping    	9903			// udp,Multicast Ping Protocol,[RFC6450]  ,
#define IANAport_domaintime     		9909			// tcp,domaintime   
#define IANAport_sype_transport   	9911			// tcp,SYPECom Transport Protocol   
#define IANAport_xybrid_cloud   		9925			// tcp,XYBRID Cloud   
//#define IANAport_				          9925			// udp,Reserved   
#define IANAport_apc_9950 	    		9950			// tcp,APC 9950   
#define IANAport_apc_9951 	    		9951			// tcp,APC 9951   
#define IANAport_apc_9952     			9952			// tcp,APC 9952   
#define IANAport_acis 		      		9953			// tcp,9953   
#define IANAport_hinp 	      			9954			// tcp,HaloteC Instrument Network Protocol   
//#define IANAport_			      	    9954			// udp,Reserved   
#define IANAport_alljoyn_stm    		9955			// tcp,Contact Port for AllJoyn standard messaging   
//#define IANAport_			      	    9956			// tcp,Reserved   
#define IANAport_alljoyn      			9956			// udp,Alljoyn Name Service   
#define IANAport_odnsp 	      			9966			// tcp,OKI Data Network Setting Protocol   
#define IANAport_xybrid_rt 	    		9978			// tcp,XYBRID RT Server   
//#define IANAport_				          9978			// udp,Reserved   
#define IANAport_visweather     		9979			// tcp,Valley Information Systems Weather station data   
//#define IANAport_				          9979			// udp,Reserved   
#define IANAport_pumpkindb 	    		9981			// tcp,Event sourcing database engine with a built_in programming language   
//#define IANAport_				          9981			// udp,Reserved   
#define IANAport_dsm_scm_target    	9987			// tcp,DSM/SCM Target Interface   
#define IANAport_nsesrvr 	      		9988			// tcp,Software Essentials Secure HTTP server   
//#define IANAport_				          9988			// udp,Reserved   
#define IANAport_osm_appsrvr    		9990			// tcp,OSM Applet Server   
#define IANAport_osm_oev 		      	9991			// tcp,OSM Event Server   
#define IANAport_palace_1     			9992			// tcp,OnLive_1   
#define IANAport_palace_2     			9993			// tcp,OnLive_2   
#define IANAport_palace_3     			9994			// tcp,OnLive_3   
#define IANAport_palace_4     			9995			// tcp,Palace_4   
#define IANAport_palace_5     			9996			// tcp,Palace_5   
#define IANAport_palace_6     			9997			// tcp,Palace_6   
#define IANAport_distinct32     		9998			// tcp,Distinct32   
#define IANAport_distinct 	    		9999			// tcp,distinct   
#define IANAport_ndmp 		      		10000			// tcp,Network Data Management Protocol   
#define IANAport_scp_config     		10001			// tcp,SCP Configuration   
#define IANAport_documentum     		10002			// tcp,EMC_Documentum Content Server Product   
#define IANAport_documentum_s   		10003			// tcp,"EMC_Documentum Content Server Product IANA assigned this well_formed service name as a replacement for ""documentum_s""."   
#define IANAport_emcrmirccd     		10004			// tcp,EMC Replication Manager Client   
//#define IANAport_				          10004			// udp,Reserved   
#define IANAport_emcrmird     			10005			// tcp,EMC Replication Manager Server   
//#define IANAport_				          10005			// udp,Reserved   
#define IANAport_netapp_sync    		10006			// tcp,Sync replication protocol among different NetApp platforms   
//#define IANAport_				          10006			// udp,Reserved   
#define IANAport_mvs_capacity   		10007			// tcp,MVS Capacity   
#define IANAport_octopus 	      		10008			// tcp,Octopus Multiplexer   
#define IANAport_swdtp_sv     			10009			// tcp,Systemwalker Desktop Patrol   
#define IANAport_rxapi 	      			10010			// tcp,ooRexx rxapi services   
//#define IANAport_				          10010			// udp,Reserved   
#define IANAport_abb_hw       			10020			// tcp,Hardware configuration and maintenance   
//#define IANAport_			      	    10020			// udp,Reserved   
#define IANAport_cefd_vmp     			10023			// udp,Comtech EF_Data's Vipersat Management Protocol   
//#define IANAport_				          10023			// tcp,Reserved   
#define IANAport_zabbix_agent   		10050			// tcp,Zabbix Agent   
#define IANAport_zabbix_trapper   	10051			// tcp,Zabbix Trapper   
#define IANAport_qptlmd 	      		10055			// tcp,Quantapoint FLEXlm Licensing Service   
//#define IANAport_			      	    10055			// udp,Reserved   
#define IANAport_amanda       			10080			// tcp,Amanda   
#define IANAport_famdc 	      			10081			// tcp,FAM Archive Server   
#define IANAport_itap_ddtp    			10100			// tcp,VERITAS ITAP DDTP   
#define IANAport_ezmeeting_2    		10101			// tcp,eZmeeting   
#define IANAport_ezproxy_2 	    		10102			// tcp,eZproxy   
#define IANAport_ezrelay 	      		10103			// tcp,eZrelay   
#define IANAport_swdtp 		      		10104			// tcp,Systemwalker Desktop Patrol   
#define IANAport_bctp_server    		10107			// tcp,"VERITAS BCTP, server"   
#define IANAport_nmea_0183 	    		10110			// tcp,NMEA_0183 Navigational Data   
//#define IANAport_				          10111			// tcp,Reserved   
#define IANAport_nmea_onenet 	    	10111			// udp,NMEA OneNet multicast messaging   
#define IANAport_netiq_endpoint   	10113			// tcp,NetIQ Endpoint   
#define IANAport_netiq_qcheck   		10114			// tcp,NetIQ Qcheck   
#define IANAport_netiq_endpt    		10115			// tcp,NetIQ Endpoint   
#define IANAport_netiq_voipa    		10116			// tcp,NetIQ VoIP Assessor   
#define IANAport_iqrm 	      			10117			// tcp,NetIQ IQCResource Managament Svc   
#define IANAport_cimple 	      		10125			// tcp,HotLink CIMple REST API   
//#define IANAport_				          10125			// udp,Reserved   
#define IANAport_bmc_perf_sd    		10128			// tcp,BMC_PERFORM_SERVICE DAEMON   
#define IANAport_bmc_gms 	      		10129			// tcp,BMC General Manager Server   
//#define IANAport_				          10129			// udp,Reserved   
#define IANAport_qb_db_server   		10160			// tcp,QB Database Server   
#define IANAport_snmptls 	      		10161			// tcp,SNMP_TLS,[RFC6353]  ,
#define IANAport_snmpdtls 	    		10161			// udp,SNMP_DTLS,[RFC6353]  ,
#define IANAport_snmptls_trap   		10162			// tcp,SNMP_Trap_TLS,[RFC6353]  ,
#define IANAport_snmpdtls_trap 	  	10162			// udp,SNMP_Trap_DTLS,[RFC6353]  ,
#define IANAport_trisoap      			10200			// tcp,Trigence AE Soap Service   
#define IANAport_rsms 			      	10201			// tcp,Remote Server Management Service   
#define IANAport_apollo_relay   		10252			// tcp,Apollo Relay Port   
#define IANAport_eapol_relay    		10253			// udp,Relay of EAPOL frames   
//#define IANAport_				          10253			// tcp,Reserved   
#define IANAport_axis_wimp_port 	  10260			// tcp,Axis WIMP Port   
#define IANAport_tile_ml      			10261			// tcp,Tile remote machine learning   
//#define IANAport_				          10261			// udp,Reserved   
#define IANAport_blocks 	      		10288			// tcp,Blocks   
#define IANAport_cosir 		      		10321			// tcp,Computer Op System Information Report   
//#define IANAport_				          10321			// udp,Reserved   
#define IANAport_bngsync 	      		10439			// udp,BalanceNG session table synchronization protocol   
//#define IANAport_				          10439			// tcp,Reserved   
#define IANAport_cirrossp     			10443			// tcp,CirrosSP Workstation Communication   
//#define IANAport_				          10443			// udp,Reserved   
//#define IANAport_				          10500			// tcp,Reserved   
#define IANAport_hip_nat_t     			10500			// udp,HIP NAT_Traversal,[RFC5770][RFC9028]  ,
#define IANAport_MOS_lower     			10540			// tcp,MOS Media Object Metadata Port   
#define IANAport_MOS_upper    			10541			// tcp,MOS Running Order Port   
#define IANAport_MOS_aux       			10542			// tcp,MOS Low Priority Port   
#define IANAport_MOS_soap     			10543			// tcp,MOS SOAP Default Port   
#define IANAport_MOS_soap_opt   		10544			// tcp,MOS SOAP Optional Port   
#define IANAport_serverdocs     		10548			// tcp,Apple Document Sharing Service   
//#define IANAport_				          10548			// udp,Reserved   
#define IANAport_printopia 	    		10631			// tcp,Printopia Serve   
//#define IANAport_				          10631			// udp,Reserved   
#define IANAport_gap 				        10800			// tcp,Gestor de Acaparamiento para Pocket PCs   
#define IANAport_lpdg 			      	10805			// tcp,LUCIA Pareja Data Group   
#define IANAport_nbd 				        10809			// tcp,Linux Network Block Device   
//#define IANAport_				          10809			// udp,Reserved   
//#define IANAport_				          10810			// tcp,Reserved   
#define IANAport_nmc_disc       		10810			// udp,Nuance Mobile Care Discovery   
#define IANAport_helix 		      		10860			// tcp,Helix Client/Server   
#define IANAport_bveapi 	      		10880			// tcp,BVEssentials HTTP API   
#define IANAport_octopustentacle  	10933			// tcp,Listen port used by the Octopus Deploy Tentacle deployment agent   
//#define IANAport_				          10933			// udp,Reserved   
#define IANAport_rmiaux 	      		10990			// tcp,Auxiliary RMI Port   
#define IANAport_irisa 		      		11000			// tcp,IRISA   
#define IANAport_metasys 	      		11001			// tcp,Metasys   
#define IANAport_weave 		      		11095			// tcp,Nest device_to_device and device_to_service application protocol   
#define IANAport_origo_sync     		11103			// tcp,OrigoDB Server Sync Interface   
//#define IANAport_				          11103			// udp,Reserved   
#define IANAport_netapp_icmgmt  		11104			// tcp,NetApp Intercluster Management   
//#define IANAport_				          11104			// udp,Reserved   
#define IANAport_netapp_icdata  		11105			// tcp,NetApp Intercluster Data   
//#define IANAport_				          11105			// udp,Reserved   
#define IANAport_sgi_lk 		      	11106			// tcp,SGI LK Licensing service   
#define IANAport_myq_termlink   		11108			// udp,Hardware Terminals Discovery and Low_Level Communication Protocol   
//#define IANAport_				          11108			// tcp,Reserved   
#define IANAport_sgi_dmfmgr      		11109			// tcp,Data migration facility Manager (DMF) is a browser based interface to DMF   
//#define IANAport_				          11109			// udp,Reserved   
#define IANAport_sgi_soap     			11110			// tcp,Data migration facility (DMF) SOAP is a web server protocol to support remote access to DMF   
//#define IANAport_				          11110			// udp,Reserved   
#define IANAport_vce 			        	11111			// tcp,Viral Computing Environment (VCE)   
#define IANAport_dicom 		      		11112			// tcp,DICOM   
#define IANAport_suncacao_snmp  		11161			// tcp,sun cacao snmp access point   
#define IANAport_suncacao_jmxmp   	11162			// tcp,sun cacao JMX_remoting access point   
#define IANAport_suncacao_rmi   		11163			// tcp,sun cacao rmi registry access point   
#define IANAport_suncacao_csa   		11164			// tcp,sun cacao command_streaming access point   
#define IANAport_suncacao_websvc  	11165			// tcp,sun cacao web service access point   
//#define IANAport_				          11171			// tcp,Reserved   
#define IANAport_snss 		      		11171			// udp,Surgical Notes Security Service Discovery (SNSS)   
#define IANAport_oemcacao_jmxmp    	11172			// tcp,OEM cacao JMX_remoting access point   
//#define IANAport_				          11172			// udp,Reserved   
#define IANAport_t5_straton     		11173			// tcp,Straton Runtime Programing   
//#define IANAport_				          11173			// udp,Reserved   
#define IANAport_oemcacao_rmi 	  	11174			// tcp,OEM cacao rmi registry access point   
//#define IANAport_				          11174			// udp,Reserved   
#define IANAport_oemcacao_websvc  	11175			// tcp,OEM cacao web service access point   
//#define IANAport_		      		    11175			// udp,Reserved   
#define IANAport_smsqp 	      			11201			// tcp,smsqp   
#define IANAport_dcsl_backup    		11202			// tcp,DCSL Network Backup Services   
//#define IANAport_			      	    11202			// udp,Reserved   
#define IANAport_wifree 	      		11208			// tcp,WiFree Service   
#define IANAport_memcache     			11211			// tcp,Memory cache service   
#define IANAport_xcompute     			11235			// tcp,numerical systems messaging   
//#define IANAport_				          11235			// udp,Reserved   
#define IANAport_imip 		      		11319			// tcp,IMIP   
#define IANAport_imip_channels 	  	11320			// tcp,IMIP Channels Port   
#define IANAport_arena_server   		11321			// tcp,Arena Server Listen   
#define IANAport_atm_uhas 	    		11367			// tcp,ATM UHAS   
#define IANAport_hkp 			        	11371			// tcp,OpenPGP HTTP Keyserver   
#define IANAport_lsdp 		      		11430			// udp,Lenbrook Service Discovery Protocol   
//#define IANAport_				          11430			// tcp,Reserved   
#define IANAport_asgcypresstcps   	11489			// tcp,ASG Cypress Secure Only   
//#define IANAport_			      	    11489			// udp,Reserved   
#define IANAport_tempest_port 	  	11600			// tcp,Tempest Protocol Port   
#define IANAport_emc_xsw_dconfig  	11623			// tcp,EMC XtremSW distributed config   
//#define IANAport_     				    11623			// udp,Reserved   
#define IANAport_h323callsigalt   	11720			// tcp,H.323 Call Control Signalling Alternate   
#define IANAport_emc_xsw_dcache   	11723			// tcp,EMC XtremSW distributed cache   
#define IANAport_intrepid_ssl   		11751			// tcp,Intrepid SSL   
#define IANAport_lanschool 	    		11796			// tcp,LanSchool   
#define IANAport_lanschool_mpt 	  	11796			// udp,Lanschool Multipoint   
#define IANAport_xoraya       			11876			// tcp,X2E Xoraya Multichannel protocol   
//#define IANAport_			      	    11877			// tcp,Reserved   
#define IANAport_x2e_disc     			11877			// udp,X2E service discovery protocol   
#define IANAport_sysinfo_sp     		11967			// tcp,SysInfo Service Protocol   
#define IANAport_tibsd 		      		11971			// tcp,TiBS Service   
//#define IANAport_				          11971			// udp,Reserved   
#define IANAport_wmereceiving   		11997			// sctp,WorldMailExpress   
#define IANAport_wmedistribution  	11998			// sctp,WorldMailExpress   
#define IANAport_wmereporting   		11999			// sctp,WorldMailExpress   
#define IANAport_entextxid 	    		12000			// tcp,IBM Enterprise Extender SNA XID Exchange   
#define IANAport_entextnetwk    		12001			// tcp,IBM Enterprise Extender SNA COS Network Priority   
#define IANAport_entexthigh     		12002			// tcp,IBM Enterprise Extender SNA COS High Priority   
#define IANAport_entextmed 		    	12003			// tcp,IBM Enterprise Extender SNA COS Medium Priority   
#define IANAport_entextlow 		    	12004			// tcp,IBM Enterprise Extender SNA COS Low Priority   
#define IANAport_dbisamserver1 	  	12005			// tcp,DBISAM Database Server _ Regular   
#define IANAport_dbisamserver2 	  	12006			// tcp,DBISAM Database Server _ Admin   
#define IANAport_accuracer 		    	12007			// tcp,Accuracer Database System Server   
#define IANAport_accuracer_dbms   	12008			// tcp,Accuracer Database System Admin   
//#define IANAport_			      	    12009			// tcp,Reserved   
#define IANAport_ghvpn 		      		12009			// udp,Green Hills VPN   
#define IANAport_edbsrvr 	      		12010			// tcp,ElevateDB Server   
//#define IANAport_				          12010			// udp,Reserved   
#define IANAport_vipera 	      		12012			// tcp,Vipera Messaging Service   
#define IANAport_vipera_ssl     		12013			// tcp,Vipera Messaging Service over SSL Communication   
#define IANAport_rets_ssl     			12109			// tcp,RETS over SSL   
#define IANAport_nupaper_ss     		12121			// tcp,NuPaper Session Service   
#define IANAport_cawas 		      		12168			// tcp,CA Web Access Service   
#define IANAport_hivep 		      		12172			// tcp,HiveP   
#define IANAport_linogridengine   	12300			// tcp,LinoGrid Engine   
#define IANAport_rads 	      			12302			// tcp,"Remote Administration Daemon (RAD) is a system service that offers secure, remote, programmatic access to Solaris system configuration and run_time state"   
//#define IANAport_				          12302			// udp,Reserved   
#define IANAport_warehouse_sss  		12321			// tcp,Warehouse Monitoring Syst SSS   
#define IANAport_warehouse    			12322			// tcp,Warehouse Monitoring Syst   
#define IANAport_italk 	      			12345			// tcp,Italk Chat System   
#define IANAport_carb_repl_ctrl   	12546			// tcp,Carbonite Server Replication Control   
//#define IANAport_			      	    12546			// udp,Reserved   
#define IANAport_tsaf 		      		12753			// tcp,tsaf port   
#define IANAport_netperf 	      		12865			// tcp,control port for the netperf benchmark   
//#define IANAport_				          12865			// udp,Reserved   
#define IANAport_i_zipqd 	      		13160			// tcp,I_ZIPQD   
#define IANAport_bcslogc 	      		13216			// tcp,Black Crow Software application logging   
#define IANAport_rs_pias 	      		13217			// tcp,R&S Proxy Installation Assistant Service   
#define IANAport_emc_vcas_tcp   		13218			// tcp,EMC Virtual CAS Service   
#define IANAport_powwow_client 	  	13223			// tcp,PowWow Client   
#define IANAport_powwow_server  		13224			// tcp,PowWow Server   
#define IANAport_doip_data 	    		13400			// tcp,DoIP Data   
#define IANAport_doip_disc 	    		13400			// udp,DoIP Discovery   
#define IANAport_bprd 			      	13720			// tcp,BPRD Protocol (VERITAS NetBackup)   
#define IANAport_bpdbm 			      	13721			// tcp,BPDBM Protocol (VERITAS NetBackup)   
#define IANAport_bpjava_msvc    		13722			// tcp,BP Java MSVC Protocol   
#define IANAport_vnetd 			      	13724			// tcp,Veritas Network Utility   
#define IANAport_bpcd 		      		13782			// tcp,VERITAS NetBackup   
#define IANAport_vopied 	      		13783			// tcp,VOPIED Protocol   
#define IANAport_nbdb 		      		13785			// tcp,NetBackup Database   
#define IANAport_nomdb 		      		13786			// tcp,Veritas_nomdb   
#define IANAport_dsmcc_config 	  	13818			// tcp,DSMCC Config,[ISO/IEC 13818_6 MPEG_2 DSM_CC]  ,
#define IANAport_dsmcc_session 	  	13819			// tcp,DSMCC Session Messages,[ISO/IEC 13818_6 MPEG_2 DSM_CC]  ,
#define IANAport_dsmcc_passthru   	13820			// tcp,DSMCC Pass_Thru Messages,[ISO/IEC 13818_6 MPEG_2 DSM_CC]  ,
#define IANAport_dsmcc_download   	13821			// tcp,DSMCC Download Protocol,[ISO/IEC 13818_6 MPEG_2 DSM_CC]  ,
#define IANAport_dsmcc_ccp 		    	13822			// tcp,DSMCC Channel Change Protocol,[ISO/IEC 13818_6 MPEG_2 DSM_CC]  ,
#define IANAport_bmdss 			      	13823			// tcp,Blackmagic Design Streaming Server   
//#define IANAport_				          13823			// udp,Reserved   
#define IANAport_a_trust_rpc     		13832			// tcp,Certificate Management and Issuing   
//#define IANAport_				          13832			// udp,Reserved   
#define IANAport_ucontrol     			13894			// tcp,Ultimate Control communication protocol   
#define IANAport_dta_systems 	    	13929			// tcp,D_TA SYSTEMS   
#define IANAport_medevolve 	    		13930			// tcp,MedEvolve Port Requester   
//#define IANAport_				          13930			// udp,Reserved   
#define IANAport_scotty_ft 	    		14000			// tcp,SCOTTY High_Speed Filetransfer   
#define IANAport_sua 		        		14001			// tcp,SUA   
#define IANAport_scotty_disc 	    	14002			// udp,Discovery of a SCOTTY hardware codec board   
//#define IANAport_				          14002			// tcp,Reserved   
#define IANAport_sage_best_com1   	14033			// tcp,sage Best! Config Server 1   
#define IANAport_sage_best_com2   	14034			// tcp,sage Best! Config Server 2   
#define IANAport_vcs_app 	      		14141			// tcp,VCS Application   
#define IANAport_icpp 		      		14142			// tcp,IceWall Cert Protocol   
#define IANAport_icpps 		      		14143			// tcp,IceWall Cert Protocol over TLS   
//#define IANAport_				          14143			// udp,Reserved   
#define IANAport_gcm_app 	      		14145			// tcp,GCM Application   
#define IANAport_vrts_tdd 	    		14149			// tcp,Veritas Traffic Director   
#define IANAport_vcscmd 	      		14150			// tcp,Veritas Cluster Server Command Server   
//#define IANAport_				          14150			// udp,Reserved   
#define IANAport_vad 			        	14154			// tcp,Veritas Application Director   
#define IANAport_cps 			        	14250			// tcp,Fencing Server   
#define IANAport_ca_web_update  		14414			// tcp,CA eTrust Web Update Service   
#define IANAport_xpra 		      		14500			// tcp,xpra network protocol   
//#define IANAport_				          14500			// udp,Reserved   
#define IANAport_hde_lcesrvr_1  		14936			// tcp,hde_lcesrvr_1   
#define IANAport_hde_lcesrvr_2  		14937			// tcp,hde_lcesrvr_2   
#define IANAport_hydap 		      		15000			// tcp,Hypack Data Aquisition   
#define IANAport_onep_tls     			15002			// tcp,Open Network Environment TLS   
//#define IANAport_				          15002			// udp,Reserved   
//#define IANAport_				          15118			// tcp,Reserved   
#define IANAport_v2g_secc     			15118			// udp,v2g Supply Equipment Communication Controller Discovery Protocol   
#define IANAport_xpilot 	      		15345			// tcp,XPilot Contact Port   
#define IANAport_3link 		      		15363			// tcp,3Link Negotiation   
#define IANAport_cisco_snat     		15555			// tcp,Cisco Stateful NAT   
#define IANAport_bex_xr 	      		15660			// tcp,Backup Express Restore Server   
#define IANAport_ptp 			        	15740			// tcp,Picture Transfer Protocol   
//#define IANAport_			      	    15998			// tcp,Reserved   
#define IANAport_2ping 	      			15998			// udp,2ping Bi_Directional Ping Service   
#define IANAport_programmar     		15999			// tcp,ProGrammar Enterprise   
//#define IANAport_			      	    15999			// udp,Reserved   
#define IANAport_fmsas 	      			16000			// tcp,Administration Server Access   
//#define IANAport_				          16000			// udp,Reserved   
#define IANAport_fmsascon       		16001			// tcp,Administration Server Connector   
//#define IANAport_			      	    16001			// udp,Reserved   
#define IANAport_gsms 	      			16002			// tcp,GoodSync Mediation Service   
//#define IANAport_			      	    16002			// udp,Reserved   
//#define IANAport_			      	    16003			// tcp,Reserved   
#define IANAport_alfin 	      			16003			// udp,Automation and Control by REGULACE.ORG   
#define IANAport_jwpc 	      			16020			// tcp,Filemaker Java Web Publishing Core   
//#define IANAport_			      	    16020			// udp,Reserved   
#define IANAport_jwpc_bin     			16021			// tcp,Filemaker Java Web Publishing Core Binary   
//#define IANAport_				          16021			// udp,Reserved   
#define IANAport_sun_sea_port   		16161			// tcp,Solaris SEA Port   
#define IANAport_solaris_audit  		16162			// tcp,Solaris Audit _ secure remote audit log   
//#define IANAport_		      		    16162			// udp,Reserved   
#define IANAport_etb4j 	      			16309			// tcp,etb4j   
#define IANAport_pduncs 	      		16310			// tcp,"Policy Distribute, Update Notification"   
#define IANAport_pdefmns 	      		16311			// tcp,Policy definition and update management   
#define IANAport_netserialext1  		16360			// tcp,Network Serial Extension Ports One   
#define IANAport_netserialext2 	  	16361			// tcp,Network Serial Extension Ports Two   
#define IANAport_netserialext3  		16367			// tcp,Network Serial Extension Ports Three   
#define IANAport_netserialext4  		16368			// tcp,Network Serial Extension Ports Four   
#define IANAport_connected    			16384			// tcp,Connected Corp   
#define IANAport_rdgs 	      			16385			// tcp,Reliable Datagram Sockets   
//#define IANAport_			      	    16385			// udp,Reserved   
#define IANAport_xoms 	      			16619			// tcp,X509 Objects Management Service   
//#define IANAport_				          16619			// udp,Reserved   
#define IANAport_axon_tunnel    		16665			// tcp,Reliable multipath data transport for high latencies   
//#define IANAport_				          16665			// udp,Reserved   
//#define IANAport_				          16666			// tcp,Reserved   
#define IANAport_vtp 			        	16666			// udp,Vidder Tunnel Protocol   
#define IANAport_cadsisvr     			16789			// tcp,This server provides callable services to mainframe External Security Managers from any TCP/IP platform   
//#define IANAport_				          16789			// udp,Reserved   
#define IANAport_newbay_snc_mc   		16900			// tcp,Newbay Mobile Client Update Service   
#define IANAport_sgcip 		      		16950			// tcp,Simple Generic Client Interface Protocol   
#define IANAport_intel_rci_mp   		16991			// tcp,INTEL_RCI_MP   
#define IANAport_amt_soap_http  		16992			// tcp,Intel(R) AMT SOAP/HTTP   
#define IANAport_amt_soap_https    	16993			// tcp,Intel(R) AMT SOAP/HTTPS   
#define IANAport_amt_redir_tcp 	  	16994			// tcp,Intel(R) AMT Redirection/TCP   
#define IANAport_amt_redir_tls 	  	16995			// tcp,Intel(R) AMT Redirection/TLS   
#define IANAport_isode_dua 	    		17007			// tcp   ,
#define IANAport_ncpu 		      		17010			// tcp,Plan 9 cpu port  k=keypattern, f=fstabFILE, n=namespace, h=hostkey, r=root
//#define IANAport_				          17010			// udp,Reserved   
#define IANAport_vestasdlp 	    		17184			// tcp,Vestas Data Layer Protocol   
//#define IANAport_				          17184			// udp,Reserved   
#define IANAport_soundsvirtual 	  	17185			// tcp,Sounds Virtual   
#define IANAport_chipper 	      		17219			// tcp,Chipper   
#define IANAport_avtp 	      			17220			// tcp,IEEE 1722 Transport Protocol for Time Sensitive Applications   
#define IANAport_avdecc       			17221			// tcp,"IEEE 1722.1 AVB Discovery, Enumeration, Connection management, and Control"   
//#define IANAport_				          17222			// tcp,Reserved   
#define IANAport_cpsp 		      		17222			// udp,Control Plane Synchronization Protocol (SPSP)   
#define IANAport_isa100_gci     		17223			// tcp,ISA100 GCI is a service utilizing a common interface between an ISA100 Wireless gateway and a client application   
//#define IANAport_			      	    17223			// udp,Reserved   
#define IANAport_trdp_pd 	      		17224			// udp,Train Realtime Data Protocol (TRDP) Process Data   
//#define IANAport_				          17224			// tcp,Reserved   
#define IANAport_trdp_md 	      		17225			// tcp,Train Realtime Data Protocol (TRDP) Message Data   
#define IANAport_integrius_stp  		17234			// tcp,Integrius Secure Tunnel Protocol   
#define IANAport_ssh_mgmt     			17235			// tcp,SSH Tectia Manager   
#define IANAport_db_lsp 	      		17500			// tcp,Dropbox LanSync Protocol   
#define IANAport_db_lsp_disc     		17500			// udp,Dropbox LanSync Discovery   
#define IANAport_ailith       			17555			// tcp,Ailith management of routers   
//#define IANAport_			      	    17555			// udp,Reserved   
#define IANAport_ea 		        		17729			// tcp,Eclipse Aviation   
#define IANAport_zep 		        		17754			// tcp,Encap. ZigBee Packets   
#define IANAport_zigbee_ip    			17755			// tcp,ZigBee IP Transport Service   
#define IANAport_zigbee_ips      		17756			// tcp,ZigBee IP Transport Secure Service   
#define IANAport_sw_orion     			17777			// tcp,SolarWinds Orion   
//#define IANAport_				          17777			// udp,Reserved   
#define IANAport_biimenu 	      		18000			// tcp,"Beckman Instruments, Inc."   
#define IANAport_radpdf 	      		18104			// tcp,RAD PDF Service   
//#define IANAport_				          18104			// udp,Reserved   
#define IANAport_racf 		      		18136			// tcp,z/OS Resource Access Control Facility   
//#define IANAport_				          18136			// udp,Reserved   
#define IANAport_opsec_cvp 	    		18181			// tcp,OPSEC CVP   
#define IANAport_opsec_ufp 	    		18182			// tcp,OPSEC UFP   
#define IANAport_opsec_sam 	    		18183			// tcp,OPSEC SAM   
#define IANAport_opsec_lea 	    		18184			// tcp,OPSEC LEA   
#define IANAport_opsec_omi 	    		18185			// tcp,OPSEC OMI   
#define IANAport_ohsc 			      	18186			// tcp,Occupational Health SC   
#define IANAport_opsec_ela 	    		18187			// tcp,OPSEC ELA   
#define IANAport_checkpoint_rtm   	18241			// tcp,Check Point RTM   
#define IANAport_iclid 		      		18242			// tcp,Checkpoint router monitoring   
//#define IANAport_				          18242			// udp,Reserved   
#define IANAport_clusterxl    			18243			// tcp,Checkpoint router state backup   
//#define IANAport_				          18243			// udp,Reserved   
#define IANAport_gv_pf 		      		18262			// tcp,GV NetConfig Service   
#define IANAport_ac_cluster 	    	18463			// tcp,AC Cluster   
//#define IANAport_				          18516			// tcp,Reserved   
#define IANAport_heythings    			18516			// udp,HeyThings Device communicate service   
#define IANAport_rds_ib 	      		18634			// tcp,Reliable Datagram Service   
#define IANAport_rds_ip 	      		18635			// tcp,Reliable Datagram Service over IP   
#define IANAport_vdmmesh 	      		18668			// tcp,Manufacturing Execution Systems Mesh Communication   
#define IANAport_vdmmesh_disc   		18668			// udp,Manufacturing Execution Systems Mesh Communication   
#define IANAport_ique 		      		18769			// tcp,IQue Protocol   
#define IANAport_infotos      			18881			// tcp,Infotos   
#define IANAport_apc_necmp    			18888			// tcp,APCNECMP   
#define IANAport_igrid 		      		19000			// tcp,iGrid Server   
#define IANAport_scintilla    			19007			// tcp,Scintilla protocol for device services   
#define IANAport_j_link 	      		19020			// tcp,J_Link TCP/IP Protocol   
//#define IANAport_				          19020			// udp,Reserved   
#define IANAport_opsec_uaa    			19191			// tcp,OPSEC UAA   
#define IANAport_ua_secureagent   	19194			// tcp,UserAuthority SecureAgent   
#define IANAport_cora 		      		19220			// tcp,Client Connection Management and Data Exchange Service   
#define IANAport_cora_disc    			19220			// udp,Discovery for Client Connection Management and Data Exchange Service   
#define IANAport_keysrvr 	      		19283			// tcp,Key Server for SASSAFRAS   
#define IANAport_keyshadow 	    		19315			// tcp,Key Shadow for SASSAFRAS   
#define IANAport_mtrgtrans    			19398			// tcp,mtrgtrans   
#define IANAport_hp_sco 	      		19410			// tcp,hp_sco   
#define IANAport_hp_sca 	      		19411			// tcp,hp_sca   
#define IANAport_hp_sessmon     		19412			// tcp,HP_SESSMON   
#define IANAport_fxuptp 	      		19539			// tcp,FXUPTP   
#define IANAport_sxuptp 	      		19540			// tcp,SXUPTP   
#define IANAport_jcp 			        	19541			// tcp,JCP Client   
#define IANAport_mle 			        	19788			// udp,Mesh Link Establishment   
//#define IANAport_				          19788			// tcp,Reserved   
#define IANAport_faircom_db      		19790			// tcp,FairCom Database   
//#define IANAport_			      	    19790			// udp,Reserved   
#define IANAport_iec_104_sec     		19998			// tcp,IEC 60870_5_104 process control _ secure   
//#define IANAport_			      	    19998			// udp,Reserved   
#define IANAport_dnp_sec      			19999			// tcp,Distributed Network Protocol _ Secure   
#define IANAport_dnp 		        		20000			// tcp,DNP   
#define IANAport_microsan     			20001			// tcp,MicroSAN   
#define IANAport_commtact_http 	  	20002			// tcp,Commtact HTTP   
#define IANAport_commtact_https   	20003			// tcp,Commtact HTTPS   
#define IANAport_openwebnet     		20005			// tcp,OpenWebNet protocol for electric network   
//#define IANAport_				          20012			// tcp,Reserved   
#define IANAport_ss_idi_disc     		20012			// udp,Samsung Interdevice Interaction discovery   
#define IANAport_ss_idi 	      		20013			// tcp,Samsung Interdevice Interaction   
//#define IANAport_				          20013			// udp,Reserved   
#define IANAport_opendeploy     		20014			// tcp,OpenDeploy Listener   
#define IANAport_nburn_id     			20034			// tcp,"NetBurner ID Port IANA assigned this well_formed service name as a replacement for ""nburn_id""."   
#define IANAport_tmophl7mts     		20046			// tcp,TMOP HL7 Message Transfer Service   
#define IANAport_mountd 	      		20048			// tcp,NFS mount protocol   
#define IANAport_nfsrdma 	      		20049			// tcp,Network File System (NFS) over RDMA,[RFC8267]  ,
#define IANAport_avesterra 	    		20057			// tcp,AvesTerra Hypergraph Transfer Protocol (HGTP)   
//#define IANAport_				          20057			// udp,Reserved   
#define IANAport_tolfab 	      		20167			// tcp,TOLfab Data Change   
#define IANAport_ipdtp_port     		20202			// tcp,IPD Tunneling Port   
#define IANAport_ipulse_ics     		20222			// tcp,iPulse_ICS   
#define IANAport_emwavemsg 	    		20480			// tcp,emWave Message Service   
#define IANAport_track 			      	20670			// tcp,Track   
#define IANAport_crtech_nlm     		20810			// tcp,CRTech NLM   
//#define IANAport_				          20810			// udp,Reserved   
#define IANAport_athand_mmp     		20999			// tcp,At Hand MMP   
#define IANAport_irtrans 		      	21000			// tcp,IRTrans Control   
#define IANAport_notezilla_lan 	  	21010			// tcp,Notezilla.Lan Server   
//#define IANAport_				          21010			// udp,Reserved   
#define IANAport_trinket_agent 	  	21212			// tcp,Distributed artificial intelligence   
//#define IANAport_				          21212			// udp,Reserved   
#define IANAport_cohesity_agent   	21213			// tcp,Cohesity backup agents   
//#define IANAport_				          21213			// udp,Reserved   
#define IANAport_aigairserver   		21221			// tcp,Services for Air Server   
//#define IANAport_			      	    21221			// udp,Reserved   
#define IANAport_rdm_tfs 	      		21553			// tcp,Raima RDM TFS   
//#define IANAport_				          21553			// udp,Reserved   
#define IANAport_dfserver     			21554			// tcp,MineScape Design File Server   
#define IANAport_vofr_gateway   		21590			// tcp,VoFR Gateway   
#define IANAport_tvpm 	      			21800			// tcp,TVNC Pro Multiplexing   
#define IANAport_sal 		        		21801			// tcp,Safe AutoLogon   
#define IANAport_webphone     			21845			// tcp,webphone   
#define IANAport_netspeak_is    		21846			// tcp,NetSpeak Corp. Directory Services   
#define IANAport_netspeak_cs 	    	21847			// tcp,NetSpeak Corp. Connection Services   
#define IANAport_netspeak_acd   		21848			// tcp,NetSpeak Corp. Automatic Call Distribution   
#define IANAport_netspeak_cps   		21849			// tcp,NetSpeak Corp. Credit Processing System   
#define IANAport_snapenetio     		22000			// tcp,SNAPenetIO   
#define IANAport_optocontrol    		22001			// tcp,OptoControl   
#define IANAport_optohost002    		22002			// tcp,Opto Host Port 2   
#define IANAport_optohost003    		22003			// tcp,Opto Host Port 3   
#define IANAport_optohost004    		22004			// tcp,Opto Host Port 4   
#define IANAport_optohost005    		22005			// tcp,Opto Host Port 5   
#define IANAport_dcap 			      	22125			// tcp,dCache Access Protocol   
//#define IANAport_				          22125			// udp,Reserved   
#define IANAport_gsidcap 		      	22128			// tcp,GSI dCache Access Protocol   
//#define IANAport_				          22128			// udp,Reserved   
#define IANAport_easyengine 	    	22222			// tcp,EasyEngine is CLI tool to manage WordPress Sites on Nginx server   
//#define IANAport_				          22222			// udp,Reserved   
#define IANAport_wnn6 			      	22273			// tcp,wnn6   
#define IANAport_cis 			        	22305			// tcp,CompactIS Tunnel   
#define IANAport_showcockpit_net  	22333			// tcp,ShowCockpit Networking   
#define IANAport_shrewd_control   	22335			// tcp,Initium Labs Security and Automation Control   
#define IANAport_shrewd_stream 	  	22335			// udp,Initium Labs Security and Automation Streaming   
#define IANAport_cis_secure 	    	22343			// tcp,CompactIS Secure Tunnel   
#define IANAport_wibukey 	      		22347			// tcp,WibuKey Standard WkLan   
#define IANAport_codemeter 	    		22350			// tcp,CodeMeter Standard   
#define IANAport_codemeter_cmwan  	22351			// tcp,TPC/IP requests of copy protection software to a server   
//#define IANAport_		      		    22351			// udp,Reserved   
#define IANAport_caldsoft_backup   	22537			// tcp,CaldSoft Backup server file transfer   
//#define IANAport_			      	    22537			// udp,Reserved   
#define IANAport_vocaltec_wconf   	22555			// tcp,Vocaltec Web Conference   
#define IANAport_vocaltec_phone   	22555			// udp,Vocaltec Internet Phone   
#define IANAport_talikaserver   		22763			// tcp,Talika Main Server   
#define IANAport_aws_brf 	      		22800			// tcp,Telerate Information Platform LAN   
#define IANAport_brf_gw 	      		22951			// tcp,Telerate Information Platform WAN   
#define IANAport_inovaport1     		23000			// tcp,Inova LightLink Server Type 1   
#define IANAport_inovaport2     		23001			// tcp,Inova LightLink Server Type 2   
#define IANAport_inovaport3     		23002			// tcp,Inova LightLink Server Type 3   
#define IANAport_inovaport4     		23003			// tcp,Inova LightLink Server Type 4   
#define IANAport_inovaport5     		23004			// tcp,Inova LightLink Server Type 5   
#define IANAport_inovaport6     		23005			// tcp,Inova LightLink Server Type 6   
#define IANAport_gntp 	      			23053			// tcp,Generic Notification Transport Protocol   
//#define IANAport_			      	    23053			// udp,Reserved   
//#define IANAport_			      	    23272			// tcp,Reserved   
#define IANAport_s102 	      			23272			// udp,S102 application   
#define IANAport_5afe_dir 	    		23294			// tcp,5AFE SDN Directory   
#define IANAport_5afe_disc 	    		23294			// udp,5AFE SDN Directory discovery   
#define IANAport_elxmgmt 		      	23333			// tcp,Emulex HBAnyware Remote Management   
#define IANAport_novar_dbase    		23400			// tcp,Novar Data   
#define IANAport_novar_alarm 	    	23401			// tcp,Novar Alarm   
#define IANAport_novar_global   		23402			// tcp,Novar Global   
#define IANAport_aequus       			23456			// tcp,Aequus Service   
//#define IANAport_				          23456			// udp,Reserved   
#define IANAport_aequus_alt     		23457			// tcp,Aequus Service Mgmt   
//#define IANAport_				          23457			// udp,Reserved   
#define IANAport_areaguard_neo  		23546			// tcp,AreaGuard Neo _ WebServer   
//#define IANAport_			      	    23546			// udp,Reserved   
#define IANAport_med_ltp 		      	24000			// tcp,med_ltp   
#define IANAport_med_fsp_rx     		24001			// tcp,med_fsp_rx   
#define IANAport_med_fsp_tx     		24002			// tcp,med_fsp_tx   
#define IANAport_med_supp 	    		24003			// tcp,med_supp   
#define IANAport_med_ovw 	      		24004			// tcp,med_ovw   
#define IANAport_med_ci 	      		24005			// tcp,med_ci   
#define IANAport_med_net_svc    		24006			// tcp,med_net_svc   
#define IANAport_filesphere     		24242			// tcp,fileSphere   
#define IANAport_vista_4gl 	    		24249			// tcp,Vista 4GL   
#define IANAport_ild 		        		24321			// tcp,Isolv Local Directory   
#define IANAport_hid 		        		24322			// udp,Transport of Human Interface Device data streams   
//#define IANAport_			      	    24322			// tcp,Reserved   
#define IANAport_vrmg_ip 	      		24323			// tcp,Verimag mobile class protocol over TCP   
//#define IANAport_				          24323			// udp,Reserved   
#define IANAport_intel_rci    			24386			// tcp,"Intel RCI IANA assigned this well_formed service name as a replacement for ""intel_rci""."   
#define IANAport_tonidods 	    		24465			// tcp,Tonido Domain Server   
#define IANAport_binkp 			      	24554			// tcp,BINKP   
#define IANAport_bilobit 	      		24577			// tcp,bilobit Service   
#define IANAport_bilobit_update   	24577			// udp,bilobit Service Update   
#define IANAport_sdtvwcam     			24666			// tcp,Service used by SmarDTV to communicate between a CAM and a second screen application   
//#define IANAport_				          24666			// udp,Reserved   
#define IANAport_canditv 	      		24676			// tcp,Canditv Message Service   
#define IANAport_flashfiler      		24677			// tcp,FlashFiler   
#define IANAport_proactivate     		24678			// tcp,Turbopower Proactivate   
#define IANAport_tcc_http     			24680			// tcp,TCC User HTTP Service   
#define IANAport_cslg 		      		24754			// tcp,Citrix StorageLink Gateway   
//#define IANAport_		      		    24754			// udp,Reserved   
//#define IANAport_		      		    24850			// tcp,Reserved   
#define IANAport_assoc_disc     		24850			// udp,Device Association Discovery   
#define IANAport_find       				24922			// tcp,Find Identification of Network Devices   
#define IANAport_icl_twobase1   		25000			// tcp,icl_twobase1   
#define IANAport_icl_twobase2   		25001			// tcp,icl_twobase2   
#define IANAport_icl_twobase3   		25002			// tcp,icl_twobase3   
#define IANAport_icl_twobase4   		25003			// tcp,icl_twobase4   
#define IANAport_icl_twobase5   		25004			// tcp,icl_twobase5   
#define IANAport_icl_twobase6   		25005			// tcp,icl_twobase6   
#define IANAport_icl_twobase7   		25006			// tcp,icl_twobase7   
#define IANAport_icl_twobase8   		25007			// tcp,icl_twobase8   
#define IANAport_icl_twobase9   		25008			// tcp,icl_twobase9   
#define IANAport_icl_twobase10  		25009			// tcp,icl_twobase10   
#define IANAport_rna 		        		25471			// sctp,RNSAP User Adaptation for Iurh   
#define IANAport_sauterdongle   		25576			// tcp,Sauter Dongle   
//#define IANAport_				          25576			// udp,Reserved   
#define IANAport_idtp 	      			25604			// tcp,Identifier Tracing Protocol   
//#define IANAport_			      	    25604			// udp,Reserved   
#define IANAport_vocaltec_hos   		25793			// tcp,Vocaltec Address Server   
#define IANAport_tasp_net     			25900			// tcp,TASP Network Comm   
#define IANAport_niobserver     		25901			// tcp,NIObserver   
#define IANAport_nilinkanalyst  		25902			// tcp,NILinkAnalyst   
#define IANAport_niprobe 	      		25903			// tcp,NIProbe   
#define IANAport_bf_game 	      		25954			// udp,Bitfighter game server   
//#define IANAport_				          25954			// tcp,Reserved   
#define IANAport_bf_master    			25955			// udp,Bitfighter master server   
//#define IANAport_				          25955			// tcp,Reserved   
#define IANAport_quake 		      		26000			// tcp,quake   
#define IANAport_scscp 		      		26133			// tcp,Symbolic Computation Software Composability Protocol   
#define IANAport_wnn6_ds 	      		26208			// tcp,wnn6_ds   
#define IANAport_cockroach    			26257			// tcp,CockroachDB   
//#define IANAport_				          26257			// udp,Reserved   
#define IANAport_ezproxy 	      		26260			// tcp,eZproxy   
#define IANAport_ezmeeting 	    		26261			// tcp,eZmeeting   
#define IANAport_k3software_svr    	26262			// tcp,K3 Software_Server   
#define IANAport_k3software_cli    	26263			// tcp,K3 Software_Client   
//#define IANAport_			      	    26264			// ,De_registered   
#define IANAport_exoline_tcp    		26486			// tcp,EXOline_TCP   
#define IANAport_exoconfig    			26487			// tcp,EXOconfig   
#define IANAport_exonet 	      		26489			// tcp,EXOnet   
#define IANAport_flex_lm_1    			27000			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_2	    		27001			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_3    			27002			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_4    			27003			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_5    			27004			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_6    			27005			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_7    			27006			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_8    			27007			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_9    			27008			// ,FLEX LM (1_10)   
#define IANAport_flex_lm_10   			27009			// ,FLEX LM (1_10)   
#define IANAport_flex_lmadmin   		27010			// tcp,A protocol for managing license services   
//#define IANAport_			      	    27010			// udp,Reserved   
#define IANAport_mongodb 	      		27017			// tcp,Mongo database system   
//#define IANAport_			      	    27017			// udp,Reserved   
#define IANAport_imagepump     			27345			// tcp,ImagePump   
#define IANAport_jesmsjc 	      		27442			// tcp,Job controller service   
#define IANAport_kopek_httphead   	27504			// tcp,Kopek HTTP Head Port   
#define IANAport_ars_vista 	    		27782			// tcp,ARS VISTA Application   
#define IANAport_astrolink 	    		27876			// tcp,Astrolink Protocol   
//#define IANAport_				          27876			// udp,Reserved   
#define IANAport_tw_auth_key    		27999			// tcp,TW Authentication/Key Distribution and Attribute Certificate Services
#define IANAport_nxlmd 			      	28000			// tcp,NX License Manager   
#define IANAport_pqsp 			      	28001			// tcp,PQ Service   
//#define IANAport_				          28001			// udp,Reserved   
#define IANAport_gruber_cashreg   	28010			// tcp,Gruber cash registry protocol   
//#define IANAport_				          28010			// udp,Reserved   
#define IANAport_thor_engine    		28080			// tcp,thor/server _ ML engine   
//#define IANAport_				          28080			// udp,Reserved   
//#define IANAport_				          28119			// tcp,Reserved   
#define IANAport_a27_ran_ran    		28119			// udp,A27 cdma2000 RAN Management   
#define IANAport_voxelstorm     		28200			// tcp,VoxelStorm game server   
#define IANAport_siemensgsm     		28240			// tcp,Siemens GSM   
#define IANAport_bosswave     			28589			// tcp,Building operating system services wide area verified exchange   
//#define IANAport_				          28589			// udp,Reserved   
#define IANAport_saltd_licensing  	29000			// tcp,Siemens Licensing Server   
//#define IANAport_			      	    29000			// udp,Reserved   
//#define IANAport_			      	    29118			// tcp,Reserved   
//#define IANAport_			      	    29118			// udp,Reserved   
#define IANAport_sgsap 	      			29118			// sctp,SGsAP in 3GPP   
#define IANAport_otmp 	      			29167			// tcp,ObTools Message Protocol   
//#define IANAport_			      	    29168			// tcp,Reserved   
//#define IANAport_			      	    29168			// udp,Reserved   
#define IANAport_sbcap 	      			29168			// sctp,SBcAP in 3GPP   
#define IANAport_iuhsctpassoc   		29169			// sctp,HNBAP and RUA Common Association   
#define IANAport_bingbang     			29999			// tcp,data exchange protocol for IEC61850 in wind power plants   
//#define IANAport_				          29999			// udp,Reserved   
#define IANAport_ndmps 		      		30000			// tcp,Secure Network Data Management Protocol   
//#define IANAport_				          30000			// udp,Reserved   
#define IANAport_pago_services1     30001			// tcp,Pago Services 1   
#define IANAport_pago_services2   	30002			// tcp,Pago Services 2   
#define IANAport_amicon_fpsu_ra   	30003			// tcp,Amicon FPSU_IP Remote Administration   
#define IANAport_amicon_fpsu_s 	  	30004			// udp,Amicon FPSU_IP VPN   
//#define IANAport_			      	    30004			// tcp,Reserved   
#define IANAport_rwp 		        		30100			// tcp,Remote Window Protocol   
//#define IANAport_			      	    30100			// udp,Reserved   
#define IANAport_rwp 			        	30100			// sctp,Remote Window Protocol   
#define IANAport_kingdomsonline   	30260			// tcp,Kingdoms Online (CraigAvenue)   
#define IANAport_gs_realtime    		30400			// tcp,GroundStar RealTime System   
//#define IANAport_			      	    30400			// udp,Reserved   
#define IANAport_samsung_disc   		30832			// udp,Samsung Convergence Discovery Protocol   
//#define IANAport_		      		    30832			// tcp,Reserved   
#define IANAport_ovobs 	      			30999			// tcp,OpenView Service Desk Client   
#define IANAport_ka_sddp      			31016			// tcp,Kollective Agent Secure Distributed Delivery Protocol   
#define IANAport_ka_kdp       			31016			// udp,Kollective Agent Kollective Delivery Protocol   
#define IANAport_autotrac_acp   		31020			// tcp,Autotrac ACP 245   
//#define IANAport_			      	    31020			// udp,Reserved   
//#define IANAport_			      	    31029			// tcp,Reserved   
#define IANAport_yawn 	      			31029			// udp,YaWN _ Yet Another Windows Notifier   
#define IANAport_eldim 	      			31337			// tcp,eldim is a secure file upload proxy   
#define IANAport_pace_licensed  		31400			// tcp,PACE license server   
//#define IANAport_			      	    31400			// udp,Reserved   
#define IANAport_xqosd 	      			31416			// tcp,XQoS network monitor   
#define IANAport_tetrinet     			31457			// tcp,TetriNET Protocol   
#define IANAport_lm_mon 	      		31620			// tcp,lm mon   
#define IANAport_dsx_monitor    		31685			// tcp,"DS Expert Monitor IANA assigned this well_formed service name as a replacement for ""dsx_monitor""."   
//#define IANAport_				          31685			// udp,Reserved   
#define IANAport_gamesmith_port     31765			// tcp,GameSmith Port   
#define IANAport_iceedcp_tx     		31948			// tcp,"Embedded Device Configuration Protocol TX IANA assigned this well_formed service name as a replacement for ""iceedcp_tx""."   
#define IANAport_iceedcp_rx     		31949			// tcp,"Embedded Device Configuration Protocol RX IANA assigned this well_formed service name as a replacement for ""iceedcp_rx""."   
#define IANAport_iracinghelper   		32034			// tcp,iRacing helper service   
#define IANAport_t1distproc60   		32249			// tcp,T1 Distributed Processor   
#define IANAport_plex 		      		32400			// tcp,Plex multimedia   
//#define IANAport_			      	    32400			// udp,Reserved   
#define IANAport_apm_link 	    		32483			// tcp,Access Point Manager Link   
#define IANAport_sec_ntb_clnt   		32635			// tcp,SecureNotebook_CLNT   
#define IANAport_DMExpress 	    		32636			// tcp,DMExpress   
#define IANAport_filenet_powsrm   	32767			// tcp,FileNet BPM WS_ReliableMessaging Client   
#define IANAport_filenet_tms    		32768			// tcp,Filenet TMS   
#define IANAport_filenet_rpc    		32769			// tcp,Filenet RPC   
#define IANAport_filenet_nch    		32770			// tcp,Filenet NCH   
#define IANAport_filenet_rmi    		32771			// tcp,FileNET RMI   
#define IANAport_filenet_pa     		32772			// tcp,FileNET Process Analyzer   
#define IANAport_filenet_cm 	    	32773			// tcp,FileNET Component Manager   
#define IANAport_filenet_re     		32774			// tcp,FileNET Rules Engine   
#define IANAport_filenet_pch 	    	32775			// tcp,Performance Clearinghouse   
#define IANAport_filenet_peior  		32776			// tcp,FileNET BPM IOR   
#define IANAport_filenet_obrok 	  	32777			// tcp,FileNet BPM CORBA   
#define IANAport_mlsn 		      		32801			// tcp,Multiple Listing Service Network   
#define IANAport_retp 			      	32811			// tcp,Real Estate Transport Protocol   
//#define IANAport_				          32811			// udp,Reserved   
#define IANAport_idmgratm 	    		32896			// tcp,Attachmate ID Manager   
#define IANAport_wg_endpt_comms   	33000			// tcp,WatchGuard Endpoint Communications   
//#define IANAport_			      	    33000			// udp,Reserved   
#define IANAport_mysqlx 	      		33060			// tcp,MySQL Database Extended Interface   
//#define IANAport_				          33060			// udp,Reserved   
#define IANAport_aurora_balaena   	33123			// tcp,Aurora (Balaena Ltd)   
#define IANAport_diamondport     		33331			// tcp,DiamondCentral Interface   
#define IANAport_dgi_serv 	    		33333			// tcp,Digital Gaslight Service   
//#define IANAport_				          33333			// udp,Reserved   
#define IANAport_speedtrace     		33334			// tcp,SpeedTrace TraceAgent   
#define IANAport_speedtrace_disc  	33334			// udp,SpeedTrace TraceAgent Discovery   
#define IANAport_traceroute     		33434			// tcp,traceroute use   
//#define IANAport_				          33435			// tcp,Reserved   
#define IANAport_mtrace 	      		33435			// udp,IP Multicast Traceroute,[RFC8487]  ,
#define IANAport_snip_slave     		33656			// tcp,SNIP Slave   
#define IANAport_digilent_adept    	33890			// tcp,Adept IP protocol   
//#define IANAport_			      	    33890			// udp,Reserved   
#define IANAport_turbonote_2    		34249			// tcp,TurboNote Relay Server Default Port   
#define IANAport_p_net_local    		34378			// tcp,P_Net on IP local   
#define IANAport_p_net_remote   		34379			// tcp,P_Net on IP remote   
#define IANAport_dhanalakshmi   		34567			// tcp,dhanalakshmi.org EDI Service   
#define IANAport_edi_service 	    	34567			// udp,dhanalakshmi.org EDI Service   
#define IANAport_profinet_rt 	    	34962			// tcp,PROFInet RT Unicast   
#define IANAport_profinet_rtm     	34963			// tcp,PROFInet RT Multicast   
#define IANAport_profinet_cm 	    	34964			// tcp,PROFInet Context Manager   
#define IANAport_ethercat 	    		34980			// tcp,EtherCAT Port   
#define IANAport_heathview 	    		35000			// tcp,HeathView   
//#define IANAport_				          35000			// udp,Reserved   
#define IANAport_rt_viewer 	    		35001			// tcp,ReadyTech Viewer   
#define IANAport_rt_sound 	    		35002			// tcp,ReadyTech Sound Server   
//#define IANAport_				          35002			// udp,Reserved   
#define IANAport_rt_devicemapper   	35003			// tcp,ReadyTech DeviceMapper Server   
//#define IANAport_				          35003			// udp,Reserved   
#define IANAport_rt_classmanager  	35004			// tcp,ReadyTech ClassManager   
#define IANAport_rt_labtracker   		35005			// tcp,ReadyTech LabTracker   
//#define IANAport_				          35005			// udp,Reserved   
#define IANAport_rt_helper    			35006			// tcp,ReadyTech Helper Service   
//#define IANAport_			      	    35006			// udp,Reserved   
#define IANAport_axio_disc 	    		35100			// tcp,Axiomatic discovery protocol   
#define IANAport_kitim 	      			35354			// tcp,KIT Messenger   
//#define IANAport_			      	    35354			// udp,Reserved   
#define IANAport_altova_lm 	    		35355			// tcp,Altova License Management   
#define IANAport_altova_lm_disc   	35355			// udp,Altova License Management Discovery   
#define IANAport_guttersnex     		35356			// tcp,Gutters Note Exchange   
//#define IANAport_				          35356			// udp,Reserved   
#define IANAport_openstack_id   		35357			// tcp,OpenStack ID Service   
//#define IANAport_			      	    35357			// udp,Reserved   
#define IANAport_allpeers     			36001			// tcp,AllPeers Network   
#define IANAport_wlcp 		      		36411			// udp,Wireless LAN Control plane Protocol (WLCP)   
//#define IANAport_				          36411			// tcp,Reserved   
//#define IANAport_				          36412			// tcp,Reserved   
//#define IANAport_				          36412			// udp,Reserved   
#define IANAport_s1_control     		36412			// sctp,S1_Control Plane (3GPP)   
//#define IANAport_				          36422			// tcp,Reserved   
//#define IANAport_				          36422			// udp,Reserved   
#define IANAport_x2_control     		36422			// sctp,X2_Control Plane (3GPP)   
#define IANAport_slmap 	      			36423			// sctp,SLm Interface Application Protocol   
#define IANAport_nq_ap 		      		36424			// sctp,Nq and Nq' Application Protocol   
#define IANAport_m2ap 		      		36443			// sctp,M2 Application Part   
#define IANAport_m3ap 		      		36444			// sctp,M3 Application Part   
//#define IANAport_			      	    36462			// tcp,Reserved   
//#define IANAport_			      	    36462			// udp,Reserved   
#define IANAport_xw_control     		36462			// sctp,Xw_Control Plane (3GPP)   
#define IANAport_febooti_aw     		36524			// tcp,Febooti Automation Workshop   
//#define IANAport_				          36524			// udp,Reserved   
#define IANAport_observium_agent  	36602			// tcp,Observium statistics collection agent   
//#define IANAport_				          36602			// udp,Reserved   
#define IANAport_mapx 		      		36700			// tcp,MapX communication   
//#define IANAport_				          36700			// udp,Reserved   
#define IANAport_kastenxpipe    		36865			// tcp,KastenX Pipe   
//#define IANAport_		      		    37472			// tcp,Reserved   
//#define IANAport_		      		    37472			// udp,Reserved   
#define IANAport_3gpp_w1ap 	    		37472			// sctp,W1 signalling transport   
#define IANAport_neckar 	      		37475			// tcp,science + computing's Venus Administration Port   
#define IANAport_gdrive_sync     		37483			// tcp,Google Drive Sync   
//#define IANAport_				          37483			// udp,Reserved   
#define IANAport_eftp 		      		37601			// tcp,Epipole File Transfer Protocol   
//#define IANAport_				          37601			// udp,Reserved   
#define IANAport_unisys_eportal   	37654			// tcp,Unisys ClearPath ePortal   
#define IANAport_ivs_database   		38000			// tcp,InfoVista Server Database   
//#define IANAport_				          38000			// udp,Reserved   
#define IANAport_ivs_insertion 	  	38001			// tcp,InfoVista Server Insertion   
//#define IANAport_			      	    38001			// udp,Reserved   
#define IANAport_cresco_control   	38002			// tcp,Cresco Controller   
#define IANAport_crescoctrl_disc   	38002			// udp,Cresco Controller Discovery   
#define IANAport_galaxy7_data   		38201			// tcp,Galaxy7 Data Tunnel   
#define IANAport_fairview     			38202			// tcp,Fairview Message Service   
#define IANAport_agpolicy     			38203			// tcp,AppGate Policy Server   
//#define IANAport_			      	    38412			// tcp,Reserved   
#define IANAport_ng_control     		38412			// sctp,NG Control Plane (3GPP)   
//#define IANAport_			      	    38422			// tcp,Reserved   
//#define IANAport_		      		    38422			// udp,Reserved   
#define IANAport_xn_control     		38422			// sctp,Xn Control Plane (3GPP)   
//#define IANAport_		      		    38462			// tcp,Reserved   
//#define IANAport_     				    38462			// udp,Reserved   
#define IANAport_e1_interface   		38462			// sctp,E1 signalling transport (3GPP)   
//#define IANAport_	      			    38472			// tcp,Reserved   
//#define IANAport_		      		    38472			// udp,Reserved   
#define IANAport_f1_control     		38472			// sctp,F1 Control Plane (3GPP)   
#define IANAport_psqlmws      			38638			// tcp,Premier SQL Middleware Server   
//#define IANAport_			      	    38638			// udp,Reserved   
#define IANAport_sruth      				38800			// tcp,"Sruth is a service for the distribution of routinely_generated but arbitrary files based on a publish/subscribe
      									                      // distribution model and implemented using a peer_to_peer transport mechanism"   
//#define IANAport_		      		    38800			// udp,Reserved   
#define IANAport_secrmmsafecopya  	38865			// tcp,Security approval process for use of the secRMM SafeCopy program   
//#define IANAport_		      		    38865			// udp,Reserved   
#define IANAport_vroa 	      			39063			// tcp,Children's hearing test/Telemedicine   
//#define IANAport_			      	    39063			// udp,Reserved   
#define IANAport_turbonote_1    		39681			// tcp,TurboNote Default Port   
#define IANAport_safetynetp     		40000			// tcp,SafetyNET p   
//#define IANAport_				          40023			// tcp,Reserved   
#define IANAport_k_patentssensor  	40023			// udp,K_PatentsSensorInformation   
#define IANAport_sptx 	      			40404			// tcp,Simplify Printing TX   
//#define IANAport_			      	    40404			// udp,Reserved   
#define IANAport_cscp 	      			40841			// tcp,CSCP   
#define IANAport_csccredir 	    		40842			// tcp,CSCCREDIR   
#define IANAport_csccfirewall   		40843			// tcp,CSCCFIREWALL   
//#define IANAport_				          40853			// tcp,Reserved   
#define IANAport_ortec_disc     		40853			// udp,ORTEC Service Discovery   
#define IANAport_fs_qos 		      	41111			// tcp,Foursticks QoS Protocol   
#define IANAport_tentacle     			41121			// tcp,Tentacle Server   
//#define IANAport_			      	    41121			// udp,Reserved   
#define IANAport_z_wave_s     			41230			// tcp,Z_Wave Protocol over SSL/TLS   
#define IANAport_crestron_cip   		41794			// tcp,Crestron Control Port   
#define IANAport_crestron_ctp   		41795			// tcp,Crestron Terminal Port   
#define IANAport_crestron_cips  		41796			// tcp,Crestron Secure Control Port   
//#define IANAport_				          41796			// udp,Reserved   
#define IANAport_crestron_ctps  		41797			// tcp,Crestron Secure Terminal Port   
//#define IANAport_			      	    41797			// udp,Reserved   
#define IANAport_candp 	      			42508			// tcp,Computer Associates network discovery protocol   
#define IANAport_candrp       			42509			// tcp,CA discovery response   
#define IANAport_caerpc 	      		42510			// tcp,CA eTrust RPC   
#define IANAport_curiosity    			42999			// tcp,API endpoint for search application   
//#define IANAport_				          42999			// udp,Reserved   
#define IANAport_recvr_rc     			43000			// tcp,Receiver Remote Control   
#define IANAport_recvr_rc_disc 	  	43000			// udp,Receiver Remote Control Discovery   
#define IANAport_reachout 	    		43188			// tcp,REACHOUT   
#define IANAport_ndm_agent_port   	43189			// tcp,NDM_AGENT_PORT   
#define IANAport_ip_provision   		43190			// tcp,IP_PROVISION   
#define IANAport_noit_transport   	43191			// tcp,Reconnoiter Agent Data Transport   
//#define IANAport_				          43191			// udp,Reserved   
#define IANAport_shaperai 	    		43210			// tcp,Shaper Automation Server Management   
#define IANAport_shaperai_disc  		43210			// udp,Shaper Automation Server Management Discovery   
//#define IANAport_				          43438			// tcp,Reserved   
#define IANAport_hmip_routing   		43438			// udp,HmIP LAN Routing   
#define IANAport_eq3_update     		43439			// tcp,EQ3 firmware update   
#define IANAport_eq3_config     		43439			// udp,EQ3 discovery and configuration   
#define IANAport_ew_mgmt 		      	43440			// tcp,Cisco EnergyWise Management   
#define IANAport_ew_disc_cmd 	    	43440			// udp,Cisco EnergyWise Discovery and Command Flooding   
#define IANAport_ciscocsdb 	    		43441			// tcp,Cisco NetMgmt DB Ports   
#define IANAport_z_wave_tunnel   		44123			// tcp,Z_Wave Secure Tunnel   
//#define IANAport_				          44123			// udp,Reserved   
#define IANAport_pmcd 			      	44321			// tcp,PCP server (pmcd)   
#define IANAport_pmcdproxy 	    		44322			// tcp,PCP server (pmcd) proxy   
#define IANAport_pmwebapi 		    	44323			// tcp,HTTP binding for Performance Co_Pilot client API   
#define IANAport_cognex_dataman   	44444			// tcp,Cognex DataMan Management Protocol   
//#define IANAport_				          44444			// udp,Reserved   
#define IANAport_acronis_backup   	44445			// tcp,Acronis Backup Gateway service port   
//#define IANAport_			      	    44445			// udp,Reserved   
//#define IANAport_			      	    44544			// tcp,Reserved   
#define IANAport_domiq 		      		44544			// udp,DOMIQ Building Automation   
#define IANAport_rbr_debug    			44553			// tcp,REALbasic Remote Debug   
//#define IANAport_				          44600			// tcp,Reserved   
#define IANAport_asihpi 	      		44600			// udp,AudioScience HPI   
#define IANAport_EtherNet_IP_2 	  	44818			// tcp,"EtherNet/IP messaging IANA assigned this well_formed service name as a replacement for ""EtherNet/IP_2""."   
#define IANAport_m3da 		      		44900			// tcp,M3DA is used for efficient machine_to_machine communications   
#define IANAport_m3da_disc 	    		44900			// udp,M3DA Discovery is used for efficient machine_to_machine communications   
#define IANAport_asmp 			      	45000			// tcp,Nuance AutoStore Status Monitoring Protocol (data transfer)   
#define IANAport_asmp_mon 	    		45000			// udp,Nuance AutoStore Status Monitoring Protocol (device monitoring)   
#define IANAport_asmps 			      	45001			// tcp,Nuance AutoStore Status Monitoring Protocol (secure data transfer)   
//#define IANAport_				          45001			// udp,Reserved   
#define IANAport_rs_status 	    		45002			// tcp,Redspeed Status Monitor   
//#define IANAport_				          45002			// udp,Reserved   
#define IANAport_synctest 	    		45045			// tcp,Remote application control protocol   
//#define IANAport_				          45045			// udp,Reserved   
#define IANAport_invision_ag 	    	45054			// tcp,InVision AG   
#define IANAport_cloudcheck     		45514			// tcp,ASSIA CloudCheck WiFi Management System   
#define IANAport_cloudcheck_ping  	45514			// udp,ASSIA CloudCheck WiFi Management keepalive   
#define IANAport_eba 		        		45678			// tcp,EBA PRISE   
#define IANAport_dai_shell 	    		45824			// tcp,Server for the DAI family of client_server products   
//#define IANAport_				          45824			// udp,Reserved   
#define IANAport_qdb2service    		45825			// tcp,Qpuncture Data Access Service   
#define IANAport_ssr_servermgr  		45966			// tcp,SSRServerMgr   
#define IANAport_inedo 	      			46336			// tcp,Listen port used for Inedo agent communication   
//#define IANAport_			      	    46336			// udp,Reserved   
#define IANAport_spremotetablet   	46998			// tcp,Connection between a desktop computer or server and a signature tablet to capture handwritten signatures   
//#define IANAport_			      	    46998			// udp,Reserved   
#define IANAport_mediabox     			46999			// tcp,MediaBox Server   
//#define IANAport_mediabox     		46999			// udp,MediaBox Server   
#define IANAport_mbus 		      		47000			// tcp,Message Bus   
#define IANAport_winrm 		      		47001			// tcp,Windows Remote Management Service   
//#define IANAport_				          47001			// udp,Reserved   
#define IANAport_jvl_mactalk    		47100			// udp,Configuration of motors connected to Industrial Ethernet   
//#define IANAport_				          47100			// tcp,Reserved   
#define IANAport_dbbrowse 		    	47557			// tcp,Databeam Corporation   
#define IANAport_directplaysrvr    	47624			// tcp,Direct Play Server   
#define IANAport_ap 			        	47806			// tcp,ALC Protocol   
#define IANAport_bacnet 		      	47808			// tcp,Building Automation and Control Networks   
#define IANAport_presonus_ucnet   	47809			// udp,PreSonus Universal Control Network Protocol   
//#define IANAport_				          47809			// tcp,Reserved   
#define IANAport_nimcontroller  		48000			// tcp,Nimbus Controller   
#define IANAport_nimspooler     		48001			// tcp,Nimbus Spooler   
#define IANAport_nimhub 	      		48002			// tcp,Nimbus Hub   
#define IANAport_nimgtw 	      		48003			// tcp,Nimbus Gateway   
#define IANAport_nimbusdb     			48004			// tcp,NimbusDB Connector   
//#define IANAport_				          48004			// udp,Reserved   
#define IANAport_nimbusdbctrl   		48005			// tcp,NimbusDB Control   
//#define IANAport_				          48005			// udp,Reserved   
#define IANAport_juka 			      	48048			// tcp,Juliar Programming Language Protocol   
//#define IANAport_				          48048			// udp,Reserved   
#define IANAport_3gpp_cbsp 	    		48049			// tcp,3GPP Cell Broadcast Service Protocol   
//#define IANAport_				          48049			// udp,Reserved   
#define IANAport_weandsf 	      		48050			// tcp,WeFi Access Network Discovery and Selection Function   
//#define IANAport_				          48050			// udp,Reserved   
#define IANAport_isnetserv 	    		48128			// tcp,Image Systems Network Services   
#define IANAport_blp5 			      	48129			// tcp,Bloomberg locator   
#define IANAport_com_bardac_dw 	  	48556			// tcp,com_bardac_dw   
#define IANAport_iqobject 		    	48619			// tcp,iqobject   
#define IANAport_robotraconteur   	48653			// tcp,Robot Raconteur transport   
#define IANAport_matahari 	    		49000			// tcp,Matahari Broker   
//#define IANAport_				          49000			// udp,Reserved   
#define IANAport_nusrp 			      	49001			// tcp,Nuance Unity Service Request Protocol   
#define IANAport_nusdp_disc     		49001			// udp,Nuance Unity Service Discovery Protocol   
#define IANAport_inspider 	    		49150			// tcp,InSpider System   
//#define IANAport_				          49150			// udp,Reserved   
//#define IANAport_				          49151			// ,IANA Reserved   

#endif

