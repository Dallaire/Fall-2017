
var players = [{ x: 0, y: 100, playerPicked: false}, { x: 570, y: 100, playerPicked: false}, {x: 300, y: 150 , changex: 0, changey: 0}, {blueScore: 0, redScore: 0, time: 0}];
var size = {width: 30, height: 60};
var ball = {width: 30, height: 30};
var selectedPlayer = -1;
var fontPointSize = 18; //point size for word text
var editorFont = "Arial"; //font for your editor

var timer;
var pollingTimer; //timer to poll server for location updates
var deltaX, deltaY; //location where mouse is pressed
var canvas = document.getElementById("canvas1"); //our drawing canvas


function setPlayerAtLocation(aCanvasX, aCanvasY) {
  //locate the player targeted by aCanvasX, aCanvasY

  var context = canvas.getContext("2d");

  if (selectedPlayer == -1){
    for (var i = 0; i < 2; i++) {
      console.log(players[i].y + " " + (players[i].y + size.height));
      if (aCanvasX > players[i].x &&
        aCanvasX < players[i].x + size.width &&
        aCanvasY < players[i].y + size.height
        && aCanvasY > players[i].y){
        selectedPlayer = i;
        players[selectedPlayer].playerPicked = true;
      }
    }
  }
  console.log("Selected Player: " + selectedPlayer);
}

var drawCanvas = function() {
  var context = canvas.getContext("2d");

  context.fillStyle = "white";
  context.fillRect(0, 0, canvas.width, canvas.height); //erase canvas

  context.font = "" + fontPointSize + "pt " + editorFont;

  context.strokeStyle = "blue";
  if (players[0].playerPicked == true){ //blue player
    context.fillStyle = "cornflowerblue";
    context.fillRect(players[0].x, players[0].y, size.width, size.height);
    context.fillText(players[3].blueScore, 50, 30);
    context.strokeText(players[3].blueScore, 50, 30);
  }
  else {context.strokeRect(players[0].x, players[0].y, size.width, size.height);}

  context.strokeStyle = "darkred";
  if (players[1].playerPicked == true){//red player
    context.fillStyle = "red";
    context.fillRect(players[1].x, players[1].y, size.width, size.height);
    context.fillText(players[3].redScore, 550, 30);
    context.strokeText(players[3].redScore, 550, 30);
  }
  else {context.strokeRect(players[1].x, players[1].y, size.width, size.height)}

  context.strokeStyle = "black";
  context.fillStyle = "black";
  context.fillText(players[3].time, 300, 30);
  context.strokeText(players[3].time, 300, 30);

  context.fillRect(players[2].x, players[2].y, ball.width, ball.height)

  context.stroke();
}

function handleMouseDown(e) {
  //get mouse location relative to canvas top left
  var rect = canvas.getBoundingClientRect();
  var canvasX = e.pageX - rect.left; //use jQuery event object pageX and pageY
  var canvasY = e.pageY - rect.top;
  console.log("mouse down:" + canvasX + ", " + canvasY);
  setPlayerAtLocation(canvasX, canvasY);

  // Stop propagation of the event and stop any default
  //  browser action
  e.stopPropagation();
  e.preventDefault();

  drawCanvas();

  var jsonString = JSON.stringify(players);
  $.post("positionData", jsonString, function(data, status) {
    console.log("data: " + data);
    console.log("typeof: " + typeof data);
    players= data;
    console.log("players: " + players);
  });
}

var UP_ARROW = 38;
var DOWN_ARROW = 40;

function pollingTimerHandler() {

  var dataObj = [{ x: -1, y: -1 }, {x: players[2].x, y: players[2].y}]; //used by server to react as poll
  //create a JSON string representation of the data object
  var jsonString = JSON.stringify(dataObj);

  //Poll the server for the location of the players
  $.post("positionData", jsonString, function(data, status) {
    console.log("data: " + data);
    console.log("typeof: " + typeof data);
    players = data;
    });
}

function handleTimer() {
  /*players[2].x = players[2].x + players[2].changex;
  players[2].y = players[2].y + players[2].changey;

  //console.log(players[2].changex + " " + players[2].changey);
  //keep moving word within bounds of canvas
  if (players[2].x + ball.width > players[1].x
    && players[2].x < players[1].x + size.width
    && players[2].y < players[1].y + size.height
    && players[2].y + ball.height > players[1].y)
    players[2].changex = players[2].changex * -1;
  if (players[2].x + ball.width + players[2].changex > players[0].x
    && players[2].x + players[2].changex < players[0].x + size.width
    && players[2].y + players[2].changey < players[0].y + size.height
    && players[2].y + ball.height + players[2].changey > players[0].y)
    players[2].changex = players[2].changex * -1;
  if (players[2].y + ball.Height + players[2].changey > canvas.height)
    players[2].changey = players[2].changey * -1;
  if (players[2].y + players[2].changey < 0)
    players[2].changey = players[2].changey * -1;
  //console.log(players[2].changex + " " + players[2].changey);*/
  drawCanvas();
}

function handleKeyDown(e) {
  console.log("keydown code = " + e.which);

  var dXY = 5; //amount to move in Y direction
  if(selectedPlayer != -1){
    if (e.which == UP_ARROW && players[selectedPlayer].y >= dXY)
      players[selectedPlayer].y -= dXY; //up arrow
    if (e.which == DOWN_ARROW && players[selectedPlayer].y + size.height + dXY <= canvas.height)
      players[selectedPlayer].y += dXY; //down arrow
  }
  //upate server with position data
  //may be too much traffic?
  //create a JSON string representation of players
  var jsonString = JSON.stringify(players);
  //update the server with a new location of the players
  $.post("positionData", jsonString, function(data, status) {
    console.log("data: " + data);
    console.log("typeof: " + typeof data);
    players= data;
    console.log("players: " + players);
  });
}

$(document).ready(function() {
  //add mouse down listener to our canvas object
  $("#canvas1").mousedown(handleMouseDown);
  //add keyboard handler to document
  $(document).keydown(handleKeyDown);

  timer = setInterval(handleTimer, 100); //tenth of second
  pollingTimer = setInterval(pollingTimerHandler, 100); //quarter of a second
  //timer.clearInterval(); //to stop

  drawCanvas();
});
