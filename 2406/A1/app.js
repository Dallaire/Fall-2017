//server code
var http = require('http'); //need to http
var fs = require('fs'); //need to read static files
var url = require('url');  //to parse url strings

var counter = 1000;

var MIME_TYPES = {
    'css': 'text/css',
    'gif': 'image/gif',
    'htm': 'text/html',
    'html': 'text/html',
    'ico': 'image/x-icon',
    'jpeg': 'image/jpeg',
    'jpg': 'image/jpeg',
    'js': 'text/javascript',
    'json': 'application/json',
    'png': 'image/png',
    'txt': 'text/plain'
};

var get_mime = function(filename) {
    var ext, type;
    for (ext in MIME_TYPES) {
        type = MIME_TYPES[ext];
        if (filename.indexOf(ext, filename.length - ext.length) !== -1) {
            return type;
        }
    }
    return MIME_TYPES['txt'];
};

var ROOT_DIR = 'html';
var directory = {'Brown Eyed Girl': 'Brown Eyed Girl.txt', 'Peaceful Easy Feeling': 'Peaceful Easy Feeling.txt', 'Sister Golden Hair': 'Sister Golden Hair.txt'};

var notFound = [];
notFound.push({word: "Not", x: 50, y: 50});
notFound.push({word: "Found", x: 90, y: 50});

http.createServer(function (request,response){
     var urlObj = url.parse(request.url, true, false);
     console.log('\n============================');
	   console.log("PATHNAME: " + urlObj.pathname);
     console.log("REQUEST: " + ROOT_DIR + urlObj.pathname);
     console.log("METHOD: " + request.method);

     var receivedData = '';

     //attached event handlers to collect the message data
     request.on('data', function(chunk) {
        receivedData += chunk;
     });

     //event handler for the end of the message
       request.on('end', function(){
          console.log('received data: ', receivedData);
          console.log('type: ', typeof receivedData);

  		//if it is a POST request then echo back the data.
  		if(request.method == "POST"){
  		   var dataObj = JSON.parse(receivedData);
         console.log('received data object: ', dataObj);
         console.log('type: ', typeof dataObj);

  	//Returns new song lyrics
      if (dataObj.type = "song"){
  		    console.log("USER REQUEST: " + dataObj.text );
          var returnObj = {};
          var words = [];
          if (directory[dataObj.text] !== undefined){
            var filePath = 'songs/' + directory[dataObj.text];
            fs.readFile(filePath, function(err, data) {
              if(err) throw err;
              var array = data.toString().split("\n");
              var vert = 10;
              for ( i in array){
                myString = array[i].replace(/(\r\n|\n|\r)/gm,"");
                var lyrics = "";
                var lyric = "";
                var chords = "";
                var chord = "";
                var spaceSkip = 0;
                for (var j=0; j<myString.length;j++){
                  if(myString[j]==" "){
                    //push the lyric
                    lyrics += lyric + " ";
                    lyric = "";
                    if (spaceSkip == 0){
                      chords += " ";
                    }
                    else spaceSkip--;
                  }
                  else if(myString[j]=="["){
                    //push chord
                    chord = "";
                    j++;
                    while (myString[j] != "]"){
                      chord += myString[j];
                      spaceSkip++;
                      j++;
                    }
                    chords += chord + " ";
                    spaceSkip++;
                    chord = "";
                  }
                  else {
                    //build lyric
                    lyric += myString[j];
                    if (spaceSkip == 0){
                      chords += " ";
                    }
                    else spaceSkip--;
                  }
                  if (j == myString.length-1) lyrics+=lyric + " ";
                }
                //add lyric and chord lines to words
                for (var k=0; k < chords.length; k++){
                  if (chords[k] != " "){
                    var xpos = 10 + k*10;
                    var ypos = vert;
                    var type = "chord";
                    var text = "";
                    while (chords[k] != " "){
                      text+= chords[k];
                      k++;
                    }
                    words.push({word: text, x: xpos, y: ypos, wordType: type});
                    text = "";
                  }
                }
                for (var l=0; l < lyrics.length; l++){
                  if (lyrics[l] != " "){
                    var xpos = 10 + l*10;
                    var ypos = vert + 20;
                    var type = "lyric";
                    var text = "";
                    while (lyrics[l] != " "){
                      text+= lyrics[l];
                      l++;
                    }
                    words.push({word: text, x: xpos, y: ypos, wordType: type});
                    text = "";
                  }
                }
                //allows consistent vertical spacing
                vert += 40;
              }
              returnObj.wordArray = words;
              response.writeHead(200, {'Content-Type': MIME_TYPES["text"]});  //does not work with application/json MIME
              response.end(JSON.stringify(returnObj)); //send just the JSON object
            });
          }
          else{
            returnObj.wordArray = notFound;
          }
      }

      //Saves to file
      if (dataObj.type = "save"){

      }
  		}
      });

      if(request.method == "GET"){
  	 //handle GET requests as static file requests
  	 var filePath = ROOT_DIR + urlObj.pathname;
  	 if(urlObj.pathname === '/') filePath = ROOT_DIR + '/assignment1.html';

     fs.readFile(filePath, function(err,data){
     if(err){
  		   //report error to console
         console.log('ERROR: ' + JSON.stringify(err));
  		   //respond with not found 404 to client
         response.writeHead(404);
         response.end(JSON.stringify(err));
         return;
      }
      response.writeHead(200, {'Content-Type': get_mime(filePath)});
      response.end(data);
      });
  }

}).listen(3000);

console.log('Server Running at http://127.0.0.1:3000  CNTL-C to quit');
