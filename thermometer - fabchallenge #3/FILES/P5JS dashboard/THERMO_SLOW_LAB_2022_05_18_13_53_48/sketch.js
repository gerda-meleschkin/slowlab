let lecture;
let val;
let tempA=0;
function setup() {
  serial = new p5.SerialPort();
  serial.open("COM3");
  serial.on('data', gotData); 
  createCanvas(400, 400,);
  background(153,140,235);
  frameRate(20);

}

function draw() {
  
  noStroke();
  fill(153,140,235)
  rect(160,80,100,50)
  fill(255);
  textSize(20);
  text('THE OVEN TEMPERATURE IS',50,70);
  textSize(40);
  text(lecture,170,120);
  //text(lecture,val/4,150);

  
  translate(tempA, 0);
  tempA+=1;
  
  fill(251, 244, 109);
  noStroke();
  //rect(20, 100,30,val);
  //rect(0,100,20,val);
  ellipse(0,val+250,20,20)
  if (tempA == 400){
    background(153,140,235);
    tempA=0;    
  }

}

function gotData() {
  lecture = serial.readStringUntil('\n');
  if(lecture) {
    lecture = int(lecture)
    console.log(val)
    val = map(lecture, 0, 40, 300, 0);
  }
}