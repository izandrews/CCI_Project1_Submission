var margin = 40;
let myArray = ['😸', '💯','💯', '👍','👍', '🏆', '🎨', '🎯', '🍔', '🍺', '🍻', '🍾', '💙','💙','💙'];
var spin_bool = false;
var spinlength = 0;
var spincount = 0;
var totalspins = 0;
var pressStart;

function preload(){
  pressStart = loadFont("PressStart2P-Regular.ttf");
}

function spin(){
  totalspins += 1;
  console.log('spin function called')
  spin_bool= true;
  spinlength = random(0, 15);
  spincount = 0;
  return spin_bool;
}

function rectangles(){
  fill(255);
    for(let i = 0; i < (width- (margin*2)); i += ((width -   margin*2)/3)){
    rect((i+ margin), 100, 100, 200);
  }
  // fill(220);
  // rect(0, 60, 400, 60);
  
  
}

function win(){
  fill(245, 221, 66);
  textSize(28);
  textFont(pressStart);
  strokeWeight(13);
  stroke(0);
  text("WINNER WINNER", 200, 40);
  stroke(224, 111, 29);
  strokeWeight(5);
  text("WINNER WINNER", 200, 40);
}

function setup() {
  noStroke();
  frameRate(5);
  console.log(spin_bool);
  createCanvas(400, 400);
  background(235, 64, 52);
  textAlign(CENTER, CENTER);
  textSize(45);
  let button = createButton('spin!');
  let col = color(245, 221, 66);
  button.style('font-size', '30px');
  button.style('background-color', col);
  button.style('color', 255);
  button.style('border', '0px');
  button.position((width/2 - (button.width)), 350);

  button.mousePressed(spin);
  //text("Fruit Machine", 200, 40);
  rectangles();


}

function draw() {
  if(spin_bool == true && spincount < spinlength){
    rectangles();
    console.log('SPIN NUMBER', spincount);
    reel1 = int(random(0, myArray.length));
    reel2 = int(random(0, myArray.length));
    reel3 = int(random(0, myArray.length));
    text(myArray[reel2], 200, 200);
    text(myArray[reel1], 100, 200);
    text(myArray[reel3], 300, 200);
    spincount = spincount += 1;
    
  }
  if(spincount >= spinlength && spin_bool == true){
    if(totalspins % 4 != 0){
      console.log('Final spin started');
      rectangles();
      reel1 = int(random(0, myArray.length));
      reel2 = int(random(0, myArray.length));
      reel3 = int(random(0, myArray.length));
   
      console.log(reel1);
      text(myArray[reel2], 200, 200);
      text(myArray[reel1], 100, 200);
      text(myArray[reel3], 300, 200);
      console.log('Spin finished');
      spin_bool = false;


    } if(totalspins % 4 == 0){
        rectangles()
        reel1 = int(random(0, myArray.length));
        text(myArray[reel1], 200, 200);
        text(myArray[reel1], 100, 200);
        text(myArray[reel1], 300, 200);
        spin_bool = false;
        win();
      }

  }
      
}

