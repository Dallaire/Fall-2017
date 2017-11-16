
/*
Example of ASYNCHRONOUS file read.
Function readFile does not block (wait) for the file to be read.

Instead its argument function(err,data) will be called once the file has been read.
function(err,data) is the "call back" function that will be called when readFile's task is done.
*/


var fs = require('fs');
var colour = require('colour');
fs.readFile('songs/sister_golden_hair.txt', function(err, data) {
  if(err) throw err;
  var array = data.toString().split("\n");
  var array2 = [];
  for ( i in array){
    myString = array[i].replace(/(\r\n|\n|\r)/gm,"");
    var words = myString.split(" ");
    var line1 = "";
    var line2 = "";
    lastChord = ""
    spaces = 0;
    for (j in words){
      if (words[j].startsWith('[')){
        if ((spaces - lastChord.length)>= 0){line1 += " ".repeat(spaces - lastChord.length);}
        line1 += (" " + words[j]);
        lastChord = words[j];
        spaces = 0;
      }
      /*else if (typeof line1[line1.length - 1] !== 'undefined'){
        line1 += " ".repeat(words[j].length - line1[line1.length - 1].length + 1);
        line2 += (" " + words[j]);
      }*/
      else {
        line2 += (" " + words[j]);
        spaces += (words[j].length + 1);
      }
    }
    console.log(line1.green);
    console.log(line2.yellow);
    array2 += line1;
    array2 += line2;
  }
  //for(k in array2) { console.log(array2[k]); }
});
console.log("DONE");
