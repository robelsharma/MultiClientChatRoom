MultiClientChatRoom
===================

Multi client chat room with server and client in c++ with MFC and thread

Server:

Multi-client chat server is an open source c++ project. In this server multiple user can log in and communicate with one another as multicast user. In reality it can use as a chat room server. Can be modified as peer to peer (p2p) text chat. It can also be used as a backbone of a video conferencing project. It has a beautiful and easy to use user interface in MFC. This project is compatible with Microsoft visual studio 2010. I will describe the use of class and function with source code.

Technology used:

```
i.   C++
ii.   Microsoft visual Studio 2010
iii.  MFC GUI
iv.  Winshock2 Socket
v.   TCP/UDP
vi.  Windows Thread
```

This project consist of  3 classes.

```
1. Server.cpp
2. ServerDlg.cpp
3. ServerManager.cpp
```

Client:

This client will use as multi chat client with our very own server. In this client you need to provide server IP ,PORT and an USERNAME.

Technology used:

```
i.   C++
ii.   Microsoft visual Studio 2010
iii.  MFC GUI
iv.  Winshock2 Socket
v.   TCP/UDP
vi.  Windows Thread
```

This project consist of  3 classes.

```
1. Client.cpp
2. ClientDlg.cpp
3. ClientCon.cpp
```

Pre-Requisite:

1. C++
2. Microsoft visual Studio 2010


Build:

No dependency. So just open this 2 project in Microsoft visual Studio 2010 and build and RUN.
Thats it!

Try Out:

Start the Server in a PC from *server* binary. Then just provide the port on MFC gui text field and click start button.

Now , connect the client with the server by running the *client* binary. Then provide server IP, PORT, USERNAME and click on *Log In* button. 

Now you are done. Start chat and enjoy with your own chat room.





 
