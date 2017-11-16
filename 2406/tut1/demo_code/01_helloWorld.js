/*
Hello World example to serving string to client
*/
//To test use browser to view http://localhost:3000
//Cntl+C to stop server

var http = require('http');
var counter = 1000;

http.createServer(function (request,response){
   //respond to client
   response.writeHead(200, {'Content-Type': 'text/plain'});
   response.write('Hello\n');
   var urlString = request.url;
   var index = urlString.indexOf("?name=");
   var index1 = urlString.indexOf("&email=");
   if(index > 0 & index1 > 0) {
     var name = urlString.substring(index + "?name=".length, index1);
     var email = urlString.substring(index1 + "&email=".length, urlString.length);
     response.write(name + "\n");
     response.write("Email: " + email +"\n");
   }
   else if (index > 0) {
     var name = urlString.substring(index + "?name=".length, urlString.length);
     response.write(name + "\n");
   }
   else response.write('World\n');
   //end HTTP response and provide final data to send
   response.end("["+ counter++ + "]\n");
   console.log("URL: " + request.url);
   console.log("method: " + request.method);
   console.log("request headers:");
   console.log(request.headers);
}).listen(3000);
console.log('Server Running at http://127.0.0.1:3000  CNTL-C to quit');
console.log('To test with browser visit: http://localhost:3000');
