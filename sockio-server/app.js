//require necessary modules
var http = require('http')
  , express = require('express')
  , socketIO = require("socket.io")
  , path = require('path');

//initialize our application
var app = express();
app.use(express.static(path.join(__dirname, 'assets')));
var server = http.createServer(app).listen(3000);
var io = socketIO.listen(server);

//settings
var settings = {
  'view_directory': '/views'
}


app.get('/', function(request, response){
  response.sendfile(__dirname + settings.view_directory + '/index.html')
});


//chat using socket.io
io.sockets.on('connection', function(client){
  //when client sends a join event
  client.on('join', function(data){
    client.set('nickname', data);
    client.broadcast.emit('message', { message: data + " just joined!", nickname: "Server Announcement" });
  });

  //when client sends a message
  client.on('message', function(data){
    client.get('nickname', function(err, nickname){
      client.broadcast.emit('message', { message: data, nickname: nickname });      
    });
  });

})