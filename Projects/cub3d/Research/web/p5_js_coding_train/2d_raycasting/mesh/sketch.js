let walls;
let ray;
let particle;

function setup() {
	createCanvas(400, 400);
	walls = [];
	for (let i = 0; i < 5; i++) {
		let x1 = random(width);
		let x2 = random(width);
		let y1 = random(height);
		let y2 = random(height);
		walls[i] = new Boundary(x1, y1, x2, y2);
	}
	walls.push(new Boundary(-1, -1, width, -1));
	walls.push(new Boundary(width, -1, width, height));
	walls.push(new Boundary(width, height, -1, height));
	walls.push(new Boundary(-1, height, -1, -1));
	ray = new Ray(100, 200);
	particle = new Particle();
}

function draw() {
	background(0);
	for (let wall of walls) {
		wall.show();
	}
	particle.update(mouseX, mouseY);
	particle.show();
	particle.look(walls);
}
