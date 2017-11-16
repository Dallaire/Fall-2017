var words = [];
words.push({word: "Search", x:50, y:50});
words.push({word: "song", x:120, y:50});
words.push({word: "by", x:170, y:50});
words.push({word: "title", x:200, y:50});
words.push({word: "case", x:250, y:50});

var wordBeingMoved;

var deltaX, deltaY; //location where mouse is pressed
var canvas = document.getElementById('canvas1'); //our drawing canvas

function getWordAtLocation(aCanvasX, aCanvasY){

	  //locate the word near aCanvasX,aCanvasY
	  //Just use crude region for now.
	  //should be improved to using lenght of word etc.

	  //note you will have to click near the start of the word
	  //as it is implemented now
    var context = canvas.getContext('2d');
	  for(var i=0; i<words.length; i++){
		 if(words[i].x < aCanvasX && words[i].x + context.measureText(words[i].word).width > aCanvasX &&
		    Math.abs(words[i].y - aCanvasY) < 20) return words[i];
	  }
	  return null;
}

var drawCanvas = function(){

    var context = canvas.getContext('2d');

    context.fillStyle = 'white';
    context.fillRect(0,0,canvas.width,canvas.height); //erase canvas

    context.font = '15pt Arial';
    context.fillStyle = 'cornflowerblue';
    context.strokeStyle = 'blue';

    for(var i=0; i<words.length; i++){  //note i declared as var
      context.fillStyle = 'cornflowerblue';
      context.strokeStyle = 'blue';

			var data = words[i];
      if (data.wordType == "chord"){
        context.fillStyle = 'green';
        context.strokeStyle = 'green';
      }
			context.fillText(data.word, data.x, data.y);
      context.strokeText(data.word, data.x, data.y);
	}
  context.stroke();
}

function handleMouseDown(e){

	//get mouse location relative to canvas top left
	var rect = canvas.getBoundingClientRect();
    //var canvasX = e.clientX - rect.left;
    //var canvasY = e.clientY - rect.top;
    var canvasX = e.pageX - rect.left; //use jQuery event object pageX and pageY
    var canvasY = e.pageY - rect.top;
	console.log("mouse down:" + canvasX + ", " + canvasY);

	wordBeingMoved = getWordAtLocation(canvasX, canvasY);
	//console.log(wordBeingMoved.word);
	if(wordBeingMoved != null ){
	   deltaX = wordBeingMoved.x - canvasX;
	   deltaY = wordBeingMoved.y - canvasY;
	   //document.addEventListener("mousemove", handleMouseMove, true);
       //document.addEventListener("mouseup", handleMouseUp, true);
	$("#canvas1").mousemove(handleMouseMove);
	$("#canvas1").mouseup(handleMouseUp);

	}

    // Stop propagation of the event and stop any default
    //  browser action

    e.stopPropagation();
    e.preventDefault();

	drawCanvas();
}

function handleMouseMove(e){

	console.log("mouse move");

	//get mouse location relative to canvas top left
	var rect = canvas.getBoundingClientRect();
    var canvasX = e.pageX - rect.left;
    var canvasY = e.pageY - rect.top;

	wordBeingMoved.x = canvasX + deltaX;
	wordBeingMoved.y = canvasY + deltaY;

	e.stopPropagation();

	drawCanvas();
	}

function handleMouseUp(e){
	console.log("mouse up");

	e.stopPropagation();

    //$("#canvas1").off(); //remove all event handlers from canvas
    //$("#canvas1").mousedown(handleMouseDown); //add mouse down handler

	//remove mouse move and mouse up handlers but leave mouse down handler
    $("#canvas1").off("mousemove", handleMouseMove); //remove mouse move handler
    $("#canvas1").off("mouseup", handleMouseUp); //remove mouse up handler

	drawCanvas(); //redraw the canvas
	}

  function handleSubmitButton () {

      var userText = $('#userTextField').val(); //get text from user text input field
  	if(userText && userText != ''){
  	   //user text was not empty
  	     var userRequestObj = {text: userText, type: "song"}; //make object to send to server
         var userRequestJSON = JSON.stringify(userRequestObj); //make json string
         console.log(userText);
         console.log(userRequestObj.text);
  	   $('#userTextField').val(''); //clear the user text field

  	   //Prepare a POST message for the server and a call back function
  	   //to catch the server repsonse.
         //alert ("You typed: " + userText);
  	   $.post("userText", userRequestJSON, function(data, status){
  			console.log("data: " + data);
  			console.log("typeof: " + typeof data);
  			var responseObj = JSON.parse(data);
  			//replace word array with new words if there are any
  			if(responseObj.wordArray) words = responseObj.wordArray;
  			});
  	}
    drawCanvas();
  }

  function handleSaveButton () {
    //PARSE WORDS INTO AN OBJECT
    

    var requestArray = [];

    var userRequestObj = {type: "save"};
    var userRequestJSON = JSON.stringify(userRequestObj);

    $.post("save",userRequestJSON, function(data, status){
      console.log("data: " + data);
      console.log("typeof: " + typeof data);
      var responseObj = JSON.parse(data);
      //replace word array with new words if there are any
      if(responseObj.wordArray) words = responseObj.wordArray;
    });
  }

  function handleTimer(){
    drawCanvas();
  }

  $(document).ready(function(){
  	//This is called after the broswer has loaded the web page

  	//add mouse down listener to our canvas object
  	$("#canvas1").mousedown(handleMouseDown);
    var interval = 250;
    timer = setInterval(handleTimer,interval);
      //timer.clearInterval(); //to stop
  	drawCanvas();
  });
