///////////////////////// WIFI_COM Operation /////////////////////////
extern char SSid[TEN];
extern char SSID_temp[TEN];
extern unsigned int SSID_index;
extern char SSID_rdy;
extern char IP_addr[FOURTEEN];
extern char IP_addr1[TEN];
extern char IP_addr2[TEN];
extern unsigned int IP_ADDR_index;
extern char IP_ADDR_rdy;
extern volatile char command[THIRTY_TWO];
extern unsigned int command_index;
extern char command_rdy;
extern char diss_event[FOURTEEN];
extern unsigned int diss_index;
extern char diss_event_rdy;
extern char AT_sent;
extern char WSYN_sent;
extern char PING_sent;
extern char NSTC_sent;
extern char NSTAT_sent;
extern unsigned int station;