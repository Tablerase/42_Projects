let walls;
let ray;
let particle;

const sceneW = 400;
const sceneH = 400;

function setup() {
	createCanvas(800, 400);
	walls = [];
	for (let i = 0; i < 5; i++) {
		let x1 = random(sceneW);
		let x2 = random(sceneW);
		let y1 = random(sceneH);
		let y2 = random(sceneH);
		walls[i] = new Boundary(x1, y1, x2, y2);
	}
	walls.push(new Boundary(-1, -1, sceneW, -1));
	walls.push(new Boundary(sceneW, -1, sceneW, sceneH));
	walls.push(new Boundary(sceneW, sceneH, -1, sceneH));
	walls.push(new Boundary(-1, sceneH, -1, -1));
	ray = new Ray(100, 200);
	particle = new Particle();
}

function draw() {
	background(0);
	// Display the walls
	for (let wall of walls) {
		wall.show();
	}
	// Update and display the ray
	particle.update(mouseX, mouseY);
	particle.show();
	
	// Translate the rays into the scene according to the walls distance form the particle
	const scene = particle.look(walls);
	const w = sceneW / scene.length; // width of each slice (ray)
	push();
	translate(sceneW, 0); // translate the scene to middle of the right side of the canvas
	for (let i = 0; i < scene.length; i++) {
		noStroke();
		const b = map(scene[i], 0, sceneW, 255, 0); // map the distance to a color
		const h = map(scene[i])
		fill(b); // color the slice according to the distance
		rect(i * w, 0, w, height); // draw the slice as a rectangle
	}
	pop();
}
