
function start(players){
  max = 10;
  min = 5;
  players[2].changex = Math.floor(Math.random() * (max - min)) + min;
  players[2].changey = Math.floor(Math.random() * (max - min)) + min;
  timer = Date.now()/1000;
  return {timer: timer, players: players};
}

function score(players){
  if (players[2].x < -100){
    players[3].redScore += 1;
    players[2].x = 300;
  }
  else if (players[2].x > 700){
    players[3].blueScore += 1;
    players[2].x = 300;
  }
  if (players[3].redScore == 3 || players[3].blueScore == 3){
    players[2].changex = 0;
    players[2].changey = 0;
  }
  return players;
}

function time(players, timer){
  players[2].x = players[2].x + players[2].changex;
  players[2].y = players[2].y + players[2].changey;

  //keep moving word within bounds of canvas
  if (players[2].x + 30 > players[1].x
    && players[2].x < players[1].x + 30
    && players[2].y < players[1].y + 60
    && players[2].y + 30 > players[1].y)
    players[2].changex = players[2].changex * -1;
  if (players[2].x + 30 + players[2].changex > players[0].x
    && players[2].x + players[2].changex < players[0].x + 30
    && players[2].y + players[2].changey < players[0].y + 60
    && players[2].y + 30 + players[2].changey > players[0].y)
    players[2].changex = players[2].changex * -1;
  if (players[2].y + 30 + players[2].changey > 300)
    players[2].changey = players[2].changey * -1;
  if (players[2].y + players[2].changey < 0)
    players[2].changey = players[2].changey * -1;

  var timeElapsed = Date.now() /1000 - timer;
  var timeLeft = 120 - Math.floor(timeElapsed);
  if(timeLeft <= 0 || players[3].blueScore == 3 || players[3].redScore == 3
      || players[0].playerPicked == false || players[1].playerPicked == false){
    timeLeft = 0;
    players[2].changex = 0;
    players[2].changey = 0;
  }
  players[3].time = timeLeft;
  return {timer: timer, players: players};
}

module.exports.start = start;
module.exports.score = score;
module.exports.time = time;
