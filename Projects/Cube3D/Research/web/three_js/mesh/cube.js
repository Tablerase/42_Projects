import * as THREE from 'three';

// Select the canvas
// Get the canvas element from the DOM
const canvas = document.querySelector('#cube');

// Create a scene
const scene = new THREE.Scene();

// Create a camera
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);

// Create a renderer
const renderer = new THREE.WebGLRenderer({ canvas });
renderer.setSize(window.innerWidth, window.innerHeight);
// Set background to null
renderer.setClearColor(0x000000, 0); // Set background color to black
renderer.setClearAlpha(0); // Set background alpha to 0 (transparent)

// Create a cube
const geometry = new THREE.BoxGeometry(1, 1, 1);
const material = new THREE.MeshBasicMaterial({ color: 0x00ff00 });
const cube = new THREE.Mesh(geometry, material);

// Add the cube to the scene
scene.add(cube);
camera.position.z = 5; // This is to move the camera back so we can see the cube, if we don't do this the camera will be inside the cube

// Rendering the scene

// Animate the cube
function animate(){
	requestAnimationFrame(animate); // This will call the animate function 60 times per second - it also allows to save resources when the tab is not active it doesn't call the function
	cube.rotation.x += 0.01;
	cube.rotation.y += 0.01;
	renderer.render(scene, camera);
}

// Compatibyility check
import WebGL from 'three/addons/capabilities/WebGL.js';

if ( WebGL.isWebGLAvailable() ) {

	// Initiate function or other initializations here
	animate();

} else {

	const warning = WebGL.getWebGLErrorMessage();
	document.getElementById( 'container' ).appendChild( warning );

}