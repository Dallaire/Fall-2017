
var http = require("http"); //need to http
var url = require("url"); //to parse url strings
var fs = require("fs"); //need to read static files
var game = require("./gameState");

var counter = 1000; //to count invocations of function(req,res)

//server maintained location of players
var players = [{ x: 0, y: 100, playerPicked: false}, { x: 570, y: 100, playerPicked: false}, {x: 300, y: 150 , changex: 0, changey: 0}, {blueScore: 0, redScore: 0, time: 0}];
var gameStarted = false;
var state;
var timer =  Date.now()/1000;

var ROOT_DIR = "html"; //dir to serve static files from

var MIME_TYPES = {
  css: "text/css",
  gif: "image/gif",
  htm: "text/html",
  html: "text/html",
  ico: "image/x-icon",
  jpeg: "image/jpeg",
  jpg: "image/jpeg",
  js: "application/javascript",
  json: "application/json",
  png: "image/png",
  txt: "text/plain"
};

var get_mime = function(filename) {
  var ext, type;
  for (ext in MIME_TYPES) {
    type = MIME_TYPES[ext];
    if (filename.indexOf(ext, filename.length - ext.length) !== -1) {
      return type;
    }
  }
  return MIME_TYPES["txt"];
};

http
  .createServer(function(request, response) {
    var urlObj = url.parse(request.url, true, false);
    console.log("\n============================");
    console.log("PATHNAME: " + urlObj.pathname);
    console.log("REQUEST: " + ROOT_DIR + urlObj.pathname);
    console.log("METHOD: " + request.method);

    var receivedData = "";

    //attached event handlers to collect the message data
    request.on("data", function(chunk) {
      receivedData += chunk;
    });

    //event handler for the end of the message
    request.on("end", function() {
      console.log("REQUEST END: ");
      console.log("received data: ", receivedData);
      console.log("type: ", typeof receivedData);

      if (request.method == "POST") {
        var dataObj = JSON.parse(receivedData);
        if (dataObj[0].x >= 0 && dataObj[0].y >= 0) {
          //Here a client is providing updated player info
          //capture location of players from client
          players = JSON.parse(receivedData);
          console.log("received data object: ", players);
          console.log("type: ", typeof players);
        }

        /*if (dataObj[0].x < 0 && dataObj[0].y < 0){
          players[2].x = dataObj[1].x;
          players[2].y = dataObj[1].y;
        }*/

        //Game state
        if(players[0].playerPicked == true && players[1].playerPicked == true && gameStarted == false){
          state = game.start(players);
          gameStarted = true;
          timer = state.timer;
        }
        if(players[2].x < -100 || players[2].x > 700){
          state.players = game.score(state.players);
        }

        state = game.time(players , timer);
        players = state.players;
        console.log("timer: " + timer);
        console.log("time left: " + players[3].time);

        //echo back the location of the players to who ever
        //sent the POST message
        response.writeHead(200, { "Content-Type": MIME_TYPES["json"] });
        response.end(JSON.stringify(players)); //send just the JSON object
      }

      if (request.method == "GET") {
        //handle GET requests as static file requests
        fs.readFile(ROOT_DIR + urlObj.pathname, function(err, data) {
          if (err) {
            //report error to console
            console.log("ERROR: " + JSON.stringify(err));
            //respond with not found 404 to client
            response.writeHead(404);
            response.end(JSON.stringify(err));
            return;
          }
          response.writeHead(200, {
            "Content-Type": get_mime(urlObj.pathname)
          });
          response.end(data);
        });
      }
    });
  })
  .listen(3000);

console.log("Server Running at http://127.0.0.1:3000  CNTL-C to quit");
