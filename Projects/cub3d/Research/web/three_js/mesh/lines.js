import * as THREE from 'three';

// Get the canvas element from the DOM
const canvas = document.querySelector('#lines');

// Create a scene
const scene = new THREE.Scene();

// Create a camera
const camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 500);
camera.position.set(0, 0, 100);
camera.lookAt(0, 0, 0);

// Create a renderer
const renderer = new THREE.WebGLRenderer({ canvas });
renderer.setSize(window.innerWidth, window.innerHeight);
// Set background to null
renderer.setClearColor(0x000000, 0); // Set background color to black
renderer.setClearAlpha(0); // Set background alpha to 0 (transparent)

// Create a line
const material = new THREE.LineBasicMaterial({ color: 0x0000ff });
const points = [];
// Square points connected by lines
points.push(new THREE.Vector3(-10, 0, 0));
points.push(new THREE.Vector3(0, 10, 0));
points.push(new THREE.Vector3(10, 0, 0));

const geometry = new THREE.BufferGeometry().setFromPoints(points);
const line = new THREE.Line(geometry, material);

// Add the line to the scene
scene.add(line);

// Rendering the scene
renderer.render(scene, camera);