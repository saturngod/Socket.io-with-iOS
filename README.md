Socket.io with objective-c example.

- Objective-C code from [https://github.com/pkyeck/socket.IO-objc](https://github.com/pkyeck/socket.IO-objc)
- Socket.io server code from [https://github.com/saturngod/geek_chat](https://github.com/saturngod/geek_chat)

##For running the app


Change IP address at sockio-server/views/index.html 

```
var socket = io.connect("192.168.1.10:3000");
```


Run socket.io chat like

	node ./sockio-server/app.js
	

Change IP address at Objective-C code

```
[_socketIO connectToHost:@"localhost" onPort:3000];
```
	
