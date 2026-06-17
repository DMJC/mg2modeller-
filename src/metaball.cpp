#include "../include/metaball.h"

void metaball::generateMesh() {
	polygonize(threshold, grid_resolution);
}

void metaball::polygonize(float thresh, float resolution) {
	// Marching cubes isosurface extraction.
	// Evaluate the field function on a 3D grid, find the isosurface at threshold,
	// and generate triangle mesh. Full implementation requires the marching cubes
	// lookup tables and field function evaluation.
	// For now, delegate to base class mesh generation from vertex/face lists.
	object::generateMesh();
}
