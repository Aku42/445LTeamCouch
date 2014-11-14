/*
*	Joshua Bryant	(jmb6357)
*	James Morris	(jsm3288)
*/


//connect to the AP specified in the parameter. returns 0 on unsuccessful connection
uint8_t connect(uint16_t AP);

//interacts with the AP to verify wireless connection
uint8_t ping();

//displays the IP address of your client and the address you are using for the server
void 	who();

//specifies the IP address of the server
void	server(uint9_t IP);

//sends a question to the server
void	ask(uint8_t *pt);