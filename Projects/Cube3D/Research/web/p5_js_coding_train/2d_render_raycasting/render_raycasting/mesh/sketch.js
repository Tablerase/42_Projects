// Daniel Shiffman
// https://thecodingtrain.com/CodingChallenges/146-rendering-ray-casting.html
// https://youtu.be/vYgIKn7iDH8

// Rendering Ray Casting

let walls = [];
let ray;
let particle;

const sceneW = 400;
const sceneH = 400;
let sliderFOV;

function setup() {
  createCanvas(800, 400);
  for (let i = 0; i < 4; i++) {
    let x1 = random(sceneW);
    let x2 = random(sceneW);
    let y1 = random(sceneH);
    let y2 = random(sceneH);
    walls[i] = new Boundary(x1, y1, x2, y2);
  }
  walls.push(new Boundary(0, 0, sceneW, 0));
  walls.push(new Boundary(sceneW, 0, sceneW, sceneH));
  walls.push(new Boundary(sceneW, sceneH, 0, sceneH));
  walls.push(new Boundary(0, sceneH, 0, 0));
  particle = new Particle();
  sliderFOV = createSlider(0, 360, 60);
  sliderFOV.input(changeFOV);
}

function changeFOV() {
  const fov = sliderFOV.value();
  particle.updateFOV(fov);
}

function draw() {
	// Update the particle's position and direction
  if (keyIsDown(LEFT_ARROW)) {
    particle.rotate(-0.01);
  } else if (keyIsDown(RIGHT_ARROW)) {
    particle.rotate(0.01);
  } else if (keyIsDown(UP_ARROW)) {
    particle.move(1);
  } else if (keyIsDown(DOWN_ARROW)) {
    particle.move(-1);
  }

  // Draw the walls
  background(0);
  for (let wall of walls) {
    wall.show();
  }
  particle.show();

  // Translate the rays into the scene according to the walls distance form the particle
  const scene = particle.look(walls); // get the distances from the particle to the walls in an array
  const w = sceneW / scene.length; // width of each slice (ray)
  push();
  translate(sceneW, 0); // translate the scene to middle of the right side of the canvas
  for (let i = 0; i < scene.length; i++) {
    noStroke();
    const sq = scene[i] * scene[i]; // square the distance to make it proportional to the brightness
    const wSq = sceneW * sceneW; // square the width of the scene to make it proportional to the brightness
    const b = map(sq, 0, wSq, 255, 0); // map the distance to a color (black to white)
    const h = map(scene[i], 0, sceneW, sceneH, 0); // map the distance to a height (close to far)
    fill(b);
    rectMode(CENTER);
    rect(i * w + w / 2, sceneH / 2, w + 1, h); // draw the slice as a rectangle (x, y, width, height) w + 1 to avoid gaps
  }
  pop();
}
